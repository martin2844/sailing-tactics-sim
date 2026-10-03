
int * __thiscall FUN_004b4d05(int param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = param_2;
  if (*(HDC *)(param_1 + 4) != *(HDC *)(param_1 + 8)) {
    param_2 = (int *)ExcludeClipRect(*(HDC *)(param_1 + 4),*param_2,param_2[1],param_2[2],param_2[3]
                                    );
  }
  if (*(HDC *)(param_1 + 8) != (HDC)0x0) {
    param_2 = (int *)ExcludeClipRect(*(HDC *)(param_1 + 8),*piVar1,piVar1[1],piVar1[2],piVar1[3]);
  }
  return param_2;
}

