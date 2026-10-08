import type * as THREE from 'three';
import type {NativeModelPacket} from './native-models';
import type {BoatView} from './protocol';
import {NativeBoatMesh} from './native-boat-mesh';
import {OptimistBoatMesh} from './models/optimist-boat-mesh';

/** Presentation contract shared by the fleet, starter preview and labels. */
export interface BoatModel {
 readonly group: THREE.Group;
 readonly bounds: THREE.Box3;
 readonly waterHullHeel?: number;
 update(packet: NativeModelPacket, start: number, end: number, classId?: number): void;
 interpolate(alpha: number, boat?: BoatView, time?: number): void;
 dispose(): void;
}
export function createBoatModel(material: THREE.Material, classId?: number): BoatModel {
 return classId === 1 ? new OptimistBoatMesh() : new NativeBoatMesh(material);
}
