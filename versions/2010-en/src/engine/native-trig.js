import { Float80 } from '../../../../src/runtime/float80.js';
import { ORIGINAL_SOURCE_SHA256 } from '../runtime/original-data.js';

function decodeBits(bits) {
  if (typeof bits !== 'string' || !/^[0-9a-f]{20}$/i.test(bits)) {
    throw new TypeError('An original x87 result must contain ten hexadecimal bytes');
  }
  return Float80.fromBytes(Uint8Array.from(bits.match(/../g), pair => Number.parseInt(pair, 16)));
}

function validateCapture(data) {
  if (data?.provenance?.authoritative_engine !== 'native-x87' ||
      data.provenance.sha256 !== ORIGINAL_SOURCE_SHA256 || data.provenance.control_word !== '0x027f' ||
      data.degreeFactorAddress !== 0x4cc568 || data.degreeFactorBits !== '3152cb9156df913f') {
    throw new TypeError('Unexpected 2010 native x87 reference');
  }
}

function decodeAngles(data) {
  validateCapture(data);
  const angles = new Map();
  for (const [key, pair] of Object.entries(data.angles)) {
    const angle = Number(key);
    if (!Number.isInteger(angle) || String(angle) !== key || angle < -2147483648 || angle > 2147483647) {
      throw new TypeError('A native trigonometric angle must be a signed integer');
    }
    angles.set(angle, Object.freeze({ sine: decodeBits(pair.sineBits), cosine: decodeBits(pair.cosineBits) }));
  }
  return angle => {
    if (!Number.isInteger(angle) || angle < -2147483648 || angle > 2147483647) {
      throw new RangeError('Original trigonometric input must be a signed integer');
    }
    const pair = angles.get(angle);
    if (!pair) throw new RangeError(`No original 2010 native trigonometric capture for ${angle}`);
    return pair;
  };
}

export function createCapturedTrig(extendedCapture, storedCapture, forceCapture) {
  const extended = decodeAngles(extendedCapture);
  const stored = storedCapture ? decodeAngles(storedCapture) : undefined;
  let radians;
  if (forceCapture) {
    validateCapture(forceCapture);
    radians = new Map(Object.entries(forceCapture.radians).map(([key, pair]) => [key, decodeBits(pair.sineBits)]));
  }
  return Object.freeze({
    extended,
    stored(angle) {
      if (!stored) throw new Error('Load the 2010 binary64-spilled trigonometric reference');
      return stored(angle);
    },
    sineRadians(value) {
      if (!radians) throw new Error('Load the 2010 fractional force reference');
      const key = Array.from(value.toBytes(), byte => byte.toString(16).padStart(2, '0')).join('');
      const result = radians.get(key);
      if (!result) throw new RangeError(`No original 2010 native FSIN capture for ${key}`);
      return result;
    },
  });
}
