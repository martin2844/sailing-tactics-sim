
void __cdecl FUN_0043c980(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00523598 / 6;
  if (((param_1 <= DAT_004da140) && (DAT_00536484 == 0)) && (DAT_004f42b8 + 10 < DAT_004f8cd0)) {
    PlaySoundA((LPCSTR)0x89,DAT_005359c8,0x40005);
  }
  FUN_00431960(param_1);
  iVar2 = FUN_0041e000(iVar1);
  *(double *)(&DAT_004f6af8 + param_1 * 8) = (double)(iVar2 + (DAT_004f6d38 - iVar1 / 2));
  iVar2 = FUN_0041e000(iVar1);
  *(double *)(&DAT_004f6c10 + param_1 * 8) = (double)(iVar2 + (DAT_004f7f88 - iVar1 / 2));
  return;
}

