
void __thiscall FUN_0047aaa7(void *this,int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if ((*(int *)((int)this + 0x10) == 0) && (*(int *)(*(int *)((int)this + 0x14) + -8) != 0)) {
      *(undefined4 *)((int)this + 0x10) = 1;
    }
    uVar1 = 0;
    if ((*(int *)((int)this + 8) == 0) && (*(int *)((int)this + 0xc) == 0)) {
      uVar1 = 1;
    }
    *(undefined4 *)((int)this + 4) = uVar1;
  }
  return;
}

