
void FUN_0046e1a7(void)

{
  LPCSTR pCVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  puVar3 = (undefined4 *)FUN_0046b505(0x14);
  *(undefined4 **)(unaff_EBP + -0x14) = puVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_0046cfc9(puVar3);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0046bd7a(puVar3 + 4);
    pCVar1 = *(LPCSTR *)(unaff_EBP + 0x10);
    puVar3[2] = *(undefined4 *)(unaff_EBP + 8);
    uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *puVar3 = &PTR_FUN_00486a54;
    puVar3[3] = uVar2;
    FUN_0046c00d(puVar3 + 4,pCVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 **)(unaff_EBP + -0x10) = puVar3;
  FUN_00457540(unaff_EBP + -0x10,&DAT_0048feb0);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

