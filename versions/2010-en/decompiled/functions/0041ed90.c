
void __cdecl FUN_0041ed90(int *param_1,int param_2)

{
  HDC pHVar1;
  HGDIOBJ pvVar2;
  
  if (DAT_005363e4 == 0) {
    if (param_2 == 0) {
      (**(code **)(*param_1 + 0x2c))(param_1,0);
    }
    if (param_2 == 1) {
      if ((((DAT_00513478 == 1) || (DAT_005364d4 == 1)) || (DAT_005363c0 == 1)) ||
         (DAT_005363c0 == 3)) {
        if (DAT_005359fc != (HGDIOBJ)0x0) {
          pHVar1 = (HDC)param_1[1];
          pvVar2 = DAT_005359fc;
          goto override_prt_41ee18_6059bb06;
        }
      }
      else if (DAT_004f3864 != (HGDIOBJ)0x0) {
        pHVar1 = (HDC)param_1[1];
        pvVar2 = DAT_004f3864;
override_prt_41ee18_6059bb06:
        SelectObject(pHVar1,pvVar2);
      }
    }
    if ((param_2 == 2) && (DAT_005233b4 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005233b4);
    }
    if ((((param_2 == 3) || (param_2 == 0xc)) || (param_2 == 0x15)) &&
       (DAT_004fb25c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004fb25c);
    }
    if ((((param_2 == 4) || (param_2 == 0xd)) || (param_2 == 0x16)) &&
       (DAT_004fe07c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
    if ((((param_2 == 5) || (param_2 == 0xe)) || (param_2 == 0x17)) &&
       (DAT_004f7f74 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004f7f74);
    }
    if ((((param_2 == 6) || (param_2 == 0xf)) || (param_2 == 0x18)) &&
       (DAT_004ff034 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004ff034);
    }
    if ((((param_2 == 7) || (param_2 == 0x10)) || (param_2 == 0x19)) &&
       (DAT_004f41ec != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004f41ec);
    }
    if ((((param_2 == 8) || (param_2 == 0x11)) || (param_2 == 0x1a)) &&
       (DAT_004fb6ac != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004fb6ac);
    }
    if ((((param_2 == 9) || (param_2 == 0x12)) || (param_2 == 0x1b)) &&
       (DAT_004fb244 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004fb244);
    }
    if ((((param_2 == 10) || (param_2 == 0x13)) || (param_2 == 0x1c)) &&
       (DAT_004f4d6c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004f4d6c);
    }
    if ((((param_2 == 0xb) || (param_2 == 0x14)) || (0x1c < param_2)) &&
       (DAT_005125f4 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_005125f4);
    }
    if ((param_2 == 0x1f) && (DAT_004fb25c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004fb25c);
    }
    if ((param_2 == 0x20) && (DAT_004f3864 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004f3864);
    }
    if ((param_2 == 0x21) && (DAT_004f7f74 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004f7f74);
    }
    if ((param_2 == 0x22) && (DAT_004ff034 != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004ff034);
    }
    if ((DAT_00536518 == 0) && ((DAT_005363c8 == 1 || (DAT_004fb410 == 1)))) {
      if (param_2 == 1) {
        (**(code **)(*param_1 + 0x2c))(param_1,0);
      }
      else if (DAT_004f3f5c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f3f5c);
      }
    }
  }
  if (DAT_00536450 != 1) goto LAB_0041f0f3;
  if (param_2 == 1) {
    if (DAT_004fb6ac != (HGDIOBJ)0x0) {
      pHVar1 = (HDC)param_1[1];
      pvVar2 = DAT_004fb6ac;
override_prt_41f0c8_6059bb06:
      SelectObject(pHVar1,pvVar2);
    }
  }
  else if (DAT_004fe07c != (HGDIOBJ)0x0) {
    pHVar1 = (HDC)param_1[1];
    pvVar2 = DAT_004fe07c;
    goto override_prt_41f0c8_6059bb06;
  }
  if (((param_2 == 2) && (DAT_004da140 == 2)) && (DAT_004fb244 != (HGDIOBJ)0x0)) {
    SelectObject((HDC)param_1[1],DAT_004fb244);
  }
LAB_0041f0f3:
  if (DAT_005363e4 == 1) {
    if ((param_2 == 1) && (DAT_004fe07c != (HGDIOBJ)0x0)) {
      SelectObject((HDC)param_1[1],DAT_004fe07c);
    }
    if (1 < param_2) {
      (**(code **)(*param_1 + 0x2c))(param_1,4);
    }
  }
  return;
}

