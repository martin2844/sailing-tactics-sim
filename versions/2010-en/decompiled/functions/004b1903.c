
undefined4 FUN_004b1903(uint *param_1,undefined4 param_2,undefined2 *param_3)

{
  short sVar1;
  uint uVar2;
  undefined2 *puVar3;
  LPSTR lpMultiByteStr;
  int cbMultiByte;
  LPCSTR lpDefaultChar;
  LPBOOL lpUsedDefaultChar;
  
  if (*(short *)((int)param_1 + 2) == -1) {
    uVar2 = param_1[3];
  }
  else {
    uVar2 = *param_1;
  }
  if ((uVar2 & 0x40) == 0) {
    return 0;
  }
  puVar3 = (undefined2 *)FUN_004b17f6(param_1);
  lpUsedDefaultChar = (LPBOOL)0x0;
  *param_3 = *puVar3;
  sVar1 = *(short *)((int)param_1 + 2);
  lpDefaultChar = (LPCSTR)0x0;
  cbMultiByte = 0x20;
  lpMultiByteStr = (LPSTR)FUN_004b09cd(0x20);
  WideCharToMultiByte(0,0,puVar3 + ((sVar1 != -1) - 1 & 2) + 1,-1,lpMultiByteStr,cbMultiByte,
                      lpDefaultChar,lpUsedDefaultChar);
  FUN_004b09a5(0xffffffff);
  return 1;
}

