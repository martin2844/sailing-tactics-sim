
void __thiscall FUN_004c0499(DWORD *param_1,undefined4 param_2,int param_3)

{
  DWORD DVar1;
  DWORD DVar2;
  LPVOID pvVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  if (param_3 == 0) {
    pvVar3 = TlsGetValue(*param_1);
    if (pvVar3 != (LPVOID)0x0) {
      FUN_004c0411(pvVar3,param_2);
    }
  }
  else {
    DVar2 = param_1[5];
    while (DVar2 != 0) {
      DVar1 = *(DWORD *)(DVar2 + 4);
      FUN_004c0411(DVar2,param_2);
      DVar2 = DVar1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  return;
}

