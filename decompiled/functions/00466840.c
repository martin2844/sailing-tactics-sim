
tm * __thiscall FUN_00466840(void *this,tm *param_1)

{
  tm *ptVar1;
  tm *ptVar2;
  int iVar3;
  tm *ptVar4;
  
  if (param_1 == (tm *)0x0) {
    ptVar2 = FUN_004591e0(this);
  }
  else {
    ptVar1 = FUN_004591e0(this);
    ptVar2 = (tm *)0x0;
    if (ptVar1 != (tm *)0x0) {
      ptVar4 = param_1;
      for (iVar3 = 9; ptVar2 = param_1, iVar3 != 0; iVar3 = iVar3 + -1) {
        ptVar4->tm_sec = ptVar1->tm_sec;
        ptVar1 = (tm *)&ptVar1->tm_min;
        ptVar4 = (tm *)&ptVar4->tm_min;
      }
    }
  }
  return ptVar2;
}

