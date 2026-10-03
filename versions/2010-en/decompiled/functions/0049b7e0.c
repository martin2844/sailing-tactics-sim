
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049b7e0(undefined4 *param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  _SYSTEMTIME local_cc;
  _SYSTEMTIME local_bc;
  _TIME_ZONE_INFORMATION local_ac;
  
  GetLocalTime(&local_bc);
  GetSystemTime(&local_cc);
  if (local_cc.wMinute == DAT_00538462) {
    if (local_cc.wHour == DAT_00538460) {
      if (local_cc.wDay == DAT_0053845e) {
        if (local_cc.wMonth == DAT_0053845a) {
          if (local_cc.wYear == DAT_00538458) goto LAB_0049b8af;
        }
      }
    }
  }
  DVar1 = GetTimeZoneInformation(&local_ac);
  if (DVar1 == 0xffffffff) {
    DAT_00538450 = 0xffffffff;
  }
  else if (((DVar1 == 2) && (local_ac.DaylightDate.wMonth != 0)) && (local_ac.DaylightBias != 0)) {
    DAT_00538450 = 1;
  }
  else {
    DAT_00538450 = 0;
  }
  DAT_00538458 = local_cc.wYear;
  DAT_0053845a = local_cc.wMonth;
  _DAT_0053845c = local_cc.wDayOfWeek;
  DAT_0053845e = local_cc.wDay;
  DAT_00538460 = local_cc.wHour;
  DAT_00538462 = local_cc.wMinute;
  _DAT_00538464 = local_cc.wSecond;
  DAT_00538464_2 = local_cc.wMilliseconds;
LAB_0049b8af:
  uVar2 = FUN_0049e9e0(local_bc.wYear,local_bc.wMonth,local_bc.wDay,local_bc.wHour,local_bc.wMinute,
                       local_bc.wSecond,DAT_00538450);
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = uVar2;
  }
  return;
}

