
void FUN_0046d3a9(short param_1)

{
  short sVar1;
  HANDLE h;
  int iVar2;
  HDC hdc;
  char *pcVar3;
  int local_44 [7];
  CHAR local_28 [32];
  void *local_8;
  
  sVar1 = 10;
  pcVar3 = "System";
  h = GetStockObject(0x11);
  if (h == (HGDIOBJ)0x0) {
    h = GetStockObject(0xd);
    if (h == (HGDIOBJ)0x0) goto LAB_0046d41d;
  }
  iVar2 = GetObjectA(h,0x3c,local_44);
  if (iVar2 != 0) {
    pcVar3 = local_28;
    hdc = GetDC((HWND)0x0);
    if (local_44[0] < 0) {
      local_44[0] = -local_44[0];
    }
    iVar2 = GetDeviceCaps(hdc,0x5a);
    iVar2 = MulDiv(local_44[0],0x48,iVar2);
    sVar1 = (short)iVar2;
    ReleaseDC((HWND)0x0,hdc);
  }
LAB_0046d41d:
  if (param_1 == 0) {
    param_1 = sVar1;
  }
  FUN_0046d292(local_8,pcVar3,param_1);
  return;
}

