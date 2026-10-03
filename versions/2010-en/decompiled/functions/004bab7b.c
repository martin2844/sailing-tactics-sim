
void __thiscall FUN_004bab7b(void *this,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 != 2) || (CWnd::ActivateTopParent(this), (*(byte *)((int)this + 0x130) & 0x40) != 0))
  {
    FUN_004ac701(this);
    return;
  }
  iVar1 = 0;
  iVar2 = 1;
  do {
    if (*(int *)((int)this + 0x150) <= iVar2) break;
    iVar1 = FUN_004ba70d(iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar1 == 0);
  (**(code **)(**(int **)(iVar1 + 0x74) + 8))();
  return;
}

