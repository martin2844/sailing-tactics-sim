
undefined4 __fastcall FUN_00467af2(void *param_1)

{
  ushort *puVar1;
  int iVar2;
  void *this;
  
  if (*(ushort **)((int)param_1 + 0x4c) == (ushort *)0x0) {
    puVar1 = FUN_0046a70a(param_1,*(LPCSTR *)((int)param_1 + 0x40));
  }
  else {
    puVar1 = FUN_0046a75a(param_1,*(ushort **)((int)param_1 + 0x4c));
  }
  if (puVar1 != (ushort *)0x0) {
    iVar2 = FUN_0046a4d3();
    if (iVar2 != 0) {
      this = (void *)FUN_0046acae(param_1,0xe146);
      if (this != (void *)0x0) {
        iVar2 = FUN_00467a9b();
        FUN_0046ae4c(this,-(uint)(iVar2 != 0) & 5);
      }
      return 1;
    }
  }
  FUN_004679cb(param_1,-1);
  return 0;
}

