import {createServer} from 'node:http';
import {readFile, readdir} from 'node:fs/promises';
import {createHash} from 'node:crypto';
import {resolve, sep, extname} from 'node:path';

const types = {'.html': 'text/html', '.js': 'text/javascript', '.json': 'application/json', '.bin': 'application/octet-stream', '.png': 'image/png'};

async function workerArtifact(dist) {
  const files = (await readdir(resolve(dist, 'assets'))).filter(file => /^engine\.worker-.*\.js$/.test(file));
  if (files.length !== 1) throw new Error('Expected one built engine worker: ' + dist);
  const file = 'assets/' + files[0];
  const bytes = await readFile(resolve(dist, file));
  return {file, sha256: createHash('sha256').update(bytes).digest('hex')};
}

export async function withCutoverServer(candidate, reference, callback) {
  const artifacts = {candidate: await workerArtifact(candidate), reference: await workerArtifact(reference)};
  const roots = {candidate: resolve(candidate), reference: resolve(reference)};
  const server = createServer(async (request, response) => {
    try {
      const url = new URL(request.url, 'http://localhost');
      if (url.pathname === '/') {
        response.writeHead(200, {'Content-Type': 'text/html'});
        response.end('<!doctype html><title>Tact isolated engine comparison</title>');
        return;
      }
      if (url.pathname === '/client.mjs') {
        response.writeHead(200, {'Content-Type': 'text/javascript'});
        response.end(await readFile(new URL('./browser-client.mjs', import.meta.url)));
        return;
      }
      if (url.pathname.startsWith('/candidate/scenarios/')) {
        const name = url.pathname.split('/').at(-1);
        if (!['round-lake-5.json', 'round-lake-15.json'].includes(name)) throw new Error('Invalid scenario');
        response.writeHead(200, {'Content-Type': 'application/json'});
        response.end(await readFile(new URL('../../config/scenarios/' + name, import.meta.url)));
        return;
      }
      const [, lane, ...segments] = decodeURIComponent(url.pathname).split('/');
      const root = roots[lane];
      if (!root) { response.writeHead(404); response.end(); return; }
      const path = resolve(root, ...segments);
      if (!path.startsWith(root + sep)) { response.writeHead(403); response.end(); return; }
      const bytes = await readFile(path);
      response.writeHead(200, {'Content-Type': types[extname(path)] ?? 'application/octet-stream', 'Cache-Control': 'no-store'});
      response.end(bytes);
    } catch {
      response.writeHead(404); response.end();
    }
  });
  await new Promise((accept, reject) => {
    server.once('error', reject);
    server.listen(0, '127.0.0.1', accept);
  });
  try {
    return await callback({url: 'http://127.0.0.1:' + server.address().port + '/', artifacts});
  } finally {
    await new Promise((accept, reject) => server.close(error => error ? reject(error) : accept()));
  }
}
