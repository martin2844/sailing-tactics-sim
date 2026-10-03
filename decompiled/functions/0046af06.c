
void __thiscall FUN_0046af06(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((((this != (void *)0x0) && (*(int *)((int)this + 0x38) == 0)) && (param_1 != 0)) &&
     (*(int *)(param_1 + 0x34) != 0)) {
    iVar2 = FUN_0046702b((void *)(*(int *)(param_1 + 0x34) + 0x20),*(uint *)((int)this + 0x1c));
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x24);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x38) == iVar2)) {
        *(undefined4 *)(iVar1 + 0x38) = 0;
      }
      *(int *)((int)this + 0x38) = iVar2;
      *(void **)(iVar2 + 0x24) = this;
    }
  }
  return;
}

