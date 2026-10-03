
undefined4 __fastcall FUN_00475164(void *param_1)

{
  HWND pHVar1;
  CWnd *pCVar2;
  BOOL BVar3;
  tagMSG local_20;
  
  pHVar1 = GetCapture();
  if (pHVar1 == (HWND)0x0) {
    SetCapture(*(HWND *)(*(int *)((int)param_1 + 0x68) + 0x1c));
    FUN_004680cc();
    GetCapture();
    pCVar2 = FUN_004680cc();
    if (pCVar2 == *(CWnd **)((int)param_1 + 0x68)) {
      do {
        BVar3 = GetMessageA(&local_20,(HWND)0x0,0,0);
        if (BVar3 == 0) {
          AfxPostQuitMessage(local_20.wParam);
          break;
        }
        if (local_20.message == 0x100) {
          if (*(int *)((int)param_1 + 0x88) != 0) {
            FUN_004748f1(param_1,local_20.wParam,1);
          }
          if (local_20.wParam == 0x1b) break;
        }
        else if (local_20.message == 0x101) {
          if (*(int *)((int)param_1 + 0x88) != 0) {
            FUN_004748f1(param_1,local_20.wParam,0);
          }
        }
        else if (local_20.message == 0x200) {
          if (*(int *)((int)param_1 + 0x88) == 0) {
            FUN_00474b6d(param_1,local_20.pt.x,local_20.pt.y);
          }
          else {
            FUN_00474875(param_1,local_20.pt.x,local_20.pt.y);
          }
        }
        else {
          if (local_20.message == 0x202) {
            if (*(int *)((int)param_1 + 0x88) == 0) {
              FUN_00474c69(param_1);
            }
            else {
              FUN_00474925(param_1);
            }
            return 1;
          }
          if (local_20.message == 0x204) break;
          DispatchMessageA(&local_20);
        }
        GetCapture();
        pCVar2 = FUN_004680cc();
      } while (pCVar2 == *(CWnd **)((int)param_1 + 0x68));
    }
    FUN_00474e53(param_1);
  }
  return 0;
}

