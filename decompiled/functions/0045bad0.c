
void __cdecl FUN_0045bad0(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_LOOP_004a2080 == param_1) {
    PTR_LOOP_004a2080 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_004a0060) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_004afdec,0,param_1);
    return;
  }
  DAT_004a0070 = 0xffffffff;
  return;
}

