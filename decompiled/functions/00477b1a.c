
void __thiscall FUN_00477b1a(void *this,uint param_1,uint param_2)

{
  CWnd *pCVar1;
  int iVar2;
  
  pCVar1 = FUN_0046980f(this);
  if (param_2 == 0xffff) {
    *(uint *)((int)this + 0x24) = *(uint *)((int)this + 0x24) & 0xffffffbf;
    if (*(int *)(pCVar1 + 0x50) == 0) {
      *(undefined4 *)((int)this + 0x90) = 0xe001;
    }
    else {
      *(undefined4 *)((int)this + 0x90) = 0xe002;
    }
    SendMessageA(*(HWND *)((int)this + 0x1c),0x362,*(WPARAM *)((int)this + 0x90),0);
    iVar2 = (**(code **)(*(int *)this + 0xdc))();
    if (iVar2 != 0) {
      UpdateWindow(*(HWND *)(iVar2 + 0x1c));
    }
    goto LAB_00477bd2;
  }
  if ((param_1 == 0) || ((param_2 & 0x810) != 0)) {
    *(undefined4 *)((int)this + 0x90) = 0;
  }
  else {
    if ((param_1 < 0xf000) || (0xf1ef < param_1)) {
      if (0xfeff < param_1) {
        *(undefined4 *)((int)this + 0x90) = 0xef1f;
        goto LAB_00477bce;
      }
    }
    else {
      param_1 = (param_1 - 0xf000 >> 4) + 0xef00;
    }
    *(uint *)((int)this + 0x90) = param_1;
  }
LAB_00477bce:
  *(uint *)(pCVar1 + 0x24) = *(uint *)(pCVar1 + 0x24) | 0x40;
LAB_00477bd2:
  if (*(int *)((int)this + 0x90) != *(int *)((int)this + 0x94)) {
    GetParent(*(HWND *)((int)this + 0x1c));
    pCVar1 = FUN_004680cc();
    if (pCVar1 != (CWnd *)0x0) {
      PostMessageA(*(HWND *)((int)this + 0x1c),0x36a,0,0);
    }
  }
  return;
}

