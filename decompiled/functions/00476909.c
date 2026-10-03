
undefined4 __thiscall FUN_00476909(void *this,uint param_1,int param_2)

{
  CWnd *pCVar1;
  LRESULT LVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = param_1 & 0xffff;
  pCVar1 = FUN_0046980f(this);
  if ((((*(int *)(pCVar1 + 0x50) == 0) || (param_2 != 0)) || (uVar4 == 0xe146)) ||
     ((uVar4 == 0xe147 || (uVar4 == 0xe145)))) {
    uVar3 = FUN_0046959c(this,param_1,param_2);
  }
  else {
    LVar2 = SendMessageA(*(HWND *)((int)this + 0x1c),0x365,0,uVar4 + 0x10000);
    if (LVar2 == 0) {
      SendMessageA(*(HWND *)((int)this + 0x1c),0x111,0xe147,0);
    }
    uVar3 = 1;
  }
  return uVar3;
}

