
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00456f10(int *param_1)

{
  DWORD DVar1;
  int iVar2;
  _SYSTEMTIME local_cc;
  _SYSTEMTIME local_bc;
  _TIME_ZONE_INFORMATION local_ac;
  
  GetLocalTime(&local_bc);
  GetSystemTime(&local_cc);
  if (local_cc.wMinute == DAT_004ae90a) {
    if (local_cc.wHour == DAT_004ae908) {
      if (local_cc.wDay == DAT_004ae906) {
        if (local_cc.wMonth == DAT_004ae902) {
          if (local_cc.wYear == DAT_004ae900) goto LAB_00456fdf;
        }
      }
    }
  }
  DVar1 = GetTimeZoneInformation(&local_ac);
  if (DVar1 == 0xffffffff) {
    DAT_004ae8f8 = -1;
  }
  else if (((DVar1 == 2) && (local_ac.DaylightDate.wMonth != 0)) && (local_ac.DaylightBias != 0)) {
    DAT_004ae8f8 = 1;
  }
  else {
    DAT_004ae8f8 = 0;
  }
  DAT_004ae900 = local_cc.wYear;
  DAT_004ae902 = local_cc.wMonth;
  _DAT_004ae904 = local_cc.wDayOfWeek;
  DAT_004ae906 = local_cc.wDay;
  DAT_004ae908 = local_cc.wHour;
  DAT_004ae90a = local_cc.wMinute;
  _DAT_004ae90c = local_cc.wSecond;
  DAT_004ae90c_2 = local_cc.wMilliseconds;
LAB_00456fdf:
  iVar2 = FUN_0045a220((uint)local_bc.wYear,(uint)local_bc.wMonth,(uint)local_bc.wDay,
                       (uint)local_bc.wHour,(uint)local_bc.wMinute,(uint)local_bc.wSecond,
                       DAT_004ae8f8);
  if (param_1 != (int *)0x0) {
    *param_1 = iVar2;
  }
  return;
}

