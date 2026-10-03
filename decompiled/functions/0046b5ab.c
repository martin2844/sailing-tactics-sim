
long FUN_0046b5ab(CException *param_1,tagMSG *param_2)

{
  UINT UVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  UVar1 = param_2->message;
  if ((UVar1 == 1) || (UVar1 == 0xf)) {
    lVar3 = AfxInternalProcessWndProcException(param_1,param_2);
  }
  else {
    lVar3 = 0;
    uVar4 = 0xf108;
    if (UVar1 == 0x111) {
      if (param_2->lParam == 0) {
        uVar4 = 0xf109;
      }
      lVar3 = 1;
    }
    iVar2 = FUN_0046cf38(param_1,0x487310);
    if (iVar2 == 0) {
      iVar2 = FUN_0046cf38(param_1,0x486e70);
      if (iVar2 != 0) {
        return lVar3;
      }
      iVar2 = *(int *)param_1;
      uVar5 = 0x10;
    }
    else {
      iVar2 = *(int *)param_1;
      uVar5 = 0x1030;
    }
    (**(code **)(iVar2 + 0x18))(uVar5,uVar4);
  }
  return lVar3;
}

