
int FUN_0049b360(int param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = *(int *)(param_1 + 0x10);
  uVar5 = *(uint *)(param_1 + 0xc);
  uVar3 = uVar5;
  uVar4 = uVar5;
  while (-1 < param_2) {
    if (uVar5 == 0xffffffff) {
      FUN_0049e6c0();
    }
    uVar5 = uVar5 - 1;
    iVar1 = iVar2 + uVar5 * 0x14;
    if (((*(int *)(iVar1 + 4) < param_3) && (param_3 <= *(int *)(iVar1 + 8))) ||
       (uVar5 == 0xffffffff)) {
      param_2 = param_2 + -1;
      uVar3 = uVar4;
      uVar4 = uVar5;
    }
  }
  uVar5 = uVar5 + 1;
  *param_4 = uVar5;
  *param_5 = uVar3;
  if ((*(uint *)(param_1 + 0xc) < uVar3) || (uVar3 < uVar5)) {
    FUN_0049e6c0();
  }
  return iVar2 + uVar5 * 0x14;
}

