
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0043efd0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  COLORREF CVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  int local_8 [2];
  
  iVar3 = param_2;
  piVar2 = param_1;
  iVar6 = 1;
  if (DAT_004da1e8 == 1) {
    iVar4 = DAT_004da194 + 7;
  }
  else {
    iVar4 = DAT_004da194 + 5;
  }
  if (0 < iVar4) {
    iVar8 = 0;
    iVar7 = 0;
    do {
      FUN_0043e730(iVar6,*(double *)((int)&DAT_004f83a0 + iVar8),
                   *(double *)((int)&DAT_004fb070 + iVar8),param_2,0);
      *(undefined4 *)((int)&DAT_004fc164 + iVar7) = *(undefined4 *)((int)&DAT_00523664 + iVar7);
      iVar6 = iVar6 + 1;
      iVar8 = iVar8 + 8;
      iVar7 = iVar7 + 4;
    } while (iVar6 <= iVar4);
  }
  FUN_0043f9f0(0);
  if (DAT_004f8cd0 < 1) {
    FUN_0043ed70(param_1,param_3,param_5,param_6,param_2);
  }
  if (*(int *)(&DAT_004fe638 + param_2 * 4) == 0) {
    if (DAT_004fe174 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe174);
    }
    iVar6 = DAT_004fed74;
    iVar7 = DAT_0052367c;
    if (param_2 == 1) {
      iVar6 = DAT_004fed70;
      iVar7 = DAT_00523678;
    }
    FUN_004b4d9d(param_1,local_8,iVar6,iVar7);
    iVar6 = (&DAT_004fed58)[DAT_005230b8];
    iVar7 = (&DAT_00523660)[DAT_005230b8];
    if (((DAT_0053527c == 0) && (*(int *)(&DAT_004f8538 + param_2 * 4) == DAT_004da1e4)) &&
       (*(int *)(&DAT_004fbf10 + param_2 * 4) == 0)) {
      iVar6 = (DAT_004fed5c + DAT_004fed60) / 2;
      iVar7 = (DAT_00523664 + DAT_00523668) / 2;
    }
    if (((DAT_0053527c == 1) && (*(int *)(&DAT_004f8538 + param_2 * 4) == DAT_004da1e4)) &&
       ((1 < *(int *)(&DAT_004fbf10 + param_2 * 4) && (DAT_004da194 < 0xf)))) {
      iVar6 = (DAT_004fed5c + DAT_004fed60) / 2;
      iVar7 = (DAT_00523664 + DAT_00523668) / 2;
    }
    if (((iVar6 < 1) || (DAT_004fe624 <= iVar6)) || (DAT_00535564 <= iVar7)) {
      local_8[0] = ((2 < *(int *)(&DAT_004f71c0 + param_2 * 4)) - 1 & 0x96) + 0x96;
      fVar9 = FUN_0043ec20((double)CONCAT44(*(undefined4 *)(&DAT_004f839c + DAT_005230b8 * 8),
                                            *(undefined4 *)(&DAT_004f8398 + DAT_005230b8 * 8)),
                           (double)CONCAT44(*(undefined4 *)(&DAT_004fb06c + DAT_005230b8 * 8),
                                            *(undefined4 *)(&DAT_004fb068 + DAT_005230b8 * 8)),-1,
                           param_2);
      iVar8 = FUN_0041bc20(6 - (int)(longlong)(fVar9 * (float10)_DAT_004cc3e8));
      iVar7 = param_6;
      iVar6 = param_6;
      if (param_2 == 1) {
        iVar7 = DAT_00523678 - (DAT_004fe624 * (&DAT_004f1740)[iVar8]) / local_8[0];
        iVar6 = DAT_004fed70 - (DAT_004fe624 * (&DAT_004f85c8)[iVar8]) / 100;
      }
      if (param_2 == 2) {
        iVar6 = DAT_004fed74 - (DAT_004fe624 * (&DAT_004f85c8)[iVar8]) / 100;
        iVar7 = DAT_0052367c - (DAT_004fe624 * (&DAT_004f1740)[iVar8]) / local_8[0];
      }
      if (iVar7 < param_7) {
        iVar7 = param_7;
      }
    }
    CDC::LineTo(param_1,iVar6,iVar7);
  }
  param_1 = (int *)0x1;
  if (0 < iVar4) {
    do {
      iVar6 = *(int *)(&DAT_004f4778 + (int)param_1 * 4);
      CVar5 = GetPixel((HDC)piVar2[1],(&DAT_004fed58)[iVar6],(&DAT_00523660)[iVar6] + 1);
      if ((CVar5 != 0x8000) &&
         (CVar5 = GetPixel((HDC)piVar2[1],(&DAT_004fed58)[iVar6],(&DAT_00523660)[iVar6] + 2),
         CVar5 != 0x8000)) {
        if ((DAT_004da184 == 1) && (*(int *)(&DAT_004fe638 + iVar3 * 4) == 0)) {
          if (((iVar6 == 3) && (*(int *)(&DAT_004fbf10 + iVar3 * 4) < 3)) &&
             (*(int *)(&DAT_004f8538 + iVar3 * 4) < 8)) {
            if (*(int *)(&DAT_004fecc8 + iVar3 * 4) < DAT_004f7200 + 10) {
              FUN_00444890(piVar2,DAT_004fed64,DAT_0052366c,1,iVar3,0,3);
            }
            if ((0xa0 - *(int *)(&DAT_004fae60 + iVar3 * 4) < *(int *)(&DAT_004fecc8 + iVar3 * 4))
               && (DAT_004da19c == 8)) {
              FUN_00444890(piVar2,DAT_004fed64,DAT_0052366c,2,iVar3,0,3);
            }
          }
          if ((iVar6 == 4) && (*(int *)(&DAT_004fbf10 + iVar3 * 4) == 2)) {
            if (*(int *)(&DAT_004fecc8 + iVar3 * 4) < DAT_004f7200 + 10) {
              FUN_00444890(piVar2,DAT_004fed68,DAT_00523670,1,iVar3,0,4);
            }
            if (0xa5 - *(int *)(&DAT_004fae60 + iVar3 * 4) < *(int *)(&DAT_004fecc8 + iVar3 * 4)) {
              FUN_00444890(piVar2,DAT_004fed68,DAT_00523670,2,iVar3,0,4);
            }
          }
          if (((*(int *)(&DAT_004f8538 + iVar3 * 4) < DAT_004da1e4 + -2) || (DAT_0053527c == 0)) &&
             (iVar6 == 5)) {
            if (((*(int *)(&DAT_004fbf10 + iVar3 * 4) == 3) && (DAT_004da168 == 0)) &&
               (DAT_004f452c == 0)) {
              if (*(int *)(&DAT_004fecc8 + iVar3 * 4) < DAT_004f7200 + 10) {
                FUN_00444890(piVar2,DAT_004fed6c,DAT_00523674,1,iVar3,0,5);
              }
              if (0xa0 - *(int *)(&DAT_004fae60 + iVar3 * 4) < *(int *)(&DAT_004fecc8 + iVar3 * 4))
              {
                FUN_00444890(piVar2,DAT_004fed6c,DAT_00523674,2,iVar3,0,5);
              }
            }
            if (((*(int *)(&DAT_004fbf10 + iVar3 * 4) == 3) && (DAT_004da168 == 1)) &&
               ((0xe < DAT_004da194 && (DAT_004f452c == 0)))) {
              if (*(int *)(&DAT_004fecc8 + iVar3 * 4) < DAT_004f7200) {
                FUN_00444890(piVar2,DAT_004fed6c,DAT_00523674,1,iVar3,0,5);
              }
              if (0xa0 - *(int *)(&DAT_004fae60 + iVar3 * 4) < *(int *)(&DAT_004fecc8 + iVar3 * 4))
              {
                FUN_00444890(piVar2,DAT_004fed6c,DAT_00523674,2,iVar3,0,5);
              }
            }
          }
          if (((iVar6 == DAT_004da194 + 6) && (DAT_004f452c == 1)) &&
             (0xa0 - *(int *)(&DAT_004fae60 + iVar3 * 4) < *(int *)(&DAT_004fecc8 + iVar3 * 4))) {
            FUN_00444890(piVar2,(&DAT_004fed58)[iVar6],(&DAT_00523660)[iVar6],0x18,iVar3,0,iVar6);
          }
          if (((iVar6 == DAT_004da194 + 7) && (DAT_004f452c == 1)) &&
             (0xa0 - *(int *)(&DAT_004fae60 + iVar3 * 4) < *(int *)(&DAT_004fecc8 + iVar3 * 4))) {
            FUN_00444890(piVar2,(&DAT_004fed58)[iVar6],(&DAT_00523660)[iVar6],0x19,iVar3,0,iVar6);
          }
          if (((iVar6 == 2) && (*(int *)(&DAT_004fbf10 + iVar3 * 4) == 0)) &&
             (*(int *)(&DAT_004fecc8 + iVar3 * 4) < 0x5a)) {
            if (DAT_0053646c == 1) {
              iVar7 = 5;
            }
            else {
              iVar7 = 4;
            }
            FUN_00444890(piVar2,DAT_004fed60,DAT_00523668,iVar7,iVar3,0,2);
          }
          if (((iVar6 == 1) && (*(int *)(&DAT_004fbf10 + iVar3 * 4) == 0)) &&
             (*(int *)(&DAT_004fecc8 + iVar3 * 4) < 0x5a)) {
            if (DAT_0053646c == 1) {
              iVar7 = 4;
            }
            else {
              iVar7 = 5;
            }
            FUN_00444890(piVar2,DAT_004fed5c,DAT_00523664,iVar7,iVar3,0,1);
          }
          if (((iVar6 == 2) && (DAT_004da1e4 + -2 <= *(int *)(&DAT_004f8538 + iVar3 * 4))) &&
             (((DAT_0053527c == 1 &&
               ((DAT_004f452c == 0 &&
                (0xa0 - *(int *)(&DAT_004fae60 + iVar3 * 4) < *(int *)(&DAT_004fecc8 + iVar3 * 4))))
               ) && (DAT_004da184 == 1)))) {
            if ((DAT_0053646c == 1) && (2 < DAT_004da194)) {
              iVar7 = 0x18;
            }
            else {
              iVar7 = 0x19;
            }
            FUN_00444890(piVar2,DAT_004fed60,DAT_00523668,iVar7,iVar3,0,2);
          }
          if (((((iVar6 == 1) && (DAT_004da1e4 + -2 <= *(int *)(&DAT_004f8538 + iVar3 * 4))) &&
               (DAT_0053527c == 1)) &&
              ((DAT_004f452c == 0 &&
               (0xa0 - *(int *)(&DAT_004fae60 + iVar3 * 4) < *(int *)(&DAT_004fecc8 + iVar3 * 4)))))
             && (DAT_004da184 == 1)) {
            if ((DAT_0053646c == 1) && (2 < DAT_004da194)) {
              iVar7 = 0x19;
            }
            else {
              iVar7 = 0x18;
            }
            FUN_00444890(piVar2,DAT_004fed5c,DAT_00523664,iVar7,iVar3,0,1);
          }
        }
        if (iVar6 < 6) {
          fVar9 = FUN_00481350((int)(longlong)DAT_004f6b00,(int)(longlong)DAT_004f6c18,
                               (int)(longlong)*(double *)(&DAT_004f8398 + iVar6 * 8),
                               (int)(longlong)*(double *)(&DAT_004fb068 + iVar6 * 8));
          param_2 = (int)(longlong)fVar9;
          if (DAT_004da19c == 8) {
            param_2 = param_2 / 3;
          }
          if ((((iVar6 < 6) && (iVar7 = (&DAT_004fed58)[iVar6], iVar7 < param_5)) &&
              (param_3 < iVar7)) && (((int)(&DAT_00523660)[iVar6] <= param_6 && (param_2 < 0xfa))))
          {
            if ((iVar6 == 2) && (DAT_005364c8 != 1)) {
              FUN_0043fed0();
              FUN_00417aa0(piVar2,DAT_004fed60,DAT_00523668,0,iVar3,param_6,param_7);
            }
            else {
              FUN_0043faa0(piVar2,iVar7,(&DAT_00523660)[iVar6],iVar6,iVar3);
            }
          }
        }
        if (((iVar6 == DAT_004da194 + 6) || (iVar6 == DAT_004da194 + 7)) &&
           ((iVar7 = (&DAT_004fed58)[iVar6], iVar7 < param_5 &&
            ((param_3 < iVar7 && ((int)(&DAT_00523660)[iVar6] <= param_6)))))) {
          FUN_0043faa0(piVar2,iVar7,(&DAT_00523660)[iVar6],iVar6,iVar3);
        }
        if (5 < iVar6) {
          if ((((iVar6 < DAT_004da194 + 6) && (iVar7 = (&DAT_004fed58)[iVar6], iVar7 < param_5)) &&
              (param_3 < iVar7)) && ((int)(&DAT_00523660)[iVar6] <= param_6)) {
            iVar8 = iVar6 + -5;
            FUN_00417aa0(piVar2,iVar7,(&DAT_00523660)[iVar6],iVar8,iVar3,param_6,param_7);
            uVar1 = (&DAT_00523660)[iVar6];
            *(undefined4 *)(&DAT_005230f0 + iVar8 * 4) = (&DAT_004fed58)[iVar6];
            *(undefined4 *)(&DAT_00522c20 + iVar8 * 4) = uVar1;
          }
          if (((5 < iVar6) && (iVar6 < DAT_004da194 + 6)) &&
             ((param_5 <= (int)(&DAT_004fed58)[iVar6] ||
              (((int)(&DAT_004fed58)[iVar6] <= param_3 || (param_6 < (int)(&DAT_00523660)[iVar6]))))
             )) {
            (&DAT_005230dc)[iVar6] = 0xffffff9c;
            *(undefined4 *)(&DAT_00522c0c + iVar6 * 4) = 0xffffff9c;
          }
        }
      }
      param_1 = (int *)((int)param_1 + 1);
    } while ((int)param_1 <= iVar4);
  }
  return;
}

