
/* WARNING: Function: __ftol replaced with injection: tact_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00412810(CDC *param_1,undefined4 param_2,int param_3,int param_4)

{
  CDC *this;
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  
  this = param_1;
  pcVar3 = SelectObject_exref;
  _DAT_004a4ca8 = DAT_004aa1b4;
  _DAT_004a4cac = DAT_004aa2b4;
  _DAT_004a4cb4 = DAT_004aa2c8;
  _DAT_004a4cb0 = DAT_004aa1c8;
  _DAT_004a4cc0 = DAT_004aa1c0;
  _DAT_004a4cb8 = DAT_004aa1c4;
  _DAT_004a4ccc = DAT_004aa2bc;
  _DAT_004a4cbc = DAT_004aa2c4;
  _DAT_004a4cd8 = DAT_004aa1e0;
  _DAT_004a4cc4 = DAT_004aa2c0;
  _DAT_004a4cc8 = DAT_004aa1bc;
  _DAT_004a4ce4 = DAT_004aa2dc;
  _DAT_004a4cd0 = DAT_004aa1b8;
  _DAT_004a4cd4 = DAT_004aa2b8;
  _DAT_004a4cf0 = DAT_004aa1d4;
  _DAT_004a4cdc = DAT_004aa2e0;
  _DAT_004a4ce0 = DAT_004aa1dc;
  _DAT_004a4cfc = DAT_004aa2d0;
  _DAT_004a4ce8 = DAT_004aa1d8;
  _DAT_004a4cec = DAT_004aa2d8;
  _DAT_004a4cf4 = DAT_004aa2d4;
  _DAT_004a4cf8 = DAT_004aa1d0;
  if ((DAT_004ac92c == 0) && (DAT_004ac910 == 0)) {
    if (DAT_004a4f7c != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(param_1 + 4),DAT_004a4f7c);
    }
  }
  else {
    (**(code **)(*(int *)param_1 + 0x2c))(0);
    pcVar3 = SelectObject_exref;
  }
  iVar1 = param_4;
  if ((DAT_00491140 < param_4) && (DAT_004a3efc != 0)) {
    (*pcVar3)(*(undefined4 *)(this + 4),DAT_004a3efc);
  }
  if ((DAT_004ac98c == 1) && (DAT_004a3efc != 0)) {
    (*pcVar3)(*(undefined4 *)(this + 4),DAT_004a3efc);
  }
  (**(code **)(*(int *)this + 0x2c))(7);
  if ((((DAT_004ac92c == 0) && (DAT_004ac910 == 1)) && (iVar1 == 1)) && (DAT_004ac854 != 0)) {
    (*pcVar3)(*(undefined4 *)(this + 4),DAT_004ac854);
  }
  Polygon(*(HDC *)(this + 4),(POINT *)&DAT_004a4ca8,0xb);
  iVar5 = param_4;
  if (((DAT_00491188 != 4) && (DAT_004ac90c != 1)) &&
     ((DAT_004ac914 != 1 && (DAT_004ac13c < param_4)))) {
    FUN_0041a450((int *)this,iVar1);
  }
  if (iVar1 == 0) {
    return;
  }
  if (DAT_00491188 < 7) {
    if (DAT_00491188 != 4) {
      if (((DAT_004a7354 < iVar5) && (0 < iVar1)) && ((DAT_00491188 != 3 && (1 < DAT_00491188)))) {
        if (DAT_004aa634 != (HGDIOBJ)0x0) {
          (*pcVar3)(*(undefined4 *)(this + 4),DAT_004aa634);
        }
        FUN_004706bd(this,(int *)&stack0xfffffff4,(DAT_004aa1ac + DAT_004aa1d4 * 2) / 3,
                     (DAT_004aa2ac + DAT_004aa2d4 * 2) / 3);
        CDC::LineTo(this,(DAT_004aa1b0 + DAT_004aa1ac) / 2,(DAT_004aa2b0 + DAT_004aa2ac) / 2);
        CDC::LineTo(this,(DAT_004aa1ac + DAT_004aa1c4 * 2) / 3,(DAT_004aa2ac + DAT_004aa2c4 * 2) / 3
                   );
      }
      goto LAB_00412b4b;
    }
  }
  else {
LAB_00412b4b:
    if ((DAT_00491188 != 4) && (DAT_004ac90c != 1)) goto LAB_00412ba2;
  }
  if (DAT_004aa634 != (HGDIOBJ)0x0) {
    (*pcVar3)(*(undefined4 *)(this + 4),DAT_004aa634);
  }
  FUN_004706bd(this,(int *)&stack0xfffffff4,DAT_004aa1c4,DAT_004aa2c4);
  CDC::LineTo(this,DAT_004aa1d4,DAT_004aa2d4);
LAB_00412ba2:
  if ((DAT_004ac908 == 1) || (DAT_004ac90c == 1)) {
    if (DAT_004a4dec != 0) {
      (*pcVar3)(*(undefined4 *)(this + 4),DAT_004a4dec);
    }
    iVar1 = DAT_004aa2b4 - DAT_004aa2ac;
    iVar5 = DAT_004aa1b4 - DAT_004aa1ac;
    if (DAT_004ac908 == 1) {
      if (*(int *)(&DAT_004abb70 + param_3 * 4) == 1) {
        DAT_004aaeb0 = iVar5 / 2 + DAT_004aa1b4;
        DAT_004ab8c0 = (iVar1 / 2 -
                       (int)(longlong)((double)CONCAT44(param_2,param_1) * _DAT_00484d48)) +
                       DAT_004aa2b4;
      }
      if (*(int *)(&DAT_004abb70 + param_3 * 4) == 0) {
        DAT_004aaeb0 = iVar5 / 5 + DAT_004aa1b4;
        DAT_004ab8c0 = iVar1 / 5 + DAT_004aa2b4;
      }
    }
    if (DAT_004ac90c == 1) {
      DAT_004aaeb0 = iVar5 / 2 + DAT_004aa1b4;
      DAT_004ab8c0 = (iVar1 / 2 - (int)(longlong)((double)CONCAT44(param_2,param_1) * _DAT_00484d48)
                     ) + DAT_004aa2b4;
    }
    FUN_004706bd(this,(int *)&stack0xfffffff4,DAT_004aa1b4,DAT_004aa2b4);
    CDC::LineTo(this,DAT_004aaeb0,DAT_004ab8c0);
  }
  if (DAT_004ac90c == 1) {
    iVar1 = (int)(longlong)((double)CONCAT44(param_2,param_1) * _DAT_00484d48);
    param_3 = ((DAT_004aa1c4 - DAT_004aa1ac) * 4) / 5 + DAT_004aa1c4;
    iVar2 = (((DAT_004aa2c4 - DAT_004aa2ac) * 4) / 5 - iVar1) + DAT_004aa2c4;
    iVar5 = ((DAT_004aa1bc - DAT_004aa1a4) * 4) / 5 + DAT_004aa1bc;
    iVar4 = (((DAT_004aa2bc - DAT_004aa2a4) * 4) / 5 - iVar1) + DAT_004aa2bc;
    FUN_004706bd(this,(int *)&param_1,DAT_004aa1c4,DAT_004aa2c4);
    CDC::LineTo(this,param_3,iVar2);
    CDC::LineTo(this,iVar5,iVar4);
    CDC::LineTo(this,DAT_004aa1bc,DAT_004aa2bc);
    param_3 = ((DAT_004aa1d4 - DAT_004aa1ac) * 4) / 5 + DAT_004aa1d4;
    iVar2 = (((DAT_004aa2d4 - DAT_004aa2ac) * 4) / 5 - iVar1) + DAT_004aa2d4;
    iVar5 = ((DAT_004aa1dc - DAT_004aa1a4) * 4) / 5 + DAT_004aa1dc;
    iVar1 = (((DAT_004aa2dc - DAT_004aa2a4) * 4) / 5 - iVar1) + DAT_004aa2dc;
    FUN_004706bd(this,(int *)&param_1,DAT_004aa1d4,DAT_004aa2d4);
    CDC::LineTo(this,param_3,iVar2);
    CDC::LineTo(this,iVar5,iVar1);
    CDC::LineTo(this,DAT_004aa1dc,DAT_004aa2dc);
    if (DAT_004aa634 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(this + 4),DAT_004aa634);
    }
    FUN_004706bd(this,(int *)&param_1,DAT_004aa1dc,DAT_004aa2dc);
    CDC::LineTo(this,DAT_004aa1bc,DAT_004aa2bc);
  }
  return;
}

