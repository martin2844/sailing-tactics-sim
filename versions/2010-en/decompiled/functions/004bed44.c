
undefined4 * FUN_004bed44(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  HANDLE pvVar4;
  DWORD DVar5;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004bf3a5();
  *extraout_ECX = &PTR_FUN_004ce294;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 8) == 0) {
    extraout_ECX[0x1e] = 0;
  }
  else {
    uVar1 = FUN_0049c480(*(undefined4 *)(unaff_EBP + 8));
    extraout_ECX[0x1e] = uVar1;
  }
  iVar2 = FUN_004bfff8();
  iVar3 = FUN_004c04f2(FUN_0049a3b2);
  *(undefined4 **)(iVar3 + 4) = extraout_ECX;
  pvVar4 = GetCurrentThread();
  extraout_ECX[10] = pvVar4;
  DVar5 = GetCurrentThreadId();
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0xb] = DVar5;
  *(undefined4 **)(iVar2 + 4) = extraout_ECX;
  extraout_ECX[0x1a] = 0;
  extraout_ECX[0x23] = 0;
  extraout_ECX[0x24] = 0;
  extraout_ECX[0x1f] = 0;
  extraout_ECX[0x22] = 0;
  extraout_ECX[0x2a] = 0;
  extraout_ECX[0x20] = 0;
  *(undefined2 *)((int)extraout_ECX + 0xb2) = 0;
  *(undefined2 *)(extraout_ECX + 0x2c) = 0;
  extraout_ECX[0x1c] = 0;
  extraout_ECX[0x2b] = 0;
  extraout_ECX[0x28] = 0;
  extraout_ECX[0x29] = 0;
  extraout_ECX[0x25] = 0;
  extraout_ECX[0x26] = 0;
  extraout_ECX[0x2d] = 0;
  extraout_ECX[0x2f] = 0;
  extraout_ECX[0x21] = 0;
  extraout_ECX[0x2e] = 0x200;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

