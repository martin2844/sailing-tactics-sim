
undefined4 FUN_0047ad3a(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  iVar3 = *(int *)(unaff_EBP + 8);
  iVar1 = *(int *)(iVar3 + 0x10);
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  if (iVar1 == 0) {
    iVar3 = FUN_0047b918();
    iVar3 = (**(code **)(**(int **)(iVar3 + 4) + 0x14))(0xe100,0,0,0);
    if (iVar3 == 0) {
      FUN_00472436((int)extraout_ECX);
    }
    iVar3 = extraout_ECX[7];
  }
  else {
    if (iVar1 != 1) {
      if (1 < iVar1) {
        if (iVar1 < 4) {
          extraout_ECX[0x1d] = 0;
          (**(code **)(*extraout_ECX + 0x84))(*(undefined4 *)(iVar3 + 0x14));
          extraout_ECX[0x2b] = iVar3;
          SendMessageA(*(HWND *)(extraout_ECX[7] + 0x1c),0x111,0xe108,0);
          extraout_ECX[0x2b] = 0;
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
        }
        else if (iVar1 == 4) {
          iVar3 = extraout_ECX[0x1d];
          extraout_ECX[0x1d] = 0;
          extraout_ECX[0x2b] = iVar3;
        }
        else if (iVar1 == 5) {
          FUN_0047b0c9();
          FUN_0047ae83();
          if (*(int *)(iVar3 + 8) == 0) {
            FUN_0047260c();
          }
          iVar3 = extraout_ECX[0x2b];
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          if (iVar3 == 0) {
            iVar3 = FUN_0046b505(0x24);
            *(int *)(unaff_EBP + 8) = iVar3;
            *(undefined4 *)(unaff_EBP + -4) = 0;
            if (iVar3 == 0) {
              puVar4 = (undefined4 *)0x0;
            }
            else {
              puVar4 = FUN_0047a888();
            }
            extraout_ECX[0x2b] = (int)puVar4;
            puVar4[4] = 5;
          }
        }
      }
      goto LAB_0047ae6f;
    }
    iVar3 = (**(code **)(*extraout_ECX + 0x84))(*(undefined4 *)(iVar3 + 0x14));
  }
  if (iVar3 == 0) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
  }
LAB_0047ae6f:
  uVar2 = *(undefined4 *)(unaff_EBP + -0x10);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

