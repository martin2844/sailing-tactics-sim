
int FUN_0049d1d0(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_005385dc = 1;
                    /* WARNING: Could not recover jumptable at 0x0049d1ed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_005385dc = 1;
                    /* WARNING: Could not recover jumptable at 0x0049d202. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_005387b0;
  }
  DAT_005385dc = (uint)bVar2;
  return param_1;
}

