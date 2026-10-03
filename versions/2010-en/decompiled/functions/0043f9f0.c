
void FUN_0043f9f0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 1;
  iVar4 = DAT_004da194;
  if (param_1 == 0) {
    if (DAT_004da1e8 == 1) {
      iVar4 = DAT_004da194 + 7;
    }
    else {
      iVar4 = DAT_004da194 + 5;
    }
  }
  if (0 < iVar4) {
    piVar2 = &DAT_004f477c;
    do {
      FUN_0043fa60(iVar3,iVar4,19000);
      iVar1 = *piVar2;
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
      *(undefined4 *)(&DAT_004fc160 + iVar1 * 4) = 20000;
    } while (iVar3 <= iVar4);
  }
  return;
}

