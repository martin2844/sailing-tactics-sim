
void __thiscall FUN_004bf187(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    if ((*(int *)(param_1 + 0x10) == 0) && (*(int *)(*(int *)(param_1 + 0x14) + -8) != 0)) {
      *(undefined4 *)(param_1 + 0x10) = 1;
    }
    uVar1 = 0;
    if ((*(int *)(param_1 + 8) == 0) && (*(int *)(param_1 + 0xc) == 0)) {
      uVar1 = 1;
    }
    *(undefined4 *)(param_1 + 4) = uVar1;
  }
  return;
}

