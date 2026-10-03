
void __thiscall FUN_004bf079(int param_1,LPCSTR param_2)

{
  int iVar1;
  
  iVar1 = lstrcmpA(param_2,"pt");
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x10) = 3;
  }
  else {
    iVar1 = lstrcmpA(param_2,"p");
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x10) = 2;
    }
    else {
      iVar1 = lstrcmpiA(param_2,"Unregister");
      if ((iVar1 != 0) && (iVar1 = lstrcmpiA(param_2,"Unregserver"), iVar1 != 0)) {
        iVar1 = lstrcmpA(param_2,"dde");
        if (iVar1 == 0) {
          FUN_004bce09(0);
          *(undefined4 *)(param_1 + 0x10) = 4;
          return;
        }
        iVar1 = lstrcmpiA(param_2,"Embedding");
        if (iVar1 == 0) {
          FUN_004bce09(0);
          *(undefined4 *)(param_1 + 8) = 1;
        }
        else {
          iVar1 = lstrcmpiA(param_2,"Automation");
          if (iVar1 != 0) {
            return;
          }
          FUN_004bce09(0);
          *(undefined4 *)(param_1 + 0xc) = 1;
        }
        *(undefined4 *)(param_1 + 4) = 0;
        return;
      }
      *(undefined4 *)(param_1 + 0x10) = 5;
    }
  }
  return;
}

