
undefined4 FUN_004bf41a(void)

{
  int iVar1;
  int iVar2;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar3;
  
  FUN_0049bcd8();
  iVar2 = *(int *)(unaff_EBP + 8);
  iVar1 = *(int *)(iVar2 + 0x10);
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  if (iVar1 == 0) {
    iVar2 = FUN_004bfff8();
    iVar2 = (**(code **)(**(int **)(iVar2 + 4) + 0x14))(0xe100,0,0,0);
    if (iVar2 == 0) {
      FUN_004b6b16();
    }
    iVar2 = extraout_ECX[7];
  }
  else {
    if (iVar1 != 1) {
      if (1 < iVar1) {
        if (iVar1 < 4) {
          extraout_ECX[0x1d] = 0;
          (**(code **)(*extraout_ECX + 0x84))(*(undefined4 *)(iVar2 + 0x14));
          extraout_ECX[0x2b] = iVar2;
          SendMessageA(*(HWND *)(extraout_ECX[7] + 0x1c),0x111,0xe108,0);
          extraout_ECX[0x2b] = 0;
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
        }
        else if (iVar1 == 4) {
          iVar2 = extraout_ECX[0x1d];
          extraout_ECX[0x1d] = 0;
          extraout_ECX[0x2b] = iVar2;
        }
        else if (iVar1 == 5) {
          FUN_004bf7a9();
          iVar1 = FUN_004bf563();
          if (*(int *)(iVar2 + 8) == 0) {
            if (iVar1 == 0) {
              uVar3 = 0xf10c;
            }
            else {
              uVar3 = 0xf10b;
            }
            FUN_004b6cec(uVar3,0,0xffffffff);
          }
          iVar2 = extraout_ECX[0x2b];
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          if (iVar2 == 0) {
            iVar2 = FUN_004afbe5(0x24);
            *(int *)(unaff_EBP + 8) = iVar2;
            *(undefined4 *)(unaff_EBP + -4) = 0;
            if (iVar2 == 0) {
              iVar2 = 0;
            }
            else {
              iVar2 = FUN_004bef68();
            }
            extraout_ECX[0x2b] = iVar2;
            *(undefined4 *)(iVar2 + 0x10) = 5;
          }
        }
      }
      goto LAB_004bf54f;
    }
    iVar2 = (**(code **)(*extraout_ECX + 0x84))(*(undefined4 *)(iVar2 + 0x14));
  }
  if (iVar2 == 0) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
  }
LAB_004bf54f:
  uVar3 = *(undefined4 *)(unaff_EBP + -0x10);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}

