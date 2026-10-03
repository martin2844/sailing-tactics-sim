
undefined4 FUN_004bf563(void)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  Tact2010CString *pTVar5;
  LSTATUS LVar6;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  iVar3 = FUN_004b6e99();
  *(int *)(unaff_EBP + -0x1c) = iVar3;
  while (iVar3 != 0) {
    piVar4 = (int *)FUN_004b6eab(unaff_EBP + -0x1c);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x14))(0,0xfffffffc,0,0);
    }
    iVar3 = *(int *)(unaff_EBP + -0x1c);
  }
  if (*(int *)(extraout_ECX + 0x7c) != 0) {
    FUN_004b0613((Tact2010CString *)(unaff_EBP + -0x10),"Software\\");
    uVar1 = *(undefined4 *)(extraout_ECX + 0x7c);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004b0902(uVar1);
    pTVar5 = FUN_004b07bb((Tact2010CString *)(unaff_EBP + -0x20),
                          (Tact2010CString *)(unaff_EBP + -0x10),"\\");
    pcVar2 = *(char **)(extraout_ECX + 0x90);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_004b07bb((Tact2010CString *)(unaff_EBP + -0x18),pTVar5,pcVar2);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x20));
    FUN_004bf692(0x80000001,unaff_EBP + -0x18);
    LVar6 = RegOpenKeyA((HKEY)0x80000001,*(LPCSTR *)(unaff_EBP + -0x10),(PHKEY)(unaff_EBP + -0x14));
    if (LVar6 == 0) {
      LVar6 = RegEnumKeyA(*(HKEY *)(unaff_EBP + -0x14),0,(LPSTR)(unaff_EBP + -300),0x104);
      if (LVar6 == 0x103) {
        FUN_004bf692(0x80000001,unaff_EBP + -0x10);
      }
      RegCloseKey(*(HKEY *)(unaff_EBP + -0x14));
    }
    RegQueryValueA((HKEY)0x80000001,*(LPCSTR *)(unaff_EBP + -0x18),(LPSTR)(unaff_EBP + -300),
                   (PLONG)(unaff_EBP + -0x24));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return 1;
}

