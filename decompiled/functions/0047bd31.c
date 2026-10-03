
void __thiscall FUN_0047bd31(void *this,undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = 1;
  bVar2 = true;
  if (1 < (int)param_1[2]) {
    do {
      if ((param_2 == 0) || (*(int *)(*(int *)((int)this + 0x10) + 4 + iVar3 * 8) == param_2)) {
        puVar1 = *(undefined4 **)(param_1[3] + iVar3 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        *(undefined4 *)(param_1[3] + iVar3 * 4) = 0;
      }
      else if (*(int *)(param_1[3] + iVar3 * 4) != 0) {
        bVar2 = false;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1[2]);
  }
  if (bVar2) {
    FUN_0047ba13((void *)((int)this + 0x14),(int)param_1);
    LocalFree((HLOCAL)param_1[3]);
    if (param_1 != (undefined4 *)0x0) {
      (**(code **)*param_1)(1);
    }
    TlsSetValue(*(DWORD *)this,(LPVOID)0x0);
  }
  return;
}

