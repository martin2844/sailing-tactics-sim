
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00433120(int *param_1)

{
  int iVar1;
  int aiStack_8 [2];
  
  if (DAT_004da19c != 4) {
    _DAT_004f6e28 = DAT_004f8028;
    _DAT_004f6e2c = DAT_004faa60;
    _DAT_004f6e30 = DAT_004f802c;
    _DAT_004f6e34 = DAT_004faa64;
    _DAT_004f6e38 = DAT_004f8030;
    _DAT_004f6e3c = DAT_004faa68;
    _DAT_004f6e40 = DAT_004f8034;
    _DAT_004f6e44 = DAT_004faa6c;
    _DAT_004f6e48 = DAT_004f8038;
    _DAT_004f6e4c = DAT_004faa70;
    _DAT_004f6e50 = DAT_004f803c;
    _DAT_004f6e54 = DAT_004faa74;
    _DAT_004f6e58 = DAT_004f8040;
    _DAT_004f6e5c = DAT_004faa78;
    _DAT_004f6e60 = DAT_004f8044;
    _DAT_004f6e64 = DAT_004faa7c;
    _DAT_004f6e68 = DAT_004f8048;
    _DAT_004f6e6c = DAT_004faa80;
    _DAT_004f6e70 = DAT_004f804c;
    _DAT_004f6e74 = DAT_004faa84;
    _DAT_004f6e78 = DAT_004f8050;
    _DAT_004f6e7c = DAT_004faa88;
    _DAT_004f6e80 = DAT_004f8054;
    _DAT_004f6e84 = DAT_004faa8c;
    _DAT_004f6e88 = DAT_004f8058;
    _DAT_004f6e8c = DAT_004faa90;
    _DAT_004f6e90 = DAT_004f805c;
    _DAT_004f6e94 = DAT_004faa94;
    _DAT_004f6e98 = DAT_004f8060;
    _DAT_004f6e9c = DAT_004faa98;
    _DAT_004f6ea0 = DAT_004f8064;
    _DAT_004f6ea4 = DAT_004faa9c;
    _DAT_004f6ea8 = DAT_004f8068;
    _DAT_004f6eac = DAT_004faaa0;
    _DAT_004f6eb0 = DAT_004f806c;
    _DAT_004f6eb4 = DAT_004faaa4;
    _DAT_004f6eb8 = DAT_004f8070;
    _DAT_004f6ebc = DAT_004faaa8;
    _DAT_004f6ec0 = DAT_004f80c8;
    _DAT_004f6ec4 = DAT_004fab00;
    _DAT_004f6ecc = DAT_004faafc;
    _DAT_004f6ec8 = DAT_004f80c4;
    _DAT_004f6ed0 = DAT_004f80c0;
    _DAT_004f6ed8 = DAT_004f80bc;
    _DAT_004f6ed4 = DAT_004faaf8;
    _DAT_004f6edc = DAT_004faaf4;
    (**(code **)(*param_1 + 0x2c))(param_1,8);
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,0x17);
    if (DAT_005359d8 == 0) {
      if ((DAT_005363e4 == 0) && (DAT_004f40a4 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004f40a4);
      }
      if (((DAT_005359d8 == 0) && (DAT_005363e4 == 1)) && (DAT_004f7ec4 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004f7ec4);
      }
    }
    if ((DAT_005359d8 == 1) && (DAT_00522d14 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_00522d14);
    }
    FUN_004b4d9d(param_1,aiStack_8,DAT_004f8028,DAT_004faa60);
    iVar1 = 0;
    do {
      CDC::LineTo(param_1,*(int *)((int)&DAT_004f802c + iVar1),*(int *)((int)&DAT_004faa64 + iVar1))
      ;
      iVar1 = iVar1 + 4;
    } while (iVar1 < 0x45);
  }
  if (DAT_004da19c != 2) {
    _DAT_004f6e28 = DAT_004f8070;
    _DAT_004f6e2c = DAT_004faaa8;
    _DAT_004f6e30 = DAT_004f8074;
    _DAT_004f6e34 = DAT_004faaac;
    _DAT_004f6e38 = DAT_004f8078;
    _DAT_004f6e3c = DAT_004faab0;
    _DAT_004f6e40 = DAT_004f807c;
    _DAT_004f6e44 = DAT_004faab4;
    _DAT_004f6e48 = DAT_004f8080;
    _DAT_004f6e4c = DAT_004faab8;
    _DAT_004f6e50 = DAT_004f8084;
    _DAT_004f6e54 = DAT_004faabc;
    _DAT_004f6e58 = DAT_004f8088;
    _DAT_004f6e5c = DAT_004faac0;
    _DAT_004f6e60 = DAT_004f808c;
    _DAT_004f6e64 = DAT_004faac4;
    _DAT_004f6e68 = DAT_004f8090;
    _DAT_004f6e6c = DAT_004faac8;
    _DAT_004f6e70 = DAT_004f8094;
    _DAT_004f6e74 = DAT_004faacc;
    _DAT_004f6e78 = DAT_004f8098;
    _DAT_004f6e7c = DAT_004faad0;
    _DAT_004f6e80 = DAT_004f809c;
    _DAT_004f6e84 = DAT_004faad4;
    _DAT_004f6e88 = DAT_004f80a0;
    _DAT_004f6e8c = DAT_004faad8;
    _DAT_004f6e90 = DAT_004f80a4;
    _DAT_004f6e94 = DAT_004faadc;
    _DAT_004f6e98 = DAT_004f80a8;
    _DAT_004f6e9c = DAT_004faae0;
    _DAT_004f6ea0 = DAT_004f80ac;
    _DAT_004f6ea4 = DAT_004faae4;
    _DAT_004f6ea8 = DAT_004f80b0;
    _DAT_004f6eac = DAT_004faae8;
    _DAT_004f6eb0 = DAT_004f80b4;
    _DAT_004f6eb4 = DAT_004faaec;
    _DAT_004f6eb8 = DAT_004f80b8;
    _DAT_004f6ebc = DAT_004faaf0;
    _DAT_004f6ec0 = DAT_004f80bc;
    _DAT_004f6ec4 = DAT_004faaf4;
    _DAT_004f6ecc = DAT_004fab08;
    _DAT_004f6ec8 = DAT_004f80d0;
    _DAT_004f6ed0 = DAT_004f80cc;
    _DAT_004f6ed8 = DAT_004f80c8;
    _DAT_004f6ed4 = DAT_004fab04;
    _DAT_004f6edc = DAT_004fab00;
    (**(code **)(*param_1 + 0x2c))(param_1,8);
    Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,0x17);
    if (DAT_005359d8 == 0) {
      if ((DAT_005363e4 == 0) && (DAT_004f40a4 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004f40a4);
      }
      if (((DAT_005359d8 == 0) && (DAT_005363e4 == 1)) && (DAT_004f7ec4 != (HGDIOBJ)0x0)) {
        SelectObject((HDC)param_1[1],DAT_004f7ec4);
      }
    }
    if ((DAT_005359d8 == 1) && (DAT_00522d14 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_00522d14);
    }
    FUN_004b4d9d(param_1,aiStack_8,DAT_004f8070,DAT_004faaa8);
    iVar1 = 0;
    do {
      CDC::LineTo(param_1,*(int *)((int)&DAT_004f8074 + iVar1),*(int *)((int)&DAT_004faaac + iVar1))
      ;
      iVar1 = iVar1 + 4;
    } while (iVar1 < 0x45);
  }
  return;
}

