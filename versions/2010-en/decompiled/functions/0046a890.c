
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0046a890(int *param_1,int param_2,int param_3,double param_4)

{
  code *pcVar1;
  float10 fVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  double dVar6;
  double dVar7;
  int *original_dc;
  char *pcVar8;
  int iVar9;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  Tact2010CString TStack_2c;
  code *local_28;
  double dStack_24;
  double dStack_1c;
  double dStack_14;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c5e40;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  iVar9 = *param_1;
  local_28 = *(code **)(iVar9 + 0x38);
  (*local_28)(param_1,0x7fff);
  FUN_004b4a1f(original_dc,1);
  if (DAT_004da1f8 == 1) {
    fVar10 = FUN_0043ec20(2416.0,-1160.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)param_3 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,1);
    FUN_004b0613(&TStack_2c,"lighthouse");
    uStack_4 = 0;
    pcVar1 = *(code **)(iVar9 + 100);
    (*pcVar1)(original_dc,iVar3 + 10,(int)param_1,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    FUN_004b0613(&TStack_2c,s_Bear_I_004ec9f0);
    uStack_4 = 1;
    (*pcVar1)(original_dc,iVar3 + 0x19,(int)(param_1 + -5),TStack_2c.data,
              *(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(1458.0,1100.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,2);
    FUN_004b0613(&TStack_2c,"Fl R buoy");
    uStack_4 = 2;
    (*pcVar1)(original_dc,iVar3 + 10,(int)param_1,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-2268.0,-1310.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a700(original_dc);
    FUN_00471100(original_dc,iVar3,(int)param_1);
    FUN_004b0613(&TStack_2c,&DAT_004ec9e0);
    uStack_4 = 3;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(923.0,-2280.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,2);
    FUN_004b0613(&TStack_2c,"Fl R buoy");
    uStack_4 = 4;
    (*pcVar1)(original_dc,iVar3 + 10,(int)param_1,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-1010.0,-2343.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a700(original_dc);
    FUN_00471100(original_dc,iVar3,(int)param_1);
    FUN_004b0613(&TStack_2c,&DAT_004ec9e0);
    uStack_4 = 5;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(927.0,1848.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a700(original_dc);
    FUN_00471100(original_dc,iVar3,(int)param_1);
    FUN_004b0613(&TStack_2c,&DAT_004ec9e0);
    uStack_4 = 6;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-226.0,2676.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a730(original_dc);
    FUN_00471100(original_dc,iVar3,(int)param_1);
    FUN_004b0613(&TStack_2c,&DAT_004ec9dc);
    uStack_4 = 7;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-4272.0,447.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_00469650(original_dc);
    FUN_00433a70(original_dc,5,iVar3,param_1);
    FUN_004b0613(&TStack_2c,"Hinckley boat yard");
    uStack_4 = 8;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(3304.0,387.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Sutton_I_004ec9bc);
    uStack_4 = 9;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-2841.0,-1966.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Greening_I_004ec9b0);
    uStack_4 = 10;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(346.0,-2841.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Northeast Harbor");
    uStack_4 = 0xb;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-4600.0,-810.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Southwest Harbor");
    uStack_4 = 0xc;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(1617.0,2408.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Great_Cranberry_I_004ec974);
    uStack_4 = 0xd;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(2582.0,-5200.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Mt__Desert_I_004ec964);
    uStack_4 = 0xe;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-7355.0,2276.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Mt__Desert_I_004ec964);
    uStack_4 = 0xf;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
  }
  if (DAT_004da1f8 == 2) {
    fVar10 = FUN_0043ec20(-1080.0,-320.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)param_3 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a700(original_dc);
    FUN_00471100(original_dc,iVar3,(int)param_1);
    FUN_004b0613(&TStack_2c,s_gong_004ec95c);
    pcVar1 = *(code **)(iVar9 + 100);
    uStack_4 = 0x10;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-1240.0,-1360.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a700(original_dc);
    FUN_00471100(original_dc,iVar3,(int)param_1);
    FUN_004b0613(&TStack_2c,&DAT_004ec954);
    uStack_4 = 0x11;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(2480.0,-1520.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,3);
    FUN_004b0613(&TStack_2c,"Fl G whistle");
    uStack_4 = 0x12;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(510.0,-1629.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Halfway_Rk_004ec938);
    uStack_4 = 0x13;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11) + 5,
              (int)param_1 + -0xf,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-4625.0,-1050.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Marblehead_004ec92c);
    uStack_4 = 0x14;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-6000.0,1800.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Nahant_004ec924);
    uStack_4 = 0x15;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(3050.0,-760.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Massachusetts Bay");
    uStack_4 = 0x16;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
  }
  if (DAT_004da1f8 == 3) {
    fVar10 = FUN_0043ec20(3740.0,-1530.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)param_3 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,2);
    FUN_004b0613(&TStack_2c,"Fl R whistle");
    pcVar1 = *(code **)(iVar9 + 100);
    uStack_4 = 0x17;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(0.0,-2448.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a700(original_dc);
    FUN_00471100(original_dc,iVar3,(int)param_1);
    FUN_004b0613(&TStack_2c,&DAT_004ec954);
    uStack_4 = 0x18;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-470.0,-4114.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Conanicut_I_004ec8f4);
    uStack_4 = 0x19;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(5000.0,-4600.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Newport_004ec8ec);
    uStack_4 = 0x1a;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-7790.0,3955.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Pt_Judith_004ec8e0);
    uStack_4 = 0x1b;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(200.0,3330.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Rhode Island Sound");
    uStack_4 = 0x1c;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
  }
  if (DAT_004da1f8 == 6) {
    fVar10 = FUN_0043ec20(-4284.0,0.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)param_3 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,1);
    FUN_004b0613(&TStack_2c,&DAT_004ec3b0);
    pcVar1 = *(code **)(iVar9 + 100);
    uStack_4 = 0x1d;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-900.0,2430.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,2);
    FUN_004b0613(&TStack_2c,s_Fl_R_bell_004ec8c0);
    uStack_4 = 0x1e;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-1350.0,3207.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,3);
    FUN_004b0613(&TStack_2c,s_Fl_R_gong_004ec8b4);
    uStack_4 = 0x1f;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-2016.0,6625.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,3);
    FUN_004b0613(&TStack_2c,"Fl W lighthouse");
    uStack_4 = 0x20;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    DAT_004f4690 = (char *)0xd5c;
    DAT_004fb418 = (int *)0xfffff5e0;
    DAT_004f4698 = (char *)0x132c;
    DAT_004fb4ac = (int *)0xfffff7c6;
    FUN_00471160(original_dc);
    if (DAT_00522d14 != (HGDIOBJ)0x0) {
      SelectObject((HDC)original_dc[1],DAT_00522d14);
    }
    fVar10 = FUN_0043ec20(872.0,-3701.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fcos(fVar10);
    fVar10 = (float10)fsin(fVar10);
    FUN_004b4d9d(original_dc,(int *)&dStack_24,
                 (int)(longlong)
                      (fVar10 * (float10)param_4 *
                       (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) + (float10)dStack_1c),
                 (int)(longlong)
                      ((float10)dStack_14 -
                      fVar11 * (float10)param_4 *
                      (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)));
    param_1 = DAT_004fb418;
    TStack_2c.data = DAT_004f4690;
    fVar10 = FUN_0043ec20((double)(int)DAT_004f4690,(double)(int)DAT_004fb418,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_00433a70(original_dc,5,iVar3,param_1);
    CDC::LineTo(original_dc,iVar3,(int)param_1);
    param_1 = DAT_004fb4ac;
    TStack_2c.data = DAT_004f4698;
    fVar10 = FUN_0043ec20((double)(int)DAT_004f4698,(double)(int)DAT_004fb4ac,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_00433a70(original_dc,5,iVar3,param_1);
    CDC::LineTo(original_dc,iVar3,(int)param_1);
    fVar10 = FUN_0043ec20(9722.0,-1026.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fcos(fVar10);
    fVar10 = (float10)fsin(fVar10);
    CDC::LineTo(original_dc,
                (int)(longlong)
                     (fVar10 * (float10)param_4 *
                      (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) + (float10)dStack_1c),
                (int)(longlong)
                     ((float10)dStack_14 -
                     fVar11 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)));
    fVar10 = FUN_0043ec20(-8000.0,-2100.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Annapolis_004ec8a8);
    uStack_4 = 0x21;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-2000.0,4500.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Chesapeake Bay");
    uStack_4 = 0x22;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
  }
  if (DAT_004fb5d4 == 1) {
    fVar10 = FUN_0043ec20(5915.0,-335.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)param_3 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,2);
    FUN_004b0613(&TStack_2c,"Fl R beacon");
    uStack_4 = 0x23;
    pcVar1 = *(code **)(iVar9 + 100);
    (*pcVar1)(original_dc,iVar3 + 10,(int)param_1,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(4971.0,-1380.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,2);
    FUN_004b0613(&TStack_2c,"Fl R buoy");
    uStack_4 = 0x24;
    (*pcVar1)(original_dc,iVar3 + 10,(int)param_1,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(10160.0,-9420.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,3);
    FUN_004b0613(&TStack_2c,s_Fl_G_bell__1BI__004ec87c);
    uStack_4 = 0x25;
    (*pcVar1)(original_dc,iVar3 + 10,(int)param_1 + -0x19,TStack_2c.data,
              *(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(9900.0,-7600.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"reef");
    uStack_4 = 0x26;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11) + 0x14,
              (int)param_1,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(3830.0,5931.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,2);
    FUN_004b0613(&TStack_2c,"Fl R whistle");
    uStack_4 = 0x27;
    (*pcVar1)(original_dc,iVar3 + 10,(int)param_1,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    FUN_004b0613(&TStack_2c,s_Southwest_Pt_004ec864);
    uStack_4 = 0x28;
    (*pcVar1)(original_dc,iVar3 + 0x14,(int)(param_1 + -10),TStack_2c.data,
              *(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(275.0,8820.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,2);
    FUN_004b0613(&TStack_2c,s_Fl_R_bell_004ec858);
    uStack_4 = 0x29;
    (*pcVar1)(original_dc,iVar3 + 10,(int)param_1,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    FUN_004b0613(&TStack_2c,"Southwest Ledge ");
    uStack_4 = 0x2a;
    (*pcVar1)(original_dc,iVar3 + 0x14,(int)(param_1 + -10),TStack_2c.data,
              *(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(6942.0,6600.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a700(original_dc);
    FUN_00471100(original_dc,iVar3,(int)param_1);
    FUN_004b0613(&TStack_2c,s_nun_2_004ec83c);
    uStack_4 = 0x2b;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(13885.0,4670.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a730(original_dc);
    FUN_00471100(original_dc,iVar3,(int)param_1);
    FUN_004b0613(&TStack_2c,s_can_1_004ec834);
    uStack_4 = 0x2c;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(14614.0,2614.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a730(original_dc);
    FUN_00471100(original_dc,iVar3,(int)param_1);
    FUN_004b0613(&TStack_2c,s_can_3_004ec82c);
    uStack_4 = 0x2d;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -0xf,TStack_2c.data,*(int *)(TStack_2c.data + -8)
             );
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(14444.0,-3300.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    param_1 = (int *)(longlong)
                     (fVar11 * (float10)param_4 *
                      (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    iVar3 = (int)(longlong)
                 ((float10)dStack_14 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_00471160(original_dc);
    FUN_00471100(original_dc,(int)param_1,iVar3);
    FUN_004b0613(&TStack_2c,"RW whistle \'NE\'");
    uStack_4 = 0x2e;
    dStack_24 = (double)CONCAT44(dStack_24._4_4_,(int)param_1 + 5);
    (*pcVar1)(original_dc,(int)param_1 + 5,iVar3 + -0xf,TStack_2c.data,*(int *)(TStack_2c.data + -8)
             );
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    (*local_28)(original_dc,0xffff);
    if (DAT_004da1f8 == 5) {
      FUN_004b0613((Tact2010CString *)&param_1,"2nd mark");
      uStack_4 = 0x2f;
      (*pcVar1)(original_dc,(int)dStack_24._0_4_,iVar3,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
  }
  if (DAT_004da1f8 == 7) {
    fVar10 = FUN_0043ec20(333.0,2180.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)param_3 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,3);
    FUN_004b0613(&TStack_2c,"Fl G beacon");
    uStack_4 = 0x30;
    pcVar1 = *(code **)(iVar9 + 100);
    (*pcVar1)(original_dc,iVar3 + 10,(int)param_1,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-41.0,-2126.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,3);
    FUN_004b0613(&TStack_2c,"Fl G beacon");
    uStack_4 = 0x31;
    (*pcVar1)(original_dc,iVar3 + 10,(int)param_1,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(1525.0,1163.0,3,1);
    dStack_24 = (double)fVar10;
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    FUN_004b4a1f(original_dc,2);
    (**(code **)(iVar9 + 0x34))(original_dc,0xff0000);
    fVar10 = (float10)fsin((float10)dStack_24);
    iVar3 = (int)(longlong)
                 (fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos((float10)dStack_24);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,2);
    FUN_004b0613(&TStack_2c,"Fl R buoy");
    uStack_4 = 0x32;
    (*pcVar1)(original_dc,iVar3 + 10,(int)param_1,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    FUN_004b4a1f(original_dc,1);
    fVar10 = FUN_0043ec20(805.0,-1180.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a700(original_dc);
    FUN_00471100(original_dc,iVar3,(int)param_1);
    FUN_004b0613(&TStack_2c,&DAT_004ec9e0);
    uStack_4 = 0x33;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -3,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(2222.0,1589.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b4a1f(original_dc,2);
    FUN_004b0613(&TStack_2c,"shoal");
    uStack_4 = 0x34;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    FUN_004b4a1f(original_dc,1);
    fVar10 = FUN_0043ec20(791.0,2846.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Connecticut River");
    uStack_4 = 0x35;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-2666.0,-174.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Essex_004ec7f8);
    uStack_4 = 0x36;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(1916.0,-112.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Nott_I_004ec7f0);
    uStack_4 = 0x37;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
  }
  if (DAT_004da1f8 == 9) {
    fVar10 = FUN_0043ec20(-3570.0,1390.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)param_3 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,3);
    FUN_004b0613(&TStack_2c,"Fl G beacon");
    pcVar1 = *(code **)(iVar9 + 100);
    uStack_4 = 0x38;
    (*pcVar1)(original_dc,iVar3 + -0x19,(int)param_1 + 5,TStack_2c.data,
              *(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(7815.0,3040.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_00471160(original_dc);
    Rectangle((HDC)original_dc[1],iVar3 + -3,(int)param_1 + -3,iVar3 + 3,(int)param_1 + 3);
    FUN_004b0613(&TStack_2c,s_Ft_Sumter_004ec7e4);
    uStack_4 = 0x39;
    (*pcVar1)(original_dc,iVar3 + -0x19,(int)(param_1 + -5),TStack_2c.data,
              *(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-5000.0,-2480.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Charleston_004ec7d8);
    uStack_4 = 0x3a;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11) + -0x19,
              (int)(param_1 + -5),TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(4100.0,145.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Charleston Harbor");
    uStack_4 = 0x3b;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11) + -0x19,
              (int)(param_1 + -5),TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(2000.0,-3600.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Cooper River");
    uStack_4 = 0x3c;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11) + -0x19,
              (int)(param_1 + -5),TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-6400.0,-630.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Ashley River");
    uStack_4 = 0x3d;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11) + -0x19,
              (int)(param_1 + -5),TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-1125.0,4711.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_James_I_004ec79c);
    uStack_4 = 0x3e;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11) + -0x19,
              (int)(param_1 + -5),TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(9660.0,3250.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Atlantic Ocean");
    uStack_4 = 0x3f;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11) + -0x19,
              (int)(param_1 + -5),TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(270.0,-3200.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Shutes_Folly_I_004ec77c);
    uStack_4 = 0x40;
    (*pcVar1)(original_dc,iVar3,(int)param_1 + -10,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    FUN_004b0613(&TStack_2c,s_Castle_Pinckney_004ec76c);
    uStack_4 = 0x41;
    (*pcVar1)(original_dc,iVar3,(int)param_1 + 6,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
  }
  if (DAT_004da1f8 == 10) {
    fVar10 = FUN_0043ec20(-6000.0,5800.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)param_2;
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)param_3 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Lake_Ontario_004ec75c);
    uStack_4 = 0x42;
    pcVar1 = *(code **)(iVar9 + 100);
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-2670.0,3450.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Simcoe_I_004ec750);
    uStack_4 = 0x43;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(5200.0,-2340.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"St Lawrence River");
    uStack_4 = 0x44;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(2800.0,2500.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Wolfe_I_004ec734);
    uStack_4 = 0x45;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-2700.0,-3300.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Kingston_004ec728);
    uStack_4 = 0x46;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
  }
  if (DAT_004da1f8 == 0xb) {
    fVar10 = FUN_0043ec20(12000.0,9760.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)param_3 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,1);
    FUN_004b4a1f(original_dc,2);
    (**(code **)(iVar9 + 0x34))(original_dc,0xff0000);
    FUN_004b0613(&TStack_2c,"Fowey Rocks lighthouse");
    pcVar1 = *(code **)(iVar9 + 100);
    uStack_4 = 0x47;
    (*pcVar1)(original_dc,iVar3 + -0x5a,(int)param_1 + -0x23,TStack_2c.data,
              *(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    FUN_004b4a1f(original_dc,1);
    fVar10 = FUN_0043ec20(-6060.0,-6723.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Coconut_Grove_004ec700);
    uStack_4 = 0x48;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-8300.0,-3360.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_South_Miami_004ec6f4);
    uStack_4 = 0x49;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-180.0,-5875.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Biscayne Bay");
    uStack_4 = 0x4a;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(6970.0,-3026.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Key_Biscayne_004ec6d4);
    uStack_4 = 0x4b;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(9858.0,3276.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"shoal");
    uStack_4 = 0x4c;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
  }
  if (DAT_004da1f8 == 0xc) {
    fVar10 = FUN_0043ec20(-3770.0,3200.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)param_3 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,2);
    FUN_004b0613(&TStack_2c,"Fl R lighthouse");
    pcVar1 = *(code **)(iVar9 + 100);
    uStack_4 = 0x4d;
    (*pcVar1)(original_dc,iVar3 + -10,(int)param_1 + 10,TStack_2c.data,*(int *)(TStack_2c.data + -8)
             );
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-7500.0,0.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Chicago_004ec6cc);
    uStack_4 = 0x4e;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(3500.0,-1500.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Lake_Michigan_004ec6bc);
    uStack_4 = 0x4f;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
  }
  if (DAT_004da1f8 == 0x67) {
    fVar10 = FUN_0043ec20(2340.0,2740.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)param_2;
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)param_3 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,&DAT_004ec6b8);
    uStack_4 = 0x50;
    pcVar1 = *(code **)(iVar9 + 100);
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(2340.0,3375.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Savannah River");
    uStack_4 = 0x51;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(4100.0,270.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_South_Carolina_004ec698);
    uStack_4 = 0x52;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-5000.0,1210.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Georgia_004ec690);
    uStack_4 = 0x53;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-1200.0,-2260.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Thurmond Lake");
    uStack_4 = 0x54;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
  }
  if (DAT_004da1f8 == 0x69) {
    fVar10 = FUN_0043ec20(-2517.0,-2339.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    piVar4 = (int *)(longlong)
                    ((float10)param_3 -
                    fVar10 * (float10)param_4 *
                    (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    param_1 = piVar4;
    FUN_00469650(original_dc);
    FUN_00433a70(original_dc,5,iVar3,piVar4);
    FUN_004b0613(&TStack_2c,"R&W Radio Tower");
    uStack_4 = 0x55;
    pcVar1 = *(code **)(iVar9 + 100);
    (*pcVar1)(original_dc,iVar3 + 10,(int)param_1,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-2650.0,-1750.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,3);
    FUN_004b0613(&TStack_2c,&DAT_004ec66c);
    uStack_4 = 0x56;
    (*pcVar1)(original_dc,iVar3 + -10,(int)param_1 + 10,TStack_2c.data,*(int *)(TStack_2c.data + -8)
             );
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-2000.0,2850.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,1);
    FUN_004b0613(&TStack_2c,s_Mo__A__004ec664);
    uStack_4 = 0x57;
    (*pcVar1)(original_dc,iVar3 + -10,(int)param_1 + 10,TStack_2c.data,*(int *)(TStack_2c.data + -8)
             );
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-2250.0,-500.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,2);
    FUN_004b0613(&TStack_2c,&DAT_004ec65c);
    uStack_4 = 0x58;
    (*pcVar1)(original_dc,iVar3 + -10,(int)param_1 + 10,TStack_2c.data,*(int *)(TStack_2c.data + -8)
             );
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(1450.0,2050.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,2);
    FUN_004b0613(&TStack_2c,&DAT_004ec65c);
    uStack_4 = 0x59;
    (*pcVar1)(original_dc,iVar3 + -10,(int)param_1 + 10,TStack_2c.data,*(int *)(TStack_2c.data + -8)
             );
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-6750.0,3250.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,1);
    FUN_004b0613(&TStack_2c,"Sand Key Fl Lighthouse");
    uStack_4 = 0x5a;
    (*pcVar1)(original_dc,iVar3 + 8,(int)param_1 + -10,TStack_2c.data,*(int *)(TStack_2c.data + -8))
    ;
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-2000.0,-3100.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Key_West_004ec638);
    uStack_4 = 0x5b;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(3400.0,-3700.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Boca_Chica_Key_004ec628);
    uStack_4 = 0x5c;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(1390.0,-3800.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Stock_I_004ec620);
    uStack_4 = 0x5d;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(2700.0,150.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Hawk Channel");
    uStack_4 = 0x5e;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(2300.0,1830.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Reef");
    uStack_4 = 0x5f;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
  }
  if (DAT_004da1f8 == 100) {
    fVar10 = FUN_0043ec20(-2255.0,-1149.5,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    piVar4 = (int *)(longlong)
                    ((float10)param_3 -
                    fVar10 * (float10)param_4 *
                    (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    param_1 = piVar4;
    FUN_0046a700(original_dc);
    FUN_00471100(original_dc,iVar3,(int)piVar4);
    FUN_004b0613(&TStack_2c,s_nun__2__004ec600);
    pcVar1 = *(code **)(iVar9 + 100);
    uStack_4 = 0x60;
    (*pcVar1)(original_dc,iVar3 + -0x14,(int)param_1 + -0x19,TStack_2c.data,
              *(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(1375.0,5783.8,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    param_1 = (int *)(longlong)
                     (fVar11 * (float10)param_4 *
                      (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    iVar3 = (int)(longlong)
                 ((float10)dStack_14 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_0046a760(original_dc,param_1,iVar3,2);
    FUN_004b0613(&TStack_2c,"Fl R Lighthouse");
    uStack_4 = 0x61;
    dStack_24._0_4_ = (code *)((int)param_1 + -10);
    (*pcVar1)(original_dc,(int)param_1 + -10,iVar3 + 10,TStack_2c.data,*(int *)(TStack_2c.data + -8)
             );
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    FUN_004b0613((Tact2010CString *)&param_1,s_Race_Rock_004ec5e4);
    uStack_4 = 0x62;
    (*pcVar1)(original_dc,(int)dStack_24._0_4_,iVar3 + 0x19,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(-2497.0,-3242.8,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,1);
    (**(code **)(iVar9 + 0x34))(original_dc,0xff0000);
    FUN_004b4a1f(original_dc,2);
    FUN_004b0613(&TStack_2c,"Fl W Lighthouse");
    uStack_4 = 99;
    (*pcVar1)(original_dc,iVar3 + -0x3c,(int)param_1 + 10,TStack_2c.data,
              *(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    FUN_004b4a1f(original_dc,1);
    fVar10 = FUN_0043ec20(-200.0,-3300.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"reef");
    uStack_4 = 100;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-7150.0,-786.5,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a730(original_dc);
    FUN_00471100(original_dc,iVar3,(int)param_1);
    FUN_004b0613(&TStack_2c,s_can__3__004ec5cc);
    uStack_4 = 0x65;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + -0xf,TStack_2c.data,*(int *)(TStack_2c.data + -8)
             );
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20((double)DAT_00535220,(double)DAT_004f4b60,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    param_1 = (int *)(longlong)
                     (fVar11 * (float10)param_4 *
                      (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    iVar3 = (int)(longlong)
                 ((float10)dStack_14 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_0046a760(original_dc,param_1,iVar3,1);
    FUN_004b0613(&TStack_2c,"F W Lighthouse");
    uStack_4 = 0x66;
    dStack_24 = (double)CONCAT44(dStack_24._4_4_,(int)param_1 + 10);
    (*pcVar1)(original_dc,(int)param_1 + 10,iVar3 + -0xf,TStack_2c.data,
              *(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    FUN_004b0613((Tact2010CString *)&param_1,s_North_Dumpling_004ec5ac);
    uStack_4 = 0x67;
    (*pcVar1)(original_dc,(int)dStack_24._0_4_,iVar3,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(3300.0,-1815.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,1);
    FUN_004b0613(&TStack_2c,"Fl W  Seaflower Reef");
    uStack_4 = 0x68;
    (*pcVar1)(original_dc,iVar3 + 10,(int)param_1 + -10,TStack_2c.data,*(int *)(TStack_2c.data + -8)
             );
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-8100.0,-7000.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_New_London_004ec588);
    uStack_4 = 0x69;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-1400.0,-7700.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Groton_004ec580);
    uStack_4 = 0x6a;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-5000.0,-6820.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Thames_004ec578);
    uStack_4 = 0x6b;
    (*pcVar1)(original_dc,iVar3,(int)param_1 + -0xf,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    FUN_004b0613(&TStack_2c,s_River_004ec570);
    uStack_4 = 0x6c;
    (*pcVar1)(original_dc,iVar3,(int)param_1,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-5560.0,4200.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Long Island Sound");
    uStack_4 = 0x6d;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(4500.0,3300.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Fishers_I_004ec550);
    uStack_4 = 0x6e;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(4700.0,-3100.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Fishers I Sound");
    uStack_4 = 0x6f;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
  }
  if (DAT_004da1f8 == 0x6a) {
    fVar10 = FUN_0043ec20(-850.0,-2298.4,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)param_3 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_0046a760(original_dc,iVar3,param_1,2);
    FUN_004b0613(&TStack_2c,&DAT_004ec65c);
    pcVar1 = *(code **)(iVar9 + 100);
    uStack_4 = 0x70;
    (*pcVar1)(original_dc,iVar3 + 5,(int)param_1 + 10,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(8160.0,265.2,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    param_1 = (int *)(longlong)
                     (fVar11 * (float10)param_4 *
                      (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88) + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    iVar3 = (int)(longlong)
                 ((float10)dStack_14 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_0046a760(original_dc,param_1,iVar3,1);
    FUN_004b0613(&TStack_2c,&DAT_004ec3b0);
    uStack_4 = 0x71;
    dStack_24 = (double)CONCAT44(dStack_24._4_4_,(int)param_1 + -0x23);
    (*pcVar1)(original_dc,(int)param_1 + -0x23,iVar3 + 10,TStack_2c.data,
              *(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    FUN_004b0613((Tact2010CString *)&param_1,"Porgee Rocks");
    uStack_4 = 0x72;
    (*pcVar1)(original_dc,(int)dStack_24._0_4_,iVar3 + 0x19,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(-8000.0,0.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Nassau_004ec528);
    uStack_4 = 0x73;
    (*pcVar1)(original_dc,iVar3,(int)param_1,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    FUN_004b0613(&TStack_2c,s_New_Providence_I_004ec514);
    uStack_4 = 0x74;
    (*pcVar1)(original_dc,iVar3,(int)param_1 + 0x32,TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-4200.0,-700.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,"Montagu Bay");
    uStack_4 = 0x75;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(-6800.0,-3560.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Paradise_I_004ec4fc);
    uStack_4 = 0x76;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
    fVar10 = FUN_0043ec20(2100.0,-2600.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar12 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar10 = (float10)fcos(fVar10);
    param_1 = (int *)(longlong)
                     ((float10)dStack_14 -
                     fVar10 * (float10)param_4 *
                     (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88));
    FUN_004b0613(&TStack_2c,s_Athol_I_004ec4f4);
    uStack_4 = 0x77;
    (*pcVar1)(original_dc,(int)(longlong)(fVar12 * fVar2 * (float10)dVar6 + fVar11),(int)param_1,
              TStack_2c.data,*(int *)(TStack_2c.data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5(&TStack_2c);
  }
  if (DAT_004da1f8 == 0x66) {
    fVar10 = FUN_0043ec20(-3425.5,-4441.250000000001,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    iVar5 = (int)(longlong)
                 ((float10)param_3 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_0046a730(original_dc);
    FUN_00471100(original_dc,iVar3,iVar5);
    FUN_004b0613((Tact2010CString *)&param_1,&DAT_004ec954);
    uStack_4 = 0x78;
    dStack_24 = (double)CONCAT44(dStack_24._4_4_,*(code **)(iVar9 + 100));
    (**(code **)(iVar9 + 100))(original_dc,iVar3 + 8,iVar5 + -10,(char *)param_1,param_1[-2]);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(2295.0,-2431.0000000000005,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    iVar5 = (int)(longlong)
                 ((float10)dStack_14 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_0046a730(original_dc);
    FUN_00471100(original_dc,iVar3,iVar5);
    FUN_004b0613((Tact2010CString *)&param_1,&DAT_004ec954);
    uStack_4 = 0x79;
    pcVar8 = FUN_004710c0((Tact2010CString *)&param_1);
    iVar9 = *(int *)(pcVar8 + 4);
    pcVar8 = FUN_004710d0((Tact2010CString *)&param_1);
    (*dStack_24._0_4_)(original_dc,iVar3 + 8,iVar5 + -10,pcVar8,iVar9);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(3332.0,-467.50000000000006,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar9 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    iVar3 = (int)(longlong)
                 ((float10)dStack_14 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_0046a760(original_dc,iVar9,iVar3,2);
    FUN_004b0613((Tact2010CString *)&param_1,s_FL_R__2__004ec4e8);
    uStack_4 = 0x7a;
    FUN_004710e0(original_dc,iVar9 + 5,iVar3 + 10,(Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(-850.0,-3459.5000000000005,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar9 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    iVar3 = (int)(longlong)
                 ((float10)dStack_14 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_0046a730(original_dc);
    FUN_00471100(original_dc,iVar9,iVar3);
    FUN_004b0613((Tact2010CString *)&param_1,&DAT_004ec9dc);
    uStack_4 = 0x7b;
    FUN_004710e0(original_dc,iVar9 + -8,iVar3 + -0x14,(Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(-80.0,4100.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_1,s_Edgartown_004ec4dc);
    uStack_4 = 0x7c;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7),
                 (Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(-4900.0,4800.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_1,"Martha\'s Vineyard");
    uStack_4 = 0x7d;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7),
                 (Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(3150.0,-3080.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_1,"Nantucket Sound");
    uStack_4 = 0x7e;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7),
                 (Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004da1f8 == 0x65) {
    fVar10 = FUN_0043ec20(-2887.5,-1478.4,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar9 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    iVar3 = (int)(longlong)
                 ((float10)param_3 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_0046a760(original_dc,iVar9,iVar3,2);
    FUN_004b0613((Tact2010CString *)&param_1,"breakwater");
    uStack_4 = 0x7f;
    FUN_004710e0(original_dc,iVar9,iVar3 + -0x23,(Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,&DAT_004ec65c);
    uStack_4 = 0x80;
    FUN_004710e0(original_dc,iVar9 + 10,iVar3 + -0x14,(Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(-3675.0,-346.5,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    fVar10 = (float10)fcos(fVar10);
    iVar9 = (int)(longlong)
                 ((float10)dStack_14 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    iVar3 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    FUN_0046a760(original_dc,iVar3,iVar9,1);
    FUN_004b0613((Tact2010CString *)&param_1,&DAT_004ec3b0);
    uStack_4 = 0x81;
    FUN_004710e0(original_dc,iVar3,iVar9 + -0x23,(Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(-3780.0,4042.5,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar9 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    iVar3 = (int)(longlong)
                 ((float10)dStack_14 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_0046a760(original_dc,iVar9,iVar3,1);
    FUN_004b0613((Tact2010CString *)&param_1,"Fl W Lighthouse");
    iVar9 = iVar9 + -0x28;
    uStack_4 = 0x82;
    FUN_004710e0(original_dc,iVar9,iVar3 + -0x23,(Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    FUN_004b0613((Tact2010CString *)&param_1,"Execution Rocks");
    uStack_4 = 0x83;
    FUN_004710e0(original_dc,iVar9,iVar3 + -0x14,(Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(8925.0,-2310.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar9 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    iVar3 = (int)(longlong)
                 ((float10)dStack_14 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_0046a760(original_dc,iVar9,iVar3,2);
    FUN_004b0613((Tact2010CString *)&param_1,&DAT_004ec65c);
    uStack_4 = 0x84;
    FUN_004710e0(original_dc,iVar9 + 10,iVar3 + -10,(Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(693.0,-2379.3,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar9 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    iVar3 = (int)(longlong)
                 ((float10)dStack_14 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_0046a760(original_dc,iVar9,iVar3,2);
    FUN_004b0613((Tact2010CString *)&param_1,s_Fl_R__42__004ec490);
    uStack_4 = 0x85;
    FUN_004710e0(original_dc,iVar9 + 10,iVar3 + -0xf,(Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(-5800.0,-4800.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_1,s_Larchmont_004ec484);
    uStack_4 = 0x86;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7),
                 (Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(4000.0,-3500.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_1,"Long Island Sound");
    uStack_4 = 0x87;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7),
                 (Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(8300.0,3800.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_1,s_Long_Island_004ec478);
    uStack_4 = 0x88;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7),
                 (Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(-8000.0,430.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_1,s_New_Rochelle_004ec468);
    uStack_4 = 0x89;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7),
                 (Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(-3000.0,-6550.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_1,s_Mamaroneck_004ec45c);
    uStack_4 = 0x8a;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7),
                 (Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(-2700.0,4020.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_1,s_Sands_Pt_004ec450);
    uStack_4 = 0x8b;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7),
                 (Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(3800.0,5450.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_1,"Hempstead Harbor");
    uStack_4 = 0x8c;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7),
                 (Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(1680.0,-4700.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_1,s_Peningo_Neck_004ec42c);
    uStack_4 = 0x8d;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7),
                 (Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(8900.0,-1600.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_1,s_Matinecock_Pt_004ec41c);
    uStack_4 = 0x8e;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7),
                 (Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
    fVar10 = FUN_0043ec20(-5000.0,-650.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_1,"reef");
    uStack_4 = 0x8f;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7),
                 (Tact2010CString *)&param_1);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  if (DAT_004da1f8 == 0x68) {
    fVar10 = FUN_0043ec20(-1724.9999999999998,675.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    dStack_1c = (double)param_2;
    fVar11 = (float10)fsin(fVar10);
    iVar9 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)param_2);
    dStack_14 = (double)param_3;
    fVar10 = (float10)fcos(fVar10);
    iVar3 = (int)(longlong)
                 ((float10)param_3 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_0046a760(original_dc,iVar9,iVar3,3);
    FUN_004b0613((Tact2010CString *)&param_2,s_Fl_G__S__004ec410);
    uStack_4 = 0x90;
    FUN_004710e0(original_dc,iVar9 + -0x32,iVar3 + 0xb,(Tact2010CString *)&param_2);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
    fVar10 = FUN_0043ec20(-1875.0,2550.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar9 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    iVar3 = (int)(longlong)
                 ((float10)dStack_14 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_0046a760(original_dc,iVar9,iVar3,3);
    FUN_004b0613((Tact2010CString *)&param_2,s_Fl_G__9__004ec404);
    uStack_4 = 0x91;
    FUN_004710e0(original_dc,iVar9 + -0x32,iVar3 + -0x14,(Tact2010CString *)&param_2);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
    fVar10 = FUN_0043ec20(1687.5,1425.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar11 = (float10)fsin(fVar10);
    iVar9 = (int)(longlong)
                 (fVar11 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)
                 + (float10)dStack_1c);
    fVar10 = (float10)fcos(fVar10);
    iVar3 = (int)(longlong)
                 ((float10)dStack_14 -
                 fVar10 * (float10)param_4 * (float10)(double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88))
    ;
    FUN_0046a760(original_dc,iVar9,iVar3,1);
    FUN_004b0613((Tact2010CString *)&param_2,&DAT_004ec400);
    uStack_4 = 0x92;
    FUN_004710e0(original_dc,iVar9 + 10,iVar3 + 10,(Tact2010CString *)&param_2);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
    fVar10 = FUN_0043ec20(-3200.0,-780.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_2,s_Municipal_Pier_004ec3f0);
    uStack_4 = 0x93;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7) + -10,
                 (Tact2010CString *)&param_2);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
    fVar10 = FUN_0043ec20(-3400.0,-1500.0,3,1);
    if (_DAT_004ccd88 < (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88)) {
      _DAT_004fbb88 = 0;
      _DAT_004fbb8c = 0x40d86a00;
    }
    fVar13 = (float10)fsin(fVar10);
    fVar2 = (float10)param_4;
    dVar6 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar11 = (float10)dStack_1c;
    fVar14 = (float10)fcos(fVar10);
    fVar10 = (float10)param_4;
    dVar7 = (double)CONCAT44(_DAT_004fbb8c,_DAT_004fbb88);
    fVar12 = (float10)dStack_14;
    FUN_004b0613((Tact2010CString *)&param_2,s_St_Petersburg_004ec3e0);
    uStack_4 = 0x94;
    FUN_004710e0(original_dc,(int)(longlong)(fVar13 * fVar2 * (float10)dVar6 + fVar11),
                 (int)(longlong)(fVar12 - fVar14 * fVar10 * (float10)dVar7),
                 (Tact2010CString *)&param_2);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
    FUN_004b0613((Tact2010CString *)&param_2,"Tampa Bay");
    uStack_4 = 0x95;
    FUN_004710e0(original_dc,(DAT_004fe624 * 5) / 6,(DAT_004fe2a8 * 2) / 5,
                 (Tact2010CString *)&param_2);
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  FUN_004b4a1f(original_dc,2);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

