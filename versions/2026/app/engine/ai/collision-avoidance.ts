/** Original avoidance radius and opponent order, without constructing floating
 * carriers for pairs that cannot enter the near-contact branch. */
export interface CollisionAvoidancePort {
 boats():number;
 humans():number;
 clock():number;
 lastAvoidance(boat:number):number;
 clearAvoidance(boat:number):void;
 x(boat:number):number;
 y(boat:number):number;
 heading(boat:number):number;
 setHeading(boat:number,value:number):void;
 avoid(distance:number,other:number,boat:number):void;
 warn(distance:number,other:number,boat:number):void;
 extendedDistance(dx:number,dy:number):number;
}
export function updateCollisionAvoidance(port:CollisionAvoidancePort,boat:number):void {
 if(((port.lastAvoidance(boat)+5)|0)<=port.clock())port.clearAvoidance(boat);
 for(let other=1;other<=port.boats();other++){
  if(other===boat)continue;
  const dy=(port.y(boat)-port.y(other))|0,dx=(port.x(boat)-port.x(other))|0;
  // The differences are exact signed DWORDs. Their PC53 squares/addition
  // round exactly as binary64 Number operations. Below2^62, sqrt cannot wrap
  // a signed DWORD negative; sqrt>=9 therefore cannot qualify after truncation.
  const square=dy*dy+dx*dx;
  if(square>=81&&square<2**62)continue;
  // Inside the radius, square is an exact integer0..80: integer boundaries
  // are perfect squares, safely separated from floating rounding midpoints.
  // Large-coordinate signed-DWORD conversion quirks retain the exact kernel.
  const distance=square<81?Math.trunc(Math.sqrt(square)):port.extendedDistance(dx,dy);
  if(distance>=9)continue;
  if(boat>port.humans())port.avoid(distance,other,boat);else port.warn(distance,other,boat);
  const heading=port.heading(boat);
  port.setHeading(boat,heading<0?(heading+360)|0:heading>359?(heading-360)|0:heading);
 }
}
