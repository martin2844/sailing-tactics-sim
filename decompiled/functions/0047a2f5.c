
undefined4 FUN_0047a2f5(void)

{
  UINT *pUVar1;
  UINT UVar2;
  bool bVar3;
  int iVar4;
  HGDIOBJ pvVar5;
  undefined3 extraout_var;
  int iVar6;
  undefined4 uVar7;
  void *this;
  int unaff_EBP;
  UINT *pUVar8;
  UINT *pUVar9;
  void *this_00;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  *(void **)(unaff_EBP + -0x1c) = this;
  iVar4 = FUN_0047a42c(this,*(int *)(unaff_EBP + 0xc),0x14);
  uVar7 = 0;
  if (iVar4 != 0) {
    *(undefined4 *)(unaff_EBP + -0x18) = 1;
    this_00 = this;
    if (*(int *)(unaff_EBP + 8) != 0) {
      pvVar5 = (HGDIOBJ)SendMessageA(*(HWND *)((int)this + 0x1c),0x31,0,0);
      FUN_00470772();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      if (pvVar5 != (HGDIOBJ)0x0) {
        pvVar5 = SelectObject(*(HDC *)(unaff_EBP + -0x34),pvVar5);
        *(HGDIOBJ *)(unaff_EBP + -0x14) = pvVar5;
      }
      pUVar9 = *(UINT **)((int)this + 0x5c);
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      if (0 < *(int *)(unaff_EBP + 0xc)) {
        pUVar8 = pUVar9 + 4;
        do {
          pUVar1 = *(UINT **)(unaff_EBP + 8);
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 4;
          UVar2 = *pUVar1;
          pUVar8[-1] = pUVar8[-1] | 1;
          *pUVar9 = UVar2;
          if (UVar2 != 0) {
            bVar3 = FUN_0046d861(UVar2);
            if (CONCAT31(extraout_var,bVar3) != 0) {
              GetTextExtentPointA(*(HDC *)(unaff_EBP + -0x30),(LPCSTR)*pUVar8,
                                  *(int *)((LPCSTR)*pUVar8 + -8),(LPSIZE)(unaff_EBP + -0x24));
              pUVar8[-3] = *(UINT *)(unaff_EBP + -0x24);
              iVar4 = FUN_00471fe5();
              if (iVar4 != 0) goto LAB_0047a3d7;
            }
            *(undefined4 *)(unaff_EBP + -0x18) = 0;
            break;
          }
          iVar6 = GetSystemMetrics(0);
          iVar4 = *(int *)(unaff_EBP + -0x10);
          pUVar8[-3] = iVar6 / 4;
          if (iVar4 == 0) {
            pUVar8[-2] = pUVar8[-2] | 0x8000100;
          }
LAB_0047a3d7:
          pUVar9 = pUVar9 + 5;
          pUVar8 = pUVar8 + 5;
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + 0xc));
      }
      if (*(int *)(unaff_EBP + -0x14) != 0) {
        SelectObject(*(HDC *)(unaff_EBP + -0x34),*(HGDIOBJ *)(unaff_EBP + -0x14));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004707e4();
      this_00 = *(void **)(unaff_EBP + -0x1c);
    }
    FUN_0047a500(this_00,1,1);
    uVar7 = *(undefined4 *)(unaff_EBP + -0x18);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar7;
}

