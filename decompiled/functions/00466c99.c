
void __thiscall FUN_00466c99(void *this,int param_1,int param_2)

{
  void *_Dst;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_2 != -1) {
    *(int *)((int)this + 0x10) = param_2;
  }
  if (param_1 == 0) {
    FUN_0046b541(*(undefined **)((int)this + 4));
    *(undefined4 *)((int)this + 4) = 0;
    *(undefined4 *)((int)this + 0xc) = 0;
    *(undefined4 *)((int)this + 8) = 0;
  }
  else {
    if (*(int *)((int)this + 4) == 0) {
      _Dst = (void *)FUN_0046b505(param_1 << 2);
      *(void **)((int)this + 4) = _Dst;
      _memset(_Dst,0,param_1 << 2);
      *(int *)((int)this + 0xc) = param_1;
    }
    else {
      if (*(int *)((int)this + 0xc) < param_1) {
        iVar1 = *(int *)((int)this + 0x10);
        if (*(int *)((int)this + 0x10) == 0) {
          iVar1 = *(int *)((int)this + 8) / 8;
          iVar3 = 4;
          if (3 < iVar1) {
            iVar3 = iVar1;
          }
          if (iVar3 < 0x401) {
            if (iVar1 < 4) {
              iVar1 = 4;
            }
          }
          else {
            iVar1 = 0x400;
          }
        }
        param_2 = iVar1 + *(int *)((int)this + 0xc);
        if (param_2 <= param_1) {
          param_2 = param_1;
        }
        puVar2 = (undefined4 *)FUN_0046b505(param_2 << 2);
        FUN_00457850(puVar2,*(undefined4 **)((int)this + 4),*(int *)((int)this + 8) << 2);
        _memset(puVar2 + *(int *)((int)this + 8),0,
                (*(int *)((int)this + 8) * 0x3fffffff + param_1) * 4);
        FUN_0046b541(*(undefined **)((int)this + 4));
        *(undefined4 **)((int)this + 4) = puVar2;
        *(int *)((int)this + 8) = param_1;
        *(int *)((int)this + 0xc) = param_2;
        return;
      }
      iVar1 = *(int *)((int)this + 8);
      if (iVar1 < param_1) {
        _memset((void *)(*(int *)((int)this + 4) + iVar1 * 4),0,(iVar1 * 0x3fffffff + param_1) * 4);
      }
    }
    *(int *)((int)this + 8) = param_1;
  }
  return;
}

