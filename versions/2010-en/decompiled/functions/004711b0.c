
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004711b0(int param_1)

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
    DAT_0053521c = 0x2f8;
    DAT_004f4b5c = 0xfffffad8;
    DAT_00534fe4 = 0x28;
    DAT_004fb5e8._0_4_ = 0x9999999a;
    DAT_004fb5e8._4_4_ = 0x3fe99999;
    DAT_004fafb0._0_4_ = 0;
    DAT_004fafb0._4_4_ = 0;
    DAT_00522cb4 = 0xffffffff;
    local_b80 = -1;
    DAT_004f45c8 = 0;
    DAT_004f45cc = 0x3ff00000;
    _DAT_004f3ef4 = 0;
    DAT_00535314 = 0xffffffff;
    DAT_00535374 = 0x48;
  }
  if (param_1 == 2) {
    DAT_00535220 = 0xfffff7b8;
    DAT_004f4b60 = 0xfffffe70;
    _DAT_00534fe8 = 0x50;
    _DAT_004fb5f0 = 0x9999999a;
    _DAT_004fb5f4 = 0x3fd99999;
    DAT_004fafb8._0_4_ = 0;
    DAT_004fafb8._4_4_ = 0;
    DAT_00522cb8 = 6;
    local_b80 = 0x18;
    DAT_004f45d0 = 0;
    DAT_004f45d4 = 0x3ff00000;
    _DAT_004f3ef8 = 0;
    DAT_00535318 = 0;
    DAT_00535378 = 0x48;
  }
  if (param_1 == 3) {
    _DAT_00535224 = 0xfffff718;
    _DAT_004f4b64 = 0xfffffba0;
    _DAT_00534fec = 400;
    _DAT_004fb5f8 = 0x66666666;
    _DAT_004fb5fc = 0x3fd66666;
    _DAT_004fafc0 = 0x28ae9d0e;
    _DAT_004fafc4 = 0x3fe0c161;
    _DAT_00522cbc = 5;
    local_b80 = 0x14;
    _DAT_004f3efc = 1;
    _DAT_0053531c = 0;
    _DAT_0053537c = 0x2a;
  }
  if (param_1 == 4) {
    _DAT_00535228 = 0xfffffb78;
    _DAT_004f4b68 = 0xfffff8f8;
    _DAT_00534ff0 = 0x96;
    _DAT_004fb600 = 0x33333333;
    _DAT_004fb604 = 0x3fd33333;
    _DAT_004fafc8 = 0xbd05eb94;
    _DAT_004fafcc = 0xbfe92211;
    _DAT_00522cc0 = 0x28;
    local_b80 = 0x28;
    _DAT_004f3f00 = 0;
    _DAT_00535320 = 0;
    _DAT_00535380 = 0x48;
  }
  if (param_1 == 5) {
    DAT_0053522c = 200;
    DAT_004f4b6c = 0xfffff510;
    _DAT_00534ff4 = 300;
    _DAT_004fb608 = 0x66666666;
    _DAT_004fb60c = 0x3fe66666;
    _DAT_004fafd0 = 0x97f017f3;
    _DAT_004fafd4 = 0xc00709e5;
    _DAT_00522cc4 = 9;
    local_b80 = 0x2d;
    _DAT_004f3f04 = 0;
    _DAT_00535324 = 0;
    _DAT_00535384 = 0x48;
  }
  if (param_1 == 6) {
    DAT_00535230 = 0xfffff290;
    DAT_004f4b70 = 0;
    DAT_00534ff8 = 100;
    _DAT_004fb610 = 0;
    _DAT_004fb614 = 0x3fe00000;
    _DAT_004fafd8 = 0;
    _DAT_004fafdc = 0;
    _DAT_00522cc8 = 0xf;
    local_b80 = -1;
    _DAT_004f45f0 = 0;
    _DAT_004f45f4 = 0x3ff00000;
    _DAT_004f3f08 = 0;
    _DAT_00535328 = 0;
    _DAT_00535388 = 0x48;
  }
  if (param_1 == 7) {
    DAT_00535234 = 0xfffff2b8;
    DAT_004f4b74 = 0xfffffad8;
    DAT_00534ffc = 0x578;
    _DAT_004fb618 = 0x9999999a;
    _DAT_004fb61c = 0x3fd99999;
    _DAT_004fafe0 = 0xaf7661e5;
    _DAT_004fafe4 = 0xc0038c46;
    _DAT_00522ccc = 0x1b;
    local_b80 = 0x30;
    _DAT_004f3f0c = 1;
    _DAT_0053532c = 0;
    _DAT_0053538c = 0x26;
  }
  if (param_1 == 8) {
    DAT_00535238 = 0xffffee80;
    _DAT_004f4b78 = 0xfffffdd0;
    DAT_00535000 = 0x578;
    _DAT_004fb620 = 0x9999999a;
    _DAT_004fb624 = 0x3fd99999;
    _DAT_004fafe8 = 0x363e26bd;
    _DAT_004fafec = 0x3fe6572c;
    _DAT_00522cd0 = 0x1b;
    local_b80 = 0x18;
    _DAT_004f3f10 = 1;
    _DAT_00535330 = 10;
    _DAT_00535390 = 0x2c;
  }
  if (param_1 == 9) {
    DAT_0053523c = 0xfffff4e8;
    _DAT_004f4b7c = 0xfffffc90;
    _DAT_00535004 = 400;
    _DAT_004fb628 = 0x9999999a;
    _DAT_004fb62c = 0x3fb99999;
    _DAT_004faff0 = 0xf9a20929;
    _DAT_004faff4 = 0x3ff7bc9e;
    _DAT_00522cd4 = 10;
    local_b80 = -1;
    _DAT_004f4608 = 0;
    _DAT_004f460c = 0x3ff00000;
    _DAT_004f3f14 = 0;
    _DAT_00535334 = 1;
    _DAT_00535394 = 0x48;
  }
  if (param_1 == 10) {
    DAT_00535240 = 0xffffe778;
    DAT_004f4b80 = 0x938;
    _DAT_00535008 = 600;
    _DAT_004fb630 = 0x66666666;
    _DAT_004fb634 = 0x3fd66666;
    _DAT_004faff8 = 0x43cdb06c;
    _DAT_004faffc = 0x3ffbecf7;
    _DAT_00522cd8 = 10;
    local_b80 = 4;
    _DAT_004f3f18 = 1;
    _DAT_00535338 = 1;
    _DAT_00535398 = 0x48;
  }
  if (param_1 == 0xb) {
    _DAT_00535244 = 0xffffe0c0;
    _DAT_004f4b84 = 0x4b0;
    _DAT_0053500c = 0x1194;
    _DAT_004fb638 = 0x9999999a;
    _DAT_004fb63c = 0x3fd99999;
    _DAT_004fb000 = 0x43cdb06c;
    _DAT_004fb004 = 0x3febecf7;
    _DAT_00522cdc = 10;
    local_b80 = -1;
    _DAT_004f3f1c = 2;
    _DAT_0053533c = 0xffffffff;
    _DAT_0053539c = 0xffffffff;
  }
  if (param_1 == 0xc) {
    DAT_00535248 = 0xffffe520;
    _DAT_004f4b88 = 0x780;
    _DAT_00535010 = 400;
    _DAT_004fb640 = 0x33333333;
    _DAT_004fb644 = 0x3fc33333;
    _DAT_004fb008 = 0x363e26bd;
    _DAT_004fb00c = 0xbfc6572c;
    _DAT_00522ce0 = 10;
    local_b80 = -1;
    _DAT_004f3f20 = 0;
    _DAT_004f4620 = 0;
    _DAT_004f4624 = 0x3ff00000;
    _DAT_00535340 = 0xffffffff;
    _DAT_005353a0 = 0xffffffff;
  }
  if (param_1 == 0xd) {
    _DAT_00522ce4 = 0xffffffff;
    DAT_0053524c = 0xffffec00;
    _DAT_004f4b8c = 0xfffff6a0;
    _DAT_00535014 = 2000;
    _DAT_004fb648 = 0x9999999a;
    _DAT_004fb64c = 0x3fd99999;
    _DAT_004fb010 = 0x363e26bd;
    _DAT_004fb014 = 0x3fc6572c;
    local_b80 = 0x14;
    _DAT_004f3f24 = 2;
    _DAT_00535344 = 0xffffffff;
    _DAT_005353a4 = 0xffffffff;
  }
  if (param_1 == 0xe) {
    DAT_00535250 = 0xffffef98;
    _DAT_004f4b90 = 0xfffff5b0;
    _DAT_00535018 = 700;
    _DAT_004fb650 = 0x9999999a;
    _DAT_004fb654 = 0x3fd99999;
    _DAT_004fb018 = 0x72da4451;
    _DAT_004fb01c = 0xc004f1b9;
    _DAT_00522ce8 = 10;
    local_b80 = 0x14;
    _DAT_004f3f28 = 2;
    _DAT_00535348 = 0xffffffff;
    _DAT_005353a8 = 0xffffffff;
  }
  if (param_1 == 0xf) {
    _DAT_00535254 = 0xfffff830;
    _DAT_004f4b94 = 0xffffee58;
    _DAT_0053501c = 0x9c4;
    _DAT_004fb658 = 0x9999999a;
    _DAT_004fb65c = 0x3fd99999;
    _DAT_004fb020 = 0x72da4451;
    _DAT_004fb024 = 0x3ff4f1b9;
    _DAT_00522cec = 10;
    local_b80 = 0x12;
    _DAT_004f3f2c = 1;
    _DAT_0053534c = 5;
    _DAT_005353ac = 0x14;
  }
  if (param_1 == 0x10) {
    _DAT_00535258 = 0xffffef70;
    _DAT_004f4b98 = 0xfffff150;
    _DAT_00535020 = 3000;
    _DAT_004fb660 = 0x33333333;
    _DAT_004fb664 = 0x3fd33333;
    _DAT_004fb028 = 0x28ae9d0e;
    _DAT_004fb02c = 0x3fe0c161;
    _DAT_00522cf0 = 10;
    local_b80 = 0xf;
    _DAT_004f3f30 = 2;
    _DAT_00535350 = 0xc;
    _DAT_005353b0 = 0x14;
  }
  if (param_1 == 0x11) {
    _DAT_0053525c = 0x5f0;
    _DAT_004f4b9c = 0xffffec00;
    _DAT_00535024 = 0x514;
    _DAT_004fb668 = 0x33333333;
    _DAT_004fb66c = 0x3fd33333;
    _DAT_004fb030 = 0x363e26bd;
    _DAT_004fb034 = 0x3fe6572c;
    _DAT_00522cf4 = 0x14;
    local_b80 = 0x23;
    _DAT_004f3f34 = 1;
    _DAT_00535354 = 0xc;
    _DAT_005353b4 = 0x24;
  }
  if (param_1 == 0x12) {
    _DAT_00535028 = 2000;
    _DAT_00535260 = 0x4b0;
    _DAT_004f4ba0 = 0xffffea48;
    _DAT_004fb670 = 0x9999999a;
    _DAT_004fb674 = 0x3fd99999;
    _DAT_004fb038 = 0x43cdb06c;
    _DAT_004fb03c = 0x3febecf7;
    _DAT_00522cf8 = 0x14;
    local_b80 = 0x23;
    _DAT_004f3f38 = 1;
    _DAT_00535358 = 0x14;
    _DAT_005353b8 = 0x20;
  }
  if (param_1 == 0x13) {
    _DAT_00535264 = 4000;
    _DAT_004f4ba4 = 0xffffe570;
    _DAT_0053502c = 5000;
    _DAT_004fb678 = 0x9999999a;
    _DAT_004fb67c = 0x3fd99999;
    _DAT_004fb040 = 0x72da4451;
    _DAT_004fb044 = 0x3ff4f1b9;
    _DAT_00522cfc = 10;
    local_b80 = 0x23;
    _DAT_004f3f3c = 1;
    _DAT_0053535c = 0x14;
    _DAT_005353bc = 0x20;
  }
  if (param_1 == 0x14) {
    _DAT_00535268 = 0xffffe2b4;
    _DAT_004f4ba8 = 0xffffeffc;
    _DAT_00535030 = 0x21fc;
    _DAT_004fb680 = 0x33333333;
    _DAT_004fb684 = 0x3fe33333;
    _DAT_004fb048 = 0x43cdb06c;
    _DAT_004fb04c = 0x3febecf7;
    _DAT_00522d00 = 10;
    local_b80 = -1;
    _DAT_004f3f40 = 1;
    _DAT_00535360 = 0xffffffff;
    _DAT_005353c0 = 0xffffffff;
  }
  if (param_1 == 0x15) {
    _DAT_0053526c = 0xffffc568;
    _DAT_004f4bac = 0x157c;
    _DAT_00535034 = 7000;
    _DAT_004fb688 = 0x33333333;
    _DAT_004fb68c = 0x3fe33333;
    _DAT_004fb050 = 0x363e26bd;
    _DAT_004fb054 = 0x3fe6572c;
    _DAT_00522d04 = 10;
    local_b80 = -1;
    _DAT_004f3f44 = 1;
    _DAT_00535364 = 0xffffffff;
    _DAT_005353c4 = 0xffffffff;
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
    dVar3 = (double)(fVar14 * (float10)*(double *)(&DAT_004fb5e0 + param_1 * 8) * (float10)*pdVar11)
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

