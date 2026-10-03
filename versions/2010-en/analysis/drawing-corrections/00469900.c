
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00469900(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  Tact2010CString *pTVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  bool bVar7;
  int aiStack_14 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  iVar3 = param_4;
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c5978;
  *unaff_FS_OFFSET = &uStack_c;
  iVar6 = DAT_004fe624;
  if (0 < param_3) {
    iVar5 = 0x49;
    iVar1 = DAT_004fe2a8 * 2;
    iVar2 = param_2 * 0x124;
    do {
      if (iVar1 < *(int *)(&DAT_004fc470 + iVar2)) {
        *(int *)(&DAT_004fc470 + iVar2) = iVar1;
      }
      if (*(int *)(&DAT_004f4e50 + iVar2) < -iVar6) {
        *(int *)(&DAT_004f4e50 + iVar2) = -iVar6;
      }
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (param_4 == 0) {
    if (DAT_00536450 == 0) {
      FUN_00484270(param_1);
      if ((DAT_004fb5d4 == 1) && ((param_2 == 5 || (param_2 == 7)))) {
        if (DAT_004fe174 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004fe174);
        }
        if (DAT_004fe07c != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004fe07c);
        }
      }
      if ((DAT_004da1f8 == 2) &&
         ((((param_2 == 1 || (param_2 == 2)) || (param_2 == 6)) ||
          ((param_2 == 9 || (param_2 == 0xc)))))) {
        if (DAT_004fe174 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004fe174);
        }
        if (DAT_004fe07c != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004fe07c);
        }
      }
      if ((DAT_004da1f8 == 0xc) && (param_2 < 3)) {
        if (DAT_004fe174 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004fe174);
        }
        if (DAT_004fe07c != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004fe07c);
        }
      }
      if (((DAT_004da1f8 == 0x68) && (param_2 == 1)) && (0 < param_3)) {
        if (DAT_004fe174 != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004fe174);
        }
        if (DAT_004fe07c != (HGDIOBJ)0x0) {
          SelectObject((HDC)param_1[1],DAT_004fe07c);
        }
      }
    }
    if (DAT_00536450 == 1) {
      if (DAT_004fe174 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe174);
      }
      if (DAT_004fe07c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe07c);
      }
    }
  }
  if (iVar3 == 1) {
    if (DAT_004fb244 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fb244);
    }
    if ((DAT_004da1f8 == 2) &&
       (((param_2 == 1 || (param_2 == 2)) ||
        ((param_2 == 6 || ((param_2 == 9 || (param_2 == 0xc)))))))) {
      if (DAT_004fe174 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe174);
      }
      if (DAT_004fe07c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe07c);
      }
    }
    if ((DAT_004fb5d4 == 1) && ((param_2 == 5 || (param_2 == 7)))) {
      if (DAT_004fe174 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe174);
      }
      if (DAT_004fe07c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe07c);
      }
    }
    if ((DAT_004da1f8 == 0xc) && (param_2 < 3)) {
      if (DAT_004fe174 != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe174);
      }
      if (DAT_004fe07c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004fe07c);
      }
    }
  }
  bVar7 = false;
  if (param_3 == 0) {
    if (((*(int *)(&DAT_00535310 + param_2 * 4) < 1) &&
        (0x47 < *(int *)(&DAT_00535370 + param_2 * 4))) || (DAT_005364b0 < 1)) {
      (**(code **)(*param_1 + 0x2c))(param_1,8);
    }
    else if (DAT_004fb994 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fb994);
    }
    bVar7 = param_3 == 0;
  }
  if (!bVar7 && -1 < param_3) {
    FUN_00484270(param_1);
  }
  if ((((DAT_004fb5d4 == 1) && ((param_2 == 5 || (param_2 == 7)))) && (0 < param_3)) &&
     (DAT_004fe174 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004fe174);
  }
  if ((DAT_004da1f8 == 2) && (param_2 == 1)) {
    if (DAT_004fe07c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
    if (DAT_004fe174 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe174);
    }
  }
  if ((DAT_004da1f8 == 0xc) && (param_2 < 3)) {
    if (DAT_004fe174 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe174);
    }
    if (DAT_004fe07c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
  }
  if (((DAT_004da1f8 == 0x68) && (param_2 == 1)) && (0 < param_3)) {
    if (DAT_004fe174 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe174);
    }
    if (DAT_004fe07c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
  }
  if (((DAT_004da1f8 == 0x65) && (param_2 == 1)) && (0 < param_3)) {
    if (DAT_004fe174 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe174);
    }
    if (DAT_004fe07c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
  }
  if (((DAT_005364b0 == 1) && (param_3 == 0)) && (DAT_005233b4 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_005233b4);
  }
  if (DAT_00536450 == 1) {
    bVar7 = param_3 == 0;
    if (!bVar7) goto LAB_00469e4d;
    (**(code **)(*param_1 + 0x2c))(param_1,8);
    if (DAT_004fe07c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
  }
  bVar7 = param_3 == 0;
LAB_00469e4d:
  if (!bVar7 && -1 < param_3) {
    if (DAT_00536450 == 1) {
      (**(code **)(*param_1 + 0x2c))(param_1,7);
    }
    else if (DAT_004f4a4c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004f4a4c);
    }
  }
  if (DAT_005363e4 == 1) {
    (**(code **)(*param_1 + 0x2c))(param_1,7);
    if (DAT_004fe07c != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
  }
  iVar6 = param_2 * 0x124;
  _DAT_004f6e30 = *(undefined4 *)(&DAT_004f4e54 + iVar6);
  _DAT_004f6e28 = *(undefined4 *)(&DAT_004f4e50 + iVar6);
  _DAT_004f6e34 = *(undefined4 *)(&DAT_004fc474 + iVar6);
  _DAT_004f6e38 = *(undefined4 *)(&DAT_004f4e58 + iVar6);
  _DAT_004f6e3c = *(undefined4 *)(&DAT_004fc478 + iVar6);
  _DAT_004f6e40 = *(undefined4 *)(&DAT_004f4e5c + iVar6);
  _DAT_004f6e44 = *(undefined4 *)(&DAT_004fc47c + iVar6);
  _DAT_004f6e48 = *(undefined4 *)(&DAT_004f4e60 + iVar6);
  _DAT_004f6e4c = *(undefined4 *)(&DAT_004fc480 + iVar6);
  _DAT_004f6e50 = *(undefined4 *)(&DAT_004f4e64 + iVar6);
  _DAT_004f6e54 = *(undefined4 *)(&DAT_004fc484 + iVar6);
  _DAT_004f6e58 = *(undefined4 *)(&DAT_004f4e68 + iVar6);
  _DAT_004f6e5c = *(undefined4 *)(&DAT_004fc488 + iVar6);
  _DAT_004f6e60 = *(undefined4 *)(&DAT_004f4e6c + iVar6);
  _DAT_004f6e64 = *(undefined4 *)(&DAT_004fc48c + iVar6);
  _DAT_004f6e68 = *(undefined4 *)(&DAT_004f4e70 + iVar6);
  _DAT_004f6e6c = *(undefined4 *)(&DAT_004fc490 + iVar6);
  _DAT_004f6e70 = *(undefined4 *)(&DAT_004f4e74 + iVar6);
  _DAT_004f6e74 = *(undefined4 *)(&DAT_004fc494 + iVar6);
  _DAT_004f6e78 = *(undefined4 *)(&DAT_004f4e78 + iVar6);
  _DAT_004f6e7c = *(undefined4 *)(&DAT_004fc498 + iVar6);
  _DAT_004f6e80 = *(undefined4 *)(&DAT_004f4e7c + iVar6);
  _DAT_004f6e84 = *(undefined4 *)(&DAT_004fc49c + iVar6);
  _DAT_004f6e88 = *(undefined4 *)(&DAT_004f4e80 + iVar6);
  _DAT_004f6e8c = *(undefined4 *)(&DAT_004fc4a0 + iVar6);
  _DAT_004f6e90 = *(undefined4 *)(&DAT_004f4e84 + iVar6);
  _DAT_004f6e94 = *(undefined4 *)(&DAT_004fc4a4 + iVar6);
  _DAT_004f6e98 = *(undefined4 *)(&DAT_004f4e88 + iVar6);
  _DAT_004f6e9c = *(undefined4 *)(&DAT_004fc4a8 + iVar6);
  _DAT_004f6ea0 = *(undefined4 *)(&DAT_004f4e8c + iVar6);
  _DAT_004f6ea4 = *(undefined4 *)(&DAT_004fc4ac + iVar6);
  _DAT_004f6ea8 = *(undefined4 *)(&DAT_004f4e90 + iVar6);
  _DAT_004f6eac = *(undefined4 *)(&DAT_004fc4b0 + iVar6);
  _DAT_004f6eb0 = *(undefined4 *)(&DAT_004f4e94 + iVar6);
  _DAT_004f6eb4 = *(undefined4 *)(&DAT_004fc4b4 + iVar6);
  _DAT_004f6e2c = *(undefined4 *)(&DAT_004fc470 + iVar6);
  _DAT_004f6eb8 = *(undefined4 *)(&DAT_004f4e98 + iVar6);
  _DAT_004f6ebc = *(undefined4 *)(&DAT_004fc4b8 + iVar6);
  _DAT_004f6ec0 = *(undefined4 *)(&DAT_004f4e9c + iVar6);
  _DAT_004f6ec4 = *(undefined4 *)(&DAT_004fc4bc + iVar6);
  _DAT_004f6ec8 = *(undefined4 *)(&DAT_004f4ea0 + iVar6);
  _DAT_004f6ecc = *(undefined4 *)(&DAT_004fc4c0 + iVar6);
  _DAT_004f6ed0 = *(undefined4 *)(&DAT_004f4ea4 + iVar6);
  _DAT_004f6ed4 = *(undefined4 *)(&DAT_004fc4c4 + iVar6);
  _DAT_004f6ed8 = *(undefined4 *)(&DAT_004f4ea8 + iVar6);
  _DAT_004f6edc = *(undefined4 *)(&DAT_004fc4c8 + iVar6);
  _DAT_004f6ee0 = *(undefined4 *)(&DAT_004f4eac + iVar6);
  _DAT_004f6ee4 = *(undefined4 *)(&DAT_004fc4cc + iVar6);
  _DAT_004f6ee8 = *(undefined4 *)(&DAT_004f4eb0 + iVar6);
  _DAT_004f6eec = *(undefined4 *)(&DAT_004fc4d0 + iVar6);
  _DAT_004f6ef0 = *(undefined4 *)(&DAT_004f4eb4 + iVar6);
  _DAT_004f6ef4 = *(undefined4 *)(&DAT_004fc4d4 + iVar6);
  _DAT_004f6ef8 = *(undefined4 *)(&DAT_004f4eb8 + iVar6);
  _DAT_004f6efc = *(undefined4 *)(&DAT_004fc4d8 + iVar6);
  _DAT_004f6f00 = *(undefined4 *)(&DAT_004f4ebc + iVar6);
  _DAT_004f6f04 = *(undefined4 *)(&DAT_004fc4dc + iVar6);
  _DAT_004f6f08 = *(undefined4 *)(&DAT_004f4ec0 + iVar6);
  _DAT_004f6f0c = *(undefined4 *)(&DAT_004fc4e0 + iVar6);
  _DAT_004f6f10 = *(undefined4 *)(&DAT_004f4ec4 + iVar6);
  _DAT_004f6f14 = *(undefined4 *)(&DAT_004fc4e4 + iVar6);
  _DAT_004f6f18 = *(undefined4 *)(&DAT_004f4ec8 + iVar6);
  _DAT_004f6f1c = *(undefined4 *)(&DAT_004fc4e8 + iVar6);
  _DAT_004f6f20 = *(undefined4 *)(&DAT_004f4ecc + iVar6);
  _DAT_004f6f24 = *(undefined4 *)(&DAT_004fc4ec + iVar6);
  _DAT_004f6f28 = *(undefined4 *)(&DAT_004f4ed0 + iVar6);
  _DAT_004f6f2c = *(undefined4 *)(&DAT_004fc4f0 + iVar6);
  _DAT_004f6f30 = *(undefined4 *)(&DAT_004f4ed4 + iVar6);
  _DAT_004f6f34 = *(undefined4 *)(&DAT_004fc4f4 + iVar6);
  _DAT_004f6f38 = *(undefined4 *)(&DAT_004f4ed8 + iVar6);
  _DAT_004f6f3c = *(undefined4 *)(&DAT_004fc4f8 + iVar6);
  _DAT_004f6f40 = *(undefined4 *)(&DAT_004f4edc + iVar6);
  _DAT_004f6f44 = *(undefined4 *)(&DAT_004fc4fc + iVar6);
  _DAT_004f6f48 = *(undefined4 *)(&DAT_004f4ee0 + iVar6);
  _DAT_004f6f4c = *(undefined4 *)(&DAT_004fc500 + iVar6);
  _DAT_004f6f50 = *(undefined4 *)(&DAT_004f4ee4 + iVar6);
  _DAT_004f6f54 = *(undefined4 *)(&DAT_004fc504 + iVar6);
  _DAT_004f6f58 = *(undefined4 *)(&DAT_004f4ee8 + iVar6);
  _DAT_004f6f5c = *(undefined4 *)(&DAT_004fc508 + iVar6);
  _DAT_004f6f60 = *(undefined4 *)(&DAT_004f4eec + iVar6);
  _DAT_004f6f64 = *(undefined4 *)(&DAT_004fc50c + iVar6);
  _DAT_004f6f68 = *(undefined4 *)(&DAT_004f4ef0 + iVar6);
  _DAT_004f6f6c = *(undefined4 *)(&DAT_004fc510 + iVar6);
  _DAT_004f6f70 = *(undefined4 *)(&DAT_004f4ef4 + iVar6);
  _DAT_004f6f74 = *(undefined4 *)(&DAT_004fc514 + iVar6);
  _DAT_004f6f78 = *(undefined4 *)(&DAT_004f4ef8 + iVar6);
  _DAT_004f6f7c = *(undefined4 *)(&DAT_004fc518 + iVar6);
  _DAT_004f6f80 = *(undefined4 *)(&DAT_004f4efc + iVar6);
  _DAT_004f6f84 = *(undefined4 *)(&DAT_004fc51c + iVar6);
  _DAT_004f6f88 = *(undefined4 *)(&DAT_004f4f00 + iVar6);
  _DAT_004f6f8c = *(undefined4 *)(&DAT_004fc520 + iVar6);
  _DAT_004f6f90 = *(undefined4 *)(&DAT_004f4f04 + iVar6);
  _DAT_004f6f94 = *(undefined4 *)(&DAT_004fc524 + iVar6);
  _DAT_004f6f98 = *(undefined4 *)(&DAT_004f4f08 + iVar6);
  _DAT_004f6f9c = *(undefined4 *)(&DAT_004fc528 + iVar6);
  _DAT_004f6fa0 = *(undefined4 *)(&DAT_004f4f0c + iVar6);
  _DAT_004f6fa4 = *(undefined4 *)(&DAT_004fc52c + iVar6);
  _DAT_004f6fa8 = *(undefined4 *)(&DAT_004f4f10 + iVar6);
  _DAT_004f6fac = *(undefined4 *)(&DAT_004fc530 + iVar6);
  _DAT_004f6fb0 = *(undefined4 *)(&DAT_004f4f14 + iVar6);
  _DAT_004f6fb4 = *(undefined4 *)(&DAT_004fc534 + iVar6);
  _DAT_004f6fb8 = *(undefined4 *)(&DAT_004f4f18 + iVar6);
  _DAT_004f6fbc = *(undefined4 *)(&DAT_004fc538 + iVar6);
  _DAT_004f6fc0 = *(undefined4 *)(&DAT_004f4f1c + iVar6);
  _DAT_004f6fc4 = *(undefined4 *)(&DAT_004fc53c + iVar6);
  _DAT_004f6fc8 = *(undefined4 *)(&DAT_004f4f20 + iVar6);
  _DAT_004f6fcc = *(undefined4 *)(&DAT_004fc540 + iVar6);
  _DAT_004f6fd0 = *(undefined4 *)(&DAT_004f4f24 + iVar6);
  _DAT_004f6fd4 = *(undefined4 *)(&DAT_004fc544 + iVar6);
  _DAT_004f6fd8 = *(undefined4 *)(&DAT_004f4f28 + iVar6);
  _DAT_004f6fdc = *(undefined4 *)(&DAT_004fc548 + iVar6);
  _DAT_004f6fe0 = *(undefined4 *)(&DAT_004f4f2c + iVar6);
  _DAT_004f6fe4 = *(undefined4 *)(&DAT_004fc54c + iVar6);
  _DAT_004f6fe8 = *(undefined4 *)(&DAT_004f4f30 + iVar6);
  _DAT_004f6fec = *(undefined4 *)(&DAT_004fc550 + iVar6);
  _DAT_004f6ff0 = *(undefined4 *)(&DAT_004f4f34 + iVar6);
  _DAT_004f6ff4 = *(undefined4 *)(&DAT_004fc554 + iVar6);
  _DAT_004f6ff8 = *(undefined4 *)(&DAT_004f4f38 + iVar6);
  _DAT_004f6ffc = *(undefined4 *)(&DAT_004fc558 + iVar6);
  _DAT_004f7000 = *(undefined4 *)(&DAT_004f4f3c + iVar6);
  _DAT_004f7004 = *(undefined4 *)(&DAT_004fc55c + iVar6);
  _DAT_004f7008 = *(undefined4 *)(&DAT_004f4f40 + iVar6);
  _DAT_004f700c = *(undefined4 *)(&DAT_004fc560 + iVar6);
  _DAT_004f7010 = *(undefined4 *)(&DAT_004f4f44 + iVar6);
  _DAT_004f7014 = *(undefined4 *)(&DAT_004fc564 + iVar6);
  _DAT_004f7018 = *(undefined4 *)(&DAT_004f4f48 + iVar6);
  _DAT_004f701c = *(undefined4 *)(&DAT_004fc568 + iVar6);
  _DAT_004f7020 = *(undefined4 *)(&DAT_004f4f4c + iVar6);
  _DAT_004f7024 = *(undefined4 *)(&DAT_004fc56c + iVar6);
  _DAT_004f7028 = *(undefined4 *)(&DAT_004f4f50 + iVar6);
  _DAT_004f702c = *(undefined4 *)(&DAT_004fc570 + iVar6);
  _DAT_004f7030 = *(undefined4 *)(&DAT_004f4f54 + iVar6);
  _DAT_004f7034 = *(undefined4 *)(&DAT_004fc574 + iVar6);
  _DAT_004f7038 = *(undefined4 *)(&DAT_004f4f58 + iVar6);
  _DAT_004f703c = *(undefined4 *)(&DAT_004fc578 + iVar6);
  _DAT_004f7040 = *(undefined4 *)(&DAT_004f4f5c + iVar6);
  _DAT_004f7044 = *(undefined4 *)(&DAT_004fc57c + iVar6);
  _DAT_004f7048 = *(undefined4 *)(&DAT_004f4f60 + iVar6);
  _DAT_004f704c = *(undefined4 *)(&DAT_004fc580 + iVar6);
  _DAT_004f7050 = *(undefined4 *)(&DAT_004f4f64 + iVar6);
  _DAT_004f7054 = *(undefined4 *)(&DAT_004fc584 + iVar6);
  _DAT_004f7058 = *(undefined4 *)(&DAT_004f4f68 + iVar6);
  _DAT_004f705c = *(undefined4 *)(&DAT_004fc588 + iVar6);
  _DAT_004f7060 = *(undefined4 *)(&DAT_004f4f6c + iVar6);
  _DAT_004f7064 = *(undefined4 *)(&DAT_004fc58c + iVar6);
  _DAT_004f7068 = _DAT_004f6e28;
  _DAT_004f706c = _DAT_004f6e2c;
  Polygon((HDC)param_1[1],(POINT *)&DAT_004f6e28,0x49);
  if ((param_3 == 0) && (DAT_005364b0 == 1)) {
    if (DAT_004fb994 != (HGDIOBJ)0x0) {
      SelectObject((HDC)param_1[1],DAT_004fb994);
    }
    FUN_004b4d9d(param_1,aiStack_14,
                 (*(int *)(&DAT_004f4e54 + iVar6) + *(int *)(&DAT_004f4ee4 + iVar6)) / 2,
                 (*(int *)(&DAT_004fc474 + iVar6) + *(int *)(&DAT_004fc504 + iVar6)) / 2);
    CDC::LineTo(param_1,*(int *)(&DAT_004f4e50 + iVar6),*(int *)(&DAT_004fc470 + iVar6));
    iVar3 = *(int *)(&DAT_00535310 + param_2 * 4);
    FUN_0046a700(param_1);
    iVar3 = (iVar3 + param_2 * 0x49) * 4;
    FUN_00433a70(param_1,6,*(undefined4 *)(&DAT_004f4e50 + iVar3),
                 *(undefined4 *)(&DAT_004fc470 + iVar3));
    iVar3 = *(int *)(&DAT_00535370 + param_2 * 4);
    FUN_00469650(param_1);
    iVar3 = (iVar3 + param_2 * 0x49) * 4;
    FUN_00433a70(param_1,6,*(undefined4 *)(&DAT_004f4e50 + iVar3),
                 *(undefined4 *)(&DAT_004fc470 + iVar3));
    FUN_004b4a1f(param_1,1);
    pTVar4 = FUN_0041bc70((Tact2010CString *)&param_3,param_2);
    uStack_4 = 0;
    (**(code **)(*param_1 + 100))
              (param_1,(*(int *)(&DAT_004f4e54 + iVar6) + *(int *)(&DAT_004f4ee4 + iVar6)) / 2,
               (*(int *)(&DAT_004fc474 + iVar6) + *(int *)(&DAT_004fc504 + iVar6)) / 2,pTVar4->data,
               *(int *)(pTVar4->data + -8));
    uStack_4 = 0xffffffff;
    FUN_004b05a5((Tact2010CString *)&param_3);
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}

