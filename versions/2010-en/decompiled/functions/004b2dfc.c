
void FUN_004b2dfc(undefined4 param_1,LPFILETIME param_2)

{
  int iVar1;
  undefined4 *puVar2;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  SYSTEMTIME local_1c;
  _FILETIME local_c;
  
  iVar1 = FUN_004aaf20(0);
  local_1c.wYear = (short)*(undefined4 *)(iVar1 + 0x14) + 0x76c;
  iVar1 = FUN_004aaf20(0);
  local_1c.wMonth = (short)*(undefined4 *)(iVar1 + 0x10) + 1;
  iVar1 = FUN_004aaf20(0);
  local_1c.wDay = (WORD)*(undefined4 *)(iVar1 + 0xc);
  iVar1 = FUN_004aaf20(0);
  local_1c.wHour = (WORD)*(undefined4 *)(iVar1 + 8);
  iVar1 = FUN_004aaf20(0);
  local_1c.wMinute = (WORD)*(undefined4 *)(iVar1 + 4);
  puVar2 = (undefined4 *)FUN_004aaf20(0);
  local_1c.wMilliseconds = 0;
  local_1c.wSecond = (WORD)*puVar2;
  BVar3 = SystemTimeToFileTime(&local_1c,&local_c);
  if (BVar3 == 0) {
    uVar5 = 0;
    DVar4 = GetLastError();
    FUN_004b27c6(DVar4,uVar5);
  }
  BVar3 = LocalFileTimeToFileTime(&local_c,param_2);
  if (BVar3 == 0) {
    uVar5 = 0;
    DVar4 = GetLastError();
    FUN_004b27c6(DVar4,uVar5);
  }
  return;
}

