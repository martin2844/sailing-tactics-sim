
undefined4 __fastcall FUN_004baf55(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004adeef();
  if (*(int *)(iVar1 + 0x50) == 0) {
    uVar2 = FUN_004ac701(param_1);
  }
  else {
    SetCursor(DAT_005381d4);
    uVar2 = 1;
  }
  return uVar2;
}

