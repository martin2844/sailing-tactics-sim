
int __fastcall FUN_00466b7b(void *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)((int)param_1 + 4);
  iVar2 = *piVar1;
  iVar3 = piVar1[2];
  *(int *)((int)param_1 + 4) = iVar2;
  if (iVar2 == 0) {
    *(undefined4 *)((int)param_1 + 8) = 0;
  }
  else {
    *(undefined4 *)(iVar2 + 4) = 0;
  }
  FUN_00466b39(param_1,piVar1);
  return iVar3;
}

