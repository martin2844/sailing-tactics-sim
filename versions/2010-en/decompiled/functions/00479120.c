
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00479120(int param_1)

{
  int iVar1;
  double dVar2;
  double dVar3;
  uint uVar4;
  double dVar5;
  double dVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  double *pdVar10;
  int iVar11;
  uint uVar12;
  double *pdVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  uint local_b80;
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
  
  if (param_1 == 1) {
    DAT_0053521c = 0xfffff3e7;
    DAT_004f4b5c = 0xfffff93c;
    DAT_00534fe4 = 0x17c;
    DAT_004fb5e8._0_4_ = 0x33333333;
    DAT_004fb5e8._4_4_ = 0x3fc33333;
    DAT_004fafb0._0_4_ = 0x81afcc2b;
    DAT_004fafb0._4_4_ = 0xbfe5c831;
    DAT_00522cb4 = 0x28;
    DAT_004f45c8 = 0;
    DAT_004f45cc = 0x3ff00000;
    _DAT_004f3ef4 = 0;
    DAT_00535314 = 1;
    DAT_00535374 = 0x47;
  }
  local_b80 = (uint)(param_1 == 1);
  if (param_1 == 2) {
    DAT_00535220 = 0xfffff41b;
    DAT_004f4b60 = 0xfffff4f3;
    _DAT_00534fe8 = 1000;
    _DAT_004fb5f0 = 0x9999999a;
    _DAT_004fb5f4 = 0x3fd99999;
    DAT_004fafb8._0_4_ = 0x363e26bd;
    DAT_004fafb8._4_4_ = 0x3fd6572c;
    DAT_00522cb8 = 0xf;
    local_b80 = 0x1e;
    DAT_004f45d0 = 0;
    DAT_004f45d4 = 0;
    _DAT_004f3ef8 = 0;
    DAT_00535318 = 1;
    DAT_00535378 = 0x28;
  }
  if (param_1 == 3) {
    _DAT_00535224 = 0xfffff522;
    _DAT_004f4b64 = 0xfffff087;
    _DAT_00534fec = 0x4b0;
    _DAT_004fb5f8 = 0x33333333;
    _DAT_004fb5fc = 0x3fe33333;
    _DAT_004fafc0 = 0x43cdb06c;
    _DAT_004fafc4 = 0xbfdbecf7;
    _DAT_00522cbc = 0x28;
    local_b80 = 0x12;
    _DAT_004f45d8 = 0;
    _DAT_004f45dc = 0;
    _DAT_004f3efc = 0;
    _DAT_0053531c = 0x12;
    _DAT_0053537c = 0x2d;
  }
  if (param_1 == 4) {
    _DAT_00535228 = 0xffffe971;
    _DAT_004f4b68 = 0xfffff642;
    _DAT_00534ff0 = 0x960;
    _DAT_004fb600 = 0x33333333;
    _DAT_004fb604 = 0x3fe33333;
    _DAT_004fafc8 = 0x363e26bd;
    _DAT_004fafcc = 0xbfb6572c;
    _DAT_00522cc0 = 0x1a;
    local_b80 = 0x28;
    _DAT_004f45e0 = 0;
    _DAT_004f45e4 = 0;
    _DAT_004f3f00 = 1;
    _DAT_00535320 = 0xf;
    _DAT_00535380 = 0x2e;
  }
  if (param_1 == 5) {
    DAT_0053522c = 0xffffe7cd;
    DAT_004f4b6c = 0xfffffe83;
    _DAT_00534ff4 = 300;
    _DAT_004fb608 = 0x9999999a;
    _DAT_004fb60c = 0x3fc99999;
    _DAT_004fafd0 = 0xaf7661e5;
    _DAT_004fafd4 = 0x3fe38c46;
    _DAT_00522cc4 = 10;
    local_b80 = 0x24;
    _DAT_004f45e8 = 0;
    _DAT_004f45ec = 0;
    _DAT_004f3f04 = 0;
    _DAT_00535324 = param_1;
    _DAT_00535384 = 0x24;
  }
  if (param_1 == 6) {
    DAT_00535230 = 0xffffdeb2;
    DAT_004f4b70 = 0x73;
    DAT_00534ff8 = 5000;
    _DAT_004fb610 = 0x9999999a;
    _DAT_004fb614 = 0x3fd99999;
    _DAT_004fafd8 = 0x363e26bd;
    _DAT_004fafdc = 0x3fb6572c;
    _DAT_00522cc8 = 0x19;
    local_b80 = 0x28;
    _DAT_004f45f0 = 0;
    _DAT_004f45f4 = 0;
    _DAT_004f3f08 = 2;
    _DAT_00535328 = 10;
    _DAT_00535388 = 0x28;
  }
  if (param_1 == 7) {
    DAT_00535234 = 0x276;
    DAT_004f4b74 = 0xffffe18c;
    DAT_00534ffc = 4000;
    _DAT_004fb618 = 0x9999999a;
    _DAT_004fb61c = 0x3fd99999;
    _DAT_004fafe0 = 0x43cdb06c;
    _DAT_004fafe4 = 0x3fdbecf7;
    _DAT_00522ccc = 0x1c;
    local_b80 = 0x1a;
    _DAT_004f45f8 = 0;
    _DAT_004f45fc = 0;
    _DAT_004f3f0c = 1;
    _DAT_0053532c = 0x13;
    _DAT_0053538c = 0x29;
  }
  if (param_1 == 8) {
    DAT_00535238 = 0xfffff835;
    _DAT_004f4b78 = 0xffffe1c6;
    DAT_00535000 = 0xce4;
    _DAT_004fb620 = 0;
    _DAT_004fb624 = 0x3fe00000;
    _DAT_004fafe8 = 0x28ae9d0e;
    _DAT_004fafec = 0x3fd0c161;
    _DAT_00522cd0 = 0x1e;
    local_b80 = 0x2e;
    _DAT_004f4600 = 0;
    _DAT_004f4604 = 0;
    _DAT_004f3f10 = 1;
    _DAT_00535330 = 0x1a;
    _DAT_00535390 = 0x23;
  }
  if (param_1 == 9) {
    _DAT_004f4b7c = 0xffffe18c;
    DAT_0053523c = 0xbe5;
    _DAT_00535004 = 0x1194;
    _DAT_004fb628 = 0x9999999a;
    _DAT_004fb62c = 0x3fc99999;
    _DAT_004faff0 = 0xdab0fb49;
    _DAT_004faff4 = 0x3fdacf01;
    _DAT_00522cd4 = 0x26;
    local_b80 = 0x23;
    _DAT_004f4608 = 0;
    _DAT_004f460c = 0;
    _DAT_004f3f14 = 1;
    _DAT_00535334 = 0x14;
    _DAT_00535394 = 0x32;
  }
  if (param_1 == 10) {
    DAT_00535240 = 0x5be;
    DAT_004f4b80 = 0x1f95;
    _DAT_00535008 = 0x157c;
    _DAT_004fb630 = 0x33333333;
    _DAT_004fb634 = 0x3fe33333;
    _DAT_004faff8 = 0x4dc470af;
    _DAT_004faffc = 0x4002d98d;
    _DAT_00522cd8 = 0x37;
    local_b80 = 0x23;
    _DAT_004f4610 = 0;
    _DAT_004f4614 = 0;
    _DAT_004f3f18 = 1;
    _DAT_00535338 = 0x23;
    _DAT_00535398 = 0x41;
  }
  if (param_1 == 0xb) {
    _DAT_00535244 = 0x21a2;
    _DAT_004f4b84 = 0x14fa;
    _DAT_0053500c = 0x1bbc;
    _DAT_004fb638 = 0x9999999a;
    _DAT_004fb63c = 0x3fd99999;
    _DAT_004fb000 = 0x5b53fa5f;
    _DAT_004fb004 = 0xc0086f58;
    _DAT_00522cdc = 0x11;
    local_b80 = 0x23;
    _DAT_004f4618 = 0;
    _DAT_004f461c = 0;
    _DAT_004f3f1c = 1;
    _DAT_0053533c = 0xc;
    _DAT_0053539c = 0x24;
  }
  if (param_1 == 0xc) {
    DAT_00535248 = 0x3aa7;
    _DAT_004f4b88 = 0x738;
    _DAT_00535010 = 0x1c84;
    _DAT_004fb640 = 0xcccccccd;
    _DAT_004fb644 = 0x3feccccc;
    _DAT_004fb008 = 0xbd05eb94;
    _DAT_004fb00c = 0xbff92211;
    _DAT_00522ce0 = 5;
    local_b80 = 0x1c;
    _DAT_004f4620 = 0;
    _DAT_004f4624 = 0;
    _DAT_004f3f20 = 1;
    _DAT_00535340 = 7;
    _DAT_005353a0 = 0x13;
  }
  if (param_1 == 0xd) {
    DAT_0053524c = 0xffffea20;
    _DAT_004f4b8c = 0xffffe3e0;
    _DAT_00535014 = 7000;
    _DAT_004fb648 = 0x8f5c28f6;
    _DAT_004fb64c = 0x3fe0f5c2;
    _DAT_004fb010 = 0x363e26bd;
    _DAT_004fb014 = 0x3fe6572c;
    _DAT_00522ce4 = 0x12;
    local_b80 = 0xffffffff;
    _DAT_004f4628 = 0;
    _DAT_004f462c = 0;
    _DAT_004f3f24 = 1;
    _DAT_00535344 = 0xffffffff;
    _DAT_005353a4 = 0xffffffff;
  }
  if (param_1 == 0xe) {
    DAT_00535250 = 0xfffff8c6;
    _DAT_004f4b90 = 0x2cec;
    _DAT_00535018 = 5000;
    _DAT_004fb650 = 0x9999999a;
    _DAT_004fb654 = 0x3fd99999;
    _DAT_004fb018 = 0xaf7661e5;
    _DAT_004fb01c = 0xbff38c46;
    _DAT_00522ce8 = 3;
    local_b80 = 0xffffffff;
    _DAT_004f4630 = 0;
    _DAT_004f4634 = 0;
    _DAT_004f3f28 = 1;
    _DAT_00535348 = 0xffffffff;
    _DAT_005353a8 = 0xffffffff;
  }
  if (param_1 == 0xf) {
    _DAT_00535254 = 0x26ac;
    _DAT_004f4b94 = 0x27d8;
    _DAT_0053501c = 10000;
    _DAT_004fb658 = 0x9999999a;
    _DAT_004fb65c = 0x3fd99999;
    _DAT_004fb020 = 0xaf7661e5;
    _DAT_004fb024 = 0x3ff38c46;
    _DAT_00522cec = 0x2d;
    local_b80 = 0xffffffff;
    _DAT_004f4638 = 0;
    _DAT_004f463c = 0;
    _DAT_004f3f2c = 1;
    _DAT_0053534c = 0xffffffff;
    _DAT_005353ac = 0xffffffff;
  }
  if (param_1 == 0x10) {
    _DAT_00535258 = 0xfffff06a;
    _DAT_004f4b98 = 0xfffffea6;
    _DAT_00535020 = 400;
    _DAT_004fb660 = 0;
    _DAT_004fb664 = 0x3fe00000;
    _DAT_004fb028 = 0x363e26bd;
    _DAT_004fb02c = 0x3fd6572c;
    _DAT_00522cf0 = 10;
    local_b80 = 0xffffffff;
    _DAT_004f4640 = 0;
    _DAT_004f4644 = 0;
    _DAT_004f3f30 = 0;
    _DAT_00535350 = 0xffffffff;
    _DAT_005353b0 = 0xffffffff;
  }
  if (param_1 == 0x11) {
    _DAT_0053525c = 0x3e5;
    _DAT_004f4b9c = 0xfffff3d2;
    _DAT_00535024 = 400;
    _DAT_004fb668 = 0x33333333;
    _DAT_004fb66c = 0x3fd33333;
    _DAT_004fb030 = 0x28ae9d0e;
    _DAT_004fb034 = 0x3fe0c161;
    _DAT_00522cf4 = 0x2a;
    local_b80 = 0xffffffff;
    _DAT_004f4648 = 0;
    _DAT_004f464c = 0;
    _DAT_004f3f34 = 0;
    _DAT_00535354 = 0xffffffff;
    _DAT_005353b4 = 0xffffffff;
  }
  fVar14 = (float10)fcos((float10)*(double *)(&DAT_004fafa8 + param_1 * 8));
  iVar11 = *(int *)(&DAT_00534fe0 + param_1 * 4);
  local_b70 = local_b48;
  uVar12 = 0;
  local_b7c = 0;
  iVar7 = param_1 * 0x124;
  fVar15 = (float10)fsin((float10)*(double *)(&DAT_004fafa8 + param_1 * 8));
  local_b6c = iVar7;
  do {
    iVar8 = iVar11 / 0x1e;
    if (*(double *)(&DAT_004fb5e0 + param_1 * 8) < _DAT_004cc4f8) {
      if ((local_b7c < 0x28) || (0x140 < local_b7c)) {
        iVar8 = iVar11 / 0x28;
      }
      if ((0x8c < local_b7c) && (local_b7c < 0xdc)) {
        iVar8 = iVar11 / 0x28;
      }
    }
    iVar11 = *(int *)(&DAT_00534fe0 + param_1 * 4);
    iVar8 = FUN_0041e000(iVar8);
    pdVar13 = (double *)(&local_488 + uVar12);
    dVar2 = (double)(iVar11 - iVar8);
    local_b78 = SUB84(dVar2,0);
    uStack_b74 = (undefined4)((ulonglong)dVar2 >> 0x20);
    *(undefined4 *)pdVar13 = local_b78;
    uVar4 = *(uint *)(&DAT_00522cb0 + param_1 * 4);
    *(undefined4 *)((int)&local_488 + uVar12 * 8 + 4) = uStack_b74;
    if (0 < (int)uVar4) {
      if (uVar12 == uVar4) {
        *pdVar13 = dVar2 * _DAT_004ccac8;
      }
      if (uVar12 == uVar4 + 1) {
        *pdVar13 = *pdVar13 * _DAT_004ccd68;
      }
      if (uVar12 == uVar4 + 2) {
        *pdVar13 = *pdVar13 * _DAT_004cc848;
      }
      if (uVar12 == uVar4 + 3) {
        *pdVar13 = *pdVar13 * _DAT_004cc6c0;
      }
      if (uVar12 == uVar4 + 4) {
        *pdVar13 = *pdVar13 * _DAT_004ccc70;
      }
      if (uVar12 == uVar4 + 5) {
        *pdVar13 = *pdVar13 * _DAT_004cc508;
      }
      if (uVar12 == uVar4 + 6) {
        *pdVar13 = *pdVar13 * _DAT_004ccc00;
      }
      if (uVar12 == uVar4 + 7) {
        *pdVar13 = *pdVar13 * _DAT_004ccbe0;
      }
      if (uVar12 == uVar4 + 8) {
        *pdVar13 = *pdVar13 * _DAT_004cc738;
      }
      if (uVar12 == uVar4 + 9) {
        *pdVar13 = *pdVar13 * _DAT_004cc738;
      }
      if (uVar12 == uVar4 + 10) {
        *pdVar13 = *pdVar13 * _DAT_004ccbe0;
      }
      if (uVar12 == uVar4 + 0xb) {
        *pdVar13 = *pdVar13 * _DAT_004ccc00;
      }
      if (uVar12 == uVar4 + 0xc) {
        *pdVar13 = *pdVar13 * _DAT_004cc508;
      }
      if (uVar12 == uVar4 + 0xd) {
        *pdVar13 = *pdVar13 * _DAT_004ccc70;
      }
      if (uVar12 == uVar4 + 0xe) {
        *pdVar13 = *pdVar13 * _DAT_004cc6c0;
      }
      if (uVar12 == uVar4 + 0xf) {
        *pdVar13 = *pdVar13 * _DAT_004cc848;
      }
      if (uVar12 == uVar4 + 0x10) {
        *pdVar13 = *pdVar13 * _DAT_004ccd68;
      }
      if (uVar12 == uVar4 + 0x11) {
        *pdVar13 = *pdVar13 * _DAT_004ccac8;
      }
    }
    if (0 < (int)local_b80) {
      if (uVar12 == local_b80 - 1) {
        *pdVar13 = *pdVar13 * _DAT_004ccd70;
      }
      if (uVar12 == local_b80) {
        *pdVar13 = *pdVar13 * _DAT_004cc630;
      }
      if (uVar12 == local_b80 + 1) {
        *pdVar13 = *pdVar13 * _DAT_004ccd70;
      }
    }
    fVar16 = (float10)fsin((float10)local_b7c * (float10)_DAT_004cc568);
    fVar17 = (float10)fcos((float10)local_b7c * (float10)_DAT_004cc568);
    dVar2 = (double)-(fVar17 * (float10)*pdVar13);
    dVar3 = (double)(fVar16 * (float10)*pdVar13 * (float10)*(double *)(&DAT_004fb5e0 + param_1 * 8))
    ;
    dVar5 = (double)fVar14 * dVar3 - (double)fVar15 * dVar2;
    dVar6 = (double)fVar14 * dVar2 + (double)fVar15 * dVar3;
    adStack_908[uVar12] = dVar3;
    *local_b70 = dVar2;
    adStack_6c8[uVar12] = dVar5;
    adStack_248[uVar12] = dVar6;
    *(int *)(&DAT_004f1cf8 + local_b6c) =
         (int)(longlong)dVar5 + *(int *)(&DAT_00535218 + param_1 * 4);
    local_b7c = local_b7c + 5;
    local_b70 = local_b70 + 1;
    uVar12 = uVar12 + 1;
    *(int *)(&DAT_004f8ee8 + local_b6c) =
         (int)(longlong)dVar6 + *(int *)(&DAT_004f4b58 + param_1 * 4);
    iVar8 = DAT_00522f08;
    local_b6c = local_b6c + 4;
  } while (local_b7c < 0x164);
  *(undefined4 *)(&DAT_004f1e18 + iVar7) = *(undefined4 *)(&DAT_004f1cf8 + iVar7);
  *(undefined4 *)(&DAT_004f9008 + iVar7) = *(undefined4 *)(&DAT_004f8ee8 + iVar7);
  iVar11 = DAT_004da1e8;
  if (0 < iVar8) {
    iVar7 = DAT_004da194 * 8;
    iVar9 = 0;
    pdVar13 = (double *)(iVar7 + 0x4fb0a8);
    pdVar10 = (double *)(iVar7 + 0x4f83d8);
    do {
      if (iVar11 == 0) {
        iVar1 = *(int *)((int)&DAT_004f4b5c + iVar9);
        *(double *)((int)&DAT_004f83c8 + iVar7) = (double)*(int *)((int)&DAT_0053521c + iVar9);
        *(double *)((int)&DAT_004fb098 + iVar7) = (double)iVar1;
      }
      if (iVar11 == 1) {
        iVar1 = *(int *)((int)&DAT_004f4b5c + iVar9);
        *pdVar10 = (double)*(int *)((int)&DAT_0053521c + iVar9);
        *pdVar13 = (double)iVar1;
      }
      iVar7 = iVar7 + 8;
      pdVar10 = pdVar10 + 1;
      pdVar13 = pdVar13 + 1;
      iVar9 = iVar9 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  return;
}

