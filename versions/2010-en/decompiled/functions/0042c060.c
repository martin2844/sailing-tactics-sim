
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042c060(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = 10;
  if (DAT_004da1f8 == 999) {
    DAT_004da220 = 0xffff8ad0;
    DAT_004da228 = 0xffff8ad0;
    DAT_004da21c = 30000;
    DAT_004da224 = 30000;
    if (DAT_00536508 == 1) {
      iVar2 = 5;
    }
    DAT_00535498 = iVar2;
    if (DAT_00536504 == 3) {
      DAT_00535498 = 8;
    }
    if (DAT_00536504 == 1) {
      DAT_00535498 = 6;
    }
    iVar2 = 1;
    DAT_004f69b8 = 0;
    DAT_00511374 = 0;
    DAT_005230dc = DAT_004da23c / 0x5a + 1;
    DAT_00535e3c = 0;
    DAT_004fe764 = DAT_00535498;
    DAT_00522f08 = DAT_00535498;
    if (DAT_00535498 != 0) {
      iVar3 = 0;
      do {
        *(undefined4 *)((int)&DAT_00535314 + iVar3) = 0;
        *(undefined4 *)((int)&DAT_00535374 + iVar3) = 0x48;
        FUN_0048b8a0(iVar2);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 4;
      } while (iVar2 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
    }
    DAT_005364b4 = 0;
    uVar1 = DAT_0051359c - DAT_004f711c >> 0x1f;
    iVar2 = (DAT_0051359c - DAT_004f711c ^ uVar1) - uVar1;
    DAT_004f4afc = iVar2;
    if (0xb4 < iVar2) {
      DAT_004f4afc = 0x168 - iVar2;
    }
    if ((DAT_004f4afc < 0x32) && (iVar2 < 0x32)) {
      DAT_004fbac4 = (DAT_004f711c + DAT_0051359c) / 2;
      DAT_004fbac8 = FUN_0041bc20(DAT_004fbac4 + 0xb4);
      DAT_005364b4 = 2;
    }
    if (0x82 < DAT_004f4afc) {
      if (DAT_004f711c < DAT_0051359c) {
        iVar2 = FUN_0041bc20(DAT_0051359c + -0xb4);
        DAT_004fbac4 = (iVar2 + DAT_004f711c) / 2;
      }
      if (DAT_0051359c < DAT_004f711c) {
        iVar2 = FUN_0041bc20(DAT_004f711c + -0xb4);
        DAT_004fbac4 = (iVar2 + DAT_0051359c) / 2;
      }
      if (DAT_004f4afc == 0) {
        DAT_004fbac4 = DAT_0051359c;
      }
      DAT_004fbac8 = FUN_0041bc20(DAT_004fbac4 + 0xb4);
      DAT_005364b4 = 2;
    }
    if (DAT_005364fc == 1) {
      return;
    }
  }
  if (DAT_004da1f8 < 1) {
    if ((DAT_004da19c == 8) && (DAT_004da190 != 7)) {
      DAT_004da19c = 1;
    }
    iVar2 = DAT_004da19c;
    DAT_004f4510 = (uint)(DAT_004da19c == 0xb);
    if (DAT_004da19c == 7) {
      DAT_004da168 = 0;
      DAT_005363f8 = 0;
      DAT_0053640c = 0;
      DAT_004da1e8 = 0;
      DAT_0053527c = 0;
      if ((DAT_004da188 < 3) || (4 < DAT_004da188)) {
        DAT_004da188 = 3;
      }
    }
    DAT_004f8db8 = 0;
    if (0 < DAT_004da194) {
      puVar4 = &DAT_004fe2b4;
      for (iVar3 = DAT_004da194; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
    }
    DAT_0050040c = 0;
    DAT_004f7ed8 = 0;
    if ((DAT_0053640c == 1) || (iVar3 = 6, DAT_00536408 == 1)) {
      iVar3 = 5;
    }
    if (iVar2 == 0) {
      iVar2 = FUN_0041e000(iVar3);
      iVar2 = iVar2 + 1;
      DAT_004da19c = iVar2;
    }
    if ((iVar2 == 1) || (iVar2 == 3)) {
      DAT_004f7ed8 = 1;
      DAT_0050040c = 1;
    }
    if (iVar2 < 5) {
      DAT_004f69b8 = 0;
      DAT_004f8b78 = 0;
      DAT_005230dc = iVar2;
    }
    if (iVar2 == 5) {
      DAT_004f69b8 = 1;
      DAT_004f8b78 = 0;
      DAT_005230dc = 1;
    }
    if (iVar2 == 6) {
      DAT_0050040c = 0;
      DAT_004f69b8 = 5;
      DAT_005230dc = 1;
      DAT_004f8b78 = 0;
    }
    if (iVar2 == 7) {
      DAT_004f8b78 = 1;
      DAT_005230dc = 1;
      DAT_004f69b8 = 0;
      DAT_0053640c = 0;
      DAT_004da168 = 0;
      DAT_0053646c = 0;
    }
    if (iVar2 == 8) {
      DAT_005363f8 = 0;
      DAT_0053640c = 0;
      DAT_004f8db8 = 0;
      DAT_004f69b8 = 0;
      DAT_00536408 = 0;
      DAT_004da1e8 = 0;
      DAT_0053527c = 0;
      if (DAT_004f8b78 == 1) {
        DAT_004f8b78 = 1;
        DAT_005230dc = 1;
        DAT_0050040c = 0;
        DAT_004f7ed8 = 0;
        DAT_004da168 = 0;
        DAT_0053646c = 0;
        DAT_004da188 = 3;
      }
      else {
        DAT_004da188 = 1;
        DAT_0050040c = 1;
        DAT_004f7ed8 = 1;
        DAT_004f8b78 = 0;
        DAT_004da168 = 1;
        iVar2 = FUN_0041e000(10);
        DAT_005230dc = ((iVar2 < 6) - 1 & 2) + 1;
        iVar2 = DAT_004da19c;
      }
    }
    if (iVar2 == 9) {
      DAT_004f7ed8 = 0;
      DAT_0050040c = 0;
      DAT_005230dc = 1;
      DAT_004f69b8 = 6;
      DAT_004f8db8 = 0;
      DAT_004f8b78 = 0;
    }
    if (iVar2 == 10) {
      DAT_004f7ed8 = 0;
      DAT_0050040c = 0;
      DAT_005230dc = 3;
      DAT_004f69b8 = 7;
      DAT_004f8db8 = 0;
      DAT_004f8b78 = 0;
    }
    if (iVar2 == 0xb) {
      DAT_0050040c = 0;
      DAT_005230dc = 4;
      DAT_004f69b8 = 0;
      DAT_004f8b78 = 0;
      DAT_004f8db8 = 0;
    }
    if (iVar2 == 0xc) {
      DAT_004f69b8 = 2;
      DAT_004f8b78 = 0;
      DAT_005230dc = 4;
      DAT_0050040c = 0;
      DAT_004f8db8 = 0;
      DAT_004f7ed8 = 0;
    }
    if (iVar2 == 0xd) {
      DAT_004f69b8 = 3;
      DAT_004f8b78 = 0;
      DAT_005230dc = 4;
      DAT_0050040c = 0;
      DAT_004f8db8 = 0;
      DAT_004f7ed8 = 0;
    }
    if (iVar2 == 0xe) {
      DAT_004f69b8 = 4;
      DAT_004f8b78 = 0;
      DAT_005230dc = 4;
      DAT_0050040c = 0;
      DAT_004f8db8 = 0;
      DAT_004f7ed8 = 0;
    }
    if (1 < DAT_004f69b8) {
      FUN_00464a30();
      return;
    }
    if (DAT_005230dc == 1) {
      DAT_005229d0 = 0xfffffc4a;
      DAT_005127a4 = 1;
    }
    else {
      DAT_005229d0 = 0x3b6;
      DAT_005127a4 = 0xffffffff;
    }
    if (DAT_004f7ed8 == 1) {
      DAT_0050040c = 1;
      FUN_0042da80();
      iVar2 = DAT_004da19c;
    }
    if ((iVar2 == 2) || (iVar2 == 4)) {
      iVar2 = FUN_0041e000(2);
      _DAT_004fba00 = _DAT_004cc6b0 - (double)iVar2 * _DAT_004cc8b0;
      iVar2 = FUN_0041e000(2);
      _DAT_00535558 = _DAT_004cc468 - (double)iVar2 * _DAT_004cc8b0;
      FUN_0042d280();
      iVar2 = DAT_004da19c;
    }
    if (DAT_004f69b8 == 1) {
      iVar2 = FUN_0041e000(10);
      _DAT_004fba00 = _DAT_004cc600 - (double)iVar2 * _DAT_004cc8b0;
      iVar2 = FUN_0041e000(10);
      _DAT_00535558 = _DAT_004cc600 - (double)iVar2 * _DAT_004cc8b0;
      if ((DAT_0053527c == 1) && (DAT_005364c8 == 0)) {
        iVar2 = FUN_0041e000(10);
        _DAT_004fba00 = _DAT_004cc650 - (double)iVar2 * _DAT_004cc908;
        iVar2 = FUN_0041e000(10);
        _DAT_00535558 = _DAT_004cc650 - (double)iVar2 * _DAT_004cc908;
      }
      FUN_0042d280();
      iVar2 = DAT_004da19c;
    }
    if (DAT_004f8db8 == 1) {
      _DAT_004fba00 = 3.0;
      _DAT_00535558 = 1.0;
      FUN_0042d280();
      iVar2 = DAT_004da19c;
    }
    if (DAT_004f8b78 == 1) {
      _DAT_004fba00 = 0.5;
      if (iVar2 == 8) {
        _DAT_00535558 = 1.4;
      }
      else {
        _DAT_00535558 = 1.1;
      }
      FUN_0042d280();
    }
    DAT_005229c4 = DAT_005230dc * 0x5a;
    DAT_004fe160 = DAT_005229c4 + 0xb4;
    if (0x168 < DAT_004fe160) {
      DAT_004fe160 = DAT_005229c4 + -0xb4;
    }
    if (DAT_004f4510 == 1) {
      DAT_005230dc = 4;
      _DAT_004fba00 = 0.65;
      _DAT_00535558 = 1.5;
      FUN_0042d280();
    }
  }
  else {
    DAT_004da19c = 0;
    DAT_004f8b78 = 0;
    DAT_004f69b8 = 0;
    DAT_005364b4 = 0;
    if ((DAT_004da1f8 == 4) || (DAT_004fb5d4 = 0, DAT_004da1f8 == 5)) {
      DAT_004fb5d4 = 1;
    }
    if (DAT_004da1f8 == 1) {
      iVar3 = 1;
      DAT_00522f08 = 0x15;
      DAT_004fe764 = 0x11;
      DAT_00535498 = 0x11;
      DAT_004f69b8 = 0;
      DAT_005230dc = 1;
      DAT_00511374 = 0;
      DAT_00535e3c = 0;
      puVar4 = &DAT_004f45c8;
      iVar2 = 0;
      do {
        *puVar4 = 0;
        *(undefined4 *)((int)&DAT_00535314 + iVar2) = 0;
        *(undefined4 *)((int)&DAT_00535374 + iVar2) = 0x48;
        puVar4[1] = 0;
        FUN_004676f0(iVar3);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
        puVar4 = puVar4 + 2;
      } while (iVar3 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 4;
      DAT_004fbac4 = 0x14a;
      DAT_004fbac8 = 0x118;
      DAT_004fbacc = 0xb4;
      _DAT_004fbad0 = 0x50;
    }
    if (DAT_004da1f8 == 2) {
      DAT_00535498 = 0x13;
      DAT_00522f08 = 0x15;
      DAT_004fe764 = 0x15;
      DAT_00511374 = 0;
      DAT_00535e3c = 0;
      DAT_004f69b8 = 0;
      DAT_005230dc = 4;
      iVar3 = 1;
      puVar4 = &DAT_004f45c8;
      iVar2 = 0;
      do {
        *puVar4 = 0;
        *(undefined4 *)((int)&DAT_00535314 + iVar2) = 0;
        *(undefined4 *)((int)&DAT_00535374 + iVar2) = 0x48;
        puVar4[1] = 0;
        FUN_004711b0(iVar3);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
        puVar4 = puVar4 + 2;
      } while (iVar3 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 1;
      DAT_004fbac4 = 0x14a;
    }
    if (DAT_004da1f8 == 3) {
      iVar3 = 1;
      DAT_00522f08 = 0xf;
      DAT_004fe764 = 0xd;
      DAT_00535498 = 0xb;
      DAT_00511374 = 0;
      DAT_00535e3c = 0;
      DAT_004f69b8 = 0;
      DAT_005230dc = 1;
      puVar4 = &DAT_004f45c8;
      iVar2 = 0;
      do {
        *puVar4 = 0;
        *(undefined4 *)((int)&DAT_00535314 + iVar2) = 0;
        *(undefined4 *)((int)&DAT_00535374 + iVar2) = 0x48;
        puVar4[1] = 0;
        FUN_00471f40(iVar3);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
        puVar4 = puVar4 + 2;
      } while (iVar3 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 1;
      DAT_004fbac4 = 0x14;
    }
    if ((DAT_004da1f8 == 4) || (DAT_004da1f8 == 5)) {
      DAT_00522f08 = 7;
      DAT_004fe764 = 7;
      DAT_00535498 = 7;
      DAT_004f69b8 = 0;
      DAT_005230dc = 1;
      if (DAT_004da1f8 == 5) {
        DAT_0053527c = 0;
        DAT_004da1e8 = 0;
      }
      iVar3 = 1;
      DAT_00535e3c = 5;
      DAT_00511374 = 1;
      puVar4 = &DAT_004f45c8;
      iVar2 = 0;
      do {
        *puVar4 = 0;
        *(undefined4 *)((int)&DAT_00535314 + iVar2) = 0;
        *(undefined4 *)((int)&DAT_00535374 + iVar2) = 0x48;
        puVar4[1] = 0;
        FUN_004729d0(iVar3);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
        puVar4 = puVar4 + 2;
      } while (iVar3 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
    }
    if (DAT_004da1f8 == 6) {
      DAT_00522f08 = 0x12;
      DAT_004fe764 = 0xc;
      DAT_00535498 = 0xd;
      DAT_004f69b8 = 0;
      DAT_005230dc = 4;
      DAT_00511374 = 0;
      DAT_00535e3c = 0;
      iVar3 = 1;
      iVar2 = 0;
      do {
        *(undefined4 *)((int)&DAT_00535314 + iVar2) = 0;
        *(undefined4 *)((int)&DAT_00535374 + iVar2) = 0x48;
        FUN_004732c0(iVar3);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar3 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 3;
      DAT_004fbac4 = 0x14;
      DAT_004fbac8 = 0xb4;
      DAT_004fbacc = 300;
    }
    if (DAT_004da1f8 == 7) {
      iVar3 = 1;
      DAT_00522f08 = 0x12;
      DAT_004fe764 = 0x12;
      DAT_00535498 = 0xb;
      DAT_004f69b8 = 0;
      DAT_005230dc = 1;
      DAT_00511374 = 2;
      DAT_00535e3c = 0;
      puVar4 = &DAT_004f45c8;
      iVar2 = 0;
      do {
        *puVar4 = 0;
        *(undefined4 *)((int)&DAT_00535314 + iVar2) = 0;
        *(undefined4 *)((int)&DAT_00535374 + iVar2) = 0x48;
        puVar4[1] = 0;
        FUN_00473ed0(iVar3);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
        puVar4 = puVar4 + 2;
      } while (iVar3 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 2;
      DAT_004fbac4 = 0;
      DAT_004fbac8 = 0x96;
    }
    if (DAT_004da1f8 == 10) {
      iVar3 = 1;
      DAT_00522f08 = 0xe;
      DAT_004fe764 = 0xe;
      DAT_00535498 = 8;
      DAT_004f69b8 = 0;
      DAT_005230dc = 1;
      DAT_00511374 = 0;
      DAT_00535e3c = 0;
      iVar2 = 0;
      do {
        *(undefined4 *)((int)&DAT_00535314 + iVar2) = 0;
        *(undefined4 *)((int)&DAT_00535374 + iVar2) = 0x48;
        FUN_00474b60(iVar3);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar3 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 2;
      DAT_004fbac4 = 0x46;
      DAT_004fbac8 = 0x104;
    }
    if (DAT_004da1f8 == 9) {
      iVar3 = 1;
      DAT_00522f08 = 0xf;
      DAT_004fe764 = 0xe;
      DAT_00535498 = 10;
      DAT_004f69b8 = 0;
      DAT_005230dc = 1;
      DAT_00511374 = 0;
      DAT_00535e3c = 0;
      iVar2 = 0;
      do {
        *(undefined4 *)((int)&DAT_00535314 + iVar2) = 0;
        *(undefined4 *)((int)&DAT_00535374 + iVar2) = 0x48;
        FUN_004756c0(iVar3);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar3 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 3;
      DAT_004fbac4 = 0x136;
      DAT_004fbac8 = 10;
      DAT_004fbacc = 0x78;
    }
    if (DAT_004da1f8 == 0xc) {
      DAT_00522f08 = 0xe;
      DAT_00535498 = 8;
      DAT_004f69b8 = 0;
      DAT_005230dc = 4;
      DAT_00511374 = 0;
      DAT_00535e3c = 0;
      iVar3 = 1;
      iVar2 = 0;
      DAT_004fe764 = 0xc;
      do {
        *(undefined4 *)((int)&DAT_00535314 + iVar2) = 0;
        *(undefined4 *)((int)&DAT_00535374 + iVar2) = 0x48;
        FUN_004762a0(iVar3);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar3 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 2;
      DAT_004fbac4 = 0;
      DAT_004fbac8 = 0xaa;
    }
    if (DAT_004da1f8 == 0xb) {
      DAT_00522f08 = 0x10;
      DAT_004fe764 = 0x10;
      DAT_004f69b8 = 0;
      DAT_005230dc = 4;
      DAT_00511374 = 2;
      DAT_00535e3c = 0;
      iVar3 = 1;
      iVar2 = 0;
      DAT_00535498 = 0xb;
      do {
        *(undefined4 *)((int)&DAT_00535314 + iVar2) = 0;
        *(undefined4 *)((int)&DAT_00535374 + iVar2) = 0x48;
        FUN_00476db0(iVar3);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar3 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 2;
      DAT_004fbac4 = 0x19;
      DAT_004fbac8 = 200;
    }
    if (DAT_004da1f8 == 0x67) {
      iVar3 = 1;
      DAT_00522f08 = 0x10;
      DAT_004fe764 = 0xf;
      DAT_00535498 = 9;
      DAT_004f69b8 = 0;
      DAT_005230dc = 1;
      DAT_00511374 = 0;
      DAT_00535e3c = 0;
      iVar2 = 0;
      do {
        *(undefined4 *)((int)&DAT_00535314 + iVar2) = 0;
        *(undefined4 *)((int)&DAT_00535374 + iVar2) = 0x48;
        FUN_0047c240(iVar3);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar3 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 0;
    }
    if (DAT_004da1f8 == 0x69) {
      iVar3 = 1;
      DAT_00522f08 = 0xf;
      DAT_004fe764 = 0xf;
      DAT_00535498 = 9;
      DAT_004f69b8 = 0;
      DAT_005230dc = 1;
      DAT_00511374 = 3;
      DAT_00535e3c = 0;
      iVar2 = 0;
      do {
        *(undefined4 *)((int)&DAT_00535314 + iVar2) = 0;
        *(undefined4 *)((int)&DAT_00535374 + iVar2) = 0x48;
        FUN_0047b5d0(iVar3);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar3 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 0;
    }
    if (DAT_004da1f8 == 0x68) {
      DAT_00535498 = 10;
      DAT_00522f08 = 0xe;
      DAT_004fe764 = 0xe;
      DAT_004f69b8 = 0;
      DAT_005230dc = 2;
      DAT_00511374 = 0;
      DAT_00535e3c = 0;
      iVar2 = 1;
      iVar3 = 0;
      do {
        *(undefined4 *)((int)&DAT_00535314 + iVar3) = 0xffffffff;
        *(undefined4 *)((int)&DAT_00535374 + iVar3) = 0xffffffff;
        FUN_0047aa70(iVar2);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 4;
      } while (iVar2 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 0;
    }
    if (DAT_004da1f8 == 100) {
      iVar2 = 1;
      DAT_00522f08 = 0xe;
      DAT_004fe764 = 0xd;
      DAT_00535498 = 9;
      DAT_004f69b8 = 0;
      DAT_005230dc = 1;
      DAT_00511374 = 2;
      DAT_00535e3c = 0;
      iVar3 = 0;
      do {
        *(undefined4 *)((int)&DAT_00535314 + iVar3) = 0xffffffff;
        *(undefined4 *)((int)&DAT_00535374 + iVar3) = 0xffffffff;
        FUN_00479e00(iVar2);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 4;
      } while (iVar2 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 0;
    }
    if (DAT_004da1f8 == 0x65) {
      iVar2 = 1;
      DAT_00522f08 = 0xf;
      DAT_004fe764 = 0xf;
      DAT_00535498 = 0xc;
      DAT_004f69b8 = 0;
      DAT_005230dc = 1;
      DAT_00511374 = 2;
      DAT_00535e3c = 0;
      iVar3 = 0;
      do {
        *(undefined4 *)((int)&DAT_00535314 + iVar3) = 0xffffffff;
        *(undefined4 *)((int)&DAT_00535374 + iVar3) = 0xffffffff;
        FUN_00479120(iVar2);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 4;
      } while (iVar2 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 0;
    }
    if (DAT_004da1f8 == 0x66) {
      iVar2 = 1;
      DAT_00522f08 = 0xe;
      DAT_004fe764 = 0xd;
      DAT_00535498 = 10;
      DAT_004f69b8 = 0;
      DAT_005230dc = 1;
      DAT_00511374 = 2;
      DAT_00535e3c = 0;
      iVar3 = 0;
      do {
        *(undefined4 *)((int)&DAT_00535314 + iVar3) = 0xffffffff;
        *(undefined4 *)((int)&DAT_00535374 + iVar3) = 0xffffffff;
        FUN_00477b00(iVar2);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 4;
      } while (iVar2 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 0;
    }
    if (DAT_004da1f8 == 0x6a) {
      DAT_00535498 = 7;
      DAT_00522f08 = 0xb;
      DAT_004fe764 = 0xb;
      DAT_004f69b8 = 0;
      DAT_005230dc = 4;
      DAT_00511374 = 0;
      DAT_00535e3c = 0;
      iVar2 = 1;
      iVar3 = 0;
      do {
        *(undefined4 *)((int)&DAT_00535314 + iVar3) = 0xffffffff;
        *(undefined4 *)((int)&DAT_00535374 + iVar3) = 0xffffffff;
        FUN_00478760(iVar2);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 4;
      } while (iVar2 <= DAT_00535e3c + DAT_00511374 + DAT_00522f08);
      DAT_005364b4 = 0;
      return;
    }
  }
  return;
}

