
void __thiscall
FUN_00468761(void *this,LPCSTR param_1,LPCSTR param_2,uint param_3,int *param_4,int param_5,
            HMENU param_6,LPVOID param_7)

{
  HWND pHVar1;
  
  if (param_5 == 0) {
    pHVar1 = (HWND)0x0;
  }
  else {
    pHVar1 = *(HWND *)(param_5 + 0x1c);
  }
  FUN_0046866b(this,0,param_1,param_2,param_3 | 0x40000000,*param_4,param_4[1],param_4[2] - *param_4
               ,param_4[3] - param_4[1],pHVar1,param_6,param_7);
  return;
}

