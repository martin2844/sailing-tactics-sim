
int * FUN_004b0b79(void)

{
  int iVar1;
  int *piVar2;
  HANDLE hTargetProcessHandle;
  HANDLE hSourceProcessHandle;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  HANDLE hSourceHandle;
  LPHANDLE lpTargetHandle;
  DWORD DVar3;
  BOOL BVar4;
  DWORD dwOptions;
  undefined4 uVar5;
  
  FUN_0049bcd8();
  iVar1 = FUN_004afbe5(0x10);
  *(int *)(unaff_EBP + -0x14) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_004b0ae7(0xffffffff);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  dwOptions = 2;
  BVar4 = 0;
  lpTargetHandle = (LPHANDLE)(unaff_EBP + -0x10);
  DVar3 = 0;
  hTargetProcessHandle = GetCurrentProcess();
  hSourceHandle = *(HANDLE *)(extraout_ECX + 4);
  hSourceProcessHandle = GetCurrentProcess();
  BVar4 = DuplicateHandle(hSourceProcessHandle,hSourceHandle,hTargetProcessHandle,lpTargetHandle,
                          DVar3,BVar4,dwOptions);
  if (BVar4 == 0) {
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(1);
    }
    uVar5 = 0;
    DVar3 = GetLastError();
    FUN_004b27c6(DVar3,uVar5);
  }
  uVar5 = *(undefined4 *)(unaff_EBP + -0xc);
  piVar2[1] = *(int *)(unaff_EBP + -0x10);
  piVar2[2] = *(int *)(extraout_ECX + 8);
  *unaff_FS_OFFSET = uVar5;
  return piVar2;
}

