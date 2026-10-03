
uint __thiscall FUN_004b7a17(int param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  HDWP pvVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = FUN_004af3eb();
  uVar2 = uVar2 & 0x10000000;
  uVar5 = uVar2 | *(uint *)(param_1 + 100) & 0xff00;
  uVar1 = *(uint *)(param_1 + 0x60);
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
      *(uint *)(param_1 + 0x60) = uVar1 & 0xfffffffc;
    }
    else {
      uVar5 = uVar5 ^ 0x10000000;
      if (*param_2 != 0) {
        *(uint *)(param_1 + 0x60) = uVar1 & 0xfffffffc;
        pvVar3 = DeferWindowPos((HDWP)*param_2,*(HWND *)(param_1 + 0x1c),(HWND)0x0,0,0,0,0,
                                uVar4 | 0x17);
        *param_2 = (int)pvVar3;
      }
    }
  }
  return uVar5;
}

