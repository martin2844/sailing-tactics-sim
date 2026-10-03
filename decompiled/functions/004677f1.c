
undefined4 __fastcall FUN_004677f1(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_0047b918();
  FUN_00472503(0);
  iVar1 = FUN_00469853(*(int *)(param_1 + 0x50),(undefined4 *)(param_1 + 0x54));
  FUN_004685dd(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x1c);
  }
  return uVar2;
}

