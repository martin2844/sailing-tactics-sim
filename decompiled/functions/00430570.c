
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00430570(CDC *param_1,int param_2,int param_3,int param_4)

{
  CDC *this;
  TactCString *pTVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int iVar6;
  TactCString local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047e5a0;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_0046bd7a(&local_10);
  this = param_1;
  local_4 = 0;
  FUN_0047033f(param_1,1);
  if (DAT_004ac92c == 0) {
    iVar3 = *(int *)this;
    (**(code **)(iVar3 + 0x34))(this,0xff0000);
    (**(code **)(iVar3 + 0x38))(this,0xffff);
  }
  iVar4 = param_4;
  iVar5 = param_3;
  iVar3 = param_2;
  if (param_2 == 2) {
    FUN_0046bf33(&param_1,s_start___finish_line_00493550);
    local_4._0_1_ = 1;
    (**(code **)(*(int *)this + 100))
              (this,iVar5 + -0x32,iVar4 + 0xd,(LPCSTR)param_1,*(int *)(param_1 + -8));
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5((int *)&param_1);
  }
  if (iVar3 == 3) {
    if (DAT_004ac940 == 0) {
      FUN_0046bf33(&param_1,s_1st_mark_00493544);
      local_4._0_1_ = 2;
      (**(code **)(*(int *)this + 100))
                (this,iVar5 + 6,iVar4 + -0xf,(LPCSTR)param_1,*(int *)(param_1 + -8));
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_004ac940 == 1) {
      if ((DAT_004a4f8c < 0xb5) || (0x13f < DAT_004a4f8c)) {
        FUN_0046bf33(&param_1,s_1st___4th_mark_00493534);
        local_4._0_1_ = 4;
        (**(code **)(*(int *)this + 100))
                  (this,iVar5 + 6,iVar4 + -0xf,(LPCSTR)param_1,*(int *)(param_1 + -8));
      }
      else {
        FUN_0046bf33(&param_1,s_1st___4th_mark_00493534);
        local_4._0_1_ = 3;
        (**(code **)(*(int *)this + 100))
                  (this,iVar5 + -0x5a,iVar4 + -0x16,(LPCSTR)param_1,*(int *)(param_1 + -8));
      }
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5((int *)&param_1);
    }
  }
  if ((DAT_004ac840 < 0xa1) || (199 < DAT_004ac840)) {
    param_1 = (CDC *)(iVar4 + -7);
    iVar3 = iVar5 + -0x46;
  }
  else {
    param_1 = (CDC *)(iVar4 + 10);
    iVar3 = iVar5;
  }
  if (param_2 == 4) {
    if (DAT_00491160 * DAT_004ac940 != 1) {
      FUN_0046bf33(&param_4,s_2nd_mark_00493528);
      local_4._0_1_ = 5;
      (**(code **)(*(int *)this + 100))
                (this,iVar3,(int)param_1,(LPCSTR)param_4,*(int *)(param_4 + -8));
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5(&param_4);
    }
    if ((((param_2 == 4) && (DAT_004ac940 == 1)) && (DAT_00491160 == 1)) && (0xe < DAT_0049118c)) {
      FUN_0046bf33(&param_4,s_5th_mark_0049351c);
      local_4._0_1_ = 6;
      (**(code **)(*(int *)this + 100))
                (this,iVar3,(int)param_1,(LPCSTR)param_4,*(int *)(param_4 + -8));
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5(&param_4);
    }
  }
  if (param_2 == 5) {
    if ((DAT_00491160 == 0) && (DAT_004ac940 == 0)) {
      FUN_0046bf33(&param_1,s_3rd_mark_00493510);
      local_4._0_1_ = 7;
      (**(code **)(*(int *)this + 100))
                (this,iVar5 + -0x28,iVar4 + 8,(LPCSTR)param_1,*(int *)(param_1 + -8));
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5((int *)&param_1);
    }
    if (param_2 == 5) {
      if (((DAT_00491160 == 1) && (DAT_004ac940 == 0)) && (0xe < DAT_0049118c)) {
        FUN_0046bf33(&param_1,s_3rd_mark_00493510);
        local_4._0_1_ = 8;
        (**(code **)(*(int *)this + 100))
                  (this,iVar5 + -0x28,iVar4 + 8,(LPCSTR)param_1,*(int *)(param_1 + -8));
        local_4 = (uint)local_4._1_3_ << 8;
        FUN_0046bec5((int *)&param_1);
      }
      if (param_2 == 5) {
        if ((DAT_004ac940 == 1) && (DAT_0049118c < 0xf)) {
          FUN_0046bf33(&param_1,s_3rd___5th_mark_00493500);
          local_4._0_1_ = 9;
          (**(code **)(*(int *)this + 100))
                    (this,iVar5 + -0x28,iVar4 + 8,(LPCSTR)param_1,*(int *)(param_1 + -8));
          local_4 = (uint)local_4._1_3_ << 8;
          FUN_0046bec5((int *)&param_1);
        }
        if (((param_2 == 5) && (DAT_004ac940 == 1)) && (0xe < DAT_0049118c)) {
          FUN_0046bf33(&param_2,s_3rd___6th_mark_004934f0);
          local_4._0_1_ = 10;
          (**(code **)(*(int *)this + 100))
                    (this,iVar5 + -0x28,iVar4 + 8,(LPCSTR)param_2,*(int *)(param_2 + -8));
          local_4 = (uint)local_4._1_3_ << 8;
          FUN_0046bec5(&param_2);
        }
      }
    }
  }
  FUN_0047033f(this,2);
  if ((DAT_004ac970 == 1) || (DAT_004ac974 == 1)) goto LAB_00430e7e;
  iVar3 = (DAT_004a72d0 * 2) / 5;
  iVar5 = iVar3;
  if (DAT_004aa804 == 1) {
    iVar5 = (DAT_004a72d0 * 3) / 5;
  }
  if (DAT_004aa804 == 2) {
    iVar5 = iVar3;
  }
  if (DAT_004aa804 == 3) {
    iVar5 = DAT_004a72d0 / 5;
  }
  iVar3 = 7;
  if (DAT_004aa804 == 4) {
    iVar3 = (DAT_004a763c << 2) / 5;
    iVar5 = (DAT_004a72d0 * 3) / 5;
  }
  if (DAT_004ac92c == 0) {
    iVar4 = *(int *)this;
    (**(code **)(iVar4 + 0x34))(this,0);
    (**(code **)(iVar4 + 0x38))(this,0xffff);
  }
  if (DAT_004a67ac != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(this + 4),DAT_004a67ac);
  }
  if (((DAT_004a4958 == 0) || (DAT_004a4958 == 6)) || (DAT_004a4958 == 7)) {
    pTVar1 = FUN_00413d00((TactCString *)&param_4,DAT_004aa390);
    local_4._0_1_ = 0xb;
    pTVar1 = FUN_0046c14f((TactCString *)&param_1,s_wind_offshore__004934dc,pTVar1);
    local_4._0_1_ = 0xc;
    pTVar1 = FUN_0046c0db((TactCString *)&param_2,pTVar1,&DAT_004911f0);
    local_4._0_1_ = 0xd;
    (**(code **)(*(int *)this + 100))(this,iVar3,iVar5,pTVar1->data,*(int *)(pTVar1->data + -8));
    local_4._0_1_ = 0xc;
    FUN_0046bec5(&param_2);
    local_4._0_1_ = 0xb;
    FUN_0046bec5((int *)&param_1);
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5(&param_4);
  }
  if ((0 < DAT_004a4958) && (DAT_004a4958 < 4)) {
    pTVar1 = FUN_00413d00((TactCString *)&param_4,DAT_004aa390);
    local_4._0_1_ = 0xe;
    pTVar1 = FUN_0046c14f((TactCString *)&param_1,s_mid_lake_wind__004934c8,pTVar1);
    local_4._0_1_ = 0xf;
    pTVar1 = FUN_0046c0db((TactCString *)&param_2,pTVar1,&DAT_004911f0);
    local_4._0_1_ = 0x10;
    (**(code **)(*(int *)this + 100))(this,iVar3,iVar5,pTVar1->data,*(int *)(pTVar1->data + -8));
    local_4._0_1_ = 0xf;
    FUN_0046bec5(&param_2);
    local_4._0_1_ = 0xe;
    FUN_0046bec5((int *)&param_1);
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5(&param_4);
  }
  if (DAT_004a4958 == 4) {
    pTVar1 = FUN_00413d00((TactCString *)&param_4,DAT_004aa390);
    local_4._0_1_ = 0x11;
    pTVar1 = FUN_0046c14f((TactCString *)&param_1,s_mid_river_wind__004934b4,pTVar1);
    local_4._0_1_ = 0x12;
    pTVar1 = FUN_0046c0db((TactCString *)&param_2,pTVar1,&DAT_004911f0);
    local_4._0_1_ = 0x13;
    (**(code **)(*(int *)this + 100))(this,iVar3,iVar5,pTVar1->data,*(int *)(pTVar1->data + -8));
    local_4._0_1_ = 0x12;
    FUN_0046bec5(&param_2);
    local_4._0_1_ = 0x11;
    FUN_0046bec5((int *)&param_1);
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5(&param_4);
  }
  if (DAT_004ac92c == 0) {
    if (DAT_004a67ac != (HGDIOBJ)0x0) {
      hdc = *(HDC *)(this + 4);
      h = DAT_004a67ac;
LAB_00430c25:
      SelectObject(hdc,h);
    }
  }
  else if (DAT_004a4ee4 != (HGDIOBJ)0x0) {
    hdc = *(HDC *)(this + 4);
    h = DAT_004a4ee4;
    goto LAB_00430c25;
  }
  iVar4 = iVar3 + 0x19;
  iVar6 = 5;
  param_4 = iVar4;
  iVar2 = FUN_00413cb0(DAT_004ac840);
  FUN_00430eb0(this,iVar4,iVar5 + 0x28,iVar2,iVar6);
  iVar5 = iVar5 + ((int)(DAT_004a72d0 + (DAT_004a72d0 >> 0x1f & 7U)) >> 3);
  param_2 = (DAT_004aa800 ^ (int)DAT_004aa800 >> 0x1f) - ((int)DAT_004aa800 >> 0x1f);
  pTVar1 = FUN_00413d90((TactCString *)&param_2,(double)param_2 * _DAT_00484d48);
  local_4._0_1_ = 0x14;
  FUN_0046bfbe(&local_10,(int *)pTVar1);
  local_4._0_1_ = 0;
  FUN_0046bec5(&param_2);
  if (((DAT_004a4958 == 0) || (DAT_004a4958 == 6)) || (DAT_004a4958 == 7)) {
    pTVar1 = FUN_0046c14f((TactCString *)&param_1,s_tide_offshore__004934a0,&local_10);
    local_4._0_1_ = 0x15;
    pTVar1 = FUN_0046c0db((TactCString *)&param_2,pTVar1,&DAT_004911f0);
    local_4._0_1_ = 0x16;
    (**(code **)(*(int *)this + 100))(this,iVar3,iVar5,pTVar1->data,*(int *)(pTVar1->data + -8));
    local_4._0_1_ = 0x15;
    FUN_0046bec5(&param_2);
    local_4._0_1_ = 0;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a4958 == 4) {
    pTVar1 = FUN_0046c14f((TactCString *)&param_1,s_mid_river_current__00493488,&local_10);
    local_4._0_1_ = 0x17;
    pTVar1 = FUN_0046c0db((TactCString *)&param_2,pTVar1,&DAT_004911f0);
    local_4._0_1_ = 0x18;
    (**(code **)(*(int *)this + 100))(this,iVar3,iVar5,pTVar1->data,*(int *)(pTVar1->data + -8));
    local_4._0_1_ = 0x17;
    FUN_0046bec5(&param_2);
    local_4._0_1_ = 0;
    FUN_0046bec5((int *)&param_1);
    iVar4 = param_4;
  }
  if (((DAT_004a4958 == 0) || (DAT_004a4958 == 4)) || ((DAT_004a4958 == 6 || (DAT_004a4958 == 7))))
  {
    iVar3 = DAT_004aae1c;
    if (DAT_004aa298 < 0) {
      iVar3 = DAT_004aae1c + 0xb4;
    }
    iVar2 = 5;
    iVar3 = FUN_00413cb0(iVar3);
    FUN_00430eb0(this,iVar4,iVar5 + 0x28,iVar3,iVar2);
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0xffff);
  }
  FUN_0046bf33(&param_2,s_north_00493480);
  iVar3 = *(int *)this;
  local_4._0_1_ = 0x19;
  (**(code **)(iVar3 + 100))
            (this,DAT_004a763c + -0x46,DAT_004a72d0 / 7,(LPCSTR)param_2,*(int *)(param_2 + -8));
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0046bec5(&param_2);
  FUN_00430eb0(this,DAT_004a763c + -0x37,DAT_004a72d0 / 7 + 0x23,0xb4,5);
  (**(code **)(iVar3 + 0x38))(this,0);
  (**(code **)(iVar3 + 0x34))(this,0xffffff);
LAB_00430e7e:
  local_4 = 0xffffffff;
  FUN_0046bec5((int *)&local_10);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

