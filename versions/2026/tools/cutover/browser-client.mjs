/** Small RPC client shared by both built worker artifacts. No rendered app,
 * graphics timing or production EngineClient behavior participates in pairing.
 */
export class CutoverClient {
  constructor(workerUrl, generation) {
    this.worker = new Worker(workerUrl, {type: 'module'});
    this.generation = generation;
    this.nextId = 1;
    this.pending = new Map();
    this.last = null;
    this.failure = null;
    this.worker.onerror = event => this.fail(new Error(event.message));
    this.worker.onmessage = ({data: message}) => {
      if (message.generation !== generation) return;
      const {type, data} = message;
      if (type === 'panel') { data.bitmap.close(); return; }
      if (type === 'snapshot') this.last = data;
      else if (type === 'ready') this.readyResolve(data);
      else if (type === 'error') this.fail(new Error(data));
      else if (type === 'reply') {
        const pending = this.pending.get(data.id);
        if (pending) {
          clearTimeout(pending.timer);
          this.pending.delete(data.id);
          pending.resolve(data.value);
        }
      }
    };
  }

  async initialize(lane, settings, fleet, trace = false, geometryContacts = true) {
    const response = await fetch('/candidate/scenarios/' + (fleet === 15 ? 'round-lake-15' : 'round-lake-5') + '.json');
    if (!response.ok) throw new Error('Missing declared scenario');
    const scenario = await response.json();
    return new Promise((resolve, reject) => {
      const timer = setTimeout(() => this.fail(new Error('Worker initialization timed out')), 60000);
      this.readyResolve = value => { clearTimeout(timer); this.readyReject = null; resolve(value); };
      this.readyReject = error => { clearTimeout(timer); reject(error); };
      this.worker.postMessage({type: 'init', data: {
        generation: this.generation, fleet, manual: true, phaseTrace: trace,
        geometryContacts, legacyBase: new URL('/' + lane + '/legacy/', location.href).href,
        scenario, settings,
      }});
    });
  }

  request(type, data) {
    if (this.failure) return Promise.reject(this.failure);
    const id = this.nextId++;
    return new Promise((resolve, reject) => {
      const timer = setTimeout(() => {
        this.pending.delete(id);
        reject(new Error('Worker request timed out: ' + type));
      }, 60000);
      this.pending.set(id, {resolve, reject, timer});
      this.worker.postMessage({generation: this.generation, type, data, id});
    });
  }

  send(type, data) {
    if (this.failure) throw this.failure;
    this.worker.postMessage({generation: this.generation, type, data});
  }

  fail(error) {
    this.failure = error;
    this.readyReject?.(error);
    for (const pending of this.pending.values()) {
      clearTimeout(pending.timer);
      pending.reject(error);
    }
    this.pending.clear();
  }

  dispose() {
    this.fail(new Error('Comparison client disposed'));
    this.worker.terminate();
  }
}
