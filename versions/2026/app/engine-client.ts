import type {NativeTerrain} from './native-environment';
import five from '../config/scenarios/round-lake-5.json';
import fifteen from '../config/scenarios/round-lake-15.json';
import type {Boundary,SceneSnapshot} from './protocol';
import type {NativeModelPacket,ModelCapture} from './native-models';
import type {NativeBoatFrame} from './native-visuals';
import {defaultRaceSettings,type RaceSettings} from './race-settings';
import {fleetChoices} from './native-catalog';
interface DiagnosticReplies {
  image:Uint8Array;
  'next-race':Boundary;
  environmentcase:{before:Boundary;after:Boundary;cases:unknown[];terrain:NativeTerrain;scope:string};
  finishcase:{before:Boundary;after:Boundary;boats:{id:number;name:string;finished:number;points:number[]}[];order:number[];results:boolean;completedRaces:number;scope:string};
  step:Boundary;boundary:Boundary;model:NativeBoatFrame;lift:ModelCapture[];geometry:NativeModelPacket;
  modelcase:{kind:string;packet:NativeModelPacket;projections:ModelCapture[];unscaled:ModelCapture};
}
export class EngineClient {
  private worker:Worker;
  private nextId=1;
  private requests=new Map<number,{resolve:(v:unknown)=>void;reject:(e:Error)=>void;timer:ReturnType<typeof setTimeout>}>();
  constructor(public generation:number,fleet:number,manual:boolean,callbacks:{ready:(v:Boundary)=>void;snapshot:(v:SceneSnapshot)=>void;terrain?:(v:NativeTerrain)=>void;models?:(v:{generation:number;sequence:number;packet:NativeModelPacket})=>void;panel?:(v:{sequence:number;title:string;bitmap:ImageBitmap})=>void;error:(e:string)=>void;paused:(v:boolean)=>void;accepted?:(v:{key?:number;command?:number;sequence:number})=>void},settings:RaceSettings=defaultRaceSettings){
    if(!fleetChoices.some(f=>f.value===fleet))throw Error('Unsupported native fleet');
    this.worker=new Worker(new URL('./engine.worker.ts',import.meta.url),{type:'module'});
    const failure=(message:string)=>{this.rejectPending(message);callbacks.error(message);};
    this.worker.onerror=e=>failure(e.message);
    this.worker.onmessage=e=>{try{if(e.data.generation!==generation){e.data.data?.bitmap?.close();return;}const {type,data}=e.data;
      if(type==='ready')callbacks.ready(data);else if(type==='snapshot')callbacks.snapshot(data);else if(type==='error')failure(data);else if(type==='paused')callbacks.paused(data);else if(type==='accepted')callbacks.accepted?.(data);
      else if(type==='terrain')callbacks.terrain?.(data);
      else if(type==='models')callbacks.models?.(data);
      else if(type==='panel'){if(callbacks.panel)callbacks.panel(data);else data.bitmap.close();}
      else if(type==='reply'){const request=this.requests.get(data.id);if(request){clearTimeout(request.timer);this.requests.delete(data.id);request.resolve(data.value);}}
    }catch(error){failure(error instanceof Error?error.message:String(error));}};
    this.worker.postMessage({type:'init',data:{generation,fleet,legacyBase:new URL(/* @vite-ignore */ '../legacy/',import.meta.url).href,scenario:fleet===15?fifteen:five,settings,manual}});
  }
  send(type:string,data?:unknown){this.worker.postMessage({generation:this.generation,type,data});}
  request<T extends keyof DiagnosticReplies>(type:T,data?:number|string):Promise<DiagnosticReplies[T]>{const id=this.nextId++;return new Promise((resolve,reject)=>{const timer=setTimeout(()=>{this.requests.delete(id);reject(new Error('Worker request timed out'));},60000);this.requests.set(id,{resolve:value=>resolve(value as DiagnosticReplies[T]),reject,timer});this.worker.postMessage({generation:this.generation,type,data,id});});}
  private rejectPending(message:string){for(const request of this.requests.values()){clearTimeout(request.timer);request.reject(new Error(message));}this.requests.clear();}
  dispose(){this.rejectPending('Worker disposed');this.worker.terminate();}
}
