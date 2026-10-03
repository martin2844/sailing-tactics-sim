
uint __thiscall FUN_0045dfc0(void *this,uint param_1,uint param_2)

{
  uint uVar1;
  undefined2 in_FPUControlWord;
  undefined4 local_8;
  
  local_8 = CONCAT22((short)((uint)this >> 0x10),in_FPUControlWord);
  uVar1 = FUN_0045e020(local_8);
  FUN_0045e0c0();
  return param_2 & param_1 | ~param_2 & uVar1;
}

