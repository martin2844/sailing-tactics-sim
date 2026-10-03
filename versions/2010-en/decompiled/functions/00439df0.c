
void __cdecl FUN_00439df0(int param_1)

{
  if ((((DAT_00536484 < 1) && (DAT_004f42b8 + 10 <= DAT_004f8cd0)) && (DAT_004f8cd0 != DAT_004da27c)
      ) && ((DAT_004f8cd0 != DAT_004da27c + 1 && (DAT_004f8cd0 != DAT_004da27c + 2)))) {
    if (param_1 == 1) {
      PlaySoundA((LPCSTR)0x8d,DAT_005359c8,0x40005);
      DAT_004da27c = DAT_004f8cd0;
    }
    if (param_1 == 2) {
      PlaySoundA((LPCSTR)0x87,DAT_005359c8,0x40005);
      DAT_004da27c = DAT_004f8cd0;
    }
  }
  return;
}

