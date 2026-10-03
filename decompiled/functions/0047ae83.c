
undefined4 FUN_0047ae83(void)

{
  LPCSTR pCVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  TactCString *pTVar5;
  LSTATUS LVar6;
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  iVar3 = FUN_004727b9((int)this);
  *(int *)(unaff_EBP + -0x1c) = iVar3;
  while (iVar3 != 0) {
    piVar4 = (int *)FUN_004727cb(this,unaff_EBP + -0x1c);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x14))(0,0xfffffffc,0,0);
    }
    iVar3 = *(int *)(unaff_EBP + -0x1c);
  }
  if (*(int *)((int)this + 0x7c) != 0) {
    FUN_0046bf33((void *)(unaff_EBP + -0x10),"Software\\");
    pCVar1 = *(LPCSTR *)((int)this + 0x7c);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0046c222((void *)(unaff_EBP + -0x10),pCVar1);
    pTVar5 = FUN_0046c0db((TactCString *)(unaff_EBP + -0x20),(TactCString *)(unaff_EBP + -0x10),"\\"
                         );
    pcVar2 = *(char **)((int)this + 0x90);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0046c0db((TactCString *)(unaff_EBP + -0x18),pTVar5,pcVar2);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_0046bec5((int *)(unaff_EBP + -0x20));
    FUN_0047afb2();
    LVar6 = RegOpenKeyA((HKEY)0x80000001,*(LPCSTR *)(unaff_EBP + -0x10),(PHKEY)(unaff_EBP + -0x14));
    if (LVar6 == 0) {
      LVar6 = RegEnumKeyA(*(HKEY *)(unaff_EBP + -0x14),0,(LPSTR)(unaff_EBP + -300),0x104);
      if (LVar6 == 0x103) {
        FUN_0047afb2();
      }
      RegCloseKey(*(HKEY *)(unaff_EBP + -0x14));
    }
    RegQueryValueA((HKEY)0x80000001,*(LPCSTR *)(unaff_EBP + -0x18),(LPSTR)(unaff_EBP + -300),
                   (PLONG)(unaff_EBP + -0x24));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0046bec5((int *)(unaff_EBP + -0x18));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046bec5((int *)(unaff_EBP + -0x10));
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return 1;
}

