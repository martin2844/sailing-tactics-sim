
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004226c0(CDC *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  bool bVar3;
  float10 fVar4;
  float10 fVar5;
  int in_stack_00000008;
  int in_stack_0000000c;
  double in_stack_00000010;
  int in_stack_00000020;
  int in_stack_00000024;
  HDC hdc;
  HGDIOBJ h;
  undefined4 *local_24;
  double local_20;
  
  if (((*(int *)(&DAT_004a8660 + in_stack_00000024 * 4) < 0x11) &&
      (_DAT_004850e8 < *(double *)(&DAT_004a7f28 + in_stack_00000024 * 8))) &&
     (in_stack_00000020 == 1)) {
    return;
  }
  bVar3 = DAT_004a864c != 1;
  iVar2 = 0;
  local_24 = &DAT_004a5bb0;
  puVar1 = &DAT_004a4f90;
  do {
    fVar4 = FUN_0042c400((double)(int)(&DAT_004a6490)[iVar2],(double)(int)(&DAT_004a68c8)[iVar2],
                         in_stack_00000020,in_stack_00000024);
    if (_DAT_00484d38 < (double)CONCAT44(_DAT_004a682c,_DAT_004a6828)) {
      _DAT_004a6828 = 0;
      _DAT_004a682c = 0x40bb5800;
    }
    fVar5 = (float10)fsin(fVar4);
    fVar4 = (float10)fcos(fVar4);
    fVar5 = fVar5 * (float10)in_stack_00000010 *
            (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828) + (float10)in_stack_00000008;
    fVar4 = (float10)in_stack_0000000c -
            fVar4 * (float10)in_stack_00000010 *
            (float10)(double)CONCAT44(_DAT_004a682c,_DAT_004a6828);
    local_20 = (double)fVar5;
    if ((float10)_DAT_004850f0 < fVar5) {
      local_20 = 8000.0;
    }
    if (local_20 < _DAT_004850f8) {
      local_20 = -8000.0;
    }
    if ((float10)_DAT_004850f0 < fVar4) {
      fVar4 = (float10)_DAT_004850f0;
    }
    if (fVar4 < (float10)_DAT_004850f8) {
      fVar4 = (float10)_DAT_004850f8;
    }
    *puVar1 = (int)(longlong)local_20;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
    *local_24 = (int)(longlong)fVar4;
    local_24 = local_24 + 1;
  } while (iVar2 <= (int)((-(uint)bVar3 & 2) + 0x28));
  if ((DAT_004ac92c == 0) && (DAT_004ac98c == 0)) {
    if (DAT_004a621c == (HGDIOBJ)0x0) goto LAB_0042289c;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a621c;
  }
  else {
    if (DAT_004a70e4 == (HGDIOBJ)0x0) goto LAB_0042289c;
    hdc = *(HDC *)(param_1 + 4);
    h = DAT_004a70e4;
  }
  SelectObject(hdc,h);
LAB_0042289c:
  if (DAT_004ac1e0 == 0) {
    if ((DAT_004ac92c == 0) && (DAT_004a3f9c != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a3f9c);
    }
    if (((DAT_004ac1e0 == 0) && (DAT_004ac92c == 1)) && (DAT_004a4ee4 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
    }
  }
  if ((DAT_004ac1e0 == 1) && (DAT_004aa634 != (HGDIOBJ)0x0)) {
    SelectObject(*(HDC *)(param_1 + 4),DAT_004aa634);
  }
  if ((DAT_004a864c == 0) && (DAT_004a5a4c == 0)) {
    FUN_00422cf0(param_1);
  }
  if (DAT_004a864c == 1) {
    FUN_00422970((int)param_1);
  }
  if (DAT_004a5a4c == 1) {
    FUN_004232e0((int)param_1);
  }
  return;
}

