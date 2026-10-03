
undefined4 __thiscall FUN_004b008c(int *param_1,int param_2)

{
  undefined4 *puVar1;
  AFX_MSGMAP_ENTRY *pAVar2;
  
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 0x30))();
  do {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if (*(uint *)(param_2 + 4) < 0xc000) {
      pAVar2 = AfxFindMessageEntry((AFX_MSGMAP_ENTRY *)puVar1[1],*(uint *)(param_2 + 4),0,0);
      if (pAVar2 != (AFX_MSGMAP_ENTRY *)0x0) {
LAB_004b00c9:
        (**(code **)(pAVar2 + 0x14))(*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc));
        return 1;
      }
    }
    else {
      pAVar2 = (AFX_MSGMAP_ENTRY *)puVar1[1];
      while (pAVar2 = AfxFindMessageEntry(pAVar2,0xc000,0,0), pAVar2 != (AFX_MSGMAP_ENTRY *)0x0) {
        if (**(int **)(pAVar2 + 0x10) == *(int *)(param_2 + 4)) goto LAB_004b00c9;
        pAVar2 = pAVar2 + 0x18;
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}

