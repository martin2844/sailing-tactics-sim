
void FUN_00477c09(UINT param_1,void *param_2)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = (byte *)FUN_0046c276(param_2,0xff);
  iVar2 = FUN_0046d8e5(param_1,(LPSTR)pbVar1,0x100);
  if (iVar2 != 0) {
    pbVar1 = FUN_00457780(pbVar1,10);
    if (pbVar1 != (byte *)0x0) {
      *pbVar1 = 0;
    }
  }
  FUN_0046c2c5(param_2,-1);
  return;
}

