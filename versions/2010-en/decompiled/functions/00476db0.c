
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00476db0(int param_1)

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
  double *pdVar10;
  int iVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  int local_b80;
  int local_b7c;
  undefined4 local_b78;
  undefined4 uStack_b74;
  double *local_b6c;
  int local_b60;
  double local_b48 [72];
  double adStack_908 [72];
  double adStack_6c8 [72];
  undefined8 local_488;
  double adStack_248 [72];
  
  local_b80 = 0;
  if (param_1 == 1) {
    DAT_0053521c = 0xffffe4d0;
    DAT_004f4b5c = 0;
    DAT_00534fe4 = 2000;
    DAT_004fb5e8._0_4_ = 0x9999999a;
    DAT_004fb5e8._4_4_ = 0x3fd99999;
    DAT_004fafb0._0_4_ = 0x28ae9d0e;
    DAT_004fafb0._4_4_ = 0x3fe0c161;
    DAT_00522cb4 = 8;
    local_b80 = -1;
    DAT_004f45c8 = 0;
    DAT_004f45cc = 0;
    _DAT_004f3ef4 = param_1;
    DAT_00535314 = 7;
    DAT_00535374 = 0x28;
  }
  if (param_1 == 2) {
    DAT_00535220 = 0xffffea70;
    DAT_004f4b60 = 0xfffff358;
    _DAT_00534fe8 = 0x9c4;
    _DAT_004fb5f0 = 0x9999999a;
    _DAT_004fb5f4 = 0x3fd99999;
    DAT_004fafb8._0_4_ = 0x363e26bd;
    DAT_004fafb8._4_4_ = 0x3fc6572c;
    DAT_00522cb8 = 0x14;
    local_b80 = -1;
    DAT_004f45d0 = 0;
    DAT_004f45d4 = 0;
    _DAT_004f3ef8 = 1;
    DAT_00535318 = 7;
    DAT_00535378 = 0x28;
  }
  if (param_1 == 3) {
    _DAT_00535224 = 0xffffee30;
    _DAT_004f4b64 = 0xffffe4d0;
    _DAT_00534fec = 0x9c4;
    _DAT_004fb5f8 = 0;
    _DAT_004fb5fc = 0x3fe00000;
    _DAT_004fafc0 = 0x28ae9d0e;
    _DAT_004fafc4 = 0x3fe0c161;
    _DAT_00522cbc = 8;
    local_b80 = -1;
    _DAT_004f45d8 = 0;
    _DAT_004f45dc = 0;
    _DAT_004f3efc = 2;
    _DAT_0053531c = 7;
    _DAT_0053537c = 0x28;
  }
  if (param_1 == 4) {
    _DAT_00535228 = 0xffffdf30;
    _DAT_004f4b68 = 0xf00;
    _DAT_00534ff0 = 3000;
    _DAT_004fb600 = 0x9999999a;
    _DAT_004fb604 = 0x3fd99999;
    _DAT_004fafc8 = 0x28ae9d0e;
    _DAT_004fafcc = 0x3fd0c161;
    _DAT_00522cc0 = 8;
    local_b80 = -1;
    _DAT_004f45e0 = 0;
    _DAT_004f45e4 = 0;
    _DAT_004f3f00 = 1;
    _DAT_00535320 = 7;
    _DAT_00535380 = 0x28;
  }
  if (param_1 == 5) {
    DAT_0053522c = 0xfffffd30;
    DAT_004f4b6c = 0xffffd738;
    _DAT_00534ff4 = 4000;
    _DAT_004fb608 = 0;
    _DAT_004fb60c = 0x3fe00000;
    _DAT_004fafd0 = 0x43cdb06c;
    _DAT_004fafd4 = 0x3febecf7;
    _DAT_00522cc4 = 0x12;
    local_b80 = -1;
    _DAT_004f45e8 = 0;
    _DAT_004f45ec = 0;
    _DAT_004f3f04 = 2;
    _DAT_00535324 = 7;
    _DAT_00535384 = 0x28;
  }
  if (param_1 == 6) {
    DAT_00535230 = 0xac8;
    DAT_004f4b70 = 0xffffc298;
    DAT_00534ff8 = 5000;
    _DAT_004fb610 = 0;
    _DAT_004fb614 = 0x3fe00000;
    _DAT_004fafd8 = 0x363e26bd;
    _DAT_004fafdc = 0x3fc6572c;
    _DAT_00522cc8 = 0x12;
    local_b80 = -1;
    _DAT_004f45f0 = 0;
    _DAT_004f45f4 = 0;
    _DAT_004f3f08 = 2;
    _DAT_00535328 = 7;
    _DAT_00535388 = 0x28;
  }
  if (param_1 == 7) {
    DAT_00535234 = 0xffffd210;
    DAT_004f4b74 = 0x1d4c;
    DAT_00534ffc = 0xdac;
    _DAT_004fb618 = 0x33333333;
    _DAT_004fb61c = 0x3fe33333;
    _DAT_004fafe0 = 0x28ae9d0e;
    _DAT_004fafe4 = 0xc000c161;
    _DAT_00522ccc = 0x2c;
    local_b80 = -1;
    _DAT_004f45f8 = 0;
    _DAT_004f45fc = 0;
    _DAT_004f3f0c = 1;
    _DAT_0053532c = 0x2c;
    _DAT_0053538c = 0x3c;
  }
  if (param_1 == 8) {
    DAT_00535238 = 0xffffc748;
    _DAT_004f4b78 = 0x2fd0;
    DAT_00535000 = 4000;
    _DAT_004fb620 = 0x33333333;
    _DAT_004fb624 = 0x3fe33333;
    _DAT_004fafe8 = 0x363e26bd;
    _DAT_004fafec = 0x3fb6572c;
    _DAT_00522cd0 = param_1;
    local_b80 = -1;
    _DAT_004f4600 = 0;
    _DAT_004f4604 = 0;
    _DAT_004f3f10 = 1;
    _DAT_00535330 = 7;
    _DAT_00535390 = 0x28;
  }
  if (param_1 == 9) {
    DAT_0053523c = 0x1a40;
    _DAT_004f4b7c = 0xfffffe20;
    _DAT_00535004 = 500;
    _DAT_004fb628 = 0x9999999a;
    _DAT_004fb62c = 0x3fd99999;
    _DAT_004faff0 = 0xaf7661e5;
    _DAT_004faff4 = 0x40038c46;
    _DAT_00522cd4 = 8;
    local_b80 = -1;
    _DAT_004f4608 = 0;
    _DAT_004f460c = 0;
    _DAT_004f3f14 = 1;
    _DAT_00535334 = 6;
    _DAT_00535394 = 0x32;
  }
  if (param_1 == 10) {
    DAT_00535240 = 0x1f68;
    DAT_004f4b80 = 0xffffee30;
    _DAT_00535008 = 0xce4;
    _DAT_004fb630 = 0x33333333;
    _DAT_004fb634 = 0x3fd33333;
    _DAT_004faff8 = 0x363e26bd;
    _DAT_004faffc = 0x3fd6572c;
    _DAT_00522cd8 = 0x37;
    local_b80 = 0x31;
    _DAT_004f4610 = 0;
    _DAT_004f4614 = 0;
    _DAT_004f3f18 = 1;
    _DAT_00535338 = 0x27;
    _DAT_00535398 = 0x46;
  }
  if (param_1 == 0xb) {
    _DAT_00535244 = 0x1e78;
    _DAT_004f4b84 = 0xfffffe98;
    _DAT_0053500c = 0x9c4;
    _DAT_004fb638 = 0x9999999a;
    _DAT_004fb63c = 0x3fd99999;
    _DAT_004fb000 = 0x363e26bd;
    _DAT_004fb004 = 0xbfd6572c;
    _DAT_00522cdc = 0x28;
    local_b80 = 0x24;
    _DAT_004f4618 = 0;
    _DAT_004f461c = 0;
    _DAT_004f3f1c = 1;
    _DAT_0053533c = 0x27;
    _DAT_0053539c = 0x46;
  }
  if (param_1 == 0xc) {
    DAT_00535248 = 0x1a40;
    _DAT_004f4b88 = 0xffffdbe8;
    _DAT_00535010 = 0x4b0;
    _DAT_004fb640 = 0x33333333;
    _DAT_004fb644 = 0x3fd33333;
    _DAT_004fb008 = 0xec127f79;
    _DAT_004fb00c = 0x400226d3;
    _DAT_00522ce0 = 0x28;
    local_b80 = 0x21;
    _DAT_004f4620 = 0;
    _DAT_004f4624 = 0;
    _DAT_004f3f20 = 1;
    _DAT_00535340 = 4;
    _DAT_005353a0 = 0x28;
  }
  if (param_1 == 0xd) {
    DAT_0053524c = 0x21c0;
    _DAT_004f4b8c = 0xffffd7b0;
    _DAT_00535014 = 3000;
    _DAT_004fb648 = 0x33333333;
    _DAT_004fb64c = 0x3fe33333;
    _DAT_004fb010 = 0x28ae9d0e;
    _DAT_004fb014 = 0x3fe0c161;
    _DAT_00522ce4 = 0x28;
    local_b80 = 0x32;
    _DAT_004f4628 = 0;
    _DAT_004f462c = 0;
    _DAT_004f3f24 = 2;
    _DAT_00535344 = 4;
    _DAT_005353a4 = 0x28;
  }
  if (param_1 == 0xe) {
    DAT_00535250 = 0x9d8;
    _DAT_004f4b90 = 0xffffd828;
    _DAT_00535018 = 800;
    _DAT_004fb650 = 0x9999999a;
    _DAT_004fb654 = 0x3fc99999;
    _DAT_004fb018 = 0xbd05eb94;
    _DAT_004fb01c = 0x3ff92211;
    _DAT_00522ce8 = 8;
    local_b80 = -1;
    _DAT_004f4630 = 0;
    _DAT_004f4634 = 0x3ff00000;
    _DAT_004f3f28 = 0;
    _DAT_00535348 = 4;
    _DAT_005353a8 = 0x22;
  }
  if (param_1 == 0xf) {
    _DAT_00535254 = 0xffffcc70;
    _DAT_004f4b94 = 0xfffff6a0;
    _DAT_0053501c = 15000;
    _DAT_004fb658 = 0xcccccccd;
    _DAT_004fb65c = 0x3fdccccc;
    _DAT_004fb020 = 0xfae80754;
    _DAT_004fb024 = 0x3fd2fd4b;
    _DAT_00522cec = 0xffffffff;
    local_b80 = -1;
    _DAT_004f4638 = 0;
    _DAT_004f463c = 0x3ff00000;
    _DAT_004f3f2c = 2;
    _DAT_0053534c = 0xffffffff;
    _DAT_005353ac = 0xffffffff;
  }
  if (param_1 == 0x10) {
    _DAT_00535258 = 0xfffff1f0;
    _DAT_004f4b98 = 0xffffcc70;
    _DAT_00535020 = 8000;
    _DAT_004fb660 = 0xcccccccd;
    _DAT_004fb664 = 0x3fdccccc;
    _DAT_004fb028 = 0x363e26bd;
    _DAT_004fb02c = 0x3fe6572c;
    _DAT_00522cf0 = 0xffffffff;
    local_b80 = -1;
    _DAT_004f4640 = 0;
    _DAT_004f4644 = 0;
    _DAT_004f3f30 = 2;
    _DAT_00535350 = 0xffffffff;
    _DAT_005353b0 = 0xffffffff;
  }
  if (param_1 == 0x11) {
    _DAT_0053525c = 0x20d0;
    _DAT_004f4b9c = 0xd98;
    _DAT_00535024 = 1000;
    _DAT_004fb668 = 0x9999999a;
    _DAT_004fb66c = 0x3fe99999;
    _DAT_004fb030 = 0xbd05eb94;
    _DAT_004fb034 = 0x3ff92211;
    _DAT_00522cf4 = 0xc;
    local_b80 = -1;
    _DAT_004f4648 = 0;
    _DAT_004f464c = 0;
    _DAT_004f3f34 = 0;
    _DAT_00535354 = 0xffffffff;
    _DAT_005353b4 = 0xffffffff;
  }
  if (param_1 == 0x12) {
    _DAT_00535260 = 0x20d0;
    _DAT_004f4ba0 = 0x1ef0;
    _DAT_00535028 = 4000;
    _DAT_004fb670 = 0x9999999a;
    _DAT_004fb674 = 0x3fd99999;
    _DAT_004fb038 = 0xbd05eb94;
    _DAT_004fb03c = 0x40092211;
    _DAT_00522cf8 = 0x1c;
    local_b80 = -1;
    _DAT_004f4650 = 0;
    _DAT_004f4654 = 0;
    _DAT_004f3f38 = 0;
    _DAT_00535358 = 0xffffffff;
    _DAT_005353b8 = 0xffffffff;
  }
  fVar12 = (float10)fcos((float10)*(double *)(&DAT_004fafa8 + param_1 * 8));
  local_b6c = local_b48;
  iVar9 = 0;
  local_b7c = 0;
  iVar6 = param_1 * 0x124;
  fVar13 = (float10)fsin((float10)*(double *)(&DAT_004fafa8 + param_1 * 8));
  local_b60 = iVar6;
  do {
    iVar11 = *(int *)(&DAT_00534fe0 + param_1 * 4);
    iVar7 = iVar11 / 0x1e;
    if (*(double *)(&DAT_004fb5e0 + param_1 * 8) < _DAT_004cc4f8) {
      if ((local_b7c < 0x28) || (0x140 < local_b7c)) {
        iVar7 = iVar11 / 0x28;
      }
      if ((0x8c < local_b7c) && (local_b7c < 0xdc)) {
        iVar7 = iVar11 / 0x28;
      }
    }
    iVar11 = *(int *)(&DAT_00534fe0 + param_1 * 4);
    iVar7 = FUN_0041e000(iVar7);
    pdVar10 = (double *)(&local_488 + iVar9);
    dVar2 = (double)(iVar11 - iVar7);
    local_b78 = SUB84(dVar2,0);
    uStack_b74 = (undefined4)((ulonglong)dVar2 >> 0x20);
    *(undefined4 *)pdVar10 = local_b78;
    *(undefined4 *)((int)&local_488 + iVar9 * 8 + 4) = uStack_b74;
    iVar11 = *(int *)(&DAT_00522cb0 + param_1 * 4);
    if (0 < iVar11) {
      if (iVar9 == iVar11) {
        *pdVar10 = dVar2 * _DAT_004ccac8;
      }
      if (iVar9 == iVar11 + 1) {
        *pdVar10 = *pdVar10 * _DAT_004ccd68;
      }
      if (iVar9 == iVar11 + 2) {
        *pdVar10 = *pdVar10 * _DAT_004cc848;
      }
      if (iVar9 == iVar11 + 3) {
        *pdVar10 = *pdVar10 * _DAT_004cc6c0;
      }
      if (iVar9 == iVar11 + 4) {
        *pdVar10 = *pdVar10 * _DAT_004ccc70;
      }
      if (iVar9 == iVar11 + 5) {
        *pdVar10 = *pdVar10 * _DAT_004cc508;
      }
      if (iVar9 == iVar11 + 6) {
        *pdVar10 = *pdVar10 * _DAT_004ccc00;
      }
      if (iVar9 == iVar11 + 7) {
        *pdVar10 = *pdVar10 * _DAT_004ccbe0;
      }
      if (iVar9 == iVar11 + 8) {
        *pdVar10 = *pdVar10 * _DAT_004cc738;
      }
      if (iVar9 == iVar11 + 9) {
        *pdVar10 = *pdVar10 * _DAT_004cc738;
      }
      if (iVar9 == iVar11 + 10) {
        *pdVar10 = *pdVar10 * _DAT_004ccbe0;
      }
      if (iVar9 == iVar11 + 0xb) {
        *pdVar10 = *pdVar10 * _DAT_004ccc00;
      }
      if (iVar9 == iVar11 + 0xc) {
        *pdVar10 = *pdVar10 * _DAT_004cc508;
      }
      if (iVar9 == iVar11 + 0xd) {
        *pdVar10 = *pdVar10 * _DAT_004ccc70;
      }
      if (iVar9 == iVar11 + 0xe) {
        *pdVar10 = *pdVar10 * _DAT_004cc6c0;
      }
      if (iVar9 == iVar11 + 0xf) {
        *pdVar10 = *pdVar10 * _DAT_004cc848;
      }
      if (iVar9 == iVar11 + 0x10) {
        *pdVar10 = *pdVar10 * _DAT_004ccd68;
      }
      if (iVar9 == iVar11 + 0x11) {
        *pdVar10 = *pdVar10 * _DAT_004ccac8;
      }
    }
    if (0 < local_b80) {
      if (iVar9 == local_b80 + -1) {
        *pdVar10 = *pdVar10 * _DAT_004ccd70;
      }
      if (iVar9 == local_b80) {
        *pdVar10 = *pdVar10 * _DAT_004cc630;
      }
      if (iVar9 == local_b80 + 1) {
        *pdVar10 = *pdVar10 * _DAT_004ccd70;
      }
    }
    fVar14 = (float10)fsin((float10)local_b7c * (float10)_DAT_004cc568);
    fVar15 = (float10)fcos((float10)local_b7c * (float10)_DAT_004cc568);
    dVar2 = (double)-(fVar15 * (float10)*pdVar10);
    dVar3 = (double)(fVar14 * (float10)*pdVar10 * (float10)*(double *)(&DAT_004fb5e0 + param_1 * 8))
    ;
    dVar4 = (double)fVar12 * dVar3 - (double)fVar13 * dVar2;
    dVar5 = (double)fVar13 * dVar3 + (double)fVar12 * dVar2;
    adStack_908[iVar9] = dVar3;
    *local_b6c = dVar2;
    adStack_6c8[iVar9] = dVar4;
    adStack_248[iVar9] = dVar5;
    *(int *)(&DAT_004f1cf8 + local_b60) =
         (int)(longlong)dVar4 + *(int *)(&DAT_00535218 + param_1 * 4);
    local_b7c = local_b7c + 5;
    *(int *)(&DAT_004f8ee8 + local_b60) =
         (int)(longlong)dVar5 + *(int *)(&DAT_004f4b58 + param_1 * 4);
    iVar11 = DAT_00522f08;
    iVar9 = iVar9 + 1;
    local_b6c = local_b6c + 1;
    local_b60 = local_b60 + 4;
  } while (local_b7c < 0x164);
  *(undefined4 *)(&DAT_004f1e18 + iVar6) = *(undefined4 *)(&DAT_004f1cf8 + iVar6);
  *(undefined4 *)(&DAT_004f9008 + iVar6) = *(undefined4 *)(&DAT_004f8ee8 + iVar6);
  iVar6 = DAT_004da1e8;
  if (0 < iVar11) {
    iVar7 = 0;
    iVar9 = DAT_004da194 * 8;
    pdVar10 = (double *)(iVar9 + 0x4fb0a8);
    pdVar8 = (double *)(iVar9 + 0x4f83d8);
    do {
      if (iVar6 == 0) {
        iVar1 = *(int *)((int)&DAT_004f4b5c + iVar7);
        *(double *)((int)&DAT_004f83c8 + iVar9) = (double)*(int *)((int)&DAT_0053521c + iVar7);
        *(double *)((int)&DAT_004fb098 + iVar9) = (double)iVar1;
      }
      if (iVar6 == 1) {
        iVar1 = *(int *)((int)&DAT_004f4b5c + iVar7);
        *pdVar8 = (double)*(int *)((int)&DAT_0053521c + iVar7);
        *pdVar10 = (double)iVar1;
      }
      iVar9 = iVar9 + 8;
      pdVar8 = pdVar8 + 1;
      pdVar10 = pdVar10 + 1;
      iVar7 = iVar7 + 4;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  return;
}

