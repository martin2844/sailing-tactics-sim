
void FUN_004a01b0(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_LOOP_004f0240 == param_1) {
    PTR_LOOP_004f0240 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_004ee220) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_0053992c,0,param_1);
    return;
  }
  DAT_004ee230 = 0xffffffff;
  return;
}

