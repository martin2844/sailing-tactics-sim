
int __cdecl FUN_00458cf0(undefined1 *param_1,char *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 *local_20;
  int local_1c;
  undefined1 *local_18;
  undefined4 local_14;
  
  local_18 = param_1;
  local_20 = param_1;
  local_14 = 0x42;
  local_1c = 0x7fffffff;
  iVar1 = FUN_0045c980((int *)&local_20,param_2,param_3);
  local_1c = local_1c + -1;
  if (-1 < local_1c) {
    *local_20 = 0;
    return iVar1;
  }
  FUN_0045c850(0,(int *)&local_20);
  return iVar1;
}

