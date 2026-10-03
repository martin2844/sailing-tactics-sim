
void FUN_0046ccf9(LPCSTR param_1,void *param_2)

{
  byte *lpString1;
  byte *pbVar1;
  byte bVar2;
  
  lpString1 = (byte *)FUN_0046c276(param_2,0x104);
  _memset(lpString1,0,0x104);
  lstrcpynA((LPSTR)lpString1,param_1,0x104);
  bVar2 = *lpString1;
  pbVar1 = lpString1;
  while ((bVar2 != 0 &&
         (((bVar2 != 0x5c && (bVar2 != 0x2f)) || ((pbVar1[1] != 0x5c && (pbVar1[1] != 0x2f))))))) {
    pbVar1 = FUN_00457e60(pbVar1);
    bVar2 = *pbVar1;
  }
  if (*pbVar1 == 0) {
    bVar2 = *lpString1;
    while (((bVar2 != 0 && (bVar2 != 0x5c)) && (bVar2 != 0x2f))) {
      lpString1 = FUN_00457e60(lpString1);
      bVar2 = *lpString1;
    }
  }
  else {
    for (lpString1 = pbVar1 + 2;
        ((bVar2 = *lpString1, bVar2 != 0 && (bVar2 != 0x5c)) && (bVar2 != 0x2f));
        lpString1 = FUN_00457e60(lpString1)) {
    }
    if (*lpString1 == 0) goto LAB_0046cd7a;
    do {
      lpString1 = FUN_00457e60(lpString1);
LAB_0046cd7a:
      bVar2 = *lpString1;
    } while (((bVar2 != 0) && (bVar2 != 0x5c)) && (bVar2 != 0x2f));
  }
  if (*lpString1 != 0) {
    lpString1[1] = 0;
  }
  FUN_0046c2c5(param_2,-1);
  return;
}

