
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041a5d0(CDC *param_1,int param_2,int param_3,uint param_4,int param_5,int param_6)

{
  double dVar1;
  int iVar2;
  int iVar3;
  code *unaff_EBX;
  int iVar4;
  code *unaff_EBP;
  int iVar5;
  code *pcVar6;
  int unaff_retaddr;
  code *local_80;
  code *local_7c;
  int iStack_78;
  int local_74;
  code *local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  int iStack_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int iStack_10;
  int local_c;
  int local_8;
  undefined4 uStack_4;
  
  if ((((DAT_00491188 == 3) || (DAT_004ac908 == 1)) || (DAT_004ac900 == 1)) && (param_6 != 1)) {
    FUN_00416ad0((int *)param_1,param_2,param_3,param_4,param_5,param_6);
  }
  iVar5 = 0;
  if ((int)param_4 <= DAT_00491140) {
    if (10 < *(int *)(&DAT_004ac5f0 + param_4 * 4)) {
      iVar5 = FUN_00415a20(0xc);
      iVar5 = iVar5 + 6;
    }
    if (0x1e < *(int *)(&DAT_004ac5f0 + param_4 * 4)) {
      iVar5 = FUN_00415a20(0x18);
      iVar5 = iVar5 + 0x11;
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
    iVar4 = (int)(longlong)(dVar1 * _DAT_00484fe0);
    iVar3 = DAT_004aa2f4;
  }
  else {
    dVar1 = (double)CONCAT44(param_3,param_2) * _DAT_00484f58;
    local_6c = DAT_004aa1f0;
    iVar4 = (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00485080);
    iVar3 = DAT_004aa2f0;
  }
  local_80 = (code *)(iVar3 - iVar4);
  if (DAT_004ac900 == 1) {
    dVar1 = dVar1 * _DAT_00484fd0;
    local_80 = (code *)(DAT_004aa2f0 - (int)(longlong)(dVar1 * _DAT_00484fe0));
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
  iVar4 = iVar5 / 2;
  local_40 = (DAT_004aa310 + iVar4) - local_1c;
  local_70 = DAT_004aa214;
  local_68 = (int)(longlong)(dVar1 * _DAT_00484da8);
  local_74 = (iVar5 + DAT_004aa314) - local_68;
  local_3c = DAT_004aa218;
  local_24 = (int)(longlong)(dVar1 * _DAT_00484ec8);
  local_4c = iVar5 - local_24;
  local_38 = DAT_004aa318 + local_4c;
  local_5c = DAT_004aa21c;
  local_14 = (int)(longlong)(dVar1 * _DAT_00484d48);
  local_58 = (DAT_004aa31c + iVar4) - local_14;
  local_54 = DAT_004aa220;
  iVar4 = (DAT_004aa320 - (int)(longlong)(dVar1 * _DAT_00485070)) + iVar4;
  pcVar6 = (code *)((iVar5 - (int)(longlong)(dVar1 * _DAT_00484f78)) + DAT_004aa324);
  local_50 = DAT_004aa228;
  local_4c = DAT_004aa328 + local_4c;
  local_18 = DAT_004aa22c;
  local_14 = DAT_004aa32c - local_14;
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
  local_2c = (int)(DAT_004aa214 + DAT_004aa224) / 2;
  local_30 = (int)(pcVar6 + local_74) / 2 - local_c;
  local_8 = (DAT_004aa234 + DAT_004aa224) / 2;
  local_c = (int)(pcVar6 + local_68) / 2 - local_c;
  if (((DAT_004ac900 == 0) && (DAT_004ac908 == 0)) && (DAT_004ac90c == 0)) {
    if (DAT_004ac13c < param_5) {
      if (DAT_004a4dec != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
      }
    }
    else {
      (**(code **)(*(int *)param_1 + 0x2c))(7);
    }
    FUN_004706bd(param_1,(int *)&local_7c,DAT_004aa1e4,
                 DAT_004aa2e4 - (int)(longlong)((double)CONCAT44(param_3,param_2) * _DAT_00485088));
    CDC::LineTo(param_1,local_60,local_64);
  }
  FUN_0041af70((int *)param_1,param_4);
  local_7c = *(code **)(*(int *)param_1 + 0x2c);
  (*local_7c)(7);
  _DAT_004a4ccc = unaff_EBP;
  if (param_5 == 1) {
    _DAT_004a4ca8 = local_60;
    _DAT_004a4cac = local_5c;
    _DAT_004a4cb0 = local_58;
    _DAT_004a4cc0 = local_54;
    _DAT_004a4cc4 = local_50;
    _DAT_004a4cc8 = local_70;
    _DAT_004a4cd0 = local_2c;
    _DAT_004a4cd4 = local_28;
    _DAT_004a4cd8 = local_4c;
    _DAT_004a4cdc = (code *)local_6c;
    _DAT_004a4ce0 = local_24;
    _DAT_004a4cb8 = iVar2;
    _DAT_004a4ce4 = local_20;
    _DAT_004a4ce8 = local_1c;
    _DAT_004a4cec = local_18;
    _DAT_004a4cb4 = iVar4;
    _DAT_004a4cbc = pcVar6;
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,9);
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
    }
    FUN_004706bd(param_1,&local_18,local_4c,local_6c);
    CDC::LineTo(param_1,local_c,iStack_10);
    CDC::LineTo(param_1,iVar2,(int)pcVar6);
    (*local_80)(7);
    _DAT_004a4ca8 = local_68;
    _DAT_004a4cac = local_6c;
    _DAT_004a4cb0 = local_4c;
    _DAT_004a4cb4 = local_48;
    _DAT_004a4cb8 = iStack_78;
    _DAT_004a4cbc = local_7c;
    _DAT_004a4cc0 = local_44;
    _DAT_004a4cc4 = local_40;
    _DAT_004a4cc8 = (code *)local_74;
    _DAT_004a4cd0 = local_58;
    _DAT_004a4cd4 = local_54;
    _DAT_004a4cd8 = iVar2;
    _DAT_004a4ce0 = local_5c;
    _DAT_004a4ce8 = local_64;
    _DAT_004a4cec = local_60;
    _DAT_004a4cdc = pcVar6;
    _DAT_004a4ce4 = iVar4;
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,9);
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
    }
    FUN_004706bd(param_1,&iStack_10,iStack_78,(int)local_7c);
    iVar5 = local_38;
  }
  else {
    _DAT_004a4cac = local_68;
    _DAT_004a4ca8 = local_64;
    _DAT_004a4cb0 = local_48;
    _DAT_004a4cb8 = local_74;
    _DAT_004a4cb4 = local_44;
    _DAT_004a4cbc = (code *)iStack_78;
    _DAT_004a4cc4 = local_3c;
    _DAT_004a4cc0 = local_40;
    _DAT_004a4cc8 = local_70;
    _DAT_004a4cd0 = local_54;
    _DAT_004a4cd4 = local_50;
    _DAT_004a4ce8 = local_60;
    _DAT_004a4cd8 = iVar2;
    _DAT_004a4ce0 = local_58;
    _DAT_004a4cec = local_5c;
    _DAT_004a4cdc = pcVar6;
    _DAT_004a4ce4 = iVar4;
    (*local_80)(7);
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,9);
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
    }
    FUN_004706bd(param_1,&local_40,iStack_78,(int)local_7c);
    CDC::LineTo(param_1,iStack_34,local_38);
    CDC::LineTo(param_1,iVar2,(int)pcVar6);
    (*unaff_EBX)(7);
    iVar5 = local_50;
    _DAT_004a4ca8 = local_64;
    _DAT_004a4cac = local_60;
    _DAT_004a4cb0 = local_5c;
    _DAT_004a4cc0 = local_58;
    _DAT_004a4cc4 = local_54;
    _DAT_004a4cc8 = (code *)local_74;
    _DAT_004a4cd0 = local_30;
    _DAT_004a4cd4 = local_2c;
    _DAT_004a4cdc = local_70;
    _DAT_004a4ce0 = local_28;
    _DAT_004a4cb8 = iVar2;
    _DAT_004a4cd8 = local_50;
    _DAT_004a4ce4 = local_24;
    _DAT_004a4ce8 = local_20;
    _DAT_004a4cec = local_1c;
    _DAT_004a4cb4 = iVar4;
    _DAT_004a4cbc = pcVar6;
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,9);
    if (DAT_004a4dec != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
    }
    FUN_004706bd(param_1,&local_1c,iVar5,(int)local_70);
    iStack_34 = iStack_10;
    iVar5 = local_14;
  }
  CDC::LineTo(param_1,iStack_34,iVar5);
  CDC::LineTo(param_1,iVar2,(int)pcVar6);
  (*unaff_EBX)(7);
  if (((DAT_00491188 == 3) || (DAT_004ac908 == 1)) || (DAT_004ac900 == 1)) {
    if (param_3 == 1) {
      FUN_00416ad0((int *)param_1,uStack_4,unaff_retaddr,(int)param_1,param_2,1);
    }
    if (((DAT_00491188 == 3) && (DAT_004ac90c == 0)) && (param_3 == 1)) {
      if (DAT_004ac13c < param_2) {
        if (DAT_004a4dec != (HGDIOBJ)0x0) {
          SelectObject(*(HDC *)(param_1 + 4),DAT_004a4dec);
        }
      }
      else {
        (*unaff_EBP)(7);
      }
      FUN_004706bd(param_1,&local_14,DAT_004aa1e4,
                   DAT_004aa2e4 -
                   (int)(longlong)((double)CONCAT44(unaff_retaddr,uStack_4) * _DAT_00485088));
      CDC::LineTo(param_1,local_6c,(int)local_70);
    }
  }
  return;
}

