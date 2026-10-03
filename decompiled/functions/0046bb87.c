
undefined4 FUN_0046bb87(int param_1,undefined4 *param_2)

{
  CWnd *pCVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  HWND hWnd;
  undefined4 local_24 [7];
  int *local_8;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0;
  }
  if (param_1 != 0) {
    if (param_1 != 2) {
      return 0;
    }
    pCVar1 = FUN_004680cc();
    if (((((pCVar1 != (CWnd *)0x0) && (pCVar1 = FUN_0046980f(pCVar1), pCVar1 != (CWnd *)0x0)) &&
         (iVar2 = FUN_0046ac25((int)pCVar1), iVar2 != 0)) &&
        ((*(int *)(pCVar1 + 0x50) != 0 &&
         (iVar2 = FUN_00455bf0(), *(int *)((int)local_8 + 0x1c) != 0)))) &&
       (((param_2[1] == 0x100 && (param_2[2] == 0xd)) || (param_2[1] == 0x202)))) {
      hWnd = *(HWND *)(iVar2 + 0x1c);
      goto LAB_0046bc42;
    }
  }
  iVar2 = FUN_00455bf0();
  if (((0x332 < DAT_004ae68c) || (iVar2 == 0)) || (iVar3 = FUN_0046bcce((int)param_2), iVar3 == 0))
  {
    if ((((param_1 != 0) || (local_8[8] == 0)) || ((uint)param_2[1] < 0x100)) ||
       ((0x108 < (uint)param_2[1] ||
        (iVar2 = FUN_0047be12(&DAT_004ae4b8,FUN_00455c3a), *(int *)(iVar2 + 0xbc) != 0)))) {
      return 0;
    }
    *(undefined4 *)(iVar2 + 0xbc) = 1;
    puVar4 = local_24;
    for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *param_2;
      param_2 = param_2 + 1;
      puVar4 = puVar4 + 1;
    }
    iVar3 = FUN_0046ae73(local_8[8]);
    if ((iVar3 != 0) && (iVar3 = (**(code **)(*local_8 + 0x60))(local_24), iVar3 != 0)) {
      *(undefined4 *)(iVar2 + 0xbc) = 0;
      return 1;
    }
    *(undefined4 *)(iVar2 + 0xbc) = 0;
    return 0;
  }
  hWnd = *(HWND *)(iVar2 + 0x1c);
LAB_0046bc42:
  SendMessageA(hWnd,0x111,0xe146,0);
  return 1;
}

