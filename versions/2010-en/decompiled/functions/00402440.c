
undefined4 * __fastcall FUN_00402440(undefined4 *param_1)

{
  int cWidth;
  int cWidth_00;
  int iVar1;
  undefined4 uVar2;
  HPEN pHVar3;
  HBRUSH pHVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_260 [36];
  byte local_23c;
  undefined1 local_20c [512];
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c1861;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  FUN_004b4126();
  local_4 = 0;
  *param_1 = &PTR_FUN_004cd0b0;
  FUN_004b0a8b();
  local_4._0_1_ = 1;
  iVar1 = FUN_004b0c0a(s_p_tac_004da298,0,0);
  if (iVar1 == 0) {
    DAT_004da144 = 0xc;
    DAT_004da190 = 6;
    DAT_005363c0 = 0;
    DAT_005363b8 = 0;
    DAT_004da1f8 = 3;
    DAT_004da19c = 0;
    DAT_004da174 = 7;
  }
  else {
    FUN_004b5195(local_260,1,0x200,local_20c);
    local_4._0_1_ = 2;
    if ((local_23c & 1) != 0) {
      FUN_004061e0(&DAT_004da19c);
      FUN_004061e0(&DAT_004da144);
      FUN_004061e0(&DAT_004da174);
      FUN_004061e0(&DAT_004da194);
      FUN_004061e0(&DAT_004da198);
      FUN_004061e0(&DAT_00536484);
      FUN_004061e0(&DAT_00536468);
      FUN_004061e0(&DAT_004da14c);
      FUN_004061e0(&DAT_004da154);
      FUN_004061e0(&DAT_004da140);
      FUN_004061e0(&DAT_00536400);
      FUN_004061e0(&DAT_004da188);
      FUN_004061e0(&DAT_004f8b78);
      FUN_004061e0(&DAT_0053646c);
      FUN_004061e0(&DAT_00536424);
      FUN_004061e0(&DAT_0053640c);
      FUN_004061e0(&DAT_004da158);
      FUN_004061e0(&DAT_00536498);
      FUN_004061e0(&DAT_0053643c);
      FUN_004061e0(&DAT_00536454);
      FUN_004061e0(&DAT_0053645c);
      FUN_004061e0(&DAT_00523a5c);
      FUN_004061e0(&DAT_00523a60);
      FUN_004061e0(&DAT_00536480);
      FUN_004061e0(&DAT_005363e4);
      FUN_004061e0(&DAT_005363fc);
      FUN_004061e0(&DAT_004da1a8);
      FUN_004061e0(&DAT_00536420);
      FUN_004061e0(&DAT_004da1ac);
      FUN_004061e0(&DAT_004da1d8);
      FUN_004061e0(&DAT_004da1a8);
      FUN_004061e0(&DAT_005363e0);
      FUN_004061e0(&DAT_00536484);
      FUN_004061e0(&DAT_00525a7c);
      FUN_004061e0(&DAT_00525a80);
      FUN_004061e0(&DAT_004da1dc);
      FUN_004061e0(&DAT_004da1e8);
      FUN_004061e0(&DAT_005363dc);
      FUN_004061e0(&DAT_004da1f8);
      FUN_004061e0(&DAT_005363d0);
      FUN_004061e0(&DAT_005363d4);
      FUN_004061e0(&DAT_005363d8);
      iVar1 = FUN_004061e0(&DAT_005363dc);
      if (*(uint *)(iVar1 + 0x28) < *(int *)(iVar1 + 0x24) + 8U) {
        FUN_004b5381((*(int *)(iVar1 + 0x24) - *(uint *)(iVar1 + 0x28)) + 8);
      }
      DAT_004da230 = **(undefined4 **)(iVar1 + 0x24);
      DAT_004da234 = (*(undefined4 **)(iVar1 + 0x24))[1];
      *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + 8;
      FUN_004061e0(&DAT_004fbf34);
      FUN_004061e0(&DAT_004fbf44);
      FUN_004061e0(&DAT_004fbf54);
      FUN_004061e0(&DAT_004fbf64);
      FUN_004061e0(&DAT_004fbf74);
      FUN_004061e0(&DAT_004fbf84);
      FUN_004061e0(&DAT_004fbf94);
      FUN_004061e0(&DAT_004fbfa4);
      FUN_004061e0(&DAT_004fbfb4);
      FUN_004061e0(&DAT_004fbfc4);
      FUN_004061e0(&DAT_004fbfd4);
      FUN_004061e0(&DAT_004fbfe4);
      FUN_004061e0(&DAT_004fbff4);
      FUN_004061e0(&DAT_004fc004);
      FUN_004061e0(&DAT_004fc014);
      FUN_004061e0(&DAT_004fc024);
      FUN_004061e0(&DAT_004fc034);
      FUN_004061e0(&DAT_004fc044);
      FUN_004061e0(&DAT_004fc054);
      FUN_004061e0(&DAT_004fc064);
      FUN_004061e0(&DAT_004fc074);
      FUN_004061e0(&DAT_004fc084);
      FUN_004061e0(&DAT_004fc094);
      FUN_004061e0(&DAT_004fc0a4);
      FUN_004061e0(&DAT_004fc0b4);
      FUN_004061e0(&DAT_004fc0c4);
      FUN_004061e0(&DAT_004fc0d4);
      FUN_004061e0(&DAT_004fc0e4);
      FUN_004061e0(&DAT_004fc0f4);
      FUN_004061e0(&DAT_004fc104);
      FUN_004061e0(&DAT_004fbf38);
      FUN_004061e0(&DAT_004fbf48);
      FUN_004061e0(&DAT_004fbf58);
      FUN_004061e0(&DAT_004fbf68);
      FUN_004061e0(&DAT_004fbf78);
      FUN_004061e0(&DAT_004fbf88);
      FUN_004061e0(&DAT_004fbf98);
      FUN_004061e0(&DAT_004fbfa8);
      FUN_004061e0(&DAT_004fbfb8);
      FUN_004061e0(&DAT_004fbfc8);
      FUN_004061e0(&DAT_004fbfd8);
      FUN_004061e0(&DAT_004fbfe8);
      FUN_004061e0(&DAT_004fbff8);
      FUN_004061e0(&DAT_004fc008);
      FUN_004061e0(&DAT_004fc018);
      FUN_004061e0(&DAT_004fc028);
      FUN_004061e0(&DAT_004fc038);
      FUN_004061e0(&DAT_004fc048);
      FUN_004061e0(&DAT_004fc058);
      FUN_004061e0(&DAT_004fc068);
      FUN_004061e0(&DAT_004fc078);
      FUN_004061e0(&DAT_004fc088);
      FUN_004061e0(&DAT_004fc098);
      FUN_004061e0(&DAT_004fc0a8);
      FUN_004061e0(&DAT_004fc0b8);
      FUN_004061e0(&DAT_004fc0c8);
      FUN_004061e0(&DAT_004fc0d8);
      FUN_004061e0(&DAT_004fc0e8);
      FUN_004061e0(&DAT_004fc0f8);
      FUN_004061e0(&DAT_004fc108);
      FUN_004061e0(&DAT_004f49bc);
      FUN_004061e0(&DAT_004f49c0);
      FUN_004061e0(&DAT_004f49c4);
      FUN_004061e0(&DAT_004f49c8);
      FUN_004061e0(&DAT_004f49cc);
      FUN_004061e0(&DAT_004f49d0);
      FUN_004061e0(&DAT_004f49d4);
      FUN_004061e0(&DAT_004f49d8);
      FUN_004061e0(&DAT_004f49dc);
      FUN_004061e0(&DAT_004f49e0);
      FUN_004061e0(&DAT_004f49e4);
      FUN_004061e0(&DAT_004f49e8);
      FUN_004061e0(&DAT_004f49ec);
      FUN_004061e0(&DAT_004f49f0);
      FUN_004061e0(&DAT_004f49f4);
      FUN_004061e0(&DAT_004f49f8);
      FUN_004061e0(&DAT_004f49fc);
      FUN_004061e0(&DAT_004f4a00);
      FUN_004061e0(&DAT_004f4a04);
      FUN_004061e0(&DAT_004f4a08);
      FUN_004061e0(&DAT_004f4a0c);
      FUN_004061e0(&DAT_004f4a10);
      FUN_004061e0(&DAT_004f4a14);
      FUN_004061e0(&DAT_004f4a18);
      FUN_004061e0(&DAT_004f4a1c);
      FUN_004061e0(&DAT_004f4a20);
      FUN_004061e0(&DAT_004f4a24);
      FUN_004061e0(&DAT_004f4a28);
      FUN_004061e0(&DAT_004f4a2c);
      FUN_004061e0(&DAT_004f4a30);
      FUN_004061e0(&DAT_004da238);
      FUN_004061e0(&DAT_004da23c);
      FUN_004061e0(&DAT_004da240);
      FUN_004061e0(&DAT_004da244);
      FUN_004061e0(&DAT_004da248);
      FUN_004061e0(&DAT_004da24c);
      FUN_004061e0(&DAT_004da250);
      FUN_004061e0(&DAT_004da254);
      FUN_004061e0(&DAT_004da258);
      FUN_004061e0(&DAT_004da25c);
      FUN_004061e0(&DAT_00536504);
      FUN_004061e0(&DAT_00522f08);
      FUN_004061e0(&DAT_00536508);
      FUN_004061e0(&DAT_004da264);
      FUN_004061e0(&DAT_00536500);
      FUN_004061e0(&DAT_004da260);
      FUN_004061e0(&DAT_004da268);
      FUN_004061e0(&DAT_0053650c);
      FUN_004061e0(&DAT_00536510);
      FUN_004061e0(&DAT_00536514);
      FUN_004061e0(&DAT_00536518);
      FUN_004061e0(&DAT_004da26c);
      FUN_004061e0(&DAT_00536524);
      FUN_004061e0(&DAT_0053641c);
    }
    local_4._0_1_ = 1;
    FUN_004b5271();
  }
  if (DAT_004da16c == 1) {
    DAT_004da154 = 3;
  }
  DAT_00536450 = (uint)(DAT_00536454 == 1);
  if ((((DAT_004da188 == 3) || (DAT_004da188 == 4)) || (DAT_004da188 == 6)) || (DAT_004da19c == 8))
  {
    DAT_004da1e8 = 0;
  }
  if (DAT_004da194 < 0xf) {
    DAT_004da1e8 = 0;
  }
  if ((1 < DAT_004da1dc) || (DAT_004da1dc < 0)) {
    DAT_004da1dc = 0;
  }
  if ((DAT_00525a7c < 0) || (2 < DAT_00525a7c)) {
    DAT_00525a7c = 1;
  }
  if ((DAT_00525a80 < 0) || (2 < DAT_00525a80)) {
    DAT_00525a80 = 1;
  }
  if ((DAT_004da1d8 < 1) || (10 < DAT_004da1d8)) {
    DAT_004da1d8 = 5;
  }
  if ((DAT_004da194 == 2) && (5 < DAT_004da1d8)) {
    DAT_004da1d8 = 5;
  }
  if (2 < DAT_005363fc) {
    DAT_005363fc = 0;
  }
  if (DAT_004da188 == 1) {
    DAT_004da168 = 1;
    DAT_005363f8 = 0;
  }
  if (DAT_004da188 == 2) {
    DAT_004da168 = 1;
    DAT_005363f8 = 0;
  }
  DAT_00536408 = (uint)(DAT_004da188 == 2);
  if (DAT_004da188 == 3) {
    DAT_004da168 = 0;
    DAT_005363f8 = 0;
  }
  if (DAT_004da188 == 4) {
    DAT_004da168 = 0;
    DAT_005363f8 = 0;
    DAT_00536408 = 1;
  }
  if (DAT_004da188 == 6) {
    DAT_004da168 = 1;
    DAT_005363f8 = 0;
  }
  DAT_0053527c = (uint)(DAT_004da188 == 6);
  if (DAT_004da188 == 7) {
    DAT_004da168 = 1;
    DAT_005363f8 = 0;
    DAT_0053527c = 1;
    DAT_00536408 = 1;
  }
  if (DAT_004da188 == 5) {
    DAT_004da168 = 0;
    DAT_005363f8 = 1;
    DAT_00536408 = 1;
  }
  if (DAT_004da19c == 8) {
    DAT_005363f8 = 0;
    DAT_00536408 = 0;
    DAT_0053640c = 0;
    DAT_004da188 = 1;
    DAT_004da1e8 = 0;
    DAT_0053527c = 0;
  }
  if (DAT_004da19c == 7) {
    DAT_004da168 = 0;
    DAT_005363f8 = 0;
    DAT_00536408 = 0;
    DAT_0053640c = 0;
    DAT_004da1e8 = 0;
    DAT_0053527c = 0;
    if ((DAT_004da188 < 3) || (4 < DAT_004da188)) {
      DAT_004da188 = 3;
    }
  }
  FUN_00464940();
  DAT_004da180 = DAT_004da174;
  DAT_004da17c = DAT_004da178;
  DAT_004fe624 = GetSystemMetrics(1);
  FUN_0041e040();
  uVar2 = FUN_0049b7e0(0);
  FUN_0049b7a0(uVar2);
  FUN_004413e0();
  iVar1 = DAT_004fe624 / 0x96;
  cWidth = DAT_004fe624 / 200;
  pHVar3 = CreatePen(0,cWidth,0x7f7900);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,cWidth,0x7f6e00);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,iVar1,0x7f7900);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,iVar1,0x7f6e00);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,iVar1,0xa07800);
  FUN_004b510d(pHVar3);
  iVar1 = DAT_004fe624 / 0x50;
  cWidth_00 = DAT_004fe624 / 0x82;
  pHVar3 = CreatePen(0,2,0xffff00);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,iVar1,0xff00);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,cWidth_00,0xff00);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,iVar1,0xff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,cWidth_00,0xff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,iVar1,0x7f7f7f);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,cWidth_00,0x7f7f7f);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,3,0x7f7f7f);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,iVar1,0);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,cWidth_00,0);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,iVar1,0xff0000);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,cWidth_00,0xff0000);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,cWidth_00,0xffffff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,3,0xffffff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,3,0);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0x7f7f7f);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0x3f3f3f);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,1,0x7f7f7f);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0xff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0x7fff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0x7f);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,1,0x7f);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0x7fffff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0x7f);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0xff00);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,3,0xff0000);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0x7f0000);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,1,0x7f0000);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0x7f00);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0x6e00);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,1,0x7f00);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0xff00ff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0x7f007f);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0xffffff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,3,0xffffff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,1,0xff00);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,1,0xff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0xffff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,1,0xff00ff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,1,0x7f007f);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0xff00ff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,4,0xff0000);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,4,0xffff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,4,0xff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,4,0x696900);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,2,0x696900);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,cWidth_00,0xffffff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,cWidth,0xffffff);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,4,0xa07800);
  FUN_004b510d(pHVar3);
  pHVar3 = CreatePen(0,4,0x646400);
  FUN_004b510d(pHVar3);
  pHVar4 = CreateSolidBrush(0xffc87f);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0xffff7f);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0xb48c00);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0xd2aa00);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0xa07800);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0xff7f00);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x969600);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x7f7f00);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x696900);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0xfa7f00);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x7f7900);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x7f7e00);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0xe60000);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0xff);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x7f7f);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x7f);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0xbe);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x7800);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x6400);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x2000);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0xff00);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0xff0000);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x7f0000);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x7fff);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0xffff);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x7f7f);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0xff00ff);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x7f007f);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x7fffff);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x7f7f7f);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x3f3f3f);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x303030);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0x202020);
  FUN_004b510d(pHVar4);
  pHVar4 = CreateSolidBrush(0xbfbfbf);
  FUN_004b510d(pHVar4);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_004b0b2b();
  *unaff_FS_OFFSET = local_c;
  return param_1;
}

