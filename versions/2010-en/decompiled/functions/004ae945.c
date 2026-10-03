
undefined4 __fastcall FUN_004ae945(undefined4 param_1)

{
  SHORT SVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = FUN_004af3eb();
  if (((((uVar2 & 0x40000000) == 0) && (iVar3 = FUN_0049a2e0(), iVar3 != 0)) &&
      (SVar1 = GetKeyState(0x10), -1 < SVar1)) &&
     ((SVar1 = GetKeyState(0x11), -1 < SVar1 && (SVar1 = GetKeyState(0x12), -1 < SVar1)))) {
    SendMessageA(*(HWND *)(iVar3 + 0x1c),0x111,0xe146,0);
    return 1;
  }
  uVar4 = FUN_004ac701(param_1);
  return uVar4;
}

