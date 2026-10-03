
undefined4 __thiscall FUN_004bd4c7(void *this)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  HWND pHVar4;
  int iVar5;
  LRESULT LVar6;
  
  iVar2 = FUN_004ac701();
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = FUN_004af3eb();
  if ((uVar3 & 0x100) == 0) {
    return 1;
  }
  iVar2 = FUN_004ade0b();
  pHVar4 = GetForegroundWindow();
  iVar5 = FUN_004ac7ac(pHVar4);
  if (iVar2 != iVar5) {
    pHVar4 = GetLastActivePopup(*(HWND *)(iVar2 + 0x1c));
    iVar2 = FUN_004ac7ac(pHVar4);
    if ((iVar2 != iVar5) || (LVar6 = SendMessageA(*(HWND *)(iVar5 + 0x1c),0x36d,0x40,0), LVar6 == 0)
       ) {
      bVar1 = 0;
      goto LAB_004bd535;
    }
  }
  bVar1 = 1;
LAB_004bd535:
  SendMessageA(*(HWND *)((int)this + 0x1c),0x36d,(-(uint)bVar1 & 0xfffffffc) + 8,0);
  return 1;
}

