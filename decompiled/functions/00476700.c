
bool __thiscall FUN_00476700(void *this,LPCSTR param_1)

{
  int iVar1;
  HACCEL pHVar2;
  
  iVar1 = FUN_0047b918();
  pHVar2 = LoadAcceleratorsA(*(HINSTANCE *)(iVar1 + 0xc),param_1);
  *(HACCEL *)((int)this + 0x48) = pHVar2;
  return pHVar2 != (HACCEL)0x0;
}

