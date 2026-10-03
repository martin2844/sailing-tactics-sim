
void __thiscall FUN_00475e8c(void *this,undefined4 param_1,int *param_2)

{
  LPRECT lprcDst;
  LONG LVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar5 = *(undefined4 *)((int)this + 0x90);
  lprcDst = (LPRECT)((int)this + 0x94);
  LVar1 = lprcDst->left;
  uVar2 = *(undefined4 *)((int)this + 0x98);
  uVar3 = *(undefined4 *)((int)this + 0x9c);
  uVar4 = *(undefined4 *)((int)this + 0xa0);
  *(uint *)((int)this + 0x90) = (uint)(*param_2 == 0);
  CopyRect(lprcDst,(RECT *)(param_2 + 1));
  FUN_004733af(this,param_1,param_2);
  lprcDst->left = LVar1;
  *(undefined4 *)((int)this + 0x98) = uVar2;
  *(undefined4 *)((int)this + 0x9c) = uVar3;
  *(undefined4 *)((int)this + 0xa0) = uVar4;
  *(undefined4 *)((int)this + 0x90) = uVar5;
  return;
}

