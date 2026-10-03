
void FUN_00467ccc(void)

{
  if ((DAT_004aca58 & 2) == 0) {
    DAT_004aca58 = DAT_004aca58 | 2;
    CWnd::~CWnd((CWnd *)&DAT_004ae320);
    return;
  }
  return;
}

