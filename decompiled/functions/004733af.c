
undefined4 __thiscall FUN_004733af(void *this,undefined4 param_1,int *param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  tagRECT local_24;
  int local_14;
  int local_10;
  int local_c;
  void *local_8;
  
  local_c = *(int *)this;
  local_8 = this;
  uVar1 = (**(code **)(local_c + 0xd4))(param_2);
  if (((uVar1 & 0x10000000) != 0) && ((uVar1 & 0xf000) != 0)) {
    CopyRect(&local_24,(RECT *)(param_2 + 1));
    iVar4 = local_24.right - local_24.left;
    iVar3 = local_24.bottom - local_24.top;
    bVar5 = param_2[7] != 0;
    if (((*(uint *)((int)local_8 + 100) & 4) == 0) || ((*(uint *)((int)local_8 + 100) & 1) == 0)) {
      if ((uVar1 & 0xa000) == 0) {
        bVar2 = bVar5 | 0x10;
      }
      else {
        bVar2 = bVar5 | 10;
      }
    }
    else {
      bVar2 = bVar5 | 6;
    }
    (**(code **)(local_c + 0xc4))(&local_14,0xffffffff,bVar2);
    if (iVar4 <= local_14) {
      local_14 = iVar4;
    }
    if (iVar3 <= local_10) {
      local_10 = iVar3;
    }
    if ((uVar1 & 0xa000) == 0) {
      if ((uVar1 & 0x5000) != 0) {
        param_2[5] = param_2[5] + local_14;
        iVar3 = param_2[6];
        if (param_2[6] <= local_10) {
          iVar3 = local_10;
        }
        param_2[6] = iVar3;
        if ((uVar1 & 0x1000) == 0) {
          if ((uVar1 & 0x4000) != 0) {
            local_24.left = local_24.right - local_14;
            param_2[3] = param_2[3] - local_14;
          }
        }
        else {
          param_2[1] = param_2[1] + local_14;
        }
      }
    }
    else {
      param_2[6] = param_2[6] + local_10;
      iVar3 = param_2[5];
      if (param_2[5] <= local_14) {
        iVar3 = local_14;
      }
      param_2[5] = iVar3;
      if ((uVar1 & 0x2000) == 0) {
        if ((uVar1 & 0x8000) != 0) {
          local_24.top = local_24.bottom - local_10;
          param_2[4] = param_2[4] - local_10;
        }
      }
      else {
        param_2[2] = param_2[2] + local_10;
      }
    }
    local_24.right = local_14 + local_24.left;
    local_24.bottom = local_10 + local_24.top;
    if (*param_2 != 0) {
      FUN_00469d00(param_2,*(HWND *)((int)local_8 + 0x1c),&local_24);
    }
  }
  return 0;
}

