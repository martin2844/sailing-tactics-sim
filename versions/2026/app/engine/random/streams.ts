export interface RandomState {gameplay: number; waves: number; presentation: number}

/** The recovered CRT distribution, with ownership explicit in the 2026 engine. */
export class RandomStream {
  private value: number;
  constructor(seed: number) { this.value = seed >>> 0; }
  get state(): number { return this.value; }
  set state(seed: number) { this.value = seed >>> 0; }
  srand(seed: number): void { this.state = seed; }
  rand(): number {
    this.value = (Math.imul(this.value, 214013) + 2531011) >>> 0;
    return (this.value >>> 16) & 0x7fff;
  }
}

function deriveSeed(seed: number, name: string): number {
  let value = (seed >>> 0) ^ 2166136261;
  for (const character of name) value = Math.imul(value ^ character.charCodeAt(0), 16777619) >>> 0;
  return value >>> 0;
}

export class RandomStreams {
  readonly gameplay: RandomStream;
  readonly waves: RandomStream;
  readonly presentation: RandomStream;
  constructor(seed: number) {
    if (!Number.isSafeInteger(seed)) throw new TypeError('Simulation seed must be an integer');
    this.gameplay = new RandomStream(seed);
    this.waves = new RandomStream(deriveSeed(seed, 'tact2026/waves/v1'));
    this.presentation = new RandomStream(deriveSeed(seed, 'tact2026/presentation/v1'));
  }
  snapshot(): RandomState {
    return {gameplay: this.gameplay.state, waves: this.waves.state, presentation: this.presentation.state};
  }
  restore(state: RandomState): void {
    for (const key of ['gameplay', 'waves', 'presentation'] as const) {
      const value = state[key]; if (!Number.isInteger(value) || value < 0 || value > 0xffffffff) throw new TypeError('Invalid random checkpoint');
    }
    this.gameplay.state = state.gameplay;
    this.waves.state = state.waves;
    this.presentation.state = state.presentation;
  }
}
