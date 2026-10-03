
bool __thiscall FUN_004b45b6(void *this,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_004b4461(this,0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xf4))(param_2 == 0xe151);
  }
  return piVar1 != (int *)0x0;
}

