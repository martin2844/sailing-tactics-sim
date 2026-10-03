
int __fastcall FUN_004b6391(int *param_1)

{
  int iVar1;
  
  if ((param_1[0x13] != 0) && (iVar1 = FUN_004b164a(), iVar1 != 0)) {
    (**(code **)(*param_1 + 100))(iVar1);
    return iVar1;
  }
  return 0;
}

