
int __cdecl FUN_0041e000(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 ^ param_1 >> 0x1f) - (param_1 >> 0x1f) < 2) {
    param_1 = 2;
  }
  iVar1 = (int)(32000 / (longlong)param_1);
  if (iVar1 < 1) {
    iVar1 = 1;
  }
  iVar2 = FUN_0049b7b0();
  return iVar2 / iVar1;
}

