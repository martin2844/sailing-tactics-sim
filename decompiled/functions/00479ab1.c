
void __thiscall FUN_00479ab1(void *this,uint param_1,int param_2)

{
  SHORT SVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = FUN_0046ad0b((int)this);
  if (((uVar2 & 0x80000000) != 0) &&
     ((((param_1 & 0xfff0) != 0xf060 ||
       (((SVar1 = GetKeyState(0x73), SVar1 < 0 && (SVar1 = GetKeyState(0x12), SVar1 < 0)) &&
        ((uVar2 & 0x100) != 0)))) && (iVar3 = FUN_00469dc5(this,param_1,param_2), iVar3 != 0)))) {
    return;
  }
  FUN_00477556(this,param_1);
  return;
}

