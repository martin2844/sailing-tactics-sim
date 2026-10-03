
void FUN_004bc53a(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_004bc506(param_1[1]);
  if (iVar1 == 0) {
    param_1[7] = 1;
  }
  else {
    iVar1 = *param_1;
    uVar2 = FUN_004af3eb();
    (**(code **)(iVar1 + 4))(uVar2 >> 0x1c & 1);
  }
  return;
}

