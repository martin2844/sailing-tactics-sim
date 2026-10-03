
int * FUN_00476e36(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  void *local_8;
  
  piVar1 = (int *)FUN_0046cf6a();
  if (piVar1 != (int *)0x0) {
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    iVar2 = (**(code **)(*piVar1 + 0x5c))(0,0,0x50800000,&local_18,local_8,param_2,param_1);
    if (iVar2 != 0) {
      if (DAT_004ae694 == 0) {
        return piVar1;
      }
      uVar3 = FUN_0046ad25((int)piVar1);
      if ((uVar3 & 0x200) == 0) {
        return piVar1;
      }
      FUN_0046ad73(local_8,0x200,0,0x20);
      return piVar1;
    }
  }
  return (int *)0x0;
}

