
void FUN_00467d48(void)

{
  if ((DAT_004aca58 & 8) == 0) {
    DAT_004aca58 = DAT_004aca58 | 8;
    CWnd::~CWnd((CWnd *)&DAT_004ae2e0);
    return;
  }
  return;
}

