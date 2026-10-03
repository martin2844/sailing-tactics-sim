
void __thiscall FUN_004b957c(int param_1,int param_2)

{
  HGDIOBJ pvVar1;
  int iVar2;
  LONG *pLVar3;
  tagRECT local_28;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_18 = 1;
  local_14 = 1;
  pvVar1 = GetStockObject(0);
  iVar2 = FUN_004b50f7(pvVar1);
  local_10 = iVar2;
  local_8 = FUN_004bce43();
  local_c = iVar2;
  if ((*(uint *)(param_1 + 0x74) & 0xa000) == 0) {
    if ((*(uint *)(param_1 + 0x74) & 0x5000) == 0) {
      local_18 = GetSystemMetrics(0x20);
      local_18 = local_18 + -1;
      local_14 = GetSystemMetrics(0x21);
      local_14 = local_14 + -1;
      if ((((*(uint *)(param_1 + 0x78) & 0xa000) == 0) || (*(int *)(param_1 + 0x7c) != 0)) &&
         (((*(uint *)(param_1 + 0x78) & 0x5000) == 0 || (*(int *)(param_1 + 0x7c) == 0)))) {
        pLVar3 = (LONG *)(param_1 + 0x58);
      }
      else {
        pLVar3 = (LONG *)(param_1 + 0x48);
      }
      local_28.left = *pLVar3;
      local_28.top = pLVar3[1];
      local_28.right = pLVar3[2];
      local_28.bottom = pLVar3[3];
      local_c = local_8;
      goto LAB_004b9613;
    }
    pLVar3 = (LONG *)(param_1 + 0x38);
  }
  else {
    pLVar3 = (LONG *)(param_1 + 0x28);
  }
  local_28.left = *pLVar3;
  local_28.top = pLVar3[1];
  local_28.right = pLVar3[2];
  local_28.bottom = pLVar3[3];
LAB_004b9613:
  if (param_2 != 0) {
    local_14 = 0;
    local_18 = 0;
  }
  if ((DAT_005381ec != 0) && ((*(byte *)(param_1 + 0x75) & 0xf0) != 0)) {
    InflateRect(&local_28,-1,-1);
  }
  iVar2 = local_8;
  if (*(int *)(param_1 + 0x24) == 0) {
    iVar2 = local_10;
  }
  FUN_004bceb6(&local_28,local_18,local_14,(LONG *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x1c),
               *(undefined4 *)(param_1 + 0x20),local_c,iVar2);
  *(LONG *)(param_1 + 0xc) = local_28.left;
  *(int *)(param_1 + 0x1c) = local_18;
  *(LONG *)(param_1 + 0x10) = local_28.top;
  *(LONG *)(param_1 + 0x14) = local_28.right;
  *(int *)(param_1 + 0x20) = local_14;
  *(LONG *)(param_1 + 0x18) = local_28.bottom;
  *(uint *)(param_1 + 0x24) = (uint)(local_c == local_8);
  return;
}

