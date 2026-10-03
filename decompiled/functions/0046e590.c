
undefined4 __thiscall FUN_0046e590(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  int *piVar6;
  _FILETIME local_1c;
  _FILETIME local_14;
  _FILETIME local_c;
  
  piVar2 = param_1;
  _memset(param_1,0,0x118);
  lstrcpynA((LPSTR)((int)piVar2 + 0x12),*(LPCSTR *)((int)this + 0xc),0x104);
  if (*(HANDLE *)((int)this + 4) == (HANDLE)0xffffffff) {
LAB_0046e660:
    uVar5 = 1;
  }
  else {
    BVar3 = GetFileTime(*(HANDLE *)((int)this + 4),&local_c,&local_14,&local_1c);
    if (BVar3 != 0) {
      DVar4 = GetFileSize(*(HANDLE *)((int)this + 4),(LPDWORD)0x0);
      piVar2[3] = DVar4;
      if (DVar4 != 0xffffffff) {
        if (*(int *)(*(LPCSTR *)((int)this + 0xc) + -8) == 0) {
LAB_0046e60f:
          *(undefined1 *)(piVar2 + 4) = 0;
        }
        else {
          DVar4 = GetFileAttributesA(*(LPCSTR *)((int)this + 0xc));
          if (DVar4 == 0xffffffff) goto LAB_0046e60f;
          *(char *)(piVar2 + 4) = (char)DVar4;
        }
        piVar6 = FUN_004667f4(&param_1,&local_c,0xffffffff);
        *piVar2 = *piVar6;
        piVar6 = FUN_004667f4(&param_1,&local_14,0xffffffff);
        piVar2[2] = *piVar6;
        piVar6 = FUN_004667f4(&param_1,&local_1c,0xffffffff);
        iVar1 = *piVar6;
        piVar2[1] = iVar1;
        if (*piVar2 == 0) {
          *piVar2 = iVar1;
        }
        if (piVar2[2] == 0) {
          piVar2[2] = piVar2[1];
        }
        goto LAB_0046e660;
      }
    }
    uVar5 = 0;
  }
  return uVar5;
}

