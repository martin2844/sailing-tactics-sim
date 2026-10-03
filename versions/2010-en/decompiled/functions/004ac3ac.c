
void FUN_004ac3ac(void)

{
  if ((DAT_005365b0 & 2) == 0) {
    DAT_005365b0 = DAT_005365b0 | 2;
    CWnd::~CWnd((CWnd *)&DAT_00537e78);
    return;
  }
  return;
}

