import type {NativeVisualPacket} from './native-visuals';
export interface BoatView {id:number;x:number;y:number;heading:number;speed:number;leg:number;finished:number;windFrom:number;windAngle:number;luff:number;boomAngle:number;tack:number}
export interface NativeView {lookDegrees:number;lookMode:number;viewpoint:number;automatic:boolean;otherBoat:number;tacticalZoom:number;tacticalOrientation:number}
export interface CoursePoint {x:number;y:number}
export interface CourseLine {a:CoursePoint;b:CoursePoint}
export interface NativeCourse {marks:CoursePoint[];start:CourseLine;finish:CourseLine;committee:CoursePoint&{heading:number};target:CoursePoint;closeAngle:number;showLaylines:boolean;length:number}
export interface SceneSnapshot {nativeVisuals:NativeVisualPacket;generation:number;sequence:number;time:number;clock:number;pace:number;windDirection:number;windStrength:number;boats:BoatView[];view:NativeView;panel:string|null;sheet:number;sailShape:number;spinnaker:boolean;frozen:boolean;marks:CoursePoint[];course:NativeCourse;configuration:{course:number;wind:number;fleet:number;selector:number;area:number};results:boolean;workMs:number;minimumDelayMs:number;sentAt:number}
export interface Boundary {frame:number;time:number;clock:number;rngState:number;memorySha256:string;shore:{previousX:number;previousTreeY:number;completedCalls:number}}
export const commands={port:32842,starboard:32841,tack:32846,close:32843,reach:32849,run:32848,jibe:32847} as const;
