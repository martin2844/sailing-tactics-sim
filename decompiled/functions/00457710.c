
void __cdecl FUN_00457710(undefined *param_1)

{
  undefined *lpMem;
  byte *pbVar1;
  int local_4;
  
  lpMem = param_1;
  if (param_1 != (undefined *)0x0) {
    FUN_0045b730(9);
    pbVar1 = (byte *)FUN_0045bc00(lpMem,&local_4,(uint *)&param_1);
    if (pbVar1 != (byte *)0x0) {
      FUN_0045bc60(local_4,(int)param_1,pbVar1);
      FUN_0045b7b0(9);
      return;
    }
    FUN_0045b7b0(9);
    HeapFree(DAT_004afdec,0,lpMem);
  }
  return;
}

