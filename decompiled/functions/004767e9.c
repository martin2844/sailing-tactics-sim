
undefined4 __fastcall FUN_004767e9(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((int *)param_1[0x1a] != (int *)0x0) {
    iVar1 = (**(code **)(*(int *)param_1[0x1a] + 0x78))();
    if (iVar1 != 0) {
      return 1;
    }
  }
  uVar2 = FUN_00468021(param_1);
  return uVar2;
}

