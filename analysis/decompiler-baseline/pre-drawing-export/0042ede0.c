
void __cdecl FUN_0042ede0(CDC *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  CDC *this;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *unaff_FS_OFFSET;
  int iStack_5c;
  int local_40;
  int iStack_3c;
  int iStack_38;
  int aiStack_34 [4];
  int iStack_24;
  int iStack_20;
  code *pcStack_10;
  int local_c;
  code *pcStack_8;
  int local_4;
  
  this = param_1;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0047e440;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_c;
  FUN_0046bd7a(&local_40);
  local_4 = 0;
  if (DAT_004ac904 != 1) {
    FUN_0047033f(param_1,1);
    iVar8 = param_3;
    iVar1 = param_3 + -0x1e;
    if (*(int *)(&DAT_004a4e88 + param_2 * 4) == 3) {
      iVar7 = 0x1f;
    }
    else {
      iVar7 = param_4 + -10;
    }
    if (DAT_004ac92c == 0) {
      iVar2 = *(int *)param_1;
      (**(code **)(iVar2 + 0x34))();
      iStack_5c = 0x42ee88;
      (**(code **)(iVar2 + 0x38))();
    }
    if (DAT_004ac98c == 1) {
      (**(code **)(*(int *)param_1 + 0x34))();
    }
    uVar4 = *(uint *)(&DAT_004ac018 + param_2 * 4);
    if ((int)uVar4 < 100) {
      param_1 = (CDC *)(iVar8 + -0x28);
    }
    else {
      param_1 = (CDC *)(iVar8 + -0x2d);
    }
    if (DAT_004ac9d0 == 1) {
      uVar4 = FUN_00413cb0(uVar4 + *(int *)(&DAT_004aa730 + param_2 * 4) * -0x2d);
      (**(code **)(*(int *)this + 0x38))();
    }
    iStack_5c = 0x42eefb;
    piVar5 = FUN_00413d00(&param_3,uVar4);
    local_4._0_1_ = 1;
    FUN_0046bfbe(&local_40,piVar5);
    local_4 = (uint)local_4._1_3_ << 8;
    FUN_0046bec5(&param_3);
    iStack_5c = iVar7 + -0x1a;
    (**(code **)(*(int *)this + 100))(param_1);
    iVar6 = FUN_00413cb0(*(int *)(&DAT_004ac018 + (int)pcStack_8 * 4));
    aiStack_34[2] = iVar1 - ((&DAT_004a54a0)[iVar6] * 0x1a) / 100;
    local_40 = iVar7 - ((&DAT_004a3450)[iVar6] * 0x1a) / 300;
    iVar2 = (&DAT_004a3450)[iVar6] * 0xd;
    iStack_20 = iVar2 / 100;
    aiStack_34[3] = iStack_20 + iVar1;
    iVar6 = (&DAT_004a54a0)[iVar6] * 0xd;
    local_c = iVar6 / 300;
    iStack_3c = iVar7 - local_c;
    iStack_24 = iVar6 / 100 + iVar1;
    iStack_38 = iVar2 / 300 + iVar7;
    iStack_20 = iVar1 - iStack_20;
    aiStack_34[0] = iVar7 + local_c;
    pcVar3 = *(code **)(*(int *)this + 0x2c);
    pcStack_8 = pcVar3;
    (*pcVar3)(4);
    (*pcVar3)(7);
    Ellipse(*(HDC *)(this + 4),iVar8 + -0x38,iVar7 + -8,iVar8 + -4,iVar7 + 8);
    if (DAT_004a4ee4 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004a4ee4);
    }
    iVar8 = 0;
    do {
      FUN_004706bd(this,(int *)&stack0xffffffac,iVar1,iVar7);
      CDC::LineTo(this,*(int *)((int)aiStack_34 + iVar8),*(int *)((int)aiStack_34 + iVar8 + -0x14));
      iVar8 = iVar8 + 4;
    } while (iVar8 < 0x10);
    (*pcStack_10)(7);
    FUN_0047033f(this,2);
    iStack_20 = 0xffffffff;
    FUN_0046bec5(&iStack_5c);
    *unaff_FS_OFFSET = aiStack_34[3];
    return;
  }
  local_4 = 0xffffffff;
  FUN_0046bec5(&local_40);
  *unaff_FS_OFFSET = local_c;
  return;
}

