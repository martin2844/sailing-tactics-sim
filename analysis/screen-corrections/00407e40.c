
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00407e40(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  HDC hdc;
  code *pcVar1;
  int this;
  int left;
  HRGN h;
  HGDIOBJ h_00;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc_00;
  HGDIOBJ h_01;
  COLORREF CVar5;
  double dStack_14;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  left = param_2;
  this = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_0047d6e0;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  hdc = *(HDC *)(param_1 + 4);
  h = CreateRectRgn(param_2,param_3,param_4,param_5);
  h_00 = SelectObject(hdc,h);
  pcVar1 = *(code **)(*(int *)this + 0x2c);
  (*pcVar1)((void *)this,7);
  (*pcVar1)((void *)this,7);
  if ((DAT_004ac92c == 0) && (DAT_004ac98c == 0)) {
    if (DAT_004aa714 != (HGDIOBJ)0x0) {
      hdc_00 = *(HDC *)(this + 4);
      h_01 = DAT_004aa714;
LAB_00407ef0:
      SelectObject(hdc_00,h_01);
    }
  }
  else if (DAT_004aa7f4 != (HGDIOBJ)0x0) {
    hdc_00 = *(HDC *)(this + 4);
    h_01 = DAT_004aa7f4;
    goto LAB_00407ef0;
  }
  iVar4 = param_7;
  if (DAT_004ac98c == 1) {
    if (param_7 < 1) goto LAB_00407fa3;
    if ((param_7 < 3) && (DAT_004aa7f4 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(this + 4),DAT_004aa7f4);
    }
  }
  if (iVar4 == 1) {
    if ((((param_6 == 1) && (0 < DAT_004aa62c)) && (DAT_004a8664 == 2)) &&
       (DAT_004a5b8c != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(this + 4),DAT_004a5b8c);
    }
    if (((param_6 == 2) && (0 < DAT_004aa638)) &&
       ((DAT_004a8668 == 2 && (DAT_004a5b8c != (HGDIOBJ)0x0)))) {
      SelectObject(*(HDC *)(this + 4),DAT_004a5b8c);
    }
  }
LAB_00407fa3:
  Rectangle(*(HDC *)(this + 4),left,param_3,param_4,param_5);
  iVar2 = param_7;
  iVar3 = param_7;
  if (iVar4 == 1) {
    iVar2 = (param_4 * 5 + left * 4) / 9;
    iVar3 = (param_5 * 5 + param_3 * 4) / 9;
  }
  if (param_7 == 2) {
    iVar2 = (param_4 + left) / 2;
    iVar3 = (param_3 * 5 + param_5 * 4) / 9;
  }
  if (2 < param_7) {
    iVar2 = (param_4 + left) / 2;
    iVar3 = (param_5 + param_3) / 2;
  }
  if (param_7 == 1) {
    dStack_14 = (_DAT_004ab0c8 * _DAT_00484cf0) / (double)*(int *)(&DAT_004a8660 + param_6 * 4);
  }
  if (((param_7 == 2) && (dStack_14 = _DAT_004ab0c8 * _DAT_00484cf8, DAT_00491194 == 8)) &&
     (DAT_004a5a4c == 0)) {
    dStack_14 = _DAT_004ab0c8 * _DAT_00484d00;
  }
  if (((param_7 == 2) && (DAT_00491194 == 8)) && (DAT_004a5a4c == 1)) {
    dStack_14 = _DAT_004ab0c8 * _DAT_00484d08;
  }
  if ((2 < param_7) &&
     (dStack_14 = (_DAT_004a8670 * _DAT_00484d10) / (double)DAT_004ab184, 2 < param_7)) {
    if ((DAT_004a4958 == 2) || (DAT_004a4958 == 3)) {
      dStack_14 = (_DAT_004a8670 * _DAT_00484d18) / (double)DAT_004ab184;
    }
    if (2 < param_7) {
      if ((DAT_00491194 == 8) && (DAT_004a5a4c == 0)) {
        dStack_14 = (_DAT_004a8670 * _DAT_00484d20) / (double)DAT_004ab184;
      }
      if (((2 < param_7) && (DAT_00491194 == 8)) && (DAT_004a5a4c == 1)) {
        dStack_14 = (_DAT_004a8670 * _DAT_00484d28) / (double)DAT_004ab184;
      }
    }
  }
  if (param_7 == 1) {
    param_2 = (int)(longlong)*(double *)(&DAT_004a49e8 + param_6 * 8);
    param_1 = (int)(longlong)*(double *)(&DAT_004a4ae0 + param_6 * 8);
  }
  else {
    param_2 = DAT_004aa594;
    param_1 = DAT_004aa59c;
  }
  if (DAT_004ac970 == 1) {
    FUN_00408860(this,dStack_14,iVar2,iVar3);
  }
  if (DAT_004ac974 == 1) {
    FUN_00408b00(this,dStack_14,iVar2,iVar3);
  }
  if (2 < param_7) {
    if (DAT_004a4958 < 2) {
      FUN_004226c0(this,iVar2,iVar3,dStack_14,param_2,param_1,param_7,param_6);
    }
    if ((2 < param_7) && (1 < DAT_004a4958)) {
      FUN_0044f320(this,iVar2,iVar3,dStack_14,param_2,param_1,param_7,param_6);
    }
  }
  DAT_004aa7e0 = FUN_0042d0c0(param_6);
  FUN_00421d90(this,iVar2,iVar3,dStack_14,param_2,param_1,param_7,param_6,left,param_3,param_4,
               param_5);
  if (param_7 < 3) {
    if (DAT_004a4958 < 2) {
      FUN_004226c0(this,iVar2,iVar3,dStack_14,param_2,param_1,param_7,param_6);
    }
    if ((param_7 < 3) && (1 < DAT_004a4958)) {
      FUN_0044f320(this,iVar2,iVar3,dStack_14,param_2,param_1,param_7,param_6);
    }
  }
  if (DAT_004ac970 == 1) {
    FUN_004094c0(this,left,param_3,param_4);
  }
  if (DAT_004ac974 == 1) {
    FUN_00408c70(this,left,param_3,param_4);
  }
  iVar4 = param_3;
  if (DAT_004aa980 == 1) {
    FUN_00409050(this,left,param_3,param_4);
  }
  (*pcVar1)((void *)this,7);
  if (param_7 == 1) {
    param_5 = DAT_004a72d0 / 0x1c;
    (**(code **)(*(int *)this + 0x34))((void *)this,0x7f7f7f);
    param_7 = *(undefined4 *)(*(int *)this + 0x38);
    if (DAT_004ac92c == 0) {
      CVar5 = 0xffff00;
    }
    else {
      CVar5 = 0xffffff;
    }
    (*(code *)param_7)((void *)this,CVar5);
    if (param_6 == 1) {
      param_4 = (int)(longlong)((double)DAT_004a763c * _DAT_00484cf8) + left;
      iVar3 = param_5 + iVar4;
      FUN_0044d990(this,left,iVar4,param_4,iVar3,1,-1);
      FUN_0046bf33(&param_1,s_zoom_004918b4);
      uStack_4 = 0;
      param_3 = *(undefined4 *)(*(int *)this + 100);
      (*(code *)param_3)((void *)this,left + 3,iVar4,(LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5(&param_1);
      FUN_0044d990(this,left + 1,iVar4,param_4,iVar3,0,-1);
      iVar3 = iVar3 + 2;
      if ((((left < DAT_004a774c) && (DAT_004a774c < param_4)) && (DAT_004aa97c < iVar3)) &&
         (iVar4 = iVar3 - param_5, iVar4 < DAT_004aa97c)) {
        DAT_004a8664 = DAT_004a8664 / 2;
        if (DAT_004a8664 < 2) {
          DAT_004a8664 = 2;
        }
        DAT_004aa97c = 0;
        (*(code *)param_7)((void *)this,0);
        FUN_0046bf33(&param_1,s_zoom_004918b4);
        uStack_4 = 1;
        (*(code *)param_3)((void *)this,left + 3,iVar4 + -2,(LPCSTR)param_1,*(int *)(param_1 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_1);
      }
      iVar4 = param_5 + iVar3;
      FUN_0044d990(this,left,iVar3,param_4,iVar4,1,-1);
      if (DAT_004ac92c == 0) {
        CVar5 = 0xffff00;
      }
      else {
        CVar5 = 0xffffff;
      }
      (*(code *)param_7)((void *)this,CVar5);
      FUN_0046bf33(&param_1,&DAT_004918b0);
      uStack_4 = 2;
      (*(code *)param_3)((void *)this,left + 5,iVar3,(LPCSTR)param_1,*(int *)(param_1 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5(&param_1);
      FUN_0044d990(this,left,iVar3,param_4,iVar4,0,-1);
      if (((left < DAT_004a774c) && (DAT_004a774c < param_4)) &&
         ((DAT_004aa97c < iVar4 && (iVar3 = iVar4 - param_5, iVar3 < DAT_004aa97c)))) {
        DAT_004a8664 = DAT_004a8664 * 2;
        _DAT_004a775c = ((DAT_004a4958 < 2) - 1 & 0xffffffc0) + 0x80;
        if (_DAT_004a775c < DAT_004a8664) {
          DAT_004a8664 = _DAT_004a775c;
        }
        DAT_004aa97c = 0;
        (*(code *)param_7)((void *)this,0);
        FUN_0046bf33(&param_4,&DAT_004918b0);
        uStack_4 = 3;
        (*(code *)param_3)((void *)this,left + 5,iVar3,(LPCSTR)param_4,*(int *)(param_4 + -8));
        uStack_4 = 0xffffffff;
        FUN_0046bec5(&param_4);
      }
    }
    if (param_6 == 2) {
      param_6 = param_5 + iVar4;
      iVar3 = (int)(longlong)((double)DAT_004a763c * _DAT_00484d30) + left;
      FUN_0044d990(this,left,iVar4,iVar3,param_6,1,1);
      if (DAT_004ac92c == 0) {
        CVar5 = 0xffff00;
      }
      else {
        CVar5 = 0xffffff;
      }
      (*(code *)param_7)((void *)this,CVar5);
      FUN_0046bf33(&param_4,&DAT_004918a8);
      uStack_4 = 4;
      param_3 = *(undefined4 *)(*(int *)this + 100);
      (*(code *)param_3)((void *)this,left + 3,iVar4,(LPCSTR)param_4,*(int *)(param_4 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5(&param_4);
      FUN_0044d990(this,left,iVar4,iVar3,param_6,0,1);
      iVar4 = param_6;
      param_6 = param_5 + param_6;
      FUN_0044d990(this,left,iVar4,iVar3,param_6,1,1);
      if (DAT_004ac92c == 0) {
        CVar5 = 0xffff00;
      }
      else {
        CVar5 = 0xffffff;
      }
      (*(code *)param_7)((void *)this,CVar5);
      FUN_0046bf33(&param_7,&DAT_004918a0);
      uStack_4 = 5;
      (*(code *)param_3)((void *)this,left + 3,iVar4,(LPCSTR)param_7,*(int *)(param_7 + -8));
      uStack_4 = 0xffffffff;
      FUN_0046bec5(&param_7);
      FUN_0044d990(this,left,iVar4,iVar3,param_6,0,1);
    }
  }
  SelectObject(hdc,h_00);
  DeleteObject(h);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

