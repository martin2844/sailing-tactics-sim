
undefined4 __cdecl FUN_0046d223(uint *param_1,void *param_2,undefined2 *param_3)

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
  puVar3 = (undefined2 *)FUN_0046d116((int)param_1);
  lpUsedDefaultChar = (LPBOOL)0x0;
  *param_3 = *puVar3;
  sVar1 = *(short *)((int)param_1 + 2);
  lpDefaultChar = (LPCSTR)0x0;
  cbMultiByte = 0x20;
  lpMultiByteStr = (LPSTR)FUN_0046c2ed(param_2,0x20);
  WideCharToMultiByte(0,0,puVar3 + ((sVar1 != -1) - 1 & 2) + 1,-1,lpMultiByteStr,cbMultiByte,
                      lpDefaultChar,lpUsedDefaultChar);
  FUN_0046c2c5(param_2,-1);
  return 1;
}

