
undefined4 FUN_004a5ee0(int param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  byte bVar1;
  bool bVar2;
  size_t _Count;
  DWORD DVar3;
  int iVar4;
  char *_Source;
  char *_Dest;
  uint uVar5;
  byte *pbVar6;
  char local_80 [128];
  
  if (param_1 != 1) {
    if (param_1 != 0) {
      return 0xffffffff;
    }
    iVar4 = FUN_004a6090(param_2,param_3,&DAT_005388f0,4,0);
    if (iVar4 != 0) {
      pbVar6 = &DAT_005388f0;
      *param_4 = '\0';
      while( true ) {
        bVar1 = *pbVar6;
        if (DAT_004f045c < 2) {
          uVar5 = (byte)PTR_DAT_004f0250[(uint)bVar1 * 2] & 4;
        }
        else {
          uVar5 = FUN_004a0b90(bVar1,4);
        }
        if (uVar5 == 0) break;
        pbVar6 = pbVar6 + 2;
        *param_4 = *param_4 * '\n' + bVar1 + -0x30;
        if (0x5388f7 < (int)pbVar6) {
          return 0;
        }
      }
      return 0;
    }
    return 0xffffffff;
  }
  _Source = local_80;
  bVar2 = false;
  _Count = FUN_004a61c0(param_2,param_3,local_80,0x80,0);
  if (_Count == 0) {
    DVar3 = GetLastError();
    if (((DVar3 != 0x7a) || (iVar4 = FUN_004a61c0(param_2,param_3,0,0,0), iVar4 == 0)) ||
       (_Source = (char *)FUN_0049bf00(iVar4), _Source == (char *)0x0)) goto LAB_004a5f90;
    bVar2 = true;
    _Count = FUN_004a61c0(param_2,param_3,_Source,iVar4,0);
    if (_Count == 0) goto LAB_004a5f90;
  }
  _Dest = (char *)FUN_0049bf00(_Count);
  *(char **)param_4 = _Dest;
  if (_Dest != (char *)0x0) {
    _strncpy(_Dest,_Source,_Count);
    if (!bVar2) {
      return 0;
    }
    FUN_0049bfd0(_Source);
    return 0;
  }
LAB_004a5f90:
  if (!bVar2) {
    return 0xffffffff;
  }
  FUN_0049bfd0(_Source);
  return 0xffffffff;
}

