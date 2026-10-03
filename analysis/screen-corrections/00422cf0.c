
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00422cf0(CDC *param_1)

{
  int iVar1;
  int aiStack_8 [2];
  
  if (DAT_00491194 != 4) {
    _DAT_004a4ca8 = DAT_004a4f90;
    _DAT_004a4cac = DAT_004a5bb0;
    _DAT_004a4cb0 = DAT_004a4f94;
    _DAT_004a4cb4 = DAT_004a5bb4;
    _DAT_004a4cb8 = DAT_004a4f98;
    _DAT_004a4cbc = DAT_004a5bb8;
    _DAT_004a4cc0 = DAT_004a4f9c;
    _DAT_004a4cc4 = DAT_004a5bbc;
    _DAT_004a4cc8 = DAT_004a4fa0;
    _DAT_004a4ccc = DAT_004a5bc0;
    _DAT_004a4cd0 = DAT_004a4fa4;
    _DAT_004a4cd4 = DAT_004a5bc4;
    _DAT_004a4cd8 = DAT_004a4fa8;
    _DAT_004a4cdc = DAT_004a5bc8;
    _DAT_004a4ce0 = DAT_004a4fac;
    _DAT_004a4ce4 = DAT_004a5bcc;
    _DAT_004a4ce8 = DAT_004a4fb0;
    _DAT_004a4cec = DAT_004a5bd0;
    _DAT_004a4cf0 = DAT_004a4fb4;
    _DAT_004a4cf4 = DAT_004a5bd4;
    _DAT_004a4cf8 = DAT_004a4fb8;
    _DAT_004a4cfc = DAT_004a5bd8;
    _DAT_004a4d00 = DAT_004a4fbc;
    _DAT_004a4d04 = DAT_004a5bdc;
    _DAT_004a4d08 = DAT_004a4fc0;
    _DAT_004a4d0c = DAT_004a5be0;
    _DAT_004a4d10 = DAT_004a4fc4;
    _DAT_004a4d14 = DAT_004a5be4;
    _DAT_004a4d18 = DAT_004a4fc8;
    _DAT_004a4d1c = DAT_004a5be8;
    _DAT_004a4d20 = DAT_004a4fcc;
    _DAT_004a4d24 = DAT_004a5bec;
    _DAT_004a4d28 = DAT_004a4fd0;
    _DAT_004a4d2c = DAT_004a5bf0;
    _DAT_004a4d30 = DAT_004a4fd4;
    _DAT_004a4d34 = DAT_004a5bf4;
    _DAT_004a4d38 = DAT_004a4fd8;
    _DAT_004a4d3c = DAT_004a5bf8;
    _DAT_004a4d40 = DAT_004a5030;
    _DAT_004a4d44 = DAT_004a5c50;
    _DAT_004a4d4c = DAT_004a5c4c;
    _DAT_004a4d48 = DAT_004a502c;
    _DAT_004a4d50 = DAT_004a5028;
    _DAT_004a4d58 = DAT_004a5024;
    _DAT_004a4d54 = DAT_004a5c48;
    _DAT_004a4d5c = DAT_004a5c44;
    (**(code **)(*(int *)param_1 + 0x2c))(param_1,8);
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,0x17);
    if (DAT_004ac1e0 == 0) {
      if ((DAT_004ac92c == 0) && (DAT_004a3f9c != (HGDIOBJ)0x0)) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a3f9c);
      }
      if (((DAT_004ac1e0 == 0) && (DAT_004ac92c == 1)) && (DAT_004a4ee4 != (HGDIOBJ)0x0)) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
      }
    }
    if ((DAT_004ac1e0 == 1) && (DAT_004aa634 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004aa634);
    }
    FUN_004706bd(param_1,aiStack_8,DAT_004a4f90,DAT_004a5bb0);
    iVar1 = 0;
    do {
      CDC::LineTo(param_1,*(int *)((int)&DAT_004a4f94 + iVar1),*(int *)((int)&DAT_004a5bb4 + iVar1))
      ;
      iVar1 = iVar1 + 4;
    } while (iVar1 < 0x45);
  }
  if (DAT_00491194 != 2) {
    _DAT_004a4ca8 = DAT_004a4fd8;
    _DAT_004a4cac = DAT_004a5bf8;
    _DAT_004a4cb0 = DAT_004a4fdc;
    _DAT_004a4cb4 = DAT_004a5bfc;
    _DAT_004a4cb8 = DAT_004a4fe0;
    _DAT_004a4cbc = DAT_004a5c00;
    _DAT_004a4cc0 = DAT_004a4fe4;
    _DAT_004a4cc4 = DAT_004a5c04;
    _DAT_004a4cc8 = DAT_004a4fe8;
    _DAT_004a4ccc = DAT_004a5c08;
    _DAT_004a4cd0 = DAT_004a4fec;
    _DAT_004a4cd4 = DAT_004a5c0c;
    _DAT_004a4cd8 = DAT_004a4ff0;
    _DAT_004a4cdc = DAT_004a5c10;
    _DAT_004a4ce0 = DAT_004a4ff4;
    _DAT_004a4ce4 = DAT_004a5c14;
    _DAT_004a4ce8 = DAT_004a4ff8;
    _DAT_004a4cec = DAT_004a5c18;
    _DAT_004a4cf0 = DAT_004a4ffc;
    _DAT_004a4cf4 = DAT_004a5c1c;
    _DAT_004a4cf8 = DAT_004a5000;
    _DAT_004a4cfc = DAT_004a5c20;
    _DAT_004a4d00 = DAT_004a5004;
    _DAT_004a4d04 = DAT_004a5c24;
    _DAT_004a4d08 = DAT_004a5008;
    _DAT_004a4d0c = DAT_004a5c28;
    _DAT_004a4d10 = DAT_004a500c;
    _DAT_004a4d14 = DAT_004a5c2c;
    _DAT_004a4d18 = DAT_004a5010;
    _DAT_004a4d1c = DAT_004a5c30;
    _DAT_004a4d20 = DAT_004a5014;
    _DAT_004a4d24 = DAT_004a5c34;
    _DAT_004a4d28 = DAT_004a5018;
    _DAT_004a4d2c = DAT_004a5c38;
    _DAT_004a4d30 = DAT_004a501c;
    _DAT_004a4d34 = DAT_004a5c3c;
    _DAT_004a4d38 = DAT_004a5020;
    _DAT_004a4d3c = DAT_004a5c40;
    _DAT_004a4d40 = DAT_004a5024;
    _DAT_004a4d44 = DAT_004a5c44;
    _DAT_004a4d4c = DAT_004a5c58;
    _DAT_004a4d48 = DAT_004a5038;
    _DAT_004a4d50 = DAT_004a5034;
    _DAT_004a4d58 = DAT_004a5030;
    _DAT_004a4d54 = DAT_004a5c54;
    _DAT_004a4d5c = DAT_004a5c50;
    (**(code **)(*(int *)param_1 + 0x2c))(param_1,8);
    Polygon(*(HDC *)(param_1 + 4),(POINT *)&DAT_004a4ca8,0x17);
    if (DAT_004ac1e0 == 0) {
      if ((DAT_004ac92c == 0) && (DAT_004a3f9c != (HGDIOBJ)0x0)) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a3f9c);
      }
      if (((DAT_004ac1e0 == 0) && (DAT_004ac92c == 1)) && (DAT_004a4ee4 != (HGDIOBJ)0x0)) {
        SelectObject(*(HDC *)(param_1 + 4),DAT_004a4ee4);
      }
    }
    if ((DAT_004ac1e0 == 1) && (DAT_004aa634 != (HGDIOBJ)0x0)) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004aa634);
    }
    FUN_004706bd(param_1,aiStack_8,DAT_004a4fd8,DAT_004a5bf8);
    iVar1 = 0;
    do {
      CDC::LineTo(param_1,*(int *)((int)&DAT_004a4fdc + iVar1),*(int *)((int)&DAT_004a5bfc + iVar1))
      ;
      iVar1 = iVar1 + 4;
    } while (iVar1 < 0x45);
  }
  return;
}

