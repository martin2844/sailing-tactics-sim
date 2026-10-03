
void __thiscall FUN_0047841b(void *this,int param_1)

{
  uint uVar1;
  tagRECT local_14;
  
  if (*(int *)((int)this + 0xb0) == 0) {
    *(undefined4 *)((int)this + 0xb0) = 1;
    if ((*(uint *)((int)this + 0xb8) & 4) != 0) {
      param_1 = 1;
    }
    *(uint *)((int)this + 0xb8) = *(uint *)((int)this + 0xb8) & 0xfffffff3;
    if ((param_1 != 0) && (*(int **)((int)this + 0x68) != (int *)0x0)) {
      (**(code **)(**(int **)((int)this + 0x68) + 0x58))();
    }
    uVar1 = FUN_0046ad0b((int)this);
    if ((uVar1 & 0x2000) == 0) {
      FUN_00469bc6(this,0,0xffff,0xe900,2,(LPRECT)((int)this + 0x58),(int *)0x0,1);
    }
    else {
      local_14.right = 0x7fff;
      local_14.bottom = 0x7fff;
      local_14.left = 0;
      local_14.top = 0;
      FUN_00469bc6(this,0,0xffff,0xe900,1,&local_14,&local_14.left,0);
      FUN_00469bc6(this,0,0xffff,0xe900,2,(LPRECT)((int)this + 0x58),&local_14.left,1);
      (**(code **)(*(int *)this + 0x68))(&local_14,0);
      FUN_0046adfd(this,0,0,0,local_14.right - local_14.left,local_14.bottom - local_14.top,0x16);
    }
    *(undefined4 *)((int)this + 0xb0) = 0;
  }
  return;
}

