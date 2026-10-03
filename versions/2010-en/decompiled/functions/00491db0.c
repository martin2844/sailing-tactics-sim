
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00491db0(void *this,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  HWND hWnd;
  
  DAT_004faf94 = param_2;
  if ((param_2 == 0x5a) && (DAT_005363b0 == 0)) {
    DAT_00536534 = DAT_00536534 + 1;
    if (1 < DAT_00536534) {
      DAT_00536534 = 0;
    }
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if (DAT_004faf94 == 0x20) {
    if (DAT_005364fc == 1) {
      DAT_005364fc = 0;
      DAT_004faf94 = -1;
      DAT_005363b4 = 0;
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    }
    if ((((DAT_004faf94 == 0x20) && (DAT_005363b0 == 0)) && (0 < DAT_004da16c)) &&
       (DAT_0053648c == 0)) {
      DAT_0053648c = 1;
      DAT_004faf94 = -1;
      DAT_005363b4 = 0;
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    }
  }
  if (DAT_004faf94 == 0x1b) {
    DAT_00536420 = 0;
  }
  if ((DAT_004faf94 == 0x43) && (DAT_005363b0 == 0)) {
    DAT_005364fc = DAT_005364fc + 1;
    if (1 < DAT_005364fc) {
      DAT_005364fc = 0;
    }
    DAT_004da1f8 = 999;
    DAT_004da200 = 1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    DAT_004faf94 = -1;
  }
  if ((DAT_004faf94 == 0x50) &&
     ((DAT_005363b0 == 0 || ((DAT_004f8cd0 == DAT_004f42b8 && (DAT_004da1d8 < 3)))))) {
    DAT_004da1d8 = 2;
    DAT_004faf94 = -1;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x42) &&
     ((DAT_005363b0 == 0 || ((DAT_004f8cd0 == DAT_004f42b8 && (DAT_004da1d8 < 3)))))) {
    DAT_004da1d8 = 1;
    DAT_004faf94 = -1;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x34) && (DAT_005363b0 == 0)) {
    DAT_004da198 = 4;
    DAT_004faf94 = -1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x35) && (DAT_005363b0 == 0)) {
    DAT_004da198 = 5;
    DAT_004faf94 = -1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x36) && (DAT_005363b0 == 0)) {
    DAT_004da198 = 6;
    DAT_004faf94 = -1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x37) && (DAT_005363b0 == 0)) {
    DAT_004da198 = 7;
    DAT_004faf94 = -1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x38) && (DAT_005363b0 == 0)) {
    DAT_004da198 = 8;
    DAT_004faf94 = -1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x39) && (DAT_005363b0 == 0)) {
    DAT_004da198 = 9;
    DAT_004faf94 = -1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x30) && (DAT_005363b0 == 0)) {
    DAT_004da198 = 10;
    DAT_004faf94 = -1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x31) && (DAT_005363b0 == 0)) {
    DAT_004da198 = 0xb;
    DAT_004faf94 = -1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x32) && (DAT_005363b0 == 0)) {
    DAT_004da198 = 0xc;
    DAT_004faf94 = -1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x33) && (DAT_005363b0 == 0)) {
    DAT_004da198 = 0xd;
    DAT_004faf94 = -1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x4d) && (DAT_005363b0 == 0)) {
    DAT_004da154 = 2;
    DAT_004faf94 = -1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x4c) && (DAT_005363b0 == 0)) {
    DAT_004da154 = 1;
    DAT_004faf94 = -1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x53) && (DAT_005363b0 == 0)) {
    DAT_004da154 = 3;
    DAT_004faf94 = -1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x20) && (DAT_005363b0 == 0)) {
    DAT_005363b0 = 1;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    DAT_004faf94 = -1;
  }
  if (DAT_004faf94 == 0xdc) {
    DAT_004da1dc = DAT_004da1dc + 1;
    if (1 < DAT_004da1dc) {
      DAT_004da1dc = 0;
    }
    DAT_004faf94 = -1;
  }
  if (DAT_004faf94 == 0x14) {
    DAT_005364b0 = DAT_005364b0 + 1;
    if (1 < DAT_005364b0) {
      DAT_005364b0 = 0;
    }
    DAT_004faf94 = -1;
  }
  if (DAT_004faf94 == 8) {
    DAT_005364ac = DAT_005364ac + 1;
  }
  if (1 < DAT_005364ac) {
    DAT_005364ac = 0;
  }
  if (DAT_004faf94 == 0x21) {
    if (DAT_004da174 < 0xf) {
      DAT_004da174 = DAT_004da174 + 1;
    }
    FUN_00464940();
    DAT_004da180 = DAT_004da174;
    DAT_004da17c = DAT_004da178;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if (DAT_004faf94 == 0x22) {
    if (1 < DAT_004da174) {
      DAT_004da174 = DAT_004da174 + -1;
    }
    FUN_00464940();
    DAT_004da180 = DAT_004da174;
    DAT_004da17c = DAT_004da178;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((((DAT_004faf94 == 0x7b) && (DAT_00536444 == 0)) && (DAT_004da140 == 1)) &&
     (DAT_004da16c == 0)) {
    DAT_00536478 = DAT_00536478 + 1;
    if (1 < DAT_00536478) {
      DAT_00536478 = 0;
    }
    DAT_004da1a8 = 0;
    if (2 < DAT_004da194) {
      DAT_00536478 = 0;
    }
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    DAT_004faf94 = -1;
  }
  if (DAT_004faf94 == 0xba) {
    DAT_00536488 = DAT_00536488 + 1;
    if (1 < DAT_00536488) {
      DAT_00536488 = 0;
    }
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((DAT_004faf94 == 0x20) && (0 < DAT_00536444)) {
    DAT_00536444 = 0;
    DAT_00536448 = 0;
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    DAT_004faf94 = -1;
  }
  if (DAT_004faf94 == 0xbf) {
    DAT_005363b4 = 1;
    DAT_00536444 = 6;
    DAT_00536448 = 6;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    DAT_004fb9b4 = 0;
  }
  if ((DAT_004faf94 == 0x20) && (0 < DAT_005363b0)) {
    if (((DAT_005363f0 == 0) &&
        (((DAT_005233a8 == 0 && (DAT_00536434 == 0)) && (DAT_00536438 == 0)))) &&
       ((DAT_0053644c == 0 && (DAT_00536444 == 0)))) {
      if (DAT_004da174 == 1) {
        DAT_004da178 = DAT_004da17c;
        DAT_004da174 = DAT_004da180;
        if (DAT_004da1dc == 1) {
          DAT_004da1dc = 2;
          DAT_004da1e0 = DAT_004f8cd0;
        }
      }
      else {
        DAT_004da180 = DAT_004da174;
        DAT_004da17c = DAT_004da178;
        DAT_004da178 = 0xb67;
        DAT_004da174 = 1;
      }
    }
    else {
      DAT_005363f0 = 0;
      DAT_00536438 = 0;
      DAT_00536434 = 0;
      DAT_00536404 = 0;
      DAT_005233a8 = 0;
      DAT_00536444 = 0;
      DAT_00536448 = 0;
      DAT_0053644c = 0;
      DAT_0053642c = 0;
      DAT_005363b4 = 0;
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    }
    DAT_004faf94 = -1;
  }
  if (DAT_004faf94 == 0x4e) {
    DAT_005363b0 = 0;
    DAT_00536440 = 0;
    DAT_005363f4 = 0;
    DAT_00536444 = 0;
    DAT_0053648c = 0;
    DAT_005363f0 = 0;
    if (2 < DAT_005363fc) {
      DAT_005363fc = 0;
    }
    DAT_005363b4 = 0;
    DAT_004f8cd0 = DAT_004f42b8;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,1);
  }
  if (DAT_004faf94 == 0x46) {
    DAT_0053642c = DAT_0053642c + 1;
    if (1 < DAT_0053642c) {
      DAT_0053642c = 0;
    }
    if (DAT_0053642c == 0) {
      DAT_005363b4 = 0;
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    }
    else {
      DAT_005363b4 = 1;
    }
  }
  if (DAT_004faf94 == 0x52) {
    DAT_005233a8 = DAT_005233a8 + 1;
    bVar6 = DAT_005233a8 == 1;
    if (1 < DAT_005233a8) {
      DAT_005233a8 = 0;
    }
    if (bVar6) {
      hWnd = *(HWND *)((int)this + 0x1c);
    }
    else {
      DAT_005363b4 = 0;
      hWnd = *(HWND *)((int)this + 0x1c);
    }
    InvalidateRect(hWnd,(RECT *)0x0,0);
    DAT_00536404 = 0;
    DAT_00536434 = 0;
    DAT_00536438 = 0;
    DAT_005363f0 = 0;
  }
  if (DAT_004faf94 == 0x57) {
    DAT_005363f0 = DAT_005363f0 + 1;
    if (1 < DAT_005363f0) {
      DAT_005363f0 = 0;
    }
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,1);
    DAT_00536404 = 0;
    DAT_005233a8 = 0;
    DAT_00536444 = 0;
    DAT_004fafa0 = 1;
  }
  if ((DAT_004faf94 == 0x59) && (DAT_004da140 == 1)) {
    if (DAT_00536448 == 300) {
      DAT_00536444 = 0;
      DAT_00536448 = 0;
    }
    else {
      DAT_00536444 = 300;
      DAT_00536448 = 300;
      DAT_005363f0 = 0;
    }
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if (DAT_004faf94 == 0xdb) {
    DAT_00536434 = DAT_00536434 + 1;
    if (1 < DAT_00536434) {
      DAT_00536434 = 0;
    }
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    DAT_00536438 = 0;
    DAT_005233a8 = 0;
    DAT_005363f0 = 0;
    DAT_00536404 = 0;
    DAT_00536444 = 0;
  }
  if ((DAT_004faf94 == 0xdd) && (0 < DAT_005359d0)) {
    DAT_00536438 = DAT_00536438 + 1;
    if (1 < DAT_00536438) {
      DAT_00536438 = 0;
    }
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    DAT_00536434 = 0;
    DAT_005233a8 = 0;
    DAT_005363f0 = 0;
    DAT_00536404 = 0;
    DAT_00536444 = 0;
  }
  iVar4 = DAT_004fe770;
  iVar5 = DAT_004faf94;
  iVar3 = DAT_004da140;
  if (((DAT_005233a8 == 1) || (DAT_00536434 == 1)) || (DAT_00536438 == 1)) {
    if (DAT_004faf94 == 0x58) {
      DAT_004da200 = 1;
      DAT_005363b4 = 0;
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    }
    iVar3 = DAT_004da140;
    iVar5 = DAT_004faf94;
    if (DAT_004faf94 == 0x5a) {
      DAT_004da200 = 0;
      DAT_005363b4 = 0;
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
      iVar3 = DAT_004da140;
      iVar5 = DAT_004faf94;
    }
  }
  else {
    if (DAT_004faf94 == 0x58) {
      iVar2 = *(int *)(&DAT_0050f6d0 + DAT_004da140 * 4) * 2;
      iVar1 = iVar2 - DAT_004fe770;
      *(int *)(&DAT_0050f6d0 + DAT_004da140 * 4) = iVar2;
      if (iVar1 != 0 && iVar4 <= iVar2) {
        *(int *)(&DAT_0050f6d0 + iVar3 * 4) = iVar4;
      }
    }
    if ((iVar5 == 0x5a) &&
       (iVar4 = *(int *)(&DAT_0050f6d0 + iVar3 * 4), *(int *)(&DAT_0050f6d0 + iVar3 * 4) = iVar4 / 2
       , iVar4 / 2 < 2)) {
      *(undefined4 *)(&DAT_0050f6d0 + iVar3 * 4) = 2;
    }
  }
  if ((iVar5 == 0x42) &&
     (iVar4 = (&DAT_00525a78)[iVar3], (&DAT_00525a78)[iVar3] = iVar4 + 1, 2 < iVar4 + 1)) {
    (&DAT_00525a78)[iVar3] = 0;
  }
  if (iVar5 == 0x56) {
    iVar4 = *(int *)(&DAT_004f71c0 + iVar3 * 4);
    *(undefined4 *)(iVar3 * 4 + 0x523a58) = 0;
    *(int *)(&DAT_004f71c0 + iVar3 * 4) = iVar4 + 1;
    if (3 < iVar4 + 1) {
      *(undefined4 *)(&DAT_004f71c0 + iVar3 * 4) = 1;
    }
  }
  if ((iVar5 == 0x55) &&
     (iVar4 = *(int *)(iVar3 * 4 + 0x4f41f0) + 1, *(int *)(iVar3 * 4 + 0x4f41f0) = iVar4, 1 < iVar4)
     ) {
    *(undefined4 *)(iVar3 * 4 + 0x4f41f0) = 0;
  }
  if ((iVar5 == 0xbc) || (iVar5 == 0xde)) {
    if (iVar3 == 1) {
      _DAT_004fe938 = _DAT_004fe938 - _DAT_004cc580;
    }
    else {
      DAT_00535748 = FUN_0041bc20(DAT_00535748 + -10);
      iVar3 = DAT_004da140;
      iVar5 = DAT_004faf94;
    }
    *(undefined4 *)(&DAT_00511620 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004f6a68 + iVar3 * 4) = 0;
    *(undefined4 *)(iVar3 * 4 + 0x4fbba8) = 0;
    *(undefined4 *)(&DAT_004f7090 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_005356b0 + iVar3 * 4) = 0;
  }
  if ((iVar5 == 0xbe) || (iVar5 == 0xd)) {
    if (iVar3 == 1) {
      _DAT_004fe938 = _DAT_004fe938 - _DAT_004cc588;
    }
    else {
      DAT_00535748 = FUN_0041bc20(DAT_00535748 + 10);
      iVar3 = DAT_004da140;
      iVar5 = DAT_004faf94;
    }
    *(undefined4 *)(&DAT_00511620 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004f6a68 + iVar3 * 4) = 0;
    *(undefined4 *)(iVar3 * 4 + 0x4fbba8) = 0;
    *(undefined4 *)(&DAT_004f7090 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_005356b0 + iVar3 * 4) = 0;
  }
  if (iVar5 == 0x43) {
    *(undefined4 *)(&DAT_004f7090 + iVar3 * 4) = 0xffffffff;
    *(undefined4 *)(&DAT_005359e0 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_00511620 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004f6a68 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_005356b0 + iVar3 * 4) = 0;
  }
  iVar4 = DAT_004f8cd0;
  if (iVar5 == 0x54) {
    *(undefined4 *)(&DAT_004f7090 + iVar3 * 4) = 1;
    *(undefined4 *)(&DAT_00511620 + iVar3 * 4) = 0;
    *(undefined4 *)(iVar3 * 4 + 0x4fbba8) = 0;
    *(undefined4 *)(&DAT_004f6a68 + iVar3 * 4) = 0;
    *(int *)(&DAT_004f4350 + iVar3 * 4) = iVar4;
    *(undefined4 *)(&DAT_004f4a70 + iVar3 * 4) = 1;
    *(undefined4 *)(&DAT_005356b0 + iVar3 * 4) = 0;
  }
  if (iVar5 == 0x4a) {
    *(undefined4 *)(&DAT_005356b0 + iVar3 * 4) = 1;
    *(undefined4 *)(&DAT_00511620 + iVar3 * 4) = 0;
    *(undefined4 *)(iVar3 * 4 + 0x4fbba8) = 0;
    *(undefined4 *)(&DAT_004f6a68 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004f7090 + iVar3 * 4) = 0;
  }
  if (iVar5 == 0x48) {
    if (*(int *)(&DAT_004fecc8 + iVar3 * 4) < 0x5a) {
      *(undefined4 *)(iVar3 * 4 + 0x4fbba8) = 2;
    }
    else {
      *(undefined4 *)(iVar3 * 4 + 0x4fbba8) = 3;
    }
    *(undefined4 *)(&DAT_00511620 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004f6a68 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004f7090 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_005356b0 + iVar3 * 4) = 0;
  }
  if ((iVar5 == 0x44) && (0 < DAT_005363b0)) {
    *(undefined4 *)(iVar3 * 4 + 0x4fbba8) = 1;
    *(undefined4 *)(&DAT_00511620 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004f6a68 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004f7090 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_005356b0 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004f3f60 + iVar3 * 4) = 0;
  }
  if ((iVar5 == 0xbd) && (DAT_00536444 == 0 && DAT_00536438 == 1)) {
    DAT_00536404 = DAT_00536404 + -1;
    if (DAT_00536404 < 0) {
      DAT_00536404 = 0;
    }
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    iVar3 = DAT_004da140;
    iVar5 = DAT_004faf94;
  }
  iVar4 = DAT_00536444;
  if (iVar5 == 0xbb) {
    if (DAT_00536444 == 0) {
      if (DAT_00536438 == 1) {
        DAT_005363b4 = 0;
        DAT_00536404 = DAT_00536404 + 1;
        InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
        iVar4 = DAT_00536444;
        iVar3 = DAT_004da140;
        iVar5 = DAT_004faf94;
      }
      else {
        if (0 < *(int *)(&DAT_00511620 + iVar3 * 4)) {
          *(undefined4 *)(&DAT_005359e0 + iVar3 * 4) = 5;
          *(undefined4 *)(&DAT_00511620 + iVar3 * 4) = 1;
          *(undefined4 *)(&DAT_004f6a68 + iVar3 * 4) = 0;
          *(undefined4 *)(&DAT_004f7090 + iVar3 * 4) = 0;
          *(undefined4 *)(&DAT_005356b0 + iVar3 * 4) = 0;
        }
        if (0 < *(int *)(&DAT_004f6a68 + iVar3 * 4)) {
          *(undefined4 *)(&DAT_004f3f60 + iVar3 * 4) = 7;
          *(undefined4 *)(&DAT_004f6a68 + iVar3 * 4) = 1;
          *(undefined4 *)(iVar3 * 4 + 0x4fbba8) = 0;
          *(undefined4 *)(&DAT_004f7090 + iVar3 * 4) = 0;
          *(undefined4 *)(&DAT_005356b0 + iVar3 * 4) = 0;
          *(undefined4 *)(&DAT_00511620 + iVar3 * 4) = 0;
        }
      }
    }
    if ((((iVar5 == 0xbb) && (100 < iVar4)) && (iVar4 < 0x6e)) &&
       ((DAT_004da16c == 0 || (iVar4 < 0x66)))) {
      DAT_004fb9b4 = 0;
      DAT_00536444 = DAT_00536444 + 1;
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
      iVar4 = DAT_00536444;
      iVar3 = DAT_004da140;
      iVar5 = DAT_004faf94;
    }
  }
  if (((iVar5 == 0xbd) && (0x65 < iVar4)) && (iVar4 < 0x6f)) {
    DAT_004fb9b4 = 0;
    DAT_00536444 = DAT_00536444 + -1;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    iVar4 = DAT_00536444;
    iVar3 = DAT_004da140;
    iVar5 = DAT_004faf94;
  }
  if ((((iVar5 == 0xbb) && (500 < iVar4)) && (iVar4 < 0x202)) &&
     ((DAT_004da16c == 0 || (iVar4 < 0x1f6)))) {
    DAT_004fb9b4 = 0;
    DAT_00536444 = DAT_00536444 + 1;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    iVar4 = DAT_00536444;
    iVar3 = DAT_004da140;
    iVar5 = DAT_004faf94;
  }
  if (((iVar5 == 0xbd) && (0x1f5 < iVar4)) && (iVar4 < 0x203)) {
    DAT_004fb9b4 = 0;
    DAT_00536444 = DAT_00536444 + -1;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    iVar4 = DAT_00536444;
    iVar3 = DAT_004da140;
    iVar5 = DAT_004faf94;
  }
  if (((iVar5 == 0xbb) && (600 < iVar4)) && (iVar4 < 0x25c)) {
    DAT_004fb9b4 = 0;
    DAT_00536444 = DAT_00536444 + 1;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    iVar4 = DAT_00536444;
    iVar3 = DAT_004da140;
    iVar5 = DAT_004faf94;
  }
  if (iVar5 == 0xbd) {
    if ((0x259 < iVar4) && (iVar4 < 0x25d)) {
      DAT_004fb9b4 = 0;
      DAT_00536444 = DAT_00536444 + -1;
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
      iVar4 = DAT_00536444;
      iVar3 = DAT_004da140;
      iVar5 = DAT_004faf94;
    }
    if ((iVar5 == 0xbd) && (iVar4 == 0)) {
      if (0 < *(int *)(&DAT_00511620 + iVar3 * 4)) {
        *(undefined4 *)(&DAT_005359e0 + iVar3 * 4) = 0xfffffffb;
        *(undefined4 *)(&DAT_00511620 + iVar3 * 4) = 1;
        *(undefined4 *)(&DAT_004f6a68 + iVar3 * 4) = 0;
        *(undefined4 *)(&DAT_004f7090 + iVar3 * 4) = 0;
        *(undefined4 *)(&DAT_005356b0 + iVar3 * 4) = 0;
      }
      if (0 < *(int *)(&DAT_004f6a68 + iVar3 * 4)) {
        *(undefined4 *)(&DAT_004f3f60 + iVar3 * 4) = 0xfffffff9;
        *(undefined4 *)(&DAT_004f6a68 + iVar3 * 4) = 1;
        *(undefined4 *)(iVar3 * 4 + 0x4fbba8) = 0;
        *(undefined4 *)(&DAT_004f7090 + iVar3 * 4) = 0;
        *(undefined4 *)(&DAT_005356b0 + iVar3 * 4) = 0;
        *(undefined4 *)(&DAT_00511620 + iVar3 * 4) = 0;
      }
    }
  }
  if (iVar5 == 0x53) {
    if (0 < DAT_005363b0) {
      *(undefined4 *)(&DAT_00500380 + iVar3 * 4) = 0x5a;
    }
    if (DAT_005363b0 == 0) {
      DAT_00536468 = DAT_00536468 + 1;
    }
  }
  if (1 < DAT_00536468) {
    DAT_00536468 = 0;
  }
  if (iVar5 == 0x41) {
    if (iVar4 == 0) {
      *(undefined4 *)(&DAT_00500380 + iVar3 * 4) = 0xffffffff;
    }
    if (0 < iVar4) {
      DAT_004fb9b4 = DAT_004fb9b4 + 1;
      if (DAT_004da18c < DAT_004fb9b4) {
        DAT_004fb9b4 = 0;
      }
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
      DAT_005363b4 = 1;
      iVar3 = DAT_004da140;
      iVar5 = DAT_004faf94;
    }
  }
  if ((iVar5 == 0x1b) &&
     (iVar4 = *(int *)(&DAT_00500380 + iVar3 * 4), *(int *)(&DAT_00500380 + iVar3 * 4) = iVar4 + -5,
     iVar4 + -5 < 0)) {
    *(undefined4 *)(&DAT_00500380 + iVar3 * 4) = 0;
  }
  if ((iVar5 == 0xc0) &&
     (iVar4 = *(int *)(&DAT_00500380 + iVar3 * 4), *(int *)(&DAT_00500380 + iVar3 * 4) = iVar4 + 5,
     0x5a < iVar4 + 5)) {
    *(undefined4 *)(&DAT_00500380 + iVar3 * 4) = 0x5a;
  }
  if (((iVar5 == 0x47) && (iVar3 == 1)) && (DAT_004f7ee4 = DAT_004f7ee4 + 1, 3 < DAT_004f7ee4)) {
    DAT_004f7ee4 = 1;
  }
  if ((iVar5 == 0x49) &&
     (iVar4 = *(int *)(&DAT_00500380 + iVar3 * 4),
     *(int *)(&DAT_00500380 + iVar3 * 4) = iVar4 + -0x14, iVar4 + -0x14 < 0)) {
    *(undefined4 *)(&DAT_00500380 + iVar3 * 4) = 0xffffffff;
  }
  if ((iVar5 == 0x4f) &&
     (iVar4 = *(int *)(&DAT_00500380 + iVar3 * 4),
     *(int *)(&DAT_00500380 + iVar3 * 4) = iVar4 + 0x14, 0x5a < iVar4 + 0x14)) {
    *(undefined4 *)(&DAT_00500380 + iVar3 * 4) = 0x5a;
  }
  iVar4 = DAT_005364c8;
  if (((iVar5 == 0x45) && (DAT_005364c8 == 0)) &&
     (iVar1 = *(int *)(&DAT_004fe778 + iVar3 * 4), *(int *)(&DAT_004fe778 + iVar3 * 4) = iVar1 + 1,
     3 < iVar1 + 1)) {
    *(undefined4 *)(&DAT_004fe778 + iVar3 * 4) = 1;
  }
  if ((iVar5 == 0x70) && (iVar4 == 0)) {
    *(undefined4 *)(&DAT_004fe778 + iVar3 * 4) = 1;
  }
  if ((iVar5 == 0x71) && (iVar4 == 0)) {
    *(undefined4 *)(&DAT_004fe778 + iVar3 * 4) = 2;
  }
  if ((iVar5 == 0x72) && (iVar4 == 0)) {
    *(undefined4 *)(&DAT_004fe778 + iVar3 * 4) = 3;
  }
  if (iVar5 == 0x73) {
    (&DAT_00525a78)[iVar3] = 1;
  }
  if (iVar5 == 0x74) {
    (&DAT_00525a78)[iVar3] = 2;
  }
  if ((((iVar5 == 0x50) && (iVar3 == 1)) && (1 < DAT_004da190)) &&
     ((DAT_004da190 != 9 && (DAT_004f4520 = DAT_004f4520 + 1, 1 < DAT_004f4520)))) {
    DAT_004f4520 = 0;
  }
  if (((iVar5 == 0x50) && (iVar3 == 2)) &&
     ((1 < DAT_004da190 &&
      ((DAT_004da190 != 9 && (DAT_004f4524 = DAT_004f4524 + 1, 1 < DAT_004f4524)))))) {
    DAT_004f4524 = 0;
  }
  if ((iVar5 == 0x4c) && (DAT_00536490 = DAT_00536490 + 1, 1 < DAT_00536490)) {
    DAT_00536490 = 0;
  }
  if ((iVar5 == 0x30) &&
     (iVar4 = *(int *)(iVar3 * 4 + 0x523a58) + 1, *(int *)(iVar3 * 4 + 0x523a58) = iVar4, 1 < iVar4)
     ) {
    *(undefined4 *)(iVar3 * 4 + 0x523a58) = 0;
  }
  if (iVar5 == 0x31) {
    *(undefined4 *)(&DAT_004f71c0 + iVar3 * 4) = 1;
    *(undefined4 *)(iVar3 * 4 + 0x523a58) = 0;
  }
  if (iVar5 == 0x32) {
    *(undefined4 *)(&DAT_004f71c0 + iVar3 * 4) = 2;
    *(undefined4 *)(iVar3 * 4 + 0x523a58) = 0;
  }
  if (iVar5 == 0x33) {
    *(undefined4 *)(&DAT_004f71c0 + iVar3 * 4) = 3;
    *(undefined4 *)(iVar3 * 4 + 0x523a58) = 0;
  }
  if (((iVar5 == 0x34) && (iVar3 == 1)) && (DAT_00536478 == 0)) {
    DAT_004da1a8 = DAT_004da1a8 + 1;
    if (1 < DAT_004da1a8) {
      DAT_004da1a8 = 0;
    }
    DAT_005363b4 = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    iVar3 = DAT_004da140;
    iVar5 = DAT_004faf94;
  }
  if ((iVar5 == 0x37) || (iVar5 == 0x24)) {
    *(undefined4 *)(&DAT_004f49a0 + iVar3 * 4) = 0;
    *(uint *)(&DAT_00512d60 + iVar3 * 4) = -(uint)(*(int *)(&DAT_00512d60 + iVar3 * 4) != -1);
  }
  if ((iVar5 == 0x35) || (iVar5 == 0xc)) {
    *(undefined4 *)(&DAT_004f49a0 + iVar3 * 4) = 0;
    *(uint *)(&DAT_00512d60 + iVar3 * 4) = (uint)(*(int *)(&DAT_00512d60 + iVar3 * 4) != 1);
  }
  if (iVar5 == 0x39) {
    DAT_005233a4 = 0;
    *(undefined4 *)(&DAT_004f49a0 + iVar3 * 4) = 0;
    *(uint *)(&DAT_00512d60 + iVar3 * 4) = -(uint)(*(int *)(&DAT_00512d60 + iVar3 * 4) != 100) & 100
    ;
  }
  if (iVar5 == 0x26) {
    *(undefined4 *)(&DAT_004f49a0 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_00512d60 + iVar3 * 4) = 0;
  }
  if (iVar5 == 0x28) {
    *(undefined4 *)(&DAT_004f49a0 + iVar3 * 4) = 0xb4;
    *(undefined4 *)(&DAT_00512d60 + iVar3 * 4) = 0;
  }
  if (iVar5 == 0x27) {
    iVar4 = *(int *)(&DAT_004f49a0 + iVar3 * 4);
    *(int *)(&DAT_004f49a0 + iVar3 * 4) = iVar4 + -0x1e;
    if (iVar4 + -0x1e < -0x168) {
      *(undefined4 *)(&DAT_004f49a0 + iVar3 * 4) = 0;
    }
    *(undefined4 *)(&DAT_00512d60 + iVar3 * 4) = 0;
  }
  if (iVar5 == 0x25) {
    iVar5 = *(int *)(&DAT_004f49a0 + iVar3 * 4);
    *(int *)(&DAT_004f49a0 + iVar3 * 4) = iVar5 + 0x1e;
    if (0x168 < iVar5 + 0x1e) {
      *(undefined4 *)(&DAT_004f49a0 + iVar3 * 4) = 0;
    }
    *(undefined4 *)(&DAT_00512d60 + iVar3 * 4) = 0;
  }
  FUN_004ac701(this);
  return;
}

