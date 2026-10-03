
undefined4 * __thiscall FUN_004aba4e(int param_1,char *param_2)

{
  undefined4 *puVar1;
  int local_8;
  
  local_8 = param_1;
  puVar1 = (undefined4 *)FUN_004ab9b0(param_2,&local_8);
  if (puVar1 == (undefined4 *)0x0) {
    if (*(int *)(param_1 + 4) == 0) {
      FUN_004ab885(*(undefined4 *)(param_1 + 8),1);
    }
    puVar1 = (undefined4 *)FUN_004ab950();
    puVar1[1] = local_8;
    FUN_004b06ed((Tact2010CString *)(puVar1 + 2),param_2);
    *puVar1 = *(undefined4 *)(*(int *)(param_1 + 4) + local_8 * 4);
    *(undefined4 **)(*(int *)(param_1 + 4) + local_8 * 4) = puVar1;
  }
  return puVar1 + 3;
}

