
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  byte bVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  HMODULE pHVar5;
  UINT UVar6;
  byte *pbVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar9;
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  undefined4 local_14;
  code *pcStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  byte *pbVar8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_00488ba0;
  pcStack_10 = FUN_0045b408;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  local_1c = &stack0xffffff88;
  DVar2 = GetVersion();
  _DAT_004ae934 = DVar2 >> 8 & 0xff;
  _DAT_004ae930 = DVar2 & 0xff;
  _DAT_004ae92c = _DAT_004ae930 * 0x100 + _DAT_004ae934;
  _DAT_004ae928 = DVar2 >> 0x10;
  iVar3 = FUN_0045b3c0();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  iVar3 = FUN_00459e50();
  if (iVar3 == 0) {
    __amsg_exit(0x10);
  }
  local_8 = 0;
  FUN_0045b1b0();
  FUN_00458bb0();
  DAT_004aff0c = (byte *)GetCommandLineA();
  DAT_004ae918 = FUN_0045b050();
  if ((DAT_004ae918 == (LPSTR)0x0) || (DAT_004aff0c == (byte *)0x0)) {
    FUN_00457c40(0xffffffff);
  }
  FUN_0045ada0();
  FUN_0045acb0();
  FUN_00457c10();
  pbVar7 = DAT_004aff0c;
  if (*DAT_004aff0c == 0x22) {
    while( true ) {
      pbVar8 = pbVar7;
      pbVar7 = pbVar8 + 1;
      bVar1 = *pbVar7;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      iVar3 = FUN_0045ac50((uint)bVar1);
      if (iVar3 != 0) {
        pbVar7 = pbVar8 + 2;
      }
    }
    if (*pbVar7 == 0x22) {
      pbVar7 = pbVar8 + 2;
    }
  }
  else {
    for (; 0x20 < *pbVar7; pbVar7 = pbVar7 + 1) {
    }
  }
  for (; (*pbVar7 != 0 && (*pbVar7 < 0x21)); pbVar7 = pbVar7 + 1) {
  }
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  if ((local_60.dwFlags & 1) == 0) {
    uVar4 = 10;
  }
  else {
    uVar4 = local_60._48_4_ & 0xffff;
  }
  uVar9 = 0;
  pHVar5 = GetModuleHandleA((LPCSTR)0x0);
  UVar6 = FUN_00465f77(pHVar5,uVar9,pbVar7,uVar4);
  FUN_00457c40(UVar6);
  FUN_0045730e();
  return;
}

