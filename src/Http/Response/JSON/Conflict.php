<?php declare(strict_types=1);

/**
 * File contains the PSR15 ResponseInterface implementation for
 * Conflict responses.
 *
 * PHP Version 7
 *
 * @category PSR15
 * @package  Http
 * @author   Xavier Lecours Boucher <xavier.lecours@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 *
 * @see https://www.php-fig.org/psr/psr-7/
 * @see https://www.php-fig.org/psr/psr-15/
 */
namespace LORIS\Http\Response\JSON;

use \LORIS\Http\Response\JsonResponse;

/**
 * A LORIS Http Response is an implementation of the PSR15 ResponseInterface
 * to use in LORIS specific for 409 Conflict.
 *
 * @category PSR15
 * @package  Http
 * @author   Xavier Lecours Boucher <xavier.lecours@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
class Conflict extends JsonResponse
{
    /**
     * Create a Json response specific to 409 Conflict
     *
     * @param string $msg The error message
     */
    public function __construct(string $msg = 'conflict')
    {
        $body = array('error' => $msg);
        parent::__construct($body, 409);
    }
}
