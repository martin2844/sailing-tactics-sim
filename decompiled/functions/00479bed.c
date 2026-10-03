
int __thiscall FUN_00479bed(void *this,int param_1,LPSTR param_2)

{
  int iVar1;
  
  if (DAT_004ae69c == 0) {
    lstrcpynA(param_2,*(LPCSTR *)((int)this + 200),param_1);
    iVar1 = *(int *)(*(int *)((int)this + 200) + -8);
    if (iVar1 < param_1) {
      param_1 = iVar1;
    }
  }
  else {
    param_1 = FUN_00468021(this);
  }
  return param_1;
}

