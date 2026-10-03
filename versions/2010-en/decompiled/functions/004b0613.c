
Tact2010CString * __thiscall FUN_004b0613(Tact2010CString *original_this,char *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_004b0454();
  original_this->data = (char *)*puVar1;
  if (param_2 != (char *)0x0) {
    if ((short)((uint)param_2 >> 0x10) == 0) {
      FUN_004b1f41((uint)param_2 & 0xffff);
      return original_this;
    }
    if (param_2 != (char *)0x0) {
      iVar2 = lstrlenA(param_2);
      goto LAB_004b0651;
    }
  }
  iVar2 = 0;
LAB_004b0651:
  if (iVar2 != 0) {
    FUN_004b04a1(iVar2);
    FUN_0049c110(original_this->data,param_2,iVar2);
  }
  return original_this;
}

