
int __fastcall FUN_004753e8(void *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (0 < *(int *)((int)param_1 + 0x84)) {
    do {
      uVar1 = FUN_0047602d(param_1,iVar3);
      if (uVar1 != 0) {
        iVar2 = iVar2 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)((int)param_1 + 0x84));
  }
  return iVar2;
}

