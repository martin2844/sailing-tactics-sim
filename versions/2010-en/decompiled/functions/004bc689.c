
void __thiscall FUN_004bc689(undefined4 param_1,undefined4 *param_2)

{
  SHORT SVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2[1];
  uVar3 = 1;
  if (iVar2 == 0xe701) {
    iVar2 = 0x14;
  }
  else if (iVar2 == 0xe702) {
    iVar2 = 0x90;
  }
  else if (iVar2 == 0xe703) {
    iVar2 = 0x91;
  }
  else {
    if (iVar2 != 0xe706) {
      param_2[7] = 1;
      return;
    }
    iVar2 = 0x15;
    if (DAT_005381ec == 0) {
      uVar3 = 0x8000;
    }
  }
  param_2 = (undefined4 *)*param_2;
  SVar1 = GetKeyState(iVar2);
  (*(code *)*param_2)((int)SVar1 & uVar3);
  return;
}

