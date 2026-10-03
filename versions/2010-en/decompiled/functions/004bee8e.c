
void FUN_004bee8e(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_0049bcd8();
  if (*(int *)(unaff_EBP + 8) != 0) {
    iVar2 = FUN_004afbe5(0x20);
    *(int *)(unaff_EBP + -0x10) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_004b2064(0,"Recent File List","File%d",*(undefined4 *)(unaff_EBP + 8),0x1e
                                  );
    }
    iVar2 = *piVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)(extraout_ECX + 0xa8) = piVar3;
    (**(code **)(iVar2 + 0xc))();
  }
  uVar4 = FUN_004bf8cc("Settings","PreviewPages",0);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0xb4) = uVar4;
  *unaff_FS_OFFSET = uVar1;
  return;
}

