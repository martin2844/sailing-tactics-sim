
void __thiscall FUN_004724a4(void *this,int param_1)

{
  HCURSOR pHVar1;
  
  FUN_0047c1af(2);
  *(int *)((int)this + 0xa0) = *(int *)((int)this + 0xa0) + param_1;
  if (*(int *)((int)this + 0xa0) < 1) {
    *(undefined4 *)((int)this + 0xa0) = 0;
    SetCursor(*(HCURSOR *)((int)this + 0xa4));
  }
  else {
    pHVar1 = SetCursor(DAT_004ae674);
    if ((0 < param_1) && (*(int *)((int)this + 0xa0) == 1)) {
      *(HCURSOR *)((int)this + 0xa4) = pHVar1;
    }
  }
  FUN_0047c21f(2);
  return;
}

