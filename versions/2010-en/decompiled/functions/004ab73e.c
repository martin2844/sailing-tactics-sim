
undefined4 * __thiscall FUN_004ab73e(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = param_2;
  puVar2 = (undefined4 *)FUN_004ab6d9(param_2,&param_2);
  if (puVar2 == (undefined4 *)0x0) {
    if (*(int *)(param_1 + 4) == 0) {
      FUN_004ab5d2(*(undefined4 *)(param_1 + 8),1);
    }
    puVar2 = (undefined4 *)FUN_004ab676();
    puVar2[1] = iVar1;
    *puVar2 = *(undefined4 *)(*(int *)(param_1 + 4) + param_2 * 4);
    *(undefined4 **)(*(int *)(param_1 + 4) + param_2 * 4) = puVar2;
  }
  return puVar2 + 2;
}

