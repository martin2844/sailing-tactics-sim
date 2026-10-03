
void * __thiscall FUN_0046c222(void *this,LPCSTR param_1)

{
  uint uVar1;
  
  if (param_1 == (LPCSTR)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = lstrlenA(param_1);
  }
  FUN_0046c1c3(this,uVar1,(undefined4 *)param_1);
  return this;
}

