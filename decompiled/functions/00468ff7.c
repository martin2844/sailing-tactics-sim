
/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 FUN_00468ff7(void)

{
  code *pcVar1;
  short sVar2;
  int iVar3;
  CWnd *pCVar4;
  uint uVar5;
  int iVar6;
  AFX_MSGMAP_ENTRY *pAVar7;
  DWORD DVar8;
  CWnd *pCVar9;
  int *extraout_ECX;
  uint uVar10;
  CWnd *pCVar11;
  int unaff_EBP;
  short sVar12;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar13;
  
  FUN_00457418();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  uVar5 = *(uint *)(unaff_EBP + 8);
  if (uVar5 == 0x111) {
    iVar3 = (**(code **)(*extraout_ECX + 0x80))
                      (*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
    if (iVar3 != 0) {
LAB_0046944b:
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      goto switchD_004691c4_caseD_26;
    }
LAB_00469179:
    uVar13 = 0;
    goto LAB_0046917b;
  }
  if (uVar5 == 0x4e) {
    if (**(int **)(unaff_EBP + 0x10) != 0) {
      iVar3 = (**(code **)(*extraout_ECX + 0x84))
                        (*(undefined4 *)(unaff_EBP + 0xc),*(int **)(unaff_EBP + 0x10),
                         unaff_EBP + -0x10);
LAB_0046946f:
      if (iVar3 != 0) goto switchD_004691c4_caseD_26;
    }
    goto LAB_00469179;
  }
  pCVar9 = *(CWnd **)(unaff_EBP + 0x10);
  if (uVar5 == 6) {
    pCVar4 = FUN_004680cc();
    FUN_004682fa((int)extraout_ECX,*(WPARAM *)(unaff_EBP + 0xc),(int)pCVar4);
  }
  sVar12 = (short)pCVar9;
  if ((uVar5 == 0x20) &&
     (iVar3 = FUN_0046835b((int)extraout_ECX,(int)sVar12,(uint)pCVar9 >> 0x10), iVar3 != 0))
  goto LAB_0046944b;
  uVar13 = (**(code **)(*extraout_ECX + 0x30))();
  *(undefined4 *)(unaff_EBP + -0x14) = uVar13;
  FUN_0047c1af(7);
  uVar10 = *(uint *)(unaff_EBP + 8);
  uVar5 = uVar5 & 0x1ff ^ *(uint *)(unaff_EBP + -0x14) & 0x1ff;
  iVar3 = uVar5 * 0xc;
  iVar6 = *(int *)(unaff_EBP + -0x14);
  if ((uVar10 != *(uint *)(&DAT_004aca60 + uVar5 * 0xc)) ||
     (iVar6 != *(int *)(&DAT_004aca68 + iVar3))) {
    *(uint *)(&DAT_004aca60 + iVar3) = uVar10;
    *(int *)(&DAT_004aca68 + iVar3) = iVar6;
    if (iVar6 != 0) {
      while( true ) {
        if (uVar10 < 0xc000) {
          pAVar7 = AfxFindMessageEntry(*(AFX_MSGMAP_ENTRY **)(iVar6 + 4),uVar10,0,0);
          *(AFX_MSGMAP_ENTRY **)(unaff_EBP + 0x10) = pAVar7;
          if (pAVar7 != (AFX_MSGMAP_ENTRY *)0x0) {
            *(AFX_MSGMAP_ENTRY **)(&DAT_004aca64 + iVar3) = pAVar7;
            FUN_0047c21f(7);
            iVar3 = *(int *)(unaff_EBP + 0x10);
            goto LAB_00469199;
          }
        }
        else {
          pAVar7 = AfxFindMessageEntry(*(AFX_MSGMAP_ENTRY **)(iVar6 + 4),0xc000,0,0);
          *(AFX_MSGMAP_ENTRY **)(unaff_EBP + 0x10) = pAVar7;
          if (pAVar7 != (AFX_MSGMAP_ENTRY *)0x0) {
            while( true ) {
              if (**(int **)(pAVar7 + 0x10) == *(int *)(unaff_EBP + 8)) {
                *(AFX_MSGMAP_ENTRY **)(&DAT_004aca64 + iVar3) = pAVar7;
                FUN_0047c21f(7);
                iVar3 = *(int *)(unaff_EBP + 0x10);
                goto LAB_00469485;
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
        uVar10 = *(uint *)(unaff_EBP + 8);
        iVar6 = *(int *)(unaff_EBP + -0x14);
      }
    }
    *(undefined4 *)(&DAT_004aca64 + iVar3) = 0;
    FUN_0047c21f(7);
    goto LAB_00469179;
  }
  iVar3 = *(int *)(&DAT_004aca64 + iVar3);
  *(int *)(unaff_EBP + 0x10) = iVar3;
  FUN_0047c21f(7);
  if (iVar3 == 0) goto LAB_00469179;
  if (0xbfff < *(uint *)(unaff_EBP + 8)) {
LAB_00469485:
    uVar13 = (**(code **)(iVar3 + 0x14))(*(undefined4 *)(unaff_EBP + 0xc),pCVar9);
    goto LAB_0046948e;
  }
LAB_00469199:
  iVar6 = *(int *)(unaff_EBP + 0x10);
  pcVar1 = *(code **)(iVar3 + 0x14);
  iVar3 = *(int *)(iVar6 + 0x10);
  if (*(int *)(iVar6 + 8) == 0x1a) {
    DVar8 = GetVersion();
    iVar6 = *(int *)(unaff_EBP + 0x10);
    iVar3 = (-(uint)((byte)DVar8 < 4) & 0xfffffff0) + 0x2f;
  }
  sVar2 = (short)((uint)pCVar9 >> 0x10);
  switch(iVar3) {
  case 1:
    pCVar9 = (CWnd *)FUN_004700b4();
    goto LAB_004692cf;
  case 2:
    pCVar9 = *(CWnd **)(unaff_EBP + 0xc);
    goto LAB_004692cf;
  case 3:
  case 8:
    uVar5 = (uint)pCVar9 >> 0x10;
    pCVar9 = (CWnd *)(int)sVar12;
    pCVar4 = FUN_004680cc();
    goto LAB_004692ea;
  case 4:
    FUN_00470000((undefined4 *)(unaff_EBP + -0x24));
    uVar5 = *(uint *)(pCVar9 + 4);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(uint *)(unaff_EBP + -0x20) = uVar5;
    FUN_00467d63((undefined4 *)(unaff_EBP + -0x60));
    uVar5 = *(uint *)pCVar9;
    uVar10 = *(uint *)(pCVar9 + 8);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(uint *)(unaff_EBP + -0x44) = uVar5;
    iVar3 = FUN_004680f4(uVar5);
    if (iVar3 == 0) {
      if ((extraout_ECX[0xd] != 0) &&
         (iVar3 = FUN_0046702b((void *)(extraout_ECX[0xd] + 0x20),*(uint *)(unaff_EBP + -0x44)),
         iVar3 != 0)) {
        *(int *)(unaff_EBP + -0x28) = iVar3;
      }
      iVar3 = unaff_EBP + -0x60;
    }
    uVar13 = (*pcVar1)(unaff_EBP + -0x24,iVar3,uVar10);
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x44) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = uVar13;
    CWnd::~CWnd((CWnd *)(unaff_EBP + -0x60));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    goto LAB_00469291;
  case 5:
    FUN_00470000((undefined4 *)(unaff_EBP + -0x24));
    uVar5 = *(uint *)(pCVar9 + 8);
    *(uint *)(unaff_EBP + -0x20) = *(uint *)(pCVar9 + 4);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    uVar13 = (*pcVar1)(unaff_EBP + -0x24,uVar5);
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x10) = uVar13;
LAB_00469291:
    FUN_00470132();
    goto switchD_004691c4_caseD_26;
  case 6:
    uVar5 = *(uint *)(unaff_EBP + 0xc) >> 0x10;
    pCVar9 = FUN_004680cc();
    goto LAB_004692e5;
  case 7:
    pCVar9 = (CWnd *)(*(uint *)(unaff_EBP + 0xc) >> 0x10);
    pCVar4 = (CWnd *)(uint)*(ushort *)(unaff_EBP + 0xc);
    goto LAB_00469400;
  case 9:
  case 0x2a:
LAB_004692cf:
    uVar13 = (*pcVar1)(pCVar9);
    goto LAB_0046948e;
  case 10:
  case 0x21:
    pCVar4 = *(CWnd **)(unaff_EBP + 0xc);
    goto LAB_00469400;
  case 0xb:
    uVar5 = FUN_0046d7e9();
    pCVar9 = (CWnd *)(*(uint *)(unaff_EBP + 0xc) >> 0x10);
LAB_004692e5:
    pCVar4 = (CWnd *)(uint)*(ushort *)(unaff_EBP + 0xc);
LAB_004692ea:
    uVar13 = (*pcVar1)(pCVar4,pCVar9,uVar5);
    goto LAB_0046948e;
  case 0xc:
    (*pcVar1)();
    goto switchD_004691c4_caseD_26;
  case 0xd:
    pCVar9 = *(CWnd **)(unaff_EBP + 0xc);
    break;
  case 0xe:
  case 0x12:
  case 0x25:
  case 0x2f:
    goto LAB_00469410;
  case 0xf:
    pCVar9 = (CWnd *)(int)sVar2;
    pCVar4 = (CWnd *)(int)sVar12;
    goto LAB_00469413;
  case 0x10:
  case 0x11:
    pCVar11 = (CWnd *)((uint)pCVar9 >> 0x10);
    pCVar4 = (CWnd *)((uint)pCVar9 & 0xffff);
    goto LAB_00469439;
  case 0x13:
    pCVar11 = FUN_004680cc();
    pCVar4 = FUN_004680cc();
    pCVar9 = (CWnd *)(uint)((CWnd *)extraout_ECX[7] == pCVar9);
    goto LAB_0046943d;
  case 0x14:
    pCVar9 = (CWnd *)FUN_004700b4();
    break;
  case 0x15:
    pCVar9 = (CWnd *)FUN_0046d7e9();
    break;
  case 0x16:
    pCVar11 = (CWnd *)((uint)pCVar9 >> 0x10);
    pCVar4 = (CWnd *)((uint)pCVar9 & 0xffff);
    pCVar9 = (CWnd *)FUN_0046d7e9();
    goto LAB_0046943d;
  case 0x17:
    goto LAB_00469372;
  case 0x18:
    pCVar11 = (CWnd *)((uint)pCVar9 >> 0x10);
    pCVar4 = (CWnd *)((uint)pCVar9 & 0xffff);
    goto LAB_00469392;
  case 0x19:
    pCVar4 = (CWnd *)(int)sVar12;
    pCVar11 = (CWnd *)(int)sVar2;
LAB_00469392:
    pCVar9 = FUN_004680cc();
    goto LAB_0046943d;
  case 0x1a:
    pCVar4 = FUN_004680cc();
    goto LAB_00469413;
  case 0x1b:
    pCVar9 = FUN_004680cc();
LAB_00469410:
    pCVar4 = *(CWnd **)(unaff_EBP + 0xc);
    goto LAB_00469413;
  case 0x1c:
    pCVar11 = (CWnd *)(*(uint *)(unaff_EBP + 0xc) >> 0x10);
    pCVar4 = FUN_004680cc();
    goto LAB_00469427;
  case 0x1d:
  case 0x1e:
    pCVar4 = (CWnd *)(int)(short)*(undefined4 *)(unaff_EBP + 0xc);
    iVar3 = *(int *)(iVar6 + 0x10);
    *(CWnd **)(unaff_EBP + 8) = pCVar4;
    pCVar9 = (CWnd *)(int)(short)((uint)*(undefined4 *)(unaff_EBP + 0xc) >> 0x10);
    *(CWnd **)(unaff_EBP + 0xc) = pCVar9;
    if (iVar3 == 0x1d) {
      pCVar11 = FUN_004680cc();
      pCVar4 = *(CWnd **)(unaff_EBP + 0xc);
      pCVar9 = *(CWnd **)(unaff_EBP + 8);
      goto LAB_0046943d;
    }
LAB_00469413:
    (*pcVar1)(pCVar4,pCVar9);
    goto switchD_004691c4_caseD_26;
  case 0x1f:
  case 0x24:
    break;
  case 0x20:
  case 0x2b:
    (*pcVar1)(*(undefined4 *)(unaff_EBP + 0xc),pCVar9);
    goto LAB_0046944b;
  case 0x22:
    pCVar4 = (CWnd *)(int)sVar12;
    pCVar9 = (CWnd *)(int)sVar2;
    goto LAB_00469400;
  case 0x23:
    uVar13 = (*pcVar1)();
    goto LAB_0046948e;
  default:
    goto switchD_004691c4_caseD_26;
  case 0x2c:
LAB_00469372:
    pCVar9 = FUN_004680cc();
    break;
  case 0x2d:
    pCVar4 = FUN_004680cc();
LAB_00469400:
    uVar13 = (*pcVar1)(pCVar4,pCVar9);
LAB_0046948e:
    *(undefined4 *)(unaff_EBP + -0x10) = uVar13;
    goto switchD_004691c4_caseD_26;
  case 0x2e:
    iVar3 = (*pcVar1)(*(undefined2 *)(unaff_EBP + 0xc),*(uint *)(unaff_EBP + 0xc) >> 0x10,
                      (uint)pCVar9 & 0xffff,(uint)pCVar9 >> 0x10);
    *(int *)(unaff_EBP + -0x10) = iVar3;
    goto LAB_0046946f;
  case 0x30:
    pCVar4 = (CWnd *)(*(uint *)(unaff_EBP + 0xc) >> 0x10);
    pCVar11 = pCVar9;
LAB_00469427:
    pCVar9 = (CWnd *)(uint)*(ushort *)(unaff_EBP + 0xc);
    goto LAB_0046943d;
  case 0x31:
    pCVar4 = (CWnd *)(int)sVar12;
    pCVar11 = (CWnd *)(int)sVar2;
LAB_00469439:
    pCVar9 = *(CWnd **)(unaff_EBP + 0xc);
LAB_0046943d:
    (*pcVar1)(pCVar9,pCVar4,pCVar11);
    goto switchD_004691c4_caseD_26;
  }
  (*pcVar1)(pCVar9);
switchD_004691c4_caseD_26:
  if (*(undefined4 **)(unaff_EBP + 0x14) != (undefined4 *)0x0) {
    **(undefined4 **)(unaff_EBP + 0x14) = *(undefined4 *)(unaff_EBP + -0x10);
  }
  uVar13 = 1;
LAB_0046917b:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar13;
}

