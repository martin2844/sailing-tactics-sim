
void __thiscall FUN_00466ef2(void *this,int param_1,int param_2)

{
  void *_Dst;
  
  if (*(undefined **)((int)this + 4) != (undefined *)0x0) {
    FUN_0046b541(*(undefined **)((int)this + 4));
    *(undefined4 *)((int)this + 4) = 0;
  }
  if (param_2 != 0) {
    _Dst = (void *)FUN_0046b505(param_1 << 2);
    *(void **)((int)this + 4) = _Dst;
    _memset(_Dst,0,param_1 << 2);
  }
  *(int *)((int)this + 8) = param_1;
  return;
}

