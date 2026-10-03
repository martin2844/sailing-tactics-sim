
bool __thiscall FUN_004bc56f(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_004bc506(param_2);
  if (iVar1 != 0) {
    uVar3 = 0;
    uVar2 = FUN_004af3eb(0);
    FUN_004bbf9a(iVar1,~uVar2 >> 0x1c & 1,uVar3);
  }
  return iVar1 != 0;
}

