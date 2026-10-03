
void __thiscall FUN_0047800a(void *this,int *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)FUN_00455bf0();
  if (pvVar1 == this) {
    (**(code **)(*param_1 + 4))(*(int *)((int)this + 0x50) != 0);
  }
  else {
    param_1[7] = 1;
  }
  return;
}

