
void __thiscall FUN_004ba56c(int param_1,undefined4 param_2,int *param_3)

{
  LPRECT lprcDst;
  LONG LVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar5 = *(undefined4 *)(param_1 + 0x90);
  lprcDst = (LPRECT)(param_1 + 0x94);
  LVar1 = lprcDst->left;
  uVar2 = *(undefined4 *)(param_1 + 0x98);
  uVar3 = *(undefined4 *)(param_1 + 0x9c);
  uVar4 = *(undefined4 *)(param_1 + 0xa0);
  *(uint *)(param_1 + 0x90) = (uint)(*param_3 == 0);
  CopyRect(lprcDst,(RECT *)(param_3 + 1));
  FUN_004b7a8f(param_2,param_3);
  lprcDst->left = LVar1;
  *(undefined4 *)(param_1 + 0x98) = uVar2;
  *(undefined4 *)(param_1 + 0x9c) = uVar3;
  *(undefined4 *)(param_1 + 0xa0) = uVar4;
  *(undefined4 *)(param_1 + 0x90) = uVar5;
  return;
}

