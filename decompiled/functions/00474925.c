
void __fastcall FUN_00474925(void *param_1)

{
  void *pvVar1;
  uint uVar2;
  LONG *pLVar3;
  int iVar4;
  int iVar5;
  RECT local_18;
  void *local_8;
  
  FUN_00474e53(param_1);
  if (*(uint *)((int)param_1 + 0x74) == 0) {
    uVar2 = *(uint *)((int)param_1 + 0x78);
    if ((((uVar2 & 4) == 0) && (((uVar2 & 0xa000) == 0 || (*(int *)((int)param_1 + 0x7c) != 0)))) &&
       (((uVar2 & 0x5000) == 0 || (*(int *)((int)param_1 + 0x7c) == 0)))) {
      *(undefined4 *)((int)param_1 + 0xa8) = *(undefined4 *)((int)param_1 + 0x58);
      iVar5 = *(int *)((int)param_1 + 0x5c);
      uVar2 = (uint)CONCAT11(0x10,(byte)*(undefined4 *)((int)param_1 + 0x70) & 0x40);
      iVar4 = *(int *)((int)param_1 + 0x58);
      *(uint *)((int)param_1 + 0xa4) = uVar2;
      *(int *)((int)param_1 + 0xac) = iVar5;
    }
    else {
      *(undefined4 *)((int)param_1 + 0xa8) = *(undefined4 *)((int)param_1 + 0x48);
      iVar5 = *(int *)((int)param_1 + 0x4c);
      uVar2 = (uint)CONCAT11(0x20,(byte)*(undefined4 *)((int)param_1 + 0x70) & 0x40);
      iVar4 = *(int *)((int)param_1 + 0x48);
      *(uint *)((int)param_1 + 0xa4) = uVar2;
      *(int *)((int)param_1 + 0xac) = iVar5;
    }
    FUN_00479eb8(*(void **)((int)param_1 + 0x6c),*(void **)((int)param_1 + 0x68),iVar4,iVar5,uVar2);
  }
  else {
    local_8 = (void *)FUN_0047511c(param_1,*(uint *)((int)param_1 + 0x74));
    pLVar3 = (LONG *)((int)param_1 + 0x38);
    if ((*(byte *)((int)param_1 + 0x75) & 0x50) == 0) {
      pLVar3 = (LONG *)((int)param_1 + 0x28);
    }
    local_18.left = *pLVar3;
    local_18.top = pLVar3[1];
    local_18.right = pLVar3[2];
    local_18.bottom = pLVar3[3];
    uVar2 = GetDlgCtrlID(*(HWND *)((int)local_8 + 0x1c));
    pvVar1 = local_8;
    uVar2 = uVar2 & 0xffff;
    if ((0xe81a < uVar2) && (uVar2 < 0xe81f)) {
      *(uint *)((int)param_1 + 0x90) = uVar2;
      ((LPPOINT)((int)param_1 + 0x94))->x = local_18.left;
      *(LONG *)((int)param_1 + 0x98) = local_18.top;
      *(LONG *)((int)param_1 + 0x9c) = local_18.right;
      *(LONG *)((int)param_1 + 0xa0) = local_18.bottom;
      ScreenToClient(*(HWND *)((int)local_8 + 0x1c),(LPPOINT)((int)param_1 + 0x94));
      ScreenToClient(*(HWND *)((int)pvVar1 + 0x1c),(LPPOINT)((int)param_1 + 0x9c));
    }
    FUN_00479dd4(*(void **)((int)param_1 + 0x6c),*(void **)((int)param_1 + 0x68),pvVar1,&local_18);
    (**(code **)(**(int **)((int)param_1 + 0x6c) + 0xd0))(1);
  }
  return;
}

