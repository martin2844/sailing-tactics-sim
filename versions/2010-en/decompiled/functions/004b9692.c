
void __thiscall FUN_004b9692(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*param_2 != param_3) {
    *param_2 = param_3;
    if ((((*(uint *)(param_1 + 0x70) & 0xa000) == 0) || ((*(uint *)(param_1 + 0x70) & 0x5000) == 0))
       || (*(int *)(param_1 + 0x7c) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    *(undefined4 *)(param_1 + 0x7c) = uVar1;
    if (*(int *)(param_1 + 0x80) == 0) {
      uVar1 = FUN_004b96e4();
    }
    else {
      uVar1 = 0;
    }
    *(undefined4 *)(param_1 + 0x74) = uVar1;
    FUN_004b957c(0);
  }
  return;
}

