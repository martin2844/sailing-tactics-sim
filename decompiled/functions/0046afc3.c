
uint __thiscall
FUN_0046afc3(void *this,undefined4 *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  void *_Buf1;
  int iVar1;
  undefined4 *puVar2;
  AFX_MSGMAP_ENTRY *pAVar3;
  uint uVar4;
  int *piVar5;
  
  if (param_2 == 0xfffffffe) {
    iVar1 = FUN_0047b918();
    param_2 = (**(code **)(**(int **)(iVar1 + 0x1038) + 4))(this,param_1,param_3,param_4);
  }
  else {
    uVar4 = 0;
    if (param_2 == 0xfffffffd) {
      param_2 = 0;
      _Buf1 = (void *)param_3[0xc];
      puVar2 = (undefined4 *)(**(code **)(*(int *)this + 0x34))();
      while ((puVar2 != (undefined4 *)0x0 && (param_2 == 0))) {
        piVar5 = (int *)puVar2[1];
        while ((((undefined4 *)piVar5[1] != (undefined4 *)0x0 && (piVar5[2] != 0)) && (param_2 == 0)
               )) {
          if (param_1 == (undefined4 *)piVar5[1]) {
            if (_Buf1 == (void *)0x0) {
              iVar1 = *piVar5;
            }
            else {
              if ((void *)*piVar5 == (void *)0x0) goto LAB_0046b068;
              iVar1 = _memcmp(_Buf1,(void *)*piVar5,0x10);
            }
            if (iVar1 == 0) {
              param_2 = 1;
              param_3[1] = piVar5[2];
            }
          }
LAB_0046b068:
          piVar5 = piVar5 + 3;
        }
        puVar2 = (undefined4 *)*puVar2;
      }
    }
    else {
      if (param_2 != 0xffffffff) {
        uVar4 = param_2 >> 0x10;
        param_2 = param_2 & 0xffff;
      }
      if (uVar4 == 0) {
        uVar4 = 0x111;
      }
      for (puVar2 = (undefined4 *)(**(code **)(*(int *)this + 0x30))(); puVar2 != (undefined4 *)0x0;
          puVar2 = (undefined4 *)*puVar2) {
        pAVar3 = AfxFindMessageEntry((AFX_MSGMAP_ENTRY *)puVar2[1],uVar4,param_2,(uint)param_1);
        if (pAVar3 != (AFX_MSGMAP_ENTRY *)0x0) {
          uVar4 = FUN_0046b0db(this,param_1,param_2,*(undefined **)(pAVar3 + 0x14),param_3,
                               *(uint *)(pAVar3 + 0x10),param_4);
          return uVar4;
        }
      }
      param_2 = 0;
    }
  }
  return param_2;
}

