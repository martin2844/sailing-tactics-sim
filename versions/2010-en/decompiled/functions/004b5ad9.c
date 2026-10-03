
void __thiscall
FUN_004b5ad9(int param_1,int param_2,int param_3,uint *param_4,int *param_5,int *param_6,int param_7
            )

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int local_c;
  int local_8;
  
  local_c = param_1;
  local_8 = param_1;
  FUN_004b5a0a(&local_c);
  piVar2 = param_5;
  iVar1 = *(int *)(param_1 + 0x50);
  *param_5 = *(int *)(param_1 + 0x4c) - param_2;
  param_5[1] = iVar1 - param_3;
  piVar3 = (int *)FUN_004b5917(&param_2);
  *param_6 = *piVar3;
  param_6[1] = piVar3[1];
  uVar4 = (uint)(0 < *piVar2);
  if (uVar4 == 0) {
    *param_6 = 0;
  }
  else if (param_7 != 0) {
    piVar2[1] = piVar2[1] + local_8;
  }
  uVar5 = (uint)(0 < piVar2[1]);
  if (uVar5 == 0) {
    param_6[1] = 0;
  }
  else if (param_7 != 0) {
    *piVar2 = *piVar2 + local_c;
  }
  if (((uVar5 != 0) && (uVar4 == 0)) && (0 < *piVar2)) {
    piVar2[1] = piVar2[1] + local_8;
    uVar4 = 1;
  }
  iVar1 = *piVar2;
  if ((0 < iVar1) && (iVar1 <= *param_6)) {
    *param_6 = iVar1;
  }
  iVar1 = piVar2[1];
  if ((0 < iVar1) && (iVar1 <= param_6[1])) {
    param_6[1] = iVar1;
  }
  *param_4 = uVar4;
  param_4[1] = uVar5;
  return;
}

