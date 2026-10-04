import { i32, u32 } from '../runtime/c-types.js';

/** Windows COLORREF is 0x00BBGGRR. */
export function colorRefCss(value) {
  value = u32(value);
  return `rgb(${value & 255},${(value >>> 8) & 255},${(value >>> 16) & 255})`;
}

const STOCK_OBJECTS = Object.freeze({
  0: { kind: 'brush', color: 0xffffff },
  1: { kind: 'brush', color: 0xc0c0c0 },
  2: { kind: 'brush', color: 0x808080 },
  3: { kind: 'brush', color: 0x404040 },
  4: { kind: 'brush', color: 0 },
  5: { kind: 'brush', null: true },
  6: { kind: 'pen', style: 0, width: 1, color: 0xffffff },
  7: { kind: 'pen', style: 0, width: 1, color: 0 },
  8: { kind: 'pen', null: true },
});

/**
 * Ordered drawing requests, independent of the Windows HDC handle values.
 * The default objects are a black pen and white brush, as on a new GDI DC.
 * Every coordinate remains a signed 32-bit integer until Canvas consumes it.
 */
export class GdiTrace {
  constructor({ objects = new Map(), sink, readPixel, recordEvents = true } = {}) {
    this.objects = objects;
    this.sink = sink;
    this.readPixel = readPixel;
    this.recordEvents = recordEvents;
    this.events = [];
    this.position = { x: 0, y: 0 };
    this.pen = STOCK_OBJECTS[7];
    this.brush = STOCK_OBJECTS[0];
    this.textColor = 0;
    this.backgroundColor = 0xffffff;
    this.backgroundMode = 2;
  }
  emit(event) {
    if (this.recordEvents) this.events.push(event);
    if (this.sink) this.sink(event, this);
    return event;
  }
  selectObject(handle) {
    handle = u32(handle);
    const object = this.objects.get(handle);
    if (object?.kind === 'pen') this.pen = object;
    if (object?.kind === 'brush') this.brush = object;
    if (object?.kind === 'font') this.font = object;
    this.emit({ op: 'selectObject', handle });
  }
  selectStockObject(index) {
    index = i32(index);
    const object = STOCK_OBJECTS[index];
    if (object?.kind === 'pen') this.pen = object;
    if (object?.kind === 'brush') this.brush = object;
    this.emit({ op: 'selectStockObject', index });
  }
  moveTo(x, y) {
    const previous = this.position;
    this.position = { x: i32(x), y: i32(y) };
    this.emit({ op: 'moveTo', ...this.position });
    return previous;
  }
  lineTo(x, y) {
    const event = { op: 'lineTo', x: i32(x), y: i32(y) };
    this.emit(event);
    this.position = { x: event.x, y: event.y };
  }
  polygon(points) {
    this.emit({ op: 'polygon', points: points.map(point => ({ x: i32(point.x), y: i32(point.y) })) });
  }
  ellipse(left, top, right, bottom) {
    this.emit({ op: 'ellipse', left: i32(left), top: i32(top), right: i32(right), bottom: i32(bottom) });
  }
  arc(left, top, right, bottom, startX, startY, endX, endY) {
    this.emit({ op: 'arc', left: i32(left), top: i32(top), right: i32(right), bottom: i32(bottom),
      startX: i32(startX), startY: i32(startY), endX: i32(endX), endY: i32(endY) });
  }
  pie(left, top, right, bottom, startX, startY, endX, endY) {
    this.emit({ op: 'pie', left: i32(left), top: i32(top), right: i32(right), bottom: i32(bottom),
      startX: i32(startX), startY: i32(startY), endX: i32(endX), endY: i32(endY) });
  }
  rectangle(left, top, right, bottom) {
    this.emit({ op: 'rectangle', left: i32(left), top: i32(top), right: i32(right), bottom: i32(bottom) });
  }
  roundRect(left, top, right, bottom, ellipseWidth, ellipseHeight) {
    this.emit({ op: 'roundRect', left: i32(left), top: i32(top), right: i32(right), bottom: i32(bottom),
      ellipseWidth: i32(ellipseWidth), ellipseHeight: i32(ellipseHeight) });
  }
  pushClipRect(left, top, right, bottom) {
    this.emit({ op: 'pushClipRect', left: i32(left), top: i32(top), right: i32(right), bottom: i32(bottom) });
  }
  popClipRect() { this.emit({ op: 'popClipRect' }); }
  setPixel(x, y, color) {
    this.emit({ op: 'setPixel', x: i32(x), y: i32(y), color: u32(color) });
  }
  getPixel(x, y) {
    x = i32(x); y = i32(y);
    if (!this.readPixel) throw new Error('Original GetPixel requires an explicit pixel sampler');
    const color = u32(this.readPixel(x, y));
    this.emit({ op: 'getPixel', x, y, color });
    return color;
  }
  setTextColor(color) {
    const previous = this.textColor;
    this.textColor = u32(color);
    this.emit({ op: 'setTextColor', color: this.textColor });
    return previous;
  }
  setBkColor(color) {
    const previous = this.backgroundColor;
    this.backgroundColor = u32(color);
    this.emit({ op: 'setBkColor', color: this.backgroundColor });
    return previous;
  }
  setBkMode(mode) {
    const previous = this.backgroundMode;
    this.backgroundMode = i32(mode);
    this.emit({ op: 'setBkMode', mode: this.backgroundMode });
    return previous;
  }
  textOut(x, y, text) {
    this.emit({ op: 'textOut', x: i32(x), y: i32(y), text: String(text) });
  }
  messageBeep(type) {
    this.emit({ op: 'messageBeep', type: u32(type) });
    return 1;
  }
}

/**
 * Canvas presentation of the traced GDI primitives. Original calls, coordinates
 * and colors are preserved; Canvas antialiasing and font rasterization are not
 * asserted to reproduce Windows GDI pixels.
 */
export function createCanvasGdi(context, options = {}) {
  // Opt-in only for a DC whose canvas is exclusively drawn through this sink
  // during its lifetime. The browser paint creates a fresh DC for each frame.
  // Raster-changing events invalidate these tiny tiles. Drawing-state changes
  // do not change getImageData pixels, so adjacent visibility probes can reuse
  // a tile even when pen, text or clipping state changes between the reads.
  const pixelTiles=options.cachePixelReads===true&&options.recordEvents===false
    &&options.readPixel==null&&options.sink==null?new Map():null;
  const fillAndStroke = dc => {
    if (!dc.brush.null) { context.fillStyle = colorRefCss(dc.brush.color); context.fill('evenodd'); }
    if (!dc.pen.null) {
      context.strokeStyle = colorRefCss(dc.pen.color);
      context.lineWidth = Math.max(1, dc.pen.width);
      context.stroke();
    }
  };
  const readPixel = options.readPixel ?? ((x, y) => {
    if (x < 0 || y < 0 || x >= context.canvas.width || y >= context.canvas.height) return 0xffffffff;
    if(pixelTiles){
      const top=y-y%8,key=`${x}:${top}`;
      let pixels=pixelTiles.get(key);
      if(!pixels){
        pixels=context.getImageData(x,top,1,Math.min(8,context.canvas.height-top)).data;
        if(pixelTiles.size>=64)pixelTiles.clear();
        pixelTiles.set(key,pixels);
      }
      const at=(y-top)*4;
      return (pixels[at]|pixels[at+1]<<8|pixels[at+2]<<16)>>>0;
    }
    const pixel = context.getImageData(x, y, 1, 1).data;
    return (pixel[0] | pixel[1] << 8 | pixel[2] << 16) >>> 0;
  });
  return new GdiTrace({ ...options, readPixel, sink(event, dc) {
    if(pixelTiles){
      switch(event.op){
        case 'getPixel':
        case 'moveTo':
        case 'selectObject':
        case 'selectStockObject':
        case 'setTextColor':
        case 'setBkColor':
        case 'setBkMode':
        case 'pushClipRect':
        case 'popClipRect': break;
        default: pixelTiles.clear();
      }
    }
    if (options.sink) options.sink(event, dc);
    switch (event.op) {
      case 'messageBeep': options.messageBeep?.(event.type); break;
      case 'lineTo':
        if (dc.pen.null) break;
        context.beginPath();
        context.moveTo(dc.position.x, dc.position.y);
        context.lineTo(event.x, event.y);
        context.strokeStyle = colorRefCss(dc.pen.color);
        context.lineWidth = Math.max(1, dc.pen.width);
        context.stroke();
        break;
      case 'polygon':
        if (!event.points.length) break;
        context.beginPath();
        context.moveTo(event.points[0].x, event.points[0].y);
        for (const point of event.points.slice(1)) context.lineTo(point.x, point.y);
        context.closePath();
        fillAndStroke(dc);
        break;
      case 'rectangle':
        context.beginPath();
        context.rect(event.left, event.top, event.right - event.left, event.bottom - event.top);
        fillAndStroke(dc);
        break;
      case 'roundRect': {
        if (event.right <= event.left || event.bottom <= event.top) break;
        const rx = Math.min(Math.abs(event.ellipseWidth) / 2, (event.right - event.left) / 2);
        const ry = Math.min(Math.abs(event.ellipseHeight) / 2, (event.bottom - event.top) / 2);
        context.beginPath();
        if (rx === 0 || ry === 0) context.rect(event.left, event.top, event.right - event.left, event.bottom - event.top);
        else {
          context.moveTo(event.left + rx, event.top); context.lineTo(event.right - rx, event.top);
          context.ellipse(event.right - rx, event.top + ry, rx, ry, 0, -Math.PI / 2, 0);
          context.lineTo(event.right, event.bottom - ry);
          context.ellipse(event.right - rx, event.bottom - ry, rx, ry, 0, 0, Math.PI / 2);
          context.lineTo(event.left + rx, event.bottom);
          context.ellipse(event.left + rx, event.bottom - ry, rx, ry, 0, Math.PI / 2, Math.PI);
          context.lineTo(event.left, event.top + ry);
          context.ellipse(event.left + rx, event.top + ry, rx, ry, 0, Math.PI, 3 * Math.PI / 2);
          context.closePath();
        }
        fillAndStroke(dc); break;
      }
      case 'pushClipRect':
        context.save(); context.beginPath();
        context.rect(event.left, event.top, event.right - event.left, event.bottom - event.top); context.clip();
        break;
      case 'popClipRect': context.restore(); break;
      case 'ellipse':
        if (event.right <= event.left || event.bottom <= event.top) break;
        context.beginPath();
        context.ellipse((event.left + event.right) / 2, (event.top + event.bottom) / 2,
          (event.right - event.left) / 2, (event.bottom - event.top) / 2, 0, 0, 2 * Math.PI);
        fillAndStroke(dc);
        break;
      case 'arc':
      case 'pie': {
        if (event.right <= event.left || event.bottom <= event.top || (event.op === 'arc' && dc.pen.null)) break;
        const x = (event.left + event.right) / 2, y = (event.top + event.bottom) / 2;
        const rx = (event.right - event.left) / 2, ry = (event.bottom - event.top) / 2;
        const start = Math.atan2((event.startY - y) / ry, (event.startX - x) / rx);
        const end = event.startX === event.endX && event.startY === event.endY ? start - 2 * Math.PI
          : Math.atan2((event.endY - y) / ry, (event.endX - x) / rx);
        context.beginPath();
        if (event.op === 'pie') context.moveTo(x, y);
        context.ellipse(x, y, rx, ry, 0, start, end, true);
        if (event.op === 'pie') { context.closePath(); fillAndStroke(dc); }
        else { context.strokeStyle = colorRefCss(dc.pen.color); context.lineWidth = Math.max(1, dc.pen.width); context.stroke(); }
        break;
      }
      case 'setPixel':
        context.fillStyle = colorRefCss(event.color);
        context.fillRect(event.x, event.y, 1, 1);
        break;
      case 'textOut':
        if(options.bitmapFont&&!dc.font){
          options.bitmapFont.draw(context,event.text,event.x,event.y,dc.textColor,dc.backgroundColor,dc.backgroundMode);
          break;
        }
        context.textBaseline = 'top';
        if (dc.font?.css) context.font = dc.font.css;
        if(dc.backgroundMode===2){
          const metrics=context.measureText(event.text);
          context.fillStyle=colorRefCss(dc.backgroundColor);
          context.fillRect(event.x,event.y,metrics.width,metrics.fontBoundingBoxAscent+metrics.fontBoundingBoxDescent);
        }
        context.fillStyle = colorRefCss(dc.textColor);
        context.fillText(event.text, event.x, event.y);
        break;
    }
  } });
}

export const GDI_STOCK_OBJECTS = STOCK_OBJECTS;
