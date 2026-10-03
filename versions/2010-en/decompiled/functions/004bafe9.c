
undefined4 __thiscall FUN_004bafe9(int param_1,uint param_2,int param_3)

{
  int iVar1;
  LRESULT LVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = param_2 & 0xffff;
  iVar1 = FUN_004adeef();
  if ((((*(int *)(iVar1 + 0x50) == 0) || (param_3 != 0)) || (uVar4 == 0xe146)) ||
     ((uVar4 == 0xe147 || (uVar4 == 0xe145)))) {
    uVar3 = FUN_004adc7c(param_2,param_3);
  }
  else {
    LVar2 = SendMessageA(*(HWND *)(param_1 + 0x1c),0x365,0,uVar4 + 0x10000);
    if (LVar2 == 0) {
      SendMessageA(*(HWND *)(param_1 + 0x1c),0x111,0xe147,0);
    }
    uVar3 = 1;
  }
  return uVar3;
}

