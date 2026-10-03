
CWnd * FUN_004680cc(void)

{
  CHandleMap *pCVar1;
  CWnd *this;
  
  pCVar1 = (CHandleMap *)FUN_0046805c();
  this = (CWnd *)FUN_0046d58d();
  CWnd::AttachControlSite(this,pCVar1);
  return this;
}

