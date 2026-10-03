
void __cdecl FUN_0042cca0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_0049118c;
  if (param_1 == 0) {
    iVar4 = DAT_0049118c + 5;
  }
  iVar3 = 1;
  if (0 < iVar4) {
    piVar2 = &DAT_004a443c;
    do {
      FUN_0042cd00(iVar3,iVar4,19000);
      iVar1 = *piVar2;
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
      *(undefined4 *)(&DAT_004a6db0 + iVar1 * 4) = 20000;
    } while (iVar3 <= iVar4);
  }
  return;
}

