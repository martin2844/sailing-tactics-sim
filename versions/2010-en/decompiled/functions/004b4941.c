
void __thiscall FUN_004b4941(int param_1,HGDIOBJ param_2)

{
  HGDIOBJ pvVar1;
  HGDIOBJ h;
  
  pvVar1 = param_2;
  if (*(HDC *)(param_1 + 4) != *(HDC *)(param_1 + 8)) {
    if (param_2 == (HGDIOBJ)0x0) {
      h = (HGDIOBJ)0x0;
    }
    else {
      h = *(HGDIOBJ *)((int)param_2 + 4);
    }
    param_2 = SelectObject(*(HDC *)(param_1 + 4),h);
  }
  if (*(HDC *)(param_1 + 8) != (HDC)0x0) {
    if (pvVar1 == (HGDIOBJ)0x0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = *(HGDIOBJ *)((int)pvVar1 + 4);
    }
    param_2 = SelectObject(*(HDC *)(param_1 + 8),pvVar1);
  }
  FUN_004b50f7(param_2);
  return;
}

