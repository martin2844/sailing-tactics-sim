
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_004225b0(int *param_1,int param_2,int param_3,double param_4,int param_5,int param_6,int param_7
            )

{
  int iVar1;
  int *original_dc;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  HDC pHVar9;
  HGDIOBJ pvVar10;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8 [2];
  
  original_dc = param_1;
  pcVar7 = SelectObject_exref;
  if (DAT_00513478 == 1) {
    return;
  }
  if ((DAT_004fb410 == 1) && (param_2 == 3)) {
    return;
  }
  if (DAT_004da194 < param_3) {
    return;
  }
  if (param_5 <= DAT_00535884) {
    return;
  }
  if (DAT_004da190 == 8) {
    return;
  }
  if (DAT_005364c8 == 1) {
    return;
  }
  if ((DAT_004da140 < param_3) && (DAT_005363e0 == 1)) {
    return;
  }
  if ((DAT_005364cc == 1) && (1 < param_2)) {
    return;
  }
  iVar8 = 0x27;
  if (param_2 != 1) {
    iVar8 = param_2;
  }
  if (param_2 == 2) {
    iVar8 = 0x2d;
  }
  if (param_2 == 3) {
    iVar8 = 0x33;
  }
  if (DAT_005363bc == 1) {
    local_1c = (int)(longlong)(param_4 + param_4);
    iVar3 = local_1c / 3;
    local_18 = (local_1c * 9) / 10;
  }
  else {
    local_1c = (int)(longlong)(param_4 * _DAT_004cc860);
    iVar3 = 0;
    local_18 = 0;
  }
  if (DAT_00536528 == 1) {
    local_1c = (int)(longlong)(param_4 * _DAT_004cc5f0);
  }
  local_14 = 0;
  if ((((DAT_005364bc == 1) && (param_2 == 2)) && (*(int *)(&DAT_004fecc8 + param_3 * 4) < 0x6e)) &&
     (0xc < *(int *)(&DAT_004fc2c0 + param_3 * 4))) {
    local_14 = -local_1c;
    iVar4 = (int)((ulonglong)((longlong)local_1c * 0x55555555) >> 0x20) - local_1c;
    local_18 = (iVar4 >> 1) - (iVar4 >> 0x1f);
  }
  if (param_2 < 4) {
    local_10 = (&DAT_005229e4)[iVar8] - local_1c / 2;
    local_c = (&DAT_005229e8)[iVar8] - local_1c / 2;
  }
  if (param_2 == 4) {
    local_10 = (DAT_00522a98 + DAT_00522a80) / 2 - local_1c / 2;
    local_c = (DAT_00522a9c + DAT_00522a84) / 2 - local_1c / 2;
  }
  if (param_2 == 5) {
    local_10 = (DAT_00522ab0 + DAT_00522a98) / 2 - local_1c / 2;
    local_c = (DAT_00522ab4 + DAT_00522a9c) / 2 - local_1c / 2;
  }
  uVar2 = param_3 >> 0x1f;
  if ((param_2 == 2) || (param_2 == 4)) {
    if ((DAT_005363e4 == 1) ||
       ((((param_3 ^ uVar2) - uVar2 & 1 ^ uVar2) == uVar2 || (DAT_00536450 == 1)))) {
      if (DAT_004fe33c < param_5) {
        if (DAT_004f1cf4 != (HGDIOBJ)0x0) {
          pHVar9 = (HDC)param_1[1];
          pvVar10 = DAT_004f1cf4;
override_prt_422a91_6059bb06:
          SelectObject(pHVar9,pvVar10);
        }
      }
      else if (DAT_004f4154 != (HGDIOBJ)0x0) {
        pHVar9 = (HDC)param_1[1];
        pvVar10 = DAT_004f4154;
        goto override_prt_422a91_6059bb06;
      }
      param_1 = (int *)0x4;
    }
    else {
      if (DAT_004fe33c < param_5) {
        if (DAT_0053560c != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_0053560c);
          param_1 = (int *)0x2;
          goto LAB_00422a9b;
        }
      }
      else if (DAT_005116dc != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_005116dc);
      }
      param_1 = (int *)0x2;
    }
  }
  else {
    if (((DAT_005363e4 == 1) || (((param_3 ^ uVar2) - uVar2 & 1 ^ uVar2) == uVar2)) ||
       (DAT_00536450 == 1)) {
      if (DAT_004fe33c < param_5) {
        if (DAT_00511774 != (HGDIOBJ)0x0) {
          pHVar9 = (HDC)param_1[1];
          pvVar10 = DAT_00511774;
override_prt_4228ad_6059bb06:
          SelectObject(pHVar9,pvVar10);
        }
      }
      else if (DAT_00535494 != (HGDIOBJ)0x0) {
        pHVar9 = (HDC)param_1[1];
        pvVar10 = DAT_00535494;
        goto override_prt_4228ad_6059bb06;
      }
      param_1 = (int *)0x3;
    }
    else {
      if (DAT_004fe33c < param_5) {
        if (DAT_00534eb4 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_00534eb4);
          param_1 = (int *)0x1;
          goto LAB_004228b7;
        }
      }
      else if (DAT_00535174 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_00535174);
      }
      param_1 = (int *)0x1;
    }
LAB_004228b7:
    if (DAT_005363e4 == 0) {
      if (((param_3 % 3 == 0) && (DAT_00536450 == 0)) && (DAT_005363bc == 0)) {
        if (DAT_004fe33c < param_5) {
          if (DAT_004fb9e4 != (HGDIOBJ)0x0) {
            pHVar9 = (HDC)original_dc[1];
            pvVar10 = DAT_004fb9e4;
override_prt_422929_6059bb06:
            SelectObject(pHVar9,pvVar10);
          }
        }
        else if (DAT_00525a74 != (HGDIOBJ)0x0) {
          pHVar9 = (HDC)original_dc[1];
          pvVar10 = DAT_00525a74;
          goto override_prt_422929_6059bb06;
        }
        param_1 = (int *)&DAT_00000005;
      }
      if (((DAT_005363e4 == 0) && (DAT_005363bc == 1)) && (param_3 == 1)) {
        if (DAT_004fe33c < param_5) {
          if (DAT_004fb9e4 != (HGDIOBJ)0x0) {
            SelectObject((HDC)original_dc[1],DAT_004fb9e4);
            param_1 = (int *)&DAT_00000005;
            goto LAB_00422a9b;
          }
        }
        else if (DAT_00525a74 != (HGDIOBJ)0x0) {
          SelectObject((HDC)original_dc[1],DAT_00525a74);
        }
        param_1 = (int *)&DAT_00000005;
      }
    }
  }
LAB_00422a9b:
  if (param_2 == 4) {
    FUN_004b4d9d(original_dc,local_8,(DAT_00522994 + DAT_0052297c) / 2,
                 (DAT_00522a7c + DAT_00522a94) / 2 - iVar3);
    CDC::LineTo(original_dc,(DAT_00522998 + DAT_00522980) / 2,
                (DAT_00522a98 + DAT_00522a80) / 2 - local_1c);
    CDC::LineTo(original_dc,(DAT_0052299c + DAT_00522984) / 2,
                (DAT_00522a84 + DAT_00522a9c) / 2 - local_1c);
    CDC::LineTo(original_dc,(DAT_00522988 + DAT_005229a0) / 2,
                (DAT_00522aa0 + DAT_00522a88) / 2 - iVar3);
    FUN_004b4d9d(original_dc,local_8,(DAT_00522994 + DAT_0052297c) / 2,
                 (DAT_00522a94 + DAT_00522a7c) / 2 - iVar3);
  }
  if (param_2 == 5) {
    FUN_004b4d9d(original_dc,local_8,(DAT_005229ac + DAT_00522994) / 2,
                 (DAT_00522a94 + DAT_00522aac) / 2 - iVar3);
    CDC::LineTo(original_dc,(DAT_00522998 + DAT_005229b0) / 2,
                (DAT_00522ab0 + DAT_00522a98) / 2 - local_1c);
    CDC::LineTo(original_dc,(DAT_005229b4 + DAT_0052299c) / 2,
                (DAT_00522a9c + DAT_00522ab4) / 2 - local_1c);
    CDC::LineTo(original_dc,(DAT_005229a0 + DAT_005229b8) / 2,
                (DAT_00522aa0 + DAT_00522ab8) / 2 - iVar3);
    FUN_004b4d9d(original_dc,local_8,(DAT_00522994 + DAT_005229ac) / 2,
                 (DAT_00522aac + DAT_00522a94) / 2 - iVar3);
  }
  if (param_2 < 4) {
    FUN_004b4d9d(original_dc,local_8,(&DAT_005228e0)[iVar8],
                 ((&DAT_005229e0)[iVar8] - local_14) - iVar3);
    CDC::LineTo(original_dc,(&DAT_005228e4)[iVar8],((&DAT_005229e4)[iVar8] - local_14) - local_1c);
    CDC::LineTo(original_dc,(&DAT_005228e8)[iVar8],((&DAT_005229e8)[iVar8] - local_14) - local_1c);
    CDC::LineTo(original_dc,(&DAT_005228ec)[iVar8],((&DAT_005229ec)[iVar8] - local_14) - iVar3);
    FUN_004b4d9d(original_dc,local_8,(&DAT_005228e0)[iVar8],
                 ((&DAT_005229e0)[iVar8] - local_14) - iVar3);
  }
  if ((DAT_004fe33c < param_5) || (pcVar7 = SelectObject_exref, param_3 == 1)) {
    if ((param_1 == (int *)0x2) && (DAT_005116dc != (HGDIOBJ)0x0)) {
      (*pcVar7)((HDC)original_dc[1],DAT_005116dc);
    }
    if ((param_1 == (int *)0x1) && (DAT_00535174 != (HGDIOBJ)0x0)) {
      (*pcVar7)((HDC)original_dc[1],DAT_00535174);
    }
    if ((param_1 == (int *)0x4) && (DAT_004f4154 != (HGDIOBJ)0x0)) {
      (*pcVar7)((HDC)original_dc[1],DAT_004f4154);
    }
    if ((param_1 == (int *)0x3) && (DAT_00535494 != (HGDIOBJ)0x0)) {
      (*pcVar7)((HDC)original_dc[1],DAT_00535494);
    }
    if ((param_1 == (int *)&DAT_00000005) && (DAT_00525a74 != (HGDIOBJ)0x0)) {
      (*pcVar7)((HDC)original_dc[1],DAT_00525a74);
    }
    if (((param_2 < 2) || (DAT_004da190 != 7)) || (param_6 != 1)) {
      iVar4 = 0;
    }
    else {
      iVar4 = (local_1c * 3) / 2;
    }
    if (((1 < param_2) && (1 < DAT_005363c0)) && ((DAT_00523198 == 2 && (param_6 == 1)))) {
      iVar4 = (local_1c * 3) / 2;
    }
    if (param_2 == 4) {
      FUN_004b4d9d(original_dc,local_8,(DAT_00522994 + DAT_0052297c) / 2,
                   (DAT_00522a94 + DAT_00522a7c) / 2 - iVar3);
      CDC::LineTo(original_dc,(DAT_0052298c + DAT_005229a4) / 2,
                  (DAT_00522aa4 + DAT_00522a8c) / 2 + iVar4);
      FUN_004b4d9d(original_dc,local_8,(DAT_005229a0 + DAT_00522988) / 2,
                   (DAT_00522aa0 + DAT_00522a88) / 2 - iVar3);
      CDC::LineTo(original_dc,(DAT_00522990 + DAT_005229a8) / 2,
                  (DAT_00522aa8 + DAT_00522a90) / 2 + iVar4);
    }
    if (param_2 == 5) {
      FUN_004b4d9d(original_dc,local_8,(DAT_00522994 + DAT_005229ac) / 2,
                   (DAT_00522a94 + DAT_00522aac) / 2 - iVar3);
      CDC::LineTo(original_dc,(DAT_005229bc + DAT_005229a4) / 2,
                  (DAT_00522aa4 + DAT_00522abc) / 2 + iVar4);
      FUN_004b4d9d(original_dc,local_8,(DAT_005229a0 + DAT_005229b8) / 2,
                   (DAT_00522aa0 + DAT_00522ab8) / 2 - iVar3);
      CDC::LineTo(original_dc,(DAT_005229c0 + DAT_005229a8) / 2,
                  (DAT_00522aa8 + DAT_00522ac0) / 2 + iVar4);
    }
    if (param_2 < 4) {
      FUN_004b4d9d(original_dc,local_8,(&DAT_005228e0)[iVar8],(&DAT_005229e0)[iVar8] - iVar3);
      CDC::LineTo(original_dc,(&DAT_005228f0)[iVar8],(&DAT_005229f0)[iVar8] + iVar4);
      FUN_004b4d9d(original_dc,local_8,(&DAT_005228ec)[iVar8],(&DAT_005229ec)[iVar8] - iVar3);
      CDC::LineTo(original_dc,(&DAT_005228f4)[iVar8],(&DAT_005229f4)[iVar8] + iVar4);
    }
    if (((DAT_005363bc == 0) && (param_2 < 4)) &&
       ((param_2 == 1 || ((DAT_004da190 < 7 && (DAT_005363c0 < 2)))))) {
      iVar3 = *(int *)(&DAT_00522ff0 + param_3 * 4);
      if (DAT_004f7084 != (HGDIOBJ)0x0) {
        SelectObject((HDC)original_dc[1],DAT_004f7084);
      }
      uVar2 = iVar3 * -0x5a - param_7;
      uVar5 = (int)uVar2 >> 0x1f;
      iVar3 = (uVar2 ^ uVar5) - uVar5;
      if (((iVar3 < 0x32) || (param_7 < -0x96)) || (0x96 < param_7)) {
        iVar4 = (&DAT_005228e4)[iVar8];
        iVar1 = (&DAT_005228f0)[iVar8];
        iVar6 = (&DAT_005229f0)[iVar8];
        FUN_004b4d9d(original_dc,local_8,iVar4,local_10);
        CDC::LineTo(original_dc,(iVar4 + iVar1 * 2) / 3,(local_10 + iVar6 * 2) / 3);
      }
      if ((iVar3 < 0x5a) ||
         ((param_7 ^ param_7 >> 0x1f) - (param_7 >> 0x1f) <
          (int)((-(uint)(param_2 != 1) & 0xffffffdd) + 0x37))) {
        iVar3 = ((&DAT_005228e8)[iVar8] + (&DAT_005228f4)[iVar8] * 2) / 3;
        iVar4 = (local_c + (&DAT_005229f4)[iVar8] * 2) / 3;
        FUN_004b4d9d(original_dc,local_8,(&DAT_005228e8)[iVar8],local_c);
        CDC::LineTo(original_dc,iVar3,iVar4);
        if (((param_2 == 1) && ((DAT_004da14c < 1 && (DAT_005363bc == 0)))) &&
           ((FUN_004b4d9d(original_dc,local_8,DAT_00522fc0,DAT_00535560), DAT_0053652c == 0 ||
            (DAT_00536458 < 1)))) {
          CDC::LineTo(original_dc,iVar3,iVar4);
        }
      }
    }
    if (DAT_005363bc == 1) {
      iVar1 = DAT_004fe090 * 4;
      iVar3 = DAT_004fe098 * 6;
      iVar6 = DAT_004fe298 * 4;
      iVar4 = DAT_004fe2a4 * 6;
      FUN_004b4d9d(original_dc,local_8,(&DAT_005228e4)[iVar8],(&DAT_005229e4)[iVar8] - local_1c);
      CDC::LineTo(original_dc,(iVar1 + iVar3) / 10,(iVar6 + iVar4) / 10);
      iVar1 = DAT_004fe098 * 4;
      iVar3 = DAT_004fe090 * 6;
      iVar6 = DAT_004fe298 * 6;
      iVar4 = DAT_004fe2a4 * 4;
      FUN_004b4d9d(original_dc,local_8,(&DAT_005228e8)[iVar8],(&DAT_005229e8)[iVar8] - local_1c);
      CDC::LineTo(original_dc,(iVar1 + iVar3) / 10,(iVar6 + iVar4) / 10);
    }
  }
  (**(code **)(*original_dc + 0x2c))(original_dc,7);
  param_3 = 1 - (int)(longlong)(param_4 * _DAT_004cc8b0);
  if (param_3 < 3) {
    param_3 = 3;
  }
  if (DAT_004da190 == 1) {
    param_3 = param_3 + 1;
  }
  if (DAT_004f71c4 == 1) {
    param_3 = param_3 + 1;
  }
  if ((DAT_004da190 == 1) && (DAT_005363bc == 0)) {
    local_18 = local_18 + -1;
  }
  if (param_5 < DAT_004fe33c) {
    param_3 = param_3 + -1;
    local_18 = local_18 + -1;
  }
  iVar3 = param_2;
  iVar4 = param_2;
  if (param_2 == 4) {
    iVar3 = ((DAT_0052299c + DAT_00522984) / 2 + (DAT_00522998 + DAT_00522980) / 2) / 2;
    iVar4 = ((DAT_00522a9c + DAT_00522a84) / 2 + (DAT_00522a98 + DAT_00522a80) / 2) / 2;
  }
  if (param_2 == 5) {
    iVar3 = ((DAT_0052299c + DAT_005229b4) / 2 + (DAT_00522998 + DAT_005229b0) / 2) / 2;
    iVar4 = ((DAT_00522a9c + DAT_00522ab4) / 2 + (DAT_00522a98 + DAT_00522ab0) / 2) / 2;
  }
  if (param_2 < 4) {
    iVar3 = (int)((&DAT_005228e4)[iVar8] + (&DAT_005228e8)[iVar8]) / 2;
    iVar4 = (int)((&DAT_005229e4)[iVar8] + (&DAT_005229e8)[iVar8]) / 2;
  }
  if ((DAT_005363e4 == 0) && (DAT_00536450 == 0)) {
    if (DAT_00525a94 == (HGDIOBJ)0x0) goto LAB_0042356a;
    pHVar9 = (HDC)original_dc[1];
    pvVar10 = DAT_00525a94;
  }
  else {
    if (DAT_004f3f5c == (HGDIOBJ)0x0) goto LAB_0042356a;
    pHVar9 = (HDC)original_dc[1];
    pvVar10 = DAT_004f3f5c;
  }
  SelectObject(pHVar9,pvVar10);
LAB_0042356a:
  Ellipse((HDC)original_dc[1],iVar3 - param_3,(iVar4 + param_3 * -3) - local_18,param_3 + iVar3,
          (iVar4 - local_18) - param_3);
  return;
}

