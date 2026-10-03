
void __thiscall FUN_0047bdb9(void *this,int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  if (param_2 == 0) {
    puVar2 = TlsGetValue(*(DWORD *)this);
    if (puVar2 != (undefined4 *)0x0) {
      FUN_0047bd31(this,puVar2,param_1);
    }
  }
  else {
    puVar2 = *(undefined4 **)((int)this + 0x14);
    while (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)puVar2[1];
      FUN_0047bd31(this,puVar2,param_1);
      puVar2 = puVar1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  return;
}

