
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041f0b0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((DAT_00491194 == 8) && (DAT_00491188 != 7)) {
    DAT_00491194 = 1;
  }
  iVar2 = DAT_00491194;
  DAT_004a4378 = (uint)(DAT_00491194 == 0xb);
  if (DAT_00491194 == 7) {
    DAT_00491160 = 0;
    DAT_004ac940 = 0;
    DAT_004ac954 = 0;
    if ((DAT_00491180 < 3) || (4 < DAT_00491180)) {
      DAT_00491180 = 3;
    }
  }
  DAT_004a5b9c = 0;
  if (0 < DAT_0049118c) {
    puVar4 = &DAT_004a72dc;
    for (iVar3 = DAT_0049118c; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
  }
  DAT_004a864c = 0;
  DAT_004a4ef0 = 0;
  if ((DAT_004ac954 == 1) || (uVar1 = 6, DAT_004ac950 == 1)) {
    uVar1 = 5;
  }
  if (iVar2 == 0) {
    iVar2 = FUN_00415a20(uVar1);
    iVar2 = iVar2 + 1;
    DAT_00491194 = iVar2;
  }
  if ((iVar2 == 1) || (iVar2 == 3)) {
    DAT_004a4ef0 = 1;
    DAT_004a864c = 1;
  }
  if (iVar2 < 5) {
    DAT_004a4958 = 0;
    DAT_004a5a4c = 0;
    DAT_004aa804 = iVar2;
  }
  if (iVar2 == 5) {
    DAT_004a4958 = 1;
    DAT_004a5a4c = 0;
    DAT_004aa804 = 1;
  }
  if (iVar2 == 6) {
    DAT_004a864c = 0;
    DAT_004a4958 = 5;
    DAT_004aa804 = 1;
    DAT_004a5a4c = 0;
  }
  if (iVar2 == 7) {
    DAT_004a5a4c = 1;
    DAT_004aa804 = 1;
    DAT_004a4958 = 0;
    DAT_004ac954 = 0;
    DAT_00491160 = 0;
    DAT_004ac9a8 = 0;
  }
  if (iVar2 == 8) {
    DAT_004ac940 = 0;
    DAT_004ac954 = 0;
    DAT_004a5b9c = 0;
    DAT_004a4958 = 0;
    DAT_004ac950 = 0;
    if (DAT_004a5a4c == 1) {
      DAT_004a5a4c = 1;
      DAT_004aa804 = 1;
      DAT_004a864c = 0;
      DAT_004a4ef0 = 0;
      DAT_00491160 = 0;
      DAT_004ac9a8 = 0;
      DAT_00491180 = 3;
    }
    else {
      DAT_00491180 = 1;
      DAT_004a864c = 1;
      DAT_004a4ef0 = 1;
      DAT_004a5a4c = 0;
      DAT_00491160 = 1;
      iVar2 = FUN_00415a20(10);
      DAT_004aa804 = ((iVar2 < 6) - 1 & 2) + 1;
      iVar2 = DAT_00491194;
    }
  }
  if (iVar2 == 9) {
    DAT_004a4ef0 = 0;
    DAT_004a864c = 0;
    DAT_004aa804 = 1;
    DAT_004a4958 = 6;
    DAT_004a5a4c = 0;
    DAT_004a5b9c = 0;
  }
  if (iVar2 == 10) {
    DAT_004a4ef0 = 0;
    DAT_004a864c = 0;
    DAT_004aa804 = 3;
    DAT_004a4958 = 7;
    DAT_004a5a4c = 0;
    DAT_004a5b9c = 0;
  }
  if (iVar2 == 0xb) {
    DAT_004a864c = 0;
    DAT_004aa804 = 4;
    DAT_004a4958 = 0;
    DAT_004a5a4c = 0;
    DAT_004a5b9c = 0;
  }
  if (iVar2 == 0xc) {
    DAT_004a4958 = 2;
    DAT_004a5a4c = 0;
    DAT_004aa804 = 4;
    DAT_004a864c = 0;
    DAT_004a5b9c = 0;
    DAT_004a4ef0 = 0;
  }
  if (iVar2 == 0xd) {
    DAT_004a4958 = 3;
    DAT_004a5a4c = 0;
    DAT_004aa804 = 4;
    DAT_004a864c = 0;
    DAT_004a5b9c = 0;
    DAT_004a4ef0 = 0;
  }
  if (iVar2 == 0xe) {
    DAT_004a4958 = 4;
    DAT_004a5a4c = 0;
    DAT_004aa804 = 4;
    DAT_004a864c = 0;
    DAT_004a5b9c = 0;
    DAT_004a4ef0 = 0;
  }
  if (DAT_004a4958 < 2) {
    if (DAT_004aa804 == 1) {
      DAT_004aa290 = 0xfffffc7c;
      DAT_004a8e8c = 1;
    }
    else {
      DAT_004aa290 = 900;
      DAT_004a8e8c = 0xffffffff;
    }
    if (DAT_004a4ef0 == 1) {
      DAT_004a864c = 1;
      FUN_0041fd90();
      iVar2 = DAT_00491194;
    }
    if ((iVar2 == 2) || (iVar2 == 4)) {
      iVar2 = FUN_00415a20(2);
      _DAT_004a6470 = _DAT_00484fe0 - (double)iVar2 * _DAT_00485060;
      iVar2 = FUN_00415a20(2);
      _DAT_004abe60 = _DAT_00484ed0 - (double)iVar2 * _DAT_00485060;
      FUN_0041f5b0();
      iVar2 = DAT_00491194;
    }
    if (DAT_004a4958 == 1) {
      iVar2 = FUN_00415a20(10);
      _DAT_004a6470 = _DAT_00484ec8 - (double)iVar2 * _DAT_00485060;
      iVar2 = FUN_00415a20(10);
      _DAT_004abe60 = _DAT_00484ec8 - (double)iVar2 * _DAT_00485060;
      FUN_0041f5b0();
      iVar2 = DAT_00491194;
    }
    if (DAT_004a5b9c == 1) {
      _DAT_004a6470 = 3.0;
      _DAT_004abe60 = 1.0;
      FUN_0041f5b0();
      iVar2 = DAT_00491194;
    }
    if (DAT_004a5a4c == 1) {
      _DAT_004a6470 = 0.5;
      if (iVar2 == 8) {
        _DAT_004abe60 = 1.4;
      }
      else {
        _DAT_004abe60 = 1.1;
      }
      FUN_0041f5b0();
    }
    DAT_004aa284 = DAT_004aa804 * 0x5a;
    DAT_004a71a8 = DAT_004aa284 + 0xb4;
    if (0x168 < DAT_004a71a8) {
      DAT_004a71a8 = DAT_004aa284 + -0xb4;
    }
    if (DAT_004a4378 == 1) {
      DAT_004aa804 = 4;
      _DAT_004a6470 = 0.65;
      _DAT_004abe60 = 1.5;
      FUN_0041f5b0();
    }
    return;
  }
  FUN_0044e470();
  return;
}

