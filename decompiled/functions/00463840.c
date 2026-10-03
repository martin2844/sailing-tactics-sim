
void FUN_00463840(void)

{
  int iVar1;
  CHAR local_c [12];
  
  if (DAT_004b0a45 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
    DAT_004b0a44 = 0x1e;
    GetProfileStringA(s_windows_004a331c,s_kanjimenu_004a3310,s_roman_004a32fc,local_c,9);
    iVar1 = lstrcmpiA(local_c,s_kanji_004a32f4);
    if (iVar1 == 0) {
      DAT_004b0a44 = 0x1f;
    }
    GetProfileStringA(s_windows_004a331c,s_hangeulmenu_004a3304,"english",local_c,9);
    iVar1 = lstrcmpiA(local_c,s_hangeul_004a32ec);
    if (iVar1 == 0) {
      DAT_004b0a44 = 0x1f;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004aff20);
  }
  return;
}

