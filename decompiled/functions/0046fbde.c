
undefined4 __thiscall
FUN_0046fbde(void *this,undefined4 *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar2 = FUN_0046afc3(this,param_1,param_2,param_3,param_4);
  if (uVar2 == 0) {
    uVar3 = 0;
    if (*(int *)((int)this + 0x3c) != 0) {
      iVar4 = FUN_0047be12(&DAT_004ae4b8,FUN_00455c3a);
      uVar1 = *(undefined4 *)(iVar4 + 0xc0);
      *(void **)(iVar4 + 0xc0) = this;
      uVar3 = (**(code **)(**(int **)((int)this + 0x3c) + 0x14))(param_1,param_2,param_3,param_4);
      *(undefined4 *)(iVar4 + 0xc0) = uVar1;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

