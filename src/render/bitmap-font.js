import { colorRefCss } from './gdi.js';

/** Default GDI System font captured as native glyph masks and character widths.
 * This preserves the measured Wine font; other Windows font versions may differ.
 */
export function createGdiBitmapFont(atlas,metrics,{createSurface}={}){
  if(metrics.face!=='System'||metrics.advances.length!==256||metrics.kerningPairs!==0)throw new TypeError('Measured default GDI font is required');
  const cellWidth=metrics.cellWidth,cellHeight=metrics.cellHeight,columns=metrics.columns,colors=new Map();
  const surface=createSurface??((width,height)=>{const canvas=document.createElement('canvas');canvas.width=width;canvas.height=height;return canvas;});
  const code=character=>{const value=character.codePointAt(0);return value<256?value:63;};
  const measure=text=>Array.from(String(text),character=>metrics.advances[code(character)]).reduce((sum,value)=>sum+value,0);
  const colored=color=>{
    if(colors.has(color))return colors.get(color);
    const canvas=surface(atlas.width,atlas.height),context=canvas.getContext('2d');
    context.fillStyle=colorRefCss(color);context.fillRect(0,0,canvas.width,canvas.height);
    context.globalCompositeOperation='destination-in';context.drawImage(atlas,0,0);context.globalCompositeOperation='source-over';
    colors.set(color,canvas);return canvas;
  };
  return Object.freeze({metrics,measure,draw(context,text,x,y,textColor,backgroundColor,backgroundMode){
    text=String(text);if(!text)return;
    context.save();context.imageSmoothingEnabled=false;
    if(backgroundMode===2){context.fillStyle=colorRefCss(backgroundColor);context.fillRect(x,y,measure(text),metrics.height);}
    const image=colored(textColor);
    for(const character of text){
      const index=code(character);
      context.drawImage(image,(index%columns)*cellWidth,Math.trunc(index/columns)*cellHeight,cellWidth,cellHeight,x,y,cellWidth,cellHeight);
      x+=metrics.advances[index];
    }
    context.restore();
  }});
}

export async function fetchGdiBitmapFont(){
  const response=await fetch(new URL('../../assets/data/system-font.json',import.meta.url));
  if(!response.ok)throw new Error('Could not load original System font metrics');
  const metrics=await response.json(),imageResponse=await fetch(new URL(`../../${metrics.atlas}`,import.meta.url));
  if(!imageResponse.ok)throw new Error('Could not load original System font glyphs');
  const bytes=await imageResponse.arrayBuffer();
  const digest=Array.from(new Uint8Array(await crypto.subtle.digest('SHA-256',bytes)),value=>value.toString(16).padStart(2,'0')).join('');
  if(digest!==metrics.provenance.atlasSha256)throw new Error('Original System font glyph hash differs');
  return createGdiBitmapFont(await createImageBitmap(new Blob([bytes],{type:'image/png'})),metrics);
}
