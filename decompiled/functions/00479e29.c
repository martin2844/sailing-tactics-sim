
void __thiscall FUN_00479e29(void *this,void *param_1,void *param_2,RECT *param_3)

{
  void *this_00;
  uint uVar1;
  uint *puVar2;
  int iVar3;
  void *local_8;
  
  if (param_2 == (void *)0x0) {
    local_8 = (void *)0x0;
    puVar2 = &DAT_00488a88;
    do {
      this_00 = (void *)FUN_00477e26(this,*puVar2);
      if (this_00 != (void *)0x0) {
        iVar3 = -1;
        uVar1 = GetDlgCtrlID(*(HWND *)((int)param_1 + 0x1c));
        iVar3 = FUN_00475fbe(this_00,uVar1 & 0xffff,iVar3);
        if (0 < iVar3) break;
      }
      if (((*(uint *)((int)param_1 + 100) ^ puVar2[1]) & 0xf000) == 0) {
        local_8 = (void *)FUN_00477e26(this,*puVar2);
      }
      puVar2 = puVar2 + 2;
      this_00 = param_2;
    } while ((int)puVar2 < 0x488aa8);
    param_2 = this_00;
    if (param_2 == (void *)0x0) {
      param_2 = local_8;
    }
  }
  FUN_0047568b(param_2,param_1,param_3);
  return;
}

