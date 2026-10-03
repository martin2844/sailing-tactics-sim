
void __thiscall FUN_0046f9b6(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = FUN_00466bd6((void *)((int)this + 0x28),param_1,(undefined4 *)0x0);
  FUN_00466b9f((void *)((int)this + 0x28),piVar2);
  iVar1 = *(int *)this;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  (**(code **)(iVar1 + 0x70))();
  return;
}

