
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004676f0(int param_1)

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
  if (param_1 == 0x15) {
    _DAT_0053526c = 0xffffcff7;
    _DAT_004f4bac = 0xfffffc5b;
    _DAT_00535034 = 0x20d0;
    _DAT_004fb688 = 0x9999999a;
    _DAT_004fb68c = 0x3fd99999;
    _DAT_004fb050 = 0x4dc470af;
    _DAT_004fb054 = 0x4002d98d;
    _DAT_00522d04 = 6;
    local_b80 = -1;
    _DAT_004f3f44 = 1;
    _DAT_00535364 = 0;
    _DAT_005353c4 = 0x26;
  }
  if (param_1 == 10) {
    DAT_00535240 = 0xffffcaf3;
    DAT_004f4b80 = 0xffffe592;
    _DAT_00535008 = 0x20d0;
    _DAT_004fb630 = 0;
    _DAT_004fb634 = 0x3fe00000;
    _DAT_004faff8 = 0xf9a20929;
    _DAT_004faffc = 0x4007bc9e;
    _DAT_00522cd8 = 0x16;
    local_b80 = -1;
    _DAT_004f3f18 = 0;
    _DAT_00535338 = 0x15;
    _DAT_00535398 = 0x32;
  }
  if (param_1 == 0x10) {
    _DAT_00535258 = 0x28d;
    _DAT_004f4b98 = 0xffffc951;
    _DAT_00535020 = 0x20d0;
    _DAT_004fb660 = 0;
    _DAT_004fb664 = 0x3fe00000;
    _DAT_004fb028 = 0xf9a20929;
    _DAT_004fb02c = 0xc007bc9e;
    _DAT_00522cf0 = 0xf;
    local_b80 = -1;
    _DAT_004f3f30 = 0;
    _DAT_00535350 = 0x1a;
    _DAT_005353b0 = 0x3e;
  }
  if (param_1 == 0x13) {
    _DAT_00535264 = 0x20a1;
    _DAT_004f4ba4 = 0xffffcddf;
    _DAT_0053502c = 0x20d0;
    _DAT_004fb678 = 0;
    _DAT_004fb67c = 0x3fe00000;
    _DAT_004fb040 = 0x363e26bd;
    _DAT_004fb044 = 0xbfe6572c;
    _DAT_00522cfc = 0xf;
    local_b80 = -1;
    _DAT_004f3f3c = 0;
    _DAT_0053535c = 4;
    _DAT_005353bc = 0x34;
  }
  if (param_1 == 0x14) {
    _DAT_00535268 = 0x2b91;
    _DAT_004f4ba8 = 0xffffc3aa;
    _DAT_00535030 = 0x348;
    _DAT_004fb680 = 0;
    _DAT_004fb684 = 0x40000000;
    _DAT_004fb048 = 0xec127f79;
    _DAT_004fb04c = 0xc00226d3;
    _DAT_00522d00 = 0xe;
    local_b80 = -1;
    _DAT_004f3f40 = 2;
    _DAT_00535360 = 0x12;
    _DAT_005353c0 = 0x41;
  }
  if (param_1 == 0x11) {
    _DAT_0053525c = 0x120b;
    _DAT_004f4b9c = 0xffffe765;
    _DAT_00535024 = 0x15e0;
    _DAT_004fb668 = 0x66666666;
    _DAT_004fb66c = 0x3fe66666;
    _DAT_004fb030 = 0;
    _DAT_004fb034 = 0;
    _DAT_00522cf4 = 0x19;
    local_b80 = -1;
    _DAT_004f3f34 = 1;
    _DAT_00535354 = param_1;
    _DAT_005353b4 = 0x35;
  }
  if (param_1 == 0x12) {
    _DAT_00535260 = 0xffffe562;
    _DAT_004f4ba0 = 0xffffbba5;
    _DAT_00535028 = 0x189c;
    _DAT_004fb670 = 0xcccccccd;
    _DAT_004fb674 = 0x3ff4cccc;
    _DAT_004fb038 = 0x363e26bd;
    _DAT_004fb03c = 0x4006572c;
    _DAT_00522cf8 = 0x28;
    local_b80 = -1;
    _DAT_004f3f38 = 1;
    _DAT_00535358 = 0x12;
    _DAT_005353b8 = 0x35;
  }
  if (param_1 == 9) {
    _DAT_00535004 = 0x189c;
    DAT_0053523c = 0xffffe278;
    _DAT_004f4b7c = 0xffffec18;
    _DAT_004fb628 = 0x9999999a;
    _DAT_004fb62c = 0x3fd99999;
    _DAT_004faff0 = 0x363e26bd;
    _DAT_004faff4 = 0xbfc6572c;
    _DAT_00522cd4 = 0x17;
    local_b80 = -1;
    _DAT_004f3f14 = 1;
    _DAT_00535334 = 7;
    _DAT_00535394 = 0x21;
  }
  if (param_1 == 6) {
    DAT_00535230 = 0xffffebf2;
    DAT_004f4b70 = 0xfffff787;
    DAT_00534ff8 = 0x348;
    _DAT_004fb610 = 0x9999999a;
    _DAT_004fb614 = 0x3fd99999;
    _DAT_004fafd8 = 0x43cdb06c;
    _DAT_004fafdc = 0xbfebecf7;
    _DAT_00522cc8 = 0x2a;
    local_b80 = -1;
    _DAT_004f3f08 = 3;
    _DAT_00535328 = 0xf;
    _DAT_00535388 = 0x38;
  }
  if (param_1 == 8) {
    DAT_00535238 = 0xffffebc3;
    _DAT_004f4b78 = 0xa7c;
    DAT_00535000 = 0xdac;
    _DAT_004fb620 = 0;
    _DAT_004fb624 = 0x3ff00000;
    _DAT_004fafe8 = 0x28ae9d0e;
    _DAT_004fafec = 0xbff0c161;
    _DAT_00522cd0 = 5;
    local_b80 = -1;
    _DAT_004f3f10 = 1;
    _DAT_00535330 = 7;
    _DAT_00535390 = 0x36;
  }
  if (param_1 == 0xf) {
    _DAT_00535254 = 0xfffff430;
    _DAT_004f4b94 = 0xffffdf84;
    _DAT_0053501c = &DAT_00001324;
    _DAT_004fb658 = 0x9999999a;
    _DAT_004fb65c = 0x3fc99999;
    _DAT_004fb020 = 0x363e26bd;
    _DAT_004fb024 = 0xbfd6572c;
    _DAT_00522cec = 0x2c;
    local_b80 = -1;
    _DAT_004f3f2c = 1;
    _DAT_0053534c = 0x2f;
    _DAT_005353ac = 0x3e;
  }
  if (param_1 == 5) {
    DAT_0053522c = 0xffffface;
    DAT_004f4b6c = 0xfffff082;
    _DAT_00534ff4 = 0x834;
    _DAT_004fb608 = 0x9999999a;
    _DAT_004fb60c = 0x3fd99999;
    _DAT_004fafd0 = 0x363e26bd;
    _DAT_004fafd4 = 0xbfe6572c;
    _DAT_00522cc4 = 0xf;
    local_b80 = -1;
    _DAT_004f3f04 = 3;
    _DAT_00535324 = 0x10;
    _DAT_00535384 = 0x46;
  }
  if (param_1 == 7) {
    DAT_00535234 = 0xffffec6c;
    DAT_004f4b74 = 0xffffed3e;
    DAT_00534ffc = 0x348;
    _DAT_004fb618 = 0;
    _DAT_004fb61c = 0x3ff00000;
    _DAT_004fafe0 = 0x363e26bd;
    _DAT_004fafe4 = 0xbff6572c;
    _DAT_00522ccc = 8;
    local_b80 = -1;
    _DAT_004f3f0c = 0;
    _DAT_0053532c = 0x10;
    _DAT_0053538c = 0x34;
  }
  if (param_1 == 4) {
    _DAT_00535228 = 0xfffff4a0;
    _DAT_004f4b68 = 0xfffff8e4;
    _DAT_00534ff0 = 700;
    _DAT_004fb600 = 0x9999999a;
    _DAT_004fb604 = 0x3fd99999;
    _DAT_004fafc8 = 0x28ae9d0e;
    _DAT_004fafcc = 0xbff0c161;
    _DAT_00522cc0 = 0x26;
    local_b80 = 0x24;
    _DAT_004f3f00 = 0;
    _DAT_00535320 = 0;
    _DAT_00535380 = 0x48;
  }
  if (param_1 == 0xe) {
    DAT_00535250 = 0xffffeb54;
    _DAT_004f4b90 = 0xffffd558;
    _DAT_00535018 = 0x578;
    _DAT_004fb650 = 0x33333333;
    _DAT_004fb654 = 0x3fd33333;
    _DAT_004fb018 = 0x363e26bd;
    _DAT_004fb01c = 0xbfc6572c;
    _DAT_00522ce8 = 0x26;
    local_b80 = 0x24;
    _DAT_004f3f28 = 0;
    _DAT_00535348 = 0x14;
    _DAT_005353a8 = 0x34;
  }
  if (param_1 == 0xd) {
    DAT_0053524c = 0xffffeb7e;
    _DAT_004f4b8c = 0xffffdd00;
    _DAT_00535014 = 0x118;
    _DAT_004fb648 = 0x9999999a;
    _DAT_004fb64c = 0x3fe99999;
    _DAT_004fb010 = 0x363e26bd;
    _DAT_004fb014 = 0xbfc6572c;
    _DAT_00522ce4 = 0x26;
    local_b80 = 0x24;
    _DAT_004f3f24 = 0;
    _DAT_00535344 = 0;
    _DAT_005353a4 = 0x48;
  }
  if (param_1 == 3) {
    _DAT_00535224 = 0xd7d;
    _DAT_004f4b64 = 0x18d;
    _DAT_00534fec = 700;
    _DAT_004fb5f8 = 0x33333333;
    _DAT_004fb5fc = 0x3fd33333;
    _DAT_004fafc0 = 0x8069ce00;
    _DAT_004fafc4 = 0x3ffa8784;
    _DAT_00522cbc = 0x2a;
    local_b80 = 0x1b;
    _DAT_004f3efc = 0;
    _DAT_0053531c = 0;
    _DAT_0053537c = 0x48;
  }
  if (param_1 == 2) {
    DAT_00535220 = 0x8ee;
    DAT_004f4b60 = 0xc95;
    _DAT_00534fe8 = 0x834;
    _DAT_004fb5f0 = 0;
    _DAT_004fb5f4 = 0x3fe00000;
    DAT_004fafb8._0_4_ = 0x363e26bd;
    DAT_004fafb8._4_4_ = 0xbfb6572c;
    DAT_00522cb8 = 6;
    local_b80 = 0x41;
    _DAT_004f3ef8 = 1;
    DAT_00535318 = 0;
    DAT_00535378 = 0x48;
  }
  if (param_1 == 0xc) {
    DAT_00535248 = 0x1cfb;
    _DAT_004f4b88 = 0x7a9;
    _DAT_00535010 = 0x7a8;
    _DAT_004fb640 = 0x66666666;
    _DAT_004fb644 = 0x3fe66666;
    _DAT_004fb008 = 0x8069ce00;
    _DAT_004fb00c = 0x3ffa8784;
    _DAT_00522ce0 = 0x1c;
    local_b80 = 0x1b;
    _DAT_004f3f20 = 3;
    _DAT_00535340 = 0;
    _DAT_005353a0 = 0x48;
  }
  if (param_1 == 0xb) {
    _DAT_00535244 = 0xf50;
    _DAT_004f4b84 = 0xbd0;
    _DAT_0053500c = 0x460;
    _DAT_004fb638 = 0;
    _DAT_004fb63c = 0x3fd00000;
    _DAT_004fb000 = 0xaf7661e5;
    _DAT_004fb004 = 0xbfe38c46;
    _DAT_00522cdc = 6;
    local_b80 = 0x28;
    _DAT_004f3f1c = 0;
    _DAT_0053533c = 0;
    _DAT_0053539c = 0x48;
  }
  if (param_1 == 1) {
    DAT_0053521c = 0x968;
    DAT_004f4b5c = 0xfffffb76;
    DAT_00534fe4 = 0x118;
    DAT_004fb5e8._0_4_ = 0;
    DAT_004fb5e8._4_4_ = 0x3fe00000;
    DAT_004fafb0._0_4_ = 0x72da4451;
    DAT_004fafb0._4_4_ = 0x3ff4f1b9;
    DAT_00522cb4 = 0x2a;
    local_b80 = 0x19;
    _DAT_004f3ef4 = 0;
    DAT_00535314 = 0;
    DAT_00535374 = 0x48;
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
    dVar3 = (double)(fVar14 * (float10)*(double *)(&DAT_004fb5e0 + param_1 * 8) * (float10)*pdVar10)
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

