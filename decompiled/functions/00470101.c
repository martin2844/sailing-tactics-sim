
int __fastcall FUN_00470101(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = param_1[1];
  if (iVar1 != 0) {
    this = (void *)FUN_00470044();
    if (this != (void *)0x0) {
      FUN_004670ae(this,param_1[1]);
    }
  }
  (**(code **)(*param_1 + 0x1c))();
  param_1[1] = 0;
  return iVar1;
}

