
int * __thiscall FUN_00470671(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = param_1;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    param_1 = (int *)IntersectClipRect(*(HDC *)((int)this + 4),*param_1,param_1[1],param_1[2],
                                       param_1[3]);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    param_1 = (int *)IntersectClipRect(*(HDC *)((int)this + 8),*piVar1,piVar1[1],piVar1[2],piVar1[3]
                                      );
  }
  return param_1;
}

