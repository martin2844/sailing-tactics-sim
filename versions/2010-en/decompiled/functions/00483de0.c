
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00483de0(int *param_1,int param_2,int param_3,int param_4,int param_5,double param_6,int param_7
            )

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  HDC hdc;
  
  if ((((DAT_004da148 + 1 <= param_3) && (-1 < param_2)) && (param_2 <= DAT_004fe624)) &&
     (param_3 <= DAT_00535564)) {
    fVar6 = (float10)FUN_00406220(param_3,param_7);
    iVar5 = (int)(longlong)(fVar6 * (float10)param_6 * (float10)_DAT_004cc580);
    if (1000 < iVar5) {
      iVar5 = 1000;
    }
    uVar3 = param_4 >> 0x1f;
    if (((param_4 ^ uVar3) - uVar3 & 1 ^ uVar3) == uVar3) {
      (**(code **)(*param_1 + 0x2c))(param_1,0);
    }
    else if (DAT_004f3f5c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f3f5c);
    }
    pcVar2 = *(code **)(*param_1 + 0x2c);
    (*pcVar2)(param_1,8);
    if (param_5 == 0) {
      hdc = (HDC)param_1[1];
      iVar1 = iVar5 / 2;
    }
    else {
      hdc = (HDC)param_1[1];
      iVar1 = iVar5;
    }
    iVar4 = iVar5 / 2;
    Rectangle(hdc,param_2 - iVar5 / 2,(param_3 - iVar1) + 2,param_2 + iVar4,param_3 + 2);
    if (param_4 == 6) {
      iVar5 = iVar5 / 5;
      iVar1 = (param_3 - iVar4) + 2;
      _DAT_004f6e34 = ((param_3 + iVar5 * -5) - iVar4) + 2;
      _DAT_004f6e30 = param_2;
      _DAT_004f6e28 = param_2 - iVar5;
      _DAT_004f6e2c = iVar1;
      _DAT_004f6e38 = iVar5 + param_2;
      _DAT_004f6e3c = iVar1;
      (*pcVar2)(param_1,7);
      (*pcVar2)(param_1,0);
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,3);
      (*pcVar2)(param_1,6);
      FUN_004b4d9d(param_1,(int *)&param_6,param_2 - iVar5,iVar1);
      CDC::LineTo(param_1,iVar5 + param_2,iVar1);
    }
  }
  return;
}

