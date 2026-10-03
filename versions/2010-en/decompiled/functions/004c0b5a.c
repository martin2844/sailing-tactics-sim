
void FUN_004c0b5a(void)

{
  undefined4 *puVar1;
  int *piVar2;
  code *pcVar3;
  LPCSTR lpSubKey;
  undefined4 *puVar4;
  int iVar5;
  LPSTR lpData;
  LSTATUS LVar6;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  PLONG lpcbData;
  
  FUN_0049bcd8();
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x24));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar5 = FUN_004bfff8();
  FUN_004b15b8(*(undefined4 *)(iVar5 + 8),unaff_EBP + -0x24);
  puVar4 = *(undefined4 **)(extraout_ECX + 8);
  while (puVar4 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar4;
    piVar2 = (int *)puVar4[2];
    FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x18));
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x14));
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x20));
    pcVar3 = *(code **)(*piVar2 + 0x6c);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(code **)(unaff_EBP + -0x1c) = pcVar3;
    iVar5 = (*pcVar3)(unaff_EBP + -0x14,5);
    if ((iVar5 != 0) && (*(int *)(*(int *)(unaff_EBP + -0x14) + -8) != 0)) {
      iVar5 = (**(code **)(unaff_EBP + -0x1c))(unaff_EBP + -0x20,6);
      if (iVar5 == 0) {
        FUN_004b069e((Tact2010CString *)(unaff_EBP + -0x20),(Tact2010CString *)(unaff_EBP + -0x14));
      }
      FUN_004aaaf5(unaff_EBP + -0x10,"%s\\DefaultIcon",*(undefined4 *)(unaff_EBP + -0x14));
      FUN_004c0a77(*(undefined4 *)(unaff_EBP + -0x10));
      iVar5 = (**(code **)(unaff_EBP + -0x1c))(unaff_EBP + -0x10,0);
      if ((iVar5 == 0) || (*(int *)(*(int *)(unaff_EBP + -0x10) + -8) == 0)) {
        FUN_004aaaf5(unaff_EBP + -0x10,"%s\\shell\\open\\%s",*(undefined4 *)(unaff_EBP + -0x14),
                     "ddeexec");
        FUN_004c0a77(*(undefined4 *)(unaff_EBP + -0x10));
        FUN_004aaaf5(unaff_EBP + -0x10,"%s\\shell\\print\\%s",*(undefined4 *)(unaff_EBP + -0x14),
                     "ddeexec");
        FUN_004c0a77(*(undefined4 *)(unaff_EBP + -0x10));
        FUN_004aaaf5(unaff_EBP + -0x10,"%s\\shell\\printto\\%s",*(undefined4 *)(unaff_EBP + -0x14),
                     "ddeexec");
        FUN_004c0a77(*(undefined4 *)(unaff_EBP + -0x10));
      }
      FUN_004aaaf5(unaff_EBP + -0x10,"%s\\shell\\open\\%s",*(undefined4 *)(unaff_EBP + -0x14),
                   "command");
      FUN_004c0a77(*(undefined4 *)(unaff_EBP + -0x10));
      FUN_004aaaf5(unaff_EBP + -0x10,"%s\\shell\\print\\%s",*(undefined4 *)(unaff_EBP + -0x14),
                   "command");
      FUN_004c0a77(*(undefined4 *)(unaff_EBP + -0x10));
      FUN_004aaaf5(unaff_EBP + -0x10,"%s\\shell\\printto\\%s",*(undefined4 *)(unaff_EBP + -0x14),
                   "command");
      FUN_004c0a77(*(undefined4 *)(unaff_EBP + -0x10));
      (**(code **)(unaff_EBP + -0x1c))(unaff_EBP + -0x18,4);
      lpSubKey = *(LPCSTR *)(unaff_EBP + -0x18);
      if (*(int *)(lpSubKey + -8) != 0) {
        lpcbData = (PLONG)(unaff_EBP + -0x28);
        *(undefined4 *)(unaff_EBP + -0x28) = 0x208;
        lpData = (LPSTR)FUN_004b0956(0x208);
        LVar6 = RegQueryValueA((HKEY)0x80000000,lpSubKey,lpData,lpcbData);
        FUN_004b09a5(0xffffffff);
        if (((LVar6 != 0) || (*(int *)(*(int *)(unaff_EBP + -0x10) + -8) == 0)) ||
           (iVar5 = FUN_0049bd00(*(int *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x14)),
           iVar5 == 0)) {
          FUN_004aaaf5(unaff_EBP + -0x10,"%s\\ShellNew",*(undefined4 *)(unaff_EBP + -0x18));
          FUN_004c0a77(*(undefined4 *)(unaff_EBP + -0x10));
          FUN_004c0a77(*(undefined4 *)(unaff_EBP + -0x18));
        }
      }
    }
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x20));
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
    puVar4 = puVar1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x24));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

