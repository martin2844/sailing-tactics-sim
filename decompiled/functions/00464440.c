
bool __cdecl FUN_00464440(HWND param_1,ushort param_2,short param_3,undefined4 param_4)

{
  HANDLE pvVar1;
  int iVar2;
  LONG LVar3;
  ushort *puVar4;
  int iVar5;
  CHAR local_10 [16];
  
  pvVar1 = FUN_00462840(param_1);
  if (pvVar1 != (HANDLE)0x0) {
    return false;
  }
  iVar5 = 0;
  puVar4 = &DAT_004897dc;
  GetClassNameA(param_1,local_10,0x10);
  do {
    if ((*puVar4 & param_2) != 0) {
      iVar2 = lstrcmpA((LPCSTR)(puVar4 + -0xe),local_10);
      if (iVar2 == 0) {
        LVar3 = GetWindowLongA(param_1,-0x10);
        iVar2 = (*(code *)(&PTR_FUN_004897d8)[iVar5 * 8])
                          (param_1,LVar3,param_2,CONCAT22((short)((uint)puVar4 >> 0x10),param_3),
                           param_4);
        if (iVar2 == 1) {
          if ((param_3 == 1) && (DAT_004aff62 == 0x10)) {
            FUN_00462a50(param_1,(&DAT_004b09a0)[iVar5 * 6]);
            return true;
          }
          FUN_004628b0(param_1,(&DAT_004b09a0)[iVar5 * 6]);
        }
        return (bool)('\x01' - (iVar2 == 0));
      }
    }
    puVar4 = puVar4 + 0x10;
    iVar5 = iVar5 + 1;
    if (&UNK_0048989b < puVar4) {
      return false;
    }
  } while( true );
}

