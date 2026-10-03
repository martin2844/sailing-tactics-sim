
tm * FUN_0049d8e0(int *param_1)

{
  int *piVar1;
  tm *ptVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = param_1;
  if (*param_1 < 0) {
    return (tm *)0x0;
  }
  FUN_004a1de0();
  iVar3 = *piVar1;
  if ((iVar3 < 0x3f481) || (0x7ffc0b7e < iVar3)) {
    ptVar2 = (tm *)FUN_0049d770(piVar1);
    iVar4 = __isindst(ptVar2);
    iVar3 = ptVar2->tm_sec;
    if (iVar4 != 0) {
      iVar3 = iVar3 - DAT_004f0480;
    }
    param_1 = (int *)(iVar3 - DAT_004f0478);
    iVar3 = (int)param_1 % 0x3c;
    ptVar2->tm_sec = iVar3;
    if (iVar3 < 0) {
      ptVar2->tm_sec = iVar3 + 0x3c;
      param_1 = (int *)((int)param_1 + -0x3c);
    }
    param_1 = (int *)((int)param_1 / 0x3c + ptVar2->tm_min);
    iVar3 = (int)param_1 % 0x3c;
    ptVar2->tm_min = iVar3;
    if (iVar3 < 0) {
      ptVar2->tm_min = iVar3 + 0x3c;
      param_1 = (int *)((int)param_1 + -0x3c);
    }
    param_1 = (int *)((int)param_1 / 0x3c + ptVar2->tm_hour);
    iVar3 = (int)param_1 % 0x18;
    ptVar2->tm_hour = iVar3;
    if (iVar3 < 0) {
      ptVar2->tm_hour = iVar3 + 0x18;
      param_1 = (int *)((int)param_1 + -0x18);
    }
    iVar3 = (int)param_1 / 0x18;
    if (0 < iVar3) {
      ptVar2->tm_wday = (iVar3 + ptVar2->tm_wday) % 7;
      ptVar2->tm_mday = ptVar2->tm_mday + iVar3;
      ptVar2->tm_yday = ptVar2->tm_yday + iVar3;
      return ptVar2;
    }
    if (iVar3 < 0) {
      ptVar2->tm_wday = (iVar3 + 7 + ptVar2->tm_wday) % 7;
      iVar4 = ptVar2->tm_mday + iVar3;
      ptVar2->tm_mday = iVar4;
      if (iVar4 < 1) {
        ptVar2->tm_yday = 0x16c;
        ptVar2->tm_mday = iVar4 + 0x1f;
        ptVar2->tm_mon = 0xb;
        ptVar2->tm_year = ptVar2->tm_year + -1;
        return ptVar2;
      }
      ptVar2->tm_yday = ptVar2->tm_yday + iVar3;
    }
  }
  else {
    param_1 = (int *)(iVar3 - DAT_004f0478);
    ptVar2 = (tm *)FUN_0049d770(&param_1);
    if (DAT_004f047c != 0) {
      iVar3 = __isindst(ptVar2);
      if (iVar3 != 0) {
        param_1 = (int *)((int)param_1 - DAT_004f0480);
        ptVar2 = (tm *)FUN_0049d770(&param_1);
        ptVar2->tm_isdst = 1;
        return ptVar2;
      }
    }
  }
  return ptVar2;
}

