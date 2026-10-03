
void __thiscall FUN_004ab7d0(int param_1,int *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  piVar3 = (int *)*param_2;
  if (piVar3 == (int *)0xffffffff) {
    uVar4 = 0;
    if (*(uint *)(param_1 + 8) != 0) {
      piVar1 = *(int **)(param_1 + 4);
      do {
        piVar3 = (int *)*piVar1;
        if (piVar3 != (int *)0x0) break;
        uVar4 = uVar4 + 1;
        piVar1 = piVar1 + 1;
      } while (uVar4 < *(uint *)(param_1 + 8));
    }
  }
  iVar5 = *piVar3;
  if (iVar5 == 0) {
    uVar4 = *(uint *)(param_1 + 8);
    uVar2 = ((uint)piVar3[1] >> 4) % uVar4 + 1;
    if (uVar2 < uVar4) {
      piVar1 = (int *)(*(int *)(param_1 + 4) + uVar2 * 4);
      do {
        iVar5 = *piVar1;
        if (iVar5 != 0) break;
        uVar2 = uVar2 + 1;
        piVar1 = piVar1 + 1;
      } while (uVar2 < uVar4);
    }
  }
  *param_2 = iVar5;
  *param_3 = piVar3[1];
  *param_4 = piVar3[2];
  return;
}

