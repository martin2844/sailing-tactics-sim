
void __thiscall FUN_004792bb(void *this,int param_1)

{
  if ((DAT_004ae69c == 0) && (param_1 == 3)) {
    *(undefined4 *)((int)this + 0xbc) = 1;
    *(undefined4 *)((int)this + 0xc0) = 1;
    SetCapture(*(HWND *)((int)this + 0x1c));
    FUN_004680cc();
    FUN_004793e7();
  }
  else {
    FUN_00468021(this);
  }
  return;
}

