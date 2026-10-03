
undefined4 __fastcall FUN_004015f0(void *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  int local_30 [9];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047d0f2;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  FUN_0047b36a();
  FUN_0047b0da(param_1,s_Local_AppWizard_Generated_Applic_004910fc);
  FUN_0047a7ae();
  puVar1 = (undefined4 *)FUN_0046b505(0x68);
  local_4 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_0046e843(puVar1);
  }
  local_4 = 0xffffffff;
  FUN_0047275d();
  FUN_0047b08d((int)param_1);
  FUN_0047b0b7(param_1,1);
  FUN_0047a888();
  local_4 = 1;
  FUN_0047a82a(local_30);
  iVar2 = FUN_0047ad3a();
  if (iVar2 != 0) {
    FUN_0046ae4c(*(void **)((int)param_1 + 0x1c),3);
    UpdateWindow(*(HWND *)(*(int *)((int)param_1 + 0x1c) + 0x1c));
    FUN_0046ac44(*(void **)((int)param_1 + 0x1c),1);
    local_4 = 0xffffffff;
    FUN_0047a913();
    *unaff_FS_OFFSET = local_c;
    return 1;
  }
  local_4 = 0xffffffff;
  FUN_0047a913();
  *unaff_FS_OFFSET = local_c;
  return 0;
}

