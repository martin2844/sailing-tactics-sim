
void FUN_004568e3(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  HWND *ppHVar3;
  HWND local_28;
  uint local_24;
  undefined4 local_1c;
  undefined1 local_14 [8];
  tagPOINT local_c;
  
  puVar2 = param_2;
  ppHVar3 = &local_28;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppHVar3 = (HWND)*puVar2;
    puVar2 = puVar2 + 1;
    ppHVar3 = ppHVar3 + 1;
  }
  local_28 = (HWND)SendMessageA(*(HWND *)(param_1 + 0x1c),0x410,0,(LPARAM)local_14);
  local_c.x = param_2[5];
  local_c.y = param_2[6];
  if ((0x1ff < local_24) && (local_24 < 0x20a)) {
    ScreenToClient(local_28,&local_c);
  }
  local_1c = CONCAT22((undefined2)local_c.y,(undefined2)local_c.x);
  SendMessageA(*(HWND *)(param_1 + 0x1c),0x407,0,(LPARAM)&local_28);
  return;
}

