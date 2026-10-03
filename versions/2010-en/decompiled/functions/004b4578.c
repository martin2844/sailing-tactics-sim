
void __thiscall FUN_004b4578(void *this,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)FUN_004b4461(this,0);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xf0))(param_2[1] == 0xe151);
    if (iVar2 != 0) {
      uVar3 = 1;
      goto LAB_004b45ab;
    }
  }
  uVar3 = 0;
LAB_004b45ab:
  (**(code **)*param_2)(uVar3);
  return;
}

