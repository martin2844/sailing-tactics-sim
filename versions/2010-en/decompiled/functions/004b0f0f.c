
undefined4 __fastcall FUN_004b0f0f(int *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  pcVar1 = *(code **)(*param_1 + 0x30);
  uVar2 = (*pcVar1)(0,1);
  uVar3 = (*pcVar1)(0,2);
  (*pcVar1)(uVar2,0);
  return uVar3;
}

