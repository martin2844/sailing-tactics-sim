
int * __thiscall
FUN_0049a575(int param_1,int *param_2,int param_3,int param_4,LPCSTR param_5,int param_6,int param_7
            ,INT *param_8,int param_9)

{
  LONG LVar1;
  
  LVar1 = TabbedTextOutA(*(HDC *)(param_1 + 4),param_3,param_4,param_5,param_6,param_7,param_8,
                         param_9);
  param_2[1] = (int)(short)((uint)LVar1 >> 0x10);
  *param_2 = (int)(short)LVar1;
  return param_2;
}

