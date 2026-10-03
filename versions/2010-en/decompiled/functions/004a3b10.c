
int FUN_004a3b10(char *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int *piVar6;
  char *pcVar7;
  
  if (((DAT_0053849c != (int *)0x0) ||
      (((DAT_005384a4 == 0 || (iVar2 = FUN_004a5e60(), iVar2 == 0)) && (DAT_0053849c != (int *)0x0))
      )) && (param_1 != (char *)0x0)) {
    uVar3 = 0xffffffff;
    pcVar5 = (char *)*DAT_0053849c;
    pcVar7 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3 - 1;
    piVar6 = DAT_0053849c;
    if (pcVar5 != (char *)0x0) {
      do {
        uVar4 = 0xffffffff;
        pcVar7 = pcVar5;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        if (((uVar3 < ~uVar4 - 1) && (pcVar5[uVar3] == '=')) &&
           (iVar2 = FUN_004a5e20(pcVar5,param_1,uVar3), iVar2 == 0)) {
          return *piVar6 + 1 + uVar3;
        }
        pcVar5 = (char *)piVar6[1];
        piVar6 = piVar6 + 1;
        if (pcVar5 == (char *)0x0) {
          return 0;
        }
      } while( true );
    }
  }
  return 0;
}

