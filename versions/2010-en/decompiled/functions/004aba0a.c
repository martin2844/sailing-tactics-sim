
bool FUN_004aba0a(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_004ab9b0(param_1,&param_1);
  if (iVar1 != 0) {
    *param_2 = *(undefined4 *)(iVar1 + 0xc);
  }
  return iVar1 != 0;
}

