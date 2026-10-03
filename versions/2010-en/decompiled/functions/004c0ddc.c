
void FUN_004c0ddc(void)

{
  int *piVar1;
  code *pcVar2;
  LPCSTR lpSubKey;
  int iVar3;
  undefined4 *puVar4;
  HICON hIcon;
  LPSTR lpData;
  LSTATUS LVar5;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar6;
  PLONG lpcbData;
  
  FUN_0049bcd8();
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x30));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x14));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar3 = FUN_004bfff8();
  FUN_004b15b8(*(undefined4 *)(iVar3 + 8),unaff_EBP + -0x30);
  puVar4 = *(undefined4 **)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -0x38) = 1;
  if (puVar4 == (undefined4 *)0x0) {
LAB_004c1224:
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x30));
    *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
    return;
  }
  do {
    piVar1 = (int *)puVar4[2];
    *(undefined4 *)(unaff_EBP + -0x3c) = *puVar4;
    FUN_004b046a((Tact2010CString *)(unaff_EBP + -0x1c),(Tact2010CString *)(unaff_EBP + -0x30));
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_004b046a((Tact2010CString *)(unaff_EBP + -0x28),(Tact2010CString *)(unaff_EBP + -0x30));
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_004b046a((Tact2010CString *)(unaff_EBP + -0x24),(Tact2010CString *)(unaff_EBP + -0x30));
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_004b046a((Tact2010CString *)(unaff_EBP + -0x2c),(Tact2010CString *)(unaff_EBP + -0x30));
    *(undefined1 *)(unaff_EBP + -4) = 5;
    if (*(int *)(unaff_EBP + 8) != 0) {
      FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x34));
      *(undefined1 *)(unaff_EBP + -4) = 6;
      iVar3 = FUN_004bfff8();
      hIcon = ExtractIconA(*(HINSTANCE *)(iVar3 + 8),*(LPCSTR *)(unaff_EBP + -0x30),
                           *(UINT *)(unaff_EBP + -0x38));
      if (hIcon == (HICON)0x0) {
        FUN_004aaaf5(unaff_EBP + -0x34,&DAT_004cf594,0);
      }
      else {
        FUN_004aaaf5(unaff_EBP + -0x34,&DAT_004cf594,*(undefined4 *)(unaff_EBP + -0x38));
        DestroyIcon(hIcon);
      }
      FUN_004b093e(unaff_EBP + -0x34);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x34));
    }
    FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x18));
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x20));
    iVar3 = *piVar1;
    *(undefined1 *)(unaff_EBP + -4) = 9;
    pcVar2 = *(code **)(iVar3 + 0x6c);
    iVar3 = (*pcVar2)(unaff_EBP + -0x10,5);
    if ((iVar3 != 0) && (*(int *)(*(int *)(unaff_EBP + -0x10) + -8) != 0)) {
      iVar3 = (*pcVar2)(unaff_EBP + -0x20,6);
      if (iVar3 == 0) {
        FUN_004b069e((Tact2010CString *)(unaff_EBP + -0x20),(Tact2010CString *)(unaff_EBP + -0x10));
      }
      iVar3 = FUN_004c124b(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x20),0);
      if (iVar3 != 0) {
        if (*(int *)(unaff_EBP + 8) != 0) {
          FUN_004aaaf5(unaff_EBP + -0x14,"%s\\DefaultIcon",*(undefined4 *)(unaff_EBP + -0x10));
          iVar3 = FUN_004c124b(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x2c)
                               ,0);
          if (iVar3 == 0) goto LAB_004c11c3;
        }
        iVar3 = (*pcVar2)(unaff_EBP + -0x14,0);
        if ((iVar3 == 0) || (*(int *)(*(int *)(unaff_EBP + -0x14) + -8) == 0)) {
          FUN_004aaaf5(unaff_EBP + -0x14,"%s\\shell\\open\\%s",*(undefined4 *)(unaff_EBP + -0x10),
                       "ddeexec");
          iVar3 = FUN_004c124b(*(undefined4 *)(unaff_EBP + -0x14),"[open(\"%1\")]",0);
          if (iVar3 != 0) {
            if (*(int *)(unaff_EBP + 8) == 0) {
              pcVar6 = " \"%1\"";
LAB_004c1091:
              FUN_004b0902(pcVar6);
              goto LAB_004c1096;
            }
            FUN_004aaaf5(unaff_EBP + -0x14,"%s\\shell\\print\\%s",*(undefined4 *)(unaff_EBP + -0x10)
                         ,"ddeexec");
            iVar3 = FUN_004c124b(*(undefined4 *)(unaff_EBP + -0x14),"[print(\"%1\")]",0);
            if (iVar3 != 0) {
              FUN_004aaaf5(unaff_EBP + -0x14,"%s\\shell\\printto\\%s",
                           *(undefined4 *)(unaff_EBP + -0x10),"ddeexec");
              iVar3 = FUN_004c124b(*(undefined4 *)(unaff_EBP + -0x14),
                                   "[printto(\"%1\",\"%2\",\"%3\",\"%4\")]",0);
              if (iVar3 != 0) {
                FUN_004b0902(" /dde");
                FUN_004b0902(" /dde");
                pcVar6 = " /dde";
                goto LAB_004c1091;
              }
            }
          }
        }
        else {
          FUN_004b0902(" \"%1\"");
          if (*(int *)(unaff_EBP + 8) != 0) {
            FUN_004b0902(" /p \"%1\"");
            pcVar6 = " /pt \"%1\" \"%2\" \"%3\" \"%4\"";
            goto LAB_004c1091;
          }
LAB_004c1096:
          FUN_004aaaf5(unaff_EBP + -0x14,"%s\\shell\\open\\%s",*(undefined4 *)(unaff_EBP + -0x10),
                       "command");
          iVar3 = FUN_004c124b(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x1c)
                               ,0);
          if (iVar3 != 0) {
            if (*(int *)(unaff_EBP + 8) == 0) {
LAB_004c1122:
              (*pcVar2)(unaff_EBP + -0x18,4);
              lpSubKey = *(LPCSTR *)(unaff_EBP + -0x18);
              if (*(int *)(lpSubKey + -8) != 0) {
                lpcbData = (PLONG)(unaff_EBP + -0x40);
                *(undefined4 *)(unaff_EBP + -0x40) = 0x208;
                lpData = (LPSTR)FUN_004b0956(0x208);
                LVar5 = RegQueryValueA((HKEY)0x80000000,lpSubKey,lpData,lpcbData);
                FUN_004b09a5(0xffffffff);
                if ((((LVar5 != 0) || (*(int *)(*(int *)(unaff_EBP + -0x14) + -8) == 0)) ||
                    (iVar3 = FUN_0049bd00(*(int *)(unaff_EBP + -0x14),
                                          *(undefined4 *)(unaff_EBP + -0x10)), iVar3 == 0)) &&
                   ((iVar3 = FUN_004c124b(*(undefined4 *)(unaff_EBP + -0x18),
                                          *(undefined4 *)(unaff_EBP + -0x10),0), iVar3 != 0 &&
                    (*(int *)(unaff_EBP + 8) != 0)))) {
                  FUN_004aaaf5(unaff_EBP + -0x14,"%s\\ShellNew",*(undefined4 *)(unaff_EBP + -0x18));
                  FUN_004c124b(*(undefined4 *)(unaff_EBP + -0x14),&DAT_004cf634,"NullFile");
                }
              }
            }
            else {
              FUN_004aaaf5(unaff_EBP + -0x14,"%s\\shell\\print\\%s",
                           *(undefined4 *)(unaff_EBP + -0x10),"command");
              iVar3 = FUN_004c124b(*(undefined4 *)(unaff_EBP + -0x14),
                                   *(undefined4 *)(unaff_EBP + -0x28),0);
              if (iVar3 != 0) {
                FUN_004aaaf5(unaff_EBP + -0x14,"%s\\shell\\printto\\%s",
                             *(undefined4 *)(unaff_EBP + -0x10),"command");
                iVar3 = FUN_004c124b(*(undefined4 *)(unaff_EBP + -0x14),
                                     *(undefined4 *)(unaff_EBP + -0x24),0);
                if (iVar3 != 0) goto LAB_004c1122;
              }
            }
          }
        }
      }
    }
LAB_004c11c3:
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x20));
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x2c));
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x24));
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x28));
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x1c));
    *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) + 1;
    if (*(int *)(unaff_EBP + -0x3c) == 0) goto LAB_004c1224;
    puVar4 = *(undefined4 **)(unaff_EBP + -0x3c);
  } while( true );
}

