
void __thiscall FUN_00468c1a(void *this,undefined4 param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  CWnd *this_00;
  
  if (*param_2 == 1) {
    iVar1 = FUN_0047be12(&DAT_004ae4b8,FUN_00455c3a);
    if (*(HWND *)(iVar1 + 0x50) != *(HWND *)((int)this + 0x1c)) {
      GetMenu(*(HWND *)((int)this + 0x1c));
    }
    iVar1 = FUN_0046d7e9();
    piVar2 = (int *)FUN_00468c93(iVar1,param_2[2]);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x18))(param_2);
    }
  }
  else {
    this_00 = FUN_004698f3(*(HWND *)((int)this + 0x1c),param_2[1],1);
    if ((this_00 != (CWnd *)0x0) && (iVar1 = FUN_00469ec1(this_00,0), iVar1 != 0)) {
      return;
    }
  }
  FUN_00468021(this);
  return;
}

