/**
 * Copy the original caller's observed retained data into the persistent host
 * frame. drawProjectedShoreline updates these same fields at the original
 * aliasing stores; callers must keep the returned object between paints.
 */
export function createShorelineStack(reference) {
  const stack = {};
  for (const field of ['centerProjectedY', 'previousX', 'previousTreeY']) {
    const value = reference.initialStack?.[field];
    if (!Number.isInteger(value) || value < -0x80000000 || value > 0x7fffffff) {
      throw new RangeError(`Original shoreline reference requires signed I32 ${field}`);
    }
    stack[field] = value;
  }
  return stack;
}
