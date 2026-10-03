
void * __thiscall FUN_0046a3f3(void *this,int param_1,void *param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  HWND pHVar4;
  
  pvVar1 = param_2;
  iVar2 = FUN_00469ec1(param_2,&param_2);
  if (iVar2 == 0) {
    iVar2 = FUN_0047bea7();
    pHVar4 = (HWND)0x0;
    if (pvVar1 != (void *)0x0) {
      pHVar4 = *(HWND *)((int)pvVar1 + 0x1c);
    }
    iVar3 = FUN_0046a456(*(HDC *)(param_1 + 4),pHVar4,param_3,*(HANDLE *)(iVar2 + 4),
                         *(COLORREF *)(iVar2 + 8));
    if (iVar3 == 0) {
      param_2 = (void *)FUN_00468021(this);
    }
    else {
      param_2 = *(void **)(iVar2 + 4);
    }
  }
  return param_2;
}

