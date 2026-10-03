
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  byte bVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  HMODULE pHVar5;
  byte *pbVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar8;
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  undefined4 local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  byte *pbVar7;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004d0870;
  pcStack_10 = FUN_0049e908;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  local_1c = &stack0xffffff88;
  DVar2 = GetVersion();
  _DAT_0053848c = DVar2 >> 8 & 0xff;
  _DAT_00538488 = DVar2 & 0xff;
  _DAT_00538484 = _DAT_00538488 * 0x100 + _DAT_0053848c;
  _DAT_00538480 = DVar2 >> 0x10;
  iVar3 = FUN_0049fb80();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  iVar3 = FUN_0049e530();
  if (iVar3 == 0) {
    __amsg_exit(0x10);
  }
  local_8 = 0;
  FUN_0049f970();
  FUN_0049d2b0();
  DAT_00539a4c = (byte *)GetCommandLineA();
  DAT_00538470 = FUN_0049f810();
  if ((DAT_00538470 == 0) || (DAT_00539a4c == (byte *)0x0)) {
    FUN_0049c500(0xffffffff);
  }
  FUN_0049f560();
  FUN_0049f470();
  FUN_0049c4d0();
  pbVar6 = DAT_00539a4c;
  if (*DAT_00539a4c == 0x22) {
    while( true ) {
      pbVar7 = pbVar6;
      pbVar6 = pbVar7 + 1;
      bVar1 = *pbVar6;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      iVar3 = FUN_0049f410(bVar1);
      if (iVar3 != 0) {
        pbVar6 = pbVar7 + 2;
      }
    }
    if (*pbVar6 == 0x22) {
      pbVar6 = pbVar7 + 2;
    }
  }
  else {
    for (; 0x20 < *pbVar6; pbVar6 = pbVar6 + 1) {
    }
  }
  for (; (*pbVar6 != 0 && (*pbVar6 < 0x21)); pbVar6 = pbVar6 + 1) {
  }
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  if ((local_60.dwFlags & 1) == 0) {
    uVar4 = 10;
  }
  else {
    uVar4 = local_60._48_4_ & 0xffff;
  }
  uVar8 = 0;
  pHVar5 = GetModuleHandleA((LPCSTR)0x0);
  uVar8 = FUN_004aa657(pHVar5,uVar8,pbVar6,uVar4);
  FUN_0049c500(uVar8);
  *unaff_FS_OFFSET = local_14;
  return;
}

