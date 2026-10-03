
undefined4 FUN_004be9d5(void)

{
  int *piVar1;
  int iVar2;
  HGDIOBJ pvVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar6;
  int *piVar7;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  iVar2 = FUN_004beb0c(*(undefined4 *)(unaff_EBP + 0xc),0x14);
  uVar5 = 0;
  if (iVar2 != 0) {
    *(undefined4 *)(unaff_EBP + -0x18) = 1;
    if (*(int *)(unaff_EBP + 8) != 0) {
      pvVar3 = (HGDIOBJ)SendMessageA(*(HWND *)(extraout_ECX + 0x1c),0x31,0,0);
      FUN_004b4e52(0);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      if (pvVar3 != (HGDIOBJ)0x0) {
        pvVar3 = SelectObject(*(HDC *)(unaff_EBP + -0x34),pvVar3);
        *(HGDIOBJ *)(unaff_EBP + -0x14) = pvVar3;
      }
      piVar7 = *(int **)(extraout_ECX + 0x5c);
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      if (0 < *(int *)(unaff_EBP + 0xc)) {
        piVar6 = piVar7 + 4;
        do {
          piVar1 = *(int **)(unaff_EBP + 8);
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 4;
          iVar2 = *piVar1;
          piVar6[-1] = piVar6[-1] | 1;
          *piVar7 = iVar2;
          if (iVar2 != 0) {
            iVar2 = FUN_004b1f41(iVar2);
            if (iVar2 != 0) {
              GetTextExtentPointA(*(HDC *)(unaff_EBP + -0x30),(LPCSTR)*piVar6,
                                  *(int *)((LPCSTR)*piVar6 + -8),(LPSIZE)(unaff_EBP + -0x24));
              piVar6[-3] = *(int *)(unaff_EBP + -0x24);
              iVar2 = FUN_004b66c5(*(undefined4 *)(unaff_EBP + -0x10),*piVar6,0);
              if (iVar2 != 0) goto LAB_004beab7;
            }
            *(undefined4 *)(unaff_EBP + -0x18) = 0;
            break;
          }
          iVar4 = GetSystemMetrics(0);
          iVar2 = *(int *)(unaff_EBP + -0x10);
          piVar6[-3] = iVar4 / 4;
          if (iVar2 == 0) {
            piVar6[-2] = piVar6[-2] | 0x8000100;
          }
LAB_004beab7:
          piVar7 = piVar7 + 5;
          piVar6 = piVar6 + 5;
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + 0xc));
      }
      if (*(int *)(unaff_EBP + -0x14) != 0) {
        SelectObject(*(HDC *)(unaff_EBP + -0x34),*(HGDIOBJ *)(unaff_EBP + -0x14));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004b4ec4();
    }
    FUN_004bebe0(1,1);
    uVar5 = *(undefined4 *)(unaff_EBP + -0x18);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar5;
}

