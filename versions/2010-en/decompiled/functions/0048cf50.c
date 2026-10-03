
void __cdecl FUN_0048cf50(int *param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  code *pcVar3;
  int *original_dc;
  undefined4 *unaff_FS_OFFSET;
  int iVar4;
  int local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  original_dc = param_1;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c6240;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  local_10 = 0x10;
  if (((DAT_004fe624 < 1000) && (local_10 = 0xf, DAT_004fe624 < 1000)) && (DAT_005363f0 == 1)) {
    local_10 = 0xd;
  }
  iVar1 = *param_1;
  pcVar2 = *(code **)(iVar1 + 0x38);
  if (DAT_005363e4 == 0) {
    iVar4 = 0xff;
  }
  else {
    iVar4 = 0;
  }
  (*pcVar2)(param_1,iVar4);
  if ((DAT_005363e4 == 0) && (DAT_005364fc == 0)) {
    (*pcVar2)(original_dc,0x7f);
  }
  FUN_004b4a1f(original_dc,2);
  (**(code **)(iVar1 + 0x34))(original_dc,0xffffff);
  FUN_004b0613((Tact2010CString *)&param_1," Personal Race Area Selections:");
  iVar4 = param_2;
  pcVar3 = *(code **)(iVar1 + 100);
  uStack_4 = 0;
  (*pcVar3)(original_dc,10,param_2,(char *)param_1,param_1[-2]);
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_1);
  FUN_004b4a1f(original_dc,1);
  if (DAT_005363e4 == 0) {
    (*pcVar2)(original_dc,0x7fff);
  }
  param_1 = (int *)(((int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 3U)) >> 2) + 0x55);
  if (DAT_004da238 == 0x5dc) {
    FUN_004b0613((Tact2010CString *)&param_2,s_Small_racing_area__004ed41c);
    uStack_4 = 1;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  if (DAT_004da238 == 2000) {
    FUN_004b0613((Tact2010CString *)&param_2,"Medium size racing area.");
    uStack_4 = 2;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  if (DAT_004da238 == 0x9c4) {
    FUN_004b0613((Tact2010CString *)&param_2,s_Large_racing_area__004ed3ec);
    uStack_4 = 3;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  iVar4 = iVar4 + local_10;
  if (DAT_005363e4 == 0) {
    (*pcVar2)(original_dc,0xffff);
  }
  if (DAT_004da248 == 2) {
    if (DAT_004da23c == 0) {
      FUN_004b0613((Tact2010CString *)&param_1,"Very Near primary shore to the North.");
      uStack_4 = 4;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x2d) {
      FUN_004b0613((Tact2010CString *)&param_1,"Very Near primary shore to the Northeast.");
      uStack_4 = 5;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x5a) {
      FUN_004b0613((Tact2010CString *)&param_1,"Very Near primary shore to the East.");
      uStack_4 = 6;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x87) {
      FUN_004b0613((Tact2010CString *)&param_1,"Very Near primary shore to the Southeast.");
      uStack_4 = 7;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0xb4) {
      FUN_004b0613((Tact2010CString *)&param_1,"Very Near primary shore to the South.");
      uStack_4 = 8;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0xe1) {
      FUN_004b0613((Tact2010CString *)&param_1,"Very Near primary shore to the Southwest.");
      uStack_4 = 9;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x10e) {
      FUN_004b0613((Tact2010CString *)&param_1,"Very Near primary shore to the West.");
      uStack_4 = 10;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x13b) {
      FUN_004b0613((Tact2010CString *)&param_1,"Very Near primary shore to the Northwest.");
      uStack_4 = 0xb;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
  }
  if (DAT_004da248 == 1) {
    if (DAT_004da23c == 0) {
      FUN_004b0613((Tact2010CString *)&param_1,"Nearby primary shore to the North.");
      uStack_4 = 0xc;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x2d) {
      FUN_004b0613((Tact2010CString *)&param_1,"Nearby primary shore to the Northeast.");
      uStack_4 = 0xd;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x5a) {
      FUN_004b0613((Tact2010CString *)&param_1,"Nearby primary shore to the East.");
      uStack_4 = 0xe;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x87) {
      FUN_004b0613((Tact2010CString *)&param_1,"Nearby primary shore to the Southeast.");
      uStack_4 = 0xf;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0xb4) {
      FUN_004b0613((Tact2010CString *)&param_1,"Nearby primary shore to the South.");
      uStack_4 = 0x10;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0xe1) {
      FUN_004b0613((Tact2010CString *)&param_1,"Nearby primary shore to the Southwest.");
      uStack_4 = 0x11;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x10e) {
      FUN_004b0613((Tact2010CString *)&param_1,"Nearby primary shore to the West.");
      uStack_4 = 0x12;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x13b) {
      FUN_004b0613((Tact2010CString *)&param_1,"Nearby primary shore to the Northwest.");
      uStack_4 = 0x13;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
  }
  if (DAT_004da248 == 0) {
    if (DAT_004da23c == 0) {
      FUN_004b0613((Tact2010CString *)&param_1,"Primary shore to the North.");
      uStack_4 = 0x14;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x2d) {
      FUN_004b0613((Tact2010CString *)&param_1,"Primary shore to the Northeast.");
      uStack_4 = 0x15;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x5a) {
      FUN_004b0613((Tact2010CString *)&param_1,"Primary shore to the East.");
      uStack_4 = 0x16;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x87) {
      FUN_004b0613((Tact2010CString *)&param_1,"Primary shore to the Southeast.");
      uStack_4 = 0x17;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0xb4) {
      FUN_004b0613((Tact2010CString *)&param_1,"Primary shore to the South.");
      uStack_4 = 0x18;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0xe1) {
      FUN_004b0613((Tact2010CString *)&param_1,"Primary shore to the Southwest.");
      uStack_4 = 0x19;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x10e) {
      FUN_004b0613((Tact2010CString *)&param_1,"Primary shore to the West.");
      uStack_4 = 0x1a;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da23c == 0x13b) {
      FUN_004b0613((Tact2010CString *)&param_1,"Primary shore to the Northwest.");
      uStack_4 = 0x1b;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
  }
  param_1 = (int *)(((int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 3U)) >> 2) + 0x55);
  if ((DAT_004da240 == 0) && (DAT_004da244 == 0)) {
    FUN_004b0613((Tact2010CString *)&param_2,"Straight primary shoreline.");
    uStack_4 = 0x1c;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  if ((DAT_004da240 == 1) && (DAT_004da244 == 1)) {
    FUN_004b0613((Tact2010CString *)&param_2,"Concave primary shoreline.");
    uStack_4 = 0x1d;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  if (DAT_004da240 == -1) {
    if (DAT_004da244 == -1) {
      FUN_004b0613((Tact2010CString *)&param_2,"Convex primary shoreline.");
      uStack_4 = 0x1e;
      (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if ((DAT_004da240 == -1) && (DAT_004da244 == 1)) {
      FUN_004b0613((Tact2010CString *)&param_2,"S shape primary shoreline.");
      uStack_4 = 0x1f;
      (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
  }
  if ((DAT_004da240 == 1) && (DAT_004da244 == -1)) {
    FUN_004b0613((Tact2010CString *)&param_2,"Reverse S shape primary shoreline.");
    uStack_4 = 0x20;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  param_1 = (int *)((DAT_004fe624 * 2) / 3 + 0x32);
  if ((DAT_004da24c == 0) && (DAT_004da250 == 0)) {
    FUN_004b0613((Tact2010CString *)&param_2,"Flat and Wilderness.");
    uStack_4 = 0x21;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  if ((DAT_004da24c == 1) && (DAT_004da250 == 0)) {
    FUN_004b0613((Tact2010CString *)&param_2,"Hilly and Wilderness.");
    uStack_4 = 0x22;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  if ((DAT_004da24c == 0) && (DAT_004da250 == 1)) {
    FUN_004b0613((Tact2010CString *)&param_2,"Flat and Rural.");
    uStack_4 = 0x23;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  if ((DAT_004da24c == 1) && (DAT_004da250 == 1)) {
    FUN_004b0613((Tact2010CString *)&param_2,s_Hilly_and_Rural__004ecf94);
    uStack_4 = 0x24;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  if ((DAT_004da24c == 0) && (DAT_004da250 == 2)) {
    FUN_004b0613((Tact2010CString *)&param_2,"Flat and Urban.");
    uStack_4 = 0x25;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  if ((DAT_004da24c == 1) && (DAT_004da250 == 2)) {
    FUN_004b0613((Tact2010CString *)&param_2,"Hilly and Urban.");
    uStack_4 = 0x26;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  if (5 < DAT_00522f08) {
    iVar4 = iVar4 + 0xf;
    if (DAT_005363e4 == 0) {
      (*pcVar2)(original_dc,0x7fff);
    }
    if (DAT_004da260 == 1) {
      if (DAT_004da25c == 0) {
        FUN_004b0613((Tact2010CString *)&param_1,"Nearby secondary land to the North.");
        uStack_4 = 0x27;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004da25c == 0x2d) {
        FUN_004b0613((Tact2010CString *)&param_1,"Nearby secondary land to the Northeast.");
        uStack_4 = 0x28;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004da25c == 0x5a) {
        FUN_004b0613((Tact2010CString *)&param_1,"Nearby secondary land to the East.");
        uStack_4 = 0x29;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004da25c == 0x87) {
        FUN_004b0613((Tact2010CString *)&param_1,"Nearby secondary land to the Southeast.");
        uStack_4 = 0x2a;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004da25c == 0xb4) {
        FUN_004b0613((Tact2010CString *)&param_1,"Nearby secondary land to the South.");
        uStack_4 = 0x2b;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004da25c == 0xe1) {
        FUN_004b0613((Tact2010CString *)&param_1,"Nearby secondary land to the Southwest.");
        uStack_4 = 0x2c;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004da25c == 0x10e) {
        FUN_004b0613((Tact2010CString *)&param_1,"Nearby secondary land to the West.");
        uStack_4 = 0x2d;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004da25c == 0x13b) {
        FUN_004b0613((Tact2010CString *)&param_1,"Nearby secondary land to the Northwest.");
        uStack_4 = 0x2e;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
LAB_0048de8e:
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
    }
    else {
      if (DAT_004da25c == 0) {
        FUN_004b0613((Tact2010CString *)&param_1,"Secondary land to the North.");
        uStack_4 = 0x2f;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004da25c == 0x2d) {
        FUN_004b0613((Tact2010CString *)&param_1,"Secondary land to the Northeast.");
        uStack_4 = 0x30;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004da25c == 0x5a) {
        FUN_004b0613((Tact2010CString *)&param_1,"Secondary land to the East.");
        uStack_4 = 0x31;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004da25c == 0x87) {
        FUN_004b0613((Tact2010CString *)&param_1,"Secondary land to the Southeast.");
        uStack_4 = 0x32;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004da25c == 0xb4) {
        FUN_004b0613((Tact2010CString *)&param_1,"Secondary land to the South.");
        uStack_4 = 0x33;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004da25c == 0xe1) {
        FUN_004b0613((Tact2010CString *)&param_1,"Secondary land to the Southwest.");
        uStack_4 = 0x34;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004da25c == 0x10e) {
        FUN_004b0613((Tact2010CString *)&param_1,"Secondary land to the West.");
        uStack_4 = 0x35;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_1);
      }
      if (DAT_004da25c == 0x13b) {
        FUN_004b0613((Tact2010CString *)&param_1,"Secondary land to the Northwest.");
        uStack_4 = 0x36;
        (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
        goto LAB_0048de8e;
      }
    }
    param_1 = (int *)(((int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 3U)) >> 2) + 0x55);
    if (DAT_00522f08 == 6) {
      FUN_004b0613((Tact2010CString *)&param_2,"One Island.");
      uStack_4 = 0x37;
      (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if (DAT_00522f08 == 8) {
      FUN_004b0613((Tact2010CString *)&param_2,"Three Islands.");
      uStack_4 = 0x38;
      (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if (DAT_00522f08 == 10) {
      FUN_004b0613((Tact2010CString *)&param_2,"Solid land.");
      uStack_4 = 0x39;
      (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    param_1 = (int *)(DAT_004fe624 / 3 + 0x87);
    if (6 < DAT_00522f08) {
      if ((DAT_004da254 == 0) && (DAT_004da258 == 0)) {
        FUN_004b0613((Tact2010CString *)&param_2,"Straight secondary land.");
        uStack_4 = 0x3a;
        (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_2);
      }
      if ((DAT_004da254 == 1) && (DAT_004da258 == 1)) {
        FUN_004b0613((Tact2010CString *)&param_2,"Concave secondary land.");
        uStack_4 = 0x3b;
        (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_2);
      }
      if (DAT_004da254 == -1) {
        if (DAT_004da258 == -1) {
          FUN_004b0613((Tact2010CString *)&param_2,"Convex secondary land.");
          uStack_4 = 0x3c;
          (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_2);
        }
        if ((DAT_004da254 == -1) && (DAT_004da258 == 1)) {
          FUN_004b0613((Tact2010CString *)&param_2,"S shape secondary land.");
          uStack_4 = 0x3d;
          (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
          uStack_4 = 0xffffffff;
          FUN_004b05a5((Tact2010CString *)&param_2);
        }
      }
      if ((DAT_004da254 == 1) && (DAT_004da258 == -1)) {
        FUN_004b0613((Tact2010CString *)&param_2,"Reverse S shape secondary land.");
        uStack_4 = 0x3e;
        (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5((Tact2010CString *)&param_2);
      }
    }
    param_1 = (int *)((DAT_004fe624 * 2) / 3 + 0x32);
    if ((DAT_004da264 == 0) && (DAT_00536500 == 0)) {
      FUN_004b0613((Tact2010CString *)&param_2,"Flat and Wilderness.");
      uStack_4 = 0x3f;
      (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if ((DAT_004da264 == 1) && (DAT_00536500 == 0)) {
      FUN_004b0613((Tact2010CString *)&param_2,"Hilly and Wilderness.");
      uStack_4 = 0x40;
      (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if ((DAT_004da264 == 0) && (DAT_00536500 == 1)) {
      FUN_004b0613((Tact2010CString *)&param_2,"Flat and Rural.");
      uStack_4 = 0x41;
      (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if ((DAT_004da264 == 1) && (DAT_00536500 == 1)) {
      FUN_004b0613((Tact2010CString *)&param_2,s_Hilly_and_Rural__004ecf94);
      uStack_4 = 0x42;
      (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if ((DAT_004da264 == 0) && (DAT_00536500 == 2)) {
      FUN_004b0613((Tact2010CString *)&param_2,"Flat and Urban.");
      uStack_4 = 0x43;
      (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if ((DAT_004da264 == 1) && (DAT_00536500 == 2)) {
      FUN_004b0613((Tact2010CString *)&param_2,"Hilly and Urban.");
      uStack_4 = 0x44;
      (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
  }
  iVar4 = iVar4 + 0xf;
  if (DAT_005363e4 == 0) {
    (*pcVar2)(original_dc,0xffff);
  }
  if (DAT_0053650c == 1) {
    FUN_004b0613((Tact2010CString *)&param_1,"No Seabreeze.");
    uStack_4 = 0x45;
    (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
LAB_0048e50a:
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_1);
  }
  else {
    if (DAT_004da268 == 0) {
      FUN_004b0613((Tact2010CString *)&param_1,"Seabreeze from the North.");
      uStack_4 = 0x46;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da268 == 0x2d) {
      FUN_004b0613((Tact2010CString *)&param_1,"Seabreeze from the Northeast.");
      uStack_4 = 0x47;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da268 == 0x5a) {
      FUN_004b0613((Tact2010CString *)&param_1,"Seabreeze from the East.");
      uStack_4 = 0x48;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da268 == 0x87) {
      FUN_004b0613((Tact2010CString *)&param_1,"Seabreeze from the Southeast.");
      uStack_4 = 0x49;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da268 == 0xb4) {
      FUN_004b0613((Tact2010CString *)&param_1,"Seabreeze from the South.");
      uStack_4 = 0x4a;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da268 == 0xe1) {
      FUN_004b0613((Tact2010CString *)&param_1,"Seabreeze from the Southwest.");
      uStack_4 = 0x4b;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da268 == 0x10e) {
      FUN_004b0613((Tact2010CString *)&param_1,"Seabreeze from the West.");
      uStack_4 = 0x4c;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_1);
    }
    if (DAT_004da268 == 0x13b) {
      FUN_004b0613((Tact2010CString *)&param_1,"Seabreeze from the Northwest.");
      uStack_4 = 0x4d;
      (*pcVar3)(original_dc,10,iVar4,(char *)param_1,param_1[-2]);
      goto LAB_0048e50a;
    }
  }
  param_1 = (int *)(((int)(DAT_004fe624 + (DAT_004fe624 >> 0x1f & 3U)) >> 2) + 0x55);
  if ((DAT_00536514 == 1) || (DAT_004da158 == 0)) {
    FUN_004b0613((Tact2010CString *)&param_2,"No current.");
    uStack_4 = 0x4e;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
  }
  else {
    if ((DAT_004da26c == 1) && (DAT_00536510 == 0)) {
      FUN_004b0613((Tact2010CString *)&param_2,"Tidal current floods from the right.");
      uStack_4 = 0x4f;
      (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if ((DAT_004da26c < 1) && (DAT_00536510 == 0)) {
      FUN_004b0613((Tact2010CString *)&param_2,"Tidal current floods from the left.");
      uStack_4 = 0x50;
      (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if ((DAT_004da26c == 1) && (DAT_00536510 == 1)) {
      FUN_004b0613((Tact2010CString *)&param_2,"River flows from the right.");
      uStack_4 = 0x51;
      (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_2);
    }
    if ((0 < DAT_004da26c) || (DAT_00536510 != 1)) goto LAB_0048e6a1;
    FUN_004b0613((Tact2010CString *)&param_2,"River flows from the left.");
    uStack_4 = 0x52;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
  }
  uStack_4 = 0xffffffff;
  FUN_004b05a5((Tact2010CString *)&param_2);
LAB_0048e6a1:
  if (DAT_00536524 == 1) {
    param_1 = (int *)((DAT_004fe624 * 2) / 3 + 0x32);
    if (DAT_005363e4 == 0) {
      (*pcVar2)(original_dc,0xffff00);
    }
    FUN_004b0613((Tact2010CString *)&param_2,"Tropical Water.");
    uStack_4 = 0x53;
    (*pcVar3)(original_dc,(int)param_1,iVar4,(char *)param_2,*(int *)(param_2 + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_2);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

