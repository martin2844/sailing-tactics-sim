
undefined4 __thiscall FUN_004ad0e8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_004bfff8();
  if (*(code **)(iVar1 + 0x1034) != (code *)0x0) {
    (**(code **)(iVar1 + 0x1034))(param_2,param_1);
  }
  return 0;
}

