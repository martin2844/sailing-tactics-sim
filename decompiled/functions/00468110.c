
bool __thiscall FUN_00468110(void *this,uint param_1)

{
  CHandleMap *this_00;
  undefined4 *puVar1;
  
  if (param_1 != 0) {
    this_00 = (CHandleMap *)FUN_0046805c();
    *(uint *)((int)this + 0x1c) = param_1;
    puVar1 = FUN_0046705e(this_00,param_1);
    *puVar1 = this;
    CWnd::AttachControlSite(this,this_00);
  }
  return param_1 != 0;
}

