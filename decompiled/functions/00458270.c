
undefined * __cdecl FUN_00458270(undefined *param_1,int *param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined *puVar3;
  uint dwBytes;
  int local_4;
  
  if ((int *)0xffffffe0 < param_2) {
    return (undefined *)0x0;
  }
  if (param_2 == (int *)0x0) {
    dwBytes = 0x10;
  }
  else {
    dwBytes = (int)param_2 + 0xfU & 0xfffffff0;
  }
  FUN_0045b730(9);
  pbVar1 = (byte *)FUN_0045bc00(param_1,&local_4,(uint *)&param_2);
  if (pbVar1 != (byte *)0x0) {
    puVar3 = (undefined *)0x0;
    if (dwBytes <= DAT_004a2084) {
      iVar2 = FUN_0045c080(local_4,param_2,pbVar1,dwBytes >> 4);
      if (iVar2 != 0) {
        puVar3 = param_1;
      }
    }
    FUN_0045b7b0(9);
    return puVar3;
  }
  FUN_0045b7b0(9);
  puVar3 = HeapReAlloc(DAT_004afdec,0x10,param_1,dwBytes);
  return puVar3;
}

