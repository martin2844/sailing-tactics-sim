
void __fastcall FUN_004bf76d(int param_1)

{
  ATOM AVar1;
  
  AVar1 = GlobalAddAtomA(*(LPCSTR *)(param_1 + 0x88));
  *(ATOM *)(param_1 + 0xb0) = AVar1;
  AVar1 = GlobalAddAtomA("system");
  *(ATOM *)(param_1 + 0xb2) = AVar1;
  return;
}

