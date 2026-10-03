
undefined4 FUN_004b8352(void)

{
  undefined4 *puVar1;
  int iVar2;
  Tact2010CString *pTVar3;
  int iVar4;
  BOOL BVar5;
  int *piVar6;
  undefined4 uVar7;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  FUN_004b0613((Tact2010CString *)(unaff_EBP + 8),*(char **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004bef68();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x2c) = 4;
  puVar1 = (undefined4 *)FUN_004aa7d8(unaff_EBP + -0x14,7);
  iVar2 = FUN_0049bd00(*puVar1,"[open(\"");
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_EBP + -0x2c) = 1;
    pTVar3 = (Tact2010CString *)
             FUN_004aa75b(unaff_EBP + -0x14,*(int *)(*(int *)(unaff_EBP + 8) + -8) + -7);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_004b069e((Tact2010CString *)(unaff_EBP + 8),pTVar3);
    *(undefined1 *)(unaff_EBP + -4) = 1;
LAB_004b8447:
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
LAB_004b84b9:
    iVar2 = FUN_004b09ed(0x22);
    if (iVar2 != -1) {
      pTVar3 = (Tact2010CString *)FUN_004aa7d8(unaff_EBP + -0x14,iVar2);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_004b069e((Tact2010CString *)(unaff_EBP + -0x28),pTVar3);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
      pTVar3 = (Tact2010CString *)
               FUN_004aa75b(unaff_EBP + -0x14,*(int *)(*(int *)(unaff_EBP + 8) + -8) - iVar2);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_004b069e((Tact2010CString *)(unaff_EBP + 8),pTVar3);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      iVar2 = FUN_004bfff8();
      if (*(int *)(*(int *)(iVar2 + 4) + 0xac) == 0) {
        iVar2 = FUN_004bfff8();
        *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(*(int *)(iVar2 + 4) + 0xac);
      }
      else {
        iVar2 = FUN_004bfff8();
        iVar2 = *(int *)(iVar2 + 4);
        iVar4 = FUN_004bfff8();
        *(undefined4 *)(*(int *)(iVar4 + 4) + 0x74) = *(undefined4 *)(iVar2 + 0xac);
        iVar2 = FUN_004bfff8();
        *(int *)(*(int *)(iVar2 + 4) + 0xac) = unaff_EBP + -0x3c;
      }
      if (*(int *)(unaff_EBP + -0x2c) == 1) {
        iVar2 = FUN_004bfff8();
        iVar2 = *(int *)(*(int *)(iVar2 + 4) + 0x1c);
        iVar4 = FUN_004bfff8();
        iVar4 = *(int *)(*(int *)(iVar4 + 4) + 0x74);
        if ((iVar4 == -1) || (iVar4 == 1)) {
          BVar5 = IsIconic(*(HWND *)(iVar2 + 0x1c));
          iVar4 = (-(uint)(BVar5 != 0) & 4) + 5;
        }
        FUN_004af52c(iVar4);
        if (iVar4 != 6) {
          SetForegroundWindow(*(HWND *)(iVar2 + 0x1c));
        }
        iVar2 = FUN_004bfff8();
        (**(code **)(**(int **)(iVar2 + 4) + 0x84))(*(undefined4 *)(unaff_EBP + -0x28));
        iVar2 = FUN_004bce18();
        if (iVar2 == 0) {
          FUN_004bce09(1);
        }
        iVar2 = FUN_004bfff8();
        *(undefined4 *)(*(int *)(iVar2 + 4) + 0x74) = 0xffffffff;
      }
      else if (*(int *)(unaff_EBP + -0x2c) == 3) {
        puVar1 = (undefined4 *)FUN_004aa7d8(unaff_EBP + -0x18,3);
        iVar2 = FUN_0049bd00(*puVar1,&DAT_004cf6e4);
        FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
        if (iVar2 == 0) {
          pTVar3 = (Tact2010CString *)
                   FUN_004aa75b(unaff_EBP + -0x18,*(int *)(*(int *)(unaff_EBP + 8) + -8) + -3);
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_004b069e((Tact2010CString *)(unaff_EBP + 8),pTVar3);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
          iVar2 = FUN_004b09ed(0x22);
          if (iVar2 != -1) {
            pTVar3 = (Tact2010CString *)FUN_004aa7d8(unaff_EBP + -0x18,iVar2);
            *(undefined1 *)(unaff_EBP + -4) = 8;
            FUN_004b069e((Tact2010CString *)(unaff_EBP + -0x24),pTVar3);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
            pTVar3 = (Tact2010CString *)
                     FUN_004aa75b(unaff_EBP + -0x18,*(int *)(*(int *)(unaff_EBP + 8) + -8) - iVar2);
            *(undefined1 *)(unaff_EBP + -4) = 9;
            FUN_004b069e((Tact2010CString *)(unaff_EBP + 8),pTVar3);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
            puVar1 = (undefined4 *)FUN_004aa7d8(unaff_EBP + -0x18,3);
            iVar2 = FUN_0049bd00(*puVar1,&DAT_004cf6e4);
            FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
            if (iVar2 == 0) {
              pTVar3 = (Tact2010CString *)
                       FUN_004aa75b(unaff_EBP + -0x18,*(int *)(*(int *)(unaff_EBP + 8) + -8) + -3);
              *(undefined1 *)(unaff_EBP + -4) = 10;
              FUN_004b069e((Tact2010CString *)(unaff_EBP + 8),pTVar3);
              *(undefined1 *)(unaff_EBP + -4) = 1;
              FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
              iVar2 = FUN_004b09ed(0x22);
              if (iVar2 != -1) {
                pTVar3 = (Tact2010CString *)FUN_004aa7d8(unaff_EBP + -0x18,iVar2);
                *(undefined1 *)(unaff_EBP + -4) = 0xb;
                FUN_004b069e((Tact2010CString *)(unaff_EBP + -0x20),pTVar3);
                *(undefined1 *)(unaff_EBP + -4) = 1;
                FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
                pTVar3 = (Tact2010CString *)
                         FUN_004aa75b(unaff_EBP + -0x18,
                                      *(int *)(*(int *)(unaff_EBP + 8) + -8) - iVar2);
                *(undefined1 *)(unaff_EBP + -4) = 0xc;
                FUN_004b069e((Tact2010CString *)(unaff_EBP + 8),pTVar3);
                *(undefined1 *)(unaff_EBP + -4) = 1;
                FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
                puVar1 = (undefined4 *)FUN_004aa7d8(unaff_EBP + -0x18,3);
                iVar2 = FUN_0049bd00(*puVar1,&DAT_004cf6e4);
                FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
                if (iVar2 == 0) {
                  pTVar3 = (Tact2010CString *)
                           FUN_004aa75b(unaff_EBP + -0x18,
                                        *(int *)(*(int *)(unaff_EBP + 8) + -8) + -3);
                  *(undefined1 *)(unaff_EBP + -4) = 0xd;
                  FUN_004b069e((Tact2010CString *)(unaff_EBP + 8),pTVar3);
                  *(undefined1 *)(unaff_EBP + -4) = 1;
                  FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
                  iVar2 = FUN_004b09ed(0x22);
                  if (iVar2 != -1) {
                    pTVar3 = (Tact2010CString *)FUN_004aa7d8(unaff_EBP + -0x18,iVar2);
                    *(undefined1 *)(unaff_EBP + -4) = 0xe;
                    FUN_004b069e((Tact2010CString *)(unaff_EBP + -0x1c),pTVar3);
                    *(undefined1 *)(unaff_EBP + -4) = 1;
                    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
                    pTVar3 = (Tact2010CString *)
                             FUN_004aa75b(unaff_EBP + -0x18,
                                          *(int *)(*(int *)(unaff_EBP + 8) + -8) - iVar2);
                    *(undefined1 *)(unaff_EBP + -4) = 0xf;
                    FUN_004b069e((Tact2010CString *)(unaff_EBP + 8),pTVar3);
                    *(undefined1 *)(unaff_EBP + -4) = 1;
                    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x18));
                    goto LAB_004b8867;
                  }
                }
              }
            }
          }
        }
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
      }
      else {
LAB_004b8867:
        iVar2 = FUN_004bfff8();
        piVar6 = (int *)(**(code **)(**(int **)(iVar2 + 4) + 0x84))
                                  (*(undefined4 *)(unaff_EBP + -0x28));
        iVar2 = FUN_004bfff8();
        *(int *)(*(int *)(iVar2 + 4) + 0xac) = unaff_EBP + -0x3c;
        iVar2 = FUN_004bfff8();
        SendMessageA(*(HWND *)(*(int *)(*(int *)(iVar2 + 4) + 0x1c) + 0x1c),0x111,0xe108,0);
        iVar2 = FUN_004bfff8();
        *(undefined4 *)(*(int *)(iVar2 + 4) + 0xac) = 0;
        (**(code **)(*piVar6 + 0x84))();
        iVar2 = FUN_004bce18();
        if (iVar2 == 0) {
          iVar2 = FUN_004bfff8();
          PostMessageA(*(HWND *)(*(int *)(*(int *)(iVar2 + 4) + 0x1c) + 0x1c),0x10,0,0);
        }
      }
      iVar2 = FUN_004bfff8();
      iVar2 = *(int *)(iVar2 + 4);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(iVar2 + 0xac) = *(undefined4 *)(unaff_EBP + -0x14);
      FUN_004beff3();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + 8));
      uVar7 = *(undefined4 *)(unaff_EBP + -0x10);
      goto LAB_004b892f;
    }
  }
  else {
    puVar1 = (undefined4 *)FUN_004aa7d8(unaff_EBP + -0x14,8);
    iVar2 = FUN_0049bd00(*puVar1,"[print(\"");
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x2c) = 2;
      pTVar3 = (Tact2010CString *)
               FUN_004aa75b(unaff_EBP + -0x14,*(int *)(*(int *)(unaff_EBP + 8) + -8) + -8);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_004b069e((Tact2010CString *)(unaff_EBP + 8),pTVar3);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      goto LAB_004b8447;
    }
    puVar1 = (undefined4 *)FUN_004aa7d8(unaff_EBP + -0x14,10);
    iVar2 = FUN_0049bd00(*puVar1,"[printto(\"");
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
    if (iVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x2c) = 3;
      pTVar3 = (Tact2010CString *)
               FUN_004aa75b(unaff_EBP + -0x14,*(int *)(*(int *)(unaff_EBP + 8) + -8) + -10);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_004b069e((Tact2010CString *)(unaff_EBP + 8),pTVar3);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
      goto LAB_004b84b9;
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004beff3();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)(unaff_EBP + 8));
  uVar7 = 0;
LAB_004b892f:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar7;
}

