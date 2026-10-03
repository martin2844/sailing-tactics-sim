
undefined4 __fastcall FUN_0046ed43(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  CWnd *pCVar4;
  undefined4 uVar5;
  int *local_8;
  
  iVar1 = *param_1;
  local_8 = param_1;
  local_8 = (int *)(**(code **)(iVar1 + 0x68))();
  if (local_8 != (int *)0x0) {
    pcVar2 = *(code **)(iVar1 + 0x6c);
    do {
      iVar3 = (*pcVar2)(&local_8);
      pCVar4 = FUN_004696a2(iVar3);
      if ((pCVar4 != (CWnd *)0x0) && (0 < *(int *)(pCVar4 + 0x40))) {
        return 1;
      }
    } while (local_8 != (int *)0x0);
  }
  uVar5 = (**(code **)(iVar1 + 0x98))();
  return uVar5;
}

