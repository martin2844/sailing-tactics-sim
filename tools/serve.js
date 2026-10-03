import { createServer } from 'node:http';
import { readFile, realpath, stat } from 'node:fs/promises';
import { dirname, extname, resolve, sep } from 'node:path';
import { fileURLToPath } from 'node:url';

const root = resolve(dirname(fileURLToPath(import.meta.url)), '..');
const host = process.env.TACT_HOST || '127.0.0.1';
const port = Number(process.env.TACT_PORT || 8765);
const mime = {
  '.html': 'text/html; charset=utf-8', '.js': 'text/javascript; charset=utf-8',
  '.css': 'text/css; charset=utf-8', '.json': 'application/json; charset=utf-8',
  '.jsonl': 'application/x-ndjson; charset=utf-8', '.png': 'image/png',
  '.ico': 'image/x-icon', '.cur': 'image/x-icon', '.bmp': 'image/bmp',
  '.wav': 'audio/wav', '.c': 'text/plain; charset=utf-8',
  '.md': 'text/plain; charset=utf-8', '.txt': 'text/plain; charset=utf-8',
};
export const server = createServer(async (request, response) => {
  if (!['GET', 'HEAD'].includes(request.method)) {
    response.writeHead(405, { Allow: 'GET, HEAD' });
    response.end('Method not allowed');
    return;
  }
  try {
    const pathname = decodeURIComponent(new URL(request.url, 'http://localhost').pathname);
    const candidate = resolve(root, '.' + (pathname === '/' ? '/index.html' : pathname));
    if (!candidate.startsWith(root + sep)) throw Object.assign(new Error('Forbidden'), { status: 403 });
    const file = await realpath(candidate);
    if (!file.startsWith(root + sep) || file.includes(`${sep}.git${sep}`))
      throw Object.assign(new Error('Forbidden'), { status: 403 });
    const metadata = await stat(file);
    if (!metadata.isFile()) throw Object.assign(new Error('Not found'), { status: 404 });
    const bytes = request.method === 'HEAD' ? null : await readFile(file);
    response.writeHead(200, {
      'Content-Type': mime[extname(file)] || 'application/octet-stream',
      'Content-Length': metadata.size,
      'Cache-Control': 'no-store',
      'X-Content-Type-Options': 'nosniff',
    });
    response.end(bytes);
  } catch (error) {
    const status = error.status || (error.code === 'ENOENT' ? 404 : 500);
    response.writeHead(status, { 'Content-Type': 'text/plain; charset=utf-8' });
    response.end(status === 404 ? 'Not found' : status === 403 ? 'Forbidden' : 'Server error');
  }
});
server.on('error', (error) => { console.error(error.message); process.exitCode = 1; });
server.listen(port, host, () => console.log(`Tact browser workbench: http://${host}:${server.address().port}`));
