
bool __thiscall FUN_00477e8f(void *this,uint param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = (int *)FUN_00477e26(this,param_1);
  if (piVar1 != (int *)0x0) {
    iVar3 = 0;
    uVar2 = FUN_0046ad0b((int)piVar1);
    FUN_004778ba(piVar1,~uVar2 >> 0x1c & 1,iVar3);
  }
  return piVar1 != (int *)0x0;
}

