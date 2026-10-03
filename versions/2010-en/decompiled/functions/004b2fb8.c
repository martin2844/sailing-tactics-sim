
int * FUN_004b2fb8(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  CWinThread *pCVar6;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  piVar5 = (int *)extraout_ECX[0x19];
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)(**(code **)(*extraout_ECX + 0x74))();
    *(undefined4 *)(unaff_EBP + -0x14) = 1;
LAB_004b3005:
    if (piVar5 == (int *)0x0) {
      FUN_004b6cec(0xf104,0,0xffffffff);
    }
    else {
      if (*(int *)(unaff_EBP + -0x10) == 0) {
        iVar2 = *extraout_ECX;
        iVar4 = piVar5[0x12];
        piVar5[0x12] = 0;
        iVar2 = (**(code **)(iVar2 + 0x78))(piVar5,0);
        *(int *)(unaff_EBP + -0x10) = iVar2;
        piVar5[0x12] = iVar4;
        if (iVar2 == 0) {
          FUN_004b6cec(0xf104,0,0xffffffff);
          (**(code **)(*piVar5 + 4))(1);
          goto LAB_004b310d;
        }
      }
      if (*(int *)(unaff_EBP + 8) == 0) {
        (**(code **)(*extraout_ECX + 0x8c))(piVar5);
        if (*(int *)(unaff_EBP + 0xc) == 0) {
          piVar5[0x13] = 1;
        }
        iVar2 = (**(code **)(*piVar5 + 0x78))();
        if (iVar2 != 0) {
LAB_004b312e:
          pCVar6 = AfxGetThread();
          if ((*(int *)(unaff_EBP + -0x14) != 0) && (*(int *)(pCVar6 + 0x1c) == 0)) {
            *(undefined4 *)(pCVar6 + 0x1c) = *(undefined4 *)(unaff_EBP + -0x10);
          }
          (**(code **)(*extraout_ECX + 0x7c))
                    (*(undefined4 *)(unaff_EBP + -0x10),piVar5,*(undefined4 *)(unaff_EBP + 0xc));
          goto LAB_004b3153;
        }
        if (*(int *)(unaff_EBP + -0x14) != 0) {
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x60))();
        }
      }
      else {
        FUN_004bfff8();
        FUN_004af903();
        *(undefined4 *)(unaff_EBP + -4) = 0;
        iVar2 = *piVar5;
        uVar3 = (**(code **)(iVar2 + 0x60))();
        *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
        pcVar1 = *(code **)(iVar2 + 100);
        *(code **)(unaff_EBP + -0x1c) = pcVar1;
        (*pcVar1)(0);
        iVar4 = (**(code **)(iVar2 + 0x7c))(*(undefined4 *)(unaff_EBP + 8));
        if (iVar4 != 0) {
          (**(code **)(iVar2 + 0x5c))(*(undefined4 *)(unaff_EBP + 8),1);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_004bfff8();
          FUN_004af918();
          goto LAB_004b312e;
        }
        if (*(int *)(unaff_EBP + -0x14) == 0) {
          iVar4 = (**(code **)(iVar2 + 0x60))();
          if (iVar4 == 0) {
            (**(code **)(unaff_EBP + -0x1c))(*(undefined4 *)(unaff_EBP + -0x18));
          }
          else {
            (**(code **)(*extraout_ECX + 0x8c))(piVar5);
            (**(code **)(iVar2 + 0x78))();
          }
        }
        else {
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x60))();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_004bfff8();
        FUN_004af918();
      }
    }
  }
  else {
    iVar2 = (**(code **)(*piVar5 + 0x98))();
    if (iVar2 != 0) {
      uVar3 = FUN_0049a2e0();
      *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
      goto LAB_004b3005;
    }
  }
LAB_004b310d:
  piVar5 = (int *)0x0;
LAB_004b3153:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return piVar5;
}

