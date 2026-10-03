
undefined4 __thiscall FUN_0046cfb0(void *this,int param_1)

{
  while( true ) {
    if (this == (void *)0x0) {
      return 0;
    }
    if (this == (void *)param_1) break;
    this = *(void **)((int)this + 0x10);
  }
  return 1;
}

