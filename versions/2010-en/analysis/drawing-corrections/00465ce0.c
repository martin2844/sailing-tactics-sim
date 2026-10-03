
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00465ce0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  HDC hdc;
  HGDIOBJ h;
  
  (**(code **)(*param_1 + 0x2c))(param_1,8);
  if (DAT_005363e4 == 0) {
    if (DAT_004fb244 == (HGDIOBJ)0x0) goto LAB_00465d37;
    hdc = (HDC)param_1[1];
    h = DAT_004fb244;
  }
  else {
    if (DAT_004fe07c == (HGDIOBJ)0x0) goto LAB_00465d37;
    hdc = (HDC)param_1[1];
    h = DAT_004fe07c;
  }
  SelectObject(hdc,h);
LAB_00465d37:
  puVar4 = &DAT_0051230c;
  puVar6 = &DAT_004fe34c;
  iVar5 = 0;
  iVar3 = DAT_004fe2a8;
  do {
    iVar1 = *(int *)((int)&DAT_004f8028 + iVar5);
    if (((((iVar1 <= DAT_004fe624) || (*(int *)((int)&DAT_004f802c + iVar5) <= DAT_004fe624)) &&
         ((-1 < iVar1 || (-1 < *(int *)((int)&DAT_004f802c + iVar5))))) &&
        ((iVar2 = *(int *)((int)&DAT_004faa60 + iVar5), -1 < iVar2 ||
         (-1 < *(int *)((int)&DAT_004faa64 + iVar5))))) &&
       ((iVar2 <= iVar3 || (*(int *)((int)&DAT_004faa64 + iVar5) <= iVar3)))) {
      _DAT_004f6e28 = puVar6[-1];
      _DAT_004f6e38 = *(undefined4 *)((int)&DAT_004f802c + iVar5);
      _DAT_004f6e2c = puVar4[-1];
      _DAT_004f6e3c = *(undefined4 *)((int)&DAT_004faa64 + iVar5);
      _DAT_004f6e40 = *puVar6;
      _DAT_004f6e44 = *puVar4;
      _DAT_004f6e30 = iVar1;
      _DAT_004f6e34 = iVar2;
      Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,4);
      iVar3 = DAT_004fe2a8;
    }
    iVar5 = iVar5 + 4;
    puVar6 = puVar6 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar5 < 0x2cd);
  return;
}

