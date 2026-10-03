
int __thiscall FUN_004b7895(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = param_3;
  iVar1 = FUN_004ae5a1(&param_3);
  iVar3 = param_3;
  if (iVar1 == 0) {
    uVar4 = 0;
    if (iVar2 != 0) {
      uVar4 = *(undefined4 *)(iVar2 + 0x1c);
    }
    iVar2 = FUN_004aeb36(*(undefined4 *)(param_2 + 4),uVar4,param_4,DAT_005381b4,DAT_005381c4);
    iVar3 = DAT_005381b4;
    if (iVar2 == 0) {
      iVar3 = FUN_004ac701(param_1);
    }
  }
  return iVar3;
}

