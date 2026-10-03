
undefined4 __fastcall FUN_004b76a3(int param_1)

{
  int iVar1;
  HWND pHVar2;
  int *piVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_004ac701();
  if (iVar1 == -1) {
    uVar4 = 0xffffffff;
  }
  else {
    if ((*(byte *)(param_1 + 100) & 0x10) != 0) {
      FUN_0049ac27(1);
    }
    pHVar2 = GetParent(*(HWND *)(param_1 + 0x1c));
    piVar3 = (int *)FUN_004ac7ac(pHVar2);
    iVar1 = (**(code **)(*piVar3 + 0xb8))();
    if (iVar1 != 0) {
      *(int **)(param_1 + 0x6c) = piVar3;
      AddTail(param_1);
    }
    uVar4 = 0;
  }
  return uVar4;
}

