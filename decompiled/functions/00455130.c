
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00455130(void)

{
  DAT_004a8664 = DAT_004a8664 * 2;
  _DAT_004a775c = ((DAT_004a4958 < 2) - 1 & 0xffffffc0) + 0x80;
  if (_DAT_004a775c < DAT_004a8664) {
    DAT_004a8664 = _DAT_004a775c;
  }
  return;
}

