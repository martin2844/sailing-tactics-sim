
int * FUN_0046c499(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  HANDLE hTargetProcessHandle;
  HANDLE hSourceProcessHandle;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  HANDLE hSourceHandle;
  LPHANDLE lpTargetHandle;
  DWORD DVar4;
  BOOL BVar5;
  DWORD dwOptions;
  
  FUN_00457418();
  iVar2 = FUN_0046b505(0x10);
  *(int *)(unaff_EBP + -0x14) = iVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = FUN_0046c407();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  dwOptions = 2;
  BVar5 = 0;
  lpTargetHandle = (LPHANDLE)(unaff_EBP + -0x10);
  DVar4 = 0;
  hTargetProcessHandle = GetCurrentProcess();
  hSourceHandle = *(HANDLE *)(extraout_ECX + 4);
  hSourceProcessHandle = GetCurrentProcess();
  BVar5 = DuplicateHandle(hSourceProcessHandle,hSourceHandle,hTargetProcessHandle,lpTargetHandle,
                          DVar4,BVar5,dwOptions);
  if (BVar5 == 0) {
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 4))(1);
    }
    DVar4 = GetLastError();
    FUN_0046e0e6(DVar4);
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  piVar3[1] = *(int *)(unaff_EBP + -0x10);
  piVar3[2] = *(int *)(extraout_ECX + 8);
  *unaff_FS_OFFSET = uVar1;
  return piVar3;
}

