
undefined4 * __thiscall FUN_004ab9b0(int param_1,char *param_2,uint *param_3)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  char *pcVar5;
  undefined4 *puVar6;
  
  uVar2 = 0;
  cVar4 = *param_2;
  pcVar5 = param_2;
  while (cVar4 != '\0') {
    uVar2 = uVar2 * 0x21 + (int)cVar4;
    pcVar1 = pcVar5 + 1;
    pcVar5 = pcVar5 + 1;
    cVar4 = *pcVar1;
  }
  uVar2 = uVar2 % *(uint *)(param_1 + 8);
  *param_3 = uVar2;
  if (*(int *)(param_1 + 4) != 0) {
    for (puVar6 = *(undefined4 **)(*(int *)(param_1 + 4) + uVar2 * 4); puVar6 != (undefined4 *)0x0;
        puVar6 = (undefined4 *)*puVar6) {
      iVar3 = FUN_0049bd00(puVar6[2],param_2);
      if (iVar3 == 0) {
        return puVar6;
      }
    }
  }
  return (undefined4 *)0x0;
}

