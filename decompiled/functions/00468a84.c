
uint __thiscall FUN_00468a84(void *this,LONG param_1,LONG param_2,uint *param_3)

{
  HWND hWnd;
  uint uVar1;
  uint uVar2;
  
  hWnd = FUN_00470e50(*(HWND *)((int)this + 0x1c),param_1,param_2);
  if (hWnd == (HWND)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = GetDlgCtrlID(hWnd);
    uVar1 = uVar1 & 0xffff;
    if ((param_3 != (uint *)0x0) && (0x2b < *param_3)) {
      uVar2 = *(uint *)((int)this + 0x1c);
      param_3[1] = param_3[1] | 1;
      param_3[9] = 0xffffffff;
      param_3[2] = uVar2;
      param_3[3] = (uint)hWnd;
      uVar2 = SendMessageA(hWnd,0x87,0,0);
      if ((uVar2 & 0x2000) == 0) {
        param_3[1] = param_3[1] | 0x80000002;
      }
    }
  }
  return uVar1;
}

