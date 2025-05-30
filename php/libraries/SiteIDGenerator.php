<?php declare(strict_types=1);

/**
 * This file contains a class used to generate SiteIDs i.e. both PSCIDs and
 * ExternalIDs.
 *
 * PHP Version 7
 *
 * @category Main
 * @package  LORIS
 * @author   John Saigle <john.saigle@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */

/**
 * This class is responsible for extracting configuration settings relating to
 * generation of SiteIDs and validates these values.
 *
 * @category Main
 * @package  LORIS
 * @author   John Saigle <john.saigle@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
class SiteIDGenerator extends IdentifierGenerator
{
    private const LENGTH = 4;

    /**
     * Either 'PSCID' or 'ExternalID'
     *
     * @var string
     */
    protected $kind;

    /**
     * Creates a new instance of a SiteIDGenerator to create either PSCIDs or
     * ExternalIDs. Relevant properties are extracted from the config.xml file.
     *
     * @param string $siteAlias    To be appended to the ID value. Usually an
     *                             abbreviation for the name of a site.
     * @param string $projectAlias To be appended to the ID value. Usually an
     *                             abbreviation for the name of a project.
     *
     * @return void
     */
    public function __construct(string $siteAlias, string $projectAlias)
    {
        // Read config settings from project/config.xml to retrieve the
        // alphabet, length, and generation method (sequential or random) used
        // to create new IDs.
        $this->generationMethod = $this->_getGeneration();
        $this->length           = $this->_getLength();
        $this->alphabet         = $this->_getAlphabet();
        $this->minValue         = $this->_getMinValue();
        $this->maxValue         = $this->_getMaxValue();

        $this->siteAlias    = $siteAlias;
        $this->projectAlias = $projectAlias;

        $this->prefix = $this->_getPrefix();
        $this->validate();
    }

    /**
     * Throws an exception if values extracted from the configuration settings
     * are not well-formed.
     *
     * @throws \DomainException
     *
     * @return void
     */
    protected function validate(): void
    {
        if (empty($this->generationMethod)
            || empty($this->length)
            || empty($this->alphabet)
            || empty($this->minValue)
            || empty($this->maxValue)
            || empty($this->prefix)
        ) {
            throw new \DomainException(
                'Values not configured properly for ' . get_class($this) . '. '
                . 'Please correct your configuration file.'
                . "Length: `{$this->length}`\n"
                . "Alphabet: `" . implode($this->alphabet) . "`\n"
                . "Min: `{$this->minValue}`\n"
                . "Max: `{$this->maxValue}`\n"
                . "Length: `{$this->prefix}`\n"
                . "Generation: `{$this->generationMethod}`\n"
            );
        }
    }

    /**
     * Generates a new ID for use in the rest of LORIS.
     * This function should be updated to use PSCID and ExternalID classes when
     * they are created. See CandIDGenerator for an example.
     *
     * @return string
     */
    public function generate()
    {
        return $this->createNewID();
    }

    /**
     * {@inheritDoc}
     *
     * Get all existing IDs for a given site. The prefix will be stripped from
     * the IDs as the calling code will be interested in and aware of the Site
     * corresponding to the prefix. Returning the bare IDs allows for easier
     * processing.
     *
     * When using the 'numeric' generation method, IDs of a different alphabet,
     * such as 'alphanumeric', should be filtered out to prevent string
     * comparison confusion. For example if the database contains an
     * alphabetical ID, these will be considered greater than the upper bound
     * of a numerical ID (PHP says 'AAA' > '999').
     * This will result in a RANGE_FULL error if the values are not filtered.
     *
     * The parameters $kind and $prefix should never be user-controllable as
     * this creates a SQL injection risk.
     *
     * @return string[] The IDs retrieved from the database with the prefix
     *                      stripped. E.g. MON1234 becomes 1234.
     */
    protected function getExistingIDs(): array
    {
        $ids = \NDB_Factory::singleton()->database()->pselectCol(
            "SELECT substring($this->kind, LENGTH('{$this->prefix}') +1)
            from candidate
            WHERE {$this->kind} LIKE '{$this->prefix}%'",
            []
        );
        if (empty($ids)) {
            return [];
        }
        // Filter out non-numeric ids if using a numeric alphabet.
        if (empty(array_diff($this->alphabet, range('0', '9')))) {
            return array_filter($ids, 'is_numeric');
        }
        return $ids;
    }
    /**
     * Helper function used for extracting the values from the config
     * settings relating to the PSCID structure.
     *
     * @param string $setting One of: 'generation', 'length', 'alphabet',
     *                        'min', 'max'.
     *
     * @return array<int,int|string>|string|null
     */
    private function _getIDSetting(
        string $setting
    ) {
        $config = \NDB_Factory::singleton()->config();
        $kind   = $config->getSetting($this->kind);

        if (!is_array($kind)) {
            throw new \LorisException("Invalid config for $this->kind");
        };
        // The generation setting can be easily extracted and returned.
        if ($setting == 'generation') {
            return $kind['generation'];
        }

        // Values other than 'generation' are found within 'seq' elements and
        // require more complex processing.
        $idStructure = $kind['structure']['seq'];

        if (!$idStructure[0]) {
            // There's only one seq tag so the param format
            // needs to be fixed
            $temp        = [];
            $temp[]      = $idStructure;
            $idStructure = $temp;
        }

        try {
            $seqValue = self::getSeqAttribute($idStructure, $setting);
        } catch (\ConfigurationException $e) {
            /* Throw a new exception so that we can inform developers whether
             * the ConfigurationException arose due to ExternalID or PSCID
             * settings.
             */
            throw new \LorisException(
                "Cannot create new candidate because of a configuration " .
                "error in settings for {$this->kind} structure. Details: "
                . $e->getMessage()
            );
        }
        if ($setting === 'alphabet') {
            switch ($seqValue) {
            case 'alpha':
                return range('A', 'Z');
            case 'numeric':
                return range('0', '9');
            case 'alphanumeric':
                return array_merge(range('0', '9'), range('A', 'Z'));
            }
        }

        if ($setting === 'prefix') {
            if ($seqValue === 'static') {
                // The 'static' seq attribute must also include a value which
                // will be a fixed string prefix to be prepended to IDs in
                // LORIS. This must be extracted manually.
                foreach ($idStructure as $seq) {
                    if ($seq['@']['type'] === 'static') {
                        // This index stores the prefix.
                        return $seq['#'];
                    }
                }
            } elseif ($seqValue === 'siteAbbrev') {
                return $this->siteAlias;
            } elseif ($seqValue === 'projectAbbrev') {
                return $this->projectAlias;
            } else {
                throw new ConfigurationException(
                    "Incorrect option $seqValue selected for PSCID generation."
                );
            }
        }
        // The remaining values - min, max, and length - should be returned as
        // null if they are not set.
        return is_null($seqValue) ? $seqValue: $seqValue;
    }
    /**
     * Iterate over each 'seq' value and return its setting if its value is
     * configured. Do error handling to make sure that there is exactly one
     * value corresponding to the requested setting.
     *
     * @param array<array<array<string>>> $idStructure Settings concerning ID
     *                                                 structure extracted from
     *                                                 project/config.sml
     * @param string                      $setting     The name of the variable
     *                                                 for which we want the
     *                                                 value.
     *
     * @throws \ConfigurationException
     *
     * @return ?string
     */
    static function getSeqAttribute(
        array $idStructure,
        string $setting
    ): ?string {
        /* Do validation on 'prefix' and 'alphabet' since they both are found in
         * 'type' attributes within 'seq' elements. See project/config.xml for
         * examples.
         */
        switch ($setting) {
        case 'alphabet':
            $seqAttributes = array_filter(
                self::_getSeqAttribute($idStructure, 'type'),
                function ($x) {
                    return $x === 'alpha'
                        || $x === 'alphanumeric'
                        || $x === 'numeric';
                }
            );
            break;
        case 'prefix':
            $seqAttributes = array_filter(
                self::_getSeqAttribute($idStructure, 'type'),
                function ($x) {
                    return $x === 'static'
                        || $x === 'siteAbbrev'
                        || $x === 'projectAbbrev';
                }
            );
            break;
        default:
            /* Other settings (i.e. 'length', 'min', 'max') can be extracted
             * directly as they are stored within distinct attributes.
             */
            $seqAttributes = self::_getSeqAttribute(
                $idStructure,
                $setting
            );
            break;
        }

        // Validation
        if (count($seqAttributes) > 1) {
            throw new \ConfigurationException(
                'Too many values found for config setting: ' . $setting
            );
        }

        $val = array_pop($seqAttributes);
        if ($val === null) {
            return null;
        }
        return strval($val);
    }

    /**
     * Traverse the $idStructure array and collect all values that exist
     * for $setting.
     *
     * @param array<array<array<string>>> $idStructure Settings concerning ID
     *                                                 structure extracted from
     *                                                 project/config.xml
     * @param string                      $setting     The name of the variable
     *                                                 for which we want the
     *                                                 value.
     *
     * @return array<int,string> The value(s) corresponding to $setting.
     */
    private static function _getSeqAttribute(
        array $idStructure,
        string $setting
    ): array {
        $seqAttributes = [];
        foreach ($idStructure as $seq) {
            if (isset($seq['@'][$setting])) {
                $seqAttributes[] = $seq['@'][$setting];
            }
        }
        return $seqAttributes;
    }

    /**
     * Initializes the alphabet property.
     *
     * @return array<int,int|float|string>
     */
    private function _getAlphabet(): array
    {
        $alphabet = $this->_getIDSetting('alphabet');
        if (!is_array($alphabet)) {
            throw new \ConfigurationException(
                'Expecting variable $alphabet to be an array but got '
                . gettype($this->alphabet)
            );
        }
        return $alphabet;
    }

    /**
     * Returns the value to be used for the length property.
     *
     * @return int
     */
    private function _getLength()
    {
        $length = $this->_getIDSetting('length') ?? self::LENGTH;
        return intval($length);
    }

    /**
     * Returns the value for the alphabet property.
     *
     * @return string
     */
    private function _getGeneration(): string
    {
        $generation = $this->_getIDSetting('generation');
        if (!in_array($generation, ['sequential', 'random'], true)) {
            throw new \ConfigurationException(
                'Generation method must be either `sequential` or `random`.'
            );
        }
        return $generation;
    }

    /**
     * Returns the prefix to be use for the prefix property.
     *
     * @return string
     */
    private function _getPrefix(): string
    {
        $val = $this->_getIDSetting('prefix');
        if (is_array($val)) {
            throw new \ConfigurationException(
                'Did not expect prefix to be an array'
            );
        }
        return strval($val);
    }
    /**
     * Returns the minimum value for the identifier.
     *
     * @return string
     */
    private function _getMinValue(): string
    {
        $val = $this->_getIDSetting('min');
        if (is_array($val)) {
            throw new \ConfigurationException(
                'Did not expect min to be an array'
            );
        }
        return strval(
            $val ??
            str_repeat(strval($this->alphabet[0]), intval($this->length))
        );
    }

    /**
     * Returns the maximum value for the identifier.
     *
     * @return string
     */
    private function _getMaxValue(): string
    {
        $val = $this->_getIDSetting('max');
        if (is_array($val)) {
            throw new \ConfigurationException(
                'Did not expect max to be an array'
            );
        }
        return strval(
            $val ??
            str_repeat(
                strval($this->alphabet[count($this->alphabet) - 1]),
                intval($this->length)
            )
        );
    }
}
