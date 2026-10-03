
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004729d0(int param_1)

{
  double *pdVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
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
  if (param_1 == 4) {
    _DAT_00535228 = 0x2401;
    _DAT_004f4b68 = 0xf57;
    _DAT_00534ff0 = 0x1068;
    _DAT_004fb600 = 0;
    _DAT_004fb604 = 0x3fe00000;
    _DAT_004fafc8 = 0x363e26bd;
    _DAT_004fafcc = 0x3ff6572c;
    _DAT_00522cc0 = 0x2d;
    local_b80 = 0x1a;
    _DAT_004f3f00 = 1;
    _DAT_00535320 = param_1;
    _DAT_00535380 = 0x2c;
  }
  if (param_1 == 3) {
    _DAT_00535224 = 0x2c4c;
    _DAT_004f4b64 = 0xfffffbe6;
    _DAT_00534fec = 0x1482;
    _DAT_004fb5f8 = 0x9999999a;
    _DAT_004fb5fc = 0x3fc99999;
    _DAT_004fafc0 = 0x28ae9d0e;
    _DAT_004fafc4 = 0xbfd0c161;
    _DAT_00522cbc = 0x3c;
    local_b80 = 1;
    _DAT_004f3efc = 1;
    _DAT_0053531c = 0;
    _DAT_0053537c = 0x48;
  }
  if (param_1 == 2) {
    DAT_00535220 = 0x22ba;
    DAT_004f4b60 = 0xfffff510;
    _DAT_00534fe8 = 0xaf0;
    _DAT_004fb5f0 = 0x9999999a;
    _DAT_004fb5f4 = 0x3fd99999;
    DAT_004fafb8._0_4_ = 0xbd05eb94;
    DAT_004fafb8._4_4_ = 0x3fe92211;
    DAT_00522cb8 = 0x14;
    local_b80 = 0x24;
    _DAT_004f3ef8 = 1;
    DAT_00535318 = 0x12;
    DAT_00535378 = 0x42;
  }
  if (param_1 == 1) {
    DAT_0053521c = 0x17ed;
    DAT_004f4b5c = 0xa09;
    DAT_00534fe4 = 0x834;
    DAT_004fb5e8._0_4_ = 0x9999999a;
    DAT_004fb5e8._4_4_ = 0x3fd99999;
    DAT_004fafb0._0_4_ = 0x97f017f3;
    DAT_004fafb0._4_4_ = 0xc00709e5;
    DAT_00522cb4 = 0x26;
    local_b80 = 0x21;
    _DAT_004f3ef4 = 1;
    DAT_00535314 = 10;
    DAT_00535374 = 0x35;
  }
  if (param_1 == 5) {
    DAT_0053522c = 0x1810;
    _DAT_004f45e8 = 0;
    _DAT_004f45ec = 0x3ff00000;
    DAT_004f4b6c = 0x46;
    _DAT_00534ff4 = 400;
    _DAT_004fb608 = 0x9999999a;
    _DAT_004fb60c = 0x3fa99999;
    _DAT_004fafd0 = 0x363e26bd;
    _DAT_004fafd4 = 0xbfe6572c;
    _DAT_00522cc4 = 0x26;
    local_b80 = 0x21;
    _DAT_004f3f04 = 0;
    _DAT_00535324 = 0;
    _DAT_00535384 = 0x48;
  }
  if (param_1 == 6) {
    DAT_00535230 = 0x3138;
    DAT_004f4b70 = 0x82a;
    DAT_00534ff8 = 0x708;
    _DAT_004fb610 = 0x9999999a;
    _DAT_004fb614 = 0x3fe99999;
    _DAT_004fafd8 = 0x28ae9d0e;
    _DAT_004fafdc = 0xbfe0c161;
    _DAT_00522cc8 = param_1;
    local_b80 = 0xc;
    _DAT_004f3f08 = 1;
    _DAT_00535328 = 10;
    _DAT_00535388 = 0x28;
  }
  if (param_1 == 7) {
    _DAT_00522ccc = 0x26;
    DAT_00535234 = 0x35ac;
    _DAT_004f45f8 = 0;
    _DAT_004f45fc = 0x3ff00000;
    DAT_004f4b74 = 1000;
    DAT_00534ffc = 400;
    _DAT_004fb618 = 0x9999999a;
    _DAT_004fb61c = 0x3fa99999;
    _DAT_004fafe0 = 0x363e26bd;
    _DAT_004fafe4 = 0x3fc6572c;
    local_b80 = 0x21;
    _DAT_004f3f0c = 0;
    _DAT_0053532c = 0;
    _DAT_0053538c = 0x48;
  }
  if (param_1 == 8) {
    DAT_00535238 = 0x27d8;
    _DAT_004f4b78 = 0xffffe37c;
    DAT_00535000 = 0x44c;
    _DAT_004fb620 = 0x33333333;
    _DAT_004fb624 = 0x3fc33333;
    _DAT_004fafe8 = 0x7f23cfd5;
    _DAT_004fafec = 0x3fbf46d7;
    _DAT_00522cd0 = 7;
    local_b80 = 1;
    _DAT_004f3f10 = 0;
  }
  if (param_1 == 9) {
    DAT_0053523c = 0x1fa4;
    _DAT_004f4b7c = 0x170c;
    _DAT_00535004 = 4000;
    _DAT_004fb628 = 0x33333333;
    _DAT_004fb62c = 0x3fd33333;
    _DAT_004faff0 = 0xaf7661e5;
    _DAT_004faff4 = 0x3ff38c46;
    _DAT_00522cd4 = 0xffffffff;
    local_b80 = -1;
    _DAT_004f3f14 = 0;
  }
  iVar9 = 0;
  if (param_1 == 10) {
    DAT_00535240 = 0x3057;
    DAT_004f4b80 = 0xfffff86f;
    _DAT_00535008 = 5000;
    _DAT_004fb630 = 0;
    _DAT_004fb634 = 0x3fd00000;
    _DAT_004faff8 = 0x363e26bd;
    _DAT_004faffc = 0xbfd6572c;
    _DAT_00522cd8 = 0xffffffff;
    local_b80 = -1;
    _DAT_004f3f18 = 0;
  }
  if (param_1 == 0xb) {
    _DAT_00535244 = 0x2904;
    _DAT_004f4b84 = 0x12c0;
    _DAT_0053500c = 4000;
    _DAT_004fb638 = 0x9999999a;
    _DAT_004fb63c = 0x3fd99999;
    _DAT_004fb000 = 0xec127f79;
    _DAT_004fb004 = 0x3ff226d3;
    _DAT_00522cdc = 0xffffffff;
    local_b80 = -1;
    _DAT_004f3f1c = 0;
  }
  if (param_1 == 0xc) {
    DAT_00535248 = 0x37dc;
    _DAT_004f4b88 = 0xa5a;
    _DAT_00535010 = 1000;
    _DAT_004fb640 = 0xae147ae1;
    _DAT_004fb644 = 0x3fcae147;
    _DAT_004fb008 = 0x91cb5231;
    _DAT_004fb00c = 0x3fc1df56;
    _DAT_00522ce0 = 0xffffffff;
    local_b80 = -1;
    _DAT_004f3f20 = 0;
  }
  if (param_1 == 0xd) {
    DAT_0053524c = 0x1130;
    _DAT_004f4b8c = 0x16a8;
    _DAT_00535014 = 0x5dc;
    _DAT_004fb648 = 0x9999999a;
    _DAT_004fb64c = 0x3fd99999;
    _DAT_004fb010 = 0xaf7661e5;
    _DAT_004fb014 = 0x3fe38c46;
    _DAT_00522ce4 = 0xffffffff;
    local_b80 = -1;
    _DAT_004f3f24 = 0;
  }
  fVar10 = (float10)fcos((float10)*(double *)(&DAT_004fafa8 + param_1 * 8));
  iVar8 = *(int *)(&DAT_00534fe0 + param_1 * 4);
  local_b70 = local_b48;
  local_b7c = 0;
  iVar6 = param_1 * 0x124;
  fVar11 = (float10)fsin((float10)*(double *)(&DAT_004fafa8 + param_1 * 8));
  local_b6c = iVar6;
  do {
    iVar7 = iVar8 / 0x1e;
    if (*(double *)(&DAT_004fb5e0 + param_1 * 8) < _DAT_004cc4f8) {
      if ((local_b7c < 0x28) || (0x140 < local_b7c)) {
        iVar7 = iVar8 / 0x28;
      }
      if ((0x8c < local_b7c) && (local_b7c < 0xdc)) {
        iVar7 = iVar8 / 0x28;
      }
    }
    iVar8 = *(int *)(&DAT_00534fe0 + param_1 * 4);
    iVar7 = FUN_0041e000(iVar7);
    pdVar1 = (double *)(&local_488 + iVar9);
    dVar2 = (double)(iVar8 - iVar7);
    local_b78 = SUB84(dVar2,0);
    uStack_b74 = (undefined4)((ulonglong)dVar2 >> 0x20);
    *(undefined4 *)pdVar1 = local_b78;
    iVar7 = *(int *)(&DAT_00522cb0 + param_1 * 4);
    *(undefined4 *)((int)&local_488 + iVar9 * 8 + 4) = uStack_b74;
    if (0 < iVar7) {
      if (iVar9 == iVar7) {
        *pdVar1 = dVar2 * _DAT_004ccac8;
      }
      if (iVar9 == iVar7 + 1) {
        *pdVar1 = *pdVar1 * _DAT_004ccd68;
      }
      if (iVar9 == iVar7 + 2) {
        *pdVar1 = *pdVar1 * _DAT_004cc848;
      }
      if (iVar9 == iVar7 + 3) {
        *pdVar1 = *pdVar1 * _DAT_004cc6c0;
      }
      if (iVar9 == iVar7 + 4) {
        *pdVar1 = *pdVar1 * _DAT_004ccc70;
      }
      if (iVar9 == iVar7 + 5) {
        *pdVar1 = *pdVar1 * _DAT_004cc508;
      }
      if (iVar9 == iVar7 + 6) {
        *pdVar1 = *pdVar1 * _DAT_004ccc00;
      }
      if (iVar9 == iVar7 + 7) {
        *pdVar1 = *pdVar1 * _DAT_004ccbe0;
      }
      if (iVar9 == iVar7 + 8) {
        *pdVar1 = *pdVar1 * _DAT_004cc738;
      }
      if (iVar9 == iVar7 + 9) {
        *pdVar1 = *pdVar1 * _DAT_004cc738;
      }
      if (iVar9 == iVar7 + 10) {
        *pdVar1 = *pdVar1 * _DAT_004ccbe0;
      }
      if (iVar9 == iVar7 + 0xb) {
        *pdVar1 = *pdVar1 * _DAT_004ccc00;
      }
      if (iVar9 == iVar7 + 0xc) {
        *pdVar1 = *pdVar1 * _DAT_004cc508;
      }
      if (iVar9 == iVar7 + 0xd) {
        *pdVar1 = *pdVar1 * _DAT_004ccc70;
      }
      if (iVar9 == iVar7 + 0xe) {
        *pdVar1 = *pdVar1 * _DAT_004cc6c0;
      }
      if (iVar9 == iVar7 + 0xf) {
        *pdVar1 = *pdVar1 * _DAT_004cc848;
      }
      if (iVar9 == iVar7 + 0x10) {
        *pdVar1 = *pdVar1 * _DAT_004ccd68;
      }
      if (iVar9 == iVar7 + 0x11) {
        *pdVar1 = *pdVar1 * _DAT_004ccac8;
      }
    }
    if (0 < local_b80) {
      if (iVar9 == local_b80 + -1) {
        *pdVar1 = *pdVar1 * _DAT_004ccd70;
      }
      if (iVar9 == local_b80) {
        *pdVar1 = *pdVar1 * _DAT_004cc630;
      }
      if (iVar9 == local_b80 + 1) {
        *pdVar1 = *pdVar1 * _DAT_004ccd70;
      }
    }
    fVar12 = (float10)fsin((float10)local_b7c * (float10)_DAT_004cc568);
    fVar13 = (float10)fcos((float10)local_b7c * (float10)_DAT_004cc568);
    dVar2 = (double)-(fVar13 * (float10)*pdVar1);
    dVar3 = (double)(fVar12 * (float10)*(double *)(&DAT_004fb5e0 + param_1 * 8) * (float10)*pdVar1);
    dVar4 = (double)fVar10 * dVar3 - (double)fVar11 * dVar2;
    dVar5 = (double)fVar10 * dVar2 + (double)fVar11 * dVar3;
    adStack_908[iVar9] = dVar3;
    *local_b70 = dVar2;
    adStack_6c8[iVar9] = dVar4;
    adStack_248[iVar9] = dVar5;
    *(int *)(&DAT_004f1cf8 + local_b6c) =
         (int)(longlong)dVar4 + *(int *)(&DAT_00535218 + param_1 * 4);
    local_b7c = local_b7c + 5;
    local_b70 = local_b70 + 1;
    iVar9 = iVar9 + 1;
    *(int *)(&DAT_004f8ee8 + local_b6c) =
         (int)(longlong)dVar5 + *(int *)(&DAT_004f4b58 + param_1 * 4);
    local_b6c = local_b6c + 4;
  } while (local_b7c < 0x164);
  *(undefined4 *)(&DAT_004f1e18 + iVar6) = *(undefined4 *)(&DAT_004f1cf8 + iVar6);
  *(undefined4 *)(&DAT_004f9008 + iVar6) = *(undefined4 *)(&DAT_004f8ee8 + iVar6);
  return;
}

