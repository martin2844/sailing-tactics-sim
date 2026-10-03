
void __fastcall FUN_004036a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_264 [16];
  undefined4 *local_254;
  uint local_23c;
  undefined1 local_20c [512];
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  pcStack_8 = FUN_004c1891;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  *param_1 = &PTR_FUN_004cd0b0;
  local_4 = 0;
  local_254 = param_1;
  FUN_004b0a8b();
  local_4._0_1_ = 1;
  FUN_004b5195(local_264,0,0x200,local_20c);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_004b0c0a(s_p_tac_004da298,0x1001,0);
  if ((DAT_004da16c == 1) && (DAT_00536420 < 0xc)) {
    DAT_00536420 = DAT_00536420 + 1;
  }
  if ((~local_23c & 1) != 0) {
    FUN_004061b0(DAT_004da19c);
    FUN_004061b0(DAT_004da144);
    FUN_004061b0(DAT_004da174);
    FUN_004061b0(DAT_004da194);
    FUN_004061b0(DAT_004da198);
    FUN_004061b0(DAT_00536484);
    FUN_004061b0(DAT_00536468);
    FUN_004061b0(DAT_004da14c);
    FUN_004061b0(DAT_004da154);
    FUN_004061b0(DAT_004da140);
    FUN_004061b0(DAT_00536400);
    FUN_004061b0(DAT_004da188);
    FUN_004061b0(DAT_004f8b78);
    FUN_004061b0(DAT_0053646c);
    FUN_004061b0(DAT_00536424);
    FUN_004061b0(DAT_0053640c);
    FUN_004061b0(DAT_004da158);
    FUN_004061b0(DAT_00536498);
    FUN_004061b0(DAT_0053643c);
    FUN_004061b0(DAT_00536454);
    FUN_004061b0(DAT_0053645c);
    FUN_004061b0(DAT_00523a5c);
    FUN_004061b0(DAT_00523a60);
    FUN_004061b0(DAT_00536480);
    FUN_004061b0(DAT_005363e4);
    FUN_004061b0(DAT_005363fc);
    FUN_004061b0(DAT_004da1a8);
    FUN_004061b0(DAT_00536420);
    FUN_004061b0(DAT_004da1ac);
    FUN_004061b0(DAT_004da1d8);
    FUN_004061b0(DAT_004da1a8);
    FUN_004061b0(DAT_005363e0);
    FUN_004061b0(DAT_00536484);
    FUN_004061b0(DAT_00525a7c);
    FUN_004061b0(DAT_00525a80);
    FUN_004061b0(DAT_004da1dc);
    FUN_004061b0(DAT_004da1e8);
    FUN_004061b0(DAT_005363dc);
    FUN_004061b0(DAT_004da1f8);
    FUN_004061b0(DAT_005363d0);
    FUN_004061b0(DAT_005363d4);
    FUN_004061b0(DAT_005363d8);
    iVar5 = FUN_004061b0(DAT_005363dc);
    uVar4 = DAT_004da234;
    uVar3 = DAT_004da230;
    if (*(uint *)(iVar5 + 0x28) < *(int *)(iVar5 + 0x24) + 8U) {
      FUN_004b5307();
    }
    puVar1 = *(undefined4 **)(iVar5 + 0x24);
    *puVar1 = uVar3;
    puVar1[1] = uVar4;
    *(int *)(iVar5 + 0x24) = *(int *)(iVar5 + 0x24) + 8;
    FUN_004061b0(DAT_004fbf34);
    FUN_004061b0(DAT_004fbf44);
    FUN_004061b0(DAT_004fbf54);
    FUN_004061b0(DAT_004fbf64);
    FUN_004061b0(DAT_004fbf74);
    FUN_004061b0(DAT_004fbf84);
    FUN_004061b0(DAT_004fbf94);
    FUN_004061b0(DAT_004fbfa4);
    FUN_004061b0(DAT_004fbfb4);
    FUN_004061b0(DAT_004fbfc4);
    FUN_004061b0(DAT_004fbfd4);
    FUN_004061b0(DAT_004fbfe4);
    FUN_004061b0(DAT_004fbff4);
    FUN_004061b0(DAT_004fc004);
    FUN_004061b0(DAT_004fc014);
    FUN_004061b0(DAT_004fc024);
    FUN_004061b0(DAT_004fc034);
    FUN_004061b0(DAT_004fc044);
    FUN_004061b0(DAT_004fc054);
    FUN_004061b0(DAT_004fc064);
    FUN_004061b0(DAT_004fc074);
    FUN_004061b0(DAT_004fc084);
    FUN_004061b0(DAT_004fc094);
    FUN_004061b0(DAT_004fc0a4);
    FUN_004061b0(DAT_004fc0b4);
    FUN_004061b0(DAT_004fc0c4);
    FUN_004061b0(DAT_004fc0d4);
    FUN_004061b0(DAT_004fc0e4);
    FUN_004061b0(DAT_004fc0f4);
    FUN_004061b0(DAT_004fc104);
    FUN_004061b0(DAT_004fbf38);
    FUN_004061b0(DAT_004fbf48);
    FUN_004061b0(DAT_004fbf58);
    FUN_004061b0(DAT_004fbf68);
    FUN_004061b0(DAT_004fbf78);
    FUN_004061b0(DAT_004fbf88);
    FUN_004061b0(DAT_004fbf98);
    FUN_004061b0(DAT_004fbfa8);
    FUN_004061b0(DAT_004fbfb8);
    FUN_004061b0(DAT_004fbfc8);
    FUN_004061b0(DAT_004fbfd8);
    FUN_004061b0(DAT_004fbfe8);
    FUN_004061b0(DAT_004fbff8);
    FUN_004061b0(DAT_004fc008);
    FUN_004061b0(DAT_004fc018);
    FUN_004061b0(DAT_004fc028);
    FUN_004061b0(DAT_004fc038);
    FUN_004061b0(DAT_004fc048);
    FUN_004061b0(DAT_004fc058);
    FUN_004061b0(DAT_004fc068);
    FUN_004061b0(DAT_004fc078);
    FUN_004061b0(DAT_004fc088);
    FUN_004061b0(DAT_004fc098);
    FUN_004061b0(DAT_004fc0a8);
    FUN_004061b0(DAT_004fc0b8);
    FUN_004061b0(DAT_004fc0c8);
    FUN_004061b0(DAT_004fc0d8);
    FUN_004061b0(DAT_004fc0e8);
    FUN_004061b0(DAT_004fc0f8);
    FUN_004061b0(DAT_004fc108);
    FUN_004061b0(DAT_004f49bc);
    FUN_004061b0(DAT_004f49c0);
    FUN_004061b0(DAT_004f49c4);
    FUN_004061b0(DAT_004f49c8);
    FUN_004061b0(DAT_004f49cc);
    iVar5 = FUN_004061b0(DAT_004f49d0);
    uVar3 = DAT_004f49d4;
    if (*(uint *)(iVar5 + 0x28) < *(int *)(iVar5 + 0x24) + 4U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f49d8;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f49dc;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f49e0;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f49e4;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f49e8;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f49ec;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f49f0;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f49f4;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f49f8;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f49fc;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f4a00;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f4a04;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f4a08;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f4a0c;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f4a10;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f4a14;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f4a18;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f4a1c;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f4a20;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f4a24;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f4a28;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f4a2c;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004f4a30;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004da238;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004da23c;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004da240;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004da244;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004da248;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004da24c;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004da250;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004da254;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004da258;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004da25c;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_00536504;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_00522f08;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_00536508;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004da264;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_00536500;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004da260;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004da268;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_0053650c;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_00536510;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_00536514;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_00536518;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_004da26c;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_00536524;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    iVar2 = *(int *)(iVar5 + 0x24);
    *(int *)(iVar5 + 0x24) = iVar2 + 4;
    uVar3 = DAT_0053641c;
    if (*(uint *)(iVar5 + 0x28) < iVar2 + 8U) {
      FUN_004b5307();
    }
    **(undefined4 **)(iVar5 + 0x24) = uVar3;
    *(int *)(iVar5 + 0x24) = *(int *)(iVar5 + 0x24) + 4;
  }
  local_4._0_1_ = 1;
  FUN_004b5271();
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_004b0b2b();
  local_4 = 0xffffffff;
  FUN_004b4158();
  *unaff_FS_OFFSET = local_c;
  return;
}

