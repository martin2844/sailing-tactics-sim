
undefined4 FUN_004668f9(HWND param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *this;
  
  if (param_1 != (HWND)0x0) {
    iVar1 = FUN_0047be12(&DAT_004ae4b8,FUN_00455c3a);
    if (*(void **)(iVar1 + 0x18) != (void *)0x0) {
      FUN_0046ac54(*(void **)(iVar1 + 0x18),param_1);
      *(undefined4 *)(iVar1 + 0x18) = 0;
    }
    if (param_2 == 0x110) {
      uVar2 = FUN_004673d0((uint)param_1,0x110);
      return uVar2;
    }
    if ((param_2 == DAT_004ae8f0) || ((param_2 == 0x111 && ((short)param_3 == 0x40e)))) {
      SendMessageA(param_1,0x111,0xe146,0);
      return 1;
    }
    if (0xbfff < param_2) {
      this = (int *)FUN_004680f4((uint)param_1);
      iVar1 = FUN_0046cf38(this,0x488130);
      if ((iVar1 == 0) || ((*(byte *)((int)this + 0x92) & 8) == 0)) {
        if (param_2 == DAT_004ae8e0) {
          uVar2 = (**(code **)(*this + 0xd8))(param_4);
          return uVar2;
        }
        if (param_2 == DAT_004ae8ec) {
          if (DAT_004ae694 != 0) {
            this[0x7d] = param_4;
          }
          uVar2 = (**(code **)(*this + 0xdc))();
          this[0x7d] = 0;
          return uVar2;
        }
        if (param_2 == DAT_004ae8e8) {
          (**(code **)(*this + 0xe0))(param_3,param_4 & 0xffff,param_4 >> 0x10);
        }
        else if (param_2 == DAT_004ae8e4) {
          uVar2 = (**(code **)(*this + 0xd8))();
          return uVar2;
        }
      }
    }
  }
  return 0;
}

