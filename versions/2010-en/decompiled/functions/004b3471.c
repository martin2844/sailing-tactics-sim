
void __thiscall FUN_004b3471(int *param_1,undefined4 param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  undefined1 local_208 [256];
  char local_108 [260];
  
  FUN_004b1300(local_108,param_2);
  FUN_004b06ed((Tact2010CString *)(param_1 + 8),local_108);
  param_1[0x13] = 0;
  iVar2 = FUN_004b1562(local_108,local_208,0x100);
  if (iVar2 == 0) {
    (**(code **)(*param_1 + 0x58))(local_208);
  }
  if (param_3 != 0) {
    pcVar1 = ((Tact2010CString *)(param_1 + 8))->data;
    iVar2 = FUN_004bfff8();
    (**(code **)(**(int **)(iVar2 + 4) + 0x88))(pcVar1);
  }
  return;
}

