
void __thiscall FUN_004763f5(void *this,uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == 2) {
    CWnd::ActivateTopParent(this);
    if ((*(byte *)((int)this + 0x130) & 0x40) == 0) {
      uVar1 = 0;
      iVar2 = 1;
      do {
        if (*(int *)((int)this + 0x150) <= iVar2) break;
        uVar1 = FUN_0047602d((void *)((int)this + 0xcc),iVar2);
        iVar2 = iVar2 + 1;
      } while (uVar1 == 0);
      (**(code **)**(undefined4 **)(uVar1 + 0x74))(param_2,param_3);
      return;
    }
  }
  else if ((9 < param_1) && (param_1 < 0x12)) {
    CWnd::ActivateTopParent(this);
    uVar1 = 0;
    iVar2 = 1;
    do {
      if (*(int *)((int)this + 0x150) <= iVar2) break;
      uVar1 = FUN_0047602d((void *)((int)this + 0xcc),iVar2);
      iVar2 = iVar2 + 1;
    } while (uVar1 == 0);
    (**(code **)(**(int **)(uVar1 + 0x74) + 4))(param_1,param_2,param_3);
    return;
  }
  FUN_004792bb(this,param_1);
  return;
}

