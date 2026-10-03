
void __cdecl FUN_0042a280(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_004ab180;
  iVar1 = *(int *)(&DAT_004a7bc8 + param_1 * 4);
  *(undefined4 *)(&DAT_004ac5f0 + param_1 * 4) = 0;
  if ((iVar1 < iVar2) && (iVar2 + -8 <= iVar1)) {
    *(undefined4 *)(&DAT_004ac5f0 + param_1 * 4) = 0x1e;
  }
  if (iVar1 < iVar2 + -8) {
    *(undefined4 *)(&DAT_004ac5f0 + param_1 * 4) = 100;
  }
  return;
}

