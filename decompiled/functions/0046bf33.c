
undefined4 * __thiscall FUN_0046bf33(void *this,LPCSTR param_1)

{
  undefined **ppuVar1;
  uint uVar2;
  
  ppuVar1 = FUN_0046bd74();
  *(undefined **)this = *ppuVar1;
  if (param_1 != (LPCSTR)0x0) {
    if ((short)((uint)param_1 >> 0x10) == 0) {
      FUN_0046d861((uint)param_1 & 0xffff);
      return this;
    }
    if (param_1 != (LPCSTR)0x0) {
      uVar2 = lstrlenA(param_1);
      goto LAB_0046bf71;
    }
  }
  uVar2 = 0;
LAB_0046bf71:
  if (uVar2 != 0) {
    FUN_0046bdc1(this,uVar2);
    FUN_00457850(*(undefined4 **)this,(undefined4 *)param_1,uVar2);
  }
  return this;
}

