
void __thiscall FUN_004b4096(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_004ab2b6(param_2,0);
  FUN_004ab27f(uVar2);
  iVar1 = *param_1;
  *(undefined4 *)(param_2 + 0x3c) = 0;
  (**(code **)(iVar1 + 0x70))();
  return;
}

