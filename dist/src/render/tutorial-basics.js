import { add32, sub32, imul32, idiv32 } from '../runtime/c-types.js';
import { readAnsiString } from '../engine/hud-state.js';

export const TUTORIAL_BASIC_ROUTINES = Object.freeze({drawTutorial1: 0x432000, drawTutorial2: 0x432920, drawTutorial3: 0x4330f0, drawTutorial4: 0x4337a0, drawTutorial5: 0x433ea0, drawTutorial6: 0x434470, drawTutorial7: 0x434c10, drawTutorial8: 0x4354d0});

/** Complete original 0x432000; ordered colors and text retain width/flag branches. */
export function drawTutorial1(memory, dc, _options = {}) {
  const get = address => memory.readI32(address);
  let iVar2, iVar3, iVar4, local_10, local_14, pCVar5, string_param_1;
  iVar2 = get(0x4a763c);
  iVar4 = 5;
  if ((iVar2 < 0x2bc)) {
    local_14 = 13;
    local_10 = 18;
    iVar3 = 1;
    iVar4 = 2;
  }
  else {
    local_14 = 16;
    local_10 = 22;
    iVar3 = 20;
  }
  if ((0x384 < iVar2)) {
    iVar3 = 20;
    local_10 = 28;
    local_14 = 20;
  }
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar3, iVar4, readAnsiString(memory, 0x0049406c));
  iVar4 = add32(iVar4, local_10);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(iVar3, iVar4, readAnsiString(memory, 0x00494014));
  pCVar5 = add32(local_14, iVar4);
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493fb0));
  pCVar5 = add32(pCVar5, local_14);
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493f54));
  pCVar5 = add32(pCVar5, local_14);
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493ef0));
  pCVar5 = add32(pCVar5, local_10);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xffff);
    dc.setBkColor(0);
  }
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493e94));
  pCVar5 = add32(pCVar5, local_14);
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493e3c));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f00);
    dc.setBkColor(0xffffff);
  }
  pCVar5 = add32(pCVar5, local_10);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493df0));
  pCVar5 = add32(pCVar5, local_14);
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493da4));
  pCVar5 = add32(pCVar5, local_10);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(127);
  }
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493d48));
  pCVar5 = add32(pCVar5, local_14);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493cec));
  pCVar5 = add32(pCVar5, local_14);
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493c94));
  pCVar5 = add32(pCVar5, local_14);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493c38));
  pCVar5 = add32(pCVar5, local_14);
  dc.textOut(add32(iVar3, 8), pCVar5, readAnsiString(memory, 0x00493bd4));
  pCVar5 = add32(pCVar5, local_14);
  dc.textOut(add32(iVar3, 8), pCVar5, readAnsiString(memory, 0x00493b78));
  pCVar5 = add32(pCVar5, local_10);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(255);
  }
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493b18));
  pCVar5 = add32(pCVar5, local_10);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493ab8));
  pCVar5 = add32(pCVar5, local_14);
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493a58));
  pCVar5 = add32(pCVar5, local_14);
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x004939fc));
  pCVar5 = add32(pCVar5, local_14);
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493998));
  pCVar5 = add32(pCVar5, local_10);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x0049393c));
  pCVar5 = add32(pCVar5, local_14);
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x004938d8));
  pCVar5 = add32(pCVar5, local_14);
  if ((get(0x4a763c) < 0x2bd)) {
    dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493858));
  }
  else {
    dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493874));
  }
  dc.setTextColor(0);
  if ((get(0x4a763c) < 0x2bc)) {
    dc.textOut(idiv32(get(0x4a763c), 3), pCVar5, readAnsiString(memory, 0x0049382c));
  }
  else {
    pCVar5 = add32(pCVar5, local_14);
    dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x0049382c));
  }
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  pCVar5 = add32(pCVar5, local_10);
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x004937d0));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f00);
  }
  pCVar5 = add32(pCVar5, local_10);
  dc.textOut(iVar3, pCVar5, readAnsiString(memory, 0x00493778));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff00ff);
  }
  dc.textOut(iVar3, add32(pCVar5, local_10), readAnsiString(memory, 0x0049371c));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(255);
  }
  dc.textOut(iVar3, add32(idiv32(imul32(get(0x4a72d0), 9), 10), sub32(0, 2)), readAnsiString(memory, 0x004936e8));
}

/** Complete original 0x432920; ordered colors and text retain width/flag branches. */
export function drawTutorial2(memory, dc, _options = {}) {
  const get = address => memory.readI32(address);
  let iVar3, iVar4, local_18;
  iVar3 = get(0x4a763c);
  if ((iVar3 < 0x2bc)) {
    iVar3 = 16;
    local_18 = 22;
  }
  else {
    iVar3 = 20;
    local_18 = 30;
  }
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.setBkColor(0xffffff);
  dc.textOut(20, 2, readAnsiString(memory, 0x004948d4));
  iVar4 = add32(local_18, 2);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  if ((get(0x491140) === 1)) {
    if ((get(0x4a4e8c) < 3)) {
      dc.textOut(20, iVar4, readAnsiString(memory, 0x00494874));
      iVar4 = add32(iVar4, iVar3);
      if ((get(0x4ac9d8) === 0)) {
        dc.textOut(20, iVar4, readAnsiString(memory, 0x00494818));
      }
      else {
        dc.textOut(20, iVar4, readAnsiString(memory, 0x004947c0));
      }
      iVar4 = add32(iVar4, local_18);
      if ((get(0x4ac92c) === 0)) {
        dc.setTextColor(0x7f0000);
      }
      if ((get(0x4ac9c8) === 0)) {
        dc.textOut(20, iVar4, readAnsiString(memory, 0x00494760));
        dc.textOut(20, add32(iVar4, iVar3), readAnsiString(memory, 0x00494700));
        iVar4 = add32(add32(iVar4, iVar3), iVar3);
        dc.textOut(20, iVar4, readAnsiString(memory, 0x004946ac));
        iVar4 = add32(iVar4, iVar3);
        dc.textOut(20, iVar4, readAnsiString(memory, 0x00494650));
      }
      else {
        dc.textOut(20, iVar4, readAnsiString(memory, 0x004945f4));
        dc.textOut(20, add32(iVar4, iVar3), readAnsiString(memory, 0x0049459c));
        iVar4 = add32(add32(iVar4, iVar3), iVar3);
        dc.textOut(20, iVar4, readAnsiString(memory, 0x0049453c));
        iVar4 = add32(iVar4, iVar3);
        dc.textOut(20, iVar4, readAnsiString(memory, 0x004944dc));
      }
      iVar4 = add32(iVar4, iVar3);
    }
    if (((get(0x491140) === 1) && (get(0x4a4e8c) === 3))) {
      if ((get(0x4ac92c) === 0)) {
        dc.setBkColor(0xffffff);
      }
      dc.textOut(20, iVar4, readAnsiString(memory, 0x00494478));
      iVar4 = add32(iVar4, iVar3);
      if ((get(0x4ac9d8) === 0)) {
        dc.textOut(20, iVar4, readAnsiString(memory, 0x00494420));
      }
      else {
        dc.textOut(20, iVar4, readAnsiString(memory, 0x004943cc));
      }
      if ((get(0x4ac92c) === 0)) {
        dc.setTextColor(0x7f0000);
      }
      dc.textOut(20, add32(iVar4, local_18), readAnsiString(memory, 0x00494378));
      iVar4 = add32(add32(iVar4, local_18), iVar3);
      dc.textOut(20, iVar4, readAnsiString(memory, 0x00494328));
      iVar4 = add32(iVar4, iVar3);
      dc.textOut(20, iVar4, readAnsiString(memory, 0x004942dc));
      iVar4 = add32(iVar4, iVar3);
      dc.textOut(20, iVar4, readAnsiString(memory, 0x004942a8));
      iVar4 = add32(iVar4, iVar3);
    }
  }
  if ((get(0x491140) === 2)) {
    dc.textOut(20, iVar4, readAnsiString(memory, 0x00494250));
    if ((get(0x4ac92c) === 0)) {
      dc.setTextColor(0x7f0000);
    }
    dc.textOut(20, add32(iVar4, iVar3), readAnsiString(memory, 0x004941fc));
    iVar4 = add32(add32(iVar4, iVar3), iVar3);
    if ((get(0x4ac92c) === 0)) {
      dc.setTextColor(0xff0000);
    }
    dc.textOut(20, iVar4, readAnsiString(memory, 0x004941a8));
    iVar4 = add32(iVar4, iVar3);
    dc.textOut(20, iVar4, readAnsiString(memory, 0x0049415c));
    iVar4 = add32(iVar4, iVar3);
    if ((get(0x4ac92c) === 0)) {
      dc.setTextColor(0x7f0000);
    }
    dc.textOut(20, iVar4, readAnsiString(memory, 0x0049410c));
    iVar4 = add32(iVar4, iVar3);
    dc.textOut(20, iVar4, readAnsiString(memory, 0x004940b4));
    dc.textOut(20, add32(iVar3, iVar4), readAnsiString(memory, 0x00494084));
  }
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(255);
  }
  dc.textOut(30, sub32(idiv32(get(0x4a72d0), 3), iVar3), readAnsiString(memory, 0x004936e8));
  dc.setTextColor(0);
}

/** Complete original 0x4330f0; ordered colors and text retain width/flag branches. */
export function drawTutorial3(memory, dc, _options = {}) {
  const get = address => memory.readI32(address);
  let iVar2, iVar3, local_10, local_14, local_18, string_param_1;
  iVar2 = get(0x4a763c);
  if ((iVar2 < 0x2bc)) {
    iVar2 = 1;
    local_18 = 16;
    local_14 = 22;
    local_10 = 1;
  }
  else {
    local_10 = 20;
    local_18 = 19;
    iVar2 = 20;
    local_14 = 26;
  }
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar2, 2, readAnsiString(memory, 0x00494f48));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(iVar2, add32(local_14, 2), readAnsiString(memory, 0x00494ef0));
  iVar3 = add32(add32(local_14, 2), local_18);
  string_param_1 = 0x00494e94;
  iVar2 = add32(iVar2, 10);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, string_param_1));
  iVar3 = add32(iVar3, local_18);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00494e58));
  iVar3 = add32(iVar3, local_14);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(local_10, iVar3, readAnsiString(memory, 0x00494e3c));
  iVar3 = add32(iVar3, local_18);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00494de4));
  iVar3 = add32(iVar3, local_18);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00494d9c));
  iVar3 = add32(iVar3, local_18);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00494d38));
  iVar3 = add32(iVar3, local_14);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(local_10, iVar3, readAnsiString(memory, 0x00494d18));
  iVar3 = add32(iVar3, local_18);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00494cc0));
  iVar3 = add32(iVar3, local_18);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00494c68));
  iVar3 = add32(iVar3, local_18);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00494c0c));
  iVar3 = add32(iVar3, local_18);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00494bb4));
  iVar3 = add32(iVar3, local_18);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00494b98));
  iVar3 = add32(iVar3, local_14);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f00);
  }
  dc.textOut(local_10, iVar3, readAnsiString(memory, 0x00494b88));
  iVar3 = add32(iVar3, local_18);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00494b2c));
  iVar3 = add32(iVar3, local_18);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00494ad0));
  iVar3 = add32(iVar3, local_18);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00494a7c));
  iVar3 = add32(iVar3, local_14);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0);
  }
  dc.textOut(local_10, iVar3, readAnsiString(memory, 0x00494a28));
  iVar3 = add32(iVar3, local_18);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x004949dc));
  iVar3 = add32(iVar3, local_18);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00494984));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff00ff);
  }
  dc.textOut(local_10, add32(iVar3, local_14), readAnsiString(memory, 0x00494930));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(255);
  }
  dc.textOut(local_10, add32(idiv32(imul32(get(0x4a72d0), 9), 10), sub32(0, 2)), readAnsiString(memory, 0x004936e8));
}

/** Complete original 0x4337a0; ordered colors and text retain width/flag branches. */
export function drawTutorial4(memory, dc, _options = {}) {
  const get = address => memory.readI32(address);
  let iVar2, iVar3, iVar4, local_14, local_1c, local_20, param_1, string_pCStack_10, string_param_1;
  iVar3 = get(0x4a763c);
  if ((iVar3 < 0x2bc)) {
    iVar3 = 16;
    local_1c = 22;
    local_20 = 5;
    local_14 = 10;
  }
  else {
    iVar3 = 20;
    local_1c = 27;
    local_20 = 20;
    local_14 = 20;
  }
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(local_20, 2, readAnsiString(memory, 0x00495584));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(local_20, add32(local_1c, 2), readAnsiString(memory, 0x0049556c));
  iVar4 = add32(add32(local_1c, 2), iVar3);
  string_param_1 = 0x00495514;
  iVar2 = add32(local_14, local_20);
  dc.textOut(iVar2, iVar4, readAnsiString(memory, string_param_1));
  iVar4 = add32(iVar4, iVar3);
  dc.textOut(iVar2, iVar4, readAnsiString(memory, 0x004954c0));
  iVar4 = add32(iVar4, iVar3);
  dc.textOut(iVar2, iVar4, readAnsiString(memory, 0x00495498));
  iVar4 = add32(iVar4, local_1c);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar2, iVar4, readAnsiString(memory, 0x00495484));
  iVar4 = add32(iVar4, iVar3);
  string_pCStack_10 = 0x00495430;
  param_1 = add32(local_20, imul32(local_14, 2));
  dc.textOut(param_1, iVar4, readAnsiString(memory, string_pCStack_10));
  iVar4 = add32(iVar4, iVar3);
  dc.textOut(param_1, iVar4, readAnsiString(memory, 0x004953d8));
  iVar4 = add32(iVar4, iVar3);
  dc.textOut(param_1, iVar4, readAnsiString(memory, 0x00495388));
  iVar4 = add32(iVar4, local_1c);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(iVar2, iVar4, readAnsiString(memory, 0x00495374));
  iVar4 = add32(iVar4, iVar3);
  dc.textOut(param_1, iVar4, readAnsiString(memory, 0x00495324));
  iVar4 = add32(iVar4, iVar3);
  dc.textOut(param_1, iVar4, readAnsiString(memory, 0x004952d4));
  iVar4 = add32(iVar4, iVar3);
  dc.textOut(param_1, iVar4, readAnsiString(memory, 0x00495294));
  iVar4 = add32(iVar4, local_1c);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar2, iVar4, readAnsiString(memory, 0x00495254));
  iVar4 = add32(iVar4, iVar3);
  dc.textOut(param_1, iVar4, readAnsiString(memory, 0x00495204));
  iVar4 = add32(iVar4, iVar3);
  dc.textOut(param_1, iVar4, readAnsiString(memory, 0x004951a4));
  iVar4 = add32(iVar4, iVar3);
  dc.textOut(param_1, iVar4, readAnsiString(memory, 0x00495144));
  iVar4 = add32(iVar4, iVar3);
  dc.textOut(param_1, iVar4, readAnsiString(memory, 0x004950e8));
  iVar4 = add32(iVar4, iVar3);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(param_1, iVar4, readAnsiString(memory, 0x0049508c));
  iVar4 = add32(iVar4, iVar3);
  dc.textOut(param_1, iVar4, readAnsiString(memory, 0x00495030));
  iVar4 = add32(iVar4, iVar3);
  dc.textOut(param_1, iVar4, readAnsiString(memory, 0x00494fd4));
  iVar4 = add32(iVar4, local_1c);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f00);
  }
  dc.textOut(local_20, iVar4, readAnsiString(memory, 0x00494fbc));
  dc.textOut(local_20, add32(iVar3, iVar4), readAnsiString(memory, 0x00494f5c));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(255);
  }
  dc.textOut(local_20, add32(idiv32(imul32(get(0x4a72d0), 9), 10), sub32(0, 2)), readAnsiString(memory, 0x004936e8));
}

/** Complete original 0x433ea0; ordered colors and text retain width/flag branches. */
export function drawTutorial5(memory, dc, _options = {}) {
  const get = address => memory.readI32(address);
  let iVar2, iVar3, local_10, local_14, local_18, local_1c, string_param_1;
  iVar2 = get(0x4a763c);
  if ((iVar2 < 0x2bc)) {
    iVar2 = 5;
    local_1c = 16;
    local_18 = 22;
    local_14 = 5;
    local_10 = 10;
  }
  else {
    local_18 = 27;
    local_1c = 20;
    local_14 = 20;
    local_10 = 20;
    iVar2 = 20;
  }
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar2, 2, readAnsiString(memory, 0x00495a24));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(iVar2, add32(local_18, 2), readAnsiString(memory, 0x004959d4));
  iVar3 = add32(add32(local_18, 2), local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x004959a8));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00495994));
  iVar3 = add32(iVar3, local_1c);
  string_param_1 = 0x00495944;
  iVar2 = add32(iVar2, local_10);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, string_param_1));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x004958f4));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x004958a4));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00495874));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00495828));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x004957ec));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f00);
  }
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00495794));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00495740));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x004956f4));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(local_14, iVar3, readAnsiString(memory, 0x004956e0));
  iVar3 = add32(iVar3, local_1c);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00495690));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00495634));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x004955e0));
  dc.textOut(iVar2, add32(local_1c, iVar3), readAnsiString(memory, 0x00495594));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(255);
  }
  dc.textOut(local_14, add32(idiv32(imul32(get(0x4a72d0), 9), 10), sub32(0, 2)), readAnsiString(memory, 0x004936e8));
}

/** Complete original 0x434470; ordered colors and text retain width/flag branches. */
export function drawTutorial6(memory, dc, _options = {}) {
  const get = address => memory.readI32(address);
  let iVar2, iVar3, local_14, local_18, local_1c, param_1, string_pCStack_10, string_param_1;
  iVar2 = get(0x4a763c);
  if ((iVar2 < 0x2bc)) {
    iVar2 = 16;
    local_18 = 22;
    local_1c = 5;
    local_14 = 10;
  }
  else {
    iVar2 = 20;
    local_18 = 27;
    local_1c = 20;
    local_14 = 20;
  }
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(local_1c, 2, readAnsiString(memory, 0x004960e4));
  iVar3 = add32(local_18, 2);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f7f7f);
  }
  if ((get(0x491140) === 1)) {
    dc.textOut(local_1c, iVar3, readAnsiString(memory, 0x0049608c));
    iVar3 = add32(iVar3, iVar2);
    dc.textOut(local_1c, iVar3, readAnsiString(memory, 0x0049603c));
  }
  else {
    dc.textOut(local_1c, iVar3, readAnsiString(memory, 0x00495fe4));
    dc.textOut(local_1c, add32(iVar3, iVar2), readAnsiString(memory, 0x00495f98));
    iVar3 = add32(add32(iVar3, iVar2), iVar2);
    if ((get(0x4ac92c) === 0)) {
      dc.setTextColor(127);
    }
    dc.textOut(local_1c, iVar3, readAnsiString(memory, 0x00495f3c));
  }
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(local_1c, add32(iVar3, local_18), readAnsiString(memory, 0x00495f28));
  iVar3 = add32(add32(iVar3, local_18), iVar2);
  string_pCStack_10 = 0x00495ec4;
  param_1 = add32(local_14, local_1c);
  dc.textOut(param_1, iVar3, readAnsiString(memory, string_pCStack_10));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(local_1c, iVar3, readAnsiString(memory, 0x00495ea8));
  iVar3 = add32(iVar3, iVar2);
  dc.textOut(param_1, iVar3, readAnsiString(memory, 0x00495e44));
  iVar3 = add32(iVar3, iVar2);
  dc.textOut(param_1, iVar3, readAnsiString(memory, 0x00495de8));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f00);
  }
  dc.textOut(local_1c, iVar3, readAnsiString(memory, 0x00495dd0));
  iVar3 = add32(iVar3, iVar2);
  dc.textOut(param_1, iVar3, readAnsiString(memory, 0x00495d80));
  iVar3 = add32(iVar3, iVar2);
  dc.textOut(param_1, iVar3, readAnsiString(memory, 0x00495d20));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(127);
  }
  dc.textOut(local_1c, iVar3, readAnsiString(memory, 0x00495d08));
  iVar3 = add32(iVar3, iVar2);
  dc.textOut(param_1, iVar3, readAnsiString(memory, 0x00495cac));
  iVar3 = add32(iVar3, iVar2);
  dc.textOut(param_1, iVar3, readAnsiString(memory, 0x00495c68));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(local_1c, iVar3, readAnsiString(memory, 0x00495c58));
  iVar3 = add32(iVar3, iVar2);
  dc.textOut(param_1, iVar3, readAnsiString(memory, 0x00495bfc));
  iVar3 = add32(iVar3, iVar2);
  dc.textOut(param_1, iVar3, readAnsiString(memory, 0x00495b9c));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0);
  }
  dc.textOut(local_1c, iVar3, readAnsiString(memory, 0x00495b88));
  iVar3 = add32(iVar3, iVar2);
  dc.textOut(param_1, iVar3, readAnsiString(memory, 0x00495b28));
  iVar3 = add32(iVar3, iVar2);
  dc.textOut(param_1, iVar3, readAnsiString(memory, 0x00495ac8));
  iVar3 = add32(iVar3, iVar2);
  dc.textOut(param_1, iVar3, readAnsiString(memory, 0x00495a64));
  dc.textOut(param_1, add32(iVar2, iVar3), readAnsiString(memory, 0x00495a38));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(255);
  }
  dc.textOut(local_1c, add32(idiv32(imul32(get(0x4a72d0), 9), 10), sub32(0, 2)), readAnsiString(memory, 0x004936e8));
}

/** Complete original 0x434c10; ordered colors and text retain width/flag branches. */
export function drawTutorial7(memory, dc, _options = {}) {
  const get = address => memory.readI32(address);
  let iVar2, iVar3, local_10, local_14, local_18, local_1c, string_param_1;
  iVar3 = get(0x4a763c);
  if ((iVar3 < 0x2bd)) {
    iVar2 = 5;
    local_1c = 13;
    local_18 = 16;
    local_14 = 5;
    local_10 = 10;
  }
  else {
    local_14 = 18;
    iVar2 = 18;
    local_1c = 20;
    local_18 = 26;
    local_10 = 20;
    if ((iVar3 < 0x384)) {
      local_14 = 18;
      local_1c = 16;
      iVar2 = 18;
      local_18 = 21;
      local_10 = 15;
    }
  }
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar2, 2, readAnsiString(memory, 0x004969f8));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(iVar2, add32(local_18, 2), readAnsiString(memory, 0x0049699c));
  iVar3 = add32(add32(local_18, 2), local_1c);
  string_param_1 = 0x00496940;
  iVar2 = add32(iVar2, local_10);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, string_param_1));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x004968f4));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(local_14, iVar3, readAnsiString(memory, 0x00496894));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x0049687c));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(local_14, iVar3, readAnsiString(memory, 0x0049681c));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x004967c0));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496774));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496734));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(127);
  }
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x004966ec));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(127);
  }
  dc.textOut(local_14, iVar3, readAnsiString(memory, 0x0049668c));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x0049663c));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(local_14, iVar3, readAnsiString(memory, 0x004965e4));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x004965a0));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(127);
  }
  dc.textOut(local_14, iVar3, readAnsiString(memory, 0x00496544));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x004964f4));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496494));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x0049643c));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f00);
  }
  dc.textOut(local_14, iVar3, readAnsiString(memory, 0x004963e0));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496388));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496328));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f00);
  }
  dc.textOut(local_14, iVar3, readAnsiString(memory, 0x004962cc));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496280));
  iVar3 = add32(iVar3, local_18);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(127);
  }
  dc.textOut(local_14, iVar3, readAnsiString(memory, 0x00496224));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x004961c4));
  iVar3 = add32(iVar3, local_1c);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496160));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f7f);
  }
  dc.textOut(local_14, add32(iVar3, local_18), readAnsiString(memory, 0x00496100));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(255);
  }
  dc.textOut(local_14, add32(idiv32(imul32(get(0x4a72d0), 9), 10), sub32(0, 2)), readAnsiString(memory, 0x004936e8));
}

/** Complete original 0x4354d0; ordered colors and text retain width/flag branches. */
export function drawTutorial8(memory, dc, _options = {}) {
  const get = address => memory.readI32(address);
  let iVar2, iVar3, local_10, local_14, string_param_1;
  iVar2 = get(0x4a763c);
  if ((iVar2 < 0x2bc)) {
    local_14 = 16;
    local_10 = 22;
    iVar2 = 5;
  }
  else {
    iVar2 = 20;
    local_10 = 27;
    local_14 = 20;
  }
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar2, 2, readAnsiString(memory, 0x00497010));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(iVar2, add32(local_10, 2), readAnsiString(memory, 0x00496fb8));
  iVar3 = add32(add32(local_10, 2), local_14);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496f60));
  iVar3 = add32(iVar3, local_14);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496f10));
  iVar3 = add32(iVar3, local_14);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496ec4));
  iVar3 = add32(iVar3, local_10);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496e70));
  iVar3 = add32(iVar3, local_14);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496e1c));
  iVar3 = add32(iVar3, local_14);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496dfc));
  iVar3 = add32(iVar3, local_10);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496dac));
  iVar3 = add32(iVar3, local_14);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496d5c));
  iVar3 = add32(iVar3, local_14);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496d20));
  iVar3 = add32(iVar3, local_10);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496ccc));
  iVar3 = add32(iVar3, local_14);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496c7c));
  iVar3 = add32(iVar3, local_14);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496c2c));
  iVar3 = add32(iVar3, local_14);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496bec));
  iVar3 = add32(iVar3, local_10);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0xff0000);
  }
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496b98));
  iVar3 = add32(iVar3, local_14);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496b5c));
  iVar3 = add32(iVar3, local_10);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496b00));
  iVar3 = add32(iVar3, local_10);
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496aa8));
  iVar3 = add32(iVar3, local_14);
  dc.textOut(iVar2, iVar3, readAnsiString(memory, 0x00496a50));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(0x7f0000);
  }
  dc.textOut(iVar2, add32(iVar3, local_10), readAnsiString(memory, 0x00496a0c));
  if ((get(0x4ac92c) === 0)) {
    dc.setTextColor(255);
  }
  dc.textOut(iVar2, add32(idiv32(imul32(get(0x4a72d0), 9), 10), sub32(0, 2)), readAnsiString(memory, 0x004936e8));
}

