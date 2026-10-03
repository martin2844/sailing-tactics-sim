
void __cdecl FUN_0045d310(uint param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_2[1];
  param_2[1] = iVar1 + -1;
  if (iVar1 + -1 < 0) {
    uVar2 = FUN_0045c850(param_1,param_2);
  }
  else {
    *(char *)*param_2 = (char)param_1;
    uVar2 = param_1 & 0xff;
    *param_2 = *param_2 + 1;
  }
  if (uVar2 == 0xffffffff) {
    *param_3 = -1;
    return;
  }
  *param_3 = *param_3 + 1;
  return;
}

