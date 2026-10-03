
undefined4 __fastcall FUN_004015f0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_30 [36];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_004c17d2;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  FUN_004bfa4a();
  FUN_004bf7ba(s_Local_AppWizard_Generated_Applic_004da10c);
  FUN_004bee8e(4);
  iVar1 = FUN_004afbe5(0x68);
  local_4 = 0;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004b2f23(0x80,&PTR_s_CTACTDoc_004c8788,&PTR_s_CMainFrame_004c8260,
                         &PTR_s_CTACTView_004c88d8);
  }
  local_4 = 0xffffffff;
  FUN_004b6e3d(uVar2);
  FUN_004bf76d();
  FUN_004bf797(1);
  FUN_004bef68();
  local_4 = 1;
  FUN_004bef0a(local_30);
  iVar1 = FUN_004bf41a(local_30);
  if (iVar1 == 0) {
    local_4 = 0xffffffff;
    FUN_004beff3();
    *unaff_FS_OFFSET = local_c;
    return 0;
  }
  FUN_004af52c(3);
  UpdateWindow(*(HWND *)(*(int *)(param_1 + 0x1c) + 0x1c));
  FUN_004af324(1);
  local_4 = 0xffffffff;
  FUN_004beff3();
  *unaff_FS_OFFSET = local_c;
  return 1;
}

