
undefined4 __thiscall FUN_0046601d(void *this,LPSTR param_1,int param_2,undefined4 *param_3)

{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  if (*(int *)((int)this + 0xc) == 0) {
    CSimpleException::InitString(this);
  }
  if (*(int *)((int)this + 0x10) == 0) {
    *param_1 = '\0';
  }
  else {
    lstrcpynA(param_1,(LPCSTR)((int)this + 0x14),param_2);
  }
  return *(undefined4 *)((int)this + 0x10);
}

