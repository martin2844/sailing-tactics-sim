
void FUN_00477d9d(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  CWnd *pCVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar5;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  FUN_00466a52((void *)(unaff_EBP + -0x28),10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar5 = *(undefined4 **)(extraout_ECX + 0x70);
  while (puVar5 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar5;
    piVar2 = (int *)puVar5[2];
    iVar3 = (**(code **)(*piVar2 + 0xd8))();
    puVar5 = puVar1;
    if (iVar3 != 0) {
      AddTail((void *)(unaff_EBP + -0x28),piVar2);
    }
  }
  puVar5 = *(undefined4 **)(unaff_EBP + -0x24);
  while (puVar5 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar5;
    piVar2 = (int *)puVar5[2];
    puVar5 = puVar1;
    if (piVar2[0x1e] == 0) {
      (**(code **)(*piVar2 + 0x60))();
    }
    else {
      pCVar4 = FUN_004696a2((int)piVar2);
      (**(code **)(*(int *)pCVar4 + 0x60))();
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00466ab1();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

