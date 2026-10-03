
undefined4 FUN_0049e908(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int extraout_ECX;
  undefined1 *puVar2;
  int iVar3;
  int local_c;
  undefined4 local_8;
  
  puVar2 = &stack0xfffffffc;
  if ((*(uint *)(param_1 + 4) & 6) == 0) {
    local_c = param_1;
    local_8 = param_3;
    *(int **)(param_2 + -4) = &local_c;
    iVar1 = *(int *)(param_2 + 8);
    for (iVar3 = *(int *)(param_2 + 0xc); iVar3 != -1; iVar3 = *(int *)(iVar1 + iVar3 * 0xc)) {
      if (*(int *)(iVar1 + 4 + iVar3 * 0xc) != 0) {
        iVar1 = (**(code **)(iVar1 + 4 + iVar3 * 0xc))();
        param_2 = *(int *)(puVar2 + 0xc);
        if (iVar1 != 0) {
          if (iVar1 < 0) {
            return 0;
          }
          iVar1 = *(int *)(param_2 + 8);
          __global_unwind2(param_2);
          puVar2 = (undefined1 *)(param_2 + 0x10);
          __local_unwind2(param_2,iVar3);
          FUN_0049b4b6(1);
          *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(iVar1 + extraout_ECX * 4);
          (**(code **)(iVar1 + 8 + extraout_ECX * 4))();
        }
      }
      iVar1 = *(int *)(param_2 + 8);
    }
  }
  else {
    __local_unwind2(param_2,0xffffffff,&stack0xfffffffc,&stack0xfffffffc);
  }
  return 1;
}

