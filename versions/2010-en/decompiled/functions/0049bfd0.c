
void FUN_0049bfd0(LPVOID param_1)

{
  LPVOID lpMem;
  int iVar1;
  undefined4 local_4;
  
  lpMem = param_1;
  if (param_1 != (LPVOID)0x0) {
    FUN_0049fe10(9);
    iVar1 = FUN_004a02e0(lpMem,&local_4,&param_1);
    if (iVar1 != 0) {
      FUN_004a0340(local_4,param_1,iVar1);
      FUN_0049fe90(9);
      return;
    }
    FUN_0049fe90(9);
    HeapFree(DAT_0053992c,0,lpMem);
  }
  return;
}

