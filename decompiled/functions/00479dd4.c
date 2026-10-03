
void __thiscall FUN_00479dd4(void *this,void *param_1,void *param_2,RECT *param_3)

{
  uint *puVar1;
  int iVar2;
  
  if (param_2 == (void *)0x0) {
    iVar2 = 0;
    puVar1 = &DAT_00488a8c;
    do {
      if (((*puVar1 ^ *(uint *)((int)param_1 + 100)) & 0xf000) == 0) {
        param_2 = (void *)FUN_00477e26(this,(&DAT_00488a88)[iVar2 * 2]);
        break;
      }
      puVar1 = puVar1 + 2;
      iVar2 = iVar2 + 1;
    } while ((int)puVar1 < 0x488aac);
  }
  FUN_00475450(param_2,param_1,param_3);
  return;
}

