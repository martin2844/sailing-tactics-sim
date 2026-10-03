
bool __thiscall FUN_0046b8a1(void *this,int param_1)

{
  void *pvVar1;
  BOOL BVar2;
  int iVar3;
  void *this_00;
  
  if (param_1 < 1) {
    pvVar1 = *(void **)((int)this + 0x1c);
    if ((pvVar1 != (void *)0x0) && (*(HWND *)((int)pvVar1 + 0x1c) != (HWND)0x0)) {
      BVar2 = IsWindowVisible(*(HWND *)((int)pvVar1 + 0x1c));
      if (BVar2 != 0) {
        FUN_00467e60();
        FUN_0046996c(*(HWND *)((int)pvVar1 + 0x1c),0x363,1,0,1,1);
      }
    }
    iVar3 = FUN_0047b918();
    iVar3 = FUN_0047be12((void *)(iVar3 + 0x1070),FUN_00455cc2);
    for (this_00 = *(void **)(iVar3 + 8); this_00 != (void *)0x0;
        this_00 = *(void **)((int)this_00 + 0x54)) {
      if ((*(int *)((int)this_00 + 0x1c) != 0) && (this_00 != pvVar1)) {
        if (*(int *)((int)this_00 + 0x88) == 0) {
          FUN_0046ae4c(this_00,0);
        }
        BVar2 = IsWindowVisible(*(HWND *)((int)this_00 + 0x1c));
        if ((BVar2 != 0) || (-1 < *(int *)((int)this_00 + 0x88))) {
          FUN_00467e60();
          FUN_0046996c(*(HWND *)((int)this_00 + 0x1c),0x363,1,0,1,1);
        }
        if (0 < *(int *)((int)this_00 + 0x88)) {
          FUN_0046ae4c(this_00,*(int *)((int)this_00 + 0x88));
        }
        *(undefined4 *)((int)this_00 + 0x88) = 0xffffffff;
      }
    }
  }
  else {
    iVar3 = FUN_0047b918();
    iVar3 = FUN_0047be12((void *)(iVar3 + 0x1070),FUN_00455cc2);
    if (*(int *)(iVar3 + 0x10) == 0) {
      FUN_0046d43a();
      FUN_0046d443(1);
    }
  }
  return param_1 < 0;
}

