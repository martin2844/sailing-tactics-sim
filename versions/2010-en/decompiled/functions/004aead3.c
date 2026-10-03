
int __thiscall FUN_004aead3(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = param_3;
  iVar1 = FUN_004ae5a1(&param_3);
  if (iVar1 == 0) {
    iVar1 = FUN_004c0587(FUN_0049a2f9);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = *(undefined4 *)(iVar2 + 0x1c);
    }
    iVar2 = FUN_004aeb36(*(undefined4 *)(param_2 + 4),uVar3,param_4,*(undefined4 *)(iVar1 + 4),
                         *(undefined4 *)(iVar1 + 8));
    if (iVar2 == 0) {
      param_3 = FUN_004ac701(param_1);
    }
    else {
      param_3 = *(int *)(iVar1 + 4);
    }
  }
  return param_3;
}

