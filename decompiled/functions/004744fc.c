
void __thiscall FUN_004744fc(void *this,int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  tagRECT local_5c;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  tagRECT local_3c;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  *(undefined4 *)((int)this + 0x88) = 1;
  FUN_00474d92((int)this);
  iVar1 = *(int *)((int)this + 0x68);
  if ((*(uint *)(iVar1 + 100) & 4) == 0) {
    if ((*(uint *)(iVar1 + 100) & 2) == 0) {
      GetWindowRect(*(HWND *)(iVar1 + 0x1c),&local_3c);
      uVar2 = *(uint *)((int)this + 0x78) & 0xa000;
      *(int *)((int)this + 4) = param_1;
      *(int *)((int)this + 8) = param_2;
      (**(code **)(**(int **)((int)this + 0x68) + 0xc4))
                (&local_c,0xffffffff,(-(uVar2 != 0) & 6U) + 10);
      if (uVar2 == 0) {
        local_4c = local_3c.left;
        *(LONG *)((int)this + 0x38) = local_3c.left;
        *(LONG *)((int)this + 0x3c) = local_3c.top;
        local_48 = param_2 - (local_3c.right - local_3c.left) / 2;
        *(LONG *)((int)this + 0x40) = local_3c.right;
        *(LONG *)((int)this + 0x44) = local_3c.bottom;
        piVar3 = (int *)((int)this + 0x28);
      }
      else {
        local_48 = local_3c.top;
        *(LONG *)((int)this + 0x28) = local_3c.left;
        *(LONG *)((int)this + 0x2c) = local_3c.top;
        local_4c = param_1 - (local_3c.bottom - local_3c.top) / 2;
        *(LONG *)((int)this + 0x30) = local_3c.right;
        *(LONG *)((int)this + 0x34) = local_3c.bottom;
        piVar3 = (int *)((int)this + 0x38);
      }
      local_40 = local_8 + local_48;
      local_44 = local_4c + local_c;
      *piVar3 = local_4c;
      piVar3[1] = local_48;
      piVar3[2] = local_44;
      piVar3[3] = local_40;
      *(undefined4 *)((int)this + 0x48) = *(undefined4 *)((int)this + 0x28);
      *(undefined4 *)((int)this + 0x4c) = *(undefined4 *)((int)this + 0x2c);
      *(undefined4 *)((int)this + 0x50) = *(undefined4 *)((int)this + 0x30);
      *(undefined4 *)((int)this + 0x54) = *(undefined4 *)((int)this + 0x34);
      *(undefined4 *)((int)this + 0x58) = *(undefined4 *)((int)this + 0x38);
      *(undefined4 *)((int)this + 0x5c) = *(undefined4 *)((int)this + 0x3c);
      *(undefined4 *)((int)this + 0x60) = *(undefined4 *)((int)this + 0x40);
      *(undefined4 *)((int)this + 100) = *(undefined4 *)((int)this + 0x44);
    }
    else {
      GetWindowRect(*(HWND *)(iVar1 + 0x1c),&local_5c);
      *(int *)((int)this + 4) = param_1;
      *(int *)((int)this + 8) = param_2;
      (**(code **)(**(int **)((int)this + 0x68) + 0xc4))(&local_3c.right,0xffffffff,10);
      (**(code **)(**(int **)((int)this + 0x68) + 0xc4))(&local_2c,0xffffffff,0x10);
      *(LONG *)((int)this + 0x28) = local_5c.left;
      *(LONG *)((int)this + 0x2c) = local_5c.top;
      *(LONG *)((int)this + 0x30) = local_3c.right + local_5c.left;
      *(LONG *)((int)this + 0x34) = local_3c.bottom + local_5c.top;
      *(LONG *)((int)this + 0x48) = local_5c.left;
      *(LONG *)((int)this + 0x4c) = local_5c.top;
      *(LONG *)((int)this + 0x50) = local_3c.right + local_5c.left;
      *(LONG *)((int)this + 0x54) = local_3c.bottom + local_5c.top;
      local_24 = local_5c.left;
      local_1c = local_2c + local_5c.left;
      local_18 = local_28 + local_5c.top;
      local_20 = local_5c.top;
      *(LONG *)((int)this + 0x38) = local_5c.left;
      *(LONG *)((int)this + 0x3c) = local_5c.top;
      *(int *)((int)this + 0x40) = local_1c;
      *(int *)((int)this + 0x44) = local_18;
      *(LONG *)((int)this + 0x58) = local_5c.left;
      *(LONG *)((int)this + 0x5c) = local_5c.top;
      *(int *)((int)this + 0x60) = local_1c;
      *(int *)((int)this + 100) = local_18;
    }
  }
  else {
    GetWindowRect(*(HWND *)(iVar1 + 0x1c),&local_5c);
    *(int *)((int)this + 4) = param_1;
    *(int *)((int)this + 8) = param_2;
    (**(code **)(**(int **)((int)this + 0x68) + 0xc4))(&local_1c,0,10);
    (**(code **)(**(int **)((int)this + 0x68) + 0xc4))(&local_2c,0,0x10);
    (**(code **)(**(int **)((int)this + 0x68) + 0xc4))(&local_3c.right,0,6);
    *(LONG *)((int)this + 0x28) = local_5c.left;
    *(LONG *)((int)this + 0x2c) = local_5c.top;
    *(int *)((int)this + 0x30) = local_1c + local_5c.left;
    local_c = local_2c + local_5c.left;
    *(int *)((int)this + 0x34) = local_18 + local_5c.top;
    local_14 = local_5c.left;
    local_10 = local_5c.top;
    *(LONG *)((int)this + 0x38) = local_5c.left;
    *(LONG *)((int)this + 0x3c) = local_5c.top;
    *(int *)((int)this + 0x40) = local_c;
    *(int *)((int)this + 0x44) = local_28 + local_5c.top;
    local_44 = local_3c.right + local_5c.left;
    local_40 = local_3c.bottom + local_5c.top;
    *(LONG *)((int)this + 0x48) = local_5c.left;
    *(LONG *)((int)this + 0x4c) = local_5c.top;
    *(int *)((int)this + 0x50) = local_44;
    *(int *)((int)this + 0x54) = local_40;
    local_4c = local_5c.left;
    local_48 = local_5c.top;
    *(LONG *)((int)this + 0x58) = local_5c.left;
    *(LONG *)((int)this + 0x5c) = local_5c.top;
    *(int *)((int)this + 0x60) = local_44;
    *(int *)((int)this + 100) = local_40;
    local_8 = local_40;
  }
  FUN_00479b81((LPRECT)((int)this + 0x48),0xc40000);
  FUN_00479b81((LPRECT)((int)this + 0x58),0xc40000);
  InflateRect((LPRECT)((int)this + 0x48),-DAT_004ae648,-DAT_004ae64c);
  InflateRect((LPRECT)((int)this + 0x58),-DAT_004ae648,-DAT_004ae64c);
  FUN_00474836((LPRECT)((int)this + 0x28),param_1,param_2);
  FUN_00474836((LPRECT)((int)this + 0x38),param_1,param_2);
  FUN_00474836((LPRECT)((int)this + 0x48),param_1,param_2);
  FUN_00474836((LPRECT)((int)this + 0x58),param_1,param_2);
  uVar2 = FUN_00475004((int)this);
  *(uint *)((int)this + 0x74) = uVar2;
  FUN_00474875(this,param_1,param_2);
  FUN_00475164(this);
  return;
}

