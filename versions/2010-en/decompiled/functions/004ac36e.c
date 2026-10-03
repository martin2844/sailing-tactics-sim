
void FUN_004ac36e(void)

{
  if ((DAT_005365b0 & 1) == 0) {
    DAT_005365b0 = DAT_005365b0 | 1;
    CWnd::~CWnd((CWnd *)&DAT_00537db8);
    return;
  }
  return;
}

