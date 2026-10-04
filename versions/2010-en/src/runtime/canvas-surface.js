/** Clear every bitmap and drawing state while retaining an unchanged surface. */
export function resetBitmapSurface(canvas,context,width,height){
  if(canvas.width===width&&canvas.height===height){
    if(typeof context.reset==='function')context.reset();
    else canvas.width=width;
  }else{
    canvas.width=width;
    canvas.height=height;
  }
  context.font='13px Arial';
}
