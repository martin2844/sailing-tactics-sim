
void __cdecl FUN_0042a8a0(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = DAT_004aa998 / 6;
  if (((param_1 <= DAT_00491140) && (DAT_004ac9c0 == 0)) && (-0xa8 < DAT_004a5b80)) {
    PlaySoundA((LPCSTR)0x89,DAT_004ac1d4,0x40005);
  }
  FUN_00421c40(param_1);
  iVar2 = FUN_00415a20(uVar1);
  *(double *)(&DAT_004a49e8 + param_1 * 8) = (double)(iVar2 + (DAT_004a4be0 - (int)uVar1 / 2));
  iVar2 = FUN_00415a20(uVar1);
  *(double *)(&DAT_004a4ae0 + param_1 * 8) = (double)(iVar2 + (DAT_004a4f84 - (int)uVar1 / 2));
  return;
}

