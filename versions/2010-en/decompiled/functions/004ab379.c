
void __thiscall FUN_004ab379(int param_1,int param_2,int param_3)

{
  void *_Dst;
  int iVar1;
  
  if (param_3 != -1) {
    *(int *)(param_1 + 0x10) = param_3;
  }
  if (param_2 == 0) {
    FUN_004afc21(*(undefined4 *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else {
    if (*(int *)(param_1 + 4) == 0) {
      _Dst = (void *)FUN_004afbe5(param_2 << 2);
      *(void **)(param_1 + 4) = _Dst;
      _memset(_Dst,0,param_2 << 2);
      *(int *)(param_1 + 0xc) = param_2;
    }
    else {
      if (*(int *)(param_1 + 0xc) < param_2) {
        param_3 = *(int *)(param_1 + 0x10);
        if (*(int *)(param_1 + 0x10) == 0) {
          param_3 = *(int *)(param_1 + 8) / 8;
          iVar1 = 4;
          if (3 < param_3) {
            iVar1 = param_3;
          }
          if (iVar1 < 0x401) {
            if (param_3 < 4) {
              param_3 = 4;
            }
          }
          else {
            param_3 = 0x400;
          }
        }
        param_3 = param_3 + *(int *)(param_1 + 0xc);
        if (param_3 <= param_2) {
          param_3 = param_2;
        }
        iVar1 = FUN_004afbe5(param_3 << 2);
        FUN_0049c110(iVar1,*(undefined4 *)(param_1 + 4),*(int *)(param_1 + 8) << 2);
        _memset((void *)(iVar1 + *(int *)(param_1 + 8) * 4),0,
                (*(int *)(param_1 + 8) * 0x3fffffff + param_2) * 4);
        FUN_004afc21(*(undefined4 *)(param_1 + 4));
        *(int *)(param_1 + 4) = iVar1;
        *(int *)(param_1 + 8) = param_2;
        *(int *)(param_1 + 0xc) = param_3;
        return;
      }
      iVar1 = *(int *)(param_1 + 8);
      if (iVar1 < param_2) {
        _memset((void *)(*(int *)(param_1 + 4) + iVar1 * 4),0,(iVar1 * 0x3fffffff + param_2) * 4);
      }
    }
    *(int *)(param_1 + 8) = param_2;
  }
  return;
}

