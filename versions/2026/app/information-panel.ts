import {informationKinds,type InformationKind,type InformationRequest,type InformationContent} from './native-information';
const titles={forecast:'Weather forecast',wind:'Wind chart',current:'Current chart',coach:'Coach comments'};
const svgNS='http://www.w3.org/2000/svg';
const color=(c:number)=>'#'+[c&255,c>>8&255,c>>16&255].map(n=>n.toString(16).padStart(2,'0')).join('');
const stroke=(c:number)=>({[0xffffff]:'#456682',[0xffff]:'#a87417',[0x7fff]:'#b77924',[0xff]:'#b33437',[0xff00ff]:'#8b479b',[0xff00]:'#24805b',[0xffff00]:'#327e88'}[c]??color(c));
const fill=(c:number)=>({[0xff0000]:'#dcebf0',[0x8000]:'#859f6d',[0x7800]:'#859f6d',[0xffffff]:'#fbfaf6'}[c]??color(c));
export class InformationPanel {
 readonly element=document.createElement('section');
 private serial=0;private kind:InformationKind='forecast';private offset=0;private zoom=false;
 private previousFocus:HTMLElement|null=null;
 constructor(private request:(data:InformationRequest)=>Promise<InformationContent>,private closed:()=>void){
  this.element.id='information-panel';this.element.hidden=true;this.element.setAttribute('role','dialog');this.element.setAttribute('aria-modal','true');this.element.setAttribute('aria-labelledby','information-title');
  this.element.innerHTML=`<div class="information-card"><div class="information-heading"><div><p>Sailing desk</p><h2 id="information-title">Weather forecast</h2></div><button id="information-close">Return to sailing</button></div><nav aria-label="Sailing information">${informationKinds.map(kind=>`<button data-information-kind="${kind}">${titles[kind]}</button>`).join('')}</nav><p id="information-status" role="status"></p><div id="information-content"></div><div id="information-time" hidden><button data-time="-1">Earlier −</button><span>Chart time</span><button data-time="1">Later +</button></div><p class="information-note">Race held while you read. Space or Esc returns to sailing.</p></div>`;
  this.element.querySelector<HTMLButtonElement>('#information-close')!.onclick=()=>this.close();
  const zoom=document.createElement('div');zoom.id='information-zoom';zoom.innerHTML='<button data-zoom="true">Zoom in · X</button><button data-zoom="false">Whole course · Z</button>';this.element.querySelector('#information-time')!.before(zoom);
  for(const b of zoom.querySelectorAll<HTMLButtonElement>('button'))b.onclick=()=>this.setZoom(b.dataset.zoom==='true');
  for(const b of this.element.querySelectorAll<HTMLButtonElement>('[data-information-kind]'))b.onclick=()=>{this.offset=0;void this.load(b.dataset.informationKind as InformationKind);};
  for(const b of this.element.querySelectorAll<HTMLButtonElement>('[data-time]'))b.onclick=()=>this.shift(Number(b.dataset.time));
  this.element.addEventListener('keydown',event=>{if(event.key!=='Tab')return;const buttons=Array.from(this.element.querySelectorAll<HTMLButtonElement>('button:not(:disabled)')).filter(b=>b.getClientRects().length);const first=buttons[0],last=buttons.at(-1);if(event.shiftKey&&document.activeElement===first){event.preventDefault();last?.focus();}else if(!event.shiftKey&&document.activeElement===last){event.preventDefault();first?.focus();}});
 }
 get isOpen(){return !this.element.hidden;}
 open(kind:InformationKind){if(!this.isOpen)this.previousFocus=document.activeElement as HTMLElement;this.element.hidden=false;this.offset=0;this.zoom=false;void this.load(kind);this.element.querySelector<HTMLButtonElement>('#information-close')!.focus();}
 reset(){this.serial++;this.element.hidden=true;}
 close(){if(!this.isOpen)return;this.reset();this.closed();this.previousFocus?.focus();}
 shift(delta:number){if(this.kind!=='current')return;this.offset=Math.max(0,Math.min(12,this.offset+delta));void this.load(this.kind);}
 setZoom(value:boolean){if(this.kind!=='wind'&&this.kind!=='current')return;this.zoom=value;void this.load(this.kind);}
 private async load(kind:InformationKind){
  this.kind=kind;const serial=++this.serial;this.element.dataset.state='loading';this.element.dataset.kind=kind;
  this.element.querySelector('#information-title')!.textContent=titles[kind];
  for(const b of this.element.querySelectorAll<HTMLButtonElement>('[data-information-kind]'))b.setAttribute('aria-pressed',String(b.dataset.informationKind===kind));
  const time=this.element.querySelector<HTMLElement>('#information-time')!;time.hidden=kind!=='current';
  const zoom=this.element.querySelector<HTMLElement>('#information-zoom')!;zoom.hidden=kind!=='wind'&&kind!=='current';for(const b of zoom.querySelectorAll<HTMLButtonElement>('button'))b.setAttribute('aria-pressed',String(this.zoom===(b.dataset.zoom==='true')));
  time.querySelector('span')!.textContent=this.offset===0?'Tide now':'Tide in '+this.offset+' hour'+(this.offset===1?'':'s');
  for(const b of time.querySelectorAll<HTMLButtonElement>('button'))b.disabled=Number(b.dataset.time)<0?this.offset===0:this.offset===12;
  const status=this.element.querySelector('#information-status')!,content=this.element.querySelector('#information-content')!;
  status.textContent='Reading conditions…';content.replaceChildren();
  try{
   const data=await this.request({kind,offset:this.offset,zoom:this.zoom});if(serial!==this.serial||!this.isOpen)return;
   if(data.error)throw Error(data.error);
   const seconds=Math.abs(data.clock);status.textContent=(data.clock<0?'Prestart · ':'Race · ')+Math.floor(seconds/60)+':'+String(seconds%60).padStart(2,'0');
   if(kind==='wind'||kind==='current'){const caption=document.createElement('p');caption.className='information-chart-caption';const legend=data.paragraphs.find(p=>p.includes('Mixing')||p.includes('Deep water current'))??'';for(const label of legend.split(' · ').filter(v=>!v.includes('at pointer'))){const span=document.createElement('span');span.textContent=label;const native=data.primitives.find(p=>p.op==='textOut'&&p.text?.trim()===label);if(native)span.style.color=stroke(native.color??0);caption.append(span);}content.append(caption,this.chart(data));}
   else{const list=this.paragraphs(data.paragraphs);if(data.history){const columns=document.createElement('div');columns.className='information-forecast';const history=document.createElement('section'),h=document.createElement('h3');h.textContent='Wind history · committee boat';history.append(h,this.paragraphs(data.history));columns.append(list,history);content.append(columns);}else content.append(list);}
   this.element.dataset.state='ready';
  }catch(error){if(serial!==this.serial)return;this.element.dataset.state='error';status.textContent='Unable to read this information. Return to sailing and try again.';console.warn('Information panel failed',error);}
 }
 private paragraphs(rows:string[]){const list=document.createElement('div');list.className='information-text';for(const text of rows){const p=document.createElement('p');p.textContent=text;list.append(p);}if(!list.children.length)list.textContent='No comments for this state.';return list;}
 private chart(data:InformationContent){
  const svg=document.createElementNS(svgNS,'svg');svg.setAttribute('viewBox',`0 42 ${data.width??1024} ${(data.height??768)-68}`);svg.setAttribute('role','img');svg.setAttribute('aria-label',data.title+' using the race’s wind and current samples');
  for(const p of data.primitives){let node:SVGElement;
   if(p.op==='textOut'){if((p.y??0)<42||(p.y??0)>(data.height??768)-30||/^Movement suspended/i.test(p.text??''))continue;node=document.createElementNS(svgNS,'text');node.setAttribute('x',String(p.x));node.setAttribute('y',String((p.y??0)+20));node.setAttribute('fill','#123f58');node.textContent=p.text??'';}
   else if(p.op==='lineTo'){node=document.createElementNS(svgNS,'line');node.setAttribute('x1',String(p.from?.x));node.setAttribute('y1',String(p.from?.y));node.setAttribute('x2',String(p.x));node.setAttribute('y2',String(p.y));}
   else if(p.op==='rectangle'){node=document.createElementNS(svgNS,'rect');node.setAttribute('x',String(Math.min(p.left!,p.right!)));node.setAttribute('y',String(Math.min(p.top!,p.bottom!)));node.setAttribute('width',String(Math.abs(p.right!-p.left!)));node.setAttribute('height',String(Math.abs(p.bottom!-p.top!)));}
   else if(p.op==='polygon'){node=document.createElementNS(svgNS,'polygon');node.setAttribute('points',p.points!.map(v=>v.x+','+v.y).join(' '));}
   else if(p.op==='ellipse'){node=document.createElementNS(svgNS,'ellipse');node.setAttribute('cx',String((p.left!+p.right!)/2));node.setAttribute('cy',String((p.top!+p.bottom!)/2));node.setAttribute('rx',String(Math.abs(p.right!-p.left!)/2));node.setAttribute('ry',String(Math.abs(p.bottom!-p.top!)/2));}
   else continue;
   if(p.op!=='textOut'){node.setAttribute('stroke',p.pen.null?'none':stroke(p.pen.color));node.setAttribute('stroke-width',String(Math.max(.8,Math.min(2,p.pen.width))));node.setAttribute('fill',p.op==='lineTo'||p.brush.null?'none':fill(p.brush.color));}
   svg.append(node);
  }return svg;
 }
}
