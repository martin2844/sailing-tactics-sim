
undefined4 __thiscall FUN_004b2c70(int param_1,int *param_2)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  undefined4 uVar4;
  int *piVar5;
  _FILETIME local_1c;
  _FILETIME local_14;
  _FILETIME local_c;
  
  _memset(param_2,0,0x118);
  lstrcpynA((LPSTR)((int)param_2 + 0x12),*(LPCSTR *)(param_1 + 0xc),0x104);
  if (*(HANDLE *)(param_1 + 4) == (HANDLE)0xffffffff) {
LAB_004b2d40:
    uVar4 = 1;
  }
  else {
    BVar2 = GetFileTime(*(HANDLE *)(param_1 + 4),&local_c,&local_14,&local_1c);
    if (BVar2 != 0) {
      DVar3 = GetFileSize(*(HANDLE *)(param_1 + 4),(LPDWORD)0x0);
      param_2[3] = DVar3;
      if (DVar3 != 0xffffffff) {
        if (*(int *)(*(LPCSTR *)(param_1 + 0xc) + -8) == 0) {
LAB_004b2cef:
          *(undefined1 *)(param_2 + 4) = 0;
        }
        else {
          DVar3 = GetFileAttributesA(*(LPCSTR *)(param_1 + 0xc));
          if (DVar3 == 0xffffffff) goto LAB_004b2cef;
          *(char *)(param_2 + 4) = (char)DVar3;
        }
        piVar5 = (int *)FUN_004aaed4(&local_c,0xffffffff);
        *param_2 = *piVar5;
        piVar5 = (int *)FUN_004aaed4(&local_14,0xffffffff);
        param_2[2] = *piVar5;
        piVar5 = (int *)FUN_004aaed4(&local_1c,0xffffffff);
        iVar1 = *piVar5;
        param_2[1] = iVar1;
        if (*param_2 == 0) {
          *param_2 = iVar1;
        }
        if (param_2[2] == 0) {
          param_2[2] = param_2[1];
        }
        goto LAB_004b2d40;
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}

