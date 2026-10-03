
void __thiscall FUN_004b4534(void *this,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004b4461(this,0);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x80) != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  (**(code **)*param_2)(uVar2);
  return;
}

