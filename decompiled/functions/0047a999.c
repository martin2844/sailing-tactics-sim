
void __thiscall FUN_0047a999(void *this,LPCSTR param_1)

{
  int iVar1;
  
  iVar1 = lstrcmpA(param_1,"pt");
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x10) = 3;
  }
  else {
    iVar1 = lstrcmpA(param_1,"p");
    if (iVar1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 2;
    }
    else {
      iVar1 = lstrcmpiA(param_1,"Unregister");
      if ((iVar1 != 0) && (iVar1 = lstrcmpiA(param_1,"Unregserver"), iVar1 != 0)) {
        iVar1 = lstrcmpA(param_1,"dde");
        if (iVar1 == 0) {
          FUN_00478729(0);
          *(undefined4 *)((int)this + 0x10) = 4;
          return;
        }
        iVar1 = lstrcmpiA(param_1,"Embedding");
        if (iVar1 == 0) {
          FUN_00478729(0);
          *(undefined4 *)((int)this + 8) = 1;
        }
        else {
          iVar1 = lstrcmpiA(param_1,"Automation");
          if (iVar1 != 0) {
            return;
          }
          FUN_00478729(0);
          *(undefined4 *)((int)this + 0xc) = 1;
        }
        *(undefined4 *)((int)this + 4) = 0;
        return;
      }
      *(undefined4 *)((int)this + 0x10) = 5;
    }
  }
  return;
}

