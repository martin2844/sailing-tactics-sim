
void __thiscall FUN_004b5d4f(int *param_1,byte param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if ((param_4 != 0) && (iVar1 = FUN_004ae5a1(0), iVar1 != 0)) {
    return;
  }
  iVar1 = *param_1;
  iVar2 = (**(code **)(iVar1 + 0x70))(1);
  if (param_4 == iVar2) {
    (**(code **)(iVar1 + 0xc4))(CONCAT31((uint3)param_2,0xff),param_3,1);
  }
  return;
}

