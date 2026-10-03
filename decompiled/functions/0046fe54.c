
void __thiscall FUN_0046fe54(void *this,undefined4 *param_1)

{
  CWnd *pCVar1;
  undefined4 uVar2;
  
  pCVar1 = FUN_0046fd81(this,0);
  if ((pCVar1 == (CWnd *)0x0) || (*(int *)(pCVar1 + 0x80) != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  (**(code **)*param_1)(uVar2);
  return;
}

