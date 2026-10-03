
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004889e0(int *param_1,int param_2)

{
  _DAT_00536224 = 0xce4;
  _DAT_004f6d44 = 0xffffd67e;
  _DAT_004fb9d4 = 0x10f7;
  _DAT_004f720c = 0xffffd6ca;
  _DAT_004fb9f4 = 0x13ce;
  _DAT_004f71f4 = 0xffffd6fc;
  _DAT_00536214 = 0x171f;
  _DAT_004f6d54 = 0xffffd738;
  FUN_004865c0(param_1,1,param_2);
  FUN_0043e730(0,12000.0,14760.0,param_2,5);
  FUN_004817a0(param_1,1,1,DAT_004fed58,DAT_00523660,0,0,5,0,param_2);
  FUN_0043e730(0,-2700.0,
               (_DAT_004cd018 - _DAT_00534d68 * _DAT_004cd010) -
               (double)_DAT_00512d84 * _DAT_004cc4c0,param_2,5);
  _DAT_005357bc = 0;
  _DAT_004fc33c = 0;
  _DAT_004fe064 = 0;
  _DAT_004fe278 = 0;
  _DAT_004fe27c = 0;
  _DAT_00535ebc = 1;
  if ((DAT_004fed58 < DAT_004fe624) && (0 < DAT_004fed58)) {
    if (DAT_00523660 <= DAT_00535564) {
      FUN_00417aa0(param_1,DAT_004fed58,DAT_00523660,0x1f,param_2,DAT_00535564,DAT_004da148);
    }
  }
  return;
}

