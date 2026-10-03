import { AddressSpaceMemory } from '../../../../src/runtime/memory.js';

export const ORIGINAL_SOURCE_SHA256 = 'd707a1e1b5894adf880470dd3af3104bc2e256aafaa8932090b8a11d137ac787';
export const IMAGE_BASE = 0x400000;
export const IMAGE_SIZE = 0x21c000;
export const MUTABLE_BASE = 0x4da000;
export const MUTABLE_SIZE = 0x60588;

const layout = Object.freeze([
  Object.freeze({ section: '.rdata', file: 'original-constants.bin', address: 0x4c8000,
    size: 72704, sha256: 'b7bb7a445e8d1342cd99094fd4d914b964caeb424a84d3b651b29336b3c39d76' }),
  Object.freeze({ section: '.data', file: 'original-initial-state.bin', address: 0x4da000,
    size: 394632, sha256: 'dddcfbf8acf3e2dcc09ef61ae6d760bab1f849673006617bcfd9082708312a8d' }),
  Object.freeze({ section: '.english', file: 'original-english-data.bin', address: 0x5aa000,
    size: 466432, sha256: '19df0a1a84d908cd1a78765a8380480be3487c4b3a987da02478c80e6a452216' }),
]);

export function validateManifest(manifest) {
  if (manifest?.sourceSha256 !== ORIGINAL_SOURCE_SHA256 || manifest.imageBase !== IMAGE_BASE ||
      manifest.imageSize !== IMAGE_SIZE || manifest.segments?.length !== layout.length) {
    throw new Error('The preserved 2010 English data profile differs');
  }
  for (let index = 0; index < layout.length; index++) {
    for (const [key, value] of Object.entries(layout[index])) {
      if (manifest.segments[index]?.[key] !== value) {
        throw new Error(`The preserved 2010 English segment ${index} differs at ${key}`);
      }
    }
  }
  return manifest;
}

/** Data mapping only; browser behavior is implemented by JavaScript functions. */
export function loadOriginalData(manifest, segments) {
  validateManifest(manifest);
  const memory = new AddressSpaceMemory(IMAGE_SIZE, IMAGE_BASE);
  for (const row of layout) {
    const bytes = segments.get(row.file);
    if (!(bytes instanceof Uint8Array) || bytes.byteLength !== row.size) {
      throw new Error(`Invalid original 2010 data segment ${row.file}`);
    }
    memory.writeBytes(row.address, bytes);
  }
  return memory;
}

export async function fetchOriginalData({ fetch: fetcher = globalThis.fetch, crypto = globalThis.crypto } = {}) {
  const base = new URL('../../assets/data/', import.meta.url);
  const get = async file => {
    const response = await fetcher(new URL(file, base));
    if (!response.ok) throw new Error(`Could not load ${file}: ${response.status}`);
    return response;
  };
  const manifest = validateManifest(await (await get('original-memory.json')).json());
  const entries = await Promise.all(manifest.segments.map(async row => {
    const bytes = new Uint8Array(await (await get(row.file)).arrayBuffer());
    const digest = new Uint8Array(await crypto.subtle.digest('SHA-256', bytes));
    const hash = Array.from(digest, byte => byte.toString(16).padStart(2, '0')).join('');
    if (hash !== row.sha256) throw new Error(`Original 2010 data integrity failed for ${row.file}`);
    return [row.file, bytes];
  }));
  return loadOriginalData(manifest, new Map(entries));
}
