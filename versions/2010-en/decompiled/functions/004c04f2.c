
/* WARNING: Removing unreachable block (ram,0x004c0519) */

int __thiscall FUN_004c04f2(int *param_1,code *param_2)

{
  int iVar1;
  LPVOID pvVar2;
  
  if (*param_1 == 0) {
    if (DAT_00538148 == (DWORD *)0x0) {
      DAT_00538148 = (DWORD *)FUN_004c0170();
    }
    iVar1 = FUN_004c01b2();
    *param_1 = iVar1;
  }
  iVar1 = *param_1;
  pvVar2 = TlsGetValue(*DAT_00538148);
  if ((pvVar2 == (LPVOID)0x0) || (*(int *)((int)pvVar2 + 8) <= iVar1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*(int *)((int)pvVar2 + 0xc) + iVar1 * 4);
  }
  if (iVar1 == 0) {
    iVar1 = (*param_2)();
    FUN_004c0321(*param_1,iVar1);
  }
  return iVar1;
}

