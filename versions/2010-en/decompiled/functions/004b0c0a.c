
LPCSTR __thiscall FUN_004b0c0a(int param_1,LPCSTR param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  HANDLE pvVar3;
  undefined4 uVar4;
  LPCSTR pCVar5;
  uint uVar6;
  DWORD DVar7;
  LPCSTR dwShareMode;
  char local_114 [260];
  _SECURITY_ATTRIBUTES local_10;
  
  uVar1 = param_3;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0xffffffff;
  uVar6 = param_3 & 0xffff7fff;
  FUN_004b0530();
  FUN_004b1300(local_114,param_2);
  FUN_004b06ed((Tact2010CString *)(param_1 + 0xc),local_114);
  uVar2 = param_3 & 3;
  if (uVar2 == 0) {
    param_3 = 0x80000000;
  }
  else if (uVar2 == 1) {
    param_3 = 0x40000000;
  }
  else if (uVar2 == 2) {
    param_3 = 0xc0000000;
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
        dwShareMode = param_2;
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
  pvVar3 = CreateFileA(param_2,param_3,(DWORD)dwShareMode,&local_10,DVar7,0x80,(HANDLE)0x0);
  if (pvVar3 == (HANDLE)0xffffffff) {
    if (param_4 != 0) {
      DVar7 = GetLastError();
      *(DWORD *)(param_4 + 0xc) = DVar7;
      uVar4 = FUN_004b2908(DVar7);
      *(undefined4 *)(param_4 + 8) = uVar4;
      FUN_004b06ed((Tact2010CString *)(param_4 + 0x10),param_2);
    }
    pCVar5 = (LPCSTR)0x0;
  }
  else {
    *(HANDLE *)(param_1 + 4) = pvVar3;
    *(undefined4 *)(param_1 + 8) = 1;
  }
  return pCVar5;
}

