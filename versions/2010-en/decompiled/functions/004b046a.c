
Tact2010CString * __thiscall FUN_004b046a(Tact2010CString *original_this,Tact2010CString *param_2)

{
  char *pcVar1;
  undefined4 *puVar2;
  
  pcVar1 = param_2->data;
  if (*(int *)(pcVar1 + -0xc) < 0) {
    puVar2 = (undefined4 *)FUN_004b0454();
    original_this->data = (char *)*puVar2;
    FUN_004b06ed(original_this,param_2->data);
  }
  else {
    original_this->data = pcVar1;
    InterlockedIncrement((LONG *)(pcVar1 + -0xc));
  }
  return original_this;
}

