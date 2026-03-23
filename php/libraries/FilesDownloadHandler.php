<?php declare(strict_types=1);

namespace LORIS;

use \Psr\Http\Message\ResponseInterface;
use \Psr\Http\Message\ServerRequestInterface;
use \Psr\Http\Server\RequestHandlerInterface;

/**
 * This class handles files being downloaded from LORIS. It should
 * serve as the ONLY way that files are downloaded so that all file downloading
 * functionality can occur on a well-tested foundation.
 *
 * @license http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 */
class FilesDownloadHandler implements RequestHandlerInterface
{

    const ERROR_EMPTY_FILENAME = 'Invalid filename: cannot be empty';
    const ERROR_FILE_NOT_FILE  = 'File requested is not a file';
    /**
     * The target download directory.
     *
     * @var \SplFileInfo
     */
    protected $downloadDirectory;

    /**
     * Create new instance of a File Downloader.
     *
     * @param \SplFileInfo $downloadDirectory The target download directory
     */
    public function __construct(\SplFileInfo $downloadDirectory)
    {
        if (! $downloadDirectory->isDir()) {
            throw new \LorisException(
                sprintf(
                    "Download directory %s is not a directory",
                    htmlentities($downloadDirectory->getPathname())
                )
            );
        }

        if (! $downloadDirectory->isReadable()) {
            throw new \LorisException(
                sprintf(
                    "Download directory %s is not readable",
                    htmlentities($downloadDirectory->getPathname())
                )
            );
        }
        $this->downloadDirectory = $downloadDirectory;
    }

    /**
     * Given an HTTP request, serve the file to the client.
     *
     * @param ServerRequestInterface $request An HTTP Request that contains files.
     *
     * @return ResponseInterface
     */
    public function handle(ServerRequestInterface $request) : ResponseInterface
    {
        if ($request->getMethod() != "GET") {
            return new \LORIS\Http\Response\JSON\MethodNotAllowed(
                ['GET']
            );
        }

        $filename = $request->getAttribute('filename');

        if (empty($filename)) {
            return new \LORIS\Http\Response\JSON\BadRequest(
                self::ERROR_EMPTY_FILENAME
            );
        }

        // [Security Fix] Prevent directory traversal
        // Get base path and ensure it ends with a separator
        $baseDir = rtrim($this->downloadDirectory->getPathname(), DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR;
        
        $filename = urldecode(strval($filename));
        
        $unifiedBaseDir = str_replace('\\', '/', $baseDir);
        $unifiedPath = $unifiedBaseDir . $filename;
        $unifiedPath = str_replace('\\', '/', $unifiedPath);

        $pattern = '/\/\.(?:\.)?\/+/';
        while (preg_match($pattern, $unifiedPath)) {
            $unifiedPath = preg_replace($pattern, '/', $unifiedPath);
        }
        
        $unifiedPath = preg_replace('/\/+/', '/', $unifiedPath);

        if (strpos($unifiedPath, $unifiedBaseDir) !== 0) {
            return new \LORIS\Http\Response\JSON\Forbidden("Access denied: Path traversal detected.");
        }

        $targetPath = str_replace('/', DIRECTORY_SEPARATOR, $unifiedPath);

        // [Security Fix End]

        if (!file_exists($targetPath)) {
            return new \LORIS\Http\Response\JSON\NotFound();
        }

        if (!is_readable($targetPath)) {
            return new \LORIS\Http\Response\JSON\Forbidden();
        }

        if (!is_file($targetPath)) {
            return new \LORIS\Http\Response\JSON\BadRequest(
                self::ERROR_FILE_NOT_FILE
            );
        }

        $mime = mime_content_type($targetPath);
        return (new \LORIS\Http\Response\JSON\OK())
            ->withHeader(
                'Content-Disposition',
                'attachment; filename=' . urlencode(basename($filename))
            )
            ->withHeader(
                'Content-Type',
                $mime !== false ? $mime : 'application/octet-stream'
            )
            ->withBody(new \LORIS\Http\FileStream($targetPath));
    }
}
