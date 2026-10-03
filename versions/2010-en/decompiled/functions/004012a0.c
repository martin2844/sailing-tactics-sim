
undefined4 __thiscall FUN_004012a0(void *this,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_004bb5b0(this,param_2);
  if (iVar1 != -1) {
    iVar1 = FUN_004be93c(this,0x50008200,0xe801);
    if (iVar1 != 0) {
      iVar1 = FUN_004be9d5(&DAT_004da0f0,4);
      if (iVar1 != 0) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}

