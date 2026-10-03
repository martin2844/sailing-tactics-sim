
HANDLE __thiscall FUN_004731b5(void *this,int param_1,void *param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  HWND pHVar4;
  
  pvVar1 = param_2;
  iVar2 = FUN_00469ec1(param_2,&param_2);
  pvVar3 = param_2;
  if (iVar2 == 0) {
    pHVar4 = (HWND)0x0;
    if (pvVar1 != (void *)0x0) {
      pHVar4 = *(HWND *)((int)pvVar1 + 0x1c);
    }
    iVar2 = FUN_0046a456(*(HDC *)(param_1 + 4),pHVar4,param_3,DAT_004ae65c,DAT_004ae66c);
    pvVar3 = DAT_004ae65c;
    if (iVar2 == 0) {
      pvVar3 = (void *)FUN_00468021(this);
    }
  }
  return pvVar3;
}

