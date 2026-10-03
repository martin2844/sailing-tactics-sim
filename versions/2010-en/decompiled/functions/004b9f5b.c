
void __thiscall FUN_004b9f5b(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  uVar1 = GetDlgCtrlID(*(HWND *)(param_2 + 0x1c));
  iVar2 = FUN_004ba69e(uVar1 & 0xffff,uVar3);
  if (0 < iVar2) {
    FUN_004ab558(iVar2,1);
    if ((*(int *)(*(int *)(param_1 + 0x80) + -4 + iVar2 * 4) == 0) &&
       (*(int *)(*(int *)(param_1 + 0x80) + iVar2 * 4) == 0)) {
      FUN_004ab558(iVar2,1);
    }
  }
  return;
}

