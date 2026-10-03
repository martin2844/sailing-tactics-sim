
int FUN_0046d58d(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00457418();
  uVar1 = *(uint *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  *(void **)(unaff_EBP + -0x1c) = this;
  if (uVar1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0046702b(this,uVar1);
    if (iVar3 == 0) {
      iVar3 = FUN_0046702b((void *)((int)this + 0x1c),uVar1);
      if (iVar3 == 0) {
        uVar4 = FUN_0046b4f1(FUN_00470fe3);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
        iVar3 = FUN_0046cf6a();
        *(int *)(unaff_EBP + -0x14) = iVar3;
        if (iVar3 == 0) {
          FUN_00466060();
        }
        puVar5 = FUN_0046705e((void *)((int)this + 0x1c),uVar1);
        *puVar5 = *(undefined4 *)(unaff_EBP + -0x14);
        iVar3 = func_0x0046d637();
        return iVar3;
      }
      iVar2 = *(int *)((int)this + 0x3c);
      *(uint *)(iVar2 + iVar3) = uVar1;
      if (*(int *)((int)this + 0x40) == 2) {
        *(uint *)(iVar2 + iVar3 + 4) = uVar1;
      }
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar3;
}

