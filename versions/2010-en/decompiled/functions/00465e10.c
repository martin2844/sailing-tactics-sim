
void __cdecl FUN_00465e10(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 * 8;
  *(undefined4 *)(&DAT_0050f818 + iVar1) = *(undefined4 *)(&DAT_004f1610 + iVar1);
  *(undefined4 *)(&DAT_0050f81c + iVar1) = *(undefined4 *)(&DAT_004f1614 + iVar1);
  *(undefined4 *)(&DAT_00523e80 + iVar1) = *(undefined4 *)(&DAT_004f3868 + iVar1);
  *(undefined4 *)(&DAT_00523e84 + iVar1) = *(undefined4 *)(&DAT_004f386c + iVar1);
  iVar2 = 0x13;
  do {
    *(undefined4 *)(&DAT_00510ea8 + iVar1) = *(undefined4 *)(&DAT_00510d78 + iVar1);
    *(undefined4 *)(&DAT_00510eac + iVar1) = *(undefined4 *)(&DAT_00510d7c + iVar1);
    *(undefined4 *)(&DAT_00525510 + iVar1) = *(undefined4 *)(&DAT_005253e0 + iVar1);
    *(undefined4 *)(&DAT_00525514 + iVar1) = *(undefined4 *)(&DAT_005253e4 + iVar1);
    iVar1 = iVar1 + -0x130;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

