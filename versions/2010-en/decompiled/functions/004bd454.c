
void __thiscall
FUN_004bd454(int param_1,undefined4 param_2,int param_3,char *param_4,undefined4 param_5,
            int *param_6,int param_7,undefined4 param_8)

{
  HCURSOR pHVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_004b06ed((Tact2010CString *)(param_1 + 200),param_4);
  uVar2 = 0;
  if (param_3 == 0) {
    uVar4 = 0;
    uVar3 = 0;
    pHVar1 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    param_3 = FUN_004ad47f(8,pHVar1,uVar3,uVar4);
  }
  if (param_7 != 0) {
    uVar2 = *(undefined4 *)(param_7 + 0x1c);
  }
  FUN_004acd4b(param_2,param_3,param_4,param_5,*param_6,param_6[1],param_6[2] - *param_6,
               param_6[3] - param_6[1],uVar2,param_8,0);
  return;
}

