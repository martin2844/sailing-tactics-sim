
ushort * __thiscall FUN_0046a75a(void *this,ushort *param_1)

{
  int iVar1;
  ushort *puVar2;
  ushort uVar3;
  LRESULT LVar4;
  ushort *puVar5;
  
  puVar5 = (ushort *)0x1;
  puVar2 = param_1;
  for (; (puVar2 != (ushort *)0x0 && (*param_1 != 0));
      param_1 = (ushort *)((int)(param_1 + 4) + iVar1)) {
    uVar3 = param_1[1];
    iVar1 = *(int *)(param_1 + 2);
    if (uVar3 == 0x401) {
      uVar3 = 0x180;
    }
    else if (uVar3 == 0x403) {
      uVar3 = 0x143;
    }
    if (((uVar3 == 0x180) || (uVar3 == 0x143)) &&
       (LVar4 = SendDlgItemMessageA(*(HWND *)((int)this + 0x1c),(uint)*param_1,(uint)uVar3,0,
                                    (LPARAM)(param_1 + 4)), LVar4 == -1)) {
      puVar5 = (ushort *)0x0;
    }
    puVar2 = puVar5;
  }
  if (puVar5 != (ushort *)0x0) {
    FUN_0046996c(*(HWND *)((int)this + 0x1c),0x364,0,0,0,0);
  }
  return puVar5;
}

