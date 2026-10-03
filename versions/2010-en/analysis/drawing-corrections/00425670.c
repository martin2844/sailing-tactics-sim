
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00425670(int *param_1,double param_2,int param_3,int param_4,int param_5)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int local_88;
  undefined4 local_84;
  int local_80;
  int local_7c;
  undefined4 local_78;
  int local_74;
  int iStack_38;
  int aiStack_2c [2];
  double local_24;
  int local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  int local_8 [2];
  
  if (((((DAT_004da190 == 3) || (DAT_005363b8 == 1)) || (DAT_0053652c == 1)) || (DAT_00536530 == 1))
     && (param_5 != 1)) {
    FUN_0041f520(param_1,param_2,param_3,param_4,param_5);
  }
  iVar21 = 0;
  if (param_3 <= DAT_004da140) {
    if (10 < *(int *)(&DAT_00535f68 + param_3 * 4)) {
      iVar21 = FUN_0041e000(0xc);
      iVar21 = iVar21 + 6;
    }
    if (0x1e < *(int *)(&DAT_00535f68 + param_3 * 4)) {
      iVar21 = FUN_0041e000(0x18);
      iVar21 = iVar21 + 0x11;
    }
  }
  iVar8 = DAT_00522974;
  iVar7 = DAT_0052296c;
  uVar18 = DAT_00522968;
  iVar6 = DAT_00522964;
  iVar5 = DAT_00522960;
  iVar4 = DAT_0052295c;
  iVar3 = DAT_00522954;
  iVar2 = DAT_00522950;
  if (((DAT_004da150 == 100) || (DAT_004da190 == 8)) ||
     ((0 < DAT_005363c0 || ((DAT_005363c4 == 1 || (DAT_0053652c == 1)))))) {
    local_24 = param_2 * _DAT_004cc828;
    local_84 = DAT_00522934;
    if (DAT_004da190 == 8) {
      local_24 = local_24 * _DAT_004cc830;
    }
    iVar9 = (int)(longlong)(local_24 * _DAT_004cc6b0);
    local_88 = DAT_00522a34;
  }
  else {
    local_24 = param_2 * _DAT_004cc418;
    local_84 = DAT_00522930;
    iVar9 = (int)(longlong)(param_2 * _DAT_004cc8d8);
    local_88 = DAT_00522a30;
  }
  local_88 = local_88 - iVar9;
  if (DAT_00536528 == 1) {
    local_84 = DAT_00522930;
    local_24 = param_2 * _DAT_004cc828 * _DAT_004cc630;
    local_88 = DAT_00522a30 - (int)(longlong)(local_24 * _DAT_004cc620);
  }
  if (DAT_0053652c == 1) {
    local_84 = DAT_00522934;
    local_24 = param_2 * _DAT_004cc828 * _DAT_004cc468;
    local_88 = DAT_00522a34 - (int)(longlong)(local_24 * _DAT_004cc6b0);
  }
  if (DAT_00536530 == 1) {
    local_24 = local_24 * _DAT_004cc738;
    local_84 = DAT_00522930;
    local_88 = DAT_00522a30 - (int)(longlong)(local_24 * _DAT_004cc6b0);
  }
  if (DAT_005363b8 == 1) {
    local_24 = local_24 * _DAT_004cc468;
    local_88 = DAT_00522a30 - (int)(longlong)(local_24 * _DAT_004cc6b0);
  }
  else if (((DAT_005363c0 < 1) && (DAT_005363c4 != 1)) && (DAT_0053652c != 1)) {
    local_74 = DAT_0052294c;
    local_80 = DAT_00522a4c - (int)(longlong)(local_24 * _DAT_004cc570);
    goto LAB_00425911;
  }
  local_74 = DAT_00523af8;
  local_80 = DAT_00534d70;
LAB_00425911:
  if ((DAT_004da190 == 8) && (DAT_00522ad0 < 0xf)) {
    local_80 = DAT_00522a4c - (int)(longlong)(local_24 * _DAT_004cc530);
  }
  iVar19 = iVar21 / 2;
  iVar9 = (int)(longlong)(local_24 * _DAT_004cc660);
  iVar15 = (DAT_00522a50 - iVar9) + iVar19;
  iVar10 = (int)(longlong)(local_24 * _DAT_004cc4f8);
  iVar16 = (DAT_00522a54 + iVar21) - iVar10;
  local_c = DAT_00522958;
  iVar11 = (int)(longlong)(local_24 * _DAT_004cc738);
  iVar17 = iVar21 - iVar11;
  local_18 = DAT_00522a58 + iVar17;
  local_7c = (int)(longlong)(local_24 * _DAT_004cc570);
  iVar20 = (DAT_00522a5c - local_7c) + iVar19;
  iVar19 = (DAT_00522a60 - (int)(longlong)(local_24 * _DAT_004cc8c0)) + iVar19;
  iVar17 = DAT_00522a68 + iVar17;
  iVar21 = (iVar21 - (int)(longlong)(local_24 * _DAT_004cc7d0)) + DAT_00522a64;
  local_7c = DAT_00522a6c - local_7c;
  if (((0 < DAT_005363c0) || (DAT_005363c4 == 1)) || ((DAT_004da190 == 8 || (DAT_0053652c == 1)))) {
    if (0 < DAT_005363c0) {
      local_7c = DAT_00522a6c - (int)(longlong)(local_24 * _DAT_004cc6d8);
    }
    if ((DAT_005363c4 == 1) || (DAT_005363b8 == 1)) {
      local_7c = DAT_00522a6c - (int)(longlong)(local_24 * _DAT_004cc8e0);
    }
    if ((DAT_004da190 == 8) && (DAT_00522ad0 < 0xf)) {
      local_7c = DAT_00522a6c - (int)(longlong)(local_24 * _DAT_004cc6d8);
    }
    if (DAT_0053652c == 1) {
      local_7c = DAT_00522a6c - (int)(longlong)(local_24 * _DAT_004cc6d8);
    }
  }
  local_1c = DAT_00522970;
  iVar9 = DAT_00522a70 - iVar9;
  iVar10 = DAT_00522a74 - iVar10;
  iVar11 = DAT_00522a78 - iVar11;
  local_14 = DAT_00522978;
  iVar12 = (int)(longlong)(local_24 * _DAT_004cc888);
  if (param_5 == 0) {
    iVar12 = iVar12 / 2;
  }
  iVar13 = (DAT_00522954 + DAT_00522964) / 2;
  local_10 = (iVar21 + iVar16) / 2 - iVar12;
  iVar14 = (DAT_00522974 + DAT_00522964) / 2;
  iVar12 = (iVar10 + iVar21) / 2 - iVar12;
  if ((((DAT_005363b8 == 0) && (DAT_005363c0 == 0)) && (DAT_005363c4 == 0)) && (DAT_0053652c == 0))
  {
    if (DAT_00535884 < param_4) {
      if (DAT_004f7084 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f7084);
      }
    }
    else {
      (**(code **)(*param_1 + 0x2c))(param_1,7);
    }
    FUN_004b4d9d(param_1,local_8,DAT_00522924,
                 DAT_00522a24 - (int)(longlong)(param_2 * _DAT_004cc7e0));
    CDC::LineTo(param_1,local_74,local_80);
  }
  if ((DAT_004fe33c < param_4) && (param_3 == 1)) {
    pcVar1 = *(code **)(*param_1 + 0x2c);
    (*pcVar1)(param_1,6);
    if (DAT_00522ff4 == 1) {
      local_8[0] = DAT_00522904;
      iStack_38 = DAT_00522a04;
    }
    else {
      local_8[0] = DAT_00522914;
      iStack_38 = DAT_00522a14;
    }
    if (((param_5 == 1) && (DAT_005363c4 == 0)) && ((DAT_005363c0 == 0 && (DAT_0053652c == 0)))) {
      FUN_004b4d9d(param_1,aiStack_2c,local_8[0],iStack_38);
      CDC::LineTo(param_1,local_74,local_80);
    }
    DAT_004f41fc = DAT_0052291c;
    DAT_004fb40c = DAT_00522a1c;
    if (DAT_00522ff4 == -1) {
      DAT_004f41fc = DAT_005228fc;
      DAT_004fb40c = DAT_005229fc;
    }
    FUN_004b4d9d(param_1,aiStack_2c,DAT_004f41fc,DAT_004fb40c);
    CDC::LineTo(param_1,iVar7,local_7c);
    (*pcVar1)(param_1,7);
    (*pcVar1)(param_1,4);
    FUN_00433a70(param_1,2,DAT_004f41fc,DAT_004fb40c);
    FUN_00433a70(param_1,2,local_8[0],iStack_38);
  }
  FUN_00426890(param_1,param_3);
  pcVar1 = *(code **)(*param_1 + 0x2c);
  (*pcVar1)(param_1,7);
  _DAT_004f6e4c = local_88;
  if (param_5 == 1) {
    _DAT_004f6e28 = iVar4;
    _DAT_004f6e30 = iVar5;
    _DAT_004f6e40 = uVar18;
    _DAT_004f6e48 = local_84;
    _DAT_004f6e50 = local_14;
    _DAT_004f6e58 = iVar8;
    _DAT_004f6e60 = local_1c;
    _DAT_004f6e38 = iVar6;
    _DAT_004f6e68 = iVar7;
    _DAT_004f6e6c = local_7c;
    _DAT_004f6e2c = iVar20;
    _DAT_004f6e34 = iVar19;
    _DAT_004f6e3c = iVar21;
    _DAT_004f6e44 = iVar17;
    _DAT_004f6e54 = iVar11;
    _DAT_004f6e5c = iVar10;
    _DAT_004f6e64 = iVar9;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,9);
    if (DAT_004f7084 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7084);
    }
    FUN_004b4d9d(param_1,aiStack_2c,iVar8,iVar10);
    CDC::LineTo(param_1,iVar14,iVar12);
    CDC::LineTo(param_1,iVar6,iVar21);
    (*pcVar1)(param_1,7);
    _DAT_004f6e28 = local_74;
    _DAT_004f6e2c = local_80;
    _DAT_004f6e30 = iVar2;
    _DAT_004f6e38 = iVar3;
    _DAT_004f6e40 = local_c;
    _DAT_004f6e44 = local_18;
    _DAT_004f6e48 = local_84;
    _DAT_004f6e50 = uVar18;
    _DAT_004f6e58 = iVar6;
    _DAT_004f6e60 = iVar5;
    _DAT_004f6e68 = iVar4;
    _DAT_004f6e34 = iVar15;
    _DAT_004f6e3c = iVar16;
    _DAT_004f6e4c = local_88;
    _DAT_004f6e54 = iVar17;
    _DAT_004f6e5c = iVar21;
    _DAT_004f6e64 = iVar19;
    _DAT_004f6e6c = iVar20;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,9);
    if (((DAT_00536530 == 1) || (DAT_0053652c == 1)) &&
       (FUN_0041f520(param_1,param_2,param_3,param_4,1), DAT_00536530 == 1)) {
      if (DAT_00535884 < param_4) {
        if (DAT_004f7084 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004f7084);
        }
      }
      else {
        (*pcVar1)(param_1,7);
      }
      FUN_004b4d9d(param_1,aiStack_2c,DAT_00522924,
                   DAT_00522a24 - (int)(longlong)(param_2 * _DAT_004cc7e0));
      CDC::LineTo(param_1,local_74,local_80);
    }
    if (DAT_004f7084 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7084);
    }
    FUN_004b4d9d(param_1,aiStack_2c,iVar3,iVar16);
    CDC::LineTo(param_1,iVar13,local_10);
    CDC::LineTo(param_1,iVar6,iVar21);
    (*pcVar1)(param_1,7);
  }
  else {
    _DAT_004f6e2c = local_80;
    _DAT_004f6e28 = local_74;
    _DAT_004f6e30 = iVar2;
    _DAT_004f6e38 = iVar3;
    _DAT_004f6e44 = local_18;
    _DAT_004f6e40 = local_c;
    _DAT_004f6e48 = local_84;
    _DAT_004f6e50 = uVar18;
    _DAT_004f6e58 = iVar6;
    _DAT_004f6e60 = iVar5;
    _DAT_004f6e68 = iVar4;
    _DAT_004f6e34 = iVar15;
    _DAT_004f6e3c = iVar16;
    _DAT_004f6e54 = iVar17;
    _DAT_004f6e5c = iVar21;
    _DAT_004f6e64 = iVar19;
    _DAT_004f6e6c = iVar20;
    (*pcVar1)(param_1,7);
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,9);
    if (DAT_004f7084 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7084);
    }
    FUN_004b4d9d(param_1,aiStack_2c,iVar3,iVar16);
    CDC::LineTo(param_1,iVar13,local_10);
    CDC::LineTo(param_1,iVar6,iVar21);
    (*pcVar1)(param_1,7);
    _DAT_004f6e28 = iVar4;
    _DAT_004f6e30 = iVar5;
    _DAT_004f6e40 = uVar18;
    _DAT_004f6e48 = local_84;
    _DAT_004f6e50 = local_14;
    _DAT_004f6e58 = iVar8;
    _DAT_004f6e60 = local_1c;
    _DAT_004f6e38 = iVar6;
    _DAT_004f6e68 = iVar7;
    _DAT_004f6e6c = local_7c;
    _DAT_004f6e2c = iVar20;
    _DAT_004f6e34 = iVar19;
    _DAT_004f6e3c = iVar21;
    _DAT_004f6e44 = iVar17;
    _DAT_004f6e4c = local_88;
    _DAT_004f6e54 = iVar11;
    _DAT_004f6e5c = iVar10;
    _DAT_004f6e64 = iVar9;
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,9);
    if (DAT_004f7084 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f7084);
    }
    FUN_004b4d9d(param_1,aiStack_2c,iVar8,iVar10);
    CDC::LineTo(param_1,iVar14,iVar12);
    CDC::LineTo(param_1,iVar6,iVar21);
    (*pcVar1)(param_1,7);
  }
  if ((DAT_004da190 == 3) || (DAT_005363b8 == 1)) {
    if (param_5 == 1) {
      FUN_0041f520(param_1,param_2,param_3,param_4,1);
    }
    if (((DAT_004da190 == 3) && (DAT_005363c4 == 0)) && (param_5 == 1)) {
      if (DAT_00535884 < param_4) {
        if (DAT_004f7084 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004f7084);
        }
      }
      else {
        (*pcVar1)(param_1,7);
      }
      FUN_004b4d9d(param_1,aiStack_2c,DAT_00522924,
                   DAT_00522a24 - (int)(longlong)(param_2 * _DAT_004cc7e0));
      CDC::LineTo(param_1,local_74,local_80);
    }
  }
  if ((*(int *)(&DAT_004f42c0 + param_3 * 4) == 3) && (param_3 <= DAT_004da140)) {
    if (*(int *)(&DAT_00522ff0 + param_3 * 4) == -1) {
      local_78 = *(undefined4 *)(&DAT_004fbab0 + param_3 * 4);
    }
    else {
      local_78 = 0;
    }
    if ((*(int *)(&DAT_00522ff0 + param_3 * 4) == 1) && (0 < *(int *)(&DAT_00535f68 + param_3 * 4)))
    {
      local_78 = 1;
    }
    iVar2 = (iVar5 + (iVar2 + iVar3) * 3) / 7;
    iVar21 = (iVar19 + (iVar16 + iVar15) * 3) / 7;
    FUN_00426550(param_1,iVar2,iVar21,local_78,2,param_2,param_3);
    if (*(int *)(&DAT_00522ff0 + param_3 * 4) == 1) {
      uVar18 = *(undefined4 *)(&DAT_004fbab0 + param_3 * 4);
    }
    else {
      uVar18 = 0;
    }
    if ((*(int *)(&DAT_00522ff0 + param_3 * 4) == -1) && (0 < *(int *)(&DAT_00535f68 + param_3 * 4))
       ) {
      uVar18 = 1;
    }
    FUN_00426550(param_1,iVar2,iVar21 - (int)(longlong)(local_24 * _DAT_004cc8e8),uVar18,1,param_2,
                 param_3);
  }
  return;
}

