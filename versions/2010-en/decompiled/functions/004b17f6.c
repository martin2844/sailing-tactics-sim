
void FUN_004b17f6(int param_1)

{
  short *psVar1;
  short sVar2;
  
  if (*(short *)(param_1 + 2) == -1) {
    psVar1 = (short *)(param_1 + 0x1a);
  }
  else {
    psVar1 = (short *)(param_1 + 0x12);
  }
  sVar2 = *psVar1;
  if (sVar2 == -1) {
    psVar1 = psVar1 + 2;
  }
  else {
    while (psVar1 = psVar1 + 1, sVar2 != 0) {
      sVar2 = *psVar1;
    }
  }
  sVar2 = *psVar1;
  if (sVar2 == -1) {
    psVar1 = psVar1 + 2;
  }
  else {
    while (psVar1 = psVar1 + 1, sVar2 != 0) {
      sVar2 = *psVar1;
    }
  }
  do {
    sVar2 = *psVar1;
    psVar1 = psVar1 + 1;
  } while (sVar2 != 0);
  return;
}

