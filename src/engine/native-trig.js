import { Float80 } from '../runtime/float80.js';

const hexBytes = hex => {
  if (typeof hex !== 'string' || !/^[0-9a-f]{20}$/i.test(hex)) throw new TypeError('Native x87 result must contain ten hexadecimal bytes');
  return Uint8Array.from(hex.match(/../g), pair => Number.parseInt(pair, 16));
};
let installedReference;

function decodeReference(data) {
  if (data?.provenance?.authoritative_engine !== 'native-x87') throw new TypeError('Native x87 trigonometry requires hardware-captured reference data');
  if (data.degreeFactorAddress !== 0x00484d40 || data.degreeFactorBits !== '3152cb9156df913f') throw new TypeError('Unexpected original degree-factor reference');
  const angles = new Map();
  for (const [key, pair] of Object.entries(data.angles)) {
    const angle = Number(key);
    if (!Number.isInteger(angle) || String(angle) !== key) throw new TypeError('Trigonometric reference angle must be a signed integer');
    angles.set(angle, Object.freeze({ sine: Float80.fromBytes(hexBytes(pair.sineBits)), cosine: Float80.fromBytes(hexBytes(pair.cosineBits)) }));
  }
  return angle => {
      if (!Number.isInteger(angle) || angle < -2147483648 || angle > 2147483647) throw new RangeError('Original native trigonometric input must be a signed 32-bit integer');
      const result = angles.get(angle);
      if (!result) throw new RangeError(`No original native x87 trigonometric capture for integer angle ${angle}`);
      return result;
  };
}

/** Decode hardware captures for unspilled and binary64-spilled radian inputs. */
export function createCapturedTrig(extendedCapture, storedCapture, forceCapture) {
  const extended = decodeReference(extendedCapture);
  const stored = storedCapture ? decodeReference(storedCapture) : undefined;
  let radians;
  if (forceCapture) {
    if (forceCapture.provenance?.authoritative_engine !== 'native-x87' || forceCapture.degreeFactorAddress !== 0x00484d40 || forceCapture.degreeFactorBits !== '3152cb9156df913f') throw new TypeError('Unexpected native x87 fractional-angle reference');
    radians = new Map(Object.entries(forceCapture.radians).map(([key, pair]) => [key, Float80.fromBytes(hexBytes(pair.sineBits))]));
  }
  return Object.freeze({
    extended,
    stored(angle) {
      if (!stored) throw new Error('Load assets/data/x87-stored-trig.json before using binary64-spilled trigonometric inputs');
      return stored(angle);
    },
    sineRadians(value) {
      if (!radians) throw new Error('Load assets/data/x87-force-trig.json before using fractional force angles');
      const key = Array.from(value.toBytes(), byte => byte.toString(16).padStart(2, '0')).join('');
      const result = radians.get(key);
      if (!result) throw new RangeError(`No original native x87 FSIN capture for extended radian input ${key}`);
      return result;
    },
  });
}

/** Install once after loading assets/data/x87-trig.json; no approximate fallback is used. */
export function installNativeTrigReference(reference) {
  if (typeof reference?.extended !== 'function' || typeof reference?.stored !== 'function') throw new TypeError('Native x87 reference must provide extended(angle) and stored(angle)');
  installedReference = reference;
}

export function setNativeTrigReference(extendedCapture, storedCapture, forceCapture) {
  const reference = createCapturedTrig(extendedCapture, storedCapture, forceCapture);
  installNativeTrigReference(reference);
  return reference;
}

export function nativeTrig(angle, { stored = false, trig = installedReference } = {}) {
  const reference = trig;
  if (!reference) throw new Error('Load and install assets/data/x87-trig.json before calling trigonometric engine routines');
  return stored ? reference.stored(angle) : reference.extended(angle);
}

export function nativeSineRadians(value, { trig = installedReference } = {}) {
  if (!trig) throw new Error('Load and install native x87 references before using fractional force angles');
  return trig.sineRadians(value);
}

export const createNativeTrigReference = createCapturedTrig;
