
void __thiscall FUN_004b7e00(int param_1,int *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 100);
  if ((uVar1 & 0x100) != 0) {
    *param_2 = *param_2 + DAT_005381a0;
  }
  if ((uVar1 & 0x200) != 0) {
    param_2[1] = param_2[1] + DAT_005381a4;
  }
  if ((uVar1 & 0x400) != 0) {
    param_2[2] = param_2[2] - DAT_005381a0;
  }
  if ((uVar1 & 0x800) != 0) {
    param_2[3] = param_2[3] - DAT_005381a4;
  }
  if (param_3 == 0) {
    *param_2 = *param_2 + *(int *)(param_1 + 0x48);
    param_2[1] = param_2[1] + *(int *)(param_1 + 0x40);
    param_2[2] = param_2[2] - *(int *)(param_1 + 0x4c);
    iVar2 = *(int *)(param_1 + 0x44);
  }
  else {
    *param_2 = *param_2 + *(int *)(param_1 + 0x40);
    param_2[1] = param_2[1] + *(int *)(param_1 + 0x48);
    param_2[2] = param_2[2] - *(int *)(param_1 + 0x44);
    iVar2 = *(int *)(param_1 + 0x4c);
  }
  param_2[3] = param_2[3] - iVar2;
  return;
}

