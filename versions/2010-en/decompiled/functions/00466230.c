
float10 __cdecl FUN_00466230(double param_1,double param_2,int param_3)

{
  int iVar1;
  float10 fVar2;
  double local_10;
  
  iVar1 = 0;
  local_10 = 50000.0;
  if (-1 < DAT_004da1f4) {
    do {
      if (((param_3 < 0) || (iVar1 != param_3)) &&
         (fVar2 = FUN_004662d0(param_1,param_2,
                               (double)CONCAT44(*(undefined4 *)((int)&DAT_004f7220 + iVar1 * 8 + 4),
                                                *(undefined4 *)(&DAT_004f7220 + iVar1)),
                               (double)CONCAT44(*(undefined4 *)((int)&DAT_004ff038 + iVar1 * 8 + 4),
                                                *(undefined4 *)(&DAT_004ff038 + iVar1))),
         fVar2 < (float10)local_10)) {
        local_10 = (double)fVar2;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 <= DAT_004da1f4);
  }
  return (float10)local_10;
}

