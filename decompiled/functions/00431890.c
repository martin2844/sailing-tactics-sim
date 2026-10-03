
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */

void __cdecl
FUN_00431890(int param_1,int param_2,int param_3,double param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  if (DAT_004ac98c == 1) {
    return;
  }
  iVar2 = DAT_004a763c / 0xe;
  if (param_11 == 1) {
    iVar4 = *(int *)(&DAT_004a8660 + param_3 * 4);
    if (iVar4 < 5) {
      iVar2 = (DAT_004a763c * 2) / 3;
    }
    if (iVar4 == 8) {
      iVar2 = DAT_004a763c / 3;
    }
    if (iVar4 == 0x10) {
      iVar2 = (int)(DAT_004a763c + (DAT_004a763c >> 0x1f & 7U)) >> 3;
    }
  }
  if (param_5 < param_7 - iVar2) {
    return;
  }
  if (iVar2 + param_9 < param_5) {
    return;
  }
  if (iVar2 + param_10 < param_6) {
    return;
  }
  if (param_6 < param_8 - iVar2) {
    return;
  }
  iVar2 = (int)(longlong)((double)*(int *)(&DAT_004a4ec0 + param_2 * 4) * param_4);
  if (iVar2 < 5) {
    iVar2 = 5;
  }
  if (DAT_004a763c * 2 < iVar2) {
    iVar2 = DAT_004a763c * 2;
  }
  if (((*(int *)(&DAT_004a8660 + param_3 * 4) < 9) && (param_11 == 1)) && (DAT_004ac92c == 0)) {
    (**(code **)(*(int *)param_1 + 0x2c))((void *)param_1,8);
    if (DAT_004a5b8c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a5b8c);
    }
    Ellipse(*(HDC *)(param_1 + 4),param_5 - iVar2,param_6 - iVar2,iVar2 + param_5,iVar2 + param_6);
  }
  if (DAT_004a4dec != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
  }
  if (param_11 == 1) {
    iVar4 = *(int *)(&DAT_004a8660 + param_3 * 4);
    if (8 < iVar4) goto LAB_00431a37;
    iVar3 = 6;
    if (iVar4 != 8) {
      iVar3 = 1;
    }
    if (iVar4 < 5) {
      iVar3 = 0xc;
    }
  }
  else {
LAB_00431a37:
    iVar3 = 4;
  }
  uVar1 = iVar2 * 2;
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    iVar4 = FUN_00415a20(uVar1);
    iVar5 = FUN_00415a20(uVar1);
    FUN_00419d50((CDC *)param_1,iVar4 + (param_5 - iVar2),iVar5 + (param_6 - iVar2),1);
  }
  iVar4 = 0xc;
  if ((param_11 == 1) && (iVar3 = *(int *)(&DAT_004a8660 + param_3 * 4), iVar3 < 0x21)) {
    if (iVar3 < 5) {
      iVar4 = 0x20;
    }
    if (iVar3 == 8) {
      iVar4 = 0x20;
    }
    if (iVar3 == 0x10) {
      iVar4 = 0x20;
    }
    if (iVar3 != 0x20) goto LAB_00431ac7;
  }
  iVar4 = 0x10;
LAB_00431ac7:
  if (iVar4 != 0) {
    piVar6 = &DAT_004a9454;
    param_11 = iVar4;
    do {
      FUN_00419d50((CDC *)param_1,(int)(uVar1 * *piVar6) / 100 + (param_5 - iVar2),
                   (int)(uVar1 * piVar6[1]) / 100 + (param_6 - iVar2),1);
      piVar6 = piVar6 + 1;
      param_11 = param_11 + -1;
    } while (param_11 != 0);
  }
  return;
}

