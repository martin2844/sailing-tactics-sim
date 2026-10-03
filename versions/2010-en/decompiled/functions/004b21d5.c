
void __thiscall FUN_004b21d5(int param_1,char *param_2)

{
  Tact2010CString *original_this;
  int iVar1;
  int iVar2;
  undefined1 local_108 [260];
  
  FUN_004b1300(local_108,param_2);
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 1 && -1 < *(int *)(param_1 + 4) + -1) {
    do {
      iVar1 = FUN_004b149f(*(undefined4 *)(*(int *)(param_1 + 8) + iVar2 * 4),local_108);
      if (iVar1 != 0) break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 4) + -1);
  }
  for (; 0 < iVar2; iVar2 = iVar2 + -1) {
    original_this = (Tact2010CString *)(*(int *)(param_1 + 8) + iVar2 * 4);
    FUN_004b069e(original_this,original_this + -1);
  }
  FUN_004b06ed(*(Tact2010CString **)(param_1 + 8),param_2);
  return;
}

