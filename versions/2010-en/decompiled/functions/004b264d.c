
void FUN_004b264d(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  Tact2010CString *pTVar4;
  int extraout_ECX;
  int unaff_EBP;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  uVar2 = FUN_004afbe5(*(int *)(*(int *)(extraout_ECX + 0x10) + -8) + 5);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  iVar3 = FUN_004bfff8();
  iVar5 = 0;
  iVar1 = *(int *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar3 + 4);
  if (0 < iVar1) {
    do {
      iVar1 = iVar5 + 1;
      wsprintfA(*(LPSTR *)(unaff_EBP + -0x10),*(LPCSTR *)(extraout_ECX + 0x10),iVar1);
      pTVar4 = (Tact2010CString *)
               FUN_004bf938(unaff_EBP + -0x18,*(undefined4 *)(extraout_ECX + 0xc),
                            *(undefined4 *)(unaff_EBP + -0x10),&DAT_00537ed8);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_004b069e((Tact2010CString *)(*(int *)(extraout_ECX + 8) + iVar5 * 4),pTVar4);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
      iVar5 = iVar1;
    } while (iVar1 < *(int *)(extraout_ECX + 4));
  }
  FUN_004afc21(*(undefined4 *)(unaff_EBP + -0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

