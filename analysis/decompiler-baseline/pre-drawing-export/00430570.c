
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00430570(CDC *param_1,int param_2,int param_3,int param_4)

{
  CDC *this;
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int iVar7;
  int local_10;
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
    iVar4 = *(int *)this;
    (**(code **)(iVar4 + 0x34))();
    (**(code **)(iVar4 + 0x38))(0xffff);
  }
  iVar5 = param_4;
  iVar6 = param_3;
  iVar4 = param_2;
  if (param_2 == 2) {
    FUN_0046bf33(&param_1,s_start___finish_line_00493550);
    local_4._0_1_ = 1;
    (**(code **)(*(int *)this + 100))(iVar6 + -0x32,iVar5 + 0xd,param_1);
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5((int *)&param_1);
  }
  if (iVar4 == 3) {
    if (DAT_004ac940 == 0) {
      FUN_0046bf33(&param_1,s_1st_mark_00493544);
      local_4._0_1_ = 2;
      (**(code **)(*(int *)this + 100))(iVar6 + 6,iVar5 + -0xf,param_1);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5((int *)&param_1);
    }
    if (DAT_004ac940 == 1) {
      if ((DAT_004a4f8c < 0xb5) || (0x13f < DAT_004a4f8c)) {
        FUN_0046bf33(&param_1,s_1st___4th_mark_00493534);
        local_4._0_1_ = 4;
        (**(code **)(*(int *)this + 100))(iVar6 + 6,iVar5 + -0xf,param_1);
      }
      else {
        FUN_0046bf33(&param_1,s_1st___4th_mark_00493534);
        local_4._0_1_ = 3;
        (**(code **)(*(int *)this + 100))(iVar6 + -0x5a,iVar5 + -0x16,param_1);
      }
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5((int *)&param_1);
    }
  }
  if ((DAT_004ac840 < 0xa1) || (199 < DAT_004ac840)) {
    param_1 = (CDC *)(iVar5 + -7);
    iVar4 = iVar6 + -0x46;
  }
  else {
    param_1 = (CDC *)(iVar5 + 10);
    iVar4 = iVar6;
  }
  if (param_2 == 4) {
    if (DAT_00491160 * DAT_004ac940 != 1) {
      FUN_0046bf33(&param_4,s_2nd_mark_00493528);
      local_4._0_1_ = 5;
      (**(code **)(*(int *)this + 100))(iVar4,param_1,param_4);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5(&param_4);
    }
    if ((((param_2 == 4) && (DAT_004ac940 == 1)) && (DAT_00491160 == 1)) && (0xe < DAT_0049118c)) {
      FUN_0046bf33(&param_4,s_5th_mark_0049351c);
      local_4._0_1_ = 6;
      (**(code **)(*(int *)this + 100))(iVar4,param_1,param_4);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5(&param_4);
    }
  }
  if (param_2 == 5) {
    if ((DAT_00491160 == 0) && (DAT_004ac940 == 0)) {
      FUN_0046bf33(&param_1,s_3rd_mark_00493510);
      local_4._0_1_ = 7;
      (**(code **)(*(int *)this + 100))(iVar6 + -0x28,iVar5 + 8,param_1);
      local_4 = (uint)local_4._1_3_ << 8;
      FUN_0046bec5((int *)&param_1);
    }
    if (param_2 == 5) {
      if (((DAT_00491160 == 1) && (DAT_004ac940 == 0)) && (0xe < DAT_0049118c)) {
        FUN_0046bf33(&param_1,s_3rd_mark_00493510);
        local_4._0_1_ = 8;
        (**(code **)(*(int *)this + 100))(iVar6 + -0x28,iVar5 + 8,param_1);
        local_4 = (uint)local_4._1_3_ << 8;
        FUN_0046bec5((int *)&param_1);
      }
      if (param_2 == 5) {
        if ((DAT_004ac940 == 1) && (DAT_0049118c < 0xf)) {
          FUN_0046bf33(&param_1,s_3rd___5th_mark_00493500);
          local_4._0_1_ = 9;
          (**(code **)(*(int *)this + 100))(iVar6 + -0x28,iVar5 + 8,param_1);
          local_4 = (uint)local_4._1_3_ << 8;
          FUN_0046bec5((int *)&param_1);
        }
        if (((param_2 == 5) && (DAT_004ac940 == 1)) && (0xe < DAT_0049118c)) {
          FUN_0046bf33(&param_2,s_3rd___6th_mark_004934f0);
          local_4._0_1_ = 10;
          (**(code **)(*(int *)this + 100))(iVar6 + -0x28,iVar5 + 8,param_2);
          local_4 = (uint)local_4._1_3_ << 8;
          FUN_0046bec5(&param_2);
        }
      }
    }
  }
  FUN_0047033f(this,2);
  if ((DAT_004ac970 == 1) || (DAT_004ac974 == 1)) goto LAB_00430e7e;
  iVar4 = (DAT_004a72d0 * 2) / 5;
  iVar6 = iVar4;
  if (DAT_004aa804 == 1) {
    iVar6 = (DAT_004a72d0 * 3) / 5;
  }
  if (DAT_004aa804 == 2) {
    iVar6 = iVar4;
  }
  if (DAT_004aa804 == 3) {
    iVar6 = DAT_004a72d0 / 5;
  }
  iVar4 = 7;
  if (DAT_004aa804 == 4) {
    iVar4 = (DAT_004a763c << 2) / 5;
    iVar6 = (DAT_004a72d0 * 3) / 5;
  }
  if (DAT_004ac92c == 0) {
    iVar5 = *(int *)this;
    (**(code **)(iVar5 + 0x34))();
    (**(code **)(iVar5 + 0x38))(0xffff);
  }
  if (DAT_004a67ac != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(this + 4),DAT_004a67ac);
  }
  if (((DAT_004a4958 == 0) || (DAT_004a4958 == 6)) || (DAT_004a4958 == 7)) {
    FUN_00413d00(&param_4,DAT_004aa390);
    local_4._0_1_ = 0xb;
    FUN_0046c14f();
    local_4._0_1_ = 0xc;
    puVar1 = (undefined4 *)FUN_0046c0db();
    local_4._0_1_ = 0xd;
    (**(code **)(*(int *)this + 100))(iVar4,iVar6,*puVar1);
    local_4._0_1_ = 0xc;
    FUN_0046bec5(&param_2);
    local_4._0_1_ = 0xb;
    FUN_0046bec5((int *)&param_1);
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5(&param_4);
  }
  if ((0 < DAT_004a4958) && (DAT_004a4958 < 4)) {
    FUN_00413d00(&param_4,DAT_004aa390);
    local_4._0_1_ = 0xe;
    FUN_0046c14f();
    local_4._0_1_ = 0xf;
    puVar1 = (undefined4 *)FUN_0046c0db();
    local_4._0_1_ = 0x10;
    (**(code **)(*(int *)this + 100))(iVar4,iVar6,*puVar1);
    local_4._0_1_ = 0xf;
    FUN_0046bec5(&param_2);
    local_4._0_1_ = 0xe;
    FUN_0046bec5((int *)&param_1);
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5(&param_4);
  }
  if (DAT_004a4958 == 4) {
    FUN_00413d00(&param_4,DAT_004aa390);
    local_4._0_1_ = 0x11;
    FUN_0046c14f();
    local_4._0_1_ = 0x12;
    puVar1 = (undefined4 *)FUN_0046c0db();
    local_4._0_1_ = 0x13;
    (**(code **)(*(int *)this + 100))(iVar4,iVar6,*puVar1);
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
  iVar5 = iVar4 + 0x19;
  iVar7 = 5;
  param_4 = iVar5;
  iVar2 = FUN_00413cb0(DAT_004ac840);
  FUN_00430eb0(this,iVar5,iVar6 + 0x28,iVar2,iVar7);
  iVar6 = iVar6 + ((int)(DAT_004a72d0 + (DAT_004a72d0 >> 0x1f & 7U)) >> 3);
  param_2 = (DAT_004aa800 ^ (int)DAT_004aa800 >> 0x1f) - ((int)DAT_004aa800 >> 0x1f);
  piVar3 = FUN_00413d90(&param_2);
  local_4._0_1_ = 0x14;
  FUN_0046bfbe(&local_10,piVar3);
  local_4._0_1_ = 0;
  FUN_0046bec5(&param_2);
  if (((DAT_004a4958 == 0) || (DAT_004a4958 == 6)) || (DAT_004a4958 == 7)) {
    FUN_0046c14f();
    local_4._0_1_ = 0x15;
    puVar1 = (undefined4 *)FUN_0046c0db();
    local_4._0_1_ = 0x16;
    (**(code **)(*(int *)this + 100))(iVar4,iVar6,*puVar1);
    local_4._0_1_ = 0x15;
    FUN_0046bec5(&param_2);
    local_4._0_1_ = 0;
    FUN_0046bec5((int *)&param_1);
  }
  if (DAT_004a4958 == 4) {
    FUN_0046c14f();
    local_4._0_1_ = 0x17;
    puVar1 = (undefined4 *)FUN_0046c0db();
    local_4._0_1_ = 0x18;
    (**(code **)(*(int *)this + 100))(iVar4,iVar6,*puVar1);
    local_4._0_1_ = 0x17;
    FUN_0046bec5(&param_2);
    local_4._0_1_ = 0;
    FUN_0046bec5((int *)&param_1);
    iVar5 = param_4;
  }
  if (((DAT_004a4958 == 0) || (DAT_004a4958 == 4)) || ((DAT_004a4958 == 6 || (DAT_004a4958 == 7))))
  {
    iVar4 = DAT_004aae1c;
    if (DAT_004aa298 < 0) {
      iVar4 = DAT_004aae1c + 0xb4;
    }
    iVar2 = 5;
    iVar4 = FUN_00413cb0(iVar4);
    FUN_00430eb0(this,iVar5,iVar6 + 0x28,iVar4,iVar2);
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))();
  }
  FUN_0046bf33(&param_2,s_north_00493480);
  iVar4 = *(int *)this;
  local_4 = CONCAT31(local_4._1_3_,0x19);
  (**(code **)(iVar4 + 100))
            (DAT_004a763c + -0x46,DAT_004a72d0 / 7,param_2,*(undefined4 *)(param_2 + -8));
  FUN_0046bec5((int *)&pcStack_8);
  FUN_00430eb0(this,DAT_004a763c + -0x37,DAT_004a72d0 / 7 + 0x23,0xb4,5);
  (**(code **)(iVar4 + 0x38))(0);
  (**(code **)(iVar4 + 0x34))(0xffffff);
LAB_00430e7e:
  local_4 = 0xffffffff;
  FUN_0046bec5(&local_10);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

