
void FUN_004bef0a(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  if (1 < DAT_00538490) {
    pcVar2 = *(code **)(*param_1 + 0x14);
    iVar3 = 1;
    do {
      iVar1 = iVar3 + 1;
      uVar5 = 0;
      pcVar4 = *(char **)(DAT_00538494 + iVar3 * 4);
      if ((*pcVar4 == '-') || (*pcVar4 == '/')) {
        pcVar4 = pcVar4 + 1;
        uVar5 = 1;
      }
      (*pcVar2)(pcVar4,uVar5,iVar1 == DAT_00538490);
      iVar3 = iVar1;
    } while (iVar1 < DAT_00538490);
  }
  return;
}

