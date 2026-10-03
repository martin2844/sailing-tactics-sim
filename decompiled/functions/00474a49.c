
void __thiscall FUN_00474a49(void *this,undefined4 param_1,int param_2,int param_3)

{
  tagRECT local_2c;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  *(undefined4 *)((int)this + 0x88) = 0;
  FUN_00474d92((int)this);
  GetWindowRect(*(HWND *)(*(int *)((int)this + 0x68) + 0x1c),&local_2c);
  *(int *)((int)this + 4) = param_2;
  *(int *)((int)this + 8) = param_3;
  *(undefined4 *)((int)this + 0x8c) = param_1;
  (**(code **)(**(int **)((int)this + 0x68) + 0xc4))(&local_c,0,6);
  local_10 = local_8 + local_2c.top;
  local_14 = local_c + local_2c.left;
  *(LONG *)((int)this + 0x28) = local_2c.left;
  *(LONG *)((int)this + 0x2c) = local_2c.top;
  *(int *)((int)this + 0x30) = local_14;
  *(int *)((int)this + 0x34) = local_10;
  *(LONG *)((int)this + 0x38) = local_2c.left;
  *(LONG *)((int)this + 0x3c) = local_2c.top;
  *(int *)((int)this + 0x40) = local_14;
  *(int *)((int)this + 0x44) = local_10;
  local_1c = local_2c.left;
  local_18 = local_2c.top;
  ((LPRECT)((int)this + 0x48))->left = local_2c.left;
  *(LONG *)((int)this + 0x4c) = local_2c.top;
  *(int *)((int)this + 0x50) = local_14;
  *(int *)((int)this + 0x54) = local_10;
  FUN_00479b81((LPRECT)((int)this + 0x48),0xc40000);
  InflateRect((LPRECT)((int)this + 0x48),-DAT_004ae648,-DAT_004ae64c);
  local_1c = 0;
  local_18 = 0;
  local_14 = (*(int *)((int)this + 0x50) - ((LPRECT)((int)this + 0x48))->left) -
             (*(int *)((int)this + 0x40) - *(int *)((int)this + 0x38));
  local_10 = (*(int *)((int)this + 0x54) - *(int *)((int)this + 0x4c)) -
             (*(int *)((int)this + 0x44) - *(int *)((int)this + 0x3c));
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(int *)((int)this + 0x60) = local_14;
  *(int *)((int)this + 100) = local_10;
  FUN_00474b6d(this,param_2,param_3);
  FUN_00475164(this);
  return;
}

