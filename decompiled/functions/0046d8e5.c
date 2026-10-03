
void FUN_0046d8e5(UINT param_1,LPSTR param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_0047b918();
  iVar1 = LoadStringA(*(HINSTANCE *)(iVar1 + 0xc),param_1,param_2,param_3);
  if (iVar1 == 0) {
    *param_2 = '\0';
  }
  return;
}

