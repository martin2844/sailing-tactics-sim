
void __fastcall FUN_004b9005(int param_1)

{
  int iVar1;
  uint uVar2;
  LONG *pLVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  LONG local_18;
  LONG LStack_14;
  LONG LStack_10;
  LONG LStack_c;
  int local_8;
  
  FUN_004b9533();
  if (*(int *)(param_1 + 0x74) == 0) {
    uVar2 = *(uint *)(param_1 + 0x78);
    if ((((uVar2 & 4) == 0) && (((uVar2 & 0xa000) == 0 || (*(int *)(param_1 + 0x7c) != 0)))) &&
       (((uVar2 & 0x5000) == 0 || (*(int *)(param_1 + 0x7c) == 0)))) {
      *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x58);
      uVar5 = *(undefined4 *)(param_1 + 0x5c);
      uVar2 = (uint)CONCAT11(0x10,(byte)*(undefined4 *)(param_1 + 0x70) & 0x40);
      uVar4 = *(undefined4 *)(param_1 + 0x58);
      *(uint *)(param_1 + 0xa4) = uVar2;
      *(undefined4 *)(param_1 + 0xac) = uVar5;
    }
    else {
      *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x48);
      uVar5 = *(undefined4 *)(param_1 + 0x4c);
      uVar2 = (uint)CONCAT11(0x20,(byte)*(undefined4 *)(param_1 + 0x70) & 0x40);
      uVar4 = *(undefined4 *)(param_1 + 0x48);
      *(uint *)(param_1 + 0xa4) = uVar2;
      *(undefined4 *)(param_1 + 0xac) = uVar5;
    }
    FUN_004be598(*(undefined4 *)(param_1 + 0x68),uVar4,uVar5,uVar2);
  }
  else {
    local_8 = FUN_004b97fc(*(int *)(param_1 + 0x74));
    pLVar3 = (LONG *)(param_1 + 0x38);
    if ((*(byte *)(param_1 + 0x75) & 0x50) == 0) {
      pLVar3 = (LONG *)(param_1 + 0x28);
    }
    local_18 = *pLVar3;
    LStack_14 = pLVar3[1];
    LStack_10 = pLVar3[2];
    LStack_c = pLVar3[3];
    uVar2 = GetDlgCtrlID(*(HWND *)(local_8 + 0x1c));
    iVar1 = local_8;
    uVar2 = uVar2 & 0xffff;
    if ((0xe81a < uVar2) && (uVar2 < 0xe81f)) {
      *(uint *)(param_1 + 0x90) = uVar2;
      ((LPPOINT)(param_1 + 0x94))->x = local_18;
      *(LONG *)(param_1 + 0x98) = LStack_14;
      *(LONG *)(param_1 + 0x9c) = LStack_10;
      *(LONG *)(param_1 + 0xa0) = LStack_c;
      ScreenToClient(*(HWND *)(local_8 + 0x1c),(LPPOINT)(param_1 + 0x94));
      ScreenToClient(*(HWND *)(iVar1 + 0x1c),(LPPOINT)(param_1 + 0x9c));
    }
    FUN_004be4b4(*(undefined4 *)(param_1 + 0x68),iVar1,&local_18);
    (**(code **)(**(int **)(param_1 + 0x6c) + 0xd0))(1);
  }
  return;
}

