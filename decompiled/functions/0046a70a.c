
ushort * __thiscall FUN_0046a70a(void *this,LPCSTR param_1)

{
  HMODULE hModule;
  int iVar1;
  HRSRC hResInfo;
  HGLOBAL hResData;
  ushort *puVar2;
  
  puVar2 = (ushort *)0x0;
  if (param_1 != (LPCSTR)0x0) {
    iVar1 = FUN_0047b918();
    hModule = *(HMODULE *)(iVar1 + 0xc);
    hResInfo = FindResourceA(hModule,param_1,(LPCSTR)0xf0);
    if (hResInfo != (HRSRC)0x0) {
      hResData = LoadResource(hModule,hResInfo);
      if (hResData == (HGLOBAL)0x0) {
        return (ushort *)0x0;
      }
      puVar2 = LockResource(hResData);
    }
  }
  puVar2 = FUN_0046a75a(this,puVar2);
  return puVar2;
}

