
void __thiscall FUN_00477e5a(void *this,int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_00477e26(this,param_1[1]);
  if (iVar2 == 0) {
    param_1[7] = 1;
  }
  else {
    iVar1 = *param_1;
    uVar3 = FUN_0046ad0b(iVar2);
    (**(code **)(iVar1 + 4))(uVar3 >> 0x1c & 1);
  }
  return;
}

