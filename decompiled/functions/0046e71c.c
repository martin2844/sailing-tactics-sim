
void __cdecl FUN_0046e71c(void *param_1,LPFILETIME param_2)

{
  tm *ptVar1;
  BOOL BVar2;
  DWORD DVar3;
  SYSTEMTIME local_1c;
  _FILETIME local_c;
  
  ptVar1 = FUN_00466840(param_1,(tm *)0x0);
  local_1c.wYear = (short)ptVar1->tm_year + 0x76c;
  ptVar1 = FUN_00466840(param_1,(tm *)0x0);
  local_1c.wMonth = (short)ptVar1->tm_mon + 1;
  ptVar1 = FUN_00466840(param_1,(tm *)0x0);
  local_1c.wDay = (WORD)ptVar1->tm_mday;
  ptVar1 = FUN_00466840(param_1,(tm *)0x0);
  local_1c.wHour = (WORD)ptVar1->tm_hour;
  ptVar1 = FUN_00466840(param_1,(tm *)0x0);
  local_1c.wMinute = (WORD)ptVar1->tm_min;
  ptVar1 = FUN_00466840(param_1,(tm *)0x0);
  local_1c.wMilliseconds = 0;
  local_1c.wSecond = (WORD)ptVar1->tm_sec;
  BVar2 = SystemTimeToFileTime(&local_1c,&local_c);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    FUN_0046e0e6(DVar3);
  }
  BVar2 = LocalFileTimeToFileTime(&local_c,param_2);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    FUN_0046e0e6(DVar3);
  }
  return;
}

