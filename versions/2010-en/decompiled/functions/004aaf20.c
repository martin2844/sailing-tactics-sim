
undefined4 * __thiscall FUN_004aaf20(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)FUN_0049d8e0(param_1);
  }
  else {
    puVar1 = (undefined4 *)FUN_0049d8e0(param_1);
    puVar2 = (undefined4 *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      puVar4 = param_2;
      for (iVar3 = 9; puVar2 = param_2, iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar4 = puVar4 + 1;
      }
    }
  }
  return puVar2;
}

