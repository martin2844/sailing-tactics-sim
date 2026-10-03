
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042b7f0(void)

{
  int iVar1;
  uint uVar2;
  
  FUN_0042ba00();
  iVar1 = DAT_004aa97c;
  if (DAT_004aa97c < DAT_004a4414) {
    iVar1 = DAT_004a4414;
  }
  if ((iVar1 < DAT_004a72d0 / 2) || (DAT_004a4e8c == 3)) {
    iVar1 = DAT_004a763c / 9;
    uVar2 = DAT_004a774c - DAT_004a67b0 >> 0x1f;
    if (((int)((DAT_004a774c - DAT_004a67b0 ^ uVar2) - uVar2) < iVar1) &&
       ((uVar2 = DAT_004aa97c - DAT_004a6840 >> 0x1f,
        (int)((DAT_004aa97c - DAT_004a6840 ^ uVar2) - uVar2) < iVar1 && (DAT_004ac8fc == 0)))) {
      _DAT_004a78e8 = _DAT_004a78e8 - _DAT_00484d58;
      DAT_004a8914 = 0;
      DAT_004a774c = 0;
      DAT_004aa97c = 0;
      DAT_004a4dfc = 0;
      DAT_004abf9c = 0;
      DAT_004a496c = 0;
      DAT_004a684c = 0;
    }
    uVar2 = DAT_004ab188 - DAT_004a67b0 >> 0x1f;
    if ((((int)((DAT_004ab188 - DAT_004a67b0 ^ uVar2) - uVar2) < iVar1) &&
        (uVar2 = DAT_004a4414 - DAT_004a6840 >> 0x1f,
        (int)((DAT_004a4414 - DAT_004a6840 ^ uVar2) - uVar2) < iVar1)) && (DAT_004ac8fc == 0)) {
      _DAT_004a78e8 = _DAT_004a78e8 - _DAT_00484d60;
      DAT_004a8914 = 0;
      DAT_004ab188 = 0;
      DAT_004a4414 = 0;
      DAT_004a4dfc = 0;
      DAT_004abf9c = 0;
      DAT_004a496c = 0;
      DAT_004a684c = 0;
    }
  }
  if (_DAT_00485098 < _DAT_004a78e8) {
    _DAT_004a78e8 = _DAT_004a78e8 - _DAT_00485098;
  }
  if (_DAT_004a78e8 < _DAT_00484e18) {
    _DAT_004a78e8 = _DAT_004a78e8 - _DAT_004850a8;
  }
  DAT_004ac01c = (int)(longlong)_DAT_004a78e8;
  if ((DAT_004a4dfc == 1) && (DAT_004aa734 != DAT_004abe74)) {
    DAT_004a8914 = 1;
    DAT_004a4dfc = 0;
    DAT_004a496c = 0;
    DAT_004a7044 = 0;
    DAT_004a684c = 0;
    _DAT_004a3a1c = DAT_004a5b80;
  }
  if ((DAT_004a4dfc == -1) && (DAT_004a7bcc < 0x46)) {
    DAT_004a8914 = 1;
    DAT_004a4dfc = 0;
    DAT_004a496c = 0;
    DAT_004a7044 = 0;
    DAT_004a684c = 0;
  }
  DAT_004ac01c = FUN_00413cb0(DAT_004ac01c);
  return;
}

