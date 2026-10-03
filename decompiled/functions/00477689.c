
void __thiscall FUN_00477689(void *this,int param_1)

{
  int *this_00;
  int iVar1;
  
  iVar1 = FUN_0047b918();
  this_00 = *(int **)(iVar1 + 4);
  if ((param_1 != 0) && ((void *)this_00[7] == this)) {
    FUN_00478729(1);
    FUN_004726d2(this_00,1);
    (**(code **)(*this_00 + 0x70))();
  }
  return;
}

