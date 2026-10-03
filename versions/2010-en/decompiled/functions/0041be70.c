
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041be70(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((((DAT_004da188 == 3) || (DAT_004da188 == 4)) || (DAT_004da188 == 6)) || (DAT_004da19c == 8))
  {
    DAT_004da1e8 = 0;
  }
  DAT_005364e0 = 0;
  FUN_0042c060();
  DAT_005363f4 = 0;
  DAT_005359f4 = 0xc0655000;
  _DAT_00500418 = (-(uint)(DAT_004da19c != 8) & 0xfffffe89) + 0x2a3;
  DAT_004f42b8 = 0xffffff56;
  DAT_004f8cd0 = 0xffffff56;
  if (DAT_004da1d8 < 3) {
    DAT_004f42b8 = 0;
    DAT_004f8cd0 = 0;
    DAT_005359f4 = 0;
  }
  if (DAT_004da1d8 == 10) {
    DAT_004f42b8 = 0xfffffeac;
    DAT_004f8cd0 = 0xfffffeac;
    DAT_005359f4 = 0xc0755000;
  }
  DAT_005359f0 = 0;
  _DAT_00534d68 = (double)((ulonglong)DAT_005359f4 << 0x20) * _DAT_004cc768;
  _DAT_00535bc0 = (ulonglong)DAT_005359f4 << 0x20;
  if (DAT_004da1f8 < 999) {
    DAT_00536510 = 0;
  }
  FUN_00426ab0();
  FUN_00427090();
  FUN_00427540();
  FUN_00441400();
  FUN_0042dea0(1);
  FUN_0042b2e0();
  iVar2 = 1;
  puVar1 = &DAT_00523634;
  do {
    *puVar1 = 0xfffffed4;
    FUN_0042b0b0(iVar2);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0x523645);
  return;
}

