
void __thiscall FUN_00477fa9(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  SHORT SVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = param_1[1];
  uVar4 = 1;
  if (iVar3 == 0xe701) {
    iVar3 = 0x14;
  }
  else if (iVar3 == 0xe702) {
    iVar3 = 0x90;
  }
  else if (iVar3 == 0xe703) {
    iVar3 = 0x91;
  }
  else {
    if (iVar3 != 0xe706) {
      param_1[7] = 1;
      return;
    }
    iVar3 = 0x15;
    if (DAT_004ae694 == 0) {
      uVar4 = 0x8000;
    }
  }
  puVar1 = (undefined4 *)*param_1;
  SVar2 = GetKeyState(iVar3);
  (*(code *)*puVar1)((int)SVar2 & uVar4);
  return;
}

