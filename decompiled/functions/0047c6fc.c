
void FUN_0047c6fc(void)

{
  int *piVar1;
  code *pcVar2;
  LPCSTR lpSubKey;
  bool bVar3;
  int iVar4;
  undefined4 *puVar5;
  HICON hIcon;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  LPSTR lpData;
  LSTATUS LVar6;
  undefined3 extraout_var_07;
  int extraout_ECX;
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar7;
  PLONG lpcbData;
  
  FUN_00457418();
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x30));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x14));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar4 = FUN_0047b918();
  FUN_0046ced8(*(HMODULE *)(iVar4 + 8),(void *)(unaff_EBP + -0x30));
  puVar5 = *(undefined4 **)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -0x38) = 1;
  if (puVar5 == (undefined4 *)0x0) {
LAB_0047cb44:
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0046bec5((int *)(unaff_EBP + -0x14));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046bec5((int *)(unaff_EBP + -0x30));
    *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
    return;
  }
  do {
    piVar1 = (int *)puVar5[2];
    *(undefined4 *)(unaff_EBP + -0x3c) = *puVar5;
    FUN_0046bd8a((void *)(unaff_EBP + -0x1c),(int *)(unaff_EBP + -0x30));
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_0046bd8a((void *)(unaff_EBP + -0x28),(int *)(unaff_EBP + -0x30));
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_0046bd8a((void *)(unaff_EBP + -0x24),(int *)(unaff_EBP + -0x30));
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_0046bd8a((void *)(unaff_EBP + -0x2c),(int *)(unaff_EBP + -0x30));
    *(undefined1 *)(unaff_EBP + -4) = 5;
    if (*(int *)(unaff_EBP + 8) != 0) {
      FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x34));
      *(undefined1 *)(unaff_EBP + -4) = 6;
      iVar4 = FUN_0047b918();
      hIcon = ExtractIconA(*(HINSTANCE *)(iVar4 + 8),*(LPCSTR *)(unaff_EBP + -0x30),
                           *(UINT *)(unaff_EBP + -0x38));
      if (hIcon == (HICON)0x0) {
        FUN_00466415((void *)(unaff_EBP + -0x34),&DAT_004878f4);
      }
      else {
        FUN_00466415((void *)(unaff_EBP + -0x34),&DAT_004878f4);
        DestroyIcon(hIcon);
      }
      FUN_0046c25e((void *)(unaff_EBP + -0x2c),(undefined4 *)(unaff_EBP + -0x34));
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_0046bec5((int *)(unaff_EBP + -0x34));
    }
    FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x18));
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x10));
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_0046bd7a((undefined4 *)(unaff_EBP + -0x20));
    iVar4 = *piVar1;
    *(undefined1 *)(unaff_EBP + -4) = 9;
    pcVar2 = *(code **)(iVar4 + 0x6c);
    iVar4 = (*pcVar2)(unaff_EBP + -0x10,5);
    if ((iVar4 != 0) && (*(int *)(*(int *)(unaff_EBP + -0x10) + -8) != 0)) {
      iVar4 = (*pcVar2)(unaff_EBP + -0x20,6);
      if (iVar4 == 0) {
        FUN_0046bfbe((void *)(unaff_EBP + -0x20),(int *)(unaff_EBP + -0x10));
      }
      bVar3 = FUN_0047cb6b(*(HKEY *)(unaff_EBP + -0x10),*(BYTE **)(unaff_EBP + -0x20),(LPCSTR)0x0);
      if (CONCAT31(extraout_var,bVar3) != 0) {
        if (*(int *)(unaff_EBP + 8) != 0) {
          FUN_00466415((void *)(unaff_EBP + -0x14),(byte *)"%s\\DefaultIcon");
          bVar3 = FUN_0047cb6b(*(HKEY *)(unaff_EBP + -0x14),*(BYTE **)(unaff_EBP + -0x2c),
                               (LPCSTR)0x0);
          if (CONCAT31(extraout_var_00,bVar3) == 0) goto LAB_0047cae3;
        }
        iVar4 = (*pcVar2)(unaff_EBP + -0x14,0);
        if ((iVar4 == 0) || (*(int *)(*(int *)(unaff_EBP + -0x14) + -8) == 0)) {
          FUN_00466415((void *)(unaff_EBP + -0x14),(byte *)"%s\\shell\\open\\%s");
          bVar3 = FUN_0047cb6b(*(HKEY *)(unaff_EBP + -0x14),(BYTE *)"[open(\"%1\")]",(LPCSTR)0x0);
          if (CONCAT31(extraout_var_01,bVar3) != 0) {
            if (*(int *)(unaff_EBP + 8) == 0) {
              pcVar7 = " \"%1\"";
              this = (void *)(unaff_EBP + -0x1c);
              goto LAB_0047c9b1;
            }
            FUN_00466415((void *)(unaff_EBP + -0x14),(byte *)"%s\\shell\\print\\%s");
            bVar3 = FUN_0047cb6b(*(HKEY *)(unaff_EBP + -0x14),(BYTE *)"[print(\"%1\")]",(LPCSTR)0x0)
            ;
            if (CONCAT31(extraout_var_02,bVar3) != 0) {
              FUN_00466415((void *)(unaff_EBP + -0x14),(byte *)"%s\\shell\\printto\\%s");
              bVar3 = FUN_0047cb6b(*(HKEY *)(unaff_EBP + -0x14),
                                   (BYTE *)"[printto(\"%1\",\"%2\",\"%3\",\"%4\")]",(LPCSTR)0x0);
              if (CONCAT31(extraout_var_03,bVar3) != 0) {
                FUN_0046c222((void *)(unaff_EBP + -0x1c)," /dde");
                FUN_0046c222((void *)(unaff_EBP + -0x28)," /dde");
                pcVar7 = " /dde";
                goto LAB_0047c9a4;
              }
            }
          }
        }
        else {
          FUN_0046c222((void *)(unaff_EBP + -0x1c)," \"%1\"");
          if (*(int *)(unaff_EBP + 8) != 0) {
            FUN_0046c222((void *)(unaff_EBP + -0x28)," /p \"%1\"");
            pcVar7 = " /pt \"%1\" \"%2\" \"%3\" \"%4\"";
LAB_0047c9a4:
            this = (void *)(unaff_EBP + -0x24);
LAB_0047c9b1:
            FUN_0046c222(this,pcVar7);
          }
          FUN_00466415((void *)(unaff_EBP + -0x14),(byte *)"%s\\shell\\open\\%s");
          bVar3 = FUN_0047cb6b(*(HKEY *)(unaff_EBP + -0x14),*(BYTE **)(unaff_EBP + -0x1c),
                               (LPCSTR)0x0);
          if (CONCAT31(extraout_var_04,bVar3) != 0) {
            if (*(int *)(unaff_EBP + 8) == 0) {
LAB_0047ca42:
              (*pcVar2)(unaff_EBP + -0x18,4);
              lpSubKey = *(LPCSTR *)(unaff_EBP + -0x18);
              if (*(int *)(lpSubKey + -8) != 0) {
                lpcbData = (PLONG)(unaff_EBP + -0x40);
                *(undefined4 *)(unaff_EBP + -0x40) = 0x208;
                lpData = (LPSTR)FUN_0046c276((void *)(unaff_EBP + -0x14),0x208);
                LVar6 = RegQueryValueA((HKEY)0x80000000,lpSubKey,lpData,lpcbData);
                FUN_0046c2c5((void *)(unaff_EBP + -0x14),-1);
                if ((((LVar6 != 0) || (*(int *)(*(byte **)(unaff_EBP + -0x14) + -8) == 0)) ||
                    (iVar4 = FUN_00457440(*(byte **)(unaff_EBP + -0x14),
                                          *(byte **)(unaff_EBP + -0x10)), iVar4 == 0)) &&
                   ((bVar3 = FUN_0047cb6b(*(HKEY *)(unaff_EBP + -0x18),*(BYTE **)(unaff_EBP + -0x10)
                                          ,(LPCSTR)0x0), CONCAT31(extraout_var_07,bVar3) != 0 &&
                    (*(int *)(unaff_EBP + 8) != 0)))) {
                  FUN_00466415((void *)(unaff_EBP + -0x14),(byte *)"%s\\ShellNew");
                  FUN_0047cb6b(*(HKEY *)(unaff_EBP + -0x14),"","NullFile");
                }
              }
            }
            else {
              FUN_00466415((void *)(unaff_EBP + -0x14),(byte *)"%s\\shell\\print\\%s");
              bVar3 = FUN_0047cb6b(*(HKEY *)(unaff_EBP + -0x14),*(BYTE **)(unaff_EBP + -0x28),
                                   (LPCSTR)0x0);
              if (CONCAT31(extraout_var_05,bVar3) != 0) {
                FUN_00466415((void *)(unaff_EBP + -0x14),(byte *)"%s\\shell\\printto\\%s");
                bVar3 = FUN_0047cb6b(*(HKEY *)(unaff_EBP + -0x14),*(BYTE **)(unaff_EBP + -0x24),
                                     (LPCSTR)0x0);
                if (CONCAT31(extraout_var_06,bVar3) != 0) goto LAB_0047ca42;
              }
            }
          }
        }
      }
    }
LAB_0047cae3:
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_0046bec5((int *)(unaff_EBP + -0x20));
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_0046bec5((int *)(unaff_EBP + -0x10));
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_0046bec5((int *)(unaff_EBP + -0x18));
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_0046bec5((int *)(unaff_EBP + -0x2c));
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_0046bec5((int *)(unaff_EBP + -0x24));
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_0046bec5((int *)(unaff_EBP + -0x28));
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0046bec5((int *)(unaff_EBP + -0x1c));
    *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) + 1;
    if (*(int *)(unaff_EBP + -0x3c) == 0) goto LAB_0047cb44;
    puVar5 = *(undefined4 **)(unaff_EBP + -0x3c);
  } while( true );
}

