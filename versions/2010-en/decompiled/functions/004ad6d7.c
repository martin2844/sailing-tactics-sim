
/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 FUN_004ad6d7(void)

{
  code *pcVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  AFX_MSGMAP_ENTRY *pAVar7;
  DWORD DVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  int *extraout_ECX;
  undefined4 *puVar12;
  int iVar13;
  int unaff_EBP;
  short sVar14;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar15;
  
  FUN_0049bcd8();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  uVar5 = *(uint *)(unaff_EBP + 8);
  if (uVar5 == 0x111) {
    iVar4 = (**(code **)(*extraout_ECX + 0x80))
                      (*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
    if (iVar4 != 0) {
LAB_004adb2b:
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      goto switchD_004ad8a4_caseD_26;
    }
LAB_004ad859:
    uVar15 = 0;
    goto LAB_004ad85b;
  }
  if (uVar5 == 0x4e) {
    if (**(int **)(unaff_EBP + 0x10) != 0) {
      iVar4 = (**(code **)(*extraout_ECX + 0x84))
                        (*(undefined4 *)(unaff_EBP + 0xc),*(int **)(unaff_EBP + 0x10),
                         unaff_EBP + -0x10);
LAB_004adb4f:
      if (iVar4 != 0) goto switchD_004ad8a4_caseD_26;
    }
    goto LAB_004ad859;
  }
  puVar10 = *(undefined4 **)(unaff_EBP + 0x10);
  if (uVar5 == 6) {
    uVar15 = FUN_004ac7ac(puVar10);
    FUN_004ac9da(extraout_ECX,*(undefined4 *)(unaff_EBP + 0xc),uVar15);
  }
  sVar14 = (short)puVar10;
  if ((uVar5 == 0x20) &&
     (iVar4 = FUN_004aca3b(extraout_ECX,(int)sVar14,(uint)puVar10 >> 0x10), iVar4 != 0))
  goto LAB_004adb2b;
  uVar15 = (**(code **)(*extraout_ECX + 0x30))();
  *(undefined4 *)(unaff_EBP + -0x14) = uVar15;
  FUN_004c088f(7);
  uVar11 = *(uint *)(unaff_EBP + 8);
  uVar5 = uVar5 & 0x1ff ^ *(uint *)(unaff_EBP + -0x14) & 0x1ff;
  iVar4 = uVar5 * 0xc;
  iVar6 = *(int *)(unaff_EBP + -0x14);
  if ((uVar11 != *(uint *)(&DAT_005365b8 + uVar5 * 0xc)) ||
     (iVar6 != *(int *)(&DAT_005365c0 + iVar4))) {
    *(uint *)(&DAT_005365b8 + iVar4) = uVar11;
    *(int *)(&DAT_005365c0 + iVar4) = iVar6;
    if (iVar6 != 0) {
      while( true ) {
        if (uVar11 < 0xc000) {
          pAVar7 = AfxFindMessageEntry(*(AFX_MSGMAP_ENTRY **)(iVar6 + 4),uVar11,0,0);
          *(AFX_MSGMAP_ENTRY **)(unaff_EBP + 0x10) = pAVar7;
          if (pAVar7 != (AFX_MSGMAP_ENTRY *)0x0) {
            *(AFX_MSGMAP_ENTRY **)(&DAT_005365bc + iVar4) = pAVar7;
            FUN_004c08ff(7);
            iVar4 = *(int *)(unaff_EBP + 0x10);
            goto LAB_004ad879;
          }
        }
        else {
          pAVar7 = AfxFindMessageEntry(*(AFX_MSGMAP_ENTRY **)(iVar6 + 4),0xc000,0,0);
          *(AFX_MSGMAP_ENTRY **)(unaff_EBP + 0x10) = pAVar7;
          if (pAVar7 != (AFX_MSGMAP_ENTRY *)0x0) {
            while( true ) {
              if (**(int **)(pAVar7 + 0x10) == *(int *)(unaff_EBP + 8)) {
                *(AFX_MSGMAP_ENTRY **)(&DAT_005365bc + iVar4) = pAVar7;
                FUN_004c08ff(7);
                iVar4 = *(int *)(unaff_EBP + 0x10);
                goto LAB_004adb65;
              }
              pAVar7 = AfxFindMessageEntry(pAVar7 + 0x18,0xc000,0,0);
              *(AFX_MSGMAP_ENTRY **)(unaff_EBP + 0x10) = pAVar7;
              if (pAVar7 == (AFX_MSGMAP_ENTRY *)0x0) break;
              pAVar7 = *(AFX_MSGMAP_ENTRY **)(unaff_EBP + 0x10);
            }
          }
        }
        iVar6 = **(int **)(unaff_EBP + -0x14);
        *(int *)(unaff_EBP + -0x14) = iVar6;
        if (iVar6 == 0) break;
        uVar11 = *(uint *)(unaff_EBP + 8);
        iVar6 = *(int *)(unaff_EBP + -0x14);
      }
    }
    *(undefined4 *)(&DAT_005365bc + iVar4) = 0;
    FUN_004c08ff(7);
    goto LAB_004ad859;
  }
  iVar4 = *(int *)(&DAT_005365bc + iVar4);
  *(int *)(unaff_EBP + 0x10) = iVar4;
  FUN_004c08ff(7);
  if (iVar4 == 0) goto LAB_004ad859;
  if (0xbfff < *(uint *)(unaff_EBP + 8)) {
LAB_004adb65:
    uVar15 = (**(code **)(iVar4 + 0x14))(*(undefined4 *)(unaff_EBP + 0xc),puVar10);
    goto LAB_004adb6e;
  }
LAB_004ad879:
  iVar6 = *(int *)(unaff_EBP + 0x10);
  pcVar1 = *(code **)(iVar4 + 0x14);
  iVar4 = *(int *)(iVar6 + 0x10);
  if (*(int *)(iVar6 + 8) == 0x1a) {
    DVar8 = GetVersion();
    iVar6 = *(int *)(unaff_EBP + 0x10);
    iVar4 = (-(uint)((byte)DVar8 < 4) & 0xfffffff0) + 0x2f;
  }
  sVar3 = (short)((uint)puVar10 >> 0x10);
  switch(iVar4) {
  case 1:
    puVar10 = (undefined4 *)FUN_004b4794(*(undefined4 *)(unaff_EBP + 0xc));
    goto LAB_004ad9af;
  case 2:
    puVar10 = *(undefined4 **)(unaff_EBP + 0xc);
    goto LAB_004ad9af;
  case 3:
  case 8:
    uVar5 = (uint)puVar10 >> 0x10;
    uVar11 = (uint)sVar14;
    uVar9 = FUN_004ac7ac(*(undefined4 *)(unaff_EBP + 0xc));
    goto LAB_004ad9ca;
  case 4:
    FUN_004b46e0();
    uVar15 = puVar10[1];
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = uVar15;
    FUN_004ac443();
    uVar15 = *puVar10;
    uVar2 = puVar10[2];
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined4 *)(unaff_EBP + -0x44) = uVar15;
    iVar4 = FUN_004ac7d4(uVar15);
    if (iVar4 == 0) {
      if ((extraout_ECX[0xd] != 0) &&
         (iVar4 = FUN_004ab70b(*(undefined4 *)(unaff_EBP + -0x44)), iVar4 != 0)) {
        *(int *)(unaff_EBP + -0x28) = iVar4;
      }
      iVar4 = unaff_EBP + -0x60;
    }
    uVar15 = (*pcVar1)(unaff_EBP + -0x24,iVar4,uVar2);
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x44) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = uVar15;
    CWnd::~CWnd((CWnd *)(unaff_EBP + -0x60));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    goto LAB_004ad971;
  case 5:
    FUN_004b46e0();
    uVar15 = puVar10[2];
    *(undefined4 *)(unaff_EBP + -0x20) = puVar10[1];
    *(undefined4 *)(unaff_EBP + -4) = 2;
    uVar15 = (*pcVar1)(unaff_EBP + -0x24,uVar15);
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x10) = uVar15;
LAB_004ad971:
    FUN_004b4812();
    goto switchD_004ad8a4_caseD_26;
  case 6:
    uVar5 = *(uint *)(unaff_EBP + 0xc) >> 0x10;
    uVar11 = FUN_004ac7ac(puVar10);
    goto LAB_004ad9c5;
  case 7:
    puVar10 = (undefined4 *)(*(uint *)(unaff_EBP + 0xc) >> 0x10);
    uVar5 = (uint)*(ushort *)(unaff_EBP + 0xc);
    goto LAB_004adae0;
  case 9:
  case 0x2a:
LAB_004ad9af:
    uVar15 = (*pcVar1)(puVar10);
    goto LAB_004adb6e;
  case 10:
  case 0x21:
    uVar5 = *(uint *)(unaff_EBP + 0xc);
    goto LAB_004adae0;
  case 0xb:
    uVar5 = FUN_004b1ec9(puVar10);
    uVar11 = *(uint *)(unaff_EBP + 0xc) >> 0x10;
LAB_004ad9c5:
    uVar9 = (uint)*(ushort *)(unaff_EBP + 0xc);
LAB_004ad9ca:
    uVar15 = (*pcVar1)(uVar9,uVar11,uVar5);
    goto LAB_004adb6e;
  case 0xc:
    (*pcVar1)();
    goto switchD_004ad8a4_caseD_26;
  case 0xd:
    puVar10 = *(undefined4 **)(unaff_EBP + 0xc);
    break;
  case 0xe:
  case 0x12:
  case 0x25:
  case 0x2f:
    goto LAB_004adaf0;
  case 0xf:
    puVar12 = (undefined4 *)(int)sVar3;
    iVar13 = (int)sVar14;
    goto LAB_004adaf3;
  case 0x10:
  case 0x11:
    puVar12 = (undefined4 *)((uint)puVar10 >> 0x10);
    uVar5 = (uint)puVar10 & 0xffff;
    goto LAB_004adb19;
  case 0x13:
    puVar12 = (undefined4 *)FUN_004ac7ac(*(undefined4 *)(unaff_EBP + 0xc));
    uVar5 = FUN_004ac7ac(puVar10);
    uVar11 = (uint)((undefined4 *)extraout_ECX[7] == puVar10);
    goto LAB_004adb1d;
  case 0x14:
    puVar10 = (undefined4 *)FUN_004b4794(*(undefined4 *)(unaff_EBP + 0xc));
    break;
  case 0x15:
    puVar10 = (undefined4 *)FUN_004b1ec9(*(undefined4 *)(unaff_EBP + 0xc));
    break;
  case 0x16:
    puVar12 = (undefined4 *)((uint)puVar10 >> 0x10);
    uVar5 = (uint)puVar10 & 0xffff;
    uVar11 = FUN_004b1ec9(*(undefined4 *)(unaff_EBP + 0xc));
    goto LAB_004adb1d;
  case 0x17:
    puVar10 = *(undefined4 **)(unaff_EBP + 0xc);
    goto LAB_004ada52;
  case 0x18:
    puVar12 = (undefined4 *)((uint)puVar10 >> 0x10);
    uVar5 = (uint)puVar10 & 0xffff;
    goto LAB_004ada72;
  case 0x19:
    uVar5 = (uint)sVar14;
    puVar12 = (undefined4 *)(int)sVar3;
LAB_004ada72:
    uVar11 = FUN_004ac7ac(*(undefined4 *)(unaff_EBP + 0xc));
    goto LAB_004adb1d;
  case 0x1a:
    iVar13 = FUN_004ac7ac(*(undefined4 *)(unaff_EBP + 0xc));
    puVar12 = puVar10;
    goto LAB_004adaf3;
  case 0x1b:
    puVar10 = (undefined4 *)FUN_004ac7ac(puVar10);
LAB_004adaf0:
    iVar13 = *(int *)(unaff_EBP + 0xc);
    puVar12 = puVar10;
    goto LAB_004adaf3;
  case 0x1c:
    puVar12 = (undefined4 *)(*(uint *)(unaff_EBP + 0xc) >> 0x10);
    uVar5 = FUN_004ac7ac(puVar10);
    goto LAB_004adb07;
  case 0x1d:
  case 0x1e:
    iVar13 = (int)(short)*(undefined4 *)(unaff_EBP + 0xc);
    iVar4 = *(int *)(iVar6 + 0x10);
    *(int *)(unaff_EBP + 8) = iVar13;
    puVar12 = (undefined4 *)(int)(short)((uint)*(undefined4 *)(unaff_EBP + 0xc) >> 0x10);
    *(undefined4 **)(unaff_EBP + 0xc) = puVar12;
    if (iVar4 == 0x1d) {
      puVar12 = (undefined4 *)FUN_004ac7ac(puVar10);
      uVar5 = *(uint *)(unaff_EBP + 0xc);
      uVar11 = *(uint *)(unaff_EBP + 8);
      goto LAB_004adb1d;
    }
LAB_004adaf3:
    (*pcVar1)(iVar13,puVar12);
    goto switchD_004ad8a4_caseD_26;
  case 0x1f:
  case 0x24:
    break;
  case 0x20:
  case 0x2b:
    (*pcVar1)(*(undefined4 *)(unaff_EBP + 0xc),puVar10);
    goto LAB_004adb2b;
  case 0x22:
    uVar5 = (uint)sVar14;
    puVar10 = (undefined4 *)(int)sVar3;
    goto LAB_004adae0;
  case 0x23:
    uVar15 = (*pcVar1)();
    goto LAB_004adb6e;
  default:
    goto switchD_004ad8a4_caseD_26;
  case 0x2c:
LAB_004ada52:
    puVar10 = (undefined4 *)FUN_004ac7ac(puVar10);
    break;
  case 0x2d:
    uVar5 = FUN_004ac7ac(puVar10);
LAB_004adae0:
    uVar15 = (*pcVar1)(uVar5,puVar10);
LAB_004adb6e:
    *(undefined4 *)(unaff_EBP + -0x10) = uVar15;
    goto switchD_004ad8a4_caseD_26;
  case 0x2e:
    iVar4 = (*pcVar1)(*(undefined2 *)(unaff_EBP + 0xc),*(uint *)(unaff_EBP + 0xc) >> 0x10,
                      (uint)puVar10 & 0xffff,(uint)puVar10 >> 0x10);
    *(int *)(unaff_EBP + -0x10) = iVar4;
    goto LAB_004adb4f;
  case 0x30:
    uVar5 = *(uint *)(unaff_EBP + 0xc) >> 0x10;
    puVar12 = puVar10;
LAB_004adb07:
    uVar11 = (uint)*(ushort *)(unaff_EBP + 0xc);
    goto LAB_004adb1d;
  case 0x31:
    uVar5 = (uint)sVar14;
    puVar12 = (undefined4 *)(int)sVar3;
LAB_004adb19:
    uVar11 = *(uint *)(unaff_EBP + 0xc);
LAB_004adb1d:
    (*pcVar1)(uVar11,uVar5,puVar12);
    goto switchD_004ad8a4_caseD_26;
  }
  (*pcVar1)(puVar10);
switchD_004ad8a4_caseD_26:
  if (*(undefined4 **)(unaff_EBP + 0x14) != (undefined4 *)0x0) {
    **(undefined4 **)(unaff_EBP + 0x14) = *(undefined4 *)(unaff_EBP + -0x10);
  }
  uVar15 = 1;
LAB_004ad85b:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar15;
}

