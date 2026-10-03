
void __thiscall FUN_0049ab29(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_30 [8];
  int local_10;
  int local_c [2];
  
  puVar1 = param_3;
  puVar3 = local_30;
  for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  if (((local_10 == 0) && (local_c[0] != -1)) && (local_c[0] != 0)) {
    iVar2 = FUN_004aba0a(local_c[0],&param_3);
    if (iVar2 == 0) {
      puVar1 = (undefined4 *)FUN_004aba4e(local_c[0]);
      *puVar1 = 0;
    }
    FUN_004aba2c(local_c[0],local_c);
  }
  (**(code **)(*param_1 + 0xa8))(0x404,param_2,local_30);
  return;
}

