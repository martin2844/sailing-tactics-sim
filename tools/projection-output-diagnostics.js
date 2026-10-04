import {createHash} from 'node:crypto';

const sha=source=>createHash('sha256').update(source).digest('hex');

/** Instrument one fetched module in memory; production sources stay unchanged. */
export function instrumentProjectionOutputSource(source,chart=false){
  const functionName=chart?'tryProjectChartPointOutputFast':'tryProjectScenePointOutputFast';
  const stateName=chart?'__chartOutputDiagnostics':'__projectionOutputDiagnostics';
  const declaration=`export function ${functionName}(`;
  if(source.split(declaration).length!==2)throw new Error('Expected one projection output function');
  const reasons=[];
  const body=source.replace(/return undefined;/g,(text,offset)=>{
    const line=source.slice(0,offset).split('\n').length;
    reasons.push({line,source:source.split('\n')[line-1].trim()});
    return `return projectionDiagnosticDecline(${line});`;
  }).replace(declaration,'function computeProjectScenePointOutput(');
  const instrumentation=`
let projectionDiagnosticKey;
const projectionDiagnosticState=()=>globalThis.${stateName}??=(
  {calls:0,accepted:0,declined:0,bySelectorMode:{},declinesByLine:{}});
function projectionDiagnosticDecline(line){
  const state=projectionDiagnosticState();
  state.declined++;state.bySelectorMode[projectionDiagnosticKey].declined++;
  const key=projectionDiagnosticKey+':L'+line;
  state.declinesByLine[key]=(state.declinesByLine[key]??0)+1;
  return undefined;
}
export function ${functionName}(...args){
  const memory=args[0],camera=args[4],selector=args[${chart?3:5}];
  const mode=typeof camera==='number'&&Number.isInteger(camera)&&camera>=1&&camera<=30
    ?memory.readI32(0x4f71c0+camera*4):'unknown';
  projectionDiagnosticKey=String(selector)+':'+String(mode);
  const state=projectionDiagnosticState();
  const row=state.bySelectorMode[projectionDiagnosticKey]??=({calls:0,accepted:0,declined:0});
  state.calls++;row.calls++;
  const result=computeProjectScenePointOutput(...args);
  if(result!==undefined){state.accepted++;row.accepted++;}
  return result;
}
`;
  return {source:body+instrumentation,reasons,originalSha256:sha(source),instrumentedSha256:sha(body+instrumentation)};
}

/** Install before Page.reload. Timings from this mode include diagnostic work. */
export async function installProjectionOutputDiagnostics(browser){
  let cursor=browser.events.length,stopped=false,timer,active;
  const receipts=[],errors=[];
  await browser.call('Network.setCacheDisabled',{cacheDisabled:true});
  await browser.call('Fetch.enable',{patterns:['projection-output-fast','chart-output-fast'].map(name=>({
    urlPattern:`*/versions/2010-en/src/render/${name}.js*`,requestStage:'Response',
  }))});
  const pump=async()=>{
    while(cursor<browser.events.length){
      const event=browser.events[cursor++];
      if(event.method!=='Fetch.requestPaused')continue;
      const {requestId,request,responseHeaders=[],responseStatusCode}=event.params;
      try{
        const response=await browser.call('Fetch.getResponseBody',{requestId});
        const source=Buffer.from(response.body,response.base64Encoded?'base64':'utf8').toString('utf8');
        const transformed=instrumentProjectionOutputSource(source,request.url.includes('/chart-output-fast.js'));
        const headers=responseHeaders.filter(row=>!['content-length','content-encoding','transfer-encoding'].includes(row.name.toLowerCase()));
        await browser.call('Fetch.fulfillRequest',{requestId,responseCode:responseStatusCode??200,
          responseHeaders:headers,body:Buffer.from(transformed.source).toString('base64')});
        receipts.push({url:request.url,originalSha256:transformed.originalSha256,
          instrumentedSha256:transformed.instrumentedSha256,reasons:transformed.reasons});
      }catch(error){
        errors.push({url:request.url,error:String(error)});
        await browser.call('Fetch.continueRequest',{requestId}).catch(()=>{});
      }
    }
  };
  const schedule=()=>{timer=setTimeout(()=>{
    active=pump().catch(error=>errors.push({error:String(error)})).finally(()=>{if(!stopped)schedule();});
  },10);};
  schedule();
  return {
    async reset(){await browser.evaluate('globalThis.__projectionOutputDiagnostics=undefined;globalThis.__chartOutputDiagnostics=undefined');},
    async read(){
      if(errors.length)throw new Error(`Projection instrumentation failed: ${JSON.stringify(errors)}`);
      if(!receipts.length)throw new Error('Projection module was not intercepted; reload after installation');
      return {scope:'Diagnostic in-memory source instrumentation. Original output computation is retained; measurements include counter and one mode-read overhead.',
        counters:await browser.evaluate('globalThis.__projectionOutputDiagnostics'),
        chartCounters:await browser.evaluate('globalThis.__chartOutputDiagnostics'),receipts:[...receipts]};
    },
    async close(){stopped=true;clearTimeout(timer);await active;await browser.call('Fetch.disable');},
  };
}
