
void FUN_004b1a89(int param_1)

{
  HANDLE h;
  int iVar1;
  HDC hdc;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  int local_44 [7];
  char local_28 [36];
  
  iVar2 = 10;
  pcVar3 = "System";
  h = GetStockObject(0x11);
  if (h == (HGDIOBJ)0x0) {
    h = GetStockObject(0xd);
    if (h == (HGDIOBJ)0x0) goto LAB_004b1afd;
  }
  iVar1 = GetObjectA(h,0x3c,local_44);
  if (iVar1 != 0) {
    pcVar3 = local_28;
    hdc = GetDC((HWND)0x0);
    if (local_44[0] < 0) {
      local_44[0] = -local_44[0];
    }
    iVar2 = GetDeviceCaps(hdc,0x5a);
    iVar2 = MulDiv(local_44[0],0x48,iVar2);
    ReleaseDC((HWND)0x0,hdc);
  }
LAB_004b1afd:
  bVar4 = (short)param_1 == 0;
  if (bVar4) {
    param_1 = iVar2;
  }
  FUN_004b1972(pcVar3,param_1);
  return;
}

