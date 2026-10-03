
void __thiscall FUN_00466de3(void *this,int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 8);
  if (param_1 < iVar1) {
    FUN_00466c99(this,iVar1 + param_3,-1);
    FUN_00457e80((undefined4 *)(*(int *)((int)this + 4) + (param_3 + param_1) * 4),
                 (undefined4 *)(*(int *)((int)this + 4) + param_1 * 4),
                 (param_1 * 0x3fffffff + iVar1) * 4);
    _memset((void *)(*(int *)((int)this + 4) + param_1 * 4),0,param_3 << 2);
  }
  else {
    FUN_00466c99(this,param_3 + param_1,-1);
  }
  if (param_3 != 0) {
    iVar1 = param_1 << 2;
    do {
      *(undefined4 *)(*(int *)((int)this + 4) + iVar1) = param_2;
      iVar1 = iVar1 + 4;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

