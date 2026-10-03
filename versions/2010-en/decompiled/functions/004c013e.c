
HLOCAL FUN_004c013e(SIZE_T param_1)

{
  HLOCAL pvVar1;
  
  pvVar1 = LocalAlloc(0x40,param_1);
  if (pvVar1 == (HLOCAL)0x0) {
    FUN_004aa740();
  }
  return pvVar1;
}

