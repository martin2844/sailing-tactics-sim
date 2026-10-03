
void FUN_004572ed(void)

{
  DWORD DVar1;
  int unaff_EBP;
  
  DVar1 = (*(_EXCEPTION_POINTERS **)(unaff_EBP + -0x14))->ExceptionRecord->ExceptionCode;
  *(DWORD *)(unaff_EBP + -0x68) = DVar1;
  FUN_0045aa00(DVar1,*(_EXCEPTION_POINTERS **)(unaff_EBP + -0x14));
  return;
}

