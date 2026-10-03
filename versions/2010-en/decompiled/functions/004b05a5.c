
void __thiscall FUN_004b05a5(Tact2010CString *original_this)

{
  LONG LVar1;
  
  if (original_this->data + -0xc != PTR_DAT_004ed788) {
    LVar1 = InterlockedDecrement((LONG *)(original_this->data + -0xc));
    if (LVar1 < 1) {
      FUN_004afc21(original_this->data + -0xc);
    }
  }
  return;
}

