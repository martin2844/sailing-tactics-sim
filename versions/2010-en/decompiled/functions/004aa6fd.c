
undefined4 __thiscall
FUN_004aa6fd(CSimpleException *param_1,LPSTR param_2,int param_3,undefined4 *param_4)

{
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    CSimpleException::InitString(param_1);
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    *param_2 = '\0';
  }
  else {
    lstrcpynA(param_2,(LPCSTR)(param_1 + 0x14),param_3);
  }
  return *(undefined4 *)(param_1 + 0x10);
}

