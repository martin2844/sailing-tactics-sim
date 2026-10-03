
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041a5d0(CDC *param_1,int param_2,int param_3,uint param_4,int param_5,int param_6)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_80;
  code *local_7c [2];
  int local_74;
  int local_70;
  undefined4 local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  int local_38 [2];
  int local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14 [2];
  int local_c;
  int local_8 [2];
  
  if ((((DAT_00491188 == 3) || (DAT_004ac908 == 1)) || (DAT_004ac900 == 1)) && (param_6 != 1)) {
    FUN_00416ad0((int *)param_1,param_2,param_3,param_4,param_5,param_6);
  }
  iVar4 = 0;
  if ((int)param_4 <= DAT_00491140) {
    if (10 < *(int *)(&DAT_004ac5f0 + param_4 * 4)) {
      iVar4 = FUN_00415a20(0xc);
      iVar4 = iVar4 + 6;
    }
    if (0x1e < *(int *)(&DAT_004ac5f0 + param_4 * 4)) {
      iVar4 = FUN_00415a20(0x18);
      iVar4 = iVar4 + 0x11;
    }
  }
  iVar2 = DAT_004aa224;
  if (((DAT_00491150 == 100) || (DAT_00491188 == 8)) || ((DAT_004ac908 == 1 || (DAT_004ac90c == 1)))
     ) {
    dVar1 = (double)CONCAT44(param_3,param_2) * _DAT_00484fc0;
    local_6c = DAT_004aa1f4;
    if (DAT_00491188 == 8) {
      dVar1 = dVar1 * _DAT_00484fc8;
    }
    iVar3 = (int)(longlong)(dVar1 * _DAT_00484fe0);
    local_80 = DAT_004aa2f4;
  }
  else {
    dVar1 = (double)CONCAT44(param_3,param_2) * _DAT_00484f58;
    local_6c = DAT_004aa1f0;
    iVar3 = (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00485080);
    local_80 = DAT_004aa2f0;
  }
  local_80 = local_80 - iVar3;
  if (DAT_004ac900 == 1) {
    dVar1 = dVar1 * _DAT_00484fd0;
    local_80 = DAT_004aa2f0 - (int)(longlong)(dVar1 * _DAT_00484fe0);
  }
  else if ((DAT_004ac908 != 1) && (DAT_004ac90c != 1)) {
    local_60 = DAT_004aa20c;
    local_64 = DAT_004aa30c - (int)(longlong)(dVar1 * _DAT_00484d48);
    goto LAB_0041a782;
  }
  local_60 = DAT_004aaeb0;
  local_64 = DAT_004ab8c0;
LAB_0041a782:
  local_44 = DAT_004aa210;
  local_1c = (int)(longlong)(dVar1 * _DAT_00484d90);
  iVar3 = iVar4 / 2;
  local_40 = (DAT_004aa310 + iVar3) - local_1c;
  local_70 = DAT_004aa214;
  local_68 = (int)(longlong)(dVar1 * _DAT_00484da8);
  local_74 = (iVar4 + DAT_004aa314) - local_68;
  local_3c = DAT_004aa218;
  local_24 = (int)(longlong)(dVar1 * _DAT_00484ec8);
  local_4c = iVar4 - local_24;
  local_38[0] = DAT_004aa318 + local_4c;
  local_5c = DAT_004aa21c;
  local_14[0] = (int)(longlong)(dVar1 * _DAT_00484d48);
  local_58 = (DAT_004aa31c + iVar3) - local_14[0];
  local_54 = DAT_004aa220;
  iVar3 = (DAT_004aa320 - (int)(longlong)(dVar1 * _DAT_00485070)) + iVar3;
  iVar4 = (iVar4 - (int)(longlong)(dVar1 * _DAT_00484f78)) + DAT_004aa324;
  local_50 = DAT_004aa228;
  local_4c = DAT_004aa328 + local_4c;
  local_18 = DAT_004aa22c;
  local_14[0] = DAT_004aa32c - local_14[0];
  local_20 = DAT_004aa230;
  local_1c = DAT_004aa330 - local_1c;
  local_48 = DAT_004aa234;
  local_68 = DAT_004aa334 - local_68;
  local_28 = DAT_004aa238;
  local_24 = DAT_004aa338 - local_24;
  local_c = (int)(longlong)(dVar1 * _DAT_00485030);
  if (param_6 == 0) {
    local_c = local_c / 2;
  }
  local_2c = (DAT_004aa224 + DAT_004aa214) / 2;
  local_30 = (local_74 + iVar4) / 2 - local_c;
  local_8[0] = (DAT_004aa234 + DAT_004aa224) / 2;
  local_c = (local_68 + iVar4) / 2 - local_c;
  if (((DAT_004ac900 == 0) && (DAT_004ac908 == 0)) && (DAT_004ac90c == 0)) {
    if (DAT_004ac13c < param_5) {
      if (DAT_004a4dec != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
      }
    }
    else {
      (**(code **)(*(int *)param_1 + 0x2c))(param_1,7);
    }
    FUN_004706bd(param_1,(int *)local_7c,DAT_004aa1e4,
                 DAT_004aa2e4 - (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00485088));
    CDC::LineTo(param_1,local_60,local_64);
  }
  FUN_0041af70((int *)param_1,param_4);
  local_7c[0] = *(code **)(*(int *)param_1 + 0x2c);
  (*local_7c[0])(param_1,7);
  if (param_6 == 1) {
    _DAT_004a4ca8 = local_5c;
    _DAT_004a4cac = local_58;
    _DAT_004a4cb0 = local_54;
    _DAT_004a4cc0 = local_50;
    _DAT_004a4cc4 = local_4c;
    _DAT_004a4cc8 = local_6c;
    _DAT_004a4ccc = local_80;
    _DAT_004a4cd0 = local_28;
    _DAT_004a4cd4 = local_24;
    _DAT_004a4cd8 = local_48;
    _DAT_004a4cdc = local_68;
    _DAT_004a4ce0 = local_20;
    _DAT_004a4cb8 = iVar2;
    _DAT_004a4ce4 = local_1c;
    _DAT_004a4ce8 = local_18;
    _DAT_004a4cec = local_14[0];
    _DAT_004a4cb4 = iVar3;
    _DAT_004a4cbc = iVar4;
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,9);
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
    }
    FUN_004706bd(param_1,local_14,local_48,local_68);
    CDC::LineTo(param_1,local_8[0],local_c);
    CDC::LineTo(param_1,iVar2,iVar4);
    (*local_7c[0])(param_1,7);
    _DAT_004a4ca8 = local_60;
    _DAT_004a4cac = local_64;
    _DAT_004a4cb0 = local_44;
    _DAT_004a4cb4 = local_40;
    _DAT_004a4cb8 = local_70;
    _DAT_004a4cbc = local_74;
    _DAT_004a4cc0 = local_3c;
    _DAT_004a4cc4 = local_38[0];
    _DAT_004a4cc8 = local_6c;
    _DAT_004a4ccc = local_80;
    _DAT_004a4cd0 = local_50;
    _DAT_004a4cd4 = local_4c;
    _DAT_004a4cd8 = iVar2;
    _DAT_004a4ce0 = local_54;
    _DAT_004a4ce8 = local_5c;
    _DAT_004a4cec = local_58;
    _DAT_004a4cdc = iVar4;
    _DAT_004a4ce4 = iVar3;
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,9);
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
    }
    FUN_004706bd(param_1,local_8,local_70,local_74);
    iVar3 = local_2c;
    iVar5 = local_30;
  }
  else {
    _DAT_004a4cac = local_64;
    _DAT_004a4ca8 = local_60;
    _DAT_004a4cb0 = local_44;
    _DAT_004a4cb8 = local_70;
    _DAT_004a4cb4 = local_40;
    _DAT_004a4cbc = local_74;
    _DAT_004a4cc4 = local_38[0];
    _DAT_004a4cc0 = local_3c;
    _DAT_004a4cc8 = local_6c;
    _DAT_004a4cd0 = local_50;
    _DAT_004a4ccc = local_80;
    _DAT_004a4cd4 = local_4c;
    _DAT_004a4ce8 = local_5c;
    _DAT_004a4cd8 = iVar2;
    _DAT_004a4ce0 = local_54;
    _DAT_004a4cec = local_58;
    _DAT_004a4cdc = iVar4;
    _DAT_004a4ce4 = iVar3;
    (*local_7c[0])(param_1,7);
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,9);
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
    }
    FUN_004706bd(param_1,local_38,local_70,local_74);
    CDC::LineTo(param_1,local_2c,local_30);
    CDC::LineTo(param_1,iVar2,iVar4);
    (*local_7c[0])(param_1,7);
    iVar5 = local_48;
    _DAT_004a4ca8 = local_5c;
    _DAT_004a4cac = local_58;
    _DAT_004a4cb0 = local_54;
    _DAT_004a4cc0 = local_50;
    _DAT_004a4cc4 = local_4c;
    _DAT_004a4cc8 = local_6c;
    _DAT_004a4ccc = local_80;
    _DAT_004a4cd0 = local_28;
    _DAT_004a4cd4 = local_24;
    _DAT_004a4cdc = local_68;
    _DAT_004a4ce0 = local_20;
    _DAT_004a4cb8 = iVar2;
    _DAT_004a4cd8 = local_48;
    _DAT_004a4ce4 = local_1c;
    _DAT_004a4ce8 = local_18;
    _DAT_004a4cec = local_14[0];
    _DAT_004a4cb4 = iVar3;
    _DAT_004a4cbc = iVar4;
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,9);
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
    }
    FUN_004706bd(param_1,local_14,iVar5,local_68);
    iVar3 = local_8[0];
    iVar5 = local_c;
  }
  CDC::LineTo(param_1,iVar3,iVar5);
  CDC::LineTo(param_1,iVar2,iVar4);
  (*local_7c[0])(param_1,7);
  if (((DAT_00491188 == 3) || (DAT_004ac908 == 1)) || (DAT_004ac900 == 1)) {
    if (param_6 == 1) {
      FUN_00416ad0((int *)param_1,param_2,param_3,param_4,param_5,1);
    }
    if (((DAT_00491188 == 3) && (DAT_004ac90c == 0)) && (param_6 == 1)) {
      if (DAT_004ac13c < param_5) {
        if (DAT_004a4dec != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
        }
      }
      else {
        (*local_7c[0])(7);
      }
      FUN_004706bd(param_1,local_8,DAT_004aa1e4,
                   DAT_004aa2e4 - (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00485088)
                  );
      CDC::LineTo(param_1,local_60,local_64);
    }
  }
  return;
}

