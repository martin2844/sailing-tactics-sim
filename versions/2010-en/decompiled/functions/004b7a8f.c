
undefined4 __thiscall FUN_004b7a8f(int *param_1,undefined4 param_2,int *param_3)

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
  int *local_8;
  
  local_c = *param_1;
  local_8 = param_1;
  uVar1 = (**(code **)(local_c + 0xd4))(param_3);
  if (((uVar1 & 0x10000000) != 0) && ((uVar1 & 0xf000) != 0)) {
    CopyRect(&local_24,(RECT *)(param_3 + 1));
    iVar4 = local_24.right - local_24.left;
    iVar3 = local_24.bottom - local_24.top;
    bVar5 = param_3[7] != 0;
    if (((local_8[0x19] & 4U) == 0) || ((local_8[0x19] & 1U) == 0)) {
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
        param_3[5] = param_3[5] + local_14;
        iVar3 = param_3[6];
        if (param_3[6] <= local_10) {
          iVar3 = local_10;
        }
        param_3[6] = iVar3;
        if ((uVar1 & 0x1000) == 0) {
          if ((uVar1 & 0x4000) != 0) {
            local_24.left = local_24.right - local_14;
            param_3[3] = param_3[3] - local_14;
          }
        }
        else {
          param_3[1] = param_3[1] + local_14;
        }
      }
    }
    else {
      param_3[6] = param_3[6] + local_10;
      iVar3 = param_3[5];
      if (param_3[5] <= local_14) {
        iVar3 = local_14;
      }
      param_3[5] = iVar3;
      if ((uVar1 & 0x2000) == 0) {
        if ((uVar1 & 0x8000) != 0) {
          local_24.top = local_24.bottom - local_10;
          param_3[4] = param_3[4] - local_10;
        }
      }
      else {
        param_3[2] = param_3[2] + local_10;
      }
    }
    local_24.right = local_14 + local_24.left;
    local_24.bottom = local_10 + local_24.top;
    if (*param_3 != 0) {
      FUN_004ae3e0(param_3,local_8[7],&local_24);
    }
  }
  return 0;
}

