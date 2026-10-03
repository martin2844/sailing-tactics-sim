
bool __thiscall FUN_004ac7f0(CWnd *param_1,int param_2)

{
  CHandleMap *pCVar1;
  undefined4 *puVar2;
  
  if (param_2 != 0) {
    pCVar1 = (CHandleMap *)FUN_004ac73c(1);
    *(int *)(param_1 + 0x1c) = param_2;
    puVar2 = (undefined4 *)FUN_004ab73e(param_2);
    *puVar2 = param_1;
    CWnd::AttachControlSite(param_1,pCVar1);
  }
  return param_2 != 0;
}

