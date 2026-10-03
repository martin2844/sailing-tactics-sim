
void FUN_004b2385(void)

{
  byte bVar1;
  int *piVar2;
  UINT_PTR uIDNewItem;
  LPCSTR lpNewItem;
  HMENU hMenu;
  LPSTR lpString;
  byte *pbVar3;
  Tact2010CString *pTVar4;
  int extraout_ECX;
  byte *pbVar5;
  int iVar6;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  int iVar7;
  UINT UVar8;
  
  FUN_0049bcd8();
  piVar2 = *(int **)(unaff_EBP + 8);
  iVar7 = *(int *)(extraout_ECX + 0x1c);
  iVar6 = piVar2[3];
  *(int *)(unaff_EBP + -0x18) = iVar6;
  if ((*(int *)(iVar7 + -8) == 0) && (iVar6 != 0)) {
    UVar8 = 0;
    *(int *)(unaff_EBP + 8) = piVar2[1];
    iVar7 = 0x100;
    lpString = (LPSTR)FUN_004b0956(0x100);
    GetMenuStringA(*(HMENU *)(*(int *)(unaff_EBP + -0x18) + 4),*(UINT *)(unaff_EBP + 8),lpString,
                   iVar7,UVar8);
    FUN_004b09a5(0xffffffff);
  }
  if (*(int *)(**(int **)(extraout_ECX + 8) + -8) == 0) {
    if (*(int *)(*(int *)(extraout_ECX + 0x1c) + -8) != 0) {
      (**(code **)(*piVar2 + 0xc))(*(int *)(extraout_ECX + 0x1c));
    }
    (**(code **)*piVar2)(0);
  }
  else if (piVar2[3] != 0) {
    iVar7 = 0;
    if (0 < *(int *)(extraout_ECX + 4)) {
      do {
        DeleteMenu(*(HMENU *)(piVar2[3] + 4),iVar7 + piVar2[1],0);
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(extraout_ECX + 4));
    }
    GetCurrentDirectoryA(0x104,(LPSTR)(unaff_EBP + -0x130));
    iVar7 = lstrlenA((LPCSTR)(unaff_EBP + -0x130));
    *(undefined1 *)(unaff_EBP + -0x130 + iVar7) = 0x5c;
    *(undefined1 *)(unaff_EBP + -0x12f + iVar7) = 0;
    *(int *)(unaff_EBP + -0x18) = iVar7 + 1;
    FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x14));
    iVar6 = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004b045a((Tact2010CString *)(unaff_EBP + -0x10));
    iVar7 = *(int *)(extraout_ECX + 4);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (0 < iVar7) {
      do {
        iVar7 = FUN_004b227c(unaff_EBP + -0x14,iVar6,unaff_EBP + -0x130,
                             *(undefined4 *)(unaff_EBP + -0x18),1);
        if (iVar7 == 0) break;
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + -0x14);
        pbVar3 = (byte *)FUN_004b0956(*(int *)(*(int *)(unaff_EBP + -0x14) + -8) << 1);
        for (pbVar5 = *(byte **)(unaff_EBP + 8); *pbVar5 != 0; pbVar5 = pbVar5 + 1) {
          if (*pbVar5 == 0x26) {
            *pbVar3 = 0x26;
            pbVar3 = pbVar3 + 1;
          }
          bVar1 = *pbVar5;
          *(byte *)(unaff_EBP + 8) = bVar1;
          if ((*(byte *)((int)&DAT_005384c0 + bVar1 + 1) & 4) != 0) {
            *pbVar3 = *(byte *)(unaff_EBP + 8);
            pbVar3 = pbVar3 + 1;
            pbVar5 = pbVar5 + 1;
          }
          *pbVar3 = *pbVar5;
          pbVar3 = pbVar3 + 1;
        }
        *pbVar3 = 0;
        FUN_004b09a5(0xffffffff);
        wsprintfA((LPSTR)(unaff_EBP + -0x2c),"&%d ",
                  (uint)(*(int *)(extraout_ECX + 0x14) + 1 + iVar6) % 10);
        pTVar4 = FUN_004b0613((Tact2010CString *)(unaff_EBP + -0x20),(char *)(unaff_EBP + -0x2c));
        *(undefined1 *)(unaff_EBP + -4) = 2;
        pTVar4 = FUN_004b0755((Tact2010CString *)(unaff_EBP + -0x1c),pTVar4,
                              (Tact2010CString *)(unaff_EBP + -0x10));
        UVar8 = piVar2[2];
        *(char **)(unaff_EBP + 8) = pTVar4->data;
        uIDNewItem = piVar2[1];
        lpNewItem = *(LPCSTR *)(unaff_EBP + 8);
        piVar2[2] = UVar8 + 1;
        piVar2[1] = uIDNewItem + 1;
        hMenu = *(HMENU *)(piVar2[3] + 4);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        InsertMenuA(hMenu,UVar8,0x400,uIDNewItem,lpNewItem);
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x1c));
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x20));
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(extraout_ECX + 4));
    }
    piVar2[2] = piVar2[2] + -1;
    iVar7 = GetMenuItemCount(*(HMENU *)(piVar2[3] + 4));
    *(undefined1 *)(unaff_EBP + -4) = 0;
    piVar2[8] = iVar7;
    piVar2[6] = 1;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x10));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)(unaff_EBP + -0x14));
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

