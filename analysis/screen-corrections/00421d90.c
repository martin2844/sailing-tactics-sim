
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00421d90(int param_1,int param_2,int param_3,double param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11,int param_12)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  int iVar7;
  int local_44;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_18 [2];
  int aiStack_10 [3];
  
  if ((DAT_004ac98c == 0) && ((param_7 == 1 || (param_7 == 2)))) {
    iVar2 = 1;
    iVar3 = 0;
    do {
      fVar5 = FUN_0042c400(*(double *)((int)&DAT_004abd90 + iVar3),
                           *(double *)((int)&DAT_004a4730 + iVar3),param_7,param_8);
      if (_DAT_00484d38 < (double)CONCAT44(_DAT_004a682c,_DAT_004a6828)) {
        _DAT_004a6828 = 0;
        _DAT_004a682c = 0x40bb5800;
      }
      fVar6 = (float10)fcos(fVar5);
      fVar5 = (float10)fsin(fVar5);
      FUN_00431890(param_1,iVar2,param_8,param_4,
                   (int)(longlong)
                        (fVar5 * (float10)param_4 *
                         (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828) + (float10)param_2),
                   (int)(longlong)
                        ((float10)param_3 -
                        fVar6 * (float10)param_4 *
                        (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828)),param_9,param_10,
                   param_11,param_12,param_7);
      iVar3 = iVar3 + 8;
      iVar2 = iVar2 + 1;
    } while (iVar3 < 0x21);
  }
  if ((DAT_004ac958 == 1) && (param_7 == 1)) {
    iVar2 = 2;
    if (DAT_0049118c != 2) {
      iVar2 = DAT_00491140;
    }
    local_44 = 1;
    if (0 < iVar2) {
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
        iVar3 = 1;
        if (0 < DAT_004ab9d8) {
          iVar4 = local_44 * 0x25c;
          do {
            fVar5 = FUN_0042c400((double)*(int *)((int)&DAT_004a9a0c + iVar4),
                                 (double)*(int *)((int)&DAT_004ab1a4 + iVar4),1,param_8);
            if (_DAT_00484d38 < (double)CONCAT44(_DAT_004a682c,_DAT_004a6828)) {
              _DAT_004a6828 = 0;
              _DAT_004a682c = 0x40bb5800;
            }
            fVar6 = (float10)fcos(fVar5);
            fVar5 = (float10)fsin(fVar5);
            FUN_00419d50((CDC *)param_1,
                         (int)(longlong)
                              (fVar5 * (float10)param_4 *
                               (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828) +
                              (float10)param_2),
                         (int)(longlong)
                              ((float10)param_3 -
                              fVar6 * (float10)param_4 *
                              (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828)),1);
            iVar3 = iVar3 + 1;
            iVar4 = iVar4 + 4;
          } while (iVar3 <= DAT_004ab9d8);
        }
        local_44 = local_44 + 1;
      } while (local_44 <= iVar2);
    }
  }
  iVar2 = DAT_0049118c;
  if (1 < param_7) {
    iVar2 = DAT_00491140;
  }
  local_44 = 1;
  if (0 < iVar2 + 5) {
    do {
      fVar5 = FUN_0042c400((double)CONCAT44(*(undefined4 *)(&DAT_004a52f4 + local_44 * 8),
                                            *(undefined4 *)(&DAT_004a52f0 + local_44 * 8)),
                           (double)CONCAT44(*(undefined4 *)(&DAT_004a60b4 + local_44 * 8),
                                            *(undefined4 *)(&DAT_004a60b0 + local_44 * 8)),param_7,
                           param_8);
      if (_DAT_00484d38 < (double)CONCAT44(_DAT_004a682c,_DAT_004a6828)) {
        _DAT_004a6828 = 0;
        _DAT_004a682c = 0x40bb5800;
      }
      fVar6 = (float10)fsin(fVar5);
      iVar3 = (int)(longlong)
                   (fVar6 * (float10)param_4 *
                    (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828) + (float10)param_2);
      fVar5 = (float10)fcos(fVar5);
      iVar4 = (int)(longlong)
                   ((float10)param_3 -
                   fVar5 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828)
                   );
      if (local_44 < 6) {
        if (local_44 == DAT_004aa7e0) {
          local_38 = iVar3;
          local_34 = iVar4;
        }
        if (((local_44 == 3) && (0 < param_7)) &&
           ((param_7 < 3 && (*(int *)(&DAT_004a6ba0 + param_8 * 4) == 1)))) {
          if ((*(int *)(&DAT_004a7bc8 + param_8 * 4) < 0x46) && (DAT_0049117c == 1)) {
            FUN_00431440(param_1,iVar3,iVar4,1,param_8,1,3);
          }
          if (((0xa5 - *(int *)(&DAT_004a5f10 + param_8 * 4) < *(int *)(&DAT_004a7bc8 + param_8 * 4)
               ) && (DAT_00491194 == 8)) && (DAT_0049117c == 1)) {
            FUN_00431440(param_1,iVar3,iVar4,2,param_8,1,3);
          }
        }
        if (((local_44 == 4) && (*(int *)(&DAT_004a6ba0 + param_8 * 4) == 2)) &&
           ((0 < param_7 && (param_7 < 3)))) {
          if ((*(int *)(&DAT_004a7bc8 + param_8 * 4) < DAT_004a4eb0 + 10) && (DAT_0049117c == 1)) {
            FUN_00431440(param_1,iVar3,iVar4,1,param_8,1,4);
          }
          if ((0xa0 - *(int *)(&DAT_004a5f10 + param_8 * 4) < *(int *)(&DAT_004a7bc8 + param_8 * 4))
             && (DAT_0049117c == 1)) {
            FUN_00431440(param_1,iVar3,iVar4,2,param_8,1,4);
          }
        }
        if (local_44 == 5) {
          if ((((*(int *)(&DAT_004a6ba0 + param_8 * 4) == 3) && (DAT_00491160 == 0)) &&
              (0 < param_7)) && (param_7 < 3)) {
            if ((*(int *)(&DAT_004a7bc8 + param_8 * 4) < DAT_004a4eb0 + 10) && (DAT_0049117c == 1))
            {
              FUN_00431440(param_1,iVar3,iVar4,1,param_8,1,5);
            }
            if ((0xa0 - *(int *)(&DAT_004a5f10 + param_8 * 4) <
                 *(int *)(&DAT_004a7bc8 + param_8 * 4)) && (DAT_0049117c == 1)) {
              FUN_00431440(param_1,iVar3,iVar4,2,param_8,1,5);
            }
          }
          if ((((*(int *)(&DAT_004a6ba0 + param_8 * 4) == 3) && (DAT_00491160 == 1)) &&
              (0xe < DAT_0049118c)) && ((0 < param_7 && (param_7 < 3)))) {
            if ((*(int *)(&DAT_004a7bc8 + param_8 * 4) < DAT_004a4eb0 + 10) && (DAT_0049117c == 1))
            {
              FUN_00431440(param_1,iVar3,iVar4,1,param_8,1,5);
            }
            if ((0xa0 - *(int *)(&DAT_004a5f10 + param_8 * 4) <
                 *(int *)(&DAT_004a7bc8 + param_8 * 4)) && (DAT_0049117c == 1)) {
              FUN_00431440(param_1,iVar3,iVar4,2,param_8,1,5);
            }
          }
        }
        if ((((local_44 == 2) && (*(int *)(&DAT_004a6ba0 + param_8 * 4) == 0)) && (0 < param_7)) &&
           (((param_7 < 3 && (*(int *)(&DAT_004a7bc8 + param_8 * 4) < 0x5a)) && (DAT_0049117c == 1))
           )) {
          if (DAT_004ac9a8 == 1) {
            iVar7 = 5;
          }
          else {
            iVar7 = 4;
          }
          FUN_00431440(param_1,iVar3,iVar4,iVar7,param_8,1,2);
        }
        if (((local_44 == 1) && (*(int *)(&DAT_004a6ba0 + param_8 * 4) == 0)) &&
           ((0 < param_7 &&
            (((param_7 < 3 && (*(int *)(&DAT_004a7bc8 + param_8 * 4) < 0x5a)) && (DAT_0049117c == 1)
             ))))) {
          if (DAT_004ac9a8 == 1) {
            iVar7 = 4;
          }
          else {
            iVar7 = 5;
          }
          FUN_00431440(param_1,iVar3,iVar4,iVar7,param_8,1,1);
        }
        if (((iVar3 < param_11) && (param_9 < iVar3)) && ((param_10 < iVar4 && (iVar4 < param_12))))
        {
          FUN_00424890(param_1,iVar3,iVar4,local_44,param_7,param_8);
        }
        if (2 < param_7) {
          FUN_00430570((CDC *)param_1,local_44,iVar3,iVar4);
        }
      }
      else {
        uVar1 = local_44 - 5;
        if (((uVar1 == param_8) && (0 < param_7)) && (param_7 < 3)) {
          if (DAT_004a71bc != (HGDIOBJ)0x0) {
            SelectObject(*(HDC *)(param_1 + 4),DAT_004a71bc);
          }
          FUN_004706bd((void *)param_1,local_18,iVar3,iVar4);
          CDC::LineTo((CDC *)param_1,local_38,local_34);
          if (((*(int *)(&DAT_004a7bc8 + param_8 * 4) < DAT_004a4eb0 + 10) && (param_7 == 1)) &&
             (DAT_0049117c == 1)) {
            FUN_00431440(param_1,iVar3,iVar4,3,param_8,1,local_44);
          }
          if (((0xa5 - *(int *)(&DAT_004a5f10 + param_8 * 4) < *(int *)(&DAT_004a7bc8 + param_8 * 4)
               ) && (param_7 == 1)) && (DAT_0049117c == 1)) {
            FUN_00431440(param_1,iVar3,iVar4,3,param_8,1,local_44);
          }
        }
        if (((*(int *)(&DAT_004a8660 + param_8 * 4) < 8) && (param_7 == 1)) &&
           ((iVar3 < param_11 && (((param_9 < iVar3 && (param_10 < iVar4)) && (iVar4 < param_12)))))
           ) {
          FUN_00423aa0((CDC *)param_1,iVar3,iVar4,uVar1,param_8);
        }
        if ((((7 < *(int *)(&DAT_004a8660 + param_8 * 4)) && (param_7 == 1)) &&
            ((iVar3 < param_11 && ((param_9 < iVar3 && (param_10 < iVar4)))))) && (iVar4 < param_12)
           ) {
          FUN_00423670((CDC *)param_1,iVar3,iVar4,uVar1,param_8,1);
        }
        if ((1 < param_7) &&
           (FUN_00423670((CDC *)param_1,iVar3,iVar4,uVar1,1,param_7), DAT_00491140 == 2)) {
          FUN_00423670((CDC *)param_1,iVar3,iVar4,uVar1,2,param_7);
        }
      }
      if (local_44 == 1) {
        local_30 = iVar4;
        local_2c = iVar3;
      }
      if ((local_44 == 2) && (DAT_004a5b80 < 1)) {
        (**(code **)(*(int *)param_1 + 0x2c))((void *)param_1,7);
        FUN_004706bd((void *)param_1,aiStack_10,local_2c,local_30);
        CDC::LineTo((CDC *)param_1,iVar3,iVar4);
      }
      local_44 = local_44 + 1;
    } while (local_44 <= iVar2 + 5);
  }
  return;
}

