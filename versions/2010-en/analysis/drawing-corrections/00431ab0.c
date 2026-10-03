
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00431ab0(int *param_1,int param_2,int param_3,double param_4,int param_5,int param_6,int param_7
            ,int param_8,int param_9,int param_10,int param_11,int param_12)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  HDC hdc;
  HGDIOBJ h;
  int local_5c;
  int local_58;
  int *local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30 [2];
  double local_28;
  double local_20;
  int local_18 [2];
  int aiStack_10 [3];
  
  if ((DAT_00536450 == 0) && (param_7 == 1)) {
    local_28 = (double)param_2;
    local_20 = (double)param_3;
    iVar7 = 0;
    iVar6 = 1;
    do {
      fVar8 = FUN_0043ec20(*(double *)((int)&DAT_00535468 + iVar7),
                           *(double *)((int)&DAT_004f4b10 + iVar7),1,param_8);
      if (_DAT_004cc560 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
        _DAT_004fbb88 = 0;
        _DAT_004fbb8c = 0x40d09a00;
      }
      fVar9 = (float10)fcos(fVar8);
      fVar8 = (float10)fsin(fVar8);
      FUN_00445040(param_1,iVar6,param_8,param_4,
                   (int)(longlong)
                        (fVar8 * (float10)param_4 *
                         (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) + (float10)local_28)
                   ,(int)(longlong)
                         ((float10)local_20 -
                         fVar9 * (float10)param_4 *
                         (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)),param_9,param_10,
                   param_11,param_12,1);
      iVar7 = iVar7 + 8;
      iVar6 = iVar6 + 1;
    } while (iVar7 < 0x21);
  }
  iVar6 = DAT_004da194;
  if (((DAT_0053641c == 1) && (((param_7 == 1 || (param_7 == 3)) || (param_7 == 2)))) &&
     (local_5c = 1, 0 < DAT_004da194)) {
    do {
      if ((((DAT_0053641c != 0) || (DAT_005363f4 != 0)) &&
          ((DAT_005363f4 < 1 || ((local_5c <= DAT_004da140 || (local_5c == DAT_004f8dbc)))))) &&
         ((DAT_005363f4 != 0 || ((local_5c <= DAT_004da140 || (local_5c == DAT_004f7f90)))))) {
        if ((local_5c == 1) && ((DAT_005363e4 == 1 && (DAT_004f7ec4 != (HGDIOBJ)0x0)))) {
          SelectObject((HDC)param_1[1],DAT_004f7ec4);
        }
        if (((local_5c == 2) && (DAT_005363e4 == 1)) && (DAT_004f7084 != (HGDIOBJ)0x0)) {
          SelectObject((HDC)param_1[1],DAT_004f7084);
        }
        if (((local_5c == 1) && (DAT_005363e4 == 0)) && (DAT_004fb994 != (HGDIOBJ)0x0)) {
          SelectObject((HDC)param_1[1],DAT_004fb994);
        }
        if (((local_5c == 2) && (DAT_005363e4 == 0)) && (DAT_004f1cec != (HGDIOBJ)0x0)) {
          SelectObject((HDC)param_1[1],DAT_004f1cec);
        }
        if (2 < local_5c) {
          FUN_0041f130(param_1,local_5c);
        }
        local_50 = 3;
        if (2 < DAT_00534ea8) {
          local_28 = (double)param_2;
          local_20 = (double)param_3;
          local_4c = local_5c * 0x7d4;
          local_54 = (int *)(&DAT_0050042c + local_4c);
          do {
            fVar8 = FUN_0043ec20((double)*(int *)(&DAT_005135a8 + local_4c),
                                 (double)*(int *)(&DAT_00525ac0 + local_4c),param_7,param_8);
            if (_DAT_004cc560 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
              _DAT_004fbb88 = 0;
              _DAT_004fbb8c = 0x40d09a00;
            }
            fVar9 = (float10)fsin(fVar8);
            uVar1 = (uint)(longlong)
                          (fVar9 * (float10)param_4 *
                           (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) +
                          (float10)local_28);
            fVar8 = (float10)fcos(fVar8);
            local_40 = (int)(longlong)
                            ((float10)local_20 -
                            fVar8 * (float10)param_4 *
                            (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
            fVar8 = FUN_0043ec20((double)*(int *)(&DAT_005135ac + local_4c),
                                 (double)*(int *)(&DAT_00525ac4 + local_4c),param_7,param_8);
            if (_DAT_004cc560 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
              _DAT_004fbb88 = 0;
              _DAT_004fbb8c = 0x40d09a00;
            }
            fVar9 = (float10)fsin(fVar8);
            uVar2 = (uint)(longlong)
                          (fVar9 * (float10)param_4 *
                           (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) +
                          (float10)local_28);
            fVar8 = (float10)fcos(fVar8);
            local_58 = (int)(longlong)
                            ((float10)local_20 -
                            fVar8 * (float10)param_4 *
                            (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
            if ((local_5c <= DAT_004da140) && (DAT_005363e4 == 0)) {
              iVar7 = *local_54;
              if ((iVar7 == 3) || (((iVar7 == 2 || (iVar7 == 0xd)) || (iVar7 == 0xc)))) {
                if (DAT_004f7084 != (HGDIOBJ)0x0) {
                  hdc = (HDC)param_1[1];
                  h = DAT_004f7084;
                  goto override_prt_431ee4_6059bb06;
                }
              }
              else {
                if ((local_5c == 1) && (DAT_004fb994 != (HGDIOBJ)0x0)) {
                  SelectObject((HDC)param_1[1],DAT_004fb994);
                }
                if ((local_5c == 2) && (DAT_004f1cec != (HGDIOBJ)0x0)) {
                  hdc = (HDC)param_1[1];
                  h = DAT_004f1cec;
override_prt_431ee4_6059bb06:
                  SelectObject(hdc,h);
                }
              }
            }
            if (2 < local_5c) {
              FUN_0041f130(param_1,local_5c);
            }
            if (((((local_50 < 3) ||
                  (uVar5 = (int)uVar1 >> 0x1f,
                  (uVar1 ^ uVar5) == uVar5 || (int)((uVar1 ^ uVar5) - uVar5) < 0)) ||
                 (uVar5 = (int)uVar2 >> 0x1f,
                 (uVar2 ^ uVar5) == uVar5 || (int)((uVar2 ^ uVar5) - uVar5) < 0)) ||
                (uVar5 = (int)(uVar2 - uVar1) >> 0x1f, 999 < (int)((uVar2 - uVar1 ^ uVar5) - uVar5))
                ) || (((iVar7 = *local_54, iVar7 != 1 && (iVar7 != 3)) &&
                      ((iVar7 != 0xb && (iVar7 != 0xd)))))) {
              if ((*local_54 < 10) || (local_50 % 5 != 0)) {
                FUN_00424320(param_1,uVar2,local_58,1);
              }
              else if (DAT_004f7ec4 != (HGDIOBJ)0x0) {
                SelectObject((HDC)param_1[1],DAT_004f7ec4);
              }
LAB_00432012:
              FUN_00424320(param_1,uVar2,local_58,1);
            }
            else {
              FUN_004b4d9d(param_1,local_30,uVar1,local_40);
              CDC::LineTo(param_1,uVar2,local_58);
              if ((9 < *local_54) && (local_50 % 5 == 0)) {
                if (DAT_005359c4 != (HGDIOBJ)0x0) {
                  SelectObject((HDC)param_1[1],DAT_005359c4);
                }
                goto LAB_00432012;
              }
            }
            local_4c = local_4c + 4;
            local_54 = local_54 + 1;
            local_50 = local_50 + 1;
          } while (local_50 <= DAT_00534ea8);
        }
      }
      local_5c = local_5c + 1;
    } while (local_5c <= iVar6);
  }
  local_48 = DAT_004da194;
  if (1 < param_7) {
    local_48 = DAT_004da140;
  }
  local_48 = local_48 + 5;
  if ((DAT_004da1e8 == 1) && (iVar6 = DAT_004da194 + 6, iVar6 <= DAT_004da194 + 7)) {
    local_20 = (double)param_3;
    local_28 = (double)param_2;
    do {
      if (DAT_004f41ec != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f41ec);
      }
      if (DAT_00522f1c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_00522f1c);
      }
      fVar8 = FUN_0043ec20((double)CONCAT44(*(undefined4 *)(&DAT_004f839c + iVar6 * 8),
                                            *(undefined4 *)(&DAT_004f8398 + iVar6 * 8)),
                           (double)CONCAT44(*(undefined4 *)(&DAT_004fb06c + iVar6 * 8),
                                            *(undefined4 *)(&DAT_004fb068 + iVar6 * 8)),param_7,
                           param_8);
      if (_DAT_004cc560 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
        _DAT_004fbb88 = 0;
        _DAT_004fbb8c = 0x40d09a00;
      }
      fVar9 = (float10)fsin(fVar8);
      local_4c = (int)(longlong)
                      (fVar9 * (float10)param_4 *
                       (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) + (float10)local_28);
      fVar8 = (float10)fcos(fVar8);
      local_58 = (int)(longlong)
                      ((float10)local_20 -
                      fVar8 * (float10)param_4 *
                      (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
      FUN_00434c60(param_1,local_4c,local_58,iVar6,param_7,param_8);
      if ((((iVar6 == DAT_004da194 + 6) && (DAT_004f452c == 1)) &&
          (0xa0 - *(int *)(&DAT_004fae60 + param_8 * 4) < *(int *)(&DAT_004fecc8 + param_8 * 4))) &&
         (DAT_004da184 == 1)) {
        FUN_00444890(param_1,local_4c,local_58,0x18,param_8,1,iVar6);
      }
      if (((iVar6 == DAT_004da194 + 7) && (DAT_004f452c == 1)) &&
         ((0xa0 - *(int *)(&DAT_004fae60 + param_8 * 4) < *(int *)(&DAT_004fecc8 + param_8 * 4) &&
          (DAT_004da184 == 1)))) {
        FUN_00444890(param_1,local_4c,local_58,0x19,param_8,1,iVar6);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 <= DAT_004da194 + 7);
  }
  local_5c = 1;
  if (0 < local_48) {
    local_20 = (double)param_3;
    local_28 = (double)param_2;
    do {
      fVar8 = FUN_0043ec20((double)CONCAT44(*(undefined4 *)(&DAT_004f839c + local_5c * 8),
                                            *(undefined4 *)(&DAT_004f8398 + local_5c * 8)),
                           (double)CONCAT44(*(undefined4 *)(&DAT_004fb06c + local_5c * 8),
                                            *(undefined4 *)(&DAT_004fb068 + local_5c * 8)),param_7,
                           param_8);
      if (_DAT_004cc560 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
        _DAT_004fbb88 = 0;
        _DAT_004fbb8c = 0x40d09a00;
      }
      fVar9 = (float10)fsin(fVar8);
      iVar6 = (int)(longlong)
                   (fVar9 * (float10)param_4 *
                    (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) + (float10)local_28);
      fVar8 = (float10)fcos(fVar8);
      iVar7 = (int)(longlong)
                   ((float10)local_20 -
                   fVar8 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                   );
      if (local_5c == 1) {
        local_58 = iVar6;
        local_40 = iVar7;
      }
      if (local_5c == 2) {
        local_4c = iVar6;
        local_44 = iVar7;
      }
      if (5 < local_5c) {
        iVar3 = local_5c + -5;
        if (((iVar3 == param_8) && (0 < param_7)) &&
           ((param_7 < 3 && (*(int *)(&DAT_004fe638 + param_8 * 4) == 0)))) {
          if (DAT_004fe174 != (HGDIOBJ)0x0) {
            SelectObject((HDC)param_1[1],DAT_004fe174);
          }
          FUN_004b4d9d(param_1,local_18,iVar6,iVar7);
          local_50 = local_38;
          iVar4 = local_3c;
          if (((DAT_0053527c == 0) && (*(int *)(&DAT_004f8538 + param_8 * 4) == DAT_004da1e4)) &&
             (*(int *)(&DAT_004fbf10 + param_8 * 4) == 0)) {
            local_50 = (local_44 + local_40) / 2;
            iVar4 = (local_4c + local_58) / 2;
          }
          if (((DAT_0053527c == 1) && (*(int *)(&DAT_004f8538 + param_8 * 4) == DAT_004da1e4)) &&
             ((1 < *(int *)(&DAT_004fbf10 + param_8 * 4) && (DAT_004da194 < 0xf)))) {
            iVar4 = (local_4c + local_58) / 2;
            local_50 = (local_44 + local_40) / 2;
          }
          if (((param_9 < iVar4) && (iVar4 < param_11)) && (local_50 < param_12)) {
            CDC::LineTo(param_1,iVar4,local_50);
          }
          if (((*(int *)(&DAT_004fecc8 + param_8 * 4) < DAT_004f7200 + 10) && (param_7 == 1)) &&
             (DAT_004da184 == 1)) {
            FUN_00444890(param_1,iVar6,iVar7,3,param_8,1,local_5c);
          }
          if (((0xa5 - *(int *)(&DAT_004fae60 + param_8 * 4) < *(int *)(&DAT_004fecc8 + param_8 * 4)
               ) && (param_7 == 1)) && (DAT_004da184 == 1)) {
            FUN_00444890(param_1,iVar6,iVar7,3,param_8,1,local_5c);
          }
        }
        if (*(int *)(&DAT_0050f6d0 + param_8 * 4) < 8) {
          if (((param_7 == 1) && (iVar6 < param_11)) &&
             ((param_9 < iVar6 && ((param_10 < iVar7 && (iVar7 < param_12)))))) {
            FUN_00433f70(param_1,iVar6,iVar7,iVar3,param_8);
          }
          if (7 < *(int *)(&DAT_0050f6d0 + param_8 * 4)) goto LAB_0043251d;
        }
        else {
LAB_0043251d:
          if ((((param_7 == 1) && (iVar6 < param_11)) && (param_9 < iVar6)) &&
             ((param_10 < iVar7 && (iVar7 < param_12)))) {
            FUN_00433aa0(param_1,iVar6,iVar7,iVar3,param_8,1);
          }
        }
        if ((1 < param_7) && (FUN_00433aa0(param_1,iVar6,iVar7,iVar3,1,param_7), DAT_004da140 == 2))
        {
          FUN_00433aa0(param_1,iVar6,iVar7,iVar3,2,param_7);
        }
      }
      if (local_5c < 6) {
        if (local_5c == DAT_005230b8) {
          local_3c = iVar6;
          local_38 = iVar7;
        }
        if ((((local_5c == 3) && (0 < param_7)) && (param_7 < 3)) &&
           ((*(int *)(&DAT_004fbf10 + param_8 * 4) < 3 &&
            (*(int *)(&DAT_004f8538 + param_8 * 4) < 8)))) {
          if ((*(int *)(&DAT_004fecc8 + param_8 * 4) < 0x46) && (DAT_004da184 == 1)) {
            FUN_00444890(param_1,iVar6,iVar7,1,param_8,1,3);
          }
          if (((0xa5 - *(int *)(&DAT_004fae60 + param_8 * 4) < *(int *)(&DAT_004fecc8 + param_8 * 4)
               ) && (DAT_004da19c == 8)) && (DAT_004da184 == 1)) {
            FUN_00444890(param_1,iVar6,iVar7,2,param_8,1,3);
          }
        }
        if ((((local_5c == 4) && (*(int *)(&DAT_004fbf10 + param_8 * 4) == 2)) && (0 < param_7)) &&
           (param_7 < 3)) {
          if ((*(int *)(&DAT_004fecc8 + param_8 * 4) < DAT_004f7200 + 10) && (DAT_004da184 == 1)) {
            FUN_00444890(param_1,iVar6,iVar7,1,param_8,1,4);
          }
          if ((0xa0 - *(int *)(&DAT_004fae60 + param_8 * 4) < *(int *)(&DAT_004fecc8 + param_8 * 4))
             && (DAT_004da184 == 1)) {
            FUN_00444890(param_1,iVar6,iVar7,2,param_8,1,4);
          }
        }
        if ((((*(int *)(&DAT_004f8538 + param_8 * 4) < DAT_004da1e4 + -2) || (DAT_0053527c == 0)) &&
            (DAT_004f452c == 0)) && (local_5c == 5)) {
          if (((*(int *)(&DAT_004fbf10 + param_8 * 4) == 3) && (DAT_004da168 == 0)) &&
             ((0 < param_7 && (param_7 < 3)))) {
            if ((*(int *)(&DAT_004fecc8 + param_8 * 4) < DAT_004f7200 + 10) && (DAT_004da184 == 1))
            {
              FUN_00444890(param_1,iVar6,iVar7,1,param_8,1,5);
            }
            if ((0xa0 - *(int *)(&DAT_004fae60 + param_8 * 4) <
                 *(int *)(&DAT_004fecc8 + param_8 * 4)) && (DAT_004da184 == 1)) {
              FUN_00444890(param_1,iVar6,iVar7,2,param_8,1,5);
            }
          }
          if ((((*(int *)(&DAT_004fbf10 + param_8 * 4) == 3) && (DAT_004da168 == 1)) &&
              (0xe < DAT_004da194)) && (((0 < param_7 && (param_7 < 3)) && (DAT_004f452c == 0)))) {
            if ((*(int *)(&DAT_004fecc8 + param_8 * 4) < DAT_004f7200 + 10) && (DAT_004da184 == 1))
            {
              FUN_00444890(param_1,iVar6,iVar7,1,param_8,1,5);
            }
            if ((0xa0 - *(int *)(&DAT_004fae60 + param_8 * 4) <
                 *(int *)(&DAT_004fecc8 + param_8 * 4)) && (DAT_004da184 == 1)) {
              FUN_00444890(param_1,iVar6,iVar7,2,param_8,1,5);
            }
          }
        }
        if ((((local_5c == 2) && (*(int *)(&DAT_004fbf10 + param_8 * 4) == 0)) && (0 < param_7)) &&
           (((param_7 < 3 && (*(int *)(&DAT_004fecc8 + param_8 * 4) < 0x5a)) && (DAT_004da184 == 1))
           )) {
          if (DAT_0053646c == 1) {
            iVar3 = 5;
          }
          else {
            iVar3 = 4;
          }
          FUN_00444890(param_1,iVar6,iVar7,iVar3,param_8,1,2);
        }
        if (((local_5c == 1) && (*(int *)(&DAT_004fbf10 + param_8 * 4) == 0)) &&
           ((0 < param_7 &&
            (((param_7 < 3 && (*(int *)(&DAT_004fecc8 + param_8 * 4) < 0x5a)) && (DAT_004da184 == 1)
             ))))) {
          if (DAT_0053646c == 1) {
            iVar3 = 4;
          }
          else {
            iVar3 = 5;
          }
          FUN_00444890(param_1,iVar6,iVar7,iVar3,param_8,1,1);
        }
        if (((local_5c == 2) && (DAT_004da1e4 + -2 <= *(int *)(&DAT_004f8538 + param_8 * 4))) &&
           ((((DAT_0053527c == 1 && ((0 < param_7 && (param_7 < 3)))) && (DAT_004f452c == 0)) &&
            ((0xa0 - *(int *)(&DAT_004fae60 + param_8 * 4) < *(int *)(&DAT_004fecc8 + param_8 * 4)
             && (DAT_004da184 == 1)))))) {
          if ((DAT_0053646c == 1) && (2 < DAT_004da194)) {
            iVar3 = 0x18;
          }
          else {
            iVar3 = 0x19;
          }
          FUN_00444890(param_1,iVar6,iVar7,iVar3,param_8,1,2);
        }
        if ((((((local_5c == 1) && (DAT_004da1e4 + -2 <= *(int *)(&DAT_004f8538 + param_8 * 4))) &&
              (DAT_0053527c == 1)) && ((0 < param_7 && (param_7 < 3)))) && (DAT_004f452c == 0)) &&
           ((0xa0 - *(int *)(&DAT_004fae60 + param_8 * 4) < *(int *)(&DAT_004fecc8 + param_8 * 4) &&
            (DAT_004da184 == 1)))) {
          if ((DAT_0053646c == 1) && (2 < DAT_004da194)) {
            iVar3 = 0x19;
          }
          else {
            iVar3 = 0x18;
          }
          FUN_00444890(param_1,iVar6,iVar7,iVar3,param_8,1,1);
        }
        if ((((iVar6 < param_11) && (param_9 < iVar6)) && (param_10 < iVar7)) && (iVar7 < param_12))
        {
          FUN_00434c60(param_1,iVar6,iVar7,local_5c,param_7,param_8);
        }
        if (2 < param_7) {
          FUN_00443620(param_1,local_5c,iVar6,iVar7);
        }
      }
      if (local_5c == 1) {
        local_34 = iVar7;
        local_30[0] = iVar6;
      }
      if ((local_5c == 2) && (DAT_004f8cd0 < 1)) {
        (**(code **)(*param_1 + 0x2c))(param_1,7);
        FUN_004b4d9d(param_1,aiStack_10,local_30[0],local_34);
        CDC::LineTo(param_1,iVar6,iVar7);
      }
      local_5c = local_5c + 1;
    } while (local_5c <= local_48);
  }
  return;
}

