
void FUN_004640e0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int unaff_retaddr;
  undefined4 uVar2;
  
  if (DAT_004da1b0 != 0) {
    iVar1 = *param_1;
    if (DAT_005363e4 == 0) {
      uVar2 = 0x7f7f00;
    }
    else {
      uVar2 = 0;
    }
    (**(code **)(iVar1 + 0x38))(uVar2);
    if (DAT_004fe624 < 700) {
      param_3 = param_2 + 1;
    }
    FUN_004b4a1f(param_1,2);
    (**(code **)(iVar1 + 0x34))(0xffffff);
    (**(code **)(iVar1 + 100))
              (param_3,(DAT_0052318c - DAT_004fe2a8 / 0x32) - unaff_retaddr,DAT_004fdfd4,
               *(undefined4 *)(DAT_004fdfd4 + -8));
    FUN_004b4a1f(param_1,1);
  }
  return;
}

