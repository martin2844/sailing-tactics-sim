
undefined4 * FUN_0047a664(void)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  HANDLE pvVar5;
  DWORD DVar6;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0047acc5();
  *extraout_ECX = &PTR_FUN_004865f4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 8) == 0) {
    extraout_ECX[0x1e] = 0;
  }
  else {
    pcVar2 = FUN_00457bc0(*(char **)(unaff_EBP + 8));
    extraout_ECX[0x1e] = pcVar2;
  }
  iVar3 = FUN_0047b918();
  iVar4 = FUN_0047be12((void *)(iVar3 + 0x1070),FUN_00455cc2);
  *(undefined4 **)(iVar4 + 4) = extraout_ECX;
  pvVar5 = GetCurrentThread();
  extraout_ECX[10] = pvVar5;
  DVar6 = GetCurrentThreadId();
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0xb] = DVar6;
  *(undefined4 **)(iVar3 + 4) = extraout_ECX;
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

