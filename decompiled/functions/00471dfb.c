
void __thiscall
FUN_00471dfb(void *this,undefined4 *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  int *piVar1;
  
  piVar1 = FUN_0046cf4a(0x485c78,*(void **)((int)this + 0x20));
  if ((param_2 == 0xfffffffc) && (piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x14))(param_1,0xfffffffc,param_3,param_4);
  }
  else {
    FUN_0046afc3(this,param_1,param_2,param_3,param_4);
  }
  return;
}

