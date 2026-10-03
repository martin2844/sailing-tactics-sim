
undefined4 __thiscall FUN_004b9fb2(int *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = FUN_004ba69e(param_2,param_3);
  if (param_4 == 0) {
    FUN_004ab558(iVar1,1);
    if ((*(int *)(param_1[0x20] + -4 + iVar1 * 4) == 0) &&
       (*(int *)(param_1[0x20] + iVar1 * 4) == 0)) {
      FUN_004ab558(iVar1,1);
    }
    FUN_004b9f5b(param_2);
  }
  else {
    iVar3 = param_1[0x20];
    iVar5 = iVar1 * 4;
    uVar2 = GetDlgCtrlID(*(HWND *)(param_2 + 0x1c));
    *(uint *)(iVar3 + iVar5) = uVar2 & 0xffff;
    iVar3 = FUN_004ba69e(*(undefined4 *)(param_1[0x20] + iVar5),iVar1);
    if (0 < iVar3) {
      FUN_004ab558(iVar1,1);
      if ((((int *)(iVar5 + param_1[0x20]))[-1] == 0) && (*(int *)(iVar5 + param_1[0x20]) == 0)) {
        FUN_004ab558(iVar1,1);
      }
    }
  }
  if (*(int *)(param_2 + 0x74) != 0) {
    piVar4 = (int *)FUN_004bcdbe();
    if ((param_1[0x1e] == 0) || (iVar1 = (**(code **)(*param_1 + 0xe8))(), iVar1 != 0)) {
      piVar4[0x2e] = piVar4[0x2e] | 0xc;
    }
    else {
      iVar1 = FUN_004b9ac8();
      if (iVar1 == 0) {
        (**(code **)(*piVar4 + 0x60))();
        return 1;
      }
      FUN_004af52c(0);
    }
  }
  return 0;
}

