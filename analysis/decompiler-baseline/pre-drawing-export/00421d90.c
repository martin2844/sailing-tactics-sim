
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00421d90(CDC *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,int param_8,uint param_9,int param_10,int param_11
            ,int param_12,int param_13)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  int local_44;
  int local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_18 [2];
  int aiStack_10 [3];
  
  if ((DAT_004ac98c == 0) && ((param_8 == 1 || (param_8 == 2)))) {
    iVar3 = 1;
    iVar4 = 0;
    do {
      fVar6 = FUN_0042c400(*(double *)((int)&DAT_004abd90 + iVar4),
                           *(double *)((int)&DAT_004a4730 + iVar4),param_8,param_9);
      if (_DAT_00484d38 < (double)CONCAT44(_DAT_004a682c,_DAT_004a6828)) {
        _DAT_004a6828 = 0;
        _DAT_004a682c = 0x40bb5800;
      }
      fVar7 = (float10)fcos(fVar6);
      fVar6 = (float10)fsin(fVar6);
      FUN_00431890(param_1,iVar3,param_9,param_4,param_5,
                   (int)(longlong)
                        (fVar6 * (float10)(double)CONCAT44(param_5,param_4) *
                         (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828) + (float10)param_2),
                   (int)(longlong)
                        ((float10)param_3 -
                        fVar7 * (float10)(double)CONCAT44(param_5,param_4) *
                        (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828)),param_10,param_11,
                   param_12,param_13,param_8);
      iVar4 = iVar4 + 8;
      iVar3 = iVar3 + 1;
    } while (iVar4 < 0x21);
  }
  if ((DAT_004ac958 == 1) && (param_8 == 1)) {
    iVar3 = 2;
    if (DAT_0049118c != 2) {
      iVar3 = DAT_00491140;
    }
    local_44 = 1;
    if (0 < iVar3) {
      do {
        if (((local_44 == 1) && (DAT_004ac92c == 1)) && (DAT_004a4ee4 != (HGDIOBJ)0x0)) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
        }
        if (((local_44 == 2) && (DAT_004ac92c == 1)) && (DAT_004a4dec != (HGDIOBJ)0x0)) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
        }
        if (((local_44 == 1) && (DAT_004ac92c == 0)) && (DAT_004a676c != (HGDIOBJ)0x0)) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a676c);
        }
        if (((local_44 == 2) && (DAT_004ac92c == 0)) && (DAT_004a39fc != (HGDIOBJ)0x0)) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a39fc);
        }
        iVar4 = 1;
        if (0 < DAT_004ab9d8) {
          iVar5 = local_44 * 0x25c;
          do {
            fVar6 = FUN_0042c400((double)*(int *)((int)&DAT_004a9a0c + iVar5),
                                 (double)*(int *)((int)&DAT_004ab1a4 + iVar5),1,param_9);
            if (_DAT_00484d38 < (double)CONCAT44(_DAT_004a682c,_DAT_004a6828)) {
              _DAT_004a6828 = 0;
              _DAT_004a682c = 0x40bb5800;
            }
            fVar7 = (float10)fcos(fVar6);
            fVar6 = (float10)fsin(fVar6);
            FUN_00419d50(param_1,(int)(longlong)
                                      (fVar6 * (float10)(double)CONCAT44(param_5,param_4) *
                                       (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828) +
                                      (float10)param_2),
                         (int)(longlong)
                              ((float10)param_3 -
                              fVar7 * (float10)(double)CONCAT44(param_5,param_4) *
                              (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828)),1);
            iVar4 = iVar4 + 1;
            iVar5 = iVar5 + 4;
          } while (iVar4 <= DAT_004ab9d8);
        }
        local_44 = local_44 + 1;
      } while (local_44 <= iVar3);
    }
  }
  iVar3 = DAT_0049118c;
  if (1 < param_8) {
    iVar3 = DAT_00491140;
  }
  local_44 = 1;
  if (0 < iVar3 + 5) {
    do {
      fVar6 = FUN_0042c400((double)CONCAT44(*(undefined4 *)(&DAT_004a52f4 + local_44 * 8),
                                            *(undefined4 *)(&DAT_004a52f0 + local_44 * 8)),
                           (double)CONCAT44(*(undefined4 *)(&DAT_004a60b4 + local_44 * 8),
                                            *(undefined4 *)(&DAT_004a60b0 + local_44 * 8)),param_8,
                           param_9);
      if (_DAT_00484d38 < (double)CONCAT44(_DAT_004a682c,_DAT_004a6828)) {
        _DAT_004a6828 = 0;
        _DAT_004a682c = 0x40bb5800;
      }
      fVar7 = (float10)fsin(fVar6);
      iVar4 = (int)(longlong)
                   (fVar7 * (float10)(double)CONCAT44(param_5,param_4) *
                    (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828) + (float10)param_2);
      fVar6 = (float10)fcos(fVar6);
      uVar1 = (uint)(longlong)
                    ((float10)param_3 -
                    fVar6 * (float10)(double)CONCAT44(param_5,param_4) *
                    (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828));
      if (local_44 < 6) {
        if (local_44 == DAT_004aa7e0) {
          local_38 = iVar4;
          local_34 = uVar1;
        }
        if (((local_44 == 3) && (0 < param_8)) &&
           ((param_8 < 3 && (*(int *)(&DAT_004a6ba0 + param_9 * 4) == 1)))) {
          if ((*(int *)(&DAT_004a7bc8 + param_9 * 4) < 0x46) && (DAT_0049117c == 1)) {
            FUN_00431440(param_1,iVar4,uVar1,1,param_9,1);
          }
          if (((0xa5 - *(int *)(&DAT_004a5f10 + param_9 * 4) < *(int *)(&DAT_004a7bc8 + param_9 * 4)
               ) && (DAT_00491194 == 8)) && (DAT_0049117c == 1)) {
            FUN_00431440(param_1,iVar4,uVar1,2,param_9,1);
          }
        }
        if (((local_44 == 4) && (*(int *)(&DAT_004a6ba0 + param_9 * 4) == 2)) &&
           ((0 < param_8 && (param_8 < 3)))) {
          if ((*(int *)(&DAT_004a7bc8 + param_9 * 4) < DAT_004a4eb0 + 10) && (DAT_0049117c == 1)) {
            FUN_00431440(param_1,iVar4,uVar1,1,param_9,1);
          }
          if ((0xa0 - *(int *)(&DAT_004a5f10 + param_9 * 4) < *(int *)(&DAT_004a7bc8 + param_9 * 4))
             && (DAT_0049117c == 1)) {
            FUN_00431440(param_1,iVar4,uVar1,2,param_9,1);
          }
        }
        if (local_44 == 5) {
          if ((((*(int *)(&DAT_004a6ba0 + param_9 * 4) == 3) && (DAT_00491160 == 0)) &&
              (0 < param_8)) && (param_8 < 3)) {
            if ((*(int *)(&DAT_004a7bc8 + param_9 * 4) < DAT_004a4eb0 + 10) && (DAT_0049117c == 1))
            {
              FUN_00431440(param_1,iVar4,uVar1,1,param_9,1);
            }
            if ((0xa0 - *(int *)(&DAT_004a5f10 + param_9 * 4) <
                 *(int *)(&DAT_004a7bc8 + param_9 * 4)) && (DAT_0049117c == 1)) {
              FUN_00431440(param_1,iVar4,uVar1,2,param_9,1);
            }
          }
          if ((((*(int *)(&DAT_004a6ba0 + param_9 * 4) == 3) && (DAT_00491160 == 1)) &&
              (0xe < DAT_0049118c)) && ((0 < param_8 && (param_8 < 3)))) {
            if ((*(int *)(&DAT_004a7bc8 + param_9 * 4) < DAT_004a4eb0 + 10) && (DAT_0049117c == 1))
            {
              FUN_00431440(param_1,iVar4,uVar1,1,param_9,1);
            }
            if ((0xa0 - *(int *)(&DAT_004a5f10 + param_9 * 4) <
                 *(int *)(&DAT_004a7bc8 + param_9 * 4)) && (DAT_0049117c == 1)) {
              FUN_00431440(param_1,iVar4,uVar1,2,param_9,1);
            }
          }
        }
        if ((((local_44 == 2) && (*(int *)(&DAT_004a6ba0 + param_9 * 4) == 0)) && (0 < param_8)) &&
           (((param_8 < 3 && (*(int *)(&DAT_004a7bc8 + param_9 * 4) < 0x5a)) && (DAT_0049117c == 1))
           )) {
          if (DAT_004ac9a8 == 1) {
            iVar5 = 5;
          }
          else {
            iVar5 = 4;
          }
          FUN_00431440(param_1,iVar4,uVar1,iVar5,param_9,1);
        }
        if (((local_44 == 1) && (*(int *)(&DAT_004a6ba0 + param_9 * 4) == 0)) &&
           ((0 < param_8 &&
            (((param_8 < 3 && (*(int *)(&DAT_004a7bc8 + param_9 * 4) < 0x5a)) && (DAT_0049117c == 1)
             ))))) {
          if (DAT_004ac9a8 == 1) {
            iVar5 = 4;
          }
          else {
            iVar5 = 5;
          }
          FUN_00431440(param_1,iVar4,uVar1,iVar5,param_9,1);
        }
        if (((iVar4 < param_12) && (param_10 < iVar4)) &&
           ((param_11 < (int)uVar1 && ((int)uVar1 < param_13)))) {
          FUN_00424890(param_1,iVar4,uVar1,local_44,param_8);
        }
        if (2 < param_8) {
          FUN_00430570(param_1,local_44,iVar4,uVar1);
        }
      }
      else {
        uVar2 = local_44 - 5;
        if (((uVar2 == param_9) && (0 < param_8)) && (param_8 < 3)) {
          if (DAT_004a71bc != (HGDIOBJ)0x0) {
            SelectObject(*(HDC *)(param_1 + 4),DAT_004a71bc);
          }
          FUN_004706bd(param_1,local_18,iVar4,uVar1);
          CDC::LineTo(param_1,local_38,local_34);
          if (((*(int *)(&DAT_004a7bc8 + param_9 * 4) < DAT_004a4eb0 + 10) && (param_8 == 1)) &&
             (DAT_0049117c == 1)) {
            FUN_00431440(param_1,iVar4,uVar1,3,param_9,1);
          }
          if (((0xa5 - *(int *)(&DAT_004a5f10 + param_9 * 4) < *(int *)(&DAT_004a7bc8 + param_9 * 4)
               ) && (param_8 == 1)) && (DAT_0049117c == 1)) {
            FUN_00431440(param_1,iVar4,uVar1,3,param_9,1);
          }
        }
        if (((*(int *)(&DAT_004a8660 + param_9 * 4) < 8) && (param_8 == 1)) &&
           ((iVar4 < param_12 &&
            (((param_10 < iVar4 && (param_11 < (int)uVar1)) && ((int)uVar1 < param_13)))))) {
          FUN_00423aa0(param_1,iVar4,uVar1,uVar2,param_9);
        }
        if ((((7 < *(int *)(&DAT_004a8660 + param_9 * 4)) && (param_8 == 1)) &&
            ((iVar4 < param_12 && ((param_10 < iVar4 && (param_11 < (int)uVar1)))))) &&
           ((int)uVar1 < param_13)) {
          FUN_00423670(param_1,iVar4,uVar1,uVar2,param_9,1);
        }
        if ((1 < param_8) && (FUN_00423670(param_1,iVar4,uVar1,uVar2,1,param_8), DAT_00491140 == 2))
        {
          FUN_00423670(param_1,iVar4,uVar1,uVar2,2,param_8);
        }
      }
      if (local_44 == 1) {
        local_30 = uVar1;
        local_2c = iVar4;
      }
      if ((local_44 == 2) && (DAT_004a5b80 < 1)) {
        (**(code **)(*(int *)param_1 + 0x2c))(7);
        FUN_004706bd(param_1,aiStack_10,local_2c,local_30);
        CDC::LineTo(param_1,iVar4,uVar1);
      }
      local_44 = local_44 + 1;
    } while (local_44 <= iVar3 + 5);
  }
  return;
}

