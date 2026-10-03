
int __thiscall FUN_00477e26(void *this,uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_1 == 0) {
LAB_00477e53:
    iVar3 = 0;
  }
  else {
    puVar4 = *(undefined4 **)((int)this + 0x70);
    do {
      if (puVar4 == (undefined4 *)0x0) goto LAB_00477e53;
      puVar1 = (undefined4 *)*puVar4;
      iVar3 = puVar4[2];
      uVar2 = GetDlgCtrlID(*(HWND *)(iVar3 + 0x1c));
      puVar4 = puVar1;
    } while ((uVar2 & 0xffff) != param_1);
  }
  return iVar3;
}

