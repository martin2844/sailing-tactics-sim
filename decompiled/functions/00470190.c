
int __fastcall FUN_00470190(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1;
  if (*(HDC *)(param_1 + 8) != (HDC)0x0) {
    iVar1 = SaveDC(*(HDC *)(param_1 + 8));
  }
  if ((*(HDC *)(param_1 + 4) != *(HDC *)(param_1 + 8)) &&
     (iVar2 = SaveDC(*(HDC *)(param_1 + 4)), iVar2 != 0)) {
    iVar1 = -1;
  }
  return iVar1;
}

