
undefined4 __thiscall FUN_00456537(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  iVar1 = FUN_0047b5c5();
  iVar2 = *(int *)(iVar1 + 0xcc);
  if (param_1 == 0) {
    if ((*(byte *)((int)this + 0x24) & 1) != 0) {
      if (*(void **)(iVar1 + 0xd0) == this) {
        FUN_00468a27(1);
      }
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar2 + 0x1c);
      }
      if (iVar1 != 0) {
        _memset(&local_30,0,0x2c);
        local_28 = *(undefined4 *)((int)this + 0x1c);
        local_30 = 0x2c;
        local_2c = 1;
        local_24 = local_28;
        SendMessageA(*(HWND *)(iVar2 + 0x1c),0x405,0,(LPARAM)&local_30);
      }
      *(uint *)((int)this + 0x24) = *(uint *)((int)this + 0x24) & 0xfffffffe;
    }
  }
  else if ((*(byte *)((int)this + 0x24) & 1) == 0) {
    iVar2 = FUN_0047b918();
    *(code **)(iVar2 + 0x1034) = FUN_004565d9;
    *(uint *)((int)this + 0x24) = *(uint *)((int)this + 0x24) | 1;
  }
  return 1;
}

