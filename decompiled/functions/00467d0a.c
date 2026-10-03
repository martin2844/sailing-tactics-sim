
void FUN_00467d0a(void)

{
  if ((DAT_004aca58 & 4) == 0) {
    DAT_004aca58 = DAT_004aca58 | 4;
    CWnd::~CWnd((CWnd *)&DAT_004ae2a0);
    return;
  }
  return;
}

