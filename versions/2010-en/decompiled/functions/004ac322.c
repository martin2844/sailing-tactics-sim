
int __thiscall FUN_004ac322(void *this)

{
  int iVar1;
  
  if (*(int *)((int)this + 0x3c) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)((int)this + 0x3c) + 0x20000;
  }
  return iVar1;
}

