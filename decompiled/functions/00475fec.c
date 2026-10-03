
void __thiscall FUN_00475fec(void *this,int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)((int)this + 0x84)) {
    do {
      piVar1 = (int *)FUN_0047602d(this,iVar2);
      if (piVar1 != (int *)0x0) {
        FUN_004786de((int)piVar1);
        FUN_004778ba(piVar1,param_1,1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this + 0x84));
  }
  return;
}

