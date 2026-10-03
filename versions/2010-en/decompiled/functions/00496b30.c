
void __thiscall FUN_00496b30(void *this)

{
  int iVar1;
  
  DAT_004da144 = 0x14;
  DAT_004da1f8 = 0;
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,1);
  DAT_00536498 = 1;
  DAT_004da14c = 1;
  DAT_004da194 = 10;
  DAT_004da1e8 = 0;
  iVar1 = FUN_0041e000(100);
  DAT_004da19c = (iVar1 < 0x32) + 0xc;
  return;
}

