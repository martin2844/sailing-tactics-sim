
void FUN_004b65c6(void)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  puVar3 = (undefined4 *)FUN_004afbe5(0x10);
  *(undefined4 **)(unaff_EBP + -0x14) = puVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_004b16a9();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_004b045a((Tact2010CString *)(puVar3 + 3));
    uVar1 = *(undefined4 *)(unaff_EBP + 8);
    pcVar2 = *(char **)(unaff_EBP + 0xc);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *puVar3 = &PTR_FUN_004cf904;
    puVar3[2] = uVar1;
    FUN_004b06ed((Tact2010CString *)(puVar3 + 3),pcVar2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 **)(unaff_EBP + -0x10) = puVar3;
  FUN_0049be00(unaff_EBP + -0x10,&DAT_004d9610);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

