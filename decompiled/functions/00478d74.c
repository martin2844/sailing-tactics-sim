
void __thiscall
FUN_00478d74(void *this,DWORD param_1,LPCSTR param_2,LPCSTR param_3,DWORD param_4,int *param_5,
            int param_6,HMENU param_7)

{
  HCURSOR pHVar1;
  HWND pHVar2;
  HBRUSH pHVar3;
  HICON pHVar4;
  
  FUN_0046c00d((void *)((int)this + 200),param_3);
  pHVar2 = (HWND)0x0;
  if (param_2 == (LPCSTR)0x0) {
    pHVar4 = (HICON)0x0;
    pHVar3 = (HBRUSH)0x0;
    pHVar1 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    param_2 = FUN_00468d9f(8,pHVar1,pHVar3,pHVar4);
  }
  if (param_6 != 0) {
    pHVar2 = *(HWND *)(param_6 + 0x1c);
  }
  FUN_0046866b(this,param_1,param_2,param_3,param_4,*param_5,param_5[1],param_5[2] - *param_5,
               param_5[3] - param_5[1],pHVar2,param_7,(LPVOID)0x0);
  return;
}

