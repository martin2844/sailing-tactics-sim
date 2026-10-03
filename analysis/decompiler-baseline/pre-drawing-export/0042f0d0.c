
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042f0d0(CDC *param_1,int param_2,int param_3,uint param_4,int param_5,int param_6)

{
  CDC *this;
  CDC *pCVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  float10 fVar8;
  int unaff_retaddr;
  int local_3c;
  int local_38;
  int local_34;
  int aiStack_2c [4];
  int aiStack_1c [4];
  undefined4 local_c;
  code *pcStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047e4b8;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  FUN_0046bd7a(&local_38);
  local_4 = 0;
  FUN_0046bd7a(&local_3c);
  iVar7 = param_2;
  this = param_1;
  local_4 = CONCAT31(local_4._1_3_,1);
  local_34 = (int)(longlong)(_DAT_004aa810 * _DAT_00485058);
  if ((((param_2 == -1) && (0 < DAT_004a4958)) && (DAT_004a4958 < 4)) ||
     (((param_2 == -1 && (DAT_00491158 == 0)) && (DAT_004a4958 != 4)))) {
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5(&local_3c);
    goto LAB_0042f90f;
  }
  FUN_0047033f(param_1,1);
  iVar5 = param_3;
  if (((DAT_004ac980 < 1) || (DAT_004ac980 == 2)) || (param_1 = (CDC *)0x1, DAT_004ac980 == 300)) {
    param_1 = (CDC *)0x0;
  }
  iVar6 = 0x1f;
  iVar7 = param_4 + 0x1e + iVar7 * 0x46;
  if (*(int *)(&DAT_004a4e88 + param_3 * 4) != 3) {
    iVar6 = param_5 + -10;
  }
  if (param_2 == -1) {
    iVar7 = 0xd2;
  }
  if (param_1 != (CDC *)0x0) {
    iVar6 = param_5 + 0x1f;
  }
  iVar4 = param_2;
  if (param_2 == 1) {
    iVar7 = param_6 - local_34;
    DAT_004aa7e0 = FUN_0042d0c0(param_3);
    fVar8 = FUN_0042c400((double)CONCAT44(*(undefined4 *)(&DAT_004a52f4 + DAT_004aa7e0 * 8),
                                          *(undefined4 *)(&DAT_004a52f0 + DAT_004aa7e0 * 8)),
                         (double)CONCAT44(*(undefined4 *)(&DAT_004a60b4 + DAT_004aa7e0 * 8),
                                          *(undefined4 *)(&DAT_004a60b0 + DAT_004aa7e0 * 8)),-1,
                         iVar5);
    iVar4 = 0xba - (int)(longlong)(fVar8 * (float10)_DAT_00484d78);
  }
  if (param_2 == 0) {
    iVar7 = param_4 + 0x1b;
    if (DAT_004ac9d8 == 0) {
      iVar4 = DAT_004a4800;
      if (iVar5 == 1) {
        iVar4 = DAT_004a47fc * DAT_004aa734 + DAT_004a475c;
      }
      else {
LAB_0042f28f:
        iVar4 = iVar4 * DAT_004aa738 + DAT_004a4770;
      }
    }
    else {
      iVar4 = DAT_004a7bd0;
      if (iVar5 != 1) goto LAB_0042f28f;
      iVar4 = DAT_004a7bcc * DAT_004aa734 + DAT_004a475c;
    }
    iVar4 = -iVar4;
    if (0 < (int)param_1) {
      iVar7 = DAT_004a763c + -0x28;
      iVar4 = DAT_004ac840;
    }
  }
  if (param_2 == -1) {
    iVar7 = local_34 + 2 + param_4;
    param_5 = FUN_00421560((int)(longlong)*(double *)(&DAT_004a49e8 + iVar5 * 8),
                           (uint)(longlong)*(double *)(&DAT_004a4ae0 + iVar5 * 8),iVar5);
    if (iVar5 == 1) {
      iVar5 = (DAT_004ac01c - DAT_004aa960) - DAT_004a475c;
    }
    else {
      iVar5 = (DAT_004ac020 - DAT_004aa960) - DAT_004a4770;
    }
    iVar4 = FUN_00413cb0(iVar5);
  }
  iVar5 = FUN_00413cb0(iVar4);
  iVar5 = FUN_00413cb0(iVar5);
  uVar2 = FUN_00413cb0(iVar5);
  param_4 = uVar2;
  if ((-1 < iVar5) && (iVar5 < 0x169)) {
    aiStack_1c[1] = iVar7 - ((&DAT_004a54a0)[iVar5] * 0x1a) / 100;
    aiStack_2c[1] = iVar6 - ((&DAT_004a3450)[iVar5] * 0x1a) / 300;
    iVar5 = FUN_00413cb0(uVar2 + 0x28);
    iVar5 = FUN_00413cb0(iVar5);
    aiStack_1c[2] = iVar7 - ((&DAT_004a54a0)[iVar5] * 0xd) / 100;
    aiStack_2c[2] = iVar6 - ((&DAT_004a3450)[iVar5] * 0xd) / 300;
    iVar5 = FUN_00413cb0(uVar2 - 0x28);
    iVar5 = FUN_00413cb0(iVar5);
    aiStack_1c[3] = iVar7 - ((&DAT_004a54a0)[iVar5] * 0xd) / 100;
    aiStack_2c[3] = iVar6 - ((&DAT_004a3450)[iVar5] * 0xd) / 300;
    if (DAT_004ac92c == 0) {
      if (DAT_004a621c != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(this + 4),DAT_004a621c);
      }
    }
    else {
      (**(code **)(*(int *)this + 0x2c))(4);
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
    (**(code **)(*(int *)this + 0x2c))(7);
    Ellipse(*(HDC *)(this + 4),iVar7 + -0x1a,iVar6 + -8,iVar7 + 0x1a,iVar6 + 8);
    if (DAT_004a4ee4 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a4ee4);
    }
    iVar5 = 0;
    do {
      FUN_004706bd(this,&local_38,iVar7,iVar6);
      CDC::LineTo(this,*(int *)((int)aiStack_1c + iVar5),*(int *)((int)aiStack_2c + iVar5));
      iVar5 = iVar5 + 4;
    } while (iVar5 < 9);
    iVar5 = iVar6 + -0x1a;
    if (900 < DAT_004a763c) {
      iVar5 = iVar6 + -0x1b;
    }
    if (DAT_004ac92c == 0) {
      iVar6 = *(int *)this;
      (**(code **)(iVar6 + 0x34))(0x7f7f00);
      (**(code **)(iVar6 + 0x38))(0xffff);
    }
    if (DAT_004ac98c == 1) {
      (**(code **)(*(int *)this + 0x34))(0x7f7f7f);
    }
    pCVar1 = param_1;
    if ((param_1 == (CDC *)0x0) && (unaff_retaddr == 0)) {
      if (DAT_004ac9d8 == 0) {
        piVar3 = FUN_00413d00(&param_1,*(uint *)(&DAT_004ab9e8 + param_2 * 4));
        pcStack_8._0_1_ = 2;
        FUN_0046bfbe(&local_3c,piVar3);
        pcStack_8._0_1_ = 1;
        FUN_0046bec5((int *)&param_1);
        piVar3 = (int *)FUN_0046c14f();
        pcStack_8._0_1_ = 3;
        (**(code **)(*(int *)this + 100))(iVar7 + -0x18,iVar5,*piVar3,*(undefined4 *)(*piVar3 + -8))
        ;
      }
      else {
        piVar3 = FUN_00413d00(&param_1,*(uint *)(&DAT_004a6338 + param_2 * 4));
        pcStack_8._0_1_ = 4;
        FUN_0046bfbe(&local_3c,piVar3);
        pcStack_8._0_1_ = 1;
        FUN_0046bec5((int *)&param_1);
        piVar3 = (int *)FUN_0046c14f();
        pcStack_8._0_1_ = 5;
        (**(code **)(*(int *)this + 100))(iVar7 + -0x18,iVar5,*piVar3,*(undefined4 *)(*piVar3 + -8))
        ;
      }
      pcStack_8 = (code *)CONCAT31(pcStack_8._1_3_,1);
      FUN_0046bec5((int *)&param_1);
    }
    if (0 < unaff_retaddr) {
      FUN_0046bf33(&param_1,&DAT_00493468);
      pcStack_8._0_1_ = 6;
      (**(code **)(*(int *)this + 100))(iVar7 + -0xc,iVar5,param_1,*(undefined4 *)(param_1 + -8));
      pcStack_8 = (code *)CONCAT31(pcStack_8._1_3_,1);
      FUN_0046bec5((int *)&param_1);
    }
    if (pCVar1 == (CDC *)0x1) {
      FUN_0046bf33(&param_1,&DAT_00493460);
      pcStack_8._0_1_ = 7;
      (**(code **)(*(int *)this + 100))(iVar7 + -0xf,iVar5,param_1,*(undefined4 *)(param_1 + -8));
      pcStack_8 = (code *)CONCAT31(pcStack_8._1_3_,1);
      FUN_0046bec5((int *)&param_1);
    }
    if (pCVar1 == (CDC *)0xffffffff) {
      if (DAT_004a4958 != 4) {
        FUN_0046c00d(&stack0xffffffc0,s_tide_00493458);
      }
      if (DAT_004a4958 == 4) {
        if (700 < DAT_004a763c) {
          FUN_0046c00d(&stack0xffffffc0,s_current_0049344c);
        }
        if ((DAT_004a4958 == 4) && (DAT_004a763c < 0x2bd)) {
          FUN_0046c00d(&stack0xffffffc0,s_curr_00493444);
        }
      }
      iVar6 = (param_4 ^ (int)param_4 >> 0x1f) - ((int)param_4 >> 0x1f);
      param_1 = FUN_00413d00(&param_5,iVar6 % 10);
      pcStack_8._0_1_ = 8;
      FUN_00413d00(&param_4,iVar6 / 10);
      pcStack_8._0_1_ = 9;
      FUN_0046c075();
      pcStack_8._0_1_ = 10;
      FUN_0046c0db();
      pcStack_8._0_1_ = 0xb;
      piVar3 = (int *)FUN_0046c075();
      pcStack_8._0_1_ = 0xc;
      (**(code **)(*(int *)this + 100))(iVar7 + -0x19,iVar5,*piVar3,*(undefined4 *)(*piVar3 + -8));
      pcStack_8._0_1_ = 0xb;
      FUN_0046bec5(&param_2);
      pcStack_8._0_1_ = 10;
      FUN_0046bec5(&param_3);
      pcStack_8._0_1_ = 9;
      FUN_0046bec5((int *)&stack0x00000000);
      pcStack_8._0_1_ = 8;
      FUN_0046bec5((int *)&param_4);
      pcStack_8 = (code *)CONCAT31(pcStack_8._1_3_,1);
      FUN_0046bec5(&param_5);
    }
    FUN_0047033f(this,2);
    iVar7 = *(int *)this;
    (**(code **)(iVar7 + 0x34))(0xffffff);
    (**(code **)(iVar7 + 0x38))(0);
  }
  local_4 = local_4 & 0xffffff00;
  FUN_0046bec5(&local_3c);
LAB_0042f90f:
  local_4 = 0xffffffff;
  FUN_0046bec5(&local_38);
  *unaff_FS_OFFSET = local_c;
  return;
}

