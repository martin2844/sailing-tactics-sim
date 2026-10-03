
void __thiscall
FUN_004713f9(void *this,int param_1,int param_2,uint *param_3,int *param_4,int *param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  void *local_c;
  void *local_8;
  
  local_c = this;
  local_8 = this;
  FUN_0047132a(this,(int *)&local_c);
  piVar2 = param_4;
  iVar1 = *(int *)((int)this + 0x50);
  *param_4 = *(int *)((int)this + 0x4c) - param_1;
  param_4[1] = iVar1 - param_2;
  piVar3 = (int *)FUN_00471237(this,&param_1);
  *param_5 = *piVar3;
  param_5[1] = piVar3[1];
  uVar4 = (uint)(0 < *piVar2);
  if (uVar4 == 0) {
    *param_5 = 0;
  }
  else if (param_6 != 0) {
    piVar2[1] = piVar2[1] + (int)local_8;
  }
  uVar5 = (uint)(0 < piVar2[1]);
  if (uVar5 == 0) {
    param_5[1] = 0;
  }
  else if (param_6 != 0) {
    *piVar2 = *piVar2 + (int)local_c;
  }
  if (((uVar5 != 0) && (uVar4 == 0)) && (0 < *piVar2)) {
    piVar2[1] = piVar2[1] + (int)local_8;
    uVar4 = 1;
  }
  iVar1 = *piVar2;
  if ((0 < iVar1) && (iVar1 <= *param_5)) {
    *param_5 = iVar1;
  }
  iVar1 = piVar2[1];
  if ((0 < iVar1) && (iVar1 <= param_5[1])) {
    param_5[1] = iVar1;
  }
  *param_3 = uVar4;
  param_3[1] = uVar5;
  return;
}

