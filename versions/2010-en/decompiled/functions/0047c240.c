
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0047c240(int param_1)

{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  int iVar6;
  int iVar7;
  double *pdVar8;
  int iVar9;
  int iVar10;
  double *pdVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  int local_b80;
  int local_b7c;
  undefined4 local_b78;
  undefined4 uStack_b74;
  double *local_b70;
  int local_b6c;
  double local_b48 [72];
  double adStack_908 [72];
  double adStack_6c8 [72];
  undefined8 local_488;
  double adStack_248 [72];
  
  local_b80 = 0;
  if (param_1 == 1) {
    DAT_0053521c = 0xffffeda4;
    DAT_004f4b5c = 0x640;
    DAT_00534fe4 = 0x960;
    DAT_004fb5e8._0_4_ = 0xcccccccd;
    DAT_004fb5e8._4_4_ = 0x3feccccc;
    DAT_004fafb0._0_4_ = 0x28ae9d0e;
    DAT_004fafb0._4_4_ = 0xc000c161;
    DAT_00522cb4 = 0x2c;
    local_b80 = 0x29;
    DAT_004f45c8 = 0;
    DAT_004f45cc = 0;
    _DAT_004f3ef4 = 0;
    DAT_00535314 = 0;
    DAT_00535374 = 0x32;
  }
  if (param_1 == 2) {
    DAT_00535220 = 0xfffff448;
    DAT_004f4b60 = 0x122a;
    _DAT_00534fe8 = 0x960;
    _DAT_004fb5f0 = 0x66666666;
    _DAT_004fb5f4 = 0x3fe66666;
    DAT_004fafb8._0_4_ = 0xc6fcabd8;
    DAT_004fafb8._4_4_ = 0xc0000ea7;
    DAT_00522cb8 = 0xe;
    local_b80 = 0x28;
    DAT_004f45d0 = 0;
    DAT_004f45d4 = 0;
    _DAT_004f3ef8 = 0;
    DAT_00535318 = 10;
    DAT_00535378 = 0x2d;
  }
  if (param_1 == 3) {
    _DAT_00535224 = 0xa5a;
    _DAT_004f4b64 = 0xa28;
    _DAT_00534fec = 600;
    _DAT_004fb5f8 = 0x33333333;
    _DAT_004fb5fc = 0x3fc33333;
    _DAT_004fafc0 = 0xf9a20929;
    _DAT_004fafc4 = 0x3ff7bc9e;
    _DAT_00522cbc = 0xffffffff;
    local_b80 = -1;
    _DAT_004f45d8 = 0;
    _DAT_004f45dc = 0x3ff00000;
    _DAT_004f3efc = 0;
    _DAT_0053531c = 0;
    _DAT_0053537c = 0x48;
  }
  if (param_1 == 4) {
    _DAT_00535228 = 0x28a;
    _DAT_004f4b68 = 0x1130;
    _DAT_00534ff0 = 0x960;
    _DAT_004fb600 = 0;
    _DAT_004fb604 = 0x3fe00000;
    _DAT_004fafc8 = 0xbd05eb94;
    _DAT_004fafcc = 0x3fe92211;
    _DAT_00522cc0 = 0x32;
    local_b80 = -1;
    _DAT_004f45e0 = 0;
    _DAT_004f45e4 = 0;
    _DAT_004f3f00 = 0;
    _DAT_00535320 = 0x32;
    _DAT_00535380 = 0x48;
  }
  if (param_1 == 5) {
    DAT_0053522c = 0xdac;
    DAT_004f4b6c = 0x125c;
    _DAT_00534ff4 = 0x960;
    _DAT_004fb608 = 0;
    _DAT_004fb60c = 0x3fe00000;
    _DAT_004fafd0 = 0xf9a20929;
    _DAT_004fafd4 = 0x4007bc9e;
    _DAT_00522cc4 = 0x11;
    local_b80 = -1;
    _DAT_004f45e8 = 0;
    _DAT_004f45ec = 0;
    _DAT_004f3f04 = 0;
    _DAT_00535324 = 0x20;
    _DAT_00535384 = 0x28;
  }
  if (param_1 == 6) {
    DAT_00535230 = 0x1518;
    DAT_004f4b70 = 0x708;
    DAT_00534ff8 = 0xed8;
    _DAT_004fb610 = 0x66666666;
    _DAT_004fb614 = 0x3fe66666;
    _DAT_004fafd8 = 0x43cdb06c;
    _DAT_004fafdc = 0x3fdbecf7;
    _DAT_00522cc8 = 0x2b;
    local_b80 = 0x3c;
    _DAT_004f45f0 = 0;
    _DAT_004f45f4 = 0;
    _DAT_004f3f08 = 0;
    _DAT_00535328 = 0x28;
    _DAT_00535388 = 0x3c;
  }
  if (param_1 == 7) {
    DAT_00535234 = 0x18ce;
    DAT_004f4b74 = 0xfffff63c;
    DAT_00534ffc = 0xdac;
    _DAT_004fb618 = 0x33333333;
    _DAT_004fb61c = 0x3fe33333;
    _DAT_004fafe0 = 0x363e26bd;
    _DAT_004fafe4 = 0xbfd6572c;
    _DAT_00522ccc = 0x2c;
    local_b80 = 0x37;
    _DAT_004f45f8 = 0;
    _DAT_004f45fc = 0;
    _DAT_004f3f0c = 0;
    _DAT_0053532c = 0x2c;
    _DAT_0053538c = 0x3c;
  }
  if (param_1 == 8) {
    DAT_00535238 = 0xed8;
    _DAT_004f4b78 = 0xfffff18c;
    DAT_00535000 = 2000;
    _DAT_004fb620 = 0x33333333;
    _DAT_004fb624 = 0x3fe33333;
    _DAT_004fafe8 = 0xaf7661e5;
    _DAT_004fafec = 0x3fe38c46;
    _DAT_00522cd0 = 0x28;
    local_b80 = 0x1e;
    _DAT_004f4600 = 0;
    _DAT_004f4604 = 0;
    _DAT_004f3f10 = 0;
    _DAT_00535330 = 0xf;
    _DAT_00535390 = 0x3c;
  }
  if (param_1 == 9) {
    DAT_0053523c = 2000;
    _DAT_004f4b7c = 0xffffe958;
    _DAT_00535004 = 0xa8c;
    _DAT_004fb628 = 0x66666666;
    _DAT_004fb62c = 0x3fe66666;
    _DAT_004faff0 = 0x43cdb06c;
    _DAT_004faff4 = 0x3febecf7;
    _DAT_00522cd4 = 0x14;
    local_b80 = 0x2a;
    _DAT_004f4608 = 0;
    _DAT_004f460c = 0;
    _DAT_004f3f14 = 0;
    _DAT_00535334 = 0x12;
    _DAT_00535394 = 0x36;
  }
  if (param_1 == 10) {
    DAT_00535240 = 0xffffeb4c;
    DAT_004f4b80 = 0x13ec;
    _DAT_00535008 = 0x960;
    _DAT_004fb630 = 0x9999999a;
    _DAT_004fb634 = 0x3fe19999;
    _DAT_004faff8 = 0x363e26bd;
    _DAT_004faffc = 0xbfc6572c;
    _DAT_00522cd8 = param_1;
    local_b80 = -1;
    _DAT_004f4610 = 0;
    _DAT_004f4614 = 0;
    _DAT_004f3f18 = 0;
    _DAT_00535338 = 0xc;
    _DAT_00535398 = 0x14;
  }
  if (param_1 == 0xb) {
    _DAT_00535244 = 0xffffe318;
    _DAT_004f4b84 = 0xdac;
    _DAT_0053500c = 3000;
    _DAT_004fb638 = 0x9999999a;
    _DAT_004fb63c = 0x3fe99999;
    _DAT_004fb000 = 0x363e26bd;
    _DAT_004fb004 = 0x3fc6572c;
    _DAT_00522cdc = 5;
    local_b80 = 0x42;
    _DAT_004f4618 = 0;
    _DAT_004f461c = 0;
    _DAT_004f3f1c = 0;
    _DAT_0053533c = 1;
    _DAT_0053539c = 0xf;
  }
  if (param_1 == 0xc) {
    DAT_00535248 = 0xfffff510;
    _DAT_004f4b88 = 0xfffffaba;
    _DAT_00535010 = 200;
    _DAT_004fb640 = 0x33333333;
    _DAT_004fb644 = 0x3fe33333;
    _DAT_004fb008 = 0x363e26bd;
    _DAT_004fb00c = 0x3ff6572c;
    _DAT_00522ce0 = 0x16;
    local_b80 = -1;
    _DAT_004f4620 = 0;
    _DAT_004f4624 = 0;
    _DAT_004f3f20 = 0;
    _DAT_00535340 = 0;
    _DAT_005353a0 = 0x24;
  }
  if (param_1 == 0xd) {
    DAT_0053524c = 0xffffe890;
    _DAT_004f4b8c = 0xfffff3e4;
    _DAT_00535014 = 600;
    _DAT_004fb648 = 0x33333333;
    _DAT_004fb64c = 0x3fd33333;
    _DAT_004fb010 = 0x72da4451;
    _DAT_004fb014 = 0x3ff4f1b9;
    _DAT_00522ce4 = 0xf;
    local_b80 = 0x19;
    _DAT_004f4628 = 0;
    _DAT_004f462c = 0;
    _DAT_004f3f24 = 0;
    _DAT_00535344 = 1;
    _DAT_005353a4 = 0x1e;
  }
  if (param_1 == 0xe) {
    _DAT_00535018 = 3000;
    DAT_00535250 = 0xfffffe0c;
    _DAT_004f4b90 = 0xffffdc10;
    _DAT_004fb650 = 0x9999999a;
    _DAT_004fb654 = 0x3fd99999;
    _DAT_004fb018 = 0x28ae9d0e;
    _DAT_004fb01c = 0x3fe0c161;
    _DAT_00522ce8 = 0x12;
    local_b80 = 0x28;
    _DAT_004f4630 = 0;
    _DAT_004f4634 = 0;
    _DAT_004f3f28 = 0;
    _DAT_00535348 = 0x12;
    _DAT_005353a8 = 0x28;
  }
  if (param_1 == 0xf) {
    _DAT_00535254 = 0xffffda1c;
    _DAT_004f4b94 = 0xffffe124;
    _DAT_0053501c = 6000;
    _DAT_004fb658 = 0;
    _DAT_004fb65c = 0x3fe00000;
    _DAT_004fb020 = 0xaf7661e5;
    _DAT_004fb024 = 0xbff38c46;
    _DAT_00522cec = 0x22;
    local_b80 = 0x2c;
    _DAT_004f4638 = 0;
    _DAT_004f463c = 0;
    _DAT_004f3f2c = 0;
    _DAT_0053534c = 0xffffffff;
    _DAT_005353ac = 0xffffffff;
  }
  if (param_1 == 0x10) {
    _DAT_00535258 = 0xffffd508;
    _DAT_004f4b98 = 0xfffffaec;
    _DAT_00535020 = 4000;
    _DAT_004fb660 = 0x9999999a;
    _DAT_004fb664 = 0x3fc99999;
    _DAT_004fb028 = 0xec127f79;
    _DAT_004fb02c = 0x3ff226d3;
    _DAT_00522cf0 = 10;
    local_b80 = 3;
    _DAT_004f4640 = 0;
    _DAT_004f4644 = 0;
    _DAT_004f3f30 = 0;
    _DAT_00535350 = 0xffffffff;
    _DAT_005353b0 = 0xffffffff;
  }
  fVar12 = (float10)fcos((float10)*(double *)(&DAT_004fafa8 + param_1 * 8));
  iVar9 = *(int *)(&DAT_00534fe0 + param_1 * 4);
  local_b70 = local_b48;
  iVar10 = 0;
  local_b7c = 0;
  iVar6 = param_1 * 0x124;
  fVar13 = (float10)fsin((float10)*(double *)(&DAT_004fafa8 + param_1 * 8));
  local_b6c = iVar6;
  do {
    iVar7 = iVar9 / 0x1e;
    if (*(double *)(&DAT_004fb5e0 + param_1 * 8) < _DAT_004cc4f8) {
      if ((local_b7c < 0x28) || (0x140 < local_b7c)) {
        iVar7 = iVar9 / 0x28;
      }
      if ((0x8c < local_b7c) && (local_b7c < 0xdc)) {
        iVar7 = iVar9 / 0x28;
      }
    }
    iVar9 = *(int *)(&DAT_00534fe0 + param_1 * 4);
    iVar7 = FUN_0041e000(iVar7);
    pdVar11 = (double *)(&local_488 + iVar10);
    dVar2 = (double)(iVar9 - iVar7);
    local_b78 = SUB84(dVar2,0);
    uStack_b74 = (undefined4)((ulonglong)dVar2 >> 0x20);
    *(undefined4 *)pdVar11 = local_b78;
    iVar7 = *(int *)(&DAT_00522cb0 + param_1 * 4);
    *(undefined4 *)((int)&local_488 + iVar10 * 8 + 4) = uStack_b74;
    if (0 < iVar7) {
      if (iVar10 == iVar7) {
        *pdVar11 = dVar2 * _DAT_004ccac8;
      }
      if (iVar10 == iVar7 + 1) {
        *pdVar11 = *pdVar11 * _DAT_004ccd68;
      }
      if (iVar10 == iVar7 + 2) {
        *pdVar11 = *pdVar11 * _DAT_004cc848;
      }
      if (iVar10 == iVar7 + 3) {
        *pdVar11 = *pdVar11 * _DAT_004cc6c0;
      }
      if (iVar10 == iVar7 + 4) {
        *pdVar11 = *pdVar11 * _DAT_004ccc70;
      }
      if (iVar10 == iVar7 + 5) {
        *pdVar11 = *pdVar11 * _DAT_004cc508;
      }
      if (iVar10 == iVar7 + 6) {
        *pdVar11 = *pdVar11 * _DAT_004ccc00;
      }
      if (iVar10 == iVar7 + 7) {
        *pdVar11 = *pdVar11 * _DAT_004ccbe0;
      }
      if (iVar10 == iVar7 + 8) {
        *pdVar11 = *pdVar11 * _DAT_004cc738;
      }
      if (iVar10 == iVar7 + 9) {
        *pdVar11 = *pdVar11 * _DAT_004cc738;
      }
      if (iVar10 == iVar7 + 10) {
        *pdVar11 = *pdVar11 * _DAT_004ccbe0;
      }
      if (iVar10 == iVar7 + 0xb) {
        *pdVar11 = *pdVar11 * _DAT_004ccc00;
      }
      if (iVar10 == iVar7 + 0xc) {
        *pdVar11 = *pdVar11 * _DAT_004cc508;
      }
      if (iVar10 == iVar7 + 0xd) {
        *pdVar11 = *pdVar11 * _DAT_004ccc70;
      }
      if (iVar10 == iVar7 + 0xe) {
        *pdVar11 = *pdVar11 * _DAT_004cc6c0;
      }
      if (iVar10 == iVar7 + 0xf) {
        *pdVar11 = *pdVar11 * _DAT_004cc848;
      }
      if (iVar10 == iVar7 + 0x10) {
        *pdVar11 = *pdVar11 * _DAT_004ccd68;
      }
      if (iVar10 == iVar7 + 0x11) {
        *pdVar11 = *pdVar11 * _DAT_004ccac8;
      }
    }
    if (0 < local_b80) {
      if (iVar10 == local_b80 + -1) {
        *pdVar11 = *pdVar11 * _DAT_004ccd70;
      }
      if (iVar10 == local_b80) {
        *pdVar11 = *pdVar11 * _DAT_004cc630;
      }
      if (iVar10 == local_b80 + 1) {
        *pdVar11 = *pdVar11 * _DAT_004ccd70;
      }
    }
    fVar14 = (float10)fsin((float10)local_b7c * (float10)_DAT_004cc568);
    fVar15 = (float10)fcos((float10)local_b7c * (float10)_DAT_004cc568);
    dVar2 = (double)-(fVar15 * (float10)*pdVar11);
    dVar3 = (double)(fVar14 * (float10)*pdVar11 * (float10)*(double *)(&DAT_004fb5e0 + param_1 * 8))
    ;
    dVar4 = (double)fVar12 * dVar3 - (double)fVar13 * dVar2;
    dVar5 = (double)fVar12 * dVar2 + (double)fVar13 * dVar3;
    adStack_908[iVar10] = dVar3;
    *local_b70 = dVar2;
    adStack_6c8[iVar10] = dVar4;
    adStack_248[iVar10] = dVar5;
    *(int *)(&DAT_004f1cf8 + local_b6c) =
         (int)(longlong)dVar4 + *(int *)(&DAT_00535218 + param_1 * 4);
    local_b7c = local_b7c + 5;
    local_b70 = local_b70 + 1;
    iVar10 = iVar10 + 1;
    *(int *)(&DAT_004f8ee8 + local_b6c) =
         (int)(longlong)dVar5 + *(int *)(&DAT_004f4b58 + param_1 * 4);
    iVar7 = DAT_00522f08;
    local_b6c = local_b6c + 4;
  } while (local_b7c < 0x164);
  *(undefined4 *)(&DAT_004f1e18 + iVar6) = *(undefined4 *)(&DAT_004f1cf8 + iVar6);
  *(undefined4 *)(&DAT_004f9008 + iVar6) = *(undefined4 *)(&DAT_004f8ee8 + iVar6);
  iVar9 = DAT_004da1e8;
  if (0 < iVar7) {
    iVar6 = DAT_004da194 * 8;
    iVar10 = 0;
    pdVar11 = (double *)(iVar6 + 0x4fb0a8);
    pdVar8 = (double *)(iVar6 + 0x4f83d8);
    do {
      if (iVar9 == 0) {
        iVar1 = *(int *)((int)&DAT_004f4b5c + iVar10);
        *(double *)((int)&DAT_004f83c8 + iVar6) = (double)*(int *)((int)&DAT_0053521c + iVar10);
        *(double *)((int)&DAT_004fb098 + iVar6) = (double)iVar1;
      }
      if (iVar9 == 1) {
        iVar1 = *(int *)((int)&DAT_004f4b5c + iVar10);
        *pdVar8 = (double)*(int *)((int)&DAT_0053521c + iVar10);
        *pdVar11 = (double)iVar1;
      }
      iVar6 = iVar6 + 8;
      pdVar8 = pdVar8 + 1;
      pdVar11 = pdVar11 + 1;
      iVar10 = iVar10 + 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  return;
}

