
uint __thiscall FUN_004af6a3(int *param_1,uint param_2,uint param_3,int param_4,undefined4 param_5)

{
  void *_Buf1;
  int iVar1;
  undefined4 *puVar2;
  AFX_MSGMAP_ENTRY *pAVar3;
  uint uVar4;
  int *piVar5;
  
  if (param_3 == 0xfffffffe) {
    iVar1 = FUN_004bfff8();
    param_3 = (**(code **)(**(int **)(iVar1 + 0x1038) + 4))(param_1,param_2,param_4,param_5);
  }
  else {
    uVar4 = 0;
    if (param_3 == 0xfffffffd) {
      param_3 = 0;
      _Buf1 = *(void **)(param_4 + 0x30);
      puVar2 = (undefined4 *)(**(code **)(*param_1 + 0x34))();
      while ((puVar2 != (undefined4 *)0x0 && (param_3 == 0))) {
        piVar5 = (int *)puVar2[1];
        while (((piVar5[1] != 0 && (piVar5[2] != 0)) && (param_3 == 0))) {
          if (param_2 == piVar5[1]) {
            if (_Buf1 == (void *)0x0) {
              iVar1 = *piVar5;
            }
            else {
              if ((void *)*piVar5 == (void *)0x0) goto LAB_004af748;
              iVar1 = _memcmp(_Buf1,(void *)*piVar5,0x10);
            }
            if (iVar1 == 0) {
              param_3 = 1;
              *(int *)(param_4 + 4) = piVar5[2];
            }
          }
LAB_004af748:
          piVar5 = piVar5 + 3;
        }
        puVar2 = (undefined4 *)*puVar2;
      }
    }
    else {
      if (param_3 != 0xffffffff) {
        uVar4 = param_3 >> 0x10;
        param_3 = param_3 & 0xffff;
      }
      if (uVar4 == 0) {
        uVar4 = 0x111;
      }
      for (puVar2 = (undefined4 *)(**(code **)(*param_1 + 0x30))(); puVar2 != (undefined4 *)0x0;
          puVar2 = (undefined4 *)*puVar2) {
        pAVar3 = AfxFindMessageEntry((AFX_MSGMAP_ENTRY *)puVar2[1],uVar4,param_3,param_2);
        if (pAVar3 != (AFX_MSGMAP_ENTRY *)0x0) {
          iVar1 = FUN_004af7bb(param_1,param_2,param_3,*(undefined4 *)(pAVar3 + 0x14),param_4,
                               *(undefined4 *)(pAVar3 + 0x10),param_5);
          return iVar1;
        }
      }
      param_3 = 0;
    }
  }
  return param_3;
}

