
bool __thiscall FUN_004bade0(int param_1,LPCSTR param_2)

{
  int iVar1;
  HACCEL pHVar2;
  
  iVar1 = FUN_004bfff8();
  pHVar2 = LoadAcceleratorsA(*(HINSTANCE *)(iVar1 + 0xc),param_2);
  *(HACCEL *)(param_1 + 0x48) = pHVar2;
  return pHVar2 != (HACCEL)0x0;
}

