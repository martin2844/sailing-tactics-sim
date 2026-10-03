
void FUN_004b55a5(HWND param_1,LPCSTR param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  CHAR local_104 [256];
  
  uVar1 = lstrlenA(param_2);
  if (((uVar1 < 0x101) && (uVar2 = GetWindowTextA(param_1,local_104,0x100), uVar2 == uVar1)) &&
     (iVar3 = lstrcmpA(local_104,param_2), iVar3 == 0)) {
    return;
  }
  SetWindowTextA(param_1,param_2);
  return;
}

