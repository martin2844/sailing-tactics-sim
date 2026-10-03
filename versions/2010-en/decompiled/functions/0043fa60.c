
void FUN_0043fa60(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 1;
  if (0 < param_2) {
    piVar3 = &DAT_004fc164;
    do {
      iVar1 = *piVar3;
      if (iVar1 < param_3) {
        *(int *)(&DAT_004f4778 + param_1 * 4) = iVar2;
        param_3 = iVar1;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 <= param_2);
  }
  return;
}

