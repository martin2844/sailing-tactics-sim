
int __fastcall FUN_00456203(int param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    this = (void *)FUN_0045622d();
    if (this != (void *)0x0) {
      FUN_004670ae(this,*(uint *)(param_1 + 4));
    }
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return iVar1;
}

