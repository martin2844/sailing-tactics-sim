
undefined4 __thiscall
FUN_00477311(void *this,undefined4 *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  piVar1 = (int *)FUN_0047782e((int)this);
  if (((piVar1 == (int *)0x0) ||
      (iVar2 = (**(code **)(*piVar1 + 0x14))(param_1,param_2,param_3,param_4), iVar2 == 0)) &&
     (uVar3 = FUN_0046afc3(this,param_1,param_2,param_3,param_4), uVar3 == 0)) {
    iVar2 = FUN_0047b918();
    if ((*(int **)(iVar2 + 4) == (int *)0x0) ||
       (iVar2 = (**(code **)(**(int **)(iVar2 + 4) + 0x14))(param_1,param_2,param_3,param_4),
       iVar2 == 0)) {
      return 0;
    }
  }
  return 1;
}

