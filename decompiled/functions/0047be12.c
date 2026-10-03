
/* WARNING: Removing unreachable block (ram,0x0047be39) */

int __thiscall FUN_0047be12(void *this,undefined *param_1)

{
  int iVar1;
  LPVOID pvVar2;
  
  if (*(int *)this == 0) {
    if (DAT_004ae5f0 == (DWORD *)0x0) {
      DAT_004ae5f0 = FUN_0047ba90((DWORD *)&DAT_004ae5f8);
    }
    iVar1 = FUN_0047bad2((int)DAT_004ae5f0);
    *(int *)this = iVar1;
  }
  iVar1 = *(int *)this;
  pvVar2 = TlsGetValue(*DAT_004ae5f0);
  if ((pvVar2 == (LPVOID)0x0) || (*(int *)((int)pvVar2 + 8) <= iVar1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*(int *)((int)pvVar2 + 0xc) + iVar1 * 4);
  }
  if (iVar1 == 0) {
    iVar1 = (*(code *)param_1)();
    FUN_0047bc41(DAT_004ae5f0,*(int *)this,iVar1);
  }
  return iVar1;
}

