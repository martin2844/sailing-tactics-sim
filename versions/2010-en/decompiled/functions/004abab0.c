
undefined4 FUN_004abab0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == 0x110) {
    uVar1 = FUN_004ac7d4(param_1);
    piVar2 = (int *)FUN_004b162a(&PTR_s_CDialog_004cd2b8,uVar1);
    if (piVar2 == (int *)0x0) {
      uVar1 = 1;
    }
    else {
      uVar1 = (**(code **)(*piVar2 + 0xc4))();
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

