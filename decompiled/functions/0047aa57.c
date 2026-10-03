
void __thiscall FUN_0047aa57(void *this,LPCSTR param_1)

{
  void *this_00;
  
  this_00 = (void *)((int)this + 0x14);
  if ((*(int *)(*(int *)((int)this + 0x14) + -8) == 0) ||
     ((*(int *)((int)this + 0x10) == 3 &&
      (((this_00 = (void *)((int)this + 0x18), *(int *)(*(int *)((int)this + 0x18) + -8) == 0 ||
        (this_00 = (void *)((int)this + 0x1c), *(int *)(*(int *)((int)this + 0x1c) + -8) == 0)) ||
       (this_00 = (void *)((int)this + 0x20), *(int *)(*(int *)((int)this + 0x20) + -8) == 0)))))) {
    FUN_0046c00d(this_00,param_1);
  }
  return;
}

