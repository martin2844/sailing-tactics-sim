
char * FUN_0049c670(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  char *pcVar3;
  byte *pbVar4;
  
  if (DAT_005385c4 == 0) {
    pcVar3 = _strpbrk((char *)param_1,(char *)param_2);
    return pcVar3;
  }
  FUN_0049fe10(0x19);
  if (*param_1 == 0) {
LAB_0049c709:
    FUN_0049fe90(0x19);
    return (char *)(-(uint)(*param_1 != 0) & (uint)param_1);
  }
  pbVar4 = param_2;
  bVar2 = *param_2;
joined_r0x0049c6af:
  do {
    if (bVar2 != 0) {
      bVar2 = *pbVar4;
      if ((*(byte *)((int)&DAT_005384c0 + bVar2 + 1) & 4) == 0) {
        if (bVar2 != *param_1) goto LAB_0049c6dd;
      }
      else if (((bVar2 != *param_1) || (pbVar4[1] != param_1[1])) && (pbVar4[1] != 0)) {
        pbVar4 = pbVar4 + 1;
LAB_0049c6dd:
        pbVar1 = pbVar4 + 1;
        pbVar4 = pbVar4 + 1;
        bVar2 = *pbVar1;
        goto joined_r0x0049c6af;
      }
    }
    if (((*pbVar4 != 0) ||
        (((*(byte *)((int)&DAT_005384c0 + *param_1 + 1) & 4) != 0 &&
         (pbVar4 = param_1 + 1, param_1 = param_1 + 1, *pbVar4 == 0)))) ||
       (pbVar1 = param_1 + 1, param_1 = param_1 + 1, pbVar4 = param_2, bVar2 = *param_2,
       *pbVar1 == 0)) goto LAB_0049c709;
  } while( true );
}

