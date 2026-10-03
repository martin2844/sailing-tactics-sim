import { add32, i32, idiv32, imul32, sub32 } from '../runtime/index.js';
import { wrapDegreesOnce } from './integer-core.js';
import { Float80 } from '../runtime/float80.js';
import { nativeTrig } from './native-trig.js';
import { initializeCourse } from './course.js';

export const RACE_TARGET_ADDRESSES = Object.freeze({
  advanceRaceTarget: 0x00426ad0,
  projectPoint: 0x00420b20,
  leg: 0x004a5420, targetX: 0x004a4888, targetY: 0x004a6f48,
  humanBoatCount: 0x00491140, boatCount: 0x0049118c,
  reverseCourse: 0x004ac9a8, time: 0x004a5b80, legStarted: 0x004a41f0,
  repeatLegs: 0x004ac950, repeatedLegFlag: 0x004a72d8,
  regenerateCourse: 0x004ac940, shortenedCourse: 0x00491160,
  courseStage: 0x004911c0, startWidth: 0x004aa998,
  startAX: 0x004aa594, startAY: 0x004aa59c,
  startBX: 0x004a70f8, startBY: 0x004a72c8,
  courseHeading: 0x004abc80, pointX: 0x004a70e8, pointY: 0x004aa81c,
  markX: 0x004a8a50, markY: 0x004a8a80,
  startLineHeading: 0x004a6440, startLineLength: 0x004a6458,
  renderMarkX: 0x004a52f8, renderMarkY: 0x004a60b8,
  finishMode: 0x004a495c, finishCount: 0x004a4be8,
  lastFinishTime: 0x004ab8b4, place: 0x004a7648,
  soundDisabled: 0x004ac9c0, moduleHandle: 0x004ac1d4,
  speedLevel: 0x0049116c, speedDivisor: 0x00491170,
  finishedSpeedLevel: 0x004aa6f8, finishedSpeedDivisor: 0x004ac858,
  finishAfterPlayer: 0x004ac960, controlState: 0x004a89c0,
  controlTime: 0x004abf18, raceComplete: 0x004ac93c, completedRaces: 0x004ac944,
});

const a = RACE_TARGET_ADDRESSES;
const at = (address, index) => add32(address, imul32(index, 4)) >>> 0;

/** Complete 0x420b20: integer endpoint projected through original native trig. */
export function projectPoint(memory, x, y, distance, heading, options = {}) {
  x = i32(x); y = i32(y); distance = i32(distance);
  const angle = wrapDegreesOnce(i32(heading));
  const { sine, cosine } = nativeTrig(angle, options);
  memory.writeI32(a.pointX, add32(sine.multiply(Float80.fromInteger(distance)).truncI32(), x));
  memory.writeI32(a.pointY, sub32(y, cosine.multiply(Float80.fromInteger(distance)).truncI32()));
}

/** Complete 0x426ad0: race leg/target advancement and original finish bookkeeping. */
export function advanceRaceTarget(memory, boat, options = {}) {
  boat = i32(boat);
  const read = key => memory.readI32(a[key]);
  const write = (key, value) => memory.writeI32(a[key], value);
  const readBoat = key => memory.readI32(at(a[key], boat));
  const writeBoat = (key, value) => memory.writeI32(at(a[key], boat), value);
  const handedness = read('reverseCourse') === 1 ? -1 : 1;
  const sound = resourceId => {
    if (read('soundDisabled') === 0) options.playSound?.({ resourceId, moduleHandle: memory.readU32(a.moduleHandle), flags: 0x40005 });
  };
  const resetStartLine = () => {
    const direction = add32(read('courseHeading'), imul32(handedness, 90));
    write('startWidth', 150);
    projectPoint(memory, read('startAX'), read('startAY'), 150, direction, options);
    write('startBX', read('pointX'));
    write('startBY', read('pointY'));
    write('startLineHeading', wrapDegreesOnce(direction));
    write('startLineLength', read('startWidth'));
    memory.writeF64(a.renderMarkX + 8, read('startBX'));
    memory.writeF64(a.renderMarkY + 8, read('startBY'));
    memory.writeI32(a.markX + 32, idiv32(add32(read('startAX'), read('startBX')), 2));
    memory.writeI32(a.markY + 32, idiv32(add32(read('startBY'), read('startAY')), 2));
  };
  let leg = readBoat('leg');
  if (leg === 6 || leg === 7) {
    if (boat > read('humanBoatCount')) writeBoat('legStarted', read('time'));
    if (leg === 7 && read('repeatLegs') === 1 && readBoat('repeatedLegFlag') === 0) {
      writeBoat('targetY', memory.readI32(a.markY + 4));
      writeBoat('leg', 0);
      writeBoat('targetX', memory.readI32(a.markX + 4));
      writeBoat('repeatedLegFlag', 1);
      if (read('regenerateCourse') === 1) {
        write('shortenedCourse', 1);
        initializeCourse(memory, 10, options.rng, options);
        resetStartLine();
        const targetX = memory.readI32(a.markX + 24);
        const targetY = memory.readI32(a.markY + 24);
        for (let other = 2; other <= read('boatCount'); other++) {
          const prior = memory.readI32(at(a.leg, other));
          if (prior > 2 && prior < 6) {
            memory.writeI32(at(a.leg, other), 6);
            memory.writeI32(at(a.targetX, other), targetX);
            memory.writeI32(at(a.targetY, other), targetY);
          }
        }
      }
    }
  }
  if (read('courseStage') > 2 && read('startWidth') > 130) resetStartLine();
  leg = readBoat('leg');
  if (leg === 7 && read('repeatLegs') === 1 && readBoat('repeatedLegFlag') === 1) writeBoat('repeatedLegFlag', 2);
  if (leg === 8) {
    writeBoat('repeatedLegFlag', 0);
    const mode = read('finishMode');
    if (mode === 0) {
      write('finishCount', add32(read('finishCount'), 1));
      write('lastFinishTime', read('time'));
    }
    if (mode > 0) write('finishCount', add32(read('boatCount'), 1));
  }
  leg = add32(leg, 1);
  writeBoat('leg', leg);
  writeBoat('targetX', memory.readI32(at(a.markX, leg)));
  writeBoat('targetY', memory.readI32(at(a.markY, leg)));
  if (leg > 8) {
    writeBoat('targetX', memory.readI32(a.markX + 36));
    writeBoat('targetY', memory.readI32(a.markY + 36));
    writeBoat('place', read('finishCount'));
    if (read('finishCount') === 1) sound(0x8c);
    if (boat <= read('humanBoatCount') && read('finishCount') > 1) sound(0x8e);
    if (boat === 1 || (boat === 2 && read('humanBoatCount') === 2)) {
      write('finishedSpeedLevel', read('speedLevel'));
      write('finishedSpeedDivisor', read('speedDivisor'));
    }
    const finishAfterPlayer = read('finishAfterPlayer');
    const humans = read('humanBoatCount');
    if (readBoat('place') > 0 && finishAfterPlayer < 1 && boat <= humans) {
      writeBoat('controlState', 11);
      writeBoat('controlTime', read('time'));
    }
    if (memory.readI32(a.place + 4) > 0 && finishAfterPlayer === 1 && humans === 1) {
      write('raceComplete', 1);
      write('completedRaces', add32(read('completedRaces'), 1));
    }
    let allFinished = true;
    for (let other = 1; other <= read('boatCount'); other++) {
      if (memory.readI32(at(a.place, other)) === 0) allFinished = false;
    }
    if (allFinished) {
      write('raceComplete', 1);
      write('completedRaces', add32(read('completedRaces'), 1));
    }
  }
  if (read('regenerateCourse') === 1 && read('raceComplete') === 1) write('shortenedCourse', 0);
}

export const FUN_00420b20 = projectPoint;
export const FUN_00426ad0 = advanceRaceTarget;
