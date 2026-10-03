
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */

void FUN_004313a0(void)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_4;
  
  iVar2 = DAT_004ab9d8;
  local_4 = 2;
  if (DAT_0049118c != 2) {
    local_4 = DAT_00491140;
  }
  if (0 < local_4) {
    iVar6 = 0;
    iVar5 = 0x97;
    iVar7 = 0;
    do {
      dVar1 = *(double *)((int)&DAT_004a4ae8 + iVar6);
      *(int *)((int)&DAT_004a9c68 + iVar7) = (int)(longlong)*(double *)((int)&DAT_004a49f0 + iVar6);
      *(int *)((int)&DAT_004ab400 + iVar7) = (int)(longlong)dVar1;
      if (1 < iVar2) {
        iVar4 = iVar2 + -1;
        iVar3 = (iVar2 + iVar5) * 4;
        do {
          *(undefined4 *)((int)&DAT_004a9a08 + iVar3) = *(undefined4 *)(&DAT_004a9a04 + iVar3);
          *(undefined4 *)((int)&DAT_004ab1a0 + iVar3) = *(undefined4 *)((int)&DAT_004ab19c + iVar3);
          iVar3 = iVar3 + -4;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      iVar6 = iVar6 + 8;
      iVar7 = iVar7 + 0x25c;
      iVar5 = iVar5 + 0x97;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}

