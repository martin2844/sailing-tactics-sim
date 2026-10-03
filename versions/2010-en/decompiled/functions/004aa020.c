
void FUN_004aa020(HWND param_1,HDC param_2,LPRECT param_3,uint param_4)

{
  int iVar1;
  UINT format;
  COLORREF local_c;
  
  PatBlt(param_2,param_3->left,param_3->top,param_3->right - param_3->left,
         param_3->bottom - param_3->top,0xf00021);
  iVar1 = GetWindowTextLengthA(param_1);
  FUN_0049c450();
  if (&stack0x00000000 != (undefined1 *)0x18) {
    iVar1 = GetWindowTextA(param_1,&stack0xffffffe8,iVar1 + 2);
    if (iVar1 != 0) {
      format = 0x140;
      if (((byte)param_4 & 0xf) != 0xc) {
        format = (UINT)((ushort)param_4 & 0xf | 0x150);
      }
      if ((param_4 & 0x80) != 0) {
        format = (UINT)(ushort)((ushort)format | 0x800);
      }
      if ((param_4 & 0x8000000) != 0) {
        local_c = SetTextColor(param_2,DAT_00539abc);
      }
      DrawTextA(param_2,&stack0xffffffe8,-1,param_3,format);
      if ((param_4 & 0x8000000) != 0) {
        SetTextColor(param_2,local_c);
      }
    }
  }
  return;
}

