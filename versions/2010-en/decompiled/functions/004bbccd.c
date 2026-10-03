
void __thiscall FUN_004bbccd(int param_1,HDROP param_2)

{
  HWND pHVar1;
  int iVar2;
  UINT iFile;
  CHAR local_110 [260];
  code *local_c;
  UINT local_8;
  
  pHVar1 = SetActiveWindow(*(HWND *)(param_1 + 0x1c));
  FUN_004ac7ac(pHVar1);
  iFile = 0;
  local_8 = DragQueryFileA(param_2,0xffffffff,(LPSTR)0x0,0);
  iVar2 = FUN_004bfff8();
  if (local_8 != 0) {
    local_c = *(code **)(**(int **)(iVar2 + 4) + 0x84);
    do {
      DragQueryFileA(param_2,iFile,local_110,0x104);
      (*local_c)(local_110);
      iFile = iFile + 1;
    } while (iFile < local_8);
  }
  DragFinish(param_2);
  return;
}

