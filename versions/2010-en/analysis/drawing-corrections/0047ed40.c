
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0047ed40(int *param_1,int param_2,int param_3)

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
  uint uVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  bool bVar15;
  float10 fVar16;
  HDC pHVar17;
  HGDIOBJ pvVar18;
  int local_298;
  int local_294;
  uint local_290;
  int *local_28c;
  int *local_288;
  int local_284;
  int local_280;
  int iStack_26c;
  int local_268 [2];
  code *local_260 [2];
  int aiStack_258 [2];
  int iStack_250;
  int aiStack_24c [73];
  int local_128 [73];
  undefined4 local_4;
  
  if (*(int *)(&DAT_004f71c0 + param_3 * 4) == 4) {
    return;
  }
  local_280 = (-(uint)(DAT_004da1f8 != 5) & 0xffffffd8) + 0x6e;
  if ((DAT_004da1f8 == 999) && ((param_2 == 1 || (local_280 = 0x3c, param_2 == 6)))) {
    local_280 = 0x50;
  }
  if ((((DAT_004da1f8 == 9) || (DAT_004da1f8 == 10)) || (DAT_004da1f8 == 100)) ||
     (DAT_004da1f8 == 0x6a)) {
    local_280 = 0x37;
  }
  if ((((DAT_004da1f8 == 2) || (DAT_004da1f8 == 3)) ||
      ((DAT_004da1f8 == 4 || ((DAT_004da1f8 == 6 || (DAT_004da1f8 == 0xb)))))) ||
     ((DAT_004da1f8 == 0xc ||
      (((DAT_004da1f8 == 0x65 || (DAT_004da1f8 == 0x68)) || (DAT_004da1f8 == 0x69)))))) {
    local_280 = 0x32;
  }
  local_298 = 2000;
  if (DAT_004da1f8 == 6) {
    local_298 = 3000;
  }
  if (((DAT_004da1f8 == 10) || (DAT_004da1f8 == 0xb)) || (DAT_004da1f8 == 0xc)) {
    local_298 = 3000;
  }
  if (((DAT_004da1f8 == 0xc) || (DAT_004da1f8 == 9)) || (DAT_004da1f8 == 1)) {
    local_298 = 5000;
  }
  if (DAT_004fb5d4 == 1) {
    local_298 = 8000;
  }
  if (DAT_004da1f8 == 100) {
    local_298 = ((0xc < param_2) - 1 & 0xfffff448) + 5000;
  }
  if ((DAT_004da1f8 == 0x65) || (DAT_004da1f8 == 0x66)) {
    local_298 = 3000;
  }
  if ((DAT_004da1f8 == 0x67) || (DAT_004da1f8 == 999)) {
    local_298 = 5000;
  }
  if (DAT_004da1f8 == 0x68) {
    local_298 = 2000;
  }
  if (DAT_004da1f8 == 0x6a) {
    local_298 = 2000;
  }
  _DAT_005364e4 = 1;
  fVar16 = (float10)FUN_00465e90(*(undefined4 *)(&DAT_00535218 + param_2 * 4),
                                 *(undefined4 *)(&DAT_004f4b58 + param_2 * 4),0,param_3);
  iVar5 = DAT_00535564;
  iVar9 = (int)(longlong)(fVar16 * (float10)_DAT_004cc3e8);
  if (local_280 < iVar9) {
    return;
  }
  if (iVar9 < -local_280) {
    return;
  }
  fVar16 = FUN_00481350((int)(longlong)DAT_004f6b00,(int)(longlong)DAT_004f6b00,
                        *(int *)(&DAT_00535218 + param_2 * 4),*(int *)(&DAT_004f4b58 + param_2 * 4))
  ;
  DAT_004da204 = (int)(longlong)fVar16;
  local_290 = (iVar5 - DAT_004da148) * (3 - DAT_005359d8);
  if ((*(int *)(&DAT_00534fe0 + param_2 * 4) < 0xc9) ||
     (local_290 = (int)local_290 / 2, *(int *)(&DAT_00534fe0 + param_2 * 4) < 0xc9)) {
    local_290 = local_290 * 2;
  }
  local_294 = 0;
  local_28c = &DAT_00535a98;
  iVar7 = param_2 * 0x124;
  piVar13 = (int *)(&DAT_004f4e50 + iVar7);
  iVar5 = iVar7;
  local_288 = (int *)(&DAT_004fc470 + iVar7);
  do {
    FUN_0043e730(0,(double)*(int *)(&DAT_004f1cf8 + iVar5),(double)*(int *)(&DAT_004f8ee8 + iVar5),
                 param_3,5);
    iVar8 = DAT_00523660;
    iVar4 = DAT_004da148;
    *piVar13 = DAT_004fed58;
    iVar10 = DAT_004fb5d4;
    if (iVar4 + 1 < iVar8) {
      iVar8 = iVar8 + 2;
      DAT_00523660 = iVar8;
    }
    if (DAT_004fb5d4 == 1) {
      iVar4 = ((&DAT_00512d70)[local_294] * (iVar8 - iVar4)) / (int)local_290 + 2;
    }
    else {
      iVar4 = ((&DAT_00512d70)[local_294] * (iVar8 - iVar4)) / (int)local_290 + 3;
    }
    bVar15 = DAT_004fb5d4 == 1;
    (&DAT_004f8dc0)[local_294] = iVar4;
    if ((bVar15) && (param_2 == 4)) {
      (&DAT_004f8dc0)[local_294] = (&DAT_004f8dc0)[local_294] << 1;
    }
    if ((iVar10 == 1) && ((param_2 == 5 || (param_2 == 7)))) {
      (&DAT_004f8dc0)[local_294] = 2;
    }
    iVar4 = DAT_004da1f8;
    if ((DAT_004da1f8 == 0xc) && (param_2 < 3)) {
      (&DAT_004f8dc0)[local_294] = 2;
    }
    if ((iVar4 == 3) && (DAT_004da204 < 1000)) {
      (&DAT_004f8dc0)[local_294] = ((&DAT_004f8dc0)[local_294] * 3) / 2;
    }
    if ((iVar4 == 0x67) && (param_2 == 3)) {
      (&DAT_004f8dc0)[local_294] = 4;
    }
    if ((iVar4 == 0x68) && (param_2 == 1)) {
      (&DAT_004f8dc0)[local_294] = 2;
    }
    *local_288 = iVar8;
    iVar4 = (&DAT_004f8dc0)[local_294];
    iVar10 = *piVar13;
    *local_28c = iVar8 - iVar4;
    aiStack_24c[local_294 + 1] = iVar10;
    local_128[local_294 + 1] = iVar8 - iVar4;
    if ((((0x535a98 < (int)local_28c) && (0 < piVar13[-1])) && (piVar13[-1] < DAT_004fe624)) &&
       ((0 < iVar10 && (iVar10 < DAT_004fe624)))) {
      if (DAT_00536450 == 0) {
        if (DAT_004f4a4c != (HGDIOBJ)0x0) {
          pHVar17 = (HDC)param_1[1];
          pvVar18 = DAT_004f4a4c;
override_prt_47f175_6059bb06:
          SelectObject(pHVar17,pvVar18);
        }
      }
      else if (DAT_005362fc != (HGDIOBJ)0x0) {
        pHVar17 = (HDC)param_1[1];
        pvVar18 = DAT_005362fc;
        goto override_prt_47f175_6059bb06;
      }
      FUN_004b4d9d(param_1,local_268,piVar13[-1],local_288[-1] + -1);
      CDC::LineTo(param_1,*piVar13,*local_288 + -1);
      if ((*(int *)(&DAT_00535310 + param_2 * 4) <= local_294) &&
         (local_294 <= *(int *)(&DAT_00535370 + param_2 * 4))) {
        if (DAT_004fe174 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004fe174);
        }
        FUN_004b4d9d(param_1,(int *)local_260,piVar13[-1],local_288[-1]);
        CDC::LineTo(param_1,*piVar13,*local_288);
      }
    }
    local_28c = local_28c + 1;
    local_294 = local_294 + 1;
    iVar5 = iVar5 + 4;
    local_288 = local_288 + 1;
    piVar13 = piVar13 + 1;
  } while ((int)local_28c < 0x535bb5);
  _DAT_004f8ee0 = DAT_004f8dc0;
  local_128[0] = *(int *)(&DAT_004f4e50 + iVar7);
  _DAT_00535bb8 = DAT_00535a98;
  *(int *)(&DAT_004f4f70 + iVar7) = local_128[0];
  local_4 = *(undefined4 *)(&DAT_004fc590 + iVar7);
  if (DAT_004da204 < 0x97) {
    FUN_00480d40(param_2,param_1,param_3);
  }
  if (DAT_004f3f5c != (HGDIOBJ)0x0) {
    SelectObject((HDC)param_1[1],DAT_004f3f5c);
  }
  pcVar1 = *(code **)(*param_1 + 0x2c);
  local_260[0] = pcVar1;
  (*pcVar1)(param_1,8);
  if ((DAT_004da1f8 == 1) && (DAT_004fe07c != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004fe07c);
  }
  if ((DAT_004da1f8 == 0xc) && (param_2 < 3)) {
    if (DAT_005230cc != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_005230cc);
    }
    (*pcVar1)(param_1,8);
  }
  if (((DAT_004da1f8 == 2) || (DAT_004da1f8 == 3)) && (DAT_004fe07c != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004fe07c);
  }
  if ((((DAT_004da1f8 == 7) || (DAT_004da1f8 == 0xb)) ||
      ((DAT_004da1f8 == 0x69 || ((DAT_004da1f8 == 999 && (DAT_00536524 == 1)))))) &&
     (DAT_00525a94 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_00525a94);
  }
  if (DAT_004fb5d4 == 1) {
    if (DAT_00525a94 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_00525a94);
    }
    if ((DAT_004fb5d4 == 1) && ((param_2 == 5 || (param_2 == 7)))) {
      if (DAT_005230cc != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_005230cc);
      }
      (*pcVar1)(param_1,8);
    }
  }
  if (DAT_004da1f8 == 9) {
    if ((param_2 < 4) || (param_2 == 7)) {
      if (DAT_004f3f5c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f3f5c);
      }
    }
    else {
      (*pcVar1)(param_1,4);
    }
  }
  if (DAT_004da1f8 == 0x67) {
    if (param_2 == 3) {
      if (DAT_004f3f5c == (HGDIOBJ)0x0) goto LAB_0047f462;
      pHVar17 = (HDC)param_1[1];
      pvVar18 = DAT_004f3f5c;
    }
    else {
      if (DAT_00525a94 == (HGDIOBJ)0x0) goto LAB_0047f462;
      pHVar17 = (HDC)param_1[1];
      pvVar18 = DAT_00525a94;
    }
    SelectObject(pHVar17,pvVar18);
  }
LAB_0047f462:
  if ((DAT_004da1f8 == 0x68) && (DAT_004f3f5c != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004f3f5c);
  }
  if (((DAT_004da1f8 == 0x6a) || (DAT_004da1f8 == 0x66)) && (DAT_00525a94 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_00525a94);
  }
  if (DAT_00536450 == 1) {
    if (DAT_004fe174 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe174);
    }
    if (DAT_004fe07c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
  }
  if (DAT_004fb5d4 == 1) {
    DAT_004da204 = 100;
  }
  if (DAT_004da1f8 == 0x68) {
    DAT_004da204 = 100;
  }
  local_294 = 1;
  iVar5 = 0;
  piVar13 = (int *)(&DAT_004f4e54 + iVar7);
  do {
    if (((*(int *)(&DAT_00535310 + param_2 * 4) <= local_294) &&
        (local_294 <= *(int *)(&DAT_00535370 + param_2 * 4))) && (DAT_004da204 <= local_298)) {
      _DAT_004f6e28 = piVar13[-1];
      _DAT_004f6e2c = *(int *)((int)&DAT_00535a98 + iVar5) + 1;
      _DAT_004f6e34 = *(int *)((int)&DAT_004f8dc0 + iVar5) + *(int *)((int)&DAT_00535a98 + iVar5);
      _DAT_004f6e3c = *(int *)((int)&DAT_00535a9c + iVar5) + *(int *)((int)&DAT_004f8dc4 + iVar5);
      _DAT_004f6e38 = *piVar13;
      _DAT_004f6e44 = *(int *)((int)&DAT_00535a9c + iVar5) + 1;
      _DAT_004f6e30 = _DAT_004f6e28;
      _DAT_004f6e40 = _DAT_004f6e38;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
      if (DAT_004fe174 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe174);
      }
      FUN_004b4d9d(param_1,local_268,piVar13[-1],*(int *)((int)&DAT_00535a98 + iVar5) + 1);
      CDC::LineTo(param_1,*piVar13,*(int *)((int)&DAT_00535a9c + iVar5) + 1);
      (*local_260[0])(param_1,8);
    }
    iVar4 = DAT_004da148;
    iVar5 = iVar5 + 4;
    local_294 = local_294 + 1;
    piVar13 = piVar13 + 1;
  } while (iVar5 < 0x11d);
  piVar13 = &DAT_00535a98;
  piVar14 = (int *)(&DAT_004fc470 + iVar7);
  for (iVar5 = 0x48; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar14 = *piVar13;
    piVar13 = piVar13 + 1;
    piVar14 = piVar14 + 1;
  }
  if (((iVar4 < DAT_00535a9c) || (iVar4 < DAT_00535ae0)) ||
     ((iVar4 < DAT_00535b28 || (iVar4 < DAT_00535b70)))) {
    FUN_00469900(param_1,param_2,1,0,0);
  }
  FUN_0043e730(0,(double)*(int *)(&DAT_00535218 + param_2 * 4),
               (double)*(int *)(&DAT_004f4b58 + param_2 * 4),param_3,5);
  iVar4 = DAT_00523660;
  iVar5 = DAT_004fed58;
  local_28c = (int *)(DAT_004fe2a8 / 0x50 + DAT_004da148);
  if (((((DAT_004da1f8 == 0x67) || (DAT_004da1f8 == 0x6a)) || (DAT_004da1f8 == 1)) ||
      (DAT_004da1f8 == 999)) &&
     (local_28c = (int *)(DAT_004fe2a8 / 0xa0 + DAT_004da148), DAT_004da1f8 == 999)) {
    local_28c = (int *)(DAT_004fe2a8 / 0x1e0 + DAT_004da148);
  }
  local_268[0] = DAT_004fe2a8 / 0x1e0 + DAT_004da148;
  iVar10 = DAT_004fe2a8 / 0xa0 + DAT_004da148;
  if (((DAT_004da1f8 == 0xb) || (DAT_004da1f8 == 0xc)) ||
     ((DAT_004da1f8 == 100 || (DAT_004da1f8 == 0x6a)))) {
    local_268[0] = DAT_004da148 + -1;
  }
  if (((*(int *)(&DAT_00534fe0 + param_2 * 4) < 2000) || (DAT_004da140 == 2)) ||
     (0xb < DAT_004da174)) {
    local_284 = 2;
  }
  else {
    local_284 = 1;
  }
  if (DAT_004da1f8 == 999) {
    local_284 = 1;
  }
  if ((DAT_005363e0 == 0) && (*(double *)(&DAT_004f45c0 + param_2 * 8) == _DAT_004cc658)) {
    local_290 = 1;
    iVar6 = iVar9;
    iVar8 = iVar9;
    do {
      if (((DAT_004da148 < iVar4) && (-(DAT_004fe624 / 2) <= iVar5)) &&
         (iVar5 <= (DAT_004fe624 * 3) / 2)) {
        iVar12 = local_128[local_290];
        if ((iVar12 <= DAT_00535564) && (iVar2 = local_128[local_290 + 1], iVar2 <= DAT_00535564)) {
          iStack_26c = 2;
          local_288 = &DAT_00512d74 + local_290;
          do {
            iVar3 = *local_288;
            if (iVar3 < 0x1a) {
              iVar8 = (aiStack_24c[local_290 + 1] * 3 + aiStack_24c[local_290] + iVar5) / 5;
              iVar6 = (iVar4 + iVar2 * 3 + iVar12) / 5;
              if (0x19 < iVar3) goto LAB_0047f8f8;
            }
            else {
LAB_0047f8f8:
              if ((int)(&DAT_00512d78)[local_290] < 0x33) {
                iVar8 = (aiStack_24c[local_290] + iVar5 + aiStack_24c[local_290 + 1]) / 3;
                iVar6 = (iVar4 + iVar2 + iVar12) / 3;
              }
            }
            if ((0x32 < iVar3) && ((int)(&DAT_00512d78)[local_290] < 0x4b)) {
              iVar8 = aiStack_24c[local_290] + iVar5 * 2 + aiStack_24c[local_290 + 1];
              iVar6 = iVar2 + iVar4 * 2 + iVar12;
              iVar8 = (int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2;
              iVar6 = (int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2;
            }
            if (0x4a < iVar3) {
              iVar8 = (iVar5 + aiStack_24c[local_290] * 3 + aiStack_24c[local_290 + 1]) / 5;
              iVar6 = (iVar4 + iVar12 * 3 + iVar2) / 5;
            }
            uVar11 = (int)local_290 >> 0x1f;
            if (((*(int *)(&DAT_004f3ef0 + param_2 * 4) == 0) ||
                (((local_290 ^ uVar11) - uVar11 & 1 ^ uVar11) == uVar11)) && (iVar6 + iVar8 != 0)) {
              if (iVar6 < (int)local_28c) {
                if (DAT_004f7084 != (HGDIOBJ)0x0) {
                  SelectObject((HDC)param_1[1],DAT_004f7084);
                }
                FUN_004b4d9d(param_1,&iStack_250,iVar8,iVar6);
                CDC::LineTo(param_1,iVar8,iVar6 + -1);
              }
              if (((int)local_28c < iVar6) && (iVar6 != iVar8)) {
                if (DAT_00535214 != (HGDIOBJ)0x0) {
                  SelectObject((HDC)param_1[1],DAT_00535214);
                }
                FUN_004b4d9d(param_1,aiStack_258,iVar8 + -1,iVar6);
                CDC::LineTo(param_1,iVar8,iVar6 + -2);
                CDC::LineTo(param_1,iVar8 + 1,iVar6);
              }
            }
            pcVar1 = local_260[0];
            local_288 = local_288 + 1;
            iStack_26c = iStack_26c + -1;
          } while (iStack_26c != 0);
          if (((2 < *(int *)(&DAT_004f3ef0 + param_2 * 4)) ||
              ((((iVar3 = (&DAT_00512d70)[local_290], 0x4f < iVar3 ||
                 (99 < *(int *)(&DAT_00534fe0 + param_2 * 4))) &&
                ((0x31 < iVar3 || (199 < *(int *)(&DAT_00534fe0 + param_2 * 4))))) &&
               (((0x3b < iVar3 || (500 < *(int *)(&DAT_00534fe0 + param_2 * 4))) ||
                (DAT_004da1f8 != 2)))))) &&
             (((0 < *(int *)(&DAT_004f3ef0 + param_2 * 4) &&
               (-((int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 3U)) >> 2) < iVar5)) &&
              (iVar5 < (int)(DAT_004fe624 * 5 + (DAT_004fe624 * 5 >> 0x1f & 3U)) >> 2)))) {
            if (*(int *)(&DAT_00512d84 + local_290 * 4) < 0x1a) {
              iVar8 = (aiStack_24c[local_290 + 1] * 3 + aiStack_24c[local_290] + iVar5) / 5;
              iVar6 = (iVar4 + iVar2 * 3 + iVar12) / 5;
            }
            if ((0x19 < *(int *)(&DAT_00512d84 + local_290 * 4)) &&
               ((int)(&DAT_00512d78)[local_290] < 0x33)) {
              iVar8 = (aiStack_24c[local_290] + iVar5 + aiStack_24c[local_290 + 1]) / 3;
              iVar6 = (iVar4 + iVar2 + iVar12) / 3;
            }
            if ((0x32 < *(int *)(&DAT_00512d84 + local_290 * 4)) &&
               ((int)(&DAT_00512d78)[local_290] < 0x4b)) {
              iVar8 = aiStack_24c[local_290] + iVar5 * 2 + aiStack_24c[local_290 + 1];
              iVar6 = iVar2 + iVar4 * 2 + iVar12;
              iVar8 = (int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2;
              iVar6 = (int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2;
            }
            if (0x4a < *(int *)(&DAT_00512d84 + local_290 * 4)) {
              iVar8 = (iVar5 + aiStack_24c[local_290] * 3 + aiStack_24c[local_290 + 1]) / 5;
              iVar6 = (iVar4 + iVar12 * 3 + iVar2) / 5;
            }
            (*local_260[0])(param_1,8);
            if (DAT_00536450 == 0) {
              if (((local_290 ^ uVar11) - uVar11 & 1 ^ uVar11) == uVar11) {
                (*pcVar1)(param_1,0);
              }
              else if (DAT_004f3f5c != (HGDIOBJ)0x0) {
                pHVar17 = (HDC)param_1[1];
                pvVar18 = DAT_004f3f5c;
                goto override_prt_47fd3c_6059bb06;
              }
            }
            else if (DAT_005230cc != (HGDIOBJ)0x0) {
              pHVar17 = (HDC)param_1[1];
              pvVar18 = DAT_005230cc;
override_prt_47fd3c_6059bb06:
              SelectObject(pHVar17,pvVar18);
            }
            if (iVar6 < local_268[0]) {
LAB_0047fe40:
              if (iVar10 <= iVar6) goto LAB_0047fe4a;
            }
            else {
              if (iVar6 < iVar10) {
                if (iVar6 + iVar8 != 0) {
                  if (*(int *)(&DAT_004f3ef0 + param_2 * 4) == 2) {
                    iVar12 = (int)(&DAT_00512d70)[local_290 + param_2] / 10 + 3;
                    if ((DAT_004da1f8 == 9) || (DAT_004da1f8 == 10)) {
                      iVar12 = (int)(&DAT_00512d70)[local_290 + param_2] / 10 + 2;
                    }
                  }
                  else {
                    iVar12 = 3;
                  }
                  if ((*(int *)(&DAT_004f3ef0 + param_2 * 4) == 2) && (DAT_004da1f8 == 0x69)) {
                    iVar12 = iVar12 / 2;
                  }
                  Rectangle((HDC)param_1[1],iVar8 + -3,iVar6,iVar8 + 3,iVar6 - iVar12);
                  if (((DAT_00536450 == 1) &&
                      (SetPixel((HDC)param_1[1],iVar8,iVar6 - iVar12 / 2,0xffffff),
                      DAT_00536450 == 1)) && (*(int *)(&DAT_004f3ef0 + param_2 * 4) == 2)) {
                    SetPixel((HDC)param_1[1],iVar8,iVar6 - iVar12,0xffffff);
                  }
                }
                goto LAB_0047fe40;
              }
LAB_0047fe4a:
              if (iVar6 + iVar8 != 0) {
                if (*(int *)(&DAT_004f3ef0 + param_2 * 4) == 2) {
                  iVar12 = (int)(&DAT_00512d70)[local_290 + param_2] / 6 + 4;
                  if ((DAT_004da1f8 == 9) || (DAT_004da1f8 == 10)) {
                    iVar12 = (int)(&DAT_00512d70)[local_290 + param_2] / 6 + 2;
                  }
                }
                else {
                  iVar12 = 4;
                }
                if ((*(int *)(&DAT_004f3ef0 + param_2 * 4) == 2) && (DAT_004da1f8 == 0x69)) {
                  iVar12 = iVar12 / 2;
                }
                Rectangle((HDC)param_1[1],iVar8 + -4,iVar6,iVar8 + 4,iVar6 - iVar12);
                if (((DAT_00536450 == 1) &&
                    (SetPixel((HDC)param_1[1],iVar8,iVar6 - iVar12 / 2,0xffffff), DAT_00536450 == 1)
                    ) && (*(int *)(&DAT_004f3ef0 + param_2 * 4) == 2)) {
                  SetPixel((HDC)param_1[1],iVar8,iVar6 - iVar12,0xffffff);
                }
              }
            }
            if (((DAT_004da1f8 == 0xc) && (param_2 == 4)) && (local_290 == 0x1c)) {
              if (DAT_004fe07c != (HGDIOBJ)0x0) {
                SelectObject((HDC)param_1[1],DAT_004fe07c);
              }
              Rectangle((HDC)param_1[1],iVar8 + -4,iVar6,iVar8 + 4,iVar6 + -0x13);
              Rectangle((HDC)param_1[1],iVar8 + -2,iVar6 + -0x12,iVar8 + 2,iVar6 + -0x1c);
            }
          }
        }
      }
      local_290 = local_290 + local_284;
    } while ((int)local_290 < 0x47);
  }
  if ((iVar9 <= local_280 + -5) && (5 - local_280 <= iVar9)) {
    if ((((200 < *(int *)(&DAT_00534fe0 + param_2 * 4)) &&
         ((((_DAT_004cc6d8 < *(double *)(&DAT_004fb5e0 + param_2 * 8) &&
            (*(int *)(&DAT_004f3ef0 + param_2 * 4) < 2)) && (DAT_004da1f8 != 0xb)) &&
          ((DAT_004da1f8 != 0xc && (DAT_004da1f8 != 9)))))) && (0 < iVar5)) &&
       (iVar5 < DAT_004fe624)) {
      FUN_004813f0(param_1,iVar5,iVar4,4,param_2,1,param_3);
    }
    if ((DAT_004da1f8 == 6) && (param_2 == 4)) {
      _DAT_00535ecc = DAT_005233ac;
    }
    iVar9 = (*(int *)(&DAT_004f4e8c + iVar7) + *(int *)(&DAT_004f4f34 + iVar7)) / 2;
    if ((((400 < *(int *)(&DAT_00534fe0 + param_2 * 4)) || (DAT_004fb5d4 == 1)) &&
        (_DAT_004cc5f0 < *(double *)(&DAT_004fb5e0 + param_2 * 8))) &&
       (((*(int *)(&DAT_004f3ef0 + param_2 * 4) < 2 || (DAT_004da1f8 == 6)) &&
        ((0 < iVar9 && (iVar9 < DAT_004fe624)))))) {
      FUN_004813f0(param_1,iVar9,
                   (*(int *)(&DAT_004fc4ac + iVar7) + *(int *)(&DAT_004fc554 + iVar7)) / 2,2,param_2
                   ,1,param_3);
    }
    if (DAT_004da1f8 == 100) {
      if (param_2 == 5) {
        FUN_004817a0(param_1,1,1,DAT_004f5470,DAT_004fca90,1,0,1,0,param_3);
      }
      iVar9 = DAT_004fcc20;
      if (param_2 == 6) {
        iVar7 = DAT_004f5600 + 5;
        iVar10 = DAT_004f5600 + -5;
        if (DAT_005359c4 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_005359c4);
        }
        FUN_004b4d9d(param_1,aiStack_258,iVar7,iVar9);
        CDC::LineTo(param_1,iVar10,iVar9);
        FUN_00441fb0(param_1,iVar7,iVar9,1);
        FUN_00441fb0(param_1,iVar10,iVar9,1);
        iVar10 = DAT_004fcc18;
        iVar7 = DAT_004f55f8;
        iVar9 = DAT_004f55f8 + 10;
        if (DAT_005359c4 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_005359c4);
        }
        FUN_004b4d9d(param_1,aiStack_258,iVar7,iVar10);
        CDC::LineTo(param_1,iVar9,iVar10);
        FUN_00441fb0(param_1,iVar7,iVar10,1);
        FUN_00441fb0(param_1,iVar9,iVar10,1);
        FUN_00483fa0(param_1,DAT_004f55c0,DAT_004fcbe0,10.0,param_3);
        FUN_00483fa0(param_1,DAT_004f55b0,DAT_004fcbd0,10.0,param_3);
      }
      if (param_2 == 9) {
        DAT_005364f4 = 1;
        FUN_00482ae0(param_1,0x1946,-0x1b8a,80.0,90.0,0.2,25.0,0.8,param_3);
        DAT_005364f4 = 0;
      }
    }
    if (DAT_004da1f8 == 0x66) {
      if (param_2 == 5) {
        iVar9 = (iVar5 + DAT_004f5494 * 0x13) / 0x14;
        FUN_004813f0(param_1,iVar9,(iVar4 + DAT_004fcab4 * 0x13) / 0x14,1,5,1,param_3);
        FUN_004817a0(param_1,99,0,iVar9,DAT_005233ac,1,1,3,0,param_3);
      }
      if (param_2 == 9) {
        FUN_004817a0(param_1,99,0,DAT_004f59a8,DAT_004fcfc8,1,1,1,0,param_3);
      }
      if (param_2 == 4) {
        FUN_004817a0(param_1,99,0,DAT_004f53f4,DAT_004fca14,1,1,2,0,param_3);
      }
    }
    if ((DAT_004da1f8 == 1) && (param_2 == 1)) {
      FUN_004817a0(param_1,99,0,iVar5,DAT_005233ac,1,1,5,0,param_3);
    }
    if (DAT_004da1f8 == 100) {
      if (param_2 == 2) {
        FUN_004817a0(param_1,99,1,iVar5,DAT_005233ac,1,1,5,0,param_3);
        FUN_00481e90(param_1,iVar5,DAT_005233ac + 2,4,param_3);
      }
      if ((DAT_004da1f8 == 100) && (param_2 == 0xd)) {
        FUN_004419a0(param_1,iVar5,DAT_005233ac + 2);
      }
    }
    if (DAT_004fb5d4 == 1) {
      if (param_2 == 3) {
        FUN_004817a0(param_1,0x62,0,(DAT_004f52d0 + DAT_004f51c8 * 2) / 3,
                     (DAT_004fc8f0 + DAT_004fc7e8 * 2) / 3,1,1,0xffffffff,0,param_3);
        FUN_00481e90(param_1,(DAT_004f52d0 + DAT_004f51c8 * 2) / 3,
                     (DAT_004fc8f0 + DAT_004fc7e8 * 2) / 3,4,param_3);
      }
      if (DAT_004fb5d4 == 1) {
        if (param_2 == 3) {
          FUN_00482810(param_1,DAT_004f51c0,DAT_004fc7e0,0,param_3);
        }
        if (DAT_004fb5d4 == 1) {
          if (param_2 == 5) {
            FUN_00482810(param_1,DAT_004f5404,DAT_004fca24,2,param_3);
          }
          if (DAT_004fb5d4 == 1) {
            if (param_2 == 1) {
              FUN_00481e90(param_1,DAT_004f500c,DAT_004fc62c,10,param_3);
            }
            if (DAT_004fb5d4 == 1) {
              if (param_2 == 4) {
                FUN_004817a0(param_1,99,0,DAT_004f52f8,DAT_004fc918,1,1,3,0,param_3);
              }
              if ((DAT_004fb5d4 == 1) && (param_2 == 6)) {
                FUN_00481e90(param_1,(iVar5 + DAT_004f5578 * 9) / 10,(iVar4 + DAT_004fcb98 * 9) / 10
                             ,6,param_3);
              }
            }
          }
        }
      }
    }
    if (DAT_004fb5d4 == 1) {
      if (param_2 == 6) {
        FUN_00481e90(param_1,DAT_004f556c,DAT_004fcb8c,0x10,param_3);
      }
      if (DAT_004fb5d4 == 1) {
        if (param_2 == 6) {
          FUN_00481e90(param_1,DAT_004f5574,DAT_004fcb94,10,param_3);
        }
        if (DAT_004fb5d4 == 1) {
          if (param_2 == 6) {
            FUN_00481e90(param_1,DAT_004f557c,DAT_004fcb9c,0x10,param_3);
          }
          if (DAT_004fb5d4 == 1) {
            if (param_2 == 7) {
              FUN_00482810(param_1,DAT_004f564c,DAT_004fcc6c,1,param_3);
            }
            if ((DAT_004fb5d4 == 1) && (param_2 == 4)) {
              FUN_00482a90(param_1,param_3);
            }
          }
        }
      }
    }
    if (DAT_004da1f8 == 2) {
      if (param_2 == 10) {
        FUN_004833f0(param_1,DAT_004f59bc,DAT_004fcfdc,param_3);
        FUN_004833f0(param_1,DAT_004f5ac0,DAT_004fd0e0,param_3);
      }
      if (param_2 == 3) {
        FUN_004833f0(param_1,DAT_004f520c,DAT_004fc82c,param_3);
        FUN_004817a0(param_1,99,0,DAT_004f52d4,DAT_004fc8f4,1,1,3,0,param_3);
      }
      if (param_2 == 5) {
        FUN_004817a0(param_1,99,0,DAT_004f549c,DAT_004fcabc,1,0,2,0,param_3);
      }
      if (param_2 == 4) {
        FUN_00483a10(param_1,iVar5,iVar4,param_3);
      }
      if (param_2 == 7) {
        FUN_00483ac0(param_1,DAT_004f56b8,DAT_004fccd8,1,param_3);
      }
    }
    if (DAT_004da1f8 == 3) {
      if (param_2 == 1) {
        FUN_004817a0(param_1,99,0,DAT_004f5010,DAT_004fc630,1,1,3,0,param_3);
      }
      if (param_2 == 8) {
        FUN_004817a0(param_1,99,0,DAT_004f5800,DAT_004fce20,1,1,1,0,param_3);
      }
      if (param_2 == 3) {
        FUN_004817a0(param_1,99,0,DAT_004f525c,DAT_004fc87c,1,1,2,0,param_3);
      }
    }
    if (DAT_004da1f8 == 6) {
      if (param_2 == 4) {
        FUN_004834b0(param_1,DAT_004f5380,DAT_004fc9a0,1,param_3);
        FUN_00483de0(param_1,iVar5,iVar4,6,0,9.0,param_3);
      }
      if (param_2 == 5) {
        FUN_00483ac0(param_1,iVar5,iVar4,4,param_3);
        FUN_00483ac0(param_1,DAT_004f5454,DAT_004fca74,1,param_3);
        FUN_00483ac0(param_1,DAT_004f5460,DAT_004fca80,2,param_3);
        FUN_00483ac0(param_1,DAT_004f546c,DAT_004fca8c,3,param_3);
      }
      if (param_2 == 8) {
        FUN_00483ac0(param_1,(DAT_004f5774 + iVar5) / 2,(iVar4 + DAT_004fcd94) / 2,1,param_3);
      }
    }
    if (DAT_004da1f8 == 9) {
      if (param_2 == 1) {
        FUN_00483fa0(param_1,iVar5,iVar4,10.0,param_3);
      }
      if (param_2 == 2) {
        FUN_004833f0(param_1,DAT_004f5138,DAT_004fc758,param_3);
        FUN_00483de0(param_1,DAT_004f5134,DAT_004fc754,1,0,7.0,param_3);
        FUN_00483de0(param_1,DAT_004f5130,DAT_004fc750,1,0,7.0,param_3);
        FUN_00483de0(param_1,DAT_004f512c,DAT_004fc74c,2,1,7.0,param_3);
        FUN_00483de0(param_1,DAT_004f5128,DAT_004fc748,1,0,6.0,param_3);
        FUN_00483de0(param_1,DAT_004f5124,DAT_004fc744,2,1,6.0,param_3);
        FUN_00483de0(param_1,DAT_004f5120,DAT_004fc740,1,0,8.0,param_3);
        FUN_00483de0(param_1,DAT_004f511c,DAT_004fc73c,6,0,9.0,param_3);
        FUN_00483de0(param_1,DAT_004f5118,DAT_004fc738,2,1,8.0,param_3);
        FUN_00483de0(param_1,DAT_004f5114,DAT_004fc734,2,1,6.0,param_3);
      }
      if (param_2 == 3) {
        FUN_00483de0(param_1,DAT_004f523c,DAT_004fc85c,1,0,9.0,param_3);
        FUN_00483de0(param_1,DAT_004f5238,DAT_004fc858,1,1,9.0,param_3);
        FUN_00483de0(param_1,DAT_004f5234,DAT_004fc854,1,0,9.0,param_3);
        FUN_00483de0(param_1,DAT_004f5230,DAT_004fc850,2,1,8.0,param_3);
        FUN_00483de0(param_1,DAT_004f522c,DAT_004fc84c,2,1,6.0,param_3);
      }
      if (param_2 == 8) {
        FUN_00483ac0(param_1,DAT_004f5800,DAT_004fce20,4,param_3);
      }
      if (param_2 == 7) {
        FUN_004419a0(param_1,DAT_004f5704,DAT_004fcd24);
      }
    }
    if (DAT_004da1f8 == 10) {
      if (param_2 == 3) {
        FUN_00483ac0(param_1,DAT_004f5294,DAT_004fc8b4,1,param_3);
      }
      if (param_2 == 4) {
        FUN_004817a0(param_1,99,0,DAT_004f52e4,DAT_004fc904,1,1,1,0,param_3);
      }
    }
    if (DAT_004da1f8 == 0xb) {
      if (param_2 == 0xb) {
        FUN_004817a0(param_1,99,0,DAT_004f5b64,DAT_004fd184,1,1,1,0,param_3);
      }
      if (param_2 == 7) {
        FUN_00441fb0(param_1,DAT_004f5724,DAT_004fcd44,1);
      }
    }
    if ((DAT_004da1f8 == 0x68) && (param_2 == 1)) {
      FUN_004836d0(param_1,DAT_004f5004,DAT_004fc624 + 2,param_3);
    }
    if (DAT_004da1f8 == 0x6a) {
      if (param_2 == 6) {
        FUN_00483fa0(param_1,DAT_004f55ac,DAT_004fcbcc,22.0,param_3);
      }
      if (param_2 == 1) {
        FUN_00482810(param_1,DAT_004f5004,DAT_004fc624,10,param_3);
      }
    }
    _DAT_005364e4 = 0;
  }
  return;
}

