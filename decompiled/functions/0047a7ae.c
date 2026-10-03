
void FUN_0047a7ae(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  if (*(int *)(unaff_EBP + 8) != 0) {
    iVar2 = FUN_0046b505(0x20);
    *(int *)(unaff_EBP + -0x10) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar2 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_0046d984();
    }
    iVar2 = *piVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)((int)this + 0xa8) = piVar3;
    (**(code **)(iVar2 + 0xc))();
  }
  pvVar4 = FUN_0047b1ec(this,"Settings","PreviewPages",(void *)0x0);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *(void **)((int)this + 0xb4) = pvVar4;
  *unaff_FS_OFFSET = uVar1;
  return;
}

