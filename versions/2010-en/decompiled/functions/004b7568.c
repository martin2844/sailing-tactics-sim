
uint __thiscall FUN_004b7568(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  iVar1 = *param_1;
  piVar3 = param_1;
  piVar4 = param_1;
  FUN_0049a700(param_3);
  iVar1 = (**(code **)(iVar1 + 0x6c))(piVar3,piVar4,uVar5);
  if (iVar1 == -1) {
    uVar2 = GetDlgCtrlID((HWND)param_1[7]);
    uVar2 = -(uint)((uVar2 & 0xffff) != 0) & (uVar2 & 0xffff) + 0x50000;
  }
  else {
    uVar2 = iVar1 + 0x10000;
  }
  return uVar2;
}

