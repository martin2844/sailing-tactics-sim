
void __thiscall FUN_004775ed(void *this,HDROP param_1)

{
  int iVar1;
  UINT iFile;
  CHAR local_110 [260];
  code *local_c;
  UINT local_8;
  
  SetActiveWindow(*(HWND *)((int)this + 0x1c));
  FUN_004680cc();
  iFile = 0;
  local_8 = DragQueryFileA(param_1,0xffffffff,(LPSTR)0x0,0);
  iVar1 = FUN_0047b918();
  if (local_8 != 0) {
    local_c = *(code **)(**(int **)(iVar1 + 4) + 0x84);
    do {
      DragQueryFileA(param_1,iFile,local_110,0x104);
      (*local_c)(local_110);
      iFile = iFile + 1;
    } while (iFile < local_8);
  }
  DragFinish(param_1);
  return;
}

