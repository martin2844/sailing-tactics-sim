
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00408b00(int param_1,double param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  float10 fVar7;
  float10 fVar8;
  int local_28;
  
  bVar6 = DAT_00491194 != 8;
  local_28 = -10;
  iVar3 = -10;
  while( true ) {
    do {
      iVar1 = DAT_004ab184 / (int)((-(uint)bVar6 & 0xfffffffc) + 9);
      iVar4 = local_28 * iVar1 + DAT_004aa594;
      uVar5 = iVar3 * iVar1 + DAT_004aa59c;
      if (DAT_004a4ee4 != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
      }
      uVar2 = FUN_00421560(iVar4,uVar5,0);
      iVar1 = (uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f);
      fVar7 = FUN_0042c400((double)iVar4,(double)(int)uVar5,4,0);
      if (_DAT_00484d38 < (double)CONCAT44(_DAT_004a682c,_DAT_004a6828)) {
        _DAT_004a6828 = 0;
        _DAT_004a682c = 0x40bb5800;
      }
      fVar8 = (float10)fsin(fVar7);
      fVar7 = (float10)fcos(fVar7);
      if (0 < iVar1) {
        FUN_00430eb0((CDC *)param_1,
                     (int)(longlong)
                          (fVar8 * (float10)param_2 *
                           (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828) + (float10)param_3
                          ),(int)(longlong)
                                 ((float10)param_4 -
                                 fVar7 * (float10)param_2 *
                                 (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828)),
                     DAT_004aa960,(int)(0x46 / (longlong)iVar1));
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xb);
    local_28 = local_28 + 1;
    if (10 < local_28) break;
    iVar3 = -10;
  }
  return;
}

