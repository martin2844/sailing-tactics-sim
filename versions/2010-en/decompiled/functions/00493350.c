
void __thiscall FUN_00493350(void *this,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  DAT_004fe75c = param_3;
  DAT_005233a4 = param_4;
  if ((((0 < param_3) && (param_3 < DAT_004fe624 / 3 + 2)) && (param_4 < DAT_004faf7c + 0x14)) &&
     ((DAT_004faf7c < param_4 && (0 < DAT_00536444)))) {
    DAT_004fb9b4 = DAT_004fb9b4 + 1;
    if (DAT_004da18c < DAT_004fb9b4) {
      DAT_004fb9b4 = 0;
    }
    DAT_005233a4 = 0;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  iVar1 = DAT_0053644c + DAT_00536448 + DAT_00536444 + DAT_00536438 + DAT_00536434 + DAT_0053642c +
          DAT_005233a8 + DAT_005363f0;
  if ((((int)(DAT_004fe2a8 + (DAT_004fe2a8 >> 0x1f & 0xfU)) >> 4) + 0x14 < DAT_005233a4) &&
     (0 < iVar1)) {
    DAT_00536438 = 0;
    DAT_00536434 = 0;
    DAT_005233a8 = 0;
    DAT_0053642c = 0;
    DAT_005363f0 = 0;
    DAT_0053644c = 0;
    DAT_00536444 = 0;
    DAT_00536448 = 0;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if (((0 < DAT_005233a4) && (iVar1 == 0)) && (DAT_005363b4 == 1)) {
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  FUN_004ac701(this);
  return;
}

