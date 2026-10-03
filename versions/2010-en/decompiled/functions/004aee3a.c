
ushort * __thiscall FUN_004aee3a(int param_1,ushort *param_2)

{
  int iVar1;
  ushort *puVar2;
  ushort uVar3;
  LRESULT LVar4;
  ushort *puVar5;
  
  puVar5 = (ushort *)0x1;
  puVar2 = param_2;
  for (; (puVar2 != (ushort *)0x0 && (*param_2 != 0));
      param_2 = (ushort *)((int)(param_2 + 4) + iVar1)) {
    uVar3 = param_2[1];
    iVar1 = *(int *)(param_2 + 2);
    if (uVar3 == 0x401) {
      uVar3 = 0x180;
    }
    else if (uVar3 == 0x403) {
      uVar3 = 0x143;
    }
    if (((uVar3 == 0x180) || (uVar3 == 0x143)) &&
       (LVar4 = SendDlgItemMessageA(*(HWND *)(param_1 + 0x1c),(uint)*param_2,(uint)uVar3,0,
                                    (LPARAM)(param_2 + 4)), LVar4 == -1)) {
      puVar5 = (ushort *)0x0;
    }
    puVar2 = puVar5;
  }
  if (puVar5 != (ushort *)0x0) {
    FUN_004ae04c(*(undefined4 *)(param_1 + 0x1c),0x364,0,0,0,0);
  }
  return puVar5;
}

