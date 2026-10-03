
undefined4 FUN_0049b4d0(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  
  FUN_0049c600();
  uVar1 = FUN_0049cbe0(DAT_00539a48);
  if (uVar1 < (uint)((int)DAT_00539a44 + (4 - DAT_00539a48))) {
    iVar2 = FUN_0049cbe0(DAT_00539a48);
    iVar2 = FUN_0049e750(DAT_00539a48,iVar2 + 0x10);
    if (iVar2 == 0) {
      FUN_0049c610();
      return 0;
    }
    DAT_00539a44 = (undefined4 *)(iVar2 + ((int)DAT_00539a44 - DAT_00539a48 >> 2) * 4);
    DAT_00539a48 = iVar2;
  }
  *DAT_00539a44 = param_1;
  DAT_00539a44 = DAT_00539a44 + 1;
  FUN_0049c610();
  return param_1;
}

