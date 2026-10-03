
int __cdecl FUN_0045f090(LPSTR param_1,WCHAR param_2)

{
  int iVar1;
  bool bVar2;
  
  InterlockedIncrement((LONG *)&DAT_004afde8);
  bVar2 = DAT_004afde4 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_004afde8);
    FUN_0045b730(0x13);
  }
  iVar1 = FUN_0045f100(param_1,param_2);
  if (!bVar2) {
    InterlockedDecrement((LONG *)&DAT_004afde8);
    return iVar1;
  }
  FUN_0045b7b0(0x13);
  return iVar1;
}

