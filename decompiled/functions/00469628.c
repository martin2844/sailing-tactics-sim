
undefined4 __thiscall
FUN_00469628(void *this,undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_10;
  undefined4 *local_c;
  uint local_8;
  
  local_8 = GetDlgCtrlID((HWND)*param_2);
  local_8 = local_8 & 0xffff;
  uVar1 = param_2[2];
  iVar2 = FUN_0047be12(&DAT_004ae4b8,FUN_00455c3a);
  if ((*(int *)(iVar2 + 0xb8) != *(int *)((int)this + 0x1c)) && (iVar2 = FUN_00469eee(), iVar2 == 0)
     ) {
    local_10 = param_3;
    local_c = param_2;
    uVar3 = (**(code **)(*(int *)this + 0x14))(local_8,uVar1 & 0xffff | 0x4e0000,&local_10,0);
    return uVar3;
  }
  return 1;
}

