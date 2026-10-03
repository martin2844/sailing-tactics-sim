
void __thiscall FUN_00476bde(void *this,int param_1)

{
  HWND hWnd;
  CWnd *pCVar1;
  HWND pHVar2;
  
  if ((param_1 == 0) || ((*(byte *)((int)this + 0x24) & 4) == 0)) {
    GetParent(*(HWND *)((int)this + 0x1c));
    pCVar1 = FUN_004680cc();
    if (pCVar1 == (CWnd *)0x0) {
      if ((param_1 == 0) && (*(int *)((int)this + 0xa0) == 0)) {
        *(byte *)((int)this + 0x24) = *(byte *)((int)this + 0x24) | 0x80;
        (**(code **)(*(int *)this + 0x90))();
      }
      else if ((param_1 != 0) && ((*(uint *)((int)this + 0x24) & 0x80) != 0)) {
        *(uint *)((int)this + 0x24) = *(uint *)((int)this + 0x24) & 0xffffff7f;
        (**(code **)(*(int *)this + 0x94))();
        hWnd = *(HWND *)((int)this + 0x1c);
        pHVar2 = GetActiveWindow();
        if (pHVar2 == hWnd) {
          SendMessageA(hWnd,6,1,0);
        }
      }
      if ((param_1 != 0) && ((*(byte *)((int)this + 0x24) & 0x20) != 0)) {
        SendMessageA(*(HWND *)((int)this + 0x1c),0x86,1,0);
      }
      FUN_00476c9c(this,(-(uint)(param_1 != 0) & 0xfffffff0) + 0x20);
    }
  }
  else {
    FUN_0046ae8e(this,0);
    SetFocus((HWND)0x0);
  }
  return;
}

