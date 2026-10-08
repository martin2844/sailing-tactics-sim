import * as THREE from 'three';
import type {BoatModel} from '../boat-model';
import {MODEL_QUANTUM, type NativeModelPacket} from '../native-models';
import type {BoatView} from '../protocol';
import {BOAT_MODEL_SCALE, WATER_SURFACE_Y} from '../world-objects';
import {OPTIMIST} from './optimist-spec';
import {OptimistStudy} from './optimist-study';

interface RigPose {trim: number; heel: number; penalty: boolean}
const degrees = THREE.MathUtils.radToDeg;
const radians = THREE.MathUtils.degToRad;
// Preserve the original four-unit hull length in the simulation's coordinates.
export const OPTIMIST_WORLD_SCALE = 4 * BOAT_MODEL_SCALE / OPTIMIST.length;
const scale = OPTIMIST_WORLD_SCALE;
const waterline = .13;

/** The reviewed metre-scale model, driven by the existing simulation's rig. */
export class OptimistBoatMesh implements BoatModel {
 readonly group = new THREE.Group();
 readonly model = new OptimistStudy();
 readonly bounds = new THREE.Box3();
 private previous?: RigPose;
 private current?: RigPose;
 private body = new THREE.Group();
 get waterHullHeel(){return this.body.rotation.z;}
 constructor() {
  this.group.scale.setScalar(scale);
  this.body.position.y = WATER_SURFACE_Y / scale;
  this.model.group.position.y = -waterline;
  this.body.add(this.model.group);
  this.group.add(this.body);
 }
 update(packet: NativeModelPacket, start: number, end: number) {
  const point = (index: number) => new THREE.Vector3().fromArray(packet.positions, index * 3).divideScalar(MODEL_QUANTUM);
  let deck: THREE.Vector3[] | undefined, sail: THREE.Vector3[] | undefined, penalty = false;
  for (let at = start; at < end;) {
   const op = packet.records[at], part = packet.records[at + 1], fill = packet.colors[packet.records[at + 2]], count = packet.records[at + 6];
   at += 7;
   if (op === 1 && ((part === 4 && count === 11) || part === 5)) {
    const points = Array.from(packet.records.subarray(at, at + count), point);
    if (part === 4) deck = points;
    else if (!sail) {sail = points; penalty = fill === 0;}
   }
   at += count + (op === 3 ? 2 : 0);
  }
  if (!deck || !sail) throw new Error('Optimist model packet is missing its deck or mainsail');
  const beam = deck[3].clone().sub(deck[8]);
  const heel = Math.atan2(beam.y, beam.x);
  const boom = sail.at(-1)!.clone().sub(sail[0]).applyAxisAngle(new THREE.Vector3(0, 0, 1), -heel);
  const pose = {trim: degrees(Math.atan2(boom.x, boom.z)), heel: degrees(heel), penalty};
  const first = !this.current;
  this.previous = this.current ?? pose;
  this.current = pose;
  if (first) this.interpolate(1);
 }
 interpolate(alpha: number, boat?: BoatView, time = 0) {
  if (!this.current || !this.previous) return;
  const delta = ((this.current.trim - this.previous.trim + 540) % 360) - 180;
  let trim = this.previous.trim + delta * alpha;
  let luff = 0;
  if (boat) {
   const relative = ((boat.windFrom - boat.heading + 540) % 360) - 180;
   const released = THREE.MathUtils.clamp((35 - Math.abs(relative)) / 30, 0, 1);
   const difference = ((-relative - trim + 540) % 360) - 180;
   trim += released * (difference + degrees(Math.sin(time * 3.1 + boat.id) * .12));
   luff = Math.max(released, THREE.MathUtils.clamp(boat.luff / 90, 0, 1));
  }
  this.body.rotation.z = radians(this.previous.heel + (this.current.heel - this.previous.heel) * alpha);
  this.model.animate({trim, heel: 0, luff, time, penalty: this.current.penalty, crew: true}, ((boat?.id ?? 1) * .0618) % .1, this.current.trim);
  this.body.updateMatrix();this.model.group.updateMatrix();
  // Bounds belong to the outer group, like the native model's geometry bounds.
  this.bounds.makeEmpty();
  for (const mesh of [this.model.hull, this.model.rig, this.model.sailor, this.model.window]) {
   mesh.geometry.computeBoundingBox();
   const transform = new THREE.Matrix4().multiplyMatrices(this.body.matrix, this.model.group.matrix);
   this.bounds.union(mesh.geometry.boundingBox!.clone().applyMatrix4(transform));
  }
 }
 dispose() {this.model.dispose(); this.group.removeFromParent();}
}
