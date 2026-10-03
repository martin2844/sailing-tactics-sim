
char * __cdecl FUN_00457db0(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  char *pcVar3;
  byte *pbVar4;
  
  if (DAT_004aea6c == 0) {
    pcVar3 = _strpbrk((char *)param_1,(char *)param_2);
    return pcVar3;
  }
  FUN_0045b730(0x19);
  if (*param_1 == 0) {
LAB_00457e49:
    FUN_0045b7b0(0x19);
    return (char *)(-(uint)(*param_1 != 0) & (uint)param_1);
  }
  pbVar4 = param_2;
  bVar2 = *param_2;
joined_r0x00457def:
  do {
    if (bVar2 != 0) {
      bVar2 = *pbVar4;
      if ((*(byte *)((int)&DAT_004ae968 + bVar2 + 1) & 4) == 0) {
        if (bVar2 != *param_1) goto LAB_00457e1d;
      }
      else if (((bVar2 != *param_1) || (pbVar4[1] != param_1[1])) && (pbVar4[1] != 0)) {
        pbVar4 = pbVar4 + 1;
LAB_00457e1d:
        pbVar1 = pbVar4 + 1;
        pbVar4 = pbVar4 + 1;
        bVar2 = *pbVar1;
        goto joined_r0x00457def;
      }
    }
    if (((*pbVar4 != 0) ||
        (((*(byte *)((int)&DAT_004ae968 + *param_1 + 1) & 4) != 0 &&
         (pbVar4 = param_1 + 1, param_1 = param_1 + 1, *pbVar4 == 0)))) ||
       (pbVar1 = param_1 + 1, param_1 = param_1 + 1, pbVar4 = param_2, bVar2 = *param_2,
       *pbVar1 == 0)) goto LAB_00457e49;
  } while( true );
}

