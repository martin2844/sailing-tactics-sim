
void __thiscall FUN_00474e9c(void *this,int param_1)

{
  int iVar1;
  LONG *pLVar2;
  tagRECT local_28;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_18 = 1;
  local_14 = 1;
  GetStockObject(0);
  iVar1 = FUN_00470a17();
  local_10 = iVar1;
  local_8 = FUN_00478763();
  local_c = iVar1;
  if ((*(uint *)((int)this + 0x74) & 0xa000) == 0) {
    if ((*(uint *)((int)this + 0x74) & 0x5000) == 0) {
      local_18 = GetSystemMetrics(0x20);
      local_18 = local_18 + -1;
      local_14 = GetSystemMetrics(0x21);
      local_14 = local_14 + -1;
      if ((((*(uint *)((int)this + 0x78) & 0xa000) == 0) || (*(int *)((int)this + 0x7c) != 0)) &&
         (((*(uint *)((int)this + 0x78) & 0x5000) == 0 || (*(int *)((int)this + 0x7c) == 0)))) {
        pLVar2 = (LONG *)((int)this + 0x58);
      }
      else {
        pLVar2 = (LONG *)((int)this + 0x48);
      }
      local_28.left = *pLVar2;
      local_28.top = pLVar2[1];
      local_28.right = pLVar2[2];
      local_28.bottom = pLVar2[3];
      local_c = local_8;
      goto LAB_00474f33;
    }
    pLVar2 = (LONG *)((int)this + 0x38);
  }
  else {
    pLVar2 = (LONG *)((int)this + 0x28);
  }
  local_28.left = *pLVar2;
  local_28.top = pLVar2[1];
  local_28.right = pLVar2[2];
  local_28.bottom = pLVar2[3];
LAB_00474f33:
  if (param_1 != 0) {
    local_14 = 0;
    local_18 = 0;
  }
  if ((DAT_004ae694 != 0) && ((*(byte *)((int)this + 0x75) & 0xf0) != 0)) {
    InflateRect(&local_28,-1,-1);
  }
  FUN_004787d6();
  *(LONG *)((int)this + 0xc) = local_28.left;
  *(int *)((int)this + 0x1c) = local_18;
  *(LONG *)((int)this + 0x10) = local_28.top;
  *(LONG *)((int)this + 0x14) = local_28.right;
  *(int *)((int)this + 0x20) = local_14;
  *(LONG *)((int)this + 0x18) = local_28.bottom;
  *(uint *)((int)this + 0x24) = (uint)(local_c == local_8);
  return;
}

