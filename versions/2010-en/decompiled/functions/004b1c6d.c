
int FUN_004b1c6d(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  iVar5 = *(int *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  if (iVar5 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004ab70b(iVar5);
    if (iVar2 == 0) {
      iVar2 = FUN_004ab70b(iVar5);
      if (iVar2 == 0) {
        uVar3 = FUN_004afbd1(FUN_004b56c3);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
        iVar2 = FUN_004b164a();
        *(int *)(unaff_EBP + -0x14) = iVar2;
        if (iVar2 == 0) {
          FUN_004aa740();
        }
        puVar4 = (undefined4 *)FUN_004ab73e(iVar5);
        *puVar4 = *(undefined4 *)(unaff_EBP + -0x14);
        iVar5 = func_0x004b1d17();
        return iVar5;
      }
      iVar1 = *(int *)(extraout_ECX + 0x3c);
      *(int *)(iVar1 + iVar2) = iVar5;
      if (*(int *)(extraout_ECX + 0x40) == 2) {
        *(int *)(iVar1 + iVar2 + 4) = iVar5;
      }
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar2;
}

