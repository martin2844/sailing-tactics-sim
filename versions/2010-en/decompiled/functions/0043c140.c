
void __cdecl FUN_0043c140(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00525a98;
  iVar1 = *(int *)(&DAT_004fecc8 + param_1 * 4);
  *(undefined4 *)(&DAT_00535f68 + param_1 * 4) = 0;
  if ((iVar1 < iVar2) && (iVar2 + -8 <= iVar1)) {
    *(undefined4 *)(&DAT_00535f68 + param_1 * 4) = 0x1e;
  }
  if (iVar1 < iVar2 + -8) {
    *(undefined4 *)(&DAT_00535f68 + param_1 * 4) = 100;
  }
  if ((((*(int *)(&DAT_004f42c0 + param_1 * 4) == 3) &&
       (0xbc - *(int *)(&DAT_004fae60 + param_1 * 4) < iVar1)) && (2 < DAT_004da190)) &&
     ((DAT_004da190 != 9 && (DAT_005364c4 == 0)))) {
    *(undefined4 *)(&DAT_004fbab0 + param_1 * 4) = 1;
    return;
  }
  *(undefined4 *)(&DAT_004fbab0 + param_1 * 4) = 0;
  return;
}

