
void FUN_004bdb5f(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  DWORD DVar4;
  HBRUSH pHVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  HGDIOBJ pvVar9;
  HDC pHVar10;
  int extraout_ECX;
  int unaff_EBP;
  int iVar11;
  undefined4 *unaff_FS_OFFSET;
  bool bVar12;
  
  FUN_0049bcd8();
  bVar12 = DAT_005381f4 != 0;
  *(int *)(unaff_EBP + -0x5c) = extraout_ECX;
  if (bVar12) {
    FUN_004ac701();
    goto LAB_004be0c7;
  }
  FUN_004b4f06(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = FUN_004af3eb();
  *(undefined4 *)(unaff_EBP + -0x34) = uVar3;
  GetWindowRect(*(HWND *)(extraout_ECX + 0x1c),(LPRECT)(unaff_EBP + -0x28));
  OffsetRect((LPRECT)(unaff_EBP + -0x28),-*(int *)(unaff_EBP + -0x28),-*(int *)(unaff_EBP + -0x24));
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined ***)(unaff_EBP + -0x30) = &PTR_FUN_004ceedc;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  DVar4 = GetSysColor(6);
  pHVar5 = CreateSolidBrush(DVar4);
  FUN_004b510d(pHVar5);
  *(undefined4 *)(unaff_EBP + -0x54) = 0;
  *(undefined ***)(unaff_EBP + -0x58) = &PTR_FUN_004ceedc;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  DVar4 = GetSysColor(0xb - (uint)(*(int *)(*(int *)(unaff_EBP + -0x5c) + 0xc4) != 0));
  pHVar5 = CreateSolidBrush(DVar4);
  FUN_004b510d(pHVar5);
  *(undefined4 *)(unaff_EBP + -0x4c) = 0;
  *(undefined ***)(unaff_EBP + -0x50) = &PTR_FUN_004ceedc;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  DVar4 = GetSysColor(3 - (uint)(*(int *)(*(int *)(unaff_EBP + -0x5c) + 0xc4) != 0));
  pHVar5 = CreateSolidBrush(DVar4);
  FUN_004b510d(pHVar5);
  iVar6 = GetSystemMetrics(6);
  *(int *)(unaff_EBP + -0x18) = iVar6;
  iVar6 = GetSystemMetrics(5);
  *(int *)(unaff_EBP + -0x10) = iVar6;
  iVar7 = GetSystemMetrics(0x21);
  *(int *)(unaff_EBP + -0x14) = iVar7;
  iVar7 = GetSystemMetrics(0x20);
  if ((*(uint *)(unaff_EBP + -0x34) & 0x40600) != 0) {
    FUN_004be0d6(unaff_EBP + -0x48,unaff_EBP + -0x28,iVar6,*(undefined4 *)(unaff_EBP + -0x18),
                 unaff_EBP + -0x30);
    InflateRect((LPRECT)(unaff_EBP + -0x28),-iVar6,-*(int *)(unaff_EBP + -0x18));
    FUN_004be0d6(unaff_EBP + -0x48,unaff_EBP + -0x28,iVar7 - iVar6,
                 *(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18),unaff_EBP + -0x58);
    iVar11 = iVar7 + iVar6 * -2;
    iVar8 = *(int *)(unaff_EBP + -0x14) + *(int *)(unaff_EBP + -0x18) * -2;
    *(int *)(unaff_EBP + -0x14) = iVar8;
    iVar6 = DAT_00538434;
    if ((*(byte *)(unaff_EBP + -0x33) & 2) == 0) {
      *(uint *)(unaff_EBP + -0x74) = iVar7 + *(int *)(unaff_EBP + -0x10) * -3 + DAT_00538430;
      iVar6 = iVar6 + iVar8;
      FUN_004bd1cb(*(undefined4 *)(unaff_EBP + -0x28),*(int *)(unaff_EBP + -0x24) + iVar6,iVar11,1,0
                  );
      FUN_004bd1cb(*(undefined4 *)(unaff_EBP + -0x28),*(int *)(unaff_EBP + -0x1c) - iVar6,iVar11,1,0
                  );
      FUN_004bd1cb(*(int *)(unaff_EBP + -0x20) - iVar11,*(int *)(unaff_EBP + -0x24) + iVar6,iVar11,1
                   ,0);
      FUN_004bd1cb(*(int *)(unaff_EBP + -0x20) - iVar11,*(int *)(unaff_EBP + -0x1c) - iVar6,iVar11,1
                   ,0);
      iVar6 = *(int *)(unaff_EBP + -0x74);
      FUN_004bd1cb(*(int *)(unaff_EBP + -0x28) + iVar6,*(undefined4 *)(unaff_EBP + -0x24),1,
                   *(undefined4 *)(unaff_EBP + -0x14),0);
      FUN_004bd1cb(*(int *)(unaff_EBP + -0x20) - iVar6,*(undefined4 *)(unaff_EBP + -0x24),1,
                   *(undefined4 *)(unaff_EBP + -0x14),0);
      FUN_004bd1cb(*(int *)(unaff_EBP + -0x28) + iVar6,
                   *(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x14),1,
                   *(undefined4 *)(unaff_EBP + -0x14),0);
      FUN_004bd1cb(*(int *)(unaff_EBP + -0x20) - iVar6,
                   *(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x14),1,
                   *(undefined4 *)(unaff_EBP + -0x14),0);
      iVar8 = *(int *)(unaff_EBP + -0x14);
    }
    InflateRect((LPRECT)(unaff_EBP + -0x28),-iVar11,-iVar8);
    iVar6 = *(int *)(unaff_EBP + -0x10);
  }
  if ((*(byte *)(unaff_EBP + -0x32) & 0xc0) == 0) {
    FUN_004be0d6(unaff_EBP + -0x48,unaff_EBP + -0x28,iVar6,*(undefined4 *)(unaff_EBP + -0x18),
                 unaff_EBP + -0x30);
LAB_004be07b:
    *(undefined ***)(unaff_EBP + -0x50) = &PTR_FUN_004ceef4;
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_004b5164();
    *(undefined ***)(unaff_EBP + -0x58) = &PTR_FUN_004ceef4;
    *(undefined ***)(unaff_EBP + -0x50) = &PTR_FUN_004cd9a4;
    *(undefined1 *)(unaff_EBP + -4) = 10;
    FUN_004b5164();
    *(undefined ***)(unaff_EBP + -0x58) = &PTR_FUN_004cd9a4;
    *(undefined ***)(unaff_EBP + -0x30) = &PTR_FUN_004ceef4;
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x1c);
    iVar6 = *(int *)(unaff_EBP + -0x18);
    *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EBP + -0x24) + iVar6 + DAT_00538434;
    FUN_004be0d6(unaff_EBP + -0x48,unaff_EBP + -0x6c,*(undefined4 *)(unaff_EBP + -0x10),iVar6,
                 unaff_EBP + -0x30);
    InflateRect((LPRECT)(unaff_EBP + -0x6c),-*(int *)(unaff_EBP + -0x10),-iVar6);
    FillRect(*(HDC *)(unaff_EBP + -0x44),(RECT *)(unaff_EBP + -0x6c),
             (HBRUSH)(-(uint)(unaff_EBP != 0x50) & *(uint *)(unaff_EBP + -0x4c)));
    FUN_004be0d6(unaff_EBP + -0x48,unaff_EBP + -0x28,*(undefined4 *)(unaff_EBP + -0x10),iVar6,
                 unaff_EBP + -0x30);
    if (DAT_00538420 != (HGDIOBJ)0x0) {
      pvVar9 = SelectObject(*(HDC *)(unaff_EBP + -0x44),DAT_00538420);
      *(HGDIOBJ *)(unaff_EBP + -0x18) = pvVar9;
      FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_004ad1d5(unaff_EBP + -0x10);
      iVar6 = (-(uint)((*(uint *)(unaff_EBP + -0x34) & 0x80000) != 0) & DAT_00538430) +
              *(int *)(unaff_EBP + -0x6c);
      GetTextExtentPointA(*(HDC *)(unaff_EBP + -0x40),*(LPCSTR *)(unaff_EBP + -0x10),
                          *(int *)(*(LPCSTR *)(unaff_EBP + -0x10) + -8),(LPSIZE)(unaff_EBP + -0x74))
      ;
      if (*(int *)(unaff_EBP + -0x74) <= *(int *)(unaff_EBP + -100) - *(int *)(unaff_EBP + -0x6c)) {
        FUN_004b4e1e(6);
        iVar6 = iVar6 + (*(int *)(unaff_EBP + -100) - iVar6) / 2;
      }
      GetTextMetricsA(*(HDC *)(unaff_EBP + -0x40),(LPTEXTMETRICA)(unaff_EBP + -0xb4));
      iVar7 = *(int *)(unaff_EBP + -0xb0);
      iVar8 = *(int *)(unaff_EBP + -0xac);
      iVar11 = *(int *)(unaff_EBP + -0xa8);
      InflateRect((LPRECT)(unaff_EBP + -0x6c),0,1);
      iVar1 = *(int *)(unaff_EBP + -0x60);
      iVar2 = *(int *)(unaff_EBP + -0x68);
      DVar4 = GetSysColor((-(uint)(*(int *)(*(int *)(unaff_EBP + -0x5c) + 0xc4) != 0) & 0xfffffff6)
                          + 0x13);
      FUN_004b4a57((int *)(unaff_EBP + -0x48),DVar4);
      FUN_004b4a1f((int *)(unaff_EBP + -0x48),1);
      ExtTextOutA(*(HDC *)(unaff_EBP + -0x44),iVar6,
                  (((iVar1 - iVar2) - (iVar7 + iVar8 + iVar11)) + 1) / 2 +
                  *(int *)(unaff_EBP + -0x68),4,(RECT *)(unaff_EBP + -0x6c),
                  *(LPCSTR *)(unaff_EBP + -0x10),*(UINT *)(*(LPCSTR *)(unaff_EBP + -0x10) + -8),
                  (INT *)0x0);
      if (*(int *)(unaff_EBP + -0x18) != 0) {
        SelectObject(*(HDC *)(unaff_EBP + -0x44),*(HGDIOBJ *)(unaff_EBP + -0x18));
      }
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
    }
    if ((*(byte *)(unaff_EBP + -0x32) & 8) == 0) {
LAB_004be05b:
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x60);
      goto LAB_004be07b;
    }
    FUN_004b46e0();
    *(undefined1 *)(unaff_EBP + -4) = 5;
    pHVar10 = CreateCompatibleDC((HDC)(-(uint)(unaff_EBP != 0x48) & *(uint *)(unaff_EBP + -0x44)));
    iVar6 = FUN_004b47aa(pHVar10);
    if (iVar6 != 0) {
      if (DAT_00538424 == (HGDIOBJ)0x0) {
        pvVar9 = (HGDIOBJ)0x0;
      }
      else {
        pvVar9 = SelectObject(*(HDC *)(unaff_EBP + -0x78),DAT_00538424);
      }
      BitBlt(*(HDC *)(unaff_EBP + -0x44),*(int *)(unaff_EBP + -0x28),*(int *)(unaff_EBP + -0x24),
             DAT_00538430,DAT_00538434,
             (HDC)(-(uint)(unaff_EBP != 0x7c) & *(uint *)(unaff_EBP + -0x78)),0,0,0xcc0020);
      if (pvVar9 != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(unaff_EBP + -0x78),pvVar9);
      }
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_004b4812();
      goto LAB_004be05b;
    }
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_004b4812();
    *(undefined ***)(unaff_EBP + -0x50) = &PTR_FUN_004ceef4;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_004b5164();
    *(undefined ***)(unaff_EBP + -0x58) = &PTR_FUN_004ceef4;
    *(undefined ***)(unaff_EBP + -0x50) = &PTR_FUN_004cd9a4;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_004b5164();
    *(undefined ***)(unaff_EBP + -0x58) = &PTR_FUN_004cd9a4;
    *(undefined ***)(unaff_EBP + -0x30) = &PTR_FUN_004ceef4;
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_004b5164();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined ***)(unaff_EBP + -0x30) = &PTR_FUN_004cd9a4;
  FUN_004b4f78();
LAB_004be0c7:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

