
void FUN_004a7f20(void)

{
  int iVar1;
  CHAR local_c [12];
  
  if (DAT_0053a585 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
    DAT_0053a584 = 0x1e;
    GetProfileStringA(s_windows_004f14dc,s_kanjimenu_004f14d0,s_roman_004f14bc,local_c,9);
    iVar1 = lstrcmpiA(local_c,s_kanji_004f14b4);
    if (iVar1 == 0) {
      DAT_0053a584 = 0x1f;
    }
    GetProfileStringA(s_windows_004f14dc,s_hangeulmenu_004f14c4,"english",local_c,9);
    iVar1 = lstrcmpiA(local_c,s_hangeul_004f14ac);
    if (iVar1 == 0) {
      DAT_0053a584 = 0x1f;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00539a60);
  }
  return;
}

