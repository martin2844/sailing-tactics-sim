
undefined4 __thiscall FUN_004012b0(void *this,undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00476ed0(this,param_1);
  if (iVar1 != -1) {
    iVar1 = FUN_0047a25c((void *)((int)this + 0xbc),(int)this,0x50008200,(HMENU)&DAT_0000e801);
    if (iVar1 != 0) {
      iVar1 = FUN_0047a2f5();
      if (iVar1 != 0) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}

