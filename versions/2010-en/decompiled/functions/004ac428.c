
void FUN_004ac428(void)

{
  if ((DAT_005365b0 & 8) == 0) {
    DAT_005365b0 = DAT_005365b0 | 8;
    CWnd::~CWnd((CWnd *)&DAT_00537e38);
    return;
  }
  return;
}

