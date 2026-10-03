
uint __thiscall FUN_00471cd8(void *this,undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined4 local_8;
  
  _memset(&local_18,0,0x14);
  local_8 = param_2;
  local_14 = param_1;
  local_18 = *(undefined4 *)((int)this + 0x54);
  if ((*(int *)((int)this + 0x50) != 0) &&
     (local_10 = this, piVar1 = (int *)FUN_0046cf6a(), piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 0xc0))(*(undefined4 *)((int)this + 0x3c),0xcf8000,0,&local_18);
    return -(uint)(iVar2 != 0) & (uint)piVar1;
  }
  return 0;
}

