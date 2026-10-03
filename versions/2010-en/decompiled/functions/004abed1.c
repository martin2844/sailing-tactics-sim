
undefined4 __fastcall FUN_004abed1(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_004bfff8();
  FUN_004b6be3(0);
  iVar1 = FUN_004adf33(*(undefined4 *)(param_1 + 0x50),param_1 + 0x54);
  FUN_004accbd(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x1c);
  }
  return uVar2;
}

