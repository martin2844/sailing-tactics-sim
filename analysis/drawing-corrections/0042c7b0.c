
void __cdecl
FUN_0042c7b0(CDC *param_1,int *param_2,int param_3,undefined4 param_4,int param_5,int param_6,
            int param_7)

{
  int *piVar1;
  int iVar2;
  COLORREF CVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8 [2];
  
  iVar2 = param_6;
  piVar1 = param_2;
  local_8[0] = DAT_0049118c + 5;
  iVar4 = 1;
  if (0 < local_8[0]) {
    iVar6 = 0;
    iVar5 = 0;
    do {
      FUN_0042bfc0(iVar4,*(double *)((int)&DAT_004a52f8 + iVar6),
                   *(double *)((int)&DAT_004a60b8 + iVar6),(int)param_2,0);
      *(undefined4 *)((int)&DAT_004a6db4 + iVar5) = *(undefined4 *)((int)&DAT_004aaa4c + iVar5);
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 8;
      iVar5 = iVar5 + 4;
    } while (iVar4 <= local_8[0]);
  }
  FUN_0042cca0(0);
  if (DAT_004a5b80 < 1) {
    FUN_0042c550(param_1,param_3,param_5,param_6,(int)param_2);
  }
  if (DAT_004a71bc != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a71bc);
  }
  iVar4 = DAT_004a7c64;
  iVar5 = DAT_004aaa64;
  if (param_2 == (int *)0x1) {
    iVar4 = DAT_004a7c60;
    iVar5 = DAT_004aaa60;
  }
  FUN_004706bd(param_1,local_8,iVar4,iVar5);
  CDC::LineTo(param_1,(&DAT_004a7c48)[DAT_004aa7e0],(&DAT_004aaa48)[DAT_004aa7e0]);
  param_6 = 1;
  if (0 < DAT_0049118c + 5) {
    param_2 = &DAT_004a443c;
    do {
      iVar4 = *param_2;
      CVar3 = GetPixel(*(HDC *)(param_1 + 4),(&DAT_004a7c48)[iVar4],(&DAT_004aaa48)[iVar4] + 1);
      if ((CVar3 != 0x8000) &&
         (CVar3 = GetPixel(*(HDC *)(param_1 + 4),(&DAT_004a7c48)[iVar4],(&DAT_004aaa48)[iVar4] + 2),
         CVar3 != 0x8000)) {
        if (DAT_0049117c == 1) {
          if ((iVar4 == 3) && (*(int *)(&DAT_004a6ba0 + (int)piVar1 * 4) == 1)) {
            if (*(int *)(&DAT_004a7bc8 + (int)piVar1 * 4) < DAT_004a4eb0 + 10) {
              FUN_00431440((int)param_1,DAT_004a7c54,DAT_004aaa54,1,(int)piVar1,0,3);
            }
            if ((0xa5 - *(int *)(&DAT_004a5f10 + (int)piVar1 * 4) <
                 *(int *)(&DAT_004a7bc8 + (int)piVar1 * 4)) && (DAT_00491194 == 8)) {
              FUN_00431440((int)param_1,DAT_004a7c54,DAT_004aaa54,2,(int)piVar1,0,3);
            }
          }
          if ((iVar4 == 4) && (*(int *)(&DAT_004a6ba0 + (int)piVar1 * 4) == 2)) {
            if (*(int *)(&DAT_004a7bc8 + (int)piVar1 * 4) < DAT_004a4eb0 + 10) {
              FUN_00431440((int)param_1,DAT_004a7c58,DAT_004aaa58,1,(int)piVar1,0,4);
            }
            if (0xa5 - *(int *)(&DAT_004a5f10 + (int)piVar1 * 4) <
                *(int *)(&DAT_004a7bc8 + (int)piVar1 * 4)) {
              FUN_00431440((int)param_1,DAT_004a7c58,DAT_004aaa58,2,(int)piVar1,0,4);
            }
          }
          if (iVar4 == 5) {
            if ((*(int *)(&DAT_004a6ba0 + (int)piVar1 * 4) == 3) && (DAT_00491160 == 0)) {
              if (*(int *)(&DAT_004a7bc8 + (int)piVar1 * 4) < DAT_004a4eb0 + 10) {
                FUN_00431440((int)param_1,DAT_004a7c5c,DAT_004aaa5c,1,(int)piVar1,0,5);
              }
              if (0xa5 - *(int *)(&DAT_004a5f10 + (int)piVar1 * 4) <
                  *(int *)(&DAT_004a7bc8 + (int)piVar1 * 4)) {
                FUN_00431440((int)param_1,DAT_004a7c5c,DAT_004aaa5c,2,(int)piVar1,0,5);
              }
            }
            if (((*(int *)(&DAT_004a6ba0 + (int)piVar1 * 4) == 3) && (DAT_00491160 == 1)) &&
               (0xe < DAT_0049118c)) {
              if (*(int *)(&DAT_004a7bc8 + (int)piVar1 * 4) < DAT_004a4eb0) {
                FUN_00431440((int)param_1,DAT_004a7c5c,DAT_004aaa5c,1,(int)piVar1,0,5);
              }
              if (0xa5 - *(int *)(&DAT_004a5f10 + (int)piVar1 * 4) <
                  *(int *)(&DAT_004a7bc8 + (int)piVar1 * 4)) {
                FUN_00431440((int)param_1,DAT_004a7c5c,DAT_004aaa5c,2,(int)piVar1,0,5);
              }
            }
          }
          if (((iVar4 == 2) && (*(int *)(&DAT_004a6ba0 + (int)piVar1 * 4) == 0)) &&
             (*(int *)(&DAT_004a7bc8 + (int)piVar1 * 4) < 0x5a)) {
            if (DAT_004ac9a8 == 1) {
              iVar5 = 5;
            }
            else {
              iVar5 = 4;
            }
            FUN_00431440((int)param_1,DAT_004a7c50,(int)DAT_004aaa50,iVar5,(int)piVar1,0,2);
          }
          if (((iVar4 == 1) && (*(int *)(&DAT_004a6ba0 + (int)piVar1 * 4) == 0)) &&
             (*(int *)(&DAT_004a7bc8 + (int)piVar1 * 4) < 0x5a)) {
            if (DAT_004ac9a8 == 1) {
              iVar5 = 4;
            }
            else {
              iVar5 = 5;
            }
            FUN_00431440((int)param_1,DAT_004a7c4c,DAT_004aaa4c,iVar5,(int)piVar1,0,1);
          }
        }
        if (iVar4 < 6) {
          iVar5 = (&DAT_004a7c48)[iVar4];
          if (((iVar5 < param_5) && (param_3 < iVar5)) && ((int)(&DAT_004aaa48)[iVar4] <= iVar2)) {
            if (iVar4 == 2) {
              FUN_0042cf50();
              FUN_00411000(param_1,DAT_004a7c50,DAT_004aaa50,0,(uint)piVar1,iVar2,param_7);
            }
            else {
              FUN_0042cd40((int *)param_1,iVar5,(&DAT_004aaa48)[iVar4],iVar4,(int)piVar1);
            }
          }
          if (iVar4 < 6) goto LAB_0042cc6d;
        }
        iVar5 = (&DAT_004a7c48)[iVar4];
        if (((iVar5 < param_5) && (param_3 < iVar5)) && ((int)(&DAT_004aaa48)[iVar4] <= iVar2)) {
          FUN_00411000(param_1,iVar5,(undefined *)(&DAT_004aaa48)[iVar4],iVar4 - 5,(uint)piVar1,
                       iVar2,param_7);
        }
      }
LAB_0042cc6d:
      param_6 = param_6 + 1;
      param_2 = param_2 + 1;
    } while (param_6 <= DAT_0049118c + 5);
  }
  return;
}

