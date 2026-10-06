/** Diagnostic observer for the compatibility engine. Disabled in normal play.
 * Method hooks observe accesses; full phase deltas also cover bypassed stores.
 * Neither source proves complete dependency coverage on its own.
 */
export interface TraceMemory {
  readonly base: number;
  readonly bytes: Uint8Array;
  readI32(address: number): number;
}
export interface TraceRandom {
  readonly state: number;
  rand(): number;
}
export interface MemoryAccess {
  method: string;
  address: number;
  width: number;
  count: number;
}
export interface PixelQuery {
  x: number;
  y: number;
  result: number;
}
export interface PhaseRecord {
  id: number;
  parent: number | null;
  frame: number;
  name: string;
  boat: number | null;
  clock: number;
  rngBefore: number;
  rngAfter: number;
  randomCalls: number;
  randomDigest: number;
  reads: MemoryAccess[];
  writes: MemoryAccess[];
  netChangedWords: number[];
  pixels: PixelQuery[];
  failed: boolean;
}
export interface PhaseTrace {
  format: 1;
  records: PhaseRecord[];
  truncated: boolean;
  limitations: string[];
}
interface OpenPhase {
  record: PhaseRecord;
  before: Uint8Array;
  reads: Map<string, MemoryAccess>;
  writes: Map<string, MemoryAccess>;
}
type Callable = (...args: unknown[]) => unknown;
const widths: Readonly<Record<string, number>> = {
  U8: 1, I8: 1, U16: 2, I16: 2, U32: 4, I32: 4, F32: 4, F64: 8,
};
const limits = { phases: 1000, accessesPerPhase: 20000, pixelsPerPhase: 2000 };
const clockAddress = 0x4f8cd0;

export class PhaseTracer {
  private readonly stack: OpenPhase[] = [];
  private readonly records: PhaseRecord[] = [];
  private readonly restoreHooks: (() => void)[] = [];
  private readonly readClock: () => number;
  private nextId = 1;
  private frame = 0;
  private recording = false;
  private truncated = false;

  private readonly memory: TraceMemory;
  private readonly random: TraceRandom;

  constructor(memory: TraceMemory, random: TraceRandom) {
    this.memory = memory;
    this.random = random;
    this.readClock = memory.readI32.bind(memory, clockAddress);
  }

  install(options: Record<string, unknown>): void {
    if (this.restoreHooks.length) throw new Error('Phase tracing is already installed');
    try {
      for (const [suffix, width] of Object.entries(widths)) {
        for (const kind of ['read', 'write'] as const) {
          const method = kind + suffix;
          this.hook(this.memory, method, (original, args, receiver) => {
            const result = Reflect.apply(original, receiver, args);
            if (receiver !== this.memory) return result;
            this.access(kind, method, Number(args[0]), width);
            return result;
          });
        }
      }
      for (const method of ['readBytes', 'writeBytes', 'moveBytes']) {
        this.hook(this.memory, method, (original, args, receiver) => {
          const result = Reflect.apply(original, receiver, args);
          if (receiver !== this.memory) return result;
          if (method === 'readBytes') this.access('read', method, Number(args[0]), Number(args[1]));
          else if (method === 'writeBytes') {
            const source = args[1] as { byteLength: number };
            this.access('write', method, Number(args[0]), source.byteLength);
          } else {
            this.access('read', method, Number(args[1]), Number(args[2]));
            this.access('write', method, Number(args[0]), Number(args[2]));
          }
          return result;
        });
      }
      this.hook(this.random, 'rand', (original, args, receiver) => {
        const result = Reflect.apply(original, receiver, args) as number;
        if (receiver !== this.random) return result;
        // Each ancestor includes its children's draws, preserving phase totals.
        for (const phase of this.stack) {
          phase.record.randomCalls++;
          phase.record.randomDigest = Math.imul(phase.record.randomDigest ^ result, 16777619) >>> 0;
        }
        return result;
      });
      for (const [name, callback] of Object.entries(options)) {
        if (typeof callback !== 'function' || !/^(draw|update|initialize|integrate|saveRaceState|restoreRaceState|respawn)/.test(name)) continue;
        this.hook(options, name, (original, args, receiver) => {
          // Private geometry/coach/model copies must not pollute master traces.
          if (args[0] !== this.memory) return Reflect.apply(original, receiver, args);
          const boat = /^(updateBoat|updatePlayer)/.test(name) && typeof args[1] === 'number' ? args[1] : null;
          return this.phase(name, () => Reflect.apply(original, receiver, args), boat);
        });
      }
    } catch (error) {
      this.dispose();
      throw error;
    }
  }

  /** Surface adapters call this after forwarding the actual pixel query. */
  pixel(x: number, y: number, result: number): void {
    for (const phase of this.stack) {
      if (phase.record.pixels.length < limits.pixelsPerPhase) phase.record.pixels.push({ x, y, result });
      else this.truncated = true;
    }
  }

  paint<T>(frame: number, callback: () => T): T {
    this.frame = frame;
    return this.phase('paint', callback);
  }

  start(): void {
    if (this.stack.length) throw new Error('Cannot reset an active phase trace');
    this.records.length = 0;
    this.nextId = 1;
    this.truncated = false;
    this.recording = true;
  }

  stop(): PhaseTrace {
    if (this.stack.length) throw new Error('Cannot stop an active phase trace');
    this.recording = false;
    return {
      format: 1,
      records: this.records.splice(0),
      truncated: this.truncated,
      limitations: [
        'Method access hooks do not intercept direct DataView/byte-array operations; phase net deltas supplement them.',
        'Net deltas do not identify restored intermediate direct writes or all computed aliases.',
        'Access lists aggregate method/address/width counts; they do not contain every intermediate value or access order.',
        'Callbacks not dispatched through observed options are attributed to their enclosing phase.',
        'Unvisited branches and dependencies remain unclassified; this is not a proof of drawing purity.',
        'RNG digest is diagnostic only; acceptance compares full images and exact RNG state separately.',
      ],
    };
  }

  dispose(): void {
    this.recording = false;
    for (const restore of this.restoreHooks.splice(0).reverse()) restore();
  }

  private phase<T>(name: string, callback: () => T, boat: number | null = null): T {
    if (!this.recording) return callback();
    if (this.nextId > limits.phases) {
      this.truncated = true;
      return callback();
    }
    const record: PhaseRecord = {
      id: this.nextId++, parent: this.stack.at(-1)?.record.id ?? null,
      frame: this.frame, name, boat, clock: this.readClock(),
      rngBefore: this.random.state, rngAfter: this.random.state,
      randomCalls: 0, randomDigest: 2166136261,
      reads: [], writes: [], netChangedWords: [], pixels: [], failed: false,
    };
    const phase: OpenPhase = { record, before: this.memory.bytes.slice(), reads: new Map(), writes: new Map() };
    this.stack.push(phase);
    try { return callback(); }
    catch (error) { record.failed = true; throw error; }
    finally {
      this.stack.pop();
      record.rngAfter = this.random.state;
      record.reads = [...phase.reads.values()];
      record.writes = [...phase.writes.values()];
      const after = this.memory.bytes;
      for (let i = 0; i < after.length; i += 4) {
        const end = Math.min(i + 4, after.length);
        for (let byte = i; byte < end; byte++) {
          if (phase.before[byte] !== after[byte]) { record.netChangedWords.push(this.memory.base + i); break; }
        }
      }
      this.records.push(record);
    }
  }

  private access(kind: 'read' | 'write', method: string, address: number, width: number): void {
    for (const phase of this.stack) {
      const accesses = kind === 'read' ? phase.reads : phase.writes;
      const key = `${method}:${address}:${width}`;
      const existing = accesses.get(key);
      if (existing) existing.count++;
      else if (accesses.size < limits.accessesPerPhase) accesses.set(key, { method, address, width, count: 1 });
      else this.truncated = true;
    }
  }

  private hook(owner: object, name: string, invoke: (original: Callable, args: unknown[], receiver: unknown) => unknown): void {
    const target = owner as Record<string, unknown>;
    const original = target[name];
    if (typeof original !== 'function') return;
    const descriptor = Object.getOwnPropertyDescriptor(owner, name);
    const replacement = function(this: unknown, ...args: unknown[]) { return invoke(original as Callable, args, this); };
    Object.defineProperty(owner, name, { configurable: true, writable: true, value: replacement, enumerable: descriptor?.enumerable ?? false });
    this.restoreHooks.push(() => {
      if (descriptor) Object.defineProperty(owner, name, descriptor);
      else Reflect.deleteProperty(owner, name);
    });
  }
}
