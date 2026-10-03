
void __thiscall FUN_004afaba(int *param_1,int param_2)

{
  (**(code **)(*param_1 + 4))(param_2 != 0);
  if ((param_1[3] != 0) && (param_1[4] == 0)) {
    if (DAT_005381e0 == (HBITMAP)0x0) {
      FUN_004be77b();
    }
    if (DAT_005381e0 != (HBITMAP)0x0) {
      SetMenuItemBitmaps(*(HMENU *)(param_1[3] + 4),param_1[2],0x400,(HBITMAP)0x0,DAT_005381e0);
    }
  }
  return;
}

