
void FUN_004ac3ea(void)

{
  if ((DAT_005365b0 & 4) == 0) {
    DAT_005365b0 = DAT_005365b0 | 4;
    CWnd::~CWnd((CWnd *)&DAT_00537df8);
    return;
  }
  return;
}

