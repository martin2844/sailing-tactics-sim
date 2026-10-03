
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042f0d0(CDC *param_1,int param_2,int param_3,uint param_4,int param_5,int param_6)

{
  CDC *this;
  uint uVar1;
  TactCString *pTVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  bool bVar7;
  float10 fVar8;
  TactCString local_3c;
  TactCString local_38;
  int local_34 [3];
  int local_28 [4];
  int local_18 [4];
  code *pcStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047e4b8;
  local_18[3] = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_18 + 3;
  FUN_0046bd7a(&local_38);
  local_4 = 0;
  FUN_0046bd7a(&local_3c);
  iVar6 = param_2;
  this = param_1;
  local_4 = CONCAT31(local_4._1_3_,1);
  local_34[0] = (int)(longlong)(_DAT_004aa810 * _DAT_00485058);
  if ((((param_2 == -1) && (0 < DAT_004a4958)) && (DAT_004a4958 < 4)) ||
     (((param_2 == -1 && (DAT_00491158 == 0)) && (DAT_004a4958 != 4)))) {
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5((int *)&local_3c);
    goto LAB_0042f90f;
  }
  FUN_0047033f(param_1,1);
  iVar4 = param_3;
  if (((DAT_004ac980 < 1) || (DAT_004ac980 == 2)) || (param_1 = (CDC *)0x1, DAT_004ac980 == 300)) {
    param_1 = (CDC *)0x0;
  }
  iVar5 = 0x1f;
  iVar6 = param_4 + 0x1e + iVar6 * 0x46;
  if (*(int *)(&DAT_004a4e88 + param_3 * 4) != 3) {
    iVar5 = param_5 + -10;
  }
  if (param_2 == -1) {
    iVar6 = 0xd2;
  }
  if (param_1 != (CDC *)0x0) {
    iVar5 = param_5 + 0x1f;
  }
  iVar3 = param_2;
  if (param_2 == 1) {
    iVar6 = param_6 - local_34[0];
    DAT_004aa7e0 = FUN_0042d0c0(param_3);
    fVar8 = FUN_0042c400((double)CONCAT44(*(undefined4 *)(&DAT_004a52f4 + DAT_004aa7e0 * 8),
                                          *(undefined4 *)(&DAT_004a52f0 + DAT_004aa7e0 * 8)),
                         (double)CONCAT44(*(undefined4 *)(&DAT_004a60b4 + DAT_004aa7e0 * 8),
                                          *(undefined4 *)(&DAT_004a60b0 + DAT_004aa7e0 * 8)),-1,
                         iVar4);
    iVar3 = 0xba - (int)(longlong)(fVar8 * (float10)_DAT_00484d78);
  }
  if (param_2 == 0) {
    iVar6 = param_4 + 0x1b;
    if (DAT_004ac9d8 == 0) {
      iVar3 = DAT_004a4800;
      if (iVar4 == 1) {
        iVar3 = DAT_004a47fc * DAT_004aa734 + DAT_004a475c;
      }
      else {
LAB_0042f28f:
        iVar3 = iVar3 * DAT_004aa738 + DAT_004a4770;
      }
    }
    else {
      iVar3 = DAT_004a7bd0;
      if (iVar4 != 1) goto LAB_0042f28f;
      iVar3 = DAT_004a7bcc * DAT_004aa734 + DAT_004a475c;
    }
    iVar3 = -iVar3;
    if (0 < (int)param_1) {
      iVar6 = DAT_004a763c + -0x28;
      iVar3 = DAT_004ac840;
    }
  }
  if (param_2 == -1) {
    iVar6 = local_34[0] + 2 + param_4;
    param_5 = FUN_00421560((int)(longlong)*(double *)(&DAT_004a49e8 + iVar4 * 8),
                           (uint)(longlong)*(double *)(&DAT_004a4ae0 + iVar4 * 8),iVar4);
    if (iVar4 == 1) {
      iVar4 = (DAT_004ac01c - DAT_004aa960) - DAT_004a475c;
    }
    else {
      iVar4 = (DAT_004ac020 - DAT_004aa960) - DAT_004a4770;
    }
    iVar3 = FUN_00413cb0(iVar4);
  }
  iVar4 = FUN_00413cb0(iVar3);
  iVar4 = FUN_00413cb0(iVar4);
  uVar1 = FUN_00413cb0(iVar4);
  param_4 = uVar1;
  if ((-1 < iVar4) && (iVar4 < 0x169)) {
    local_18[0] = iVar6 - ((&DAT_004a54a0)[iVar4] * 0x1a) / 100;
    local_28[0] = iVar5 - ((&DAT_004a3450)[iVar4] * 0x1a) / 300;
    iVar4 = FUN_00413cb0(uVar1 + 0x28);
    iVar4 = FUN_00413cb0(iVar4);
    local_18[1] = iVar6 - ((&DAT_004a54a0)[iVar4] * 0xd) / 100;
    local_28[1] = iVar5 - ((&DAT_004a3450)[iVar4] * 0xd) / 300;
    iVar4 = FUN_00413cb0(uVar1 - 0x28);
    iVar4 = FUN_00413cb0(iVar4);
    local_18[2] = iVar6 - ((&DAT_004a54a0)[iVar4] * 0xd) / 100;
    local_28[2] = iVar5 - ((&DAT_004a3450)[iVar4] * 0xd) / 300;
    if (DAT_004ac92c == 0) {
      if (DAT_004a621c != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(this + 4),DAT_004a621c);
      }
    }
    else {
      (**(code **)(*(int *)this + 0x2c))(this,4);
    }
    if (DAT_004ac92c == 0) {
      if (param_2 == 1) {
        if (((DAT_004aa7e0 == 3) || (DAT_004aa7e0 == 5)) && (DAT_004a6484 != (HGDIOBJ)0x0)) {
          SelectObject(*(HDC *)(this + 4),DAT_004a6484);
        }
        if ((DAT_004aa7e0 == 4) && (DAT_004ab17c != (HGDIOBJ)0x0)) {
          SelectObject(*(HDC *)(this + 4),DAT_004ab17c);
        }
        if ((DAT_004aa7e0 == 2) && (DAT_004a70e4 != (HGDIOBJ)0x0)) {
          SelectObject(*(HDC *)(this + 4),DAT_004a70e4);
        }
      }
      if (((DAT_004ac92c == 0) && (param_2 == -1)) && (DAT_004aa714 != (HGDIOBJ)0x0)) {
        SelectObject(*(HDC *)(this + 4),DAT_004aa714);
      }
    }
    (**(code **)(*(int *)this + 0x2c))(this,7);
    Ellipse(*(HDC *)(this + 4),iVar6 + -0x1a,iVar5 + -8,iVar6 + 0x1a,iVar5 + 8);
    if (DAT_004a4ee4 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a4ee4);
    }
    iVar4 = 0;
    do {
      FUN_004706bd(this,local_34,iVar6,iVar5);
      CDC::LineTo(this,*(int *)((int)local_18 + iVar4),*(int *)((int)local_28 + iVar4));
      iVar4 = iVar4 + 4;
    } while (iVar4 < 9);
    iVar4 = iVar5 + -0x1a;
    if (900 < DAT_004a763c) {
      iVar4 = iVar5 + -0x1b;
    }
    if (DAT_004ac92c == 0) {
      iVar5 = *(int *)this;
      (**(code **)(iVar5 + 0x34))(this,0x7f7f00);
      (**(code **)(iVar5 + 0x38))(this,0xffff);
    }
    if (DAT_004ac98c == 1) {
      (**(code **)(*(int *)this + 0x34))(this,0x7f7f7f);
    }
    iVar5 = param_2;
    if (param_2 == 0) {
      bVar7 = false;
      if (param_1 == (CDC *)0x0) {
        if (DAT_004ac9d8 == 0) {
          pTVar2 = FUN_00413d00((TactCString *)&param_2,*(int *)(&DAT_004ab9e8 + param_3 * 4));
          local_4._0_1_ = 2;
          FUN_0046bfbe(&local_38,(int *)pTVar2);
          local_4._0_1_ = 1;
          FUN_0046bec5(&param_2);
          pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_a_wind_00493478,&local_38);
          local_4._0_1_ = 3;
          (**(code **)(*(int *)this + 100))
                    (this,iVar6 + -0x18,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
        }
        else {
          pTVar2 = FUN_00413d00((TactCString *)&param_2,*(int *)(&DAT_004a6338 + param_3 * 4));
          local_4._0_1_ = 4;
          FUN_0046bfbe(&local_38,(int *)pTVar2);
          local_4._0_1_ = 1;
          FUN_0046bec5(&param_2);
          pTVar2 = FUN_0046c14f((TactCString *)&param_2,s_t_wind_00493470,&local_38);
          local_4._0_1_ = 5;
          (**(code **)(*(int *)this + 100))
                    (this,iVar6 + -0x18,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
        }
        local_4 = CONCAT31(local_4._1_3_,1);
        FUN_0046bec5(&param_2);
        goto LAB_0042f714;
      }
    }
    else {
LAB_0042f714:
      bVar7 = param_1 == (CDC *)0x0;
    }
    if (!bVar7 && -1 < (int)param_1) {
      FUN_0046bf33(&param_2,&DAT_00493468);
      local_4._0_1_ = 6;
      (**(code **)(*(int *)this + 100))
                (this,iVar6 + -0xc,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
      local_4 = CONCAT31(local_4._1_3_,1);
      FUN_0046bec5(&param_2);
    }
    if (iVar5 == 1) {
      FUN_0046bf33(&param_2,&DAT_00493460);
      local_4._0_1_ = 7;
      (**(code **)(*(int *)this + 100))
                (this,iVar6 + -0xf,iVar4,(LPCSTR)param_2,*(int *)(param_2 + -8));
      local_4 = CONCAT31(local_4._1_3_,1);
      FUN_0046bec5(&param_2);
    }
    if (iVar5 == -1) {
      if (DAT_004a4958 != 4) {
        FUN_0046c00d(&local_3c,s_tide_00493458);
      }
      if (DAT_004a4958 == 4) {
        if (700 < DAT_004a763c) {
          FUN_0046c00d(&local_3c,s_current_0049344c);
        }
        if ((DAT_004a4958 == 4) && (DAT_004a763c < 0x2bd)) {
          FUN_0046c00d(&local_3c,s_curr_00493444);
        }
      }
      iVar5 = (param_5 ^ param_5 >> 0x1f) - (param_5 >> 0x1f);
      param_2 = (int)FUN_00413d00((TactCString *)&param_6,iVar5 % 10);
      local_4._0_1_ = 8;
      pTVar2 = FUN_00413d00((TactCString *)&param_5,iVar5 / 10);
      local_4._0_1_ = 9;
      pTVar2 = FUN_0046c075((TactCString *)&param_1,&local_3c,pTVar2);
      local_4._0_1_ = 10;
      pTVar2 = FUN_0046c0db((TactCString *)&param_4,pTVar2,(char *)&DAT_0049300c);
      local_4._0_1_ = 0xb;
      pTVar2 = FUN_0046c075((TactCString *)&param_3,pTVar2,(TactCString *)param_2);
      local_4._0_1_ = 0xc;
      (**(code **)(*(int *)this + 100))
                (this,iVar6 + -0x19,iVar4,pTVar2->data,*(int *)(pTVar2->data + -8));
      local_4._0_1_ = 0xb;
      FUN_0046bec5(&param_3);
      local_4._0_1_ = 10;
      FUN_0046bec5((int *)&param_4);
      local_4._0_1_ = 9;
      FUN_0046bec5((int *)&param_1);
      local_4._0_1_ = 8;
      FUN_0046bec5(&param_5);
      local_4 = CONCAT31(local_4._1_3_,1);
      FUN_0046bec5(&param_6);
    }
    FUN_0047033f(this,2);
    iVar6 = *(int *)this;
    (**(code **)(iVar6 + 0x34))(this,0xffffff);
    (**(code **)(iVar6 + 0x38))(this,0);
  }
  local_4 = local_4 & 0xffffff00;
  FUN_0046bec5((int *)&local_3c);
LAB_0042f90f:
  local_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_38);
  *unaff_FS_OFFSET = local_18[3];
  return;
}

