
undefined4 FUN_0046d90c(int *param_1,byte *param_2,int param_3,char param_4)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (param_2 == (byte *)0x0) {
LAB_0046d980:
    uVar4 = 0;
  }
  else {
    if (param_3 != 0) {
      do {
        param_3 = param_3 + -1;
        pbVar1 = FUN_00457780(param_2,(int)param_4);
        if (pbVar1 == (byte *)0x0) {
          FUN_0046be50(param_1);
          goto LAB_0046d980;
        }
        param_2 = pbVar1 + 1;
      } while (param_3 != 0);
    }
    pbVar1 = FUN_00457780(param_2,(int)param_4);
    if (pbVar1 == (byte *)0x0) {
      uVar2 = lstrlenA((LPCSTR)param_2);
    }
    else {
      uVar2 = (int)pbVar1 - (int)param_2;
    }
    puVar3 = (undefined4 *)FUN_0046c2ed(param_1,uVar2);
    FUN_00457850(puVar3,(undefined4 *)param_2,uVar2);
    uVar4 = 1;
  }
  return uVar4;
}

