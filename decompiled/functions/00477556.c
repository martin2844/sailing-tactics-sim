
void __thiscall FUN_00477556(void *this,uint param_1)

{
  CWnd *pCVar1;
  LRESULT LVar2;
  uint uVar3;
  
  pCVar1 = FUN_0046980f(this);
  uVar3 = param_1 & 0xfff0;
  if (*(int *)(pCVar1 + 0x50) == 0) {
LAB_00477582:
    FUN_00468021(this);
  }
  else {
    if (uVar3 < 0xf011) {
      if ((uVar3 != 0xf010) && (uVar3 != 0xf000)) goto LAB_00477582;
    }
    else if (uVar3 != 0xf020) {
      if (((((uVar3 != 0xf030) && (uVar3 != 0xf040)) && (uVar3 != 0xf050)) &&
          ((uVar3 != 0xf060 && (uVar3 != 0xf120)))) && (uVar3 != 0xf130)) goto LAB_00477582;
    }
    LVar2 = SendMessageA(*(HWND *)((int)this + 0x1c),0x365,0,(uVar3 - 0xf000 >> 4) + 0x1ef00);
    if (LVar2 == 0) {
      SendMessageA(*(HWND *)((int)this + 0x1c),0x111,0xe147,0);
    }
  }
  return;
}

