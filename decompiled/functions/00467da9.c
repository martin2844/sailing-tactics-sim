
undefined4 * __thiscall FUN_00467da9(void *this,undefined4 param_1)

{
  FUN_0046af4b(this);
  *(undefined ***)this = &PTR_FUN_00485a94;
  _memset((undefined4 *)((int)this + 0x1c),0,0x20);
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x1c) = param_1;
  return this;
}

