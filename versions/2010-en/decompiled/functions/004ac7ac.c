
CWnd * FUN_004ac7ac(undefined4 param_1)

{
  CHandleMap *pCVar1;
  CWnd *this;
  
  pCVar1 = (CHandleMap *)FUN_004ac73c(1);
  this = (CWnd *)FUN_004b1c6d(param_1);
  CWnd::AttachControlSite(this,pCVar1);
  return this;
}

