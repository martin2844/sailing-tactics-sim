
void FUN_00467c8e(void)

{
  if ((DAT_004aca58 & 1) == 0) {
    DAT_004aca58 = DAT_004aca58 | 1;
    CWnd::~CWnd((CWnd *)&DAT_004ae260);
    return;
  }
  return;
}

