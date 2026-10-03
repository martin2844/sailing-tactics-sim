
uint __cdecl FUN_0045f180(LPSTR param_1,LPCWSTR param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  
  InterlockedIncrement((LONG *)&DAT_004afde8);
  bVar2 = DAT_004afde4 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_004afde8);
    FUN_0045b730(0x13);
  }
  uVar1 = FUN_0045f200(param_1,param_2,param_3);
  if (!bVar2) {
    InterlockedDecrement((LONG *)&DAT_004afde8);
    return uVar1;
  }
  FUN_0045b7b0(0x13);
  return uVar1;
}

