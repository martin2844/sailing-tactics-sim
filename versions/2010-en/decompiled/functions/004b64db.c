
void __thiscall
FUN_004b64db(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_004b162a(&PTR_s_CCmdTarget_004cd918,*(undefined4 *)(param_1 + 0x20));
  if ((param_3 == -4) && (piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x14))(param_2,0xfffffffc,param_4,param_5);
  }
  else {
    FUN_004af6a3(param_2,param_3,param_4,param_5);
  }
  return;
}

