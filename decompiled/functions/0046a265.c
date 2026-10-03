
undefined4 __fastcall FUN_0046a265(int *param_1)

{
  SHORT SVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = FUN_0046ad0b((int)param_1);
  if (((((uVar2 & 0x40000000) == 0) && (iVar3 = FUN_00455bf0(), iVar3 != 0)) &&
      (SVar1 = GetKeyState(0x10), -1 < SVar1)) &&
     ((SVar1 = GetKeyState(0x11), -1 < SVar1 && (SVar1 = GetKeyState(0x12), -1 < SVar1)))) {
    SendMessageA(*(HWND *)(iVar3 + 0x1c),0x111,0xe146,0);
    return 1;
  }
  uVar4 = FUN_00468021(param_1);
  return uVar4;
}

