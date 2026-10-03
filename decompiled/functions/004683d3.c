
undefined4 FUN_004683d3(undefined4 param_1,int param_2,HDC param_3,HWND param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_0047bea7();
  if (((*(HANDLE *)(iVar1 + 4) != (HANDLE)0x0) &&
      ((((param_2 == 0x135 || (param_2 == 0x136)) || (param_2 == 0x138)) ||
       ((param_2 == 0x137 || (param_2 == 0x134)))))) &&
     (iVar2 = FUN_0046a456(param_3,param_4,param_2 + -0x132,*(HANDLE *)(iVar1 + 4),
                           *(COLORREF *)(iVar1 + 8)), iVar2 != 0)) {
    return *(undefined4 *)(iVar1 + 4);
  }
  uVar3 = FUN_004681ad();
  return uVar3;
}

