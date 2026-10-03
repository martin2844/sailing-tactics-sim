
void __thiscall FUN_004c02c4(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  for (iVar2 = *(int *)(param_1 + 0x14); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
    if (param_2 < *(int *)(iVar2 + 8)) {
      puVar3 = *(undefined4 **)(*(int *)(iVar2 + 0xc) + param_2 * 4);
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(1);
      }
      *(undefined4 *)(*(int *)(iVar2 + 0xc) + param_2 * 4) = 0;
    }
  }
  puVar1 = (uint *)(*(int *)(param_1 + 0x10) + param_2 * 8);
  *puVar1 = *puVar1 & 0xfffffffe;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  return;
}

