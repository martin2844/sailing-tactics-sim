
void FUN_004be191(uint param_1,undefined4 param_2)

{
  SHORT SVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = FUN_004af3eb();
  if (((uVar2 & 0x80000000) != 0) &&
     ((((param_1 & 0xfff0) != 0xf060 ||
       (((SVar1 = GetKeyState(0x73), SVar1 < 0 && (SVar1 = GetKeyState(0x12), SVar1 < 0)) &&
        ((uVar2 & 0x100) != 0)))) && (iVar3 = FUN_004ae4a5(param_1,param_2), iVar3 != 0)))) {
    return;
  }
  FUN_004bbc36(param_1,param_2);
  return;
}

