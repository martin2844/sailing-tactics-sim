
int __fastcall FUN_004b47e1(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  if (iVar1 != 0) {
    iVar2 = FUN_004b4724(0);
    if (iVar2 != 0) {
      FUN_004ab78e(param_1[1]);
    }
  }
  (**(code **)(*param_1 + 0x1c))();
  param_1[1] = 0;
  return iVar1;
}

