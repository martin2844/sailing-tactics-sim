
void __thiscall FUN_0046b3da(void *this,int param_1)

{
  (**(code **)(*(int *)this + 4))(param_1 != 0);
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x10) == 0)) {
    if (DAT_004ae688 == (HBITMAP)0x0) {
      FUN_0047a09b();
    }
    if (DAT_004ae688 != (HBITMAP)0x0) {
      SetMenuItemBitmaps(*(HMENU *)(*(int *)((int)this + 0xc) + 4),*(UINT *)((int)this + 8),0x400,
                         (HBITMAP)0x0,DAT_004ae688);
    }
  }
  return;
}

