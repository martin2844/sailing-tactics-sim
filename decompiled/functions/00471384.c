
undefined4 __thiscall FUN_00471384(void *this,int *param_1,int *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  tagRECT local_14;
  
  GetClientRect(*(HWND *)((int)this + 0x1c),&local_14);
  *param_1 = local_14.right;
  param_1[1] = local_14.bottom;
  uVar1 = FUN_0046ad0b((int)this);
  FUN_0047132a(this,param_2);
  if ((*param_2 != 0) && ((uVar1 & 0x200000) != 0)) {
    *param_1 = *param_1 + *param_2;
  }
  if ((param_2[1] != 0) && ((uVar1 & 0x100000) != 0)) {
    param_1[1] = param_1[1] + param_2[1];
  }
  if ((*param_2 < *param_1) && (param_2[1] < param_1[1])) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

