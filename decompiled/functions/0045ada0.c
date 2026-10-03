
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045ada0(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_8;
  int local_4;
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_004aeab8,0x104);
  _DAT_004ae954 = &DAT_004aeab8;
  pbVar2 = DAT_004aff0c;
  if (*DAT_004aff0c == 0) {
    pbVar2 = &DAT_004aeab8;
  }
  FUN_0045ae40(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = (undefined4 *)FUN_00457640(local_4 + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_0045ae40(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  DAT_004ae93c = puVar1;
  DAT_004ae938 = local_8 + -1;
  return;
}

