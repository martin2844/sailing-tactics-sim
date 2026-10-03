
void __thiscall FUN_0047132a(void *this,int *param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  
  param_1[1] = 0;
  *param_1 = 0;
  uVar2 = FUN_0046ad0b((int)this);
  pcVar1 = *(code **)(*(int *)this + 0x70);
  iVar3 = (*pcVar1)(1);
  if ((iVar3 == 0) && (*param_1 = DAT_004ae638, (uVar2 & 0x800000) != 0)) {
    *param_1 = *param_1 + -1;
  }
  iVar3 = (*pcVar1)(0);
  if ((iVar3 == 0) && (param_1[1] = DAT_004ae63c, (uVar2 & 0x800000) != 0)) {
    param_1[1] = param_1[1] + -1;
  }
  return;
}

