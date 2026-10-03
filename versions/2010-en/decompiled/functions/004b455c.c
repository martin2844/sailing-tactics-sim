
bool __thiscall FUN_004b455c(void *this)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_004b4461(this,0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xf8))();
  }
  return piVar1 != (int *)0x0;
}

