
int __fastcall FUN_00468149(int param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar1 != 0) {
    this = (void *)FUN_0046805c();
    if (this != (void *)0x0) {
      FUN_004670ae(this,*(uint *)(param_1 + 0x1c));
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  return iVar1;
}

