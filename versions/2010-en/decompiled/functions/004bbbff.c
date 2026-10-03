
void __thiscall FUN_004bbbff(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 9) & 0x20) != 0) {
    param_2 = 1;
  }
  iVar1 = FUN_004af553();
  if (iVar1 == 0) {
    param_2 = 0;
  }
  (**(code **)(*param_1 + 0xa8))(0x86,param_2,0);
  return;
}

