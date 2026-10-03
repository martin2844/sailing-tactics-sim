
void __thiscall FUN_0046fe98(void *this,undefined4 *param_1)

{
  CWnd *pCVar1;
  int iVar2;
  undefined4 uVar3;
  
  pCVar1 = FUN_0046fd81(this,0);
  if (pCVar1 != (CWnd *)0x0) {
    iVar2 = (**(code **)(*(int *)pCVar1 + 0xf0))(param_1[1] == 0xe151);
    if (iVar2 != 0) {
      uVar3 = 1;
      goto LAB_0046fecb;
    }
  }
  uVar3 = 0;
LAB_0046fecb:
  (**(code **)*param_1)(uVar3);
  return;
}

