
undefined4 __thiscall
FUN_004add08(int *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  HWND hWnd;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_10;
  undefined4 *local_c;
  uint local_8;
  
  hWnd = (HWND)*param_3;
  local_8 = GetDlgCtrlID(hWnd);
  local_8 = local_8 & 0xffff;
  uVar1 = param_3[2];
  iVar2 = FUN_004c04f2(FUN_0049a32a);
  if ((*(int *)(iVar2 + 0xb8) != param_1[7]) && (iVar2 = FUN_004ae5ce(hWnd,param_4), iVar2 == 0)) {
    local_10 = param_4;
    local_c = param_3;
    uVar3 = (**(code **)(*param_1 + 0x14))(local_8,uVar1 & 0xffff | 0x4e0000,&local_10,0);
    return uVar3;
  }
  return 1;
}

