
void __thiscall FUN_0047166f(void *this,byte param_1,undefined4 param_2,void *param_3)

{
  int iVar1;
  void *pvVar2;
  
  if ((param_3 != (void *)0x0) && (iVar1 = FUN_00469ec1(param_3,0), iVar1 != 0)) {
    return;
  }
  iVar1 = *(int *)this;
  pvVar2 = (void *)(**(code **)(iVar1 + 0x70))(1);
  if (param_3 == pvVar2) {
    (**(code **)(iVar1 + 0xc4))(CONCAT31((uint3)param_1,0xff),param_2,1);
  }
  return;
}

