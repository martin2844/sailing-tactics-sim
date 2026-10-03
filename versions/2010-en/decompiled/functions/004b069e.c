
Tact2010CString * __thiscall FUN_004b069e(Tact2010CString *original_this,Tact2010CString *param_2)

{
  char *pcVar1;
  int *piVar2;
  
  pcVar1 = param_2->data;
  if (original_this->data != pcVar1) {
    piVar2 = (int *)(original_this->data + -0xc);
    if (((*piVar2 < 0) && (piVar2 != (int *)PTR_DAT_004ed788)) || (*(int *)(pcVar1 + -0xc) < 0)) {
      FUN_004b0671(*(undefined4 *)(pcVar1 + -8),pcVar1);
    }
    else {
      FUN_004b04db();
      pcVar1 = param_2->data;
      original_this->data = pcVar1;
      InterlockedIncrement((LONG *)(pcVar1 + -0xc));
    }
  }
  return original_this;
}

