
void __thiscall FUN_0047807d(void *this,LPCSTR param_1)

{
  uint uVar1;
  int iVar2;
  LPCSTR pCVar3;
  int iVar4;
  CHAR local_208 [516];
  
  uVar1 = FUN_0046ad0b((int)this);
  if ((uVar1 & 0x4000) == 0) {
    lstrcpyA(local_208,*(LPCSTR *)((int)this + 0xac));
    if (param_1 != (LPCSTR)0x0) {
      lstrcatA(local_208," - ");
      lstrcatA(local_208,param_1);
      iVar4 = *(int *)((int)this + 0x40);
      if (0 < iVar4) {
        pCVar3 = ":%d";
        iVar2 = lstrlenA(local_208);
        wsprintfA(local_208 + iVar2,pCVar3,iVar4);
      }
    }
  }
  else {
    local_208[0] = '\0';
    if (param_1 != (LPCSTR)0x0) {
      lstrcpyA(local_208,param_1);
      iVar4 = *(int *)((int)this + 0x40);
      if (0 < iVar4) {
        pCVar3 = ":%d";
        iVar2 = lstrlenA(local_208);
        wsprintfA(local_208 + iVar2,pCVar3,iVar4);
      }
      lstrcatA(local_208," - ");
    }
    lstrcatA(local_208,*(LPCSTR *)((int)this + 0xac));
  }
  FUN_00470ec5(*(HWND *)((int)this + 0x1c),local_208);
  return;
}

