
void __thiscall FUN_0046daf5(void *this,LPCSTR param_1)

{
  void *this_00;
  int iVar1;
  int iVar2;
  CHAR local_108 [260];
  
  FUN_0046cc20();
  iVar2 = 0;
  if (*(int *)((int)this + 4) != 1 && -1 < *(int *)((int)this + 4) + -1) {
    do {
      iVar1 = FUN_0046cdbf(*(byte **)(*(int *)((int)this + 8) + iVar2 * 4),local_108);
      if (iVar1 != 0) break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this + 4) + -1);
  }
  for (; 0 < iVar2; iVar2 = iVar2 + -1) {
    this_00 = (void *)(*(int *)((int)this + 8) + iVar2 * 4);
    FUN_0046bfbe(this_00,(int *)((int)this_00 + -4));
  }
  FUN_0046c00d(*(void **)((int)this + 8),param_1);
  return;
}

