
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0044f630(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  HDC hdc;
  HGDIOBJ h;
  
  (**(code **)(*param_1 + 0x2c))(8);
  if (DAT_004ac92c == 0) {
    if (DAT_004a621c == (HGDIOBJ)0x0) goto LAB_0044f687;
    hdc = (HDC)param_1[1];
    h = DAT_004a621c;
  }
  else {
    if (DAT_004a70e4 == (HGDIOBJ)0x0) goto LAB_0044f687;
    hdc = (HDC)param_1[1];
    h = DAT_004a70e4;
  }
  SelectObject(hdc,h);
LAB_0044f687:
  puVar4 = &DAT_004a8b2c;
  puVar6 = &DAT_004a7364;
  iVar5 = 0;
  iVar3 = DAT_004a72d0;
  do {
    iVar1 = *(int *)((int)&DAT_004a4f90 + iVar5);
    if (((((iVar1 <= DAT_004a763c) || (*(int *)((int)&DAT_004a4f94 + iVar5) <= DAT_004a763c)) &&
         ((-1 < iVar1 || (-1 < *(int *)((int)&DAT_004a4f94 + iVar5))))) &&
        ((iVar2 = *(int *)((int)&DAT_004a5bb0 + iVar5), -1 < iVar2 ||
         (-1 < *(int *)((int)&DAT_004a5bb4 + iVar5))))) &&
       ((iVar2 <= iVar3 || (*(int *)((int)&DAT_004a5bb4 + iVar5) <= iVar3)))) {
      _DAT_004a4ca8 = puVar6[-1];
      _DAT_004a4cb8 = *(undefined4 *)((int)&DAT_004a4f94 + iVar5);
      _DAT_004a4cac = puVar4[-1];
      _DAT_004a4cbc = *(undefined4 *)((int)&DAT_004a5bb4 + iVar5);
      _DAT_004a4cc0 = *puVar6;
      _DAT_004a4cc4 = *puVar4;
      _DAT_004a4cb0 = iVar1;
      _DAT_004a4cb4 = iVar2;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004a4ca8,4);
      iVar3 = DAT_004a72d0;
    }
    iVar5 = iVar5 + 4;
    puVar6 = puVar6 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar5 < 0x2cd);
  return;
}

