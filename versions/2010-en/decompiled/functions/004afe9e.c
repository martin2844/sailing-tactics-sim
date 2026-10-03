
void __fastcall FUN_004afe9e(int *param_1)

{
  int iVar1;
  bool bVar2;
  BOOL BVar3;
  int iVar4;
  int iVar5;
  
  bVar2 = true;
  iVar1 = *param_1;
  iVar5 = 0;
  do {
    if (bVar2) {
      iVar4 = iVar5;
      do {
        BVar3 = PeekMessageA((LPMSG)(param_1 + 0xc),(HWND)0x0,0,0,0);
        iVar5 = iVar4;
        if (BVar3 != 0) break;
        iVar5 = iVar4 + 1;
        iVar4 = (**(code **)(iVar1 + 0x68))(iVar4);
        if (iVar4 == 0) {
          bVar2 = false;
        }
        iVar4 = iVar5;
      } while (bVar2);
    }
    do {
      iVar4 = (**(code **)(iVar1 + 100))();
      if (iVar4 == 0) {
        (**(code **)(iVar1 + 0x70))();
        return;
      }
      iVar4 = (**(code **)(iVar1 + 0x6c))((LPMSG)(param_1 + 0xc));
      if (iVar4 != 0) {
        bVar2 = true;
        iVar5 = 0;
      }
      BVar3 = PeekMessageA((LPMSG)(param_1 + 0xc),(HWND)0x0,0,0,0);
    } while (BVar3 != 0);
  } while( true );
}

