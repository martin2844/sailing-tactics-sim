
HLOCAL FUN_0047ba5e(SIZE_T param_1)

{
  HLOCAL pvVar1;
  
  pvVar1 = LocalAlloc(0x40,param_1);
  if (pvVar1 == (HLOCAL)0x0) {
    FUN_00466060();
  }
  return pvVar1;
}

