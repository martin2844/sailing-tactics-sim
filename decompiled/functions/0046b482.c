
undefined4 __thiscall FUN_0046b482(void *this,int *param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 local_10 [2];
  undefined4 local_8;
  
  if ((*(int *)((int)this + 4) == 0) || (*(short *)((int)this + 4) == -1)) {
    local_8 = 1;
  }
  else {
    iVar1 = *param_1;
    *(undefined4 *)((int)this + 0x18) = 0;
    pcVar2 = *(code **)(iVar1 + 0x14);
    local_8 = (*pcVar2)(*(int *)((int)this + 4),0xffffffff,this,0);
    if ((param_2 != 0) && (*(int *)((int)this + 0x18) == 0)) {
      local_10[0] = 0;
      uVar3 = (*pcVar2)(*(undefined4 *)((int)this + 4),0,this,local_10);
      (*(code *)**(undefined4 **)this)(uVar3);
    }
  }
  return local_8;
}

