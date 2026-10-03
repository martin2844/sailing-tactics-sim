
undefined4 __thiscall FUN_0046a8e9(void *this,LPMSG param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1->message;
  if (((uVar1 < 0x100) || (0x108 < uVar1)) && ((uVar1 < 0x200 || (0x209 < uVar1)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0046acd8(this,param_1);
  }
  return uVar2;
}

