
void FUN_004be598(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  HWND pHVar3;
  int *piVar4;
  uint uVar5;
  
  if ((((*(int *)(param_1 + 0x6c) == 0) || (iVar1 = *(int *)(param_1 + 0x70), iVar1 == 0)) ||
      (*(int *)(iVar1 + 0x78) == 0)) ||
     ((iVar2 = FUN_004b9ac8(), iVar2 != 1 || ((*(uint *)(iVar1 + 100) & param_4 & 0xf000) == 0)))) {
    uVar5 = param_4;
    if (((*(byte *)(param_1 + 100) & 4) != 0) && (uVar5 = param_4 | 4, (param_4 & 0x5000) != 0)) {
      uVar5 = param_4 & 0xffff2fff | 0x2004;
    }
    param_4 = uVar5;
    piVar4 = (int *)FUN_004be47b(param_4);
    FUN_004af4dd(0,param_2,param_3,0,0,0x15);
    if (piVar4[8] == 0) {
      piVar4[8] = *(int *)(param_1 + 0x1c);
    }
    FUN_004af38e(0xe81f);
    FUN_004b9b30(param_1,0);
    (**(code **)(*piVar4 + 0xd0))(1);
    uVar5 = GetWindowLongA(*(HWND *)(param_1 + 0x1c),-0x10);
    if ((uVar5 & 0x10000000) == 0) {
      return;
    }
    FUN_004af52c(8);
  }
  else {
    pHVar3 = GetParent(*(HWND *)(iVar1 + 0x1c));
    piVar4 = (int *)FUN_004ac7ac(pHVar3);
    FUN_004af4dd(0,param_2,param_3,0,0,0x15);
    (**(code **)(*piVar4 + 0xd0))(1);
  }
  UpdateWindow((HWND)piVar4[7]);
  return;
}

