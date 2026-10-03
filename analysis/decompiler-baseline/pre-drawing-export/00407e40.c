
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00407e40(CDC *param_1,int param_2,CDC *param_3,undefined *param_4,int param_5)

{
  CDC *pCVar1;
  int left;
  HRGN h;
  HDC unaff_EBX;
  int iVar2;
  CDC *pCVar3;
  CDC *pCVar4;
  code *unaff_EBP;
  int iVar5;
  int iVar6;
  int *unaff_FS_OFFSET;
  code *pcVar7;
  undefined4 uVar8;
  HDC pHVar9;
  HGDIOBJ h_00;
  code *local_24;
  undefined8 local_1c;
  code *pcStack_14;
  int iStack_10;
  int iStack_c;
  code *pcStack_8;
  code *pcStack_4;
  
  left = param_2;
  pCVar1 = param_1;
  pcStack_4 = (code *)0xffffffff;
  pcStack_8 = FUN_0047d6e0;
  iStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&iStack_c;
  pHVar9 = *(HDC *)(param_1 + 4);
  local_1c = (double)CONCAT44(local_1c._4_4_,pHVar9);
  h = CreateRectRgn(param_2,(int)param_3,(int)param_4,param_5);
  local_1c = (double)CONCAT44(h,(int)local_1c);
  SelectObject(pHVar9,h);
  local_24 = *(code **)(*(int *)pCVar1 + 0x2c);
  (*local_24)(7);
  (*local_24)(7);
  if ((DAT_004ac92c == 0) && (DAT_004ac98c == 0)) {
    if (DAT_004aa714 != (HGDIOBJ)0x0) {
      pHVar9 = *(HDC *)(pCVar1 + 4);
      h_00 = DAT_004aa714;
LAB_00407ef0:
      SelectObject(pHVar9,h_00);
    }
  }
  else if (DAT_004aa7f4 != (HGDIOBJ)0x0) {
    pHVar9 = *(HDC *)(pCVar1 + 4);
    h_00 = DAT_004aa7f4;
    goto LAB_00407ef0;
  }
  iVar6 = param_5;
  if (DAT_004ac98c == 1) {
    if (param_5 < 1) goto LAB_00407fa3;
    if ((param_5 < 3) && (DAT_004aa7f4 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(pCVar1 + 4),DAT_004aa7f4);
    }
  }
  if (iVar6 == 1) {
    if ((((param_4 == (undefined *)0x1) && (0 < DAT_004aa62c)) && (DAT_004a8664 == 2)) &&
       (DAT_004a5b8c != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(pCVar1 + 4),DAT_004a5b8c);
    }
    if (((param_4 == (undefined *)0x2) && (0 < DAT_004aa638)) &&
       ((DAT_004a8668 == 2 && (DAT_004a5b8c != (HGDIOBJ)0x0)))) {
      SelectObject(*(HDC *)(pCVar1 + 4),DAT_004a5b8c);
    }
  }
LAB_00407fa3:
  Rectangle(*(HDC *)(pCVar1 + 4),left,(int)param_1,param_2,(int)param_3);
  iVar2 = param_5;
  iVar5 = param_5;
  if (iVar6 == 1) {
    iVar2 = (param_2 * 5 + left * 4) / 9;
    iVar5 = ((int)param_3 * 5 + (int)param_1 * 4) / 9;
  }
  if (param_5 == 2) {
    iVar2 = (param_2 + left) / 2;
    iVar5 = ((int)param_1 * 5 + (int)param_3 * 4) / 9;
  }
  if (2 < param_5) {
    iVar2 = (param_2 + left) / 2;
    iVar5 = (int)(param_3 + (int)param_1) / 2;
  }
  if (param_5 == 1) {
    local_1c = (_DAT_004ab0c8 * _DAT_00484cf0) / (double)*(int *)(&DAT_004a8660 + (int)param_4 * 4);
  }
  if (((param_5 == 2) && (local_1c = _DAT_004ab0c8 * _DAT_00484cf8, DAT_00491194 == 8)) &&
     (DAT_004a5a4c == 0)) {
    local_1c = _DAT_004ab0c8 * _DAT_00484d00;
  }
  if (((param_5 == 2) && (DAT_00491194 == 8)) && (DAT_004a5a4c == 1)) {
    local_1c = _DAT_004ab0c8 * _DAT_00484d08;
  }
  if ((2 < param_5) &&
     (local_1c = (_DAT_004a8670 * _DAT_00484d10) / (double)DAT_004ab184, 2 < param_5)) {
    if ((DAT_004a4958 == 2) || (DAT_004a4958 == 3)) {
      local_1c = (_DAT_004a8670 * _DAT_00484d18) / (double)DAT_004ab184;
    }
    if (2 < param_5) {
      if ((DAT_00491194 == 8) && (DAT_004a5a4c == 0)) {
        local_1c = (_DAT_004a8670 * _DAT_00484d20) / (double)DAT_004ab184;
      }
      if (((2 < param_5) && (DAT_00491194 == 8)) && (DAT_004a5a4c == 1)) {
        local_1c = (_DAT_004a8670 * _DAT_00484d28) / (double)DAT_004ab184;
      }
    }
  }
  if (param_5 == 1) {
    pcStack_4 = (code *)(longlong)*(double *)(&DAT_004a4ae0 + (int)param_4 * 8);
    pcVar7 = (code *)(longlong)*(double *)(&DAT_004a49e8 + (int)param_4 * 8);
  }
  else {
    pcStack_4 = DAT_004aa59c;
    pcVar7 = DAT_004aa594;
  }
  if (DAT_004ac970 == 1) {
    FUN_00408860(pCVar1);
  }
  if (DAT_004ac974 == 1) {
    FUN_00408b00(pCVar1);
  }
  if (2 < param_5) {
    if (DAT_004a4958 < 2) {
      FUN_004226c0(pCVar1);
    }
    if ((2 < param_5) && (1 < DAT_004a4958)) {
      FUN_0044f320((int *)pCVar1);
    }
  }
  DAT_004aa7e0 = FUN_0042d0c0((int)param_4);
  FUN_00421d90(pCVar1,iVar2,iVar5,(int)local_1c,local_1c._4_4_,pcVar7,pcStack_4,param_5,
               (uint)param_4,left,(int)param_1,param_2,(int)param_3);
  if (param_5 < 3) {
    if (DAT_004a4958 < 2) {
      FUN_004226c0(pCVar1);
    }
    if ((param_5 < 3) && (1 < DAT_004a4958)) {
      FUN_0044f320((int *)pCVar1);
    }
  }
  if (DAT_004ac970 == 1) {
    FUN_004094c0((int *)pCVar1,left);
  }
  if (DAT_004ac974 == 1) {
    FUN_00408c70((int *)pCVar1,left);
  }
  pCVar4 = param_1;
  if (DAT_004aa980 == 1) {
    FUN_00409050((int *)pCVar1,left);
  }
  (*unaff_EBP)(7);
  if (param_4 == (undefined *)0x1) {
    param_2 = DAT_004a72d0 / 0x1c;
    (**(code **)(*(int *)pCVar1 + 0x34))(0x7f7f7f);
    param_3 = *(CDC **)(*(int *)pCVar1 + 0x38);
    if (DAT_004ac92c == 0) {
      uVar8 = 0xffff00;
    }
    else {
      uVar8 = 0xffffff;
    }
    (*(code *)param_3)(uVar8);
    if (param_3 == (CDC *)0x1) {
      param_1 = (CDC *)((int)(longlong)((double)DAT_004a763c * _DAT_00484cf8) + left);
      pCVar3 = pCVar4 + param_2;
      FUN_0044d990((int *)pCVar1,left,(int)pCVar4,(int)param_1,pCVar3,1);
      FUN_0046bf33(&pcStack_8,s_zoom_004918b4);
      iStack_10 = 0;
      pcVar7 = *(code **)(*(int *)pCVar1 + 100);
      (*pcVar7)(left + 3,pCVar4,pcStack_8,*(undefined4 *)(pcStack_8 + -8));
      FUN_0046bec5((int *)((int)&local_1c + 4));
      FUN_0044d990((int *)pCVar1,left + 1,(int)pCVar4,iStack_c,pCVar3,0);
      pCVar3 = pCVar3 + 2;
      if ((((left < DAT_004a774c) && (DAT_004a774c < iStack_c)) && (DAT_004aa97c < (int)pCVar3)) &&
         (iVar6 = (int)pCVar3 - (int)pcStack_8, iVar6 < DAT_004aa97c)) {
        DAT_004a8664 = DAT_004a8664 / 2;
        if (DAT_004a8664 < 2) {
          DAT_004a8664 = 2;
        }
        DAT_004aa97c = 0;
        (*pcVar7)(0);
        FUN_0046bf33(&local_1c,s_zoom_004918b4);
        (*pcStack_14)(left + 3,iVar6 + -2,(int)local_1c,*(undefined4 *)((int)local_1c + -8));
        FUN_0046bec5((int *)((int)&local_1c + 4));
      }
      pCVar4 = pCVar3 + (int)pcStack_8;
      FUN_0044d990((int *)pCVar1,left,(int)pCVar3,iStack_c,pCVar4,1);
      if (DAT_004ac92c == 0) {
        uVar8 = 0xffff00;
      }
      else {
        uVar8 = 0xffffff;
      }
      (*pcVar7)(uVar8);
      FUN_0046bf33(&local_1c,&DAT_004918b0);
      local_24 = (code *)0x2;
      (*pcStack_14)(left + 5,pCVar3,(int)local_1c,*(undefined4 *)((int)local_1c + -8));
      iStack_10 = -1;
      FUN_0046bec5((int *)&pcStack_8);
      FUN_0044d990((int *)pCVar1,left,(int)pCVar3,(int)param_1,pCVar4,0);
      if (((left < DAT_004a774c) && (DAT_004a774c < (int)param_1)) &&
         ((DAT_004aa97c < (int)pCVar4 && (iVar6 = (int)pCVar4 - param_2, iVar6 < DAT_004aa97c)))) {
        DAT_004a8664 = DAT_004a8664 * 2;
        _DAT_004a775c = ((DAT_004a4958 < 2) - 1 & 0xffffffc0) + 0x80;
        if (_DAT_004a775c < DAT_004a8664) {
          DAT_004a8664 = _DAT_004a775c;
        }
        DAT_004aa97c = 0;
        (*(code *)param_4)(0);
        FUN_0046bf33(&stack0x00000000,&DAT_004918b0);
        pcStack_14 = (code *)0x3;
        (*pcStack_4)(left + 5,iVar6,pcVar7,*(undefined4 *)(pcVar7 + -8));
        iStack_10 = -1;
        FUN_0046bec5((int *)&param_1);
      }
    }
    if (param_3 == (CDC *)0x2) {
      param_3 = pCVar4 + param_2;
      iVar6 = (int)(longlong)((double)DAT_004a763c * _DAT_00484d30) + left;
      FUN_0044d990((int *)pCVar1,left,(int)pCVar4,iVar6,param_3,1);
      if (DAT_004ac92c == 0) {
        uVar8 = 0xffff00;
      }
      else {
        uVar8 = 0xffffff;
      }
      (*(code *)param_4)(uVar8);
      FUN_0046bf33(&stack0x00000000,&DAT_004918a8);
      pcStack_14 = (code *)0x4;
      pcStack_4 = *(code **)(*(int *)pCVar1 + 100);
      (*pcStack_4)(left + 3,pCVar4,pcVar7,*(undefined4 *)(pcVar7 + -8));
      local_24 = (code *)0xffffffff;
      FUN_0046bec5(&iStack_10);
      FUN_0044d990((int *)pCVar1,left,(int)pCVar4,iVar6,pcStack_8,0);
      pcVar7 = pcStack_8;
      pcStack_8 = pcStack_8 + iStack_c;
      FUN_0044d990((int *)pCVar1,left,(int)pcVar7,iVar6,pcStack_8,1);
      if (DAT_004ac92c == 0) {
        uVar8 = 0xffff00;
      }
      else {
        uVar8 = 0xffffff;
      }
      (*pcStack_4)(uVar8);
      FUN_0046bf33(&pcStack_8,&DAT_004918a0);
      unaff_EBX = (HDC)&DAT_00000005;
      (*local_1c._4_4_)(left + 3,pcVar7,pcStack_8,*(undefined4 *)(pcStack_8 + -8));
      iStack_10 = -1;
      FUN_0046bec5((int *)&param_4);
      FUN_0044d990((int *)pCVar1,left,(int)pcVar7,iVar6,param_3,0);
    }
  }
  SelectObject(unaff_EBX,unaff_EBP);
  DeleteObject(local_24);
  *unaff_FS_OFFSET = (int)local_1c._4_4_;
  return;
}

