
undefined4 __thiscall FUN_0046959c(void *this,uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  CCmdUI local_30 [4];
  uint local_2c;
  int local_8;
  
  uVar3 = param_1 & 0xffff;
  param_1 = param_1 >> 0x10;
  if (param_2 == 0) {
    if (uVar3 == 0) {
      return 0;
    }
    FUN_00469569(local_30);
    local_2c = uVar3;
    (**(code **)(*(int *)this + 0x14))(uVar3,0xffffffff,local_30,0);
    if (local_8 != 0) {
      param_1 = 0;
LAB_004695e0:
      uVar1 = (**(code **)(*(int *)this + 0x14))(uVar3,param_1,0,0);
      return uVar1;
    }
  }
  else {
    iVar2 = FUN_0047be12(&DAT_004ae4b8,FUN_00455c3a);
    if ((*(int *)(iVar2 + 0xb8) != *(int *)((int)this + 0x1c)) &&
       (iVar2 = FUN_00469eee(), iVar2 == 0)) {
      if (uVar3 == 0) {
        return 0;
      }
      goto LAB_004695e0;
    }
  }
  return 1;
}

