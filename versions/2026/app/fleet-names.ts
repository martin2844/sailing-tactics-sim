import * as THREE from 'three';
import type {BoatView} from './protocol';
const storageKey='tact2026.boatName';
let custom='';try{custom=cleanName(localStorage.getItem(storageKey)??'');}catch{}
export function cleanName(value:string){return value.replace(/[\u0000-\u001f\u007f]/g,'').trim().slice(0,32);}
export function setBoatName(value:string){custom=cleanName(value);try{custom?localStorage.setItem(storageKey,custom):localStorage.removeItem(storageKey);}catch{}return custom;}
export const getBoatName=()=>custom;
export const boatName=(boat:Pick<BoatView,'id'|'name'>)=>boat.id===1&&custom?custom:boat.name||`Boat ${boat.id}`;
/** Canvas text is deliberate: arbitrary boat names never become markup. */
export class FleetLabels{
 readonly group=new THREE.Group();private labels=new Map<number,{text:string;sprite:THREE.Sprite;texture:THREE.CanvasTexture}>();
 update(boats:BoatView[],poses:{x:number;y:number}[],origin:{x:number;y:number}){
  for(let i=0;i<boats.length;i++){
   const boat=boats[i],text=boatName(boat);let label=this.labels.get(boat.id);
   if(!label){const texture=new THREE.CanvasTexture(document.createElement('canvas')),material=new THREE.SpriteMaterial({map:texture,depthWrite:false});const sprite=new THREE.Sprite(material);sprite.scale.set(25,5,1);this.group.add(sprite);label={text:'',sprite,texture};this.labels.set(boat.id,label);}
   if(label.text!==text){const canvas=label.texture.image as HTMLCanvasElement;canvas.width=512;canvas.height=96;const ctx=canvas.getContext('2d')!;ctx.fillStyle=boat.id===1?'#123f58':'#f4f7f8e8';ctx.fillRect(0,0,512,96);ctx.fillStyle=boat.id===1?'#fff':'#12303d';ctx.font='600 42px "IBM Plex Sans",sans-serif';ctx.textAlign='center';ctx.textBaseline='middle';ctx.fillText(text,256,48,480);label.text=text;label.texture.needsUpdate=true;}
   label.sprite.position.set(poses[i].x-origin.x,14,poses[i].y-origin.y);
  }
 }
 reset(){for(const {sprite,texture}of this.labels.values()){texture.dispose();(sprite.material as THREE.SpriteMaterial).dispose();}this.labels.clear();this.group.clear();}
 dispose(){this.reset();}
}
