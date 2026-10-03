
int __thiscall FUN_00471f61(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = *(int *)((int)this + 0x58);
  if (0 < iVar1) {
    piVar3 = *(int **)((int)this + 0x5c);
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if (*piVar3 == param_1) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 5;
      } while (iVar2 < iVar1);
    }
  }
  return -1;
}

