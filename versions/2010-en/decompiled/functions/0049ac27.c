
undefined4 __thiscall FUN_0049ac27(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  iVar1 = FUN_004bfca5();
  iVar2 = *(int *)(iVar1 + 0xcc);
  if (param_2 == 0) {
    if ((*(byte *)(param_1 + 0x24) & 1) != 0) {
      if (*(int *)(iVar1 + 0xd0) == param_1) {
        FUN_004ad107(1);
      }
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar2 + 0x1c);
      }
      if (iVar1 != 0) {
        _memset(&local_30,0,0x2c);
        local_28 = *(undefined4 *)(param_1 + 0x1c);
        local_30 = 0x2c;
        local_2c = 1;
        local_24 = local_28;
        SendMessageA(*(HWND *)(iVar2 + 0x1c),0x405,0,(LPARAM)&local_30);
      }
      *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0xfffffffe;
    }
  }
  else if ((*(byte *)(param_1 + 0x24) & 1) == 0) {
    iVar2 = FUN_004bfff8();
    *(code **)(iVar2 + 0x1034) = FUN_0049acc9;
    *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 1;
  }
  return 1;
}

