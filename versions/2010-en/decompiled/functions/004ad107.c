
void FUN_004ad107(int param_1)

{
  int iVar1;
  int *piVar2;
  SHORT SVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = FUN_004bfca5();
  iVar1 = *(int *)(iVar4 + 0xcc);
  if (iVar1 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(iVar1 + 0x1c);
  }
  if (iVar5 != 0) {
    SendMessageA(*(HWND *)(iVar1 + 0x1c),0x401,0,0);
  }
  piVar2 = *(int **)(iVar4 + 0x108);
  if ((param_1 != 0) && (piVar2 != (int *)0x0)) {
    SVar3 = GetKeyState(1);
    if (-1 < SVar3) {
      (**(code **)(*piVar2 + 0xe4))(0xffffffff);
    }
  }
  return;
}

