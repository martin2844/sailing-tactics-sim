
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00497f30(void *this)

{
  _DAT_004da230 = _DAT_004da230 - _DAT_004cc700;
  if (_DAT_004cc650 < _DAT_004da230) {
    _DAT_004da230 = 0.0;
  }
  if (_DAT_004da230 == _DAT_004cc650) {
    DAT_00536480 = 0;
  }
  DAT_005363b4 = 0;
  InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  return;
}

