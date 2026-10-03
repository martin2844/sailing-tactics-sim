
int __thiscall
FUN_00476049(void *this,undefined4 param_1,int param_2,int param_3,undefined4 param_4,
            undefined4 param_5,int param_6,int param_7)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined1 local_24 [12];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  local_c = 0;
  bVar3 = (*(uint *)((int)this + 100) & 0xa000) == 0;
  local_14 = 0;
  local_8 = 0;
  if (0 < *(int *)((int)this + 0x84)) {
    do {
      piVar1 = (int *)FUN_0047602d(this,local_8);
      if ((piVar1 == (int *)0x0) || (iVar2 = (**(code **)(*piVar1 + 0xd0))(), iVar2 == 0)) {
        iVar2 = local_c - DAT_004ae64c;
        local_c = 0;
        local_14 = local_14 + iVar2;
        iVar2 = param_7;
        if (bVar3) {
          iVar2 = param_6;
        }
        if (iVar2 < local_14) {
          if (local_8 == 0) {
            FUN_00466de3((void *)((int)this + 0x7c),local_10 + 1,0,1);
          }
          iVar2 = local_10 + 1;
          goto LAB_00476168;
        }
LAB_00476132:
        local_10 = local_8;
      }
      else {
        GetWindowRect((HWND)piVar1[7],(LPRECT)local_24);
        ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)local_24);
        ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)(local_24 + 8));
        if (bVar3) {
          iVar2 = (local_24._8_4_ - local_24._0_4_) + -1;
        }
        else {
          iVar2 = local_18 - local_24._4_4_;
        }
        if (local_c <= iVar2) {
          if (bVar3) {
            local_c = (local_24._8_4_ - local_24._0_4_) + -1;
          }
          else {
            local_c = local_18 - local_24._4_4_;
          }
        }
        if (bVar3) {
          bVar5 = SBORROW4(param_3,local_24._4_4_);
          iVar2 = param_3 - local_24._4_4_;
          bVar4 = param_3 == local_24._4_4_;
        }
        else {
          bVar5 = SBORROW4(param_2,local_24._0_4_);
          iVar2 = param_2 - local_24._0_4_;
          bVar4 = param_2 == local_24._0_4_;
        }
        if (!bVar4 && bVar5 == iVar2 < 0) goto LAB_00476132;
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)((int)this + 0x84));
  }
  iVar2 = local_10 + 1;
  FUN_00466de3((void *)((int)this + 0x7c),iVar2,0,1);
LAB_00476168:
  FUN_00466de3((void *)((int)this + 0x7c),iVar2,param_1,1);
  return iVar2;
}

