
void __thiscall FUN_004b8bdc(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
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
  
  *(undefined4 *)(param_1 + 0x88) = 1;
  FUN_004b9472();
  iVar1 = *(int *)(param_1 + 0x68);
  if ((*(uint *)(iVar1 + 100) & 4) == 0) {
    if ((*(uint *)(iVar1 + 100) & 2) == 0) {
      GetWindowRect(*(HWND *)(iVar1 + 0x1c),&local_3c);
      uVar3 = *(uint *)(param_1 + 0x78) & 0xa000;
      *(int *)(param_1 + 4) = param_2;
      *(int *)(param_1 + 8) = param_3;
      (**(code **)(**(int **)(param_1 + 0x68) + 0xc4))
                (&local_c,0xffffffff,(-(uVar3 != 0) & 6U) + 10);
      if (uVar3 == 0) {
        local_4c = local_3c.left;
        *(LONG *)(param_1 + 0x38) = local_3c.left;
        *(LONG *)(param_1 + 0x3c) = local_3c.top;
        local_48 = param_3 - (local_3c.right - local_3c.left) / 2;
        *(LONG *)(param_1 + 0x40) = local_3c.right;
        *(LONG *)(param_1 + 0x44) = local_3c.bottom;
        piVar4 = (int *)(param_1 + 0x28);
      }
      else {
        local_48 = local_3c.top;
        *(LONG *)(param_1 + 0x28) = local_3c.left;
        *(LONG *)(param_1 + 0x2c) = local_3c.top;
        local_4c = param_2 - (local_3c.bottom - local_3c.top) / 2;
        *(LONG *)(param_1 + 0x30) = local_3c.right;
        *(LONG *)(param_1 + 0x34) = local_3c.bottom;
        piVar4 = (int *)(param_1 + 0x38);
      }
      local_40 = local_8 + local_48;
      local_44 = local_4c + local_c;
      *piVar4 = local_4c;
      piVar4[1] = local_48;
      piVar4[2] = local_44;
      piVar4[3] = local_40;
      *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x30);
      *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x34);
      *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x38);
      *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x3c);
      *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x40);
      *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x44);
    }
    else {
      GetWindowRect(*(HWND *)(iVar1 + 0x1c),&local_5c);
      *(int *)(param_1 + 4) = param_2;
      *(int *)(param_1 + 8) = param_3;
      (**(code **)(**(int **)(param_1 + 0x68) + 0xc4))(&local_3c.right,0xffffffff,10);
      (**(code **)(**(int **)(param_1 + 0x68) + 0xc4))(&local_2c,0xffffffff,0x10);
      *(LONG *)(param_1 + 0x28) = local_5c.left;
      *(LONG *)(param_1 + 0x2c) = local_5c.top;
      *(LONG *)(param_1 + 0x30) = local_3c.right + local_5c.left;
      *(LONG *)(param_1 + 0x34) = local_3c.bottom + local_5c.top;
      *(LONG *)(param_1 + 0x48) = local_5c.left;
      *(LONG *)(param_1 + 0x4c) = local_5c.top;
      *(LONG *)(param_1 + 0x50) = local_3c.right + local_5c.left;
      *(LONG *)(param_1 + 0x54) = local_3c.bottom + local_5c.top;
      local_24 = local_5c.left;
      local_1c = local_2c + local_5c.left;
      local_18 = local_28 + local_5c.top;
      local_20 = local_5c.top;
      *(LONG *)(param_1 + 0x38) = local_5c.left;
      *(LONG *)(param_1 + 0x3c) = local_5c.top;
      *(int *)(param_1 + 0x40) = local_1c;
      *(int *)(param_1 + 0x44) = local_18;
      *(LONG *)(param_1 + 0x58) = local_5c.left;
      *(LONG *)(param_1 + 0x5c) = local_5c.top;
      *(int *)(param_1 + 0x60) = local_1c;
      *(int *)(param_1 + 100) = local_18;
    }
  }
  else {
    GetWindowRect(*(HWND *)(iVar1 + 0x1c),&local_5c);
    *(int *)(param_1 + 4) = param_2;
    *(int *)(param_1 + 8) = param_3;
    (**(code **)(**(int **)(param_1 + 0x68) + 0xc4))(&local_1c,0,10);
    (**(code **)(**(int **)(param_1 + 0x68) + 0xc4))(&local_2c,0,0x10);
    (**(code **)(**(int **)(param_1 + 0x68) + 0xc4))(&local_3c.right,0,6);
    *(LONG *)(param_1 + 0x28) = local_5c.left;
    *(LONG *)(param_1 + 0x2c) = local_5c.top;
    *(int *)(param_1 + 0x30) = local_1c + local_5c.left;
    local_c = local_2c + local_5c.left;
    *(int *)(param_1 + 0x34) = local_18 + local_5c.top;
    local_14 = local_5c.left;
    local_10 = local_5c.top;
    *(LONG *)(param_1 + 0x38) = local_5c.left;
    *(LONG *)(param_1 + 0x3c) = local_5c.top;
    *(int *)(param_1 + 0x40) = local_c;
    *(int *)(param_1 + 0x44) = local_28 + local_5c.top;
    local_44 = local_3c.right + local_5c.left;
    local_40 = local_3c.bottom + local_5c.top;
    *(LONG *)(param_1 + 0x48) = local_5c.left;
    *(LONG *)(param_1 + 0x4c) = local_5c.top;
    *(int *)(param_1 + 0x50) = local_44;
    *(int *)(param_1 + 0x54) = local_40;
    local_4c = local_5c.left;
    local_48 = local_5c.top;
    *(LONG *)(param_1 + 0x58) = local_5c.left;
    *(LONG *)(param_1 + 0x5c) = local_5c.top;
    *(int *)(param_1 + 0x60) = local_44;
    *(int *)(param_1 + 100) = local_40;
    local_8 = local_40;
  }
  FUN_004be261(param_1 + 0x48,0xc40000,0);
  FUN_004be261((LPRECT)(param_1 + 0x58),0xc40000,0);
  InflateRect((LPRECT)(param_1 + 0x48),-DAT_005381a0,-DAT_005381a4);
  InflateRect((LPRECT)(param_1 + 0x58),-DAT_005381a0,-DAT_005381a4);
  FUN_004b8f16(param_1 + 0x28,param_2,param_3);
  FUN_004b8f16(param_1 + 0x38,param_2,param_3);
  FUN_004b8f16(param_1 + 0x48,param_2,param_3);
  FUN_004b8f16(param_1 + 0x58,param_2,param_3);
  uVar2 = FUN_004b96e4();
  *(undefined4 *)(param_1 + 0x74) = uVar2;
  FUN_004b8f55(param_2,param_3);
  FUN_004b9844();
  return;
}

