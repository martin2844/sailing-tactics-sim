
void __thiscall FUN_0046f996(void *this,int param_1)

{
  int iVar1;
  
  AddTail((void *)((int)this + 0x28),param_1);
  iVar1 = *(int *)this;
  *(void **)(param_1 + 0x3c) = this;
  (**(code **)(iVar1 + 0x70))();
  return;
}

