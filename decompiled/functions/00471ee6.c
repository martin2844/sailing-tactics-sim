
void FUN_00471ee6(void)

{
  undefined4 uVar1;
  LPCSTR pCVar2;
  undefined4 *puVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  puVar3 = (undefined4 *)FUN_0046b505(0x10);
  *(undefined4 **)(unaff_EBP + -0x14) = puVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_0046cfc9(puVar3);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0046bd7a(puVar3 + 3);
    uVar1 = *(undefined4 *)(unaff_EBP + 8);
    pCVar2 = *(LPCSTR *)(unaff_EBP + 0xc);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *puVar3 = &PTR_FUN_00487c64;
    puVar3[2] = uVar1;
    FUN_0046c00d(puVar3 + 3,pCVar2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 **)(unaff_EBP + -0x10) = puVar3;
  FUN_00457540(unaff_EBP + -0x10,&DAT_0048ff60);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

