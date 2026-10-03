
undefined4 FUN_004b2d4a(LPCSTR param_1,int *param_2)

{
  int iVar1;
  HANDLE hFindFile;
  int *piVar2;
  _WIN32_FIND_DATAA local_144;
  
  iVar1 = FUN_004b1300((undefined1 *)((int)param_2 + 0x12),param_1);
  if (iVar1 == 0) {
    *(undefined1 *)((int)param_2 + 0x12) = 0;
  }
  else {
    hFindFile = FindFirstFileA(param_1,&local_144);
    if (hFindFile != (HANDLE)0xffffffff) {
      FindClose(hFindFile);
      *(byte *)(param_2 + 4) = (byte)local_144.dwFileAttributes & 0x7f;
      param_2[3] = local_144.nFileSizeLow;
      piVar2 = (int *)FUN_004aaed4(&local_144.ftCreationTime,0xffffffff);
      *param_2 = *piVar2;
      piVar2 = (int *)FUN_004aaed4(&local_144.ftLastAccessTime,0xffffffff);
      param_2[2] = *piVar2;
      piVar2 = (int *)FUN_004aaed4(&local_144.ftLastWriteTime,0xffffffff);
      iVar1 = *piVar2;
      param_2[1] = iVar1;
      if (*param_2 == 0) {
        *param_2 = iVar1;
      }
      if (param_2[2] == 0) {
        param_2[2] = param_2[1];
      }
      return 1;
    }
  }
  return 0;
}

