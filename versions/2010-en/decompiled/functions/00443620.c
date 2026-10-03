
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00443620(Tact2010CString param_1,Tact2010CString param_2,int param_3,
                 Tact2010CString param_4)

{
  Tact2010CString original_dc;
  Tact2010CString TVar1;
  Tact2010CString TVar2;
  Tact2010CString *pTVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int iVar7;
  Tact2010CString local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c3300;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_004b045a(&local_10);
  original_dc.data = param_1.data;
  local_4._0_1_ = 0;
  local_4._1_3_ = 0;
  FUN_004b4a1f((int *)param_1.data,1);
  if (DAT_005363e4 == 0) {
    iVar5 = *(int *)original_dc.data;
    (**(code **)(iVar5 + 0x34))((int *)original_dc.data,0xff0000);
    (**(code **)(iVar5 + 0x38))((int *)original_dc.data,0xffff);
  }
  TVar2.data = param_4.data;
  iVar5 = param_3;
  TVar1.data = param_2.data;
  if ((param_2.data == (char *)0x2) && ((DAT_004f452c == 0 || (DAT_0053527c == 0)))) {
    FUN_004b0613(&param_1,"start & finish line");
    local_4._0_1_ = 1;
    (**(code **)(*(int *)original_dc.data + 100))
              ((int *)original_dc.data,iVar5 + -0x32,(int)(TVar2.data + 0xd),param_1.data,
               *(int *)(param_1.data + -8));
    local_4._0_1_ = 0;
    FUN_004b05a5(&param_1);
  }
  if ((((TVar1.data == (char *)0x1) && (DAT_0053527c == 1)) && (DAT_00536408 == 1)) &&
     (((DAT_004fe2b4 == 0 && (10 < DAT_004f8cd0)) && (DAT_004da1e8 == 0)))) {
    if (DAT_004da194 < 0xf) {
      FUN_004b0613(&param_1,"2nd mark");
      local_4._0_1_ = 2;
      (**(code **)(*(int *)original_dc.data + 100))
                ((int *)original_dc.data,iVar5 + 6,(int)(TVar2.data + -0xf),param_1.data,
                 *(int *)(param_1.data + -8));
    }
    else {
      FUN_004b0613(&param_1,"3rd mark");
      local_4._0_1_ = 3;
      (**(code **)(*(int *)original_dc.data + 100))
                ((int *)original_dc.data,iVar5 + 6,(int)(TVar2.data + -0xf),param_1.data,
                 *(int *)(param_1.data + -8));
    }
    local_4._0_1_ = 0;
    FUN_004b05a5(&param_1);
  }
  if (TVar1.data == (char *)0x3) {
    if (DAT_005363f8 == 0) {
      FUN_004b0613(&param_1,"1st mark");
      local_4._0_1_ = 4;
      (**(code **)(*(int *)original_dc.data + 100))
                ((int *)original_dc.data,iVar5 + 6,(int)(TVar2.data + -0xf),param_1.data,
                 *(int *)(param_1.data + -8));
      local_4._0_1_ = 0;
      FUN_004b05a5(&param_1);
    }
    if (DAT_005363f8 == 1) {
      if ((DAT_004f7f94 < 0xb5) || (0x13f < DAT_004f7f94)) {
        FUN_004b0613(&param_1,"1st & 4th mark");
        local_4._0_1_ = 6;
        (**(code **)(*(int *)original_dc.data + 100))
                  ((int *)original_dc.data,iVar5 + 6,(int)(TVar2.data + -0xf),param_1.data,
                   *(int *)(param_1.data + -8));
      }
      else {
        FUN_004b0613(&param_1,"1st & 4th mark");
        local_4._0_1_ = 5;
        (**(code **)(*(int *)original_dc.data + 100))
                  ((int *)original_dc.data,iVar5 + -0x5a,(int)(TVar2.data + -0x16),param_1.data,
                   *(int *)(param_1.data + -8));
      }
      local_4._0_1_ = 0;
      FUN_004b05a5(&param_1);
    }
  }
  if ((DAT_005362d4 < 0xa1) || (199 < DAT_005362d4)) {
    param_1.data = TVar2.data + -7;
    iVar4 = iVar5 + -0x46;
  }
  else {
    param_1.data = TVar2.data + 10;
    iVar4 = iVar5;
  }
  if (param_2.data == (char *)0x4) {
    if (((DAT_004da168 * DAT_005363f8 != 1) && (0xf < DAT_004da194)) && (DAT_004da1f8 != 5)) {
      FUN_004b0613(&param_4,"2nd mark");
      local_4._0_1_ = 7;
      (**(code **)(*(int *)original_dc.data + 100))
                ((int *)original_dc.data,iVar4,(int)param_1.data,param_4.data,
                 *(int *)(param_4.data + -8));
      local_4._0_1_ = 0;
      FUN_004b05a5(&param_4);
    }
    if (((param_2.data == (char *)0x4) && (DAT_005363f8 == 1)) &&
       ((DAT_004da168 == 1 && (0xe < DAT_004da194)))) {
      FUN_004b0613(&param_4,"5th mark");
      local_4._0_1_ = 8;
      (**(code **)(*(int *)original_dc.data + 100))
                ((int *)original_dc.data,iVar4,(int)param_1.data,param_4.data,
                 *(int *)(param_4.data + -8));
      local_4._0_1_ = 0;
      FUN_004b05a5(&param_4);
    }
  }
  if (param_2.data == &DAT_00000005) {
    if (((DAT_004da168 == 0) && (DAT_005363f8 == 0)) && (DAT_0053527c == 0)) {
      FUN_004b0613(&param_1,"3rd mark");
      local_4._0_1_ = 9;
      (**(code **)(*(int *)original_dc.data + 100))
                ((int *)original_dc.data,iVar5 + -0x28,(int)(TVar2.data + 8),param_1.data,
                 *(int *)(param_1.data + -8));
      local_4._0_1_ = 0;
      FUN_004b05a5(&param_1);
    }
    if ((((param_2.data == &DAT_00000005) && (DAT_004da168 == 1)) && (DAT_005363f8 == 0)) &&
       ((0xe < DAT_004da194 && (DAT_0053527c == 0)))) {
      if (DAT_004f452c == 0) {
        FUN_004b0613(&param_1,"3rd mark");
        local_4._0_1_ = 10;
        (**(code **)(*(int *)original_dc.data + 100))
                  ((int *)original_dc.data,iVar5 + -0x28,(int)(TVar2.data + 8),param_1.data,
                   *(int *)(param_1.data + -8));
      }
      else {
        FUN_004b0613(&param_1,&DAT_004dd80c);
        local_4._0_1_ = 0xb;
        (**(code **)(*(int *)original_dc.data + 100))
                  ((int *)original_dc.data,iVar5 + -0x28,(int)(TVar2.data + 8),param_1.data,
                   *(int *)(param_1.data + -8));
      }
      local_4._0_1_ = 0;
      FUN_004b05a5(&param_1);
    }
  }
  TVar1.data = param_2.data;
  if (DAT_0053527c == 1) {
    if (param_2.data == &DAT_00000005) {
      if (((DAT_00536408 == 1) && (0xe < DAT_004da194)) && (DAT_004f452c == 1)) {
        FUN_004b0613(&param_2,&DAT_004dd80c);
        local_4._0_1_ = 0xc;
        (**(code **)(*(int *)original_dc.data + 100))
                  ((int *)original_dc.data,iVar5 + -0x28,(int)(TVar2.data + -8),param_2.data,
                   *(int *)(param_2.data + -8));
        local_4._0_1_ = 0;
        FUN_004b05a5(&param_2);
      }
      goto LAB_00443adf;
    }
  }
  else {
LAB_00443adf:
    if (TVar1.data == &DAT_00000005) {
      if ((DAT_005363f8 == 1) && (DAT_004da194 < 0xf)) {
        FUN_004b0613(&param_2,"3rd & 5th mark");
        local_4._0_1_ = 0xd;
        (**(code **)(*(int *)original_dc.data + 100))
                  ((int *)original_dc.data,iVar5 + -0x28,(int)(TVar2.data + 8),param_2.data,
                   *(int *)(param_2.data + -8));
        local_4._0_1_ = 0;
        FUN_004b05a5(&param_2);
      }
      if ((DAT_005363f8 == 1) && (0xe < DAT_004da194)) {
        if (DAT_004f452c == 0) {
          FUN_004b0613(&param_2,"3rd & 6th mark");
          local_4._0_1_ = 0xe;
          (**(code **)(*(int *)original_dc.data + 100))
                    ((int *)original_dc.data,iVar5 + -0x28,(int)(TVar2.data + 8),param_2.data,
                     *(int *)(param_2.data + -8));
        }
        else {
          FUN_004b0613(&param_2,&DAT_004dd80c);
          local_4._0_1_ = 0xf;
          (**(code **)(*(int *)original_dc.data + 100))
                    ((int *)original_dc.data,iVar5 + -0x28,(int)(TVar2.data + 8),param_2.data,
                     *(int *)(param_2.data + -8));
        }
        local_4._0_1_ = 0;
        FUN_004b05a5(&param_2);
      }
    }
  }
  FUN_004b4a1f((int *)original_dc.data,2);
  if ((DAT_00536434 == 1) || (DAT_00536438 == 1)) goto LAB_00444249;
  param_2.data = (char *)((DAT_004fe2a8 * 2) / 5);
  pcVar6 = param_2.data;
  if (DAT_005230dc == 1) {
    pcVar6 = (char *)((DAT_004fe2a8 * 3) / 5);
  }
  if (DAT_005230dc == 2) {
    pcVar6 = param_2.data;
  }
  if (DAT_005230dc == 3) {
    pcVar6 = (char *)(DAT_004fe2a8 / 5);
  }
  iVar5 = 7;
  if (DAT_005230dc == 4) {
    iVar5 = (DAT_004fe624 * 4) / 5;
    pcVar6 = (char *)((DAT_004fe2a8 * 3) / 5);
  }
  if (DAT_004da1f8 == 0x68) {
    iVar5 = (DAT_004fe624 * 5) / 6;
    pcVar6 = (char *)((DAT_004fe2a8 * 3) / 5);
  }
  if (DAT_004da1f8 == 0x6a) {
    iVar5 = (DAT_004fe624 * 5) / 6;
    pcVar6 = (char *)((DAT_004fe2a8 << 2) / 5);
  }
  if (DAT_004da1f8 == 0xb) {
    iVar5 = (DAT_004fe624 * 5) / 6;
    pcVar6 = param_2.data;
  }
  if (DAT_005363e4 == 0) {
    iVar4 = *(int *)original_dc.data;
    (**(code **)(iVar4 + 0x34))((int *)original_dc.data,0);
    (**(code **)(iVar4 + 0x38))((int *)original_dc.data,0xffff);
  }
  if (DAT_004fba14 != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)(original_dc.data + 4),DAT_004fba14);
  }
  if (((DAT_004f69b8 == 0) || (DAT_004f69b8 == 6)) || (DAT_004f69b8 == 7)) {
    pTVar3 = FUN_0041bc70(&param_4,DAT_00522ad0);
    local_4._0_1_ = 0x10;
    pTVar3 = FUN_004b082f(&param_1," wind offshore: ",pTVar3);
    local_4._0_1_ = 0x11;
    pTVar3 = FUN_004b07bb(&param_2,pTVar3,&DAT_004da2bc);
    local_4._0_1_ = 0x12;
    (**(code **)(*(int *)original_dc.data + 100))
              ((int *)original_dc.data,iVar5,(int)pcVar6,pTVar3->data,*(int *)(pTVar3->data + -8));
    local_4._0_1_ = 0x11;
    FUN_004b05a5(&param_2);
    local_4._0_1_ = 0x10;
    FUN_004b05a5(&param_1);
    local_4._0_1_ = 0;
    FUN_004b05a5(&param_4);
  }
  if ((0 < DAT_004f69b8) && (DAT_004f69b8 < 4)) {
    pTVar3 = FUN_0041bc70(&param_4,DAT_00522ad0);
    local_4._0_1_ = 0x13;
    pTVar3 = FUN_004b082f(&param_1,s_mid_lake_wind__004dd7c4,pTVar3);
    local_4._0_1_ = 0x14;
    pTVar3 = FUN_004b07bb(&param_2,pTVar3,&DAT_004da2bc);
    local_4._0_1_ = 0x15;
    (**(code **)(*(int *)original_dc.data + 100))
              ((int *)original_dc.data,iVar5,(int)pcVar6,pTVar3->data,*(int *)(pTVar3->data + -8));
    local_4._0_1_ = 0x14;
    FUN_004b05a5(&param_2);
    local_4._0_1_ = 0x13;
    FUN_004b05a5(&param_1);
    local_4._0_1_ = 0;
    FUN_004b05a5(&param_4);
  }
  if (DAT_004f69b8 == 4) {
    pTVar3 = FUN_0041bc70(&param_4,DAT_00522ad0);
    local_4._0_1_ = 0x16;
    pTVar3 = FUN_004b082f(&param_1,s_mid_river_wind__004dd7b0,pTVar3);
    local_4._0_1_ = 0x17;
    pTVar3 = FUN_004b07bb(&param_2,pTVar3,&DAT_004da2bc);
    local_4._0_1_ = 0x18;
    (**(code **)(*(int *)original_dc.data + 100))
              ((int *)original_dc.data,iVar5,(int)pcVar6,pTVar3->data,*(int *)(pTVar3->data + -8));
    local_4._0_1_ = 0x17;
    FUN_004b05a5(&param_2);
    local_4._0_1_ = 0x16;
    FUN_004b05a5(&param_1);
    local_4._0_1_ = 0;
    FUN_004b05a5(&param_4);
  }
  if ((DAT_004da1f8 == 999) && (DAT_00536438 == 0)) {
    pTVar3 = FUN_0041bc70(&param_4,DAT_00522ad0);
    local_4._0_1_ = 0x19;
    pTVar3 = FUN_004b082f(&param_1,s_mid_area_wind__004dd79c,pTVar3);
    local_4._0_1_ = 0x1a;
    pTVar3 = FUN_004b07bb(&param_2,pTVar3,&DAT_004da2bc);
    local_4._0_1_ = 0x1b;
    (**(code **)(*(int *)original_dc.data + 100))
              ((int *)original_dc.data,iVar5,(int)pcVar6,pTVar3->data,*(int *)(pTVar3->data + -8));
    local_4._0_1_ = 0x1a;
    FUN_004b05a5(&param_2);
    local_4._0_1_ = 0x19;
    FUN_004b05a5(&param_1);
    local_4._0_1_ = 0;
    FUN_004b05a5(&param_4);
  }
  if (DAT_005363e4 == 0) {
    if (DAT_004fba14 != (HGDIOBJ)0x0) {
      hdc = *(HDC *)(original_dc.data + 4);
      h = DAT_004fba14;
override_prt_443fe3_6059bb06:
      SelectObject(hdc,h);
    }
  }
  else if (DAT_004f7ec4 != (HGDIOBJ)0x0) {
    hdc = *(HDC *)(original_dc.data + 4);
    h = DAT_004f7ec4;
    goto override_prt_443fe3_6059bb06;
  }
  iVar7 = 5;
  param_4.data = (char *)(iVar5 + 0x19);
  iVar4 = FUN_0041bc20(DAT_005362d4);
  FUN_00444270((int *)original_dc.data,iVar5 + 0x19,(int)(pcVar6 + 0x28),iVar4,iVar7);
  pcVar6 = pcVar6 + ((int)(DAT_004fe2a8 + (DAT_004fe2a8 >> 0x1f & 7U)) >> 3);
  if (DAT_004da1f8 == 0) {
    param_2.data = (char *)((DAT_005230d8 ^ (int)DAT_005230d8 >> 0x1f) - ((int)DAT_005230d8 >> 0x1f)
                           );
    pTVar3 = FUN_0041bd00(&param_2,(double)(int)param_2.data * _DAT_004cc570);
    local_4._0_1_ = 0x1c;
    FUN_004b069e(&local_10,pTVar3);
    local_4._0_1_ = 0;
    FUN_004b05a5(&param_2);
    if (((DAT_004f69b8 == 0) || (DAT_004f69b8 == 6)) || (DAT_004f69b8 == 7)) {
      pTVar3 = FUN_004b082f(&param_1," tide offshore: ",&local_10);
      local_4._0_1_ = 0x1d;
      pTVar3 = FUN_004b07bb(&param_2,pTVar3,&DAT_004da2bc);
      local_4._0_1_ = 0x1e;
      (**(code **)(*(int *)original_dc.data + 100))
                ((int *)original_dc.data,iVar5,(int)pcVar6,pTVar3->data,*(int *)(pTVar3->data + -8))
      ;
      local_4._0_1_ = 0x1d;
      FUN_004b05a5(&param_2);
      local_4._0_1_ = 0;
      FUN_004b05a5(&param_1);
    }
    if (DAT_004f69b8 == 4) {
      pTVar3 = FUN_004b082f(&param_1,s_mid_river_current__004dd770,&local_10);
      local_4._0_1_ = 0x1f;
      pTVar3 = FUN_004b07bb(&param_2,pTVar3,&DAT_004da2bc);
      local_4._0_1_ = 0x20;
      (**(code **)(*(int *)original_dc.data + 100))
                ((int *)original_dc.data,iVar5,(int)pcVar6,pTVar3->data,*(int *)(pTVar3->data + -8))
      ;
      local_4._0_1_ = 0x1f;
      FUN_004b05a5(&param_2);
      local_4._0_1_ = 0;
      FUN_004b05a5(&param_1);
    }
    if (((DAT_004f69b8 == 0) || (DAT_004f69b8 == 4)) || ((DAT_004f69b8 == 6 || (DAT_004f69b8 == 7)))
       ) {
      iVar5 = DAT_00523a54;
      if (DAT_005229d8 < 0) {
        iVar5 = DAT_00523a54 + 0xb4;
      }
      iVar4 = 5;
      iVar5 = FUN_0041bc20(iVar5);
      FUN_00444270((int *)original_dc.data,(int)param_4.data,(int)(pcVar6 + 0x28),iVar5,iVar4);
    }
  }
  if (DAT_005363e4 == 0) {
    (**(code **)(*(int *)original_dc.data + 0x38))((int *)original_dc.data,0xffff);
  }
  FUN_004b0613(&param_2," north ");
  iVar5 = *(int *)original_dc.data;
  local_4._0_1_ = 0x21;
  (**(code **)(iVar5 + 100))
            ((int *)original_dc.data,DAT_004fe624 + -0x46,DAT_004fe2a8 / 7,param_2.data,
             *(int *)(param_2.data + -8));
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_004b05a5(&param_2);
  FUN_00444270((int *)original_dc.data,DAT_004fe624 + -0x37,DAT_004fe2a8 / 7 + 0x23,0xb4,5);
  (**(code **)(iVar5 + 0x38))((int *)original_dc.data,0);
  (**(code **)(iVar5 + 0x34))((int *)original_dc.data,0xffffff);
LAB_00444249:
  local_4 = 0xffffffff;
  FUN_004b05a5(&local_10);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

