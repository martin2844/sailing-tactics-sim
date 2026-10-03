
int __thiscall FUN_004b4994(int *original_dc,int *param_2)

{
  int *piVar1;
  int iVar2;
  HGDIOBJ pvVar3;
  
  piVar1 = param_2;
  if ((HDC)original_dc[1] != (HDC)original_dc[2]) {
    if (param_2 == (int *)0x0) {
      pvVar3 = (HGDIOBJ)0x0;
    }
    else {
      pvVar3 = (HGDIOBJ)param_2[1];
    }
    param_2 = SelectObject((HDC)original_dc[1],pvVar3);
  }
  if ((HDC)original_dc[2] != (HDC)0x0) {
    if (piVar1 == (int *)0x0) {
      pvVar3 = (HGDIOBJ)0x0;
    }
    else {
      pvVar3 = (HGDIOBJ)piVar1[1];
    }
    param_2 = SelectObject((HDC)original_dc[2],pvVar3);
  }
  iVar2 = FUN_004b50f7(param_2);
  return iVar2;
}

