
uint __thiscall FUN_00473337(void *this,int *param_1)

{
  uint uVar1;
  uint uVar2;
  HDWP pvVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = FUN_0046ad0b((int)this);
  uVar2 = uVar2 & 0x10000000;
  uVar5 = uVar2 | *(uint *)((int)this + 100) & 0xff00;
  uVar1 = *(uint *)((int)this + 0x60);
  if ((uVar1 & 3) != 0) {
    uVar4 = 0;
    if ((uVar1 & 1) == 0) {
      if (uVar2 == 0) {
        uVar4 = 0x40;
      }
    }
    else if (uVar2 != 0) {
      uVar4 = 0x80;
    }
    if (uVar4 == 0) {
      *(uint *)((int)this + 0x60) = uVar1 & 0xfffffffc;
    }
    else {
      uVar5 = uVar5 ^ 0x10000000;
      if (*param_1 != 0) {
        *(uint *)((int)this + 0x60) = uVar1 & 0xfffffffc;
        pvVar3 = DeferWindowPos((HDWP)*param_1,*(HWND *)((int)this + 0x1c),(HWND)0x0,0,0,0,0,
                                uVar4 | 0x17);
        *param_1 = (int)pvVar3;
      }
    }
  }
  return uVar5;
}

