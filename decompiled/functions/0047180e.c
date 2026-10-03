
int * __thiscall FUN_0047180e(void *this,char *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  CWnd *pCVar3;
  char *lpString2;
  byte *pbVar4;
  int iVar5;
  CWnd *pCVar6;
  int iVar7;
  undefined4 *puVar8;
  CHAR local_318 [260];
  byte local_214 [260];
  CHAR local_110 [260];
  int *local_c;
  int *local_8;
  
  iVar7 = 0;
  puVar8 = *(undefined4 **)((int)this + 8);
  local_c = (int *)0x0;
  local_8 = (int *)0x0;
  lpString2 = param_1;
  if (*param_1 == '\"') {
    lpString2 = param_1 + 1;
  }
  lstrcpynA((LPSTR)local_214,lpString2,0x104);
  pbVar4 = FUN_00458bc0(local_214,0x22);
  if (pbVar4 != (byte *)0x0) {
    *pbVar4 = 0;
  }
  FUN_0046cc20();
  FUN_00455bf0();
  iVar5 = FUN_0046cad6();
  if (iVar5 != 0) {
    lstrcpyA(local_110,local_318);
  }
  do {
    if (puVar8 == (undefined4 *)0x0) break;
    puVar1 = (undefined4 *)*puVar8;
    piVar2 = (int *)puVar8[2];
    iVar5 = (**(code **)(*piVar2 + 0x70))(local_110,&local_8);
    if (iVar7 < iVar5) {
      iVar7 = iVar5;
      local_c = piVar2;
    }
    puVar8 = puVar1;
  } while (iVar5 != 5);
  if (local_8 == (int *)0x0) {
    if (local_c == (int *)0x0) {
      FUN_0047260c();
      local_8 = (int *)0x0;
    }
    else {
      local_8 = (int *)(**(code **)(*local_c + 0x88))(local_110,1);
    }
  }
  else {
    param_1 = (char *)(**(code **)(*local_8 + 0x68))();
    if (param_1 != (char *)0x0) {
      iVar7 = (**(code **)(*local_8 + 0x6c))(&param_1);
      pCVar6 = FUN_004696a2(iVar7);
      if (pCVar6 != (CWnd *)0x0) {
        (**(code **)(*(int *)pCVar6 + 0xd4))(0xffffffff);
      }
      iVar7 = FUN_0047b918();
      pCVar3 = *(CWnd **)(*(int *)(iVar7 + 4) + 0x1c);
      if (pCVar6 != pCVar3) {
        (**(code **)(*(int *)pCVar3 + 0xd4))(0xffffffff);
      }
    }
  }
  return local_8;
}

