
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004517c0(void *this,int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  HWND hWnd;
  
  DAT_004a60a4 = param_1;
  if (param_1 == 0xdc) {
    DAT_004911d0 = DAT_004911d0 + 1;
    if (1 < DAT_004911d0) {
      DAT_004911d0 = 0;
    }
    DAT_004a60a4 = -1;
  }
  if (DAT_004a60a4 == 8) {
    DAT_004ac9ec = DAT_004ac9ec + 1;
  }
  if (1 < DAT_004ac9ec) {
    DAT_004ac9ec = 0;
  }
  if (DAT_004a60a4 == 0x21) {
    if (DAT_0049116c < 0xf) {
      DAT_0049116c = DAT_0049116c + 1;
    }
    FUN_0044e380();
    DAT_00491178 = DAT_0049116c;
    DAT_00491174 = DAT_00491170;
    DAT_004ac8fc = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if (DAT_004a60a4 == 0x22) {
    if (1 < DAT_0049116c) {
      DAT_0049116c = DAT_0049116c + -1;
    }
    FUN_0044e380();
    DAT_00491178 = DAT_0049116c;
    DAT_00491174 = DAT_00491170;
    DAT_004ac8fc = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if ((((DAT_004a60a4 == 0x7b) && (DAT_004ac980 == 0)) && (DAT_00491140 == 1)) &&
     (DAT_00491164 == 0)) {
    DAT_004ac9b4 = DAT_004ac9b4 + 1;
    if (1 < DAT_004ac9b4) {
      DAT_004ac9b4 = 0;
    }
    DAT_004ac9c8 = 0;
    if (2 < DAT_0049118c) {
      DAT_004ac9b4 = 0;
    }
    DAT_004ac8fc = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    DAT_004a60a4 = -1;
  }
  if (DAT_004a60a4 == 0xba) {
    DAT_004ac9c4 = DAT_004ac9c4 + 1;
    if (1 < DAT_004ac9c4) {
      DAT_004ac9c4 = 0;
    }
    DAT_004ac8fc = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if (DAT_004a60a4 == 0x20) {
    if (0 < DAT_004ac980) {
      DAT_004ac980 = 0;
      DAT_004ac984 = 0;
      DAT_004ac8fc = 0;
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
      DAT_004a60a4 = -1;
    }
    if (DAT_004a60a4 == 0x20) {
      if (((DAT_004ac8f8 == 0) && (0 < DAT_00491164)) && (DAT_004ac9cc == 0)) {
        DAT_004ac9cc = 1;
        DAT_004a60a4 = -1;
        DAT_004ac8fc = 0;
        InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
      }
      if ((DAT_004a60a4 == 0x20) && (DAT_004ac8f8 == 0)) {
        DAT_004ac8f8 = 1;
        DAT_004ac8fc = 0;
        InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
        DAT_004a60a4 = -1;
      }
    }
  }
  if (DAT_004a60a4 == 0x1b) {
    DAT_004ac95c = 0;
  }
  if (DAT_004a60a4 == 0xbf) {
    DAT_004ac8fc = 1;
    DAT_004ac980 = 6;
    DAT_004ac984 = 6;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    DAT_004a6774 = 0;
  }
  if ((DAT_004a60a4 == 0x20) && (0 < DAT_004ac8f8)) {
    if (((DAT_004ac938 == 0) &&
        (((DAT_004aa980 == 0 && (DAT_004ac970 == 0)) && (DAT_004ac974 == 0)))) &&
       ((DAT_004ac988 == 0 && (DAT_004ac980 == 0)))) {
      if (DAT_0049116c == 1) {
        DAT_00491170 = DAT_00491174;
        DAT_0049116c = DAT_00491178;
        if (DAT_004911d0 == 1) {
          DAT_004911d0 = 2;
          DAT_004911d4 = DAT_004a5b80;
        }
      }
      else {
        DAT_00491178 = DAT_0049116c;
        DAT_00491174 = DAT_00491170;
        DAT_00491170 = 0xb67;
        DAT_0049116c = 1;
      }
    }
    else {
      DAT_004ac938 = 0;
      DAT_004ac974 = 0;
      DAT_004ac970 = 0;
      DAT_004ac94c = 0;
      DAT_004aa980 = 0;
      DAT_004ac980 = 0;
      DAT_004ac984 = 0;
      DAT_004ac988 = 0;
      DAT_004ac968 = 0;
      DAT_004ac8fc = 0;
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    }
  }
  if (DAT_004a60a4 == 0x4e) {
    DAT_004ac8f8 = 0;
    DAT_004ac97c = 0;
    DAT_004ac93c = 0;
    DAT_004ac980 = 0;
    DAT_004ac9cc = 0;
    if (2 < DAT_004ac944) {
      DAT_004ac944 = 0;
    }
    DAT_004ac8fc = 0;
    DAT_004a5b80 = DAT_004a4168;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,1);
  }
  if (DAT_004a60a4 == 0x46) {
    DAT_004ac968 = DAT_004ac968 + 1;
    if (1 < DAT_004ac968) {
      DAT_004ac968 = 0;
    }
    if (DAT_004ac968 == 0) {
      DAT_004ac8fc = 0;
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    }
    else {
      DAT_004ac8fc = 1;
    }
  }
  if (DAT_004a60a4 == 0x52) {
    DAT_004aa980 = DAT_004aa980 + 1;
    bVar6 = DAT_004aa980 != 1;
    if (1 < DAT_004aa980) {
      DAT_004aa980 = 0;
    }
    if (bVar6) {
      hWnd = *(HWND *)((int)this + 0x1c);
    }
    else {
      hWnd = *(HWND *)((int)this + 0x1c);
    }
    DAT_004ac8fc = (uint)!bVar6;
    InvalidateRect(hWnd,(RECT *)0x0,0);
    DAT_004ac94c = 0;
    DAT_004ac970 = 0;
    DAT_004ac974 = 0;
    DAT_004ac938 = 0;
  }
  if (DAT_004a60a4 == 0x57) {
    DAT_004ac938 = DAT_004ac938 + 1;
    if (1 < DAT_004ac938) {
      DAT_004ac938 = 0;
    }
    DAT_004ac8fc = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,1);
    DAT_004ac94c = 0;
    DAT_004aa980 = 0;
    DAT_004ac980 = 0;
    DAT_004a60a8 = 1;
  }
  if ((DAT_004a60a4 == 0x59) && (DAT_00491140 == 1)) {
    if (DAT_004ac984 == 300) {
      DAT_004ac980 = 0;
      DAT_004ac984 = 0;
    }
    else {
      DAT_004ac980 = 300;
      DAT_004ac984 = 300;
      DAT_004ac938 = 0;
    }
    DAT_004ac8fc = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
  }
  if (DAT_004a60a4 == 0xdb) {
    DAT_004ac970 = DAT_004ac970 + 1;
    if (1 < DAT_004ac970) {
      DAT_004ac970 = 0;
    }
    DAT_004ac8fc = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    DAT_004ac974 = 0;
    DAT_004aa980 = 0;
    DAT_004ac938 = 0;
    DAT_004ac94c = 0;
    DAT_004ac980 = 0;
  }
  if (DAT_004a60a4 == 0xdd) {
    DAT_004ac974 = DAT_004ac974 + 1;
    if (1 < DAT_004ac974) {
      DAT_004ac974 = 0;
    }
    DAT_004ac8fc = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    DAT_004ac970 = 0;
    DAT_004aa980 = 0;
    DAT_004ac938 = 0;
    DAT_004ac94c = 0;
    DAT_004ac980 = 0;
  }
  iVar5 = DAT_004a60a4;
  iVar3 = DAT_00491140;
  iVar4 = ((DAT_004a4958 < 2) - 1 & 0xffffffc0) + 0x80;
  _DAT_004a775c = iVar4;
  if (DAT_004a60a4 == 0x58) {
    iVar2 = *(int *)(&DAT_004a8660 + DAT_00491140 * 4) * 2;
    *(int *)(&DAT_004a8660 + DAT_00491140 * 4) = iVar2;
    if (iVar2 - iVar4 != 0 && iVar4 <= iVar2) {
      *(int *)(&DAT_004a8660 + iVar3 * 4) = iVar4;
    }
  }
  if ((iVar5 == 0x5a) &&
     (iVar4 = *(int *)(&DAT_004a8660 + iVar3 * 4), *(int *)(&DAT_004a8660 + iVar3 * 4) = iVar4 / 2,
     iVar4 / 2 < 2)) {
    *(undefined4 *)(&DAT_004a8660 + iVar3 * 4) = 2;
  }
  if ((iVar5 == 0x42) &&
     (iVar4 = (&DAT_004ab160)[iVar3], (&DAT_004ab160)[iVar3] = iVar4 + 1, 2 < iVar4 + 1)) {
    (&DAT_004ab160)[iVar3] = 0;
  }
  if (iVar5 == 0x56) {
    iVar4 = *(int *)(&DAT_004a4e88 + iVar3 * 4);
    *(undefined4 *)(iVar3 * 4 + 0x4aae20) = 0;
    *(int *)(&DAT_004a4e88 + iVar3 * 4) = iVar4 + 1;
    if (3 < iVar4 + 1) {
      *(undefined4 *)(&DAT_004a4e88 + iVar3 * 4) = 1;
    }
  }
  if ((iVar5 == 0x55) &&
     (*(int *)(iVar3 * 4 + 0x4a40c0) = *(int *)(iVar3 * 4 + 0x4a40c0) + 1,
     1 < *(int *)(iVar3 * 4 + 0x4a40c0))) {
    *(undefined4 *)(iVar3 * 4 + 0x4a40c0) = 0;
  }
  if ((iVar5 == 0xc0) && (DAT_004ac958 = DAT_004ac958 + 1, 1 < DAT_004ac958)) {
    DAT_004ac958 = 0;
  }
  if (iVar5 == 0xbc) {
    if (iVar3 == 1) {
      _DAT_004a78e8 = _DAT_004a78e8 - _DAT_00484d58;
    }
    else {
      DAT_004ac020 = FUN_00413cb0(DAT_004ac020 + -10);
      iVar3 = DAT_00491140;
      iVar5 = DAT_004a60a4;
    }
    *(undefined4 *)(&DAT_004a8910 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004a4968 + iVar3 * 4) = 0;
    *(undefined4 *)(iVar3 * 4 + 0x4a6848) = 0;
    *(undefined4 *)(&DAT_004a4df8 + iVar3 * 4) = 0;
    *(undefined4 *)(iVar3 * 4 + 0x4abf98) = 0;
  }
  if (iVar5 == 0xbe) {
    if (iVar3 == 1) {
      _DAT_004a78e8 = _DAT_004a78e8 - _DAT_00484d60;
    }
    else {
      DAT_004ac020 = FUN_00413cb0(DAT_004ac020 + 10);
      iVar3 = DAT_00491140;
      iVar5 = DAT_004a60a4;
    }
    *(undefined4 *)(&DAT_004a8910 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004a4968 + iVar3 * 4) = 0;
    *(undefined4 *)(iVar3 * 4 + 0x4a6848) = 0;
    *(undefined4 *)(&DAT_004a4df8 + iVar3 * 4) = 0;
    *(undefined4 *)(iVar3 * 4 + 0x4abf98) = 0;
  }
  if (iVar5 == 0x43) {
    *(undefined4 *)(&DAT_004a4df8 + iVar3 * 4) = 0xffffffff;
    *(undefined4 *)(&DAT_004ac1e8 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004a8910 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004a4968 + iVar3 * 4) = 0;
    *(undefined4 *)(iVar3 * 4 + 0x4abf98) = 0;
  }
  uVar1 = DAT_004a5b80;
  if (iVar5 == 0x54) {
    *(undefined4 *)(&DAT_004a4df8 + iVar3 * 4) = 1;
    *(undefined4 *)(&DAT_004a8910 + iVar3 * 4) = 0;
    *(undefined4 *)(iVar3 * 4 + 0x4a6848) = 0;
    *(undefined4 *)(&DAT_004a4968 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004a41f0 + iVar3 * 4) = uVar1;
    *(undefined4 *)(&DAT_004a46a8 + iVar3 * 4) = 1;
    *(undefined4 *)(iVar3 * 4 + 0x4abf98) = 0;
  }
  if (iVar5 == 0x4a) {
    *(undefined4 *)(iVar3 * 4 + 0x4abf98) = 1;
    *(undefined4 *)(&DAT_004a8910 + iVar3 * 4) = 0;
    *(undefined4 *)(iVar3 * 4 + 0x4a6848) = 0;
    *(undefined4 *)(&DAT_004a4968 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004a4df8 + iVar3 * 4) = 0;
  }
  if (iVar5 == 0x48) {
    if (*(int *)(&DAT_004a7bc8 + iVar3 * 4) < 0x5a) {
      *(undefined4 *)(iVar3 * 4 + 0x4a6848) = 2;
    }
    else {
      *(undefined4 *)(iVar3 * 4 + 0x4a6848) = 3;
    }
    *(undefined4 *)(&DAT_004a8910 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004a4968 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004a4df8 + iVar3 * 4) = 0;
    *(undefined4 *)(iVar3 * 4 + 0x4abf98) = 0;
  }
  if ((iVar5 == 0x44) && (0 < DAT_004ac8f8)) {
    *(undefined4 *)(iVar3 * 4 + 0x4a6848) = 1;
    *(undefined4 *)(&DAT_004a8910 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004a4968 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004a4df8 + iVar3 * 4) = 0;
    *(undefined4 *)(iVar3 * 4 + 0x4abf98) = 0;
  }
  iVar4 = DAT_004ac980;
  if ((iVar5 == 0xbb) && (DAT_004ac980 == 0)) {
    if (DAT_004ac974 == 1) {
      DAT_004ac8fc = 0;
      DAT_004ac94c = DAT_004ac94c + 1;
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
      iVar4 = DAT_004ac980;
      iVar3 = DAT_00491140;
      iVar5 = DAT_004a60a4;
    }
    else if (0 < *(int *)(&DAT_004a8910 + iVar3 * 4)) {
      *(undefined4 *)(&DAT_004ac1e8 + iVar3 * 4) = 5;
      *(undefined4 *)(&DAT_004a8910 + iVar3 * 4) = 1;
      *(undefined4 *)(&DAT_004a4968 + iVar3 * 4) = 0;
      *(undefined4 *)(&DAT_004a4df8 + iVar3 * 4) = 0;
      *(undefined4 *)(iVar3 * 4 + 0x4abf98) = 0;
    }
  }
  if ((((iVar5 == 0xbb) && (100 < iVar4)) && (iVar4 < 0x6e)) &&
     ((DAT_00491164 == 0 || (iVar4 < 0x66)))) {
    DAT_004a6774 = 0;
    DAT_004ac980 = DAT_004ac980 + 1;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    iVar4 = DAT_004ac980;
    iVar3 = DAT_00491140;
    iVar5 = DAT_004a60a4;
  }
  if (((iVar5 == 0xbd) && (0x65 < iVar4)) && (iVar4 < 0x6f)) {
    DAT_004a6774 = 0;
    DAT_004ac980 = DAT_004ac980 + -1;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    iVar4 = DAT_004ac980;
    iVar3 = DAT_00491140;
    iVar5 = DAT_004a60a4;
  }
  if ((((iVar5 == 0xbb) && (500 < iVar4)) && (iVar4 < 0x202)) &&
     ((DAT_00491164 == 0 || (iVar4 < 0x1f6)))) {
    DAT_004a6774 = 0;
    DAT_004ac980 = DAT_004ac980 + 1;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    iVar4 = DAT_004ac980;
    iVar3 = DAT_00491140;
    iVar5 = DAT_004a60a4;
  }
  if (((iVar5 == 0xbd) && (0x1f5 < iVar4)) && (iVar4 < 0x203)) {
    DAT_004a6774 = 0;
    DAT_004ac980 = DAT_004ac980 + -1;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    iVar4 = DAT_004ac980;
    iVar3 = DAT_00491140;
    iVar5 = DAT_004a60a4;
  }
  if (((iVar5 == 0xbb) && (600 < iVar4)) && (iVar4 < 0x25c)) {
    DAT_004a6774 = 0;
    DAT_004ac980 = DAT_004ac980 + 1;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    iVar4 = DAT_004ac980;
    iVar3 = DAT_00491140;
    iVar5 = DAT_004a60a4;
  }
  if (iVar5 == 0xbd) {
    if ((0x259 < iVar4) && (iVar4 < 0x25d)) {
      DAT_004a6774 = 0;
      DAT_004ac980 = DAT_004ac980 + -1;
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
      iVar4 = DAT_004ac980;
      iVar3 = DAT_00491140;
      iVar5 = DAT_004a60a4;
    }
    if (((iVar5 == 0xbd) && (iVar4 == 0)) && (0 < *(int *)(&DAT_004a8910 + iVar3 * 4))) {
      *(undefined4 *)(&DAT_004ac1e8 + iVar3 * 4) = 0xfffffffb;
      *(undefined4 *)(&DAT_004a8910 + iVar3 * 4) = 1;
      *(undefined4 *)(&DAT_004a4968 + iVar3 * 4) = 0;
      *(undefined4 *)(&DAT_004a4df8 + iVar3 * 4) = 0;
      *(undefined4 *)(iVar3 * 4 + 0x4abf98) = 0;
    }
  }
  if (iVar5 == 0x53) {
    if (0 < DAT_004ac8f8) {
      *(undefined4 *)(&DAT_004a85d0 + iVar3 * 4) = 0x5a;
    }
    if (DAT_004ac8f8 == 0) {
      DAT_004ac9a4 = DAT_004ac9a4 + 1;
    }
  }
  if (1 < DAT_004ac9a4) {
    DAT_004ac9a4 = 0;
  }
  if (iVar5 == 0x41) {
    if (iVar4 == 0) {
      *(undefined4 *)(&DAT_004a85d0 + iVar3 * 4) = 0xffffffff;
    }
    if (0 < iVar4) {
      DAT_004a6774 = DAT_004a6774 + 1;
      if (DAT_00491184 < DAT_004a6774) {
        DAT_004a6774 = 0;
      }
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
      DAT_004ac8fc = 1;
      iVar3 = DAT_00491140;
      iVar5 = DAT_004a60a4;
    }
  }
  if ((iVar5 == 0x49) &&
     (iVar4 = *(int *)(&DAT_004a85d0 + iVar3 * 4),
     *(int *)(&DAT_004a85d0 + iVar3 * 4) = iVar4 + -0x14, iVar4 + -0x14 < 0)) {
    *(undefined4 *)(&DAT_004a85d0 + iVar3 * 4) = 0xffffffff;
  }
  if ((iVar5 == 0x4f) &&
     (*(int *)(&DAT_004a85d0 + iVar3 * 4) = *(int *)(&DAT_004a85d0 + iVar3 * 4) + 0x14,
     0x5a < *(int *)(&DAT_004a85d0 + iVar3 * 4))) {
    *(undefined4 *)(&DAT_004a85d0 + iVar3 * 4) = 0x5a;
  }
  if ((iVar5 == 0x45) &&
     (iVar4 = *(int *)(&DAT_004a7768 + iVar3 * 4), *(int *)(&DAT_004a7768 + iVar3 * 4) = iVar4 + 1,
     3 < iVar4 + 1)) {
    *(undefined4 *)(&DAT_004a7768 + iVar3 * 4) = 1;
  }
  if (iVar5 == 0x70) {
    *(undefined4 *)(&DAT_004a7768 + iVar3 * 4) = 1;
  }
  if (iVar5 == 0x71) {
    *(undefined4 *)(&DAT_004a7768 + iVar3 * 4) = 2;
  }
  if (iVar5 == 0x72) {
    *(undefined4 *)(&DAT_004a7768 + iVar3 * 4) = 3;
  }
  if ((((iVar5 == 0x50) && (iVar3 == 1)) && (1 < DAT_00491188)) &&
     ((DAT_00491188 != 9 && (DAT_004a4388 = DAT_004a4388 + 1, 1 < DAT_004a4388)))) {
    DAT_004a4388 = 0;
  }
  if (((iVar5 == 0x50) && (iVar3 == 2)) &&
     ((1 < DAT_00491188 &&
      ((DAT_00491188 != 9 && (DAT_004a438c = DAT_004a438c + 1, 1 < DAT_004a438c)))))) {
    DAT_004a438c = 0;
  }
  if ((iVar5 == 0x4c) && (DAT_004ac9d0 = DAT_004ac9d0 + 1, 1 < DAT_004ac9d0)) {
    DAT_004ac9d0 = 0;
  }
  if ((iVar5 == 0x30) &&
     (iVar4 = *(int *)(iVar3 * 4 + 0x4aae20) + 1, *(int *)(iVar3 * 4 + 0x4aae20) = iVar4, 1 < iVar4)
     ) {
    *(undefined4 *)(iVar3 * 4 + 0x4aae20) = 0;
  }
  if (iVar5 == 0x31) {
    *(undefined4 *)(&DAT_004a4e88 + iVar3 * 4) = 1;
    *(undefined4 *)(iVar3 * 4 + 0x4aae20) = 0;
  }
  if (iVar5 == 0x32) {
    *(undefined4 *)(&DAT_004a4e88 + iVar3 * 4) = 2;
    *(undefined4 *)(iVar3 * 4 + 0x4aae20) = 0;
  }
  if (iVar5 == 0x33) {
    *(undefined4 *)(&DAT_004a4e88 + iVar3 * 4) = 3;
    *(undefined4 *)(iVar3 * 4 + 0x4aae20) = 0;
  }
  if (((iVar5 == 0x34) && (iVar3 == 1)) && (DAT_004ac9b4 == 0)) {
    DAT_004ac9c8 = DAT_004ac9c8 + 1;
    if (1 < DAT_004ac9c8) {
      DAT_004ac9c8 = 0;
    }
    DAT_004ac8fc = 0;
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,0);
    iVar3 = DAT_00491140;
    iVar5 = DAT_004a60a4;
  }
  if ((iVar5 == 0x37) || (iVar5 == 0x24)) {
    *(undefined4 *)(&DAT_004a9440 + iVar3 * 4) = 0xffffffff;
    *(undefined4 *)(&DAT_004a4608 + iVar3 * 4) = 0;
  }
  if ((iVar5 == 0x35) || (iVar5 == 0xc)) {
    *(undefined4 *)(&DAT_004a9440 + iVar3 * 4) = 1;
    *(undefined4 *)(&DAT_004a4608 + iVar3 * 4) = 0;
  }
  if (iVar5 == 0x39) {
    *(undefined4 *)(&DAT_004a9440 + iVar3 * 4) = 100;
    DAT_004aa97c = 0;
    *(undefined4 *)(&DAT_004a4608 + iVar3 * 4) = 0;
  }
  if (iVar5 == 0x26) {
    *(undefined4 *)(&DAT_004a4608 + iVar3 * 4) = 0;
    *(undefined4 *)(&DAT_004a9440 + iVar3 * 4) = 0;
  }
  if (iVar5 == 0x28) {
    *(undefined4 *)(&DAT_004a4608 + iVar3 * 4) = 0xb4;
    *(undefined4 *)(&DAT_004a9440 + iVar3 * 4) = 0;
  }
  if (iVar5 == 0x27) {
    iVar4 = *(int *)(&DAT_004a4608 + iVar3 * 4);
    *(int *)(&DAT_004a4608 + iVar3 * 4) = iVar4 + -0x1e;
    if (iVar4 + -0x1e < -0x168) {
      *(undefined4 *)(&DAT_004a4608 + iVar3 * 4) = 0;
    }
    *(undefined4 *)(&DAT_004a9440 + iVar3 * 4) = 0;
  }
  if (iVar5 == 0x25) {
    iVar5 = *(int *)(&DAT_004a4608 + iVar3 * 4);
    *(int *)(&DAT_004a4608 + iVar3 * 4) = iVar5 + 0x1e;
    if (0x168 < iVar5 + 0x1e) {
      *(undefined4 *)(&DAT_004a4608 + iVar3 * 4) = 0;
    }
    *(undefined4 *)(&DAT_004a9440 + iVar3 * 4) = 0;
  }
  FUN_00468021(this);
  return;
}

