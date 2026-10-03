
void __thiscall FUN_004b16fe(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 local_208 [512];
  undefined4 local_8;
  
  iVar1 = (**(code **)(*param_1 + 0x14))(local_208,0x200,&local_8);
  if (iVar1 == 0) {
    if (param_3 == 0) {
      param_3 = 0xf020;
    }
    FUN_004b6cec(param_3,param_2,local_8);
  }
  else {
    FUN_004b6ccb(local_208,param_2,local_8);
  }
  return;
}

