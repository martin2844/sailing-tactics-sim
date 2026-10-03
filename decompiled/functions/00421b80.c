
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */

int __cdecl FUN_00421b80(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  
  iVar2 = DAT_004ac840;
  if ((param_1 != 1) && (iVar2 = DAT_004aae1c, DAT_004aa298 < 0)) {
    iVar2 = DAT_004aae1c + 0xb4;
  }
  iVar2 = FUN_00413cb0(iVar2);
  iVar5 = 300;
  while( true ) {
    iVar1 = iVar5 / 400;
    iVar3 = iVar1 * (&DAT_004a54a0)[iVar2] + param_2;
    iVar4 = param_3 - iVar1 * (&DAT_004a3450)[iVar2];
    if (DAT_004a864c == 1) {
      fVar6 = FUN_00420b70(iVar3,iVar4,0);
    }
    else {
      fVar6 = FUN_00420c40(iVar3,iVar4,0);
    }
    if ((int)(longlong)fVar6 < 5) break;
    iVar5 = iVar5 + 300;
    if (0xce4 < iVar5) {
      return 900;
    }
  }
  return iVar1 * 100;
}

