
undefined4 __thiscall FUN_0047270a(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  
  if (*(int **)((int)this + 0x80) == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)((int)this + 0x80) + 0x38))(param_1);
  }
  return uVar1;
}

