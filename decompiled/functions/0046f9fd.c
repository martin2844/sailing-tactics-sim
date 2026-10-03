
undefined4 __thiscall
FUN_0046f9fd(void *this,undefined4 *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_0046afc3(this,param_1,param_2,param_3,param_4);
  if (uVar1 == 0) {
    if (*(int **)((int)this + 0x24) != (int *)0x0) {
      iVar2 = (**(code **)(**(int **)((int)this + 0x24) + 0x14))(param_1,param_2,param_3,param_4);
      if (iVar2 != 0) goto LAB_0046fa34;
    }
    uVar3 = 0;
  }
  else {
LAB_0046fa34:
    uVar3 = 1;
  }
  return uVar3;
}

