
void __thiscall FUN_0047a500(void *this,int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  tagRECT local_30;
  int local_20;
  int local_18;
  code *local_14;
  undefined1 *local_10;
  int local_c;
  int *local_8;
  
  if (param_1 != 0) {
    GetWindowRect(*(HWND *)((int)this + 0x1c),&local_30);
    OffsetRect(&local_30,-local_30.left,-local_30.top);
    FUN_0047a491(this,&local_30.left,1);
    local_14 = *(code **)(*(int *)this + 0xa8);
    (*local_14)();
    param_1 = 0;
    iVar4 = *(int *)((int)this + 0x58);
    iVar5 = (local_30.right - local_30.left) + local_18;
    if (0 < iVar4) {
      piVar1 = (int *)(*(int *)((int)this + 0x5c) + 4);
      iVar3 = iVar4;
      do {
        if ((*(byte *)((int)piVar1 + 7) & 8) != 0) {
          param_1 = param_1 + 1;
        }
        iVar2 = *piVar1;
        piVar1 = piVar1 + 5;
        iVar5 = iVar5 + ((-6 - local_18) - iVar2);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    FUN_00457b90();
    local_c = 0;
    local_10 = &stack0xffffffb8;
    if (0 < iVar4) {
      iVar4 = *(int *)((int)this + 0x5c) + 8;
      local_10 = &stack0xffffffb8;
      local_8 = (int *)&stack0xffffffb8;
      do {
        iVar3 = local_20 + 6 + *(int *)(iVar4 + -4);
        if (((*(byte *)(iVar4 + 3) & 8) != 0) && (0 < iVar5)) {
          iVar2 = iVar5 / param_1;
          iVar3 = iVar3 + iVar2;
          param_1 = param_1 + -1;
          iVar5 = iVar5 - iVar2;
        }
        iVar4 = iVar4 + 0x14;
        piVar1 = local_8 + 1;
        *local_8 = iVar3;
        local_8 = piVar1;
        local_20 = iVar3 + local_18;
        local_c = local_c + 1;
      } while (local_c < *(int *)((int)this + 0x58));
    }
    (*local_14)(0x404,*(undefined4 *)((int)this + 0x58),local_10);
  }
  iVar4 = 0;
  if ((param_2 != 0) && (0 < *(int *)((int)this + 0x58))) {
    iVar5 = *(int *)((int)this + 0x5c) + 0x10;
    do {
      if ((*(byte *)(iVar5 + -4) & 1) != 0) {
        FUN_00471fe5();
      }
      iVar5 = iVar5 + 0x14;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)((int)this + 0x58));
  }
  return;
}

