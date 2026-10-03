
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00439600(CDC *param_1)

{
  code *pcVar1;
  undefined *puVar2;
  double dVar3;
  undefined4 uVar4;
  CDC *this;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  HDC hdc;
  HGDIOBJ h;
  int local_18;
  int local_14;
  LPCSTR local_10;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  dVar3 = _DAT_004aa7d8 * _DAT_00484f10;
  pcStack_8 = FUN_0047f078;
  *unaff_FS_OFFSET = &uStack_c;
  DAT_004a600c = (int)(longlong)dVar3;
  if (DAT_004a763c < 700) {
    iVar6 = 0x10;
    local_14 = 0x16;
    local_18 = 0x10;
    local_10 = &DAT_00000005;
  }
  else {
    local_14 = 0x1b;
    local_18 = 0x14;
    local_10 = (LPCSTR)0x14;
    iVar6 = 0x14;
  }
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)param_1 + 0x38))(param_1,0x7f);
  }
  FUN_0046bf33(&param_1,s_Same_tack__starting__A_windward_b_004984e8);
  uStack_4 = 0;
  pcVar1 = *(code **)(*(int *)this + 100);
  (*pcVar1)(this,5,2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f0000);
  }
  FUN_0046bf33(&param_1,s_L_and_L2_may_turn_toward_the_win_00498488);
  uStack_4 = 1;
  (*pcVar1)(this,5,local_14 + 2,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = local_14 + 2 + iVar6;
  FUN_0046bf33(&param_1,s_give_the_windward_boats_room_and_0049842c);
  uStack_4 = 2;
  (*pcVar1)(this,5,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar5 + iVar6;
  FUN_0046bf33(&param_1,s_keep_clear__00498420);
  uStack_4 = 3;
  (*pcVar1)(this,5,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar5 + local_14;
  if (DAT_004ac92c == 0) {
    (**(code **)(*(int *)this + 0x38))(this,0x7f00);
  }
  FUN_0046bf33(&param_1,s_Before_the_starting_signal_there_004983c4);
  uStack_4 = 4;
  (*pcVar1)(this,5,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  iVar5 = iVar5 + iVar6;
  FUN_0046bf33(&param_1,s_to_wind__After_the_starting_sign_00498368);
  uStack_4 = 5;
  (*pcVar1)(this,5,iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0046bf33(&param_1,s_established_the_overlap_from_ast_00498334);
  uStack_4 = 6;
  (*pcVar1)(this,5,iVar6 + iVar5,(LPCSTR)param_1,*(int *)(param_1 + -8));
  uStack_4 = 0xffffffff;
  FUN_0046bec5((int *)&param_1);
  FUN_0044d830((int)this,(int)local_10,iVar6);
  if (DAT_004ac92c == 0) {
    if (DAT_004a6dac == (HGDIOBJ)0x0) goto LAB_004398a2;
    hdc = *(HDC *)(this + 4);
    h = DAT_004a6dac;
  }
  else {
    if (DAT_004aa7f4 == (HGDIOBJ)0x0) goto LAB_004398a2;
    hdc = *(HDC *)(this + 4);
    h = DAT_004aa7f4;
  }
  SelectObject(hdc,h);
LAB_004398a2:
  Rectangle(*(HDC *)(this + 4),0,DAT_004a600c,DAT_004a763c,DAT_004a72d0);
  uVar4 = DAT_004a4e8c;
  DAT_004ac994 = 2;
  DAT_004a4e8c = 3;
  _DAT_004a6834 = 0;
  DAT_00491184 = 1;
  FUN_0044d6d0((int)this,iVar6);
  FUN_0042cd40((int *)this,(int)(longlong)(_DAT_004aa810 * _DAT_00484dd8),
               (int)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),3,1);
  FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484d70),
               (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),0,1,DAT_004a72d0,0);
  if (DAT_004a6774 == 0) {
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00484d90);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    param_1 = (CDC *)(DAT_004a763c / 0x14);
    DAT_004aa734 = 1;
    DAT_004a6ecc = 9;
    _DAT_004a77ec = 0x28;
    DAT_004a7064 = 0x14;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x10e;
    DAT_004a7bcc = 0x5a;
    FUN_00411000(this,iVar6,puVar2,1,1,DAT_004a72d0,0);
    FUN_0046bf33(&local_10,s_Boat_W_0049809c);
    uStack_4 = 7;
    (*pcVar1)(this,(int)(param_1 + iVar6),(int)puVar2 - local_18,local_10,*(int *)(local_10 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_10);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_004852e8);
    local_10 = (LPCSTR)(longlong)(_DAT_004aa7d8 * _DAT_00484de0);
    iVar5 = DAT_004a763c + (DAT_004a763c >> 0x1f & 0xfU);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 9;
    _DAT_004a77f0 = 0x28;
    DAT_004a7068 = 0x14;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x10e;
    DAT_004a7bd0 = 0x5a;
    FUN_00411000(this,iVar6,local_10,2,1,DAT_004a72d0,0);
    FUN_0046bf33(&param_1,s_Boat_L_0049832c);
    uStack_4 = 8;
    (*pcVar1)(this,iVar6 - (iVar5 >> 4),(int)(local_10 + local_18 + 4),(LPCSTR)param_1,
              *(int *)(param_1 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&param_1);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00484ec8);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8);
    param_1 = (CDC *)(DAT_004a763c / 7);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 5;
    _DAT_004a77f4 = 0x32;
    _DAT_004a706c = 0x14;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x10e;
    _DAT_004a7bd4 = 0x2d;
    FUN_00411000(this,iVar6,puVar2,3,1,DAT_004a72d0,0);
    FUN_0046bf33(&local_10,s_Boat_W2_00498324);
    uStack_4 = 9;
    (*pcVar1)(this,iVar6 - (int)param_1,(int)(puVar2 + (-4 - local_18)),local_10,
              *(int *)(local_10 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_10);
    iVar6 = (int)(longlong)(_DAT_004aa810 * _DAT_00484de8);
    puVar2 = (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484de0);
    _DAT_004aa748 = 1;
    param_1 = (CDC *)(DAT_004a763c / 0x19);
    _DAT_004a6ee0 = 0xf;
    _DAT_004a7800 = 2;
    _DAT_004a7078 = 0x3c;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x10e;
    _DAT_004a7be0 = 0x2d;
    FUN_00411000(this,iVar6,puVar2,6,1,DAT_004a72d0,0);
    FUN_0046bf33(&local_10,s_Boat_L2_0049831c);
    uStack_4 = 10;
    (*pcVar1)(this,(int)(param_1 + iVar6),(int)(puVar2 + DAT_004a72d0 / 0x46),local_10,
              *(int *)(local_10 + -8));
    uStack_4 = 0xffffffff;
    FUN_0046bec5((int *)&local_10);
  }
  else {
    DAT_004aa734 = 1;
    DAT_004a6ecc = 0xf;
    _DAT_004a77ec = 2;
    DAT_004a7064 = 0x32;
    DAT_004a633c = 0xf;
    DAT_004ac01c = 0x145;
    DAT_004a7bcc = 0x23;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_004852e8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8),1,1,DAT_004a72d0,0);
    DAT_004aa738 = 1;
    _DAT_004a6ed0 = 0xf;
    _DAT_004a77f0 = 2;
    DAT_004a7068 = 0x32;
    DAT_004a6340 = 0xf;
    DAT_004ac020 = 0x13b;
    DAT_004a7bd0 = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484db0),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484ec8),2,1,DAT_004a72d0,0);
    _DAT_004aa73c = 1;
    _DAT_004a6ed4 = 0xf;
    _DAT_004a77f4 = 2;
    _DAT_004a706c = 0x14;
    _DAT_004a6344 = 0xf;
    _DAT_004ac024 = 0x145;
    _DAT_004a7bd4 = 0x23;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00484ec8),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8),3,1,DAT_004a72d0,0);
    _DAT_004aa748 = 1;
    _DAT_004a6ee0 = 0xf;
    _DAT_004a7800 = 2;
    _DAT_004a7078 = 0x3c;
    _DAT_004a6350 = 0xf;
    _DAT_004ac030 = 0x13b;
    _DAT_004a7be0 = 0x2d;
    FUN_00411000(this,(int)(longlong)(_DAT_004aa810 * _DAT_00485348),
                 (undefined *)(longlong)(_DAT_004aa7d8 * _DAT_00484db8),6,1,DAT_004a72d0,0);
  }
  FUN_0042f0d0(this,0,1,0,DAT_004a600c,DAT_004a763c);
  DAT_004ac994 = 0;
  DAT_004abb74 = 0;
  DAT_004a4e8c = uVar4;
  *unaff_FS_OFFSET = uStack_c;
  return;
}

