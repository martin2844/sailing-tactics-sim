
void FUN_00459a9f(void)

{
  int *piVar1;
  int iVar2;
  DWORD *pDVar3;
  int unaff_EBP;
  
  piVar1 = *(int **)(unaff_EBP + 8);
  iVar2 = *(int *)(unaff_EBP + -0x2c);
  *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  pDVar3 = FUN_00459ed0();
  pDVar3[0x1b] = *(DWORD *)(unaff_EBP + -0x1c);
  pDVar3 = FUN_00459ed0();
  pDVar3[0x1c] = *(DWORD *)(unaff_EBP + -0x20);
  if ((((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == 0 && (iVar2 != 0)))) {
    __abnormal_termination();
    FUN_00459d50((int)piVar1);
  }
  return;
}

