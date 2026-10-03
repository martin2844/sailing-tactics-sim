
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00408860(int param_1,double param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  float10 fVar5;
  float10 fVar6;
  int local_30;
  int local_2c;
  
  bVar4 = DAT_00491194 != 8;
  local_2c = -10;
  local_30 = -10;
  while( true ) {
    do {
      iVar1 = DAT_004ab184 / (int)((-(uint)bVar4 & 0xfffffffc) + 9);
      iVar3 = local_2c * iVar1 + DAT_004aa594;
      iVar1 = local_30 * iVar1 + DAT_004aa59c;
      if (DAT_004a4ee4 != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
      }
      iVar2 = FUN_00426150(iVar3,iVar1,0);
      if ((DAT_004a4390 == 1) && (DAT_004abbf4 != (HGDIOBJ)0x0)) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004abbf4);
      }
      if ((DAT_004a4390 == -1) && (DAT_004a39fc != (HGDIOBJ)0x0)) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a39fc);
      }
      if ((DAT_004a5f0c == 1) && (DAT_004a67ac != (HGDIOBJ)0x0)) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a67ac);
      }
      if ((DAT_004abd84 == 1) && (DAT_004ac30c != (HGDIOBJ)0x0)) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004ac30c);
      }
      if ((DAT_004a5b94 == 1) && (DAT_004a676c != (HGDIOBJ)0x0)) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a676c);
      }
      if (DAT_004ac92c == 1) {
        if ((DAT_004a5b94 == 0) && (DAT_004a4ee4 != (HGDIOBJ)0x0)) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
        }
        if (((DAT_004ac92c == 1) && (DAT_004a5b94 == 1)) && (DAT_004a4dec != (HGDIOBJ)0x0)) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
        }
      }
      fVar5 = FUN_0042c400((double)iVar3,(double)iVar1,4,0);
      if (_DAT_00484d38 < (double)CONCAT44(_DAT_004a682c,_DAT_004a6828)) {
        _DAT_004a6828 = 0;
        _DAT_004a682c = 0x40bb5800;
      }
      fVar6 = (float10)fcos(fVar5);
      fVar5 = (float10)fsin(fVar5);
      FUN_00430eb0((CDC *)param_1,
                   (int)(longlong)
                        (fVar5 * (float10)param_2 *
                         (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828) + (float10)param_3),
                   (int)(longlong)
                        ((float10)param_4 -
                        fVar6 * (float10)param_2 *
                        (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828)),DAT_004aaeac,
                   (int)(0x78 / (longlong)iVar2));
      local_30 = local_30 + 1;
    } while (local_30 < 0xb);
    local_2c = local_2c + 1;
    if (10 < local_2c) break;
    local_30 = -10;
  }
  return;
}

