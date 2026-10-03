
void __thiscall FUN_0047162b(void *this,undefined1 param_1,undefined4 param_2,void *param_3)

{
  int iVar1;
  void *pvVar2;
  
  if ((param_3 != (void *)0x0) && (iVar1 = FUN_00469ec1(param_3,0), iVar1 != 0)) {
    return;
  }
  iVar1 = *(int *)this;
  pvVar2 = (void *)(**(code **)(iVar1 + 0x70))(0);
  if (param_3 == pvVar2) {
    (**(code **)(iVar1 + 0xc4))(CONCAT11(0xff,param_1),param_2,1);
  }
  return;
}

