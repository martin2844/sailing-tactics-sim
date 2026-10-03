
undefined4 FUN_0046e66a(LPCSTR param_1,int *param_2)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  HANDLE hFindFile;
  int *piVar4;
  _WIN32_FIND_DATAA local_144;
  
  piVar2 = param_2;
  puVar1 = (undefined1 *)((int)param_2 + 0x12);
  iVar3 = FUN_0046cc20();
  if (iVar3 == 0) {
    *puVar1 = 0;
  }
  else {
    hFindFile = FindFirstFileA(param_1,&local_144);
    if (hFindFile != (HANDLE)0xffffffff) {
      FindClose(hFindFile);
      *(byte *)(piVar2 + 4) = (byte)local_144.dwFileAttributes & 0x7f;
      piVar2[3] = local_144.nFileSizeLow;
      piVar4 = FUN_004667f4(&param_1,&local_144.ftCreationTime,0xffffffff);
      *piVar2 = *piVar4;
      piVar4 = FUN_004667f4(&param_1,&local_144.ftLastAccessTime,0xffffffff);
      piVar2[2] = *piVar4;
      piVar4 = FUN_004667f4(&param_1,&local_144.ftLastWriteTime,0xffffffff);
      iVar3 = *piVar4;
      piVar2[1] = iVar3;
      if (*piVar2 == 0) {
        *piVar2 = iVar3;
      }
      if (piVar2[2] == 0) {
        piVar2[2] = piVar2[1];
      }
      return 1;
    }
  }
  return 0;
}

