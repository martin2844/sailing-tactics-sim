
void FUN_00478763(void)

{
  byte bVar1;
  undefined2 *puVar2;
  HBITMAP hbm;
  int iVar3;
  undefined2 local_14 [8];
  
  FUN_0047c1af(8);
  if (DAT_004ae8bc == (HBRUSH)0x0) {
    iVar3 = 0;
    puVar2 = local_14;
    do {
      bVar1 = (byte)iVar3;
      iVar3 = iVar3 + 1;
      *puVar2 = (short)(0x5555 << (bVar1 & 1));
      puVar2 = puVar2 + 1;
    } while (iVar3 < 8);
    hbm = CreateBitmap(8,8,1,1,local_14);
    if (hbm != (HBITMAP)0x0) {
      DAT_004ae8bc = CreatePatternBrush(hbm);
      DeleteObject(hbm);
    }
  }
  FUN_0047c21f(8);
  FUN_00470a17();
  return;
}

