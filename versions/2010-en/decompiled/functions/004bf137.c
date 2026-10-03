
void __thiscall FUN_004bf137(int param_1,char *param_2)

{
  Tact2010CString *original_this;
  
  original_this = (Tact2010CString *)(param_1 + 0x14);
  if ((*(int *)(*(int *)(param_1 + 0x14) + -8) == 0) ||
     ((*(int *)(param_1 + 0x10) == 3 &&
      (((original_this = (Tact2010CString *)(param_1 + 0x18),
        *(int *)(*(int *)(param_1 + 0x18) + -8) == 0 ||
        (original_this = (Tact2010CString *)(param_1 + 0x1c),
        *(int *)(*(int *)(param_1 + 0x1c) + -8) == 0)) ||
       (original_this = (Tact2010CString *)(param_1 + 0x20),
       *(int *)(*(int *)(param_1 + 0x20) + -8) == 0)))))) {
    FUN_004b06ed(original_this,param_2);
  }
  return;
}

