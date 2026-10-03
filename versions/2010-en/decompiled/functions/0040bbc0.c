
/* WARNING: Function: __ftol replaced with injection: tact2010_ftol_x87_pop */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0040bbc0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  code *pcVar1;
  bool bVar2;
  Tact2010CString TVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  int iStack_24;
  Tact2010CString local_20;
  int iStack_1c;
  int iStack_18;
  int aiStack_14 [2];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_004c2058;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_004b4a1f(param_1,1);
  iVar5 = param_3;
  if ((DAT_004fe624 < 700) || ((DAT_004fe624 < 900 && (0 < DAT_004f82fc)))) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  iVar11 = (int)(longlong)((double)DAT_004fe624 * _DAT_004cc578);
  local_20.data = (char *)(param_7 + param_3);
  iVar6 = *param_1;
  (**(code **)(iVar6 + 0x34))(param_1,0x7f7f7f);
  param_3 = *(undefined4 *)(iVar6 + 0x38);
  (*(code *)param_3)(param_1,0);
  aiStack_14[0] = param_4 - iVar11;
  iVar4 = aiStack_14[0] + -2;
  FUN_00463f50(param_1,iVar4,iVar5,param_4,(int)local_20.data,1,0);
  pcVar1 = *(code **)(iVar6 + 0x2c);
  (*pcVar1)(param_1,7);
  iStack_24 = 1;
  iVar5 = param_7 / 2 + iVar5;
  do {
    if (iStack_24 == 1) {
      iVar6 = param_4 * 4 + iVar11 * -3;
    }
    else {
      iVar6 = param_4 * 4 - iVar11;
    }
    iVar6 = ((int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2) + -2;
    if (DAT_004da140 == 2) {
      if (DAT_00512d64 == 1) {
        iVar9 = (int)(param_7 + (param_7 >> 0x1f & 3U)) >> 2;
      }
      else {
LAB_0040bd4a:
        iVar9 = param_7 / 3;
      }
    }
    else {
      if (DAT_00512d64 != 1) goto LAB_0040bd4a;
      iVar9 = (int)(param_7 + (param_7 >> 0x1f & 3U)) >> 2;
    }
    iVar7 = iVar9 * 3 + (iVar9 * 3 >> 0x1f & 3U);
    iStack_1c = iVar7 >> 2;
    iStack_18 = iStack_1c - (iVar7 >> 0x1f) >> 1;
    iVar7 = iVar6;
    if ((0 < DAT_004f49a4) && (DAT_00512d64 == 0)) {
      iVar7 = iVar6 - param_7 / 3;
    }
    if ((DAT_004f49a4 < 0) && (DAT_00512d64 == 0)) {
      iVar7 = iVar7 + param_7 / 3;
    }
    (*pcVar1)(param_1,0);
    if (DAT_00512d64 == 1) {
      iVar8 = iVar9 * 3;
    }
    else {
      iVar8 = iVar9 * 2;
    }
    Ellipse((HDC)param_1[1],iVar6 - iVar8,iVar5 - iVar9,iVar6 + iVar8,iVar9 + iVar5);
    if (DAT_005363e4 == 0) {
      if (DAT_004f4a5c != (HGDIOBJ)0x0) {
        SelectObject((HDC)param_1[1],DAT_004f4a5c);
      }
    }
    else {
      (*pcVar1)(param_1,4);
    }
    Ellipse((HDC)param_1[1],iVar7 - iStack_1c,iVar5 - iStack_1c,iStack_1c + iVar7,iStack_1c + iVar5)
    ;
    (*pcVar1)(param_1,4);
    Ellipse((HDC)param_1[1],iVar7 - iStack_18,iVar5 - iStack_18,iStack_18 + iVar7,iStack_18 + iVar5)
    ;
    iStack_24 = iStack_24 + 1;
    if (2 < iStack_24) {
      if ((DAT_004f49a4 == 0) && (DAT_00512d64 == 0)) {
        iVar5 = 0;
      }
      else if (DAT_005363e4 == 0) {
        iVar5 = 0xffff00;
      }
      else {
        iVar5 = 0xffffff;
      }
      (*(code *)param_3)(param_1,iVar5);
      TVar3.data = local_20.data;
      iVar5 = param_4;
      pcVar12 = local_20.data + param_7;
      FUN_00463f50(param_1,iVar4,(int)local_20.data,param_4,(int)pcVar12,1,0);
      FUN_004b0613(&local_20,s_ahead_004daef0);
      iVar6 = aiStack_14[0];
      uStack_4 = 0;
      param_4 = *(undefined4 *)(*param_1 + 100);
      (*(code *)param_4)(param_1,aiStack_14[0],(int)TVar3.data,local_20.data,
                         *(int *)(local_20.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&local_20);
      (*pcVar1)(param_1,6);
      FUN_004b4d9d(param_1,aiStack_14,iVar6,(int)TVar3.data);
      CDC::LineTo(param_1,iVar5 + -2,(int)TVar3.data);
      FUN_00463f50(param_1,iVar4,(int)TVar3.data,iVar5,(int)pcVar12,0,0);
      if ((((iVar6 < DAT_005364a0) && (DAT_005364a0 < iVar5)) && (DAT_005364a4 < (int)pcVar12)) &&
         ((int)TVar3.data < DAT_005364a4)) {
        if (bVar2) {
          pcVar10 = s_Sets_line_of_sight_over_the_bow__004daea4;
        }
        else {
          pcVar10 = s_Sets_your_line_of_sight_over_the_004daec8;
        }
        FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,pcVar10);
        DAT_0053649c = 1;
      }
      if (((iVar6 < DAT_004fe75c) && (DAT_004fe75c < iVar5)) &&
         ((DAT_005233a4 < (int)pcVar12 && ((int)pcVar12 - param_7 < DAT_005233a4)))) {
        DAT_004f49a4 = 0;
        DAT_00512d64 = 0;
        DAT_005233a4 = 0;
      }
      if (((DAT_004f49a4 < 1) || (DAT_004f49a4 == 0xb4)) || (DAT_00512d64 != 0)) {
        if (DAT_005363e4 == 0) {
          iVar11 = 0xffff00;
        }
        else {
          iVar11 = 0xffffff;
        }
      }
      else {
        iVar11 = 0;
      }
      (*(code *)param_3)(param_1,iVar11);
      pcVar10 = pcVar12 + param_7;
      FUN_00463f50(param_1,iVar4,(int)pcVar12,iVar5,(int)pcVar10,1,0);
      FUN_004b0613(&local_20,&DAT_004dae9c);
      uStack_4 = 1;
      (*(code *)param_4)(param_1,iVar6,(int)pcVar12,local_20.data,*(int *)(local_20.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&local_20);
      (*pcVar1)(param_1,6);
      FUN_004b4d9d(param_1,aiStack_14,iVar6,(int)pcVar12);
      CDC::LineTo(param_1,iVar5 + -2,(int)pcVar12);
      FUN_00463f50(param_1,iVar4,(int)pcVar12,iVar5,(int)pcVar10,0,0);
      if ((((iVar6 < DAT_005364a0) && (DAT_005364a0 < iVar5)) && (DAT_005364a4 < (int)pcVar10)) &&
         ((int)pcVar12 < DAT_005364a4)) {
        if (bVar2) {
          pcVar12 = s_Line_of_sight_30_deg_left_per_cl_004dae4c;
        }
        else {
          pcVar12 = s_Moves_line_of_sight_30_deg_left_p_004dae70;
        }
        FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,pcVar12);
        DAT_0053649c = 1;
      }
      if (((iVar6 < DAT_004fe75c) && (DAT_004fe75c < iVar5)) &&
         ((DAT_005233a4 < (int)pcVar10 && ((int)pcVar10 - param_7 < DAT_005233a4)))) {
        DAT_004f49a4 = DAT_004f49a4 + 0x1e;
        DAT_00512d64 = 0;
        DAT_005233a4 = 0;
      }
      if ((DAT_004f49a4 < 0) && (DAT_00512d64 == 0)) {
        iVar11 = 0;
      }
      else if (DAT_005363e4 == 0) {
        iVar11 = 0xffff00;
      }
      else {
        iVar11 = 0xffffff;
      }
      (*(code *)param_3)(param_1,iVar11);
      pcVar12 = pcVar10 + param_7;
      FUN_00463f50(param_1,iVar4,(int)pcVar10,iVar5,(int)pcVar12,1,0);
      FUN_004b0613(&local_20,s_right_004dae44);
      uStack_4 = 2;
      (*(code *)param_4)(param_1,iVar6,(int)pcVar10,local_20.data,*(int *)(local_20.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&local_20);
      (*pcVar1)(param_1,6);
      FUN_004b4d9d(param_1,aiStack_14,iVar6,(int)pcVar10);
      CDC::LineTo(param_1,iVar5 + -2,(int)pcVar10);
      FUN_00463f50(param_1,iVar4,(int)pcVar10,iVar5,(int)pcVar12,0,0);
      if ((((iVar6 < DAT_005364a0) && (DAT_005364a0 < iVar5)) && (DAT_005364a4 < (int)pcVar12)) &&
         ((int)pcVar10 < DAT_005364a4)) {
        if (bVar2) {
          pcVar10 = s_Sight_30_deg_right_per_click_004dadfc;
        }
        else {
          pcVar10 = s_Line_of_sight_30_deg_right_per_c_004dae1c;
        }
        FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,pcVar10);
        DAT_0053649c = 1;
      }
      if (((iVar6 < DAT_004fe75c) && (DAT_004fe75c < iVar5)) &&
         ((DAT_005233a4 < (int)pcVar12 && ((int)pcVar12 - param_7 < DAT_005233a4)))) {
        DAT_004f49a4 = DAT_004f49a4 + -0x1e;
        DAT_00512d64 = 0;
        DAT_005233a4 = 0;
      }
      if ((DAT_004f49a4 == 0xb4) && (DAT_00512d64 == 0)) {
        iVar11 = 0;
      }
      else if (DAT_005363e4 == 0) {
        iVar11 = 0xffff00;
      }
      else {
        iVar11 = 0xffffff;
      }
      (*(code *)param_3)(param_1,iVar11);
      pcVar10 = pcVar12 + param_7;
      FUN_00463f50(param_1,iVar4,(int)pcVar12,iVar5,(int)pcVar10,1,0);
      FUN_004b0613(&local_20,s_astern_004dadf4);
      uStack_4 = 3;
      (*(code *)param_4)(param_1,iVar6,(int)pcVar12,local_20.data,*(int *)(local_20.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&local_20);
      (*pcVar1)(param_1,6);
      FUN_004b4d9d(param_1,aiStack_14,iVar6,(int)pcVar12);
      CDC::LineTo(param_1,iVar5 + -2,(int)pcVar12);
      FUN_00463f50(param_1,iVar4,(int)pcVar12,iVar5,(int)pcVar10,0,0);
      if ((((iVar6 < DAT_005364a0) && (DAT_005364a0 < iVar5)) && (DAT_005364a4 < (int)pcVar10)) &&
         ((int)pcVar12 < DAT_005364a4)) {
        if (bVar2) {
          pcVar10 = s_Line_of_sight_over_the_stern__004dadac;
        }
        else {
          pcVar10 = s_Sets_your_line_of_sight_over_the_004dadcc;
        }
        FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,pcVar10);
        DAT_0053649c = 1;
      }
      pcVar12 = pcVar12 + ((int)(param_7 * 5 + (param_7 * 5 >> 0x1f & 3U)) >> 2);
      if (((iVar6 < DAT_004fe75c) && (DAT_004fe75c < iVar5)) &&
         ((DAT_005233a4 < (int)pcVar12 && ((int)pcVar12 - param_7 < DAT_005233a4)))) {
        DAT_004f49a4 = 0xb4;
        DAT_00512d64 = 0;
        DAT_005233a4 = 0;
      }
      if (DAT_00512d64 == 1) {
        iVar11 = 0;
      }
      else if (DAT_005363e4 == 0) {
        iVar11 = 0xffff;
      }
      else {
        iVar11 = 0xffffff;
      }
      (*(code *)param_3)(param_1,iVar11);
      pcVar10 = pcVar12 + param_7;
      FUN_00463f50(param_1,iVar4,(int)pcVar12,iVar5,(int)pcVar10,1,0);
      FUN_004b0613(&local_20,s_upwind_004dada4);
      uStack_4 = 4;
      (*(code *)param_4)(param_1,iVar6,(int)pcVar12,local_20.data,*(int *)(local_20.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&local_20);
      (*pcVar1)(param_1,6);
      FUN_004b4d9d(param_1,aiStack_14,iVar6,(int)pcVar12);
      CDC::LineTo(param_1,iVar5 + -2,(int)pcVar12);
      FUN_00463f50(param_1,iVar4,(int)pcVar12,iVar5,(int)pcVar10,0,0);
      if (((iVar6 < DAT_005364a0) && (DAT_005364a0 < iVar5)) &&
         ((DAT_005364a4 < (int)pcVar10 && ((int)pcVar12 < DAT_005364a4)))) {
        FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,s_You_will_look_directly_upwind__004dad84);
        DAT_0053649c = 1;
      }
      if ((((iVar6 < DAT_004fe75c) && (DAT_004fe75c < iVar5)) && (DAT_005233a4 < (int)pcVar10)) &&
         ((int)pcVar10 - param_7 < DAT_005233a4)) {
        DAT_00512d64 = 1;
        DAT_005233a4 = 0;
        DAT_004f49a4 = 0;
      }
      if (DAT_00512d64 == -1) {
        iVar11 = 0;
      }
      else if (DAT_005363e4 == 0) {
        iVar11 = 0xffff;
      }
      else {
        iVar11 = 0xffffff;
      }
      (*(code *)param_3)(param_1,iVar11);
      pcVar12 = pcVar10 + param_7;
      FUN_00463f50(param_1,iVar4,(int)pcVar10,iVar5,(int)pcVar12,1,0);
      FUN_004b0613(&local_20,s_dnwind_004dad7c);
      uStack_4 = 5;
      (*(code *)param_4)(param_1,iVar6,(int)pcVar10,local_20.data,*(int *)(local_20.data + -8));
      uStack_4 = 0xffffffff;
      FUN_004b05a5(&local_20);
      (*pcVar1)(param_1,6);
      FUN_004b4d9d(param_1,aiStack_14,iVar6,(int)pcVar10);
      CDC::LineTo(param_1,iVar5 + -2,(int)pcVar10);
      FUN_00463f50(param_1,iVar4,(int)pcVar10,iVar5,(int)pcVar12,0,0);
      if (((iVar6 < DAT_005364a0) && (DAT_005364a0 < iVar5)) &&
         ((DAT_005364a4 < (int)pcVar12 && ((int)pcVar10 < DAT_005364a4)))) {
        FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,s_You_will_look_directly_downwind__004dad58);
        DAT_0053649c = 1;
      }
      if (((iVar6 < DAT_004fe75c) && (DAT_004fe75c < iVar5)) &&
         ((DAT_005233a4 < (int)pcVar12 && ((int)pcVar12 - param_7 < DAT_005233a4)))) {
        DAT_00512d64 = -1;
        DAT_005233a4 = 0;
        DAT_004f49a4 = 0;
      }
      if ((DAT_004da140 == 2) || (pcVar10 = pcVar12, DAT_004da194 == 2)) {
        if (DAT_00512d64 == 100) {
          iVar11 = 0;
        }
        else if (DAT_005363e4 == 0) {
          iVar11 = 0xffff00;
        }
        else {
          iVar11 = 0xffffff;
        }
        (*(code *)param_3)(param_1,iVar11);
        pcVar10 = pcVar12 + param_7;
        FUN_00463f50(param_1,iVar4,(int)pcVar12,iVar5,(int)pcVar10,1,0);
        FUN_004b0613(&local_20,s_boat_2_004dad50);
        uStack_4 = 6;
        (*(code *)param_4)(param_1,iVar6,(int)pcVar12,local_20.data,*(int *)(local_20.data + -8));
        uStack_4 = 0xffffffff;
        FUN_004b05a5(&local_20);
        (*pcVar1)(param_1,6);
        FUN_004b4d9d(param_1,aiStack_14,iVar6,(int)pcVar12);
        CDC::LineTo(param_1,iVar5 + -2,(int)pcVar12);
        FUN_004b4d9d(param_1,aiStack_14,iVar6,(int)(pcVar10 + 1));
        CDC::LineTo(param_1,iVar5 + -2,(int)(pcVar10 + 1));
        FUN_00463f50(param_1,iVar4,(int)pcVar12,iVar5,(int)pcVar10,0,0);
        if ((((iVar6 < DAT_005364a0) && (DAT_005364a0 < iVar5)) && (DAT_005364a4 < (int)pcVar10)) &&
           ((int)pcVar12 < DAT_005364a4)) {
          FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,s_You_will_look_at_the_other_boat__004dad2c)
          ;
          DAT_0053649c = 1;
        }
        if (((iVar6 < DAT_004fe75c) && (DAT_004fe75c < iVar5)) &&
           ((DAT_005233a4 < (int)pcVar10 && ((int)pcVar10 - param_7 < DAT_005233a4)))) {
          DAT_00512d64 = 100;
          DAT_005233a4 = 0;
          DAT_004f49a4 = 0;
        }
      }
      if (DAT_00512d64 == 100) {
        iVar11 = 0;
      }
      else if (DAT_005363e4 == 0) {
        iVar11 = 0xffff00;
      }
      else {
        iVar11 = 0xffffff;
      }
      (*(code *)param_3)(param_1,iVar11);
      pcVar12 = pcVar10 + param_7;
      FUN_00463f50(param_1,iVar4,(int)pcVar10,iVar5,(int)pcVar12,1,0);
      if (DAT_004f41f4 == 0) {
        FUN_004b0613((Tact2010CString *)&param_3,s_hide_sail_004dad20);
        uStack_4 = 7;
        (*(code *)param_4)(param_1,iVar6,(int)pcVar10,(char *)param_3,*(int *)(param_3 + -8));
      }
      else {
        FUN_004b0613((Tact2010CString *)&param_3,s_show_sail_004dad14);
        uStack_4 = 8;
        (*(code *)param_4)(param_1,iVar6,(int)pcVar10,(char *)param_3,*(int *)(param_3 + -8));
      }
      uStack_4 = 0xffffffff;
      FUN_004b05a5((Tact2010CString *)&param_3);
      (*pcVar1)(param_1,6);
      FUN_004b4d9d(param_1,aiStack_14,iVar6,(int)pcVar10);
      CDC::LineTo(param_1,iVar5 + -2,(int)pcVar10);
      FUN_004b4d9d(param_1,aiStack_14,iVar6,(int)(pcVar12 + 1));
      CDC::LineTo(param_1,iVar5 + -2,(int)(pcVar12 + 1));
      FUN_00463f50(param_1,iVar4,(int)pcVar10,iVar5,(int)pcVar12,0,0);
      if (((iVar6 < DAT_005364a0) && (DAT_005364a0 < iVar5)) &&
         ((DAT_005364a4 < (int)pcVar12 && ((int)pcVar10 < DAT_005364a4)))) {
        if (DAT_004f41f4 == 0) {
          pcVar10 = s_Your_sails_will_be_transparent__004dacf4;
        }
        else {
          pcVar10 = s_Your_sails_will_be_opaque__004dacd8;
        }
        FUN_004b06ed((Tact2010CString *)&DAT_004fdfd4,pcVar10);
        DAT_0053649c = 1;
      }
      if ((((iVar6 < DAT_004fe75c) && (DAT_004fe75c < iVar5)) && (DAT_005233a4 < (int)pcVar12)) &&
         ((int)pcVar12 - param_7 < DAT_005233a4)) {
        DAT_004f41f4 = DAT_004f41f4 + 1;
        if (1 < DAT_004f41f4) {
          DAT_004f41f4 = 0;
        }
        DAT_005233a4 = 0;
      }
      if (DAT_004da140 == 2) {
        FUN_0040c980(param_1,param_2,(int)pcVar12 - param_7,iVar5,param_5,param_6,param_7);
      }
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
  } while( true );
}

