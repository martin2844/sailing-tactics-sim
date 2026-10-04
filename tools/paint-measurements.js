/** Browser diagnostic injection; supports both immediate tasks and timers. */
export function paintMeasurementInstrumentation(record,{setupGate=false}={}){
  return `
    Date.now=()=>1546300800000;
    globalThis.paintMeasurements=[];
    const wrapPaint=(callback,args=[])=>
      typeof callback==='function'&&callback.name==='paint'?()=>{
        ${setupGate?'const runPaint=()=>{':''}
          const start=performance.now();callback(...args);
          ${record}
        ${setupGate?'};globalThis.paintSetupGate.accept(runPaint);':''}
      }:callback;
    const schedule=globalThis.setTimeout;
    globalThis.setTimeout=(callback,delay,...args)=>schedule(wrapPaint(callback,args),delay,...args);
    const OriginalMessageChannel=globalThis.MessageChannel;
    if(OriginalMessageChannel){
      const handler=Object.getOwnPropertyDescriptor(MessagePort.prototype,'onmessage');
      globalThis.MessageChannel=function(){
        const channel=new OriginalMessageChannel();
        Object.defineProperty(channel.port1,'onmessage',{
          configurable:true,
          get(){return handler.get.call(this);},
          set(callback){handler.set.call(this,wrapPaint(callback));},
        });
        return channel;
      };
      globalThis.MessageChannel.prototype=OriginalMessageChannel.prototype;
    }
  `;
}
