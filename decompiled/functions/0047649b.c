
void __thiscall FUN_0047649b(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != 2) || (CWnd::ActivateTopParent(this), (*(byte *)((int)this + 0x130) & 0x40) != 0))
  {
    FUN_00468021(this);
    return;
  }
  uVar1 = 0;
  iVar2 = 1;
  do {
    if (*(int *)((int)this + 0x150) <= iVar2) break;
    uVar1 = FUN_0047602d((void *)((int)this + 0xcc),iVar2);
    iVar2 = iVar2 + 1;
  } while (uVar1 == 0);
  (**(code **)(**(int **)(uVar1 + 0x74) + 8))();
  return;
}

