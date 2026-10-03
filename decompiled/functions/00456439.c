
void __thiscall FUN_00456439(void *this,undefined4 param_1,undefined4 *param_2)

{
  void *this_00;
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_30 [8];
  int local_10;
  byte *local_c [2];
  
  puVar2 = param_2;
  puVar4 = local_30;
  for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  if (((local_10 == 0) && (local_c[0] != (byte *)0xffffffff)) && (local_c[0] != (byte *)0x0)) {
    this_00 = (void *)((int)this + 0x3c);
    bVar1 = FUN_0046732a(this_00,local_c[0],&param_2);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      puVar2 = FUN_0046736e(this_00,local_c[0]);
      *puVar2 = 0;
    }
    FUN_0046734c(this_00,local_c[0],local_c);
  }
  (**(code **)(*(int *)this + 0xa8))(0x404,param_1,local_30);
  return;
}

