
int __cdecl
FUN_0045a220(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  tm local_24;
  
  uVar2 = param_1 - 0x76c;
  if (((int)uVar2 < 0x46) || (0x8a < (int)uVar2)) {
    return -1;
  }
  iVar3 = *(int *)(&DAT_004a23a4 + param_2 * 4) + param_3;
  if (((uVar2 & 3) == 0) && (2 < param_2)) {
    iVar3 = iVar3 + 1;
  }
  FUN_0045d700();
  local_24.tm_hour = param_4;
  local_24.tm_mon = param_2 + -1;
  iVar1 = param_6 + (param_5 +
                    (param_4 + ((param_1 + -0x76d >> 2) + uVar2 * 0x16d + iVar3) * 0x18) * 0x3c) *
                    0x3c + 0x7c558180 + DAT_004a22b8;
  if (param_7 != 1) {
    if (param_7 != -1) {
      return iVar1;
    }
    if (DAT_004a22bc == 0) {
      return iVar1;
    }
    local_24.tm_year = uVar2;
    local_24.tm_yday = iVar3;
    iVar3 = __isindst(&local_24);
    if (iVar3 == 0) {
      return iVar1;
    }
  }
  return iVar1 + DAT_004a22c0;
}

