
LPCSTR __thiscall FUN_0046c52a(void *this,LPCSTR param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  HANDLE pvVar3;
  undefined4 uVar4;
  LPCSTR pCVar5;
  uint uVar6;
  DWORD DVar7;
  LPCSTR dwShareMode;
  CHAR local_114 [260];
  _SECURITY_ATTRIBUTES local_10;
  
  uVar1 = param_2;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 4) = 0xffffffff;
  uVar6 = param_2 & 0xffff7fff;
  FUN_0046be50((int *)((int)this + 0xc));
  FUN_0046cc20();
  FUN_0046c00d((int *)((int)this + 0xc),local_114);
  uVar2 = param_2 & 3;
  if (uVar2 == 0) {
    param_2 = 0x80000000;
  }
  else if (uVar2 == 1) {
    param_2 = 0x40000000;
  }
  else if (uVar2 == 2) {
    param_2 = 0xc0000000;
  }
  uVar2 = uVar1 & 0x70;
  pCVar5 = (LPCSTR)0x1;
  if ((uVar2 == 0) || (uVar2 == 0x10)) {
    dwShareMode = (LPCSTR)0x0;
  }
  else {
    dwShareMode = pCVar5;
    if (uVar2 != 0x20) {
      if (uVar2 == 0x30) {
        dwShareMode = (LPCSTR)0x2;
      }
      else {
        dwShareMode = param_1;
        if (uVar2 == 0x40) {
          dwShareMode = (LPCSTR)0x3;
        }
      }
    }
  }
  local_10.nLength = 0xc;
  local_10.bInheritHandle = ~uVar6 >> 7 & 1;
  local_10.lpSecurityDescriptor = (LPVOID)0x0;
  if ((uVar1 & 0x1000) == 0) {
    DVar7 = 3;
  }
  else {
    DVar7 = (-(uint)((uVar1 & 0x2000) != 0) & 2) + 2;
  }
  pvVar3 = CreateFileA(param_1,param_2,(DWORD)dwShareMode,&local_10,DVar7,0x80,(HANDLE)0x0);
  if (pvVar3 == (HANDLE)0xffffffff) {
    if (param_3 != 0) {
      DVar7 = GetLastError();
      *(DWORD *)(param_3 + 0xc) = DVar7;
      uVar4 = FUN_0046e228(DVar7);
      *(undefined4 *)(param_3 + 8) = uVar4;
      FUN_0046c00d((void *)(param_3 + 0x10),param_1);
    }
    pCVar5 = (LPCSTR)0x0;
  }
  else {
    *(HANDLE *)((int)this + 4) = pvVar3;
    *(undefined4 *)((int)this + 8) = 1;
  }
  return pCVar5;
}

