
undefined4 * __fastcall FUN_00402180(undefined4 *param_1)

{
  int iVar1;
  LPCSTR pCVar2;
  void *pvVar3;
  int iVar4;
  DWORD DVar5;
  HPEN pHVar6;
  HBRUSH pHVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_260 [16];
  undefined1 local_250 [20];
  byte local_23c;
  undefined4 local_c;
  code *pcStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047d181;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  FUN_0046fa46(param_1);
  local_4 = 0;
  *param_1 = &PTR_FUN_00485410;
  FUN_0046c3ab();
  local_4._0_1_ = 1;
  pCVar2 = FUN_0046c52a(local_260,s_p_tac_004911d8,0,0);
  if (pCVar2 == (LPCSTR)0x0) {
    DAT_00491144 = 0xc;
    DAT_00491188 = 6;
    DAT_004ac908 = 0;
    DAT_004ac900 = 0;
    DAT_00491194 = 1;
    DAT_0049116c = 8;
  }
  else {
    FUN_00470ab5();
    local_4._0_1_ = 2;
    if ((local_23c & 1) != 0) {
      pvVar3 = FUN_00406060(local_250,&DAT_00491194);
      pvVar3 = FUN_00406060(pvVar3,&DAT_00491144);
      pvVar3 = FUN_00406060(pvVar3,&DAT_0049116c);
      pvVar3 = FUN_00406060(pvVar3,&DAT_0049118c);
      pvVar3 = FUN_00406060(pvVar3,&DAT_00491190);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac9c0);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac9a4);
      pvVar3 = FUN_00406060(pvVar3,&DAT_0049114c);
      pvVar3 = FUN_00406060(pvVar3,&DAT_00491154);
      pvVar3 = FUN_00406060(pvVar3,&DAT_00491140);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac948);
      pvVar3 = FUN_00406060(pvVar3,&DAT_00491180);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a5a4c);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac9a8);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac960);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac954);
      pvVar3 = FUN_00406060(pvVar3,&DAT_00491158);
      pvVar3 = FUN_00406060(pvVar3,&DAT_0049114c);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac9d8);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac978);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac990);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac998);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004aae24);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004aae28);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac9bc);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac92c);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac944);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac9c8);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac95c);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004911a0);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004911cc);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac9c8);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac928);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ac9c0);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ab164);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004ab168);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004911d0);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6bc4);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6bd4);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6be4);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6bf4);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c04);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c14);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c24);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c34);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c44);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c54);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c64);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c74);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c84);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c94);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6ca4);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6cb4);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6cc4);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6cd4);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6ce4);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6cf4);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d04);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d14);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d24);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d34);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d44);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d54);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d64);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d74);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d84);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d94);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6bc8);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6bd8);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6be8);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6bf8);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c08);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c18);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c28);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c38);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c48);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c58);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c68);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c78);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c88);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6c98);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6ca8);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6cb8);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6cc8);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6cd8);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6ce8);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6cf8);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d08);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d18);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d28);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d38);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d48);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d58);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d68);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d78);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d88);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a6d98);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a461c);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4620);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4624);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4628);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a462c);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4630);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4634);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4638);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a463c);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4640);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4644);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4648);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a464c);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4650);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4654);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4658);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a465c);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4660);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4664);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4668);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a466c);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4670);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4674);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4678);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a467c);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4680);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4684);
      pvVar3 = FUN_00406060(pvVar3,&DAT_004a4688);
      if (*(uint *)((int)pvVar3 + 0x28) < *(int *)((int)pvVar3 + 0x24) + 4U) {
        FUN_00470ca1(pvVar3,(*(int *)((int)pvVar3 + 0x24) - *(uint *)((int)pvVar3 + 0x28)) + 4);
      }
      DAT_004a468c = **(undefined4 **)((int)pvVar3 + 0x24);
      iVar1 = *(int *)((int)pvVar3 + 0x24);
      iVar4 = iVar1 + 4;
      *(int *)((int)pvVar3 + 0x24) = iVar4;
      if (*(uint *)((int)pvVar3 + 0x28) < iVar1 + 8U) {
        FUN_00470ca1(pvVar3,(iVar4 - *(uint *)((int)pvVar3 + 0x28)) + 4);
      }
      DAT_004a4690 = **(undefined4 **)((int)pvVar3 + 0x24);
      *(int *)((int)pvVar3 + 0x24) = *(int *)((int)pvVar3 + 0x24) + 4;
    }
    local_4._0_1_ = 1;
    FUN_00470b91();
  }
  if ((1 < DAT_004911d0) || (DAT_004911d0 < 0)) {
    DAT_004911d0 = 0;
  }
  if ((DAT_004ab164 < 0) || (2 < DAT_004ab164)) {
    DAT_004ab164 = 1;
  }
  if ((DAT_004ab168 < 0) || (2 < DAT_004ab168)) {
    DAT_004ab168 = 1;
  }
  if ((DAT_004911cc < 1) || (10 < DAT_004911cc)) {
    DAT_004911cc = 5;
  }
  if ((DAT_0049118c == 2) && (5 < DAT_004911cc)) {
    DAT_004911cc = 5;
  }
  if (2 < DAT_004ac944) {
    DAT_004ac944 = 0;
  }
  if (DAT_00491180 == 1) {
    DAT_00491160 = 1;
    DAT_004ac940 = 0;
    DAT_004ac950 = 0;
  }
  if (DAT_00491180 == 2) {
    DAT_00491160 = 1;
    DAT_004ac940 = 0;
    DAT_004ac950 = 1;
  }
  if (DAT_00491180 == 3) {
    DAT_00491160 = 0;
    DAT_004ac940 = 0;
    DAT_004ac950 = 0;
  }
  if (DAT_00491180 == 4) {
    DAT_00491160 = 0;
    DAT_004ac940 = 0;
    DAT_004ac950 = 1;
  }
  if (DAT_00491180 == 5) {
    DAT_00491160 = 0;
    DAT_004ac940 = 1;
    DAT_004ac950 = 1;
  }
  if (DAT_00491194 == 8) {
    DAT_004ac940 = 0;
    DAT_004ac950 = 0;
    DAT_004ac954 = 0;
    DAT_00491180 = 1;
  }
  if (DAT_00491194 == 7) {
    DAT_00491160 = 0;
    DAT_004ac940 = 0;
    DAT_004ac950 = 0;
    DAT_004ac954 = 0;
    if ((DAT_00491180 < 3) || (4 < DAT_00491180)) {
      DAT_00491180 = 3;
    }
  }
  if ((DAT_00491188 < 7) || (8 < DAT_00491188)) {
    DAT_0049114c = 0xffffffff;
  }
  FUN_0044e380();
  DAT_00491178 = DAT_0049116c;
  DAT_00491174 = DAT_00491170;
  DAT_004a763c = GetSystemMetrics(1);
  FUN_00415a60();
  DVar5 = FUN_00456f10((int *)0x0);
  FUN_00456ed0(DVar5);
  FUN_0042e080();
  iVar1 = DAT_004a763c / 0x96;
  iVar4 = DAT_004a763c / 200;
  pHVar6 = CreatePen(0,iVar4,0x7f7900);
  FUN_00470a2d(&DAT_004aa640,(uint)pHVar6);
  pHVar6 = CreatePen(0,iVar4,0x7f6e00);
  FUN_00470a2d(&DAT_004aa950,(uint)pHVar6);
  pHVar6 = CreatePen(0,iVar1,0x7f7900);
  FUN_00470a2d(&DAT_004a6228,(uint)pHVar6);
  pHVar6 = CreatePen(0,iVar1,0x7f6e00);
  FUN_00470a2d(&DAT_004a4428,(uint)pHVar6);
  iVar1 = DAT_004a763c / 0x50;
  iVar4 = DAT_004a763c / 0x82;
  pHVar6 = CreatePen(0,2,0xffff00);
  FUN_00470a2d(&DAT_004ac308,(uint)pHVar6);
  pHVar6 = CreatePen(0,iVar1,0xff00);
  FUN_00470a2d(&DAT_004abf00,(uint)pHVar6);
  pHVar6 = CreatePen(0,iVar4,0xff00);
  FUN_00470a2d(&DAT_004a89b8,(uint)pHVar6);
  pHVar6 = CreatePen(0,iVar1,0xff);
  FUN_00470a2d(&DAT_004a6790,(uint)pHVar6);
  pHVar6 = CreatePen(0,iVar4,0xff);
  FUN_00470a2d(&DAT_004ab158,(uint)pHVar6);
  pHVar6 = CreatePen(0,iVar1,0x7f7f7f);
  FUN_00470a2d(&DAT_004a8a40,(uint)pHVar6);
  pHVar6 = CreatePen(0,iVar4,0x7f7f7f);
  FUN_00470a2d(&DAT_004abdb8,(uint)pHVar6);
  pHVar6 = CreatePen(0,iVar1,0);
  FUN_00470a2d(&DAT_004a3a00,(uint)pHVar6);
  pHVar6 = CreatePen(0,iVar4,0);
  FUN_00470a2d(&DAT_004a4038,(uint)pHVar6);
  pHVar6 = CreatePen(0,iVar1,0xff0000);
  FUN_00470a2d(&DAT_004ab9e0,(uint)pHVar6);
  pHVar6 = CreatePen(0,iVar4,0xff0000);
  FUN_00470a2d(&DAT_004abbf8,(uint)pHVar6);
  pHVar6 = CreatePen(0,iVar4,0xffffff);
  FUN_00470a2d(&DAT_004a46a0,(uint)pHVar6);
  pHVar6 = CreatePen(0,2,0);
  FUN_00470a2d(&DAT_004a4de8,(uint)pHVar6);
  pHVar6 = CreatePen(0,2,0x7f7f7f);
  FUN_00470a2d(&DAT_004aa630,(uint)pHVar6);
  pHVar6 = CreatePen(0,1,0x7f7f7f);
  FUN_00470a2d(&DAT_004a71b8,(uint)pHVar6);
  pHVar6 = CreatePen(0,2,0xff);
  FUN_00470a2d(&DAT_004a6768,(uint)pHVar6);
  pHVar6 = CreatePen(0,2,0x7f);
  FUN_00470a2d(&DAT_004a7050,(uint)pHVar6);
  pHVar6 = CreatePen(0,1,0x7f);
  FUN_00470a2d(&DAT_004a7058,(uint)pHVar6);
  pHVar6 = CreatePen(0,2,0x7fffff);
  FUN_00470a2d(&DAT_004a3f98,(uint)pHVar6);
  pHVar6 = CreatePen(0,2,0x7f);
  FUN_00470a2d(&DAT_004aa7e8,(uint)pHVar6);
  pHVar6 = CreatePen(0,2,0xff00);
  FUN_00470a2d(&DAT_004a39f8,(uint)pHVar6);
  pHVar6 = CreatePen(0,3,0xff0000);
  FUN_00470a2d(&DAT_004a4370,(uint)pHVar6);
  pHVar6 = CreatePen(0,2,0x7f0000);
  FUN_00470a2d(&DAT_004ab9c8,(uint)pHVar6);
  pHVar6 = CreatePen(0,1,0x7f0000);
  FUN_00470a2d(&DAT_004aa700,(uint)pHVar6);
  pHVar6 = CreatePen(0,2,0x7f00);
  FUN_00470a2d(&DAT_004a3a28,(uint)pHVar6);
  pHVar6 = CreatePen(0,1,0x7f00);
  FUN_00470a2d(&DAT_004ac848,(uint)pHVar6);
  pHVar6 = CreatePen(0,2,0xff00ff);
  FUN_00470a2d(&DAT_004abbf0,(uint)pHVar6);
  pHVar6 = CreatePen(0,2,0x7f007f);
  FUN_00470a2d(&DAT_004aa7d0,(uint)pHVar6);
  pHVar6 = CreatePen(0,2,0xffffff);
  FUN_00470a2d(&DAT_004a4ee0,(uint)pHVar6);
  pHVar6 = CreatePen(0,1,0xff00);
  FUN_00470a2d(&DAT_004a3c08,(uint)pHVar6);
  pHVar6 = CreatePen(0,1,0xff);
  FUN_00470a2d(&DAT_004ac850,(uint)pHVar6);
  pHVar6 = CreatePen(0,2,0xffff);
  FUN_00470a2d(&DAT_004a67a8,(uint)pHVar6);
  pHVar6 = CreatePen(0,1,0xff00ff);
  FUN_00470a2d(&DAT_004aa970,(uint)pHVar6);
  pHVar6 = CreatePen(0,1,0x7f007f);
  FUN_00470a2d(&DAT_004a4948,(uint)pHVar6);
  pHVar7 = CreateSolidBrush(0xffff7f);
  FUN_00470a2d(&DAT_004a4698,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0xffff7f);
  FUN_00470a2d(&DAT_004a5af8,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0xff7f00);
  FUN_00470a2d(&DAT_004a8e00,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x7f7f00);
  FUN_00470a2d(&DAT_004a6da8,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0xfa7f00);
  FUN_00470a2d(&DAT_004a8650,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x7f7900);
  FUN_00470a2d(&DAT_004ac1c8,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x7f7e00);
  FUN_00470a2d(&DAT_004aa828,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0xe60000);
  FUN_00470a2d(&DAT_004a5b88,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0xff);
  FUN_00470a2d(&DAT_004a3a10,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x7f7f);
  FUN_00470a2d(&DAT_004ab190,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x7f);
  FUN_00470a2d(&DAT_004a6480,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x7f00);
  FUN_00470a2d(&DAT_004a6218,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x3f00);
  FUN_00470a2d(&DAT_004ac8e8,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0xff00);
  FUN_00470a2d(&DAT_004aa988,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0xff0000);
  FUN_00470a2d(&DAT_004aa710,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x7f0000);
  FUN_00470a2d(&DAT_004a71b0,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0xffff);
  FUN_00470a2d(&DAT_004a6230,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x7f7f);
  FUN_00470a2d(&DAT_004ab178,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0xff00ff);
  FUN_00470a2d(&DAT_004a7f20,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x7f007f);
  FUN_00470a2d(&DAT_004a4878,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x7fffff);
  FUN_00470a2d(&DAT_004a4f78,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x7f7f7f);
  FUN_00470a2d(&DAT_004a70e0,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x3f3f3f);
  FUN_00470a2d(&DAT_004aa7f0,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x303030);
  FUN_00470a2d(&DAT_004a7bc0,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0x202020);
  FUN_00470a2d(&DAT_004ac8f0,(uint)pHVar7);
  pHVar7 = CreateSolidBrush(0xbfbfbf);
  FUN_00470a2d(&DAT_004a3ef8,(uint)pHVar7);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0046c44b();
  *unaff_FS_OFFSET = local_c;
  return param_1;
}

