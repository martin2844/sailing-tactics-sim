
void __fastcall FUN_004b0e30(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  bool bVar3;
  undefined4 uVar4;
  
  bVar3 = false;
  if (*(HANDLE *)(param_1 + 4) != (HANDLE)0xffffffff) {
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 4));
    bVar3 = BVar1 == 0;
  }
  *(undefined4 *)(param_1 + 4) = 0xffffffff;
  *(undefined4 *)(param_1 + 8) = 0;
  FUN_004b0530();
  if (bVar3) {
    uVar4 = 0;
    DVar2 = GetLastError();
    FUN_004b27c6(DVar2,uVar4);
  }
  return;
}

