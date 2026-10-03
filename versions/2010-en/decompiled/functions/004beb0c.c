
undefined4 __thiscall FUN_004beb0c(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  Tact2010CString *original_this;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x58)) {
    original_this = (Tact2010CString *)(*(int *)(param_1 + 0x5c) + 0x10);
    do {
      FUN_004b05a5(original_this);
      original_this = original_this + 5;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x58));
  }
  iVar3 = FUN_004c0a3e(param_2,param_3);
  uVar1 = 0;
  if (iVar3 != 0) {
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x58)) {
      iVar2 = *(int *)(param_1 + 0x5c) + 0x10;
      do {
        uVar1 = FUN_004b0454(4);
        FUN_0049c110(iVar2,uVar1);
        iVar2 = iVar2 + 0x14;
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x58));
    }
    uVar1 = 1;
  }
  return uVar1;
}

