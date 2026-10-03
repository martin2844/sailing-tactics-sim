
undefined4 __thiscall FUN_00468a08(void *this,undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0047b918();
  if (*(code **)(iVar1 + 0x1034) != (code *)0x0) {
    (**(code **)(iVar1 + 0x1034))(param_1,this);
  }
  return 0;
}

