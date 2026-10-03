
void __thiscall FUN_00474b6d(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  void *local_c;
  void *local_8;
  
  iVar1 = param_1 - *(int *)((int)this + 4);
  iVar3 = param_2 - *(int *)((int)this + 8);
  iVar2 = *(int *)((int)this + 0x8c);
  uVar4 = 2;
  if (iVar2 == 10) {
    *(int *)((int)this + 0x28) = *(int *)((int)this + 0x28) + iVar1;
  }
  else {
    if (iVar2 != 0xb) {
      uVar4 = 0x22;
      if (iVar2 == 0xc) {
        *(int *)((int)this + 0x2c) = *(int *)((int)this + 0x2c) + iVar3;
      }
      else {
        *(int *)((int)this + 0x34) = *(int *)((int)this + 0x34) + iVar3;
      }
      iVar2 = *(int *)((int)this + 0x34) - *(int *)((int)this + 0x2c);
      goto LAB_00474bc7;
    }
    *(int *)((int)this + 0x30) = *(int *)((int)this + 0x30) + iVar1;
  }
  iVar2 = *(int *)((int)this + 0x30) - *(int *)((int)this + 0x28);
LAB_00474bc7:
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  local_c = this;
  local_8 = this;
  (**(code **)(**(int **)((int)this + 0x68) + 0xc4))(&local_c,iVar2,uVar4);
  if ((*(int *)((int)this + 0x8c) == 10) || (*(int *)((int)this + 0x8c) == 0xc)) {
    *(int *)((int)this + 0x38) = *(int *)((int)this + 0x40) - (int)local_c;
    *(int *)((int)this + 0x3c) = *(int *)((int)this + 0x44) - (int)local_8;
    *(int *)((int)this + 0x48) =
         ((*(int *)((int)this + 0x50) - *(int *)((int)this + 0x60)) + *(int *)((int)this + 0x58)) -
         (int)local_c;
    *(int *)((int)this + 0x4c) =
         ((*(int *)((int)this + 0x5c) - *(int *)((int)this + 100)) + *(int *)((int)this + 0x54)) -
         (int)local_8;
  }
  else {
    *(int *)((int)this + 0x40) = *(int *)((int)this + 0x38) + (int)local_c;
    *(int *)((int)this + 0x44) = *(int *)((int)this + 0x3c) + (int)local_8;
    *(int *)((int)this + 0x50) =
         ((*(int *)((int)this + 0x60) + *(int *)((int)this + 0x48)) - *(int *)((int)this + 0x58)) +
         (int)local_c;
    *(int *)((int)this + 0x54) =
         (*(int *)((int)this + 100) - *(int *)((int)this + 0x5c)) + *(int *)((int)this + 0x4c) +
         (int)local_8;
  }
  *(int *)((int)this + 4) = param_1;
  *(int *)((int)this + 8) = param_2;
  FUN_00474e9c(this,0);
  return;
}

