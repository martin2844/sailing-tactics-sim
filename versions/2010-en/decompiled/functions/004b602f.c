
int __fastcall FUN_004b602f(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_c;
  int local_8;
  
  local_8 = 0;
  puVar4 = *(undefined4 **)(param_1 + 8);
  iVar5 = param_1;
  while (local_c = iVar5, puVar4 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar4;
    iVar2 = *(int *)puVar4[2];
    local_c = (**(code **)(iVar2 + 0x5c))();
    puVar4 = puVar1;
    iVar5 = 0;
    if (local_c != 0) {
      pcVar3 = *(code **)(iVar2 + 0x60);
      do {
        iVar5 = (*pcVar3)(&local_c);
        if (iVar5 != 0) {
          local_8 = local_8 + 1;
        }
        iVar5 = 0;
      } while (local_c != 0);
    }
  }
  return local_8;
}

