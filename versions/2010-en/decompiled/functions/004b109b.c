
Tact2010CString * FUN_004b109b(Tact2010CString *param_1,undefined4 *param_2)

{
  CHAR local_108 [256];
  undefined4 local_8;
  
  local_8 = 0;
  wsprintfA(local_108,"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",*param_2,
            (uint)*(ushort *)(param_2 + 1),(uint)*(ushort *)((int)param_2 + 6),
            (uint)*(byte *)(param_2 + 2),(uint)*(byte *)((int)param_2 + 9),
            (uint)*(byte *)((int)param_2 + 10),(uint)*(byte *)((int)param_2 + 0xb),
            (uint)*(byte *)(param_2 + 3),(uint)*(byte *)((int)param_2 + 0xd),
            (uint)*(byte *)((int)param_2 + 0xe),(uint)*(byte *)((int)param_2 + 0xf));
  FUN_004b0613(param_1,local_108);
  return param_1;
}

