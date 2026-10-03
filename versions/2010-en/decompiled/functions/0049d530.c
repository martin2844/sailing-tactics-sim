
int FUN_0049d530(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = param_1;
  uVar3 = param_1[5];
  if ((int)uVar3 < 0x45) {
    return -1;
  }
  if (0x8b < (int)uVar3) {
    return -1;
  }
  iVar4 = param_1[4];
  if ((iVar4 < 0) || (0xb < iVar4)) {
    uVar3 = uVar3 + iVar4 / 0xc;
    iVar4 = iVar4 % 0xc;
    param_1[4] = iVar4;
    if (iVar4 < 0) {
      uVar3 = uVar3 - 1;
      param_1[4] = iVar4 + 0xc;
    }
    if ((int)uVar3 < 0x45) {
      return -1;
    }
    if (0x8b < (int)uVar3) {
      return -1;
    }
  }
  iVar4 = (&DAT_004f0568)[param_1[4]];
  if (((uVar3 & 3) == 0) && (1 < param_1[4])) {
    iVar4 = iVar4 + 1;
  }
  iVar1 = param_1[3];
  iVar5 = uVar3 * 0x16d + -0x63df + iVar4 + ((int)(uVar3 - 1) >> 2);
  iVar4 = iVar5 + iVar1;
  if (iVar5 < 0) {
LAB_0049d5e0:
    if ((iVar1 < 0) && (-1 < iVar4)) {
      return -1;
    }
  }
  else {
    if ((-1 < iVar1) && (iVar4 < 0)) {
      return -1;
    }
    if (iVar5 < 0) goto LAB_0049d5e0;
  }
  iVar5 = iVar4 * 0x18;
  if (iVar4 != 0 && iVar5 / iVar4 != 0x18) {
    return -1;
  }
  iVar1 = param_1[2];
  iVar4 = iVar1 + iVar5;
  if (iVar5 < 0) {
LAB_0049d62b:
    if ((iVar1 < 0) && (-1 < iVar4)) {
      return -1;
    }
  }
  else {
    if ((-1 < iVar1) && (iVar4 < 0)) {
      return -1;
    }
    if (iVar5 < 0) goto LAB_0049d62b;
  }
  iVar5 = iVar4 * 0x3c;
  if (iVar4 != 0 && iVar5 / iVar4 != 0x3c) {
    return -1;
  }
  iVar1 = param_1[1];
  iVar4 = iVar1 + iVar5;
  if (iVar5 < 0) {
LAB_0049d67a:
    if ((iVar1 < 0) && (-1 < iVar4)) {
      return -1;
    }
  }
  else {
    if ((-1 < iVar1) && (iVar4 < 0)) {
      return -1;
    }
    if (iVar5 < 0) goto LAB_0049d67a;
  }
  iVar5 = iVar4 * 0x3c;
  if (iVar4 != 0 && iVar5 / iVar4 != 0x3c) {
    return -1;
  }
  iVar4 = *param_1;
  param_1 = (int *)(iVar4 + iVar5);
  if (-1 < iVar5) {
    if ((-1 < iVar4) && ((int)param_1 < 0)) {
      return -1;
    }
    if (-1 < iVar5) goto LAB_0049d6d8;
  }
  if ((iVar4 < 0) && (-1 < (int)param_1)) {
    return -1;
  }
LAB_0049d6d8:
  if (param_2 == 0) {
    piVar2 = (int *)FUN_0049d770(&param_1);
    if (piVar2 == (int *)0x0) {
      return -1;
    }
  }
  else {
    FUN_004a1de0();
    param_1 = (int *)((int)param_1 + DAT_004f0478);
    piVar2 = (int *)FUN_0049d8e0(&param_1);
    if (piVar2 == (int *)0x0) {
      return -1;
    }
    if ((0 < piVar6[8]) || ((piVar6[8] < 0 && (0 < piVar2[8])))) {
      param_1 = (int *)((int)param_1 + DAT_004f0480);
      piVar2 = (int *)FUN_0049d8e0(&param_1);
      for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar6 = *piVar2;
        piVar2 = piVar2 + 1;
        piVar6 = piVar6 + 1;
      }
      return (int)param_1;
    }
  }
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar6 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar6 = piVar6 + 1;
  }
  return (int)param_1;
}

