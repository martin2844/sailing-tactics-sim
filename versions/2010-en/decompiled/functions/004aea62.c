
void __fastcall FUN_004aea62(undefined4 param_1)

{
  BOOL BVar1;
  tagMSG local_20;
  
  while( true ) {
    BVar1 = PeekMessageA(&local_20,(HWND)0x0,0x121,0x121,1);
    if (BVar1 == 0) break;
    DispatchMessageA(&local_20);
  }
  FUN_004ac701(param_1);
  return;
}

