
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00428a30(int param_1)

{
  if ((DAT_004ac9c0 < 1) && (DAT_004a4168 + 10 <= DAT_004a5b80)) {
    if (param_1 == 1) {
      PlaySoundA((LPCSTR)0x8d,DAT_004ac1d4,0x40015);
      _DAT_004aca08 = DAT_004a5b80;
    }
    if (param_1 == 2) {
      PlaySoundA((LPCSTR)0x87,DAT_004ac1d4,0x40015);
      _DAT_004aca08 = DAT_004a5b80;
    }
  }
  return;
}

