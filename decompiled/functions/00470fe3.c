
undefined4 __cdecl FUN_00470fe3(int param_1)

{
  int iVar1;
  SIZE_T SVar2;
  
  iVar1 = FUN_0047b5c5();
  if ((iVar1 != 0) && (*(undefined **)(iVar1 + 0xc) != (undefined *)0x0)) {
    SVar2 = FUN_00458320(*(undefined **)(iVar1 + 0xc));
    if (param_1 + 4U < SVar2) {
      FUN_00458270(*(undefined **)(iVar1 + 0xc),(int *)((SVar2 - param_1) + -4));
    }
    else {
      FUN_00457710(*(undefined **)(iVar1 + 0xc));
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
    return 1;
  }
  FUN_00466060();
  return 0;
}

