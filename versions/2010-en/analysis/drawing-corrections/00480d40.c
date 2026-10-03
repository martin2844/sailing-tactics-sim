
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00480d40(int param_1,int *param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  HDC hdc;
  HGDIOBJ h;
  int local_1c;
  int local_18;
  int local_14;
  int aiStack_10 [2];
  int aiStack_8 [2];
  
  if ((0 < *(int *)(&DAT_00535310 + param_1 * 4)) || (0 < *(int *)(&DAT_00535370 + param_1 * 4))) {
    local_1c = 1;
    local_14 = 0xb9;
    local_18 = 0;
    do {
      if ((local_1c < *(int *)(&DAT_00535310 + param_1 * 4)) ||
         (*(int *)(&DAT_00535370 + param_1 * 4) < local_1c)) goto LAB_00481106;
      iVar3 = FUN_0041bc20(local_14 -
                           (int)(longlong)(*(double *)(&DAT_004fafa8 + param_1 * 8) * _DAT_004cc910)
                          );
      _DAT_004fe084 = FUN_0041bc20(iVar3);
      uVar5 = _DAT_004fe084 - DAT_005362d4 >> 0x1f;
      iVar3 = (_DAT_004fe084 - DAT_005362d4 ^ uVar5) - uVar5;
      if (0xb4 < iVar3) {
        iVar3 = 0x168 - iVar3;
      }
      uVar5 = (uint)(iVar3 < 0x4b);
      if (0x78 < iVar3) {
        uVar5 = 0xffffffff;
      }
      if (((uVar5 == 0xffffffff) && (DAT_00536450 == 0)) && (0xc < DAT_00522ad0)) {
        iVar3 = param_1 * 0x49;
        if ((*(int *)(&DAT_004fc470 + (local_1c + iVar3) * 4) <= DAT_004da148) ||
           (DAT_004fe2a8 <= *(int *)(&DAT_004fc470 + (local_1c + iVar3) * 4))) goto LAB_00480fa7;
        (**(code **)(*param_2 + 0x2c))(param_2,6);
        uVar2 = (uint)(longlong)(_DAT_005355f8 * _DAT_004cc7b0);
        uVar6 = (int)uVar2 >> 0x1f;
        if ((((uVar2 ^ uVar6) - uVar6 & 1 ^ uVar6) != uVar6) || (DAT_004da288 != 0)) {
LAB_00480edf:
          uVar2 = (uint)(longlong)(_DAT_004cc650 - _DAT_005355f8 * _DAT_004cc7f8);
          uVar6 = (int)uVar2 >> 0x1f;
          if ((((uVar2 ^ uVar6) - uVar6 & 1 ^ uVar6) == uVar6) && (DAT_004da288 == 1)) {
            DAT_004da288 = 0;
          }
          iVar4 = (DAT_004da280 + iVar3) * 4;
          FUN_004b4d9d(param_2,aiStack_10,*(int *)(&DAT_004f4e4c + iVar4),
                       *(int *)(&DAT_004fc46c + iVar4) + 1);
          iVar4 = (DAT_004da280 + iVar3) * 4;
          CDC::LineTo(param_2,*(int *)(&DAT_004f4e50 + iVar4),*(int *)(&DAT_004fc470 + iVar4) + 1);
          iVar4 = (DAT_004da284 + iVar3) * 4;
          FUN_004b4d9d(param_2,aiStack_8,*(int *)(&DAT_004f4e4c + iVar4),
                       *(int *)(&DAT_004fc46c + iVar4) + 1);
          iVar3 = (DAT_004da284 + iVar3) * 4;
          CDC::LineTo(param_2,*(int *)(&DAT_004f4e50 + iVar3),*(int *)(&DAT_004fc470 + iVar3) + 1);
          goto LAB_00480fa7;
        }
        iVar4 = FUN_0041e000(0x44);
        DAT_004da280 = iVar4 + 2;
        if ((*(int *)(&DAT_00535310 + param_1 * 4) < DAT_004da280) &&
           (DAT_004da280 < *(int *)(&DAT_00535370 + param_1 * 4))) {
          iVar4 = FUN_0041e000(0x44);
          DAT_004da284 = iVar4 + 2;
          if ((*(int *)(&DAT_00535310 + param_1 * 4) < DAT_004da284) &&
             (DAT_004da284 < *(int *)(&DAT_00535370 + param_1 * 4))) {
            DAT_004da288 = 1;
            goto LAB_00480edf;
          }
        }
      }
      else {
LAB_00480fa7:
        if ((0 < (int)uVar5) && (DAT_00536450 == 0)) {
          pcVar1 = *(code **)(*param_2 + 0x2c);
          (*pcVar1)(param_2,8);
          (*pcVar1)(param_2,8);
          if (DAT_005363e4 == 0) {
            if (((DAT_004da1f8 == 0x69) || (DAT_004da1f8 == 0x6a)) ||
               ((DAT_004da1f8 == 999 && (DAT_00536524 == 1)))) {
              if (DAT_004f71d4 != (HGDIOBJ)0x0) {
                hdc = (HDC)param_2[1];
                h = DAT_004f71d4;
                goto override_prt_481049_6059bb06;
              }
            }
            else if (DAT_004f71b4 != (HGDIOBJ)0x0) {
              hdc = (HDC)param_2[1];
              h = DAT_004f71b4;
override_prt_481049_6059bb06:
              SelectObject(hdc,h);
            }
          }
          else if (DAT_004fe07c != (HGDIOBJ)0x0) {
            hdc = (HDC)param_2[1];
            h = DAT_004fe07c;
            goto override_prt_481049_6059bb06;
          }
          iVar3 = local_1c + param_1 * 0x49;
          _DAT_004f6e28 = *(undefined4 *)(&DAT_004f4e4c + iVar3 * 4);
          _DAT_004f6e38 = *(undefined4 *)(&DAT_004f4e50 + iVar3 * 4);
          _DAT_004f6e34 =
               *(int *)((int)&DAT_00535a98 + local_18) + *(int *)((int)&DAT_004f8dc0 + local_18);
          _DAT_004f6e2c = _DAT_004f6e34 + 1;
          _DAT_004f6e34 =
               (int)(uVar5 * *(int *)((int)&DAT_004f8dc0 + local_18) * 2) / 3 + 1 + _DAT_004f6e34;
          _DAT_004f6e44 =
               *(int *)((int)&DAT_004f8dc4 + local_18) + *(int *)((int)&DAT_00535a9c + local_18);
          _DAT_004f6e3c =
               (int)(uVar5 * *(int *)((int)&DAT_004f8dc4 + local_18) * 2) / 3 + 1 + _DAT_004f6e44;
          _DAT_004f6e44 = _DAT_004f6e44 + 1;
          _DAT_004f6e30 = _DAT_004f6e28;
          _DAT_004f6e40 = _DAT_004f6e38;
          Polygon((HDC)param_2[1],(POINT *)&DAT_004f6e28,4);
        }
      }
LAB_00481106:
      local_14 = local_14 + 5;
      local_1c = local_1c + 1;
      local_18 = local_18 + 4;
    } while (local_14 < 0x21d);
    (**(code **)(*param_2 + 0x2c))(param_2,8);
  }
  return;
}

