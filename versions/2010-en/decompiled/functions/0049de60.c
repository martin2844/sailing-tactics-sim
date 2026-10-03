
void FUN_0049de60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint local_8;
  uint local_4;
  
  iVar1 = FUN_0049e5b0();
  if ((*(int *)(iVar1 + 0x68) != 0) &&
     (iVar1 = FUN_0049b200(param_1,param_2,param_3,param_4,param_5,param_7,param_8), iVar1 != 0)) {
    return;
  }
  piVar2 = (int *)FUN_0049b360(param_5,param_7,param_6,&local_8,&local_4);
  if (local_8 < local_4) {
    do {
      if ((*piVar2 <= param_6) && (param_6 <= piVar2[1])) {
        iVar3 = piVar2[4] + piVar2[3] * 0x10;
        iVar1 = *(int *)(iVar3 + -0xc);
        if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
          FUN_0049e000(param_1,param_2,param_3,param_4,param_5,iVar3 + -0x10,0,piVar2,param_7,
                       param_8);
        }
      }
      local_8 = local_8 + 1;
      piVar2 = piVar2 + 5;
    } while (local_8 < local_4);
  }
  return;
}

