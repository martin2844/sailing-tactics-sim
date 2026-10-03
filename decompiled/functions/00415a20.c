
int __cdecl FUN_00415a20(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((int)((param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f)) < 2) {
    param_1 = 2;
  }
  iVar1 = (int)(32000 / (longlong)(int)param_1);
  if (iVar1 < 1) {
    iVar1 = 1;
  }
  uVar2 = FUN_00456ee0();
  return (int)uVar2 / iVar1;
}

