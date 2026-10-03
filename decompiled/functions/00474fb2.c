
void __thiscall FUN_00474fb2(void *this,int *param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (*param_1 != param_2) {
    *param_1 = param_2;
    if ((((*(uint *)((int)this + 0x70) & 0xa000) == 0) ||
        ((*(uint *)((int)this + 0x70) & 0x5000) == 0)) || (*(int *)((int)this + 0x7c) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    *(undefined4 *)((int)this + 0x7c) = uVar1;
    if (*(int *)((int)this + 0x80) == 0) {
      uVar2 = FUN_00475004((int)this);
    }
    else {
      uVar2 = 0;
    }
    *(uint *)((int)this + 0x74) = uVar2;
    FUN_00474e9c(this,0);
  }
  return;
}

