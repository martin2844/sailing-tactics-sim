
void __fastcall FUN_004ab8cb(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (*(int *)(param_1 + 4) != 0) {
    uVar1 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        for (puVar2 = *(undefined4 **)(*(int *)(param_1 + 4) + uVar1 * 4);
            puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
          FUN_004b05a5((Tact2010CString *)(puVar2 + 2));
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(param_1 + 8));
    }
    FUN_004afc21(*(undefined4 *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  FUN_004ab2f9();
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}

