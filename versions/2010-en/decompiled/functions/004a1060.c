
int FUN_004a1060(undefined4 param_1,char *param_2,undefined4 *param_3)

{
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  char *pcVar11;
  int iVar12;
  ulonglong uVar13;
  longlong lVar14;
  uint local_24c;
  short *local_248;
  int local_244;
  int local_240;
  undefined1 local_23a;
  char local_239;
  int local_238;
  int local_234;
  int local_230;
  int local_22c;
  int local_228;
  int local_224;
  int local_220;
  uint local_21c;
  undefined4 local_218;
  undefined1 local_214 [4];
  undefined4 local_210;
  undefined4 local_20c;
  int local_204;
  undefined1 local_200 [511];
  undefined1 uStack_1;
  
  local_220 = 0;
  puVar10 = (undefined1 *)0x0;
  local_240 = 0;
  cVar8 = *param_2;
  local_21c = CONCAT31(local_21c._1_3_,cVar8);
  pcVar11 = param_2;
  do {
    if ((cVar8 == '\0') || (param_2 = pcVar11 + 1, local_240 < 0)) {
      return local_240;
    }
    if ((cVar8 < ' ') || ('x' < cVar8)) {
      uVar2 = 0;
    }
    else {
      uVar2 = (byte)"<program name unknown>"[cVar8] & 0xf;
    }
    local_220 = (int)(char)(&DAT_004d0d80)[uVar2 * 8 + local_220] >> 4;
    switch(local_220) {
    case 0:
switchD_004a10dd_caseD_0:
      local_230 = 0;
      if ((PTR_DAT_004f0250[(local_21c & 0xff) * 2 + 1] & 0x80) != 0) {
        FUN_004a19f0((int)cVar8,param_1,&local_240);
        cVar8 = *param_2;
        param_2 = pcVar11 + 2;
      }
      FUN_004a19f0((int)cVar8,param_1,&local_240);
      break;
    case 1:
      local_218 = 0;
      local_228 = 0;
      local_234 = 0;
      local_238 = 0;
      local_24c = 0;
      local_244 = -1;
      local_230 = 0;
      break;
    case 2:
      switch(cVar8) {
      case ' ':
        local_24c = local_24c | 2;
        break;
      case '#':
        local_24c = local_24c | 0x80;
        break;
      case '+':
        local_24c = local_24c | 1;
        break;
      case '-':
        local_24c = local_24c | 4;
        break;
      case '0':
        local_24c = local_24c | 8;
      }
      break;
    case 3:
      if (cVar8 == '*') {
        local_234 = FUN_004a1ac0(&param_3);
        if (local_234 < 0) {
          local_24c = local_24c | 4;
          local_234 = -local_234;
        }
      }
      else {
        local_234 = cVar8 + -0x30 + local_234 * 10;
      }
      break;
    case 4:
      local_244 = 0;
      break;
    case 5:
      if (cVar8 == '*') {
        local_244 = FUN_004a1ac0(&param_3);
        if (local_244 < 0) {
          local_244 = -1;
        }
      }
      else {
        local_244 = cVar8 + -0x30 + local_244 * 10;
      }
      break;
    case 6:
      switch(cVar8) {
      case 'I':
        if ((*param_2 != '6') || (pcVar11[2] != '4')) {
          local_220 = 0;
          goto switchD_004a10dd_caseD_0;
        }
        param_2 = pcVar11 + 3;
        local_24c = local_24c | 0x8000;
        break;
      case 'h':
        local_24c = local_24c | 0x20;
        break;
      case 'l':
        local_24c = local_24c | 0x10;
        break;
      case 'w':
        local_24c = local_24c | 0x800;
      }
      break;
    case 7:
      switch(cVar8) {
      case 'C':
        if ((local_24c & 0x830) == 0) {
          local_24c = local_24c | 0x800;
        }
      case 'c':
        if ((local_24c & 0x810) == 0) {
          local_200[0] = FUN_004a1ac0(&param_3);
          puVar10 = (undefined1 *)0x1;
        }
        else {
          uVar3 = FUN_004a1b00(&param_3);
          puVar10 = (undefined1 *)FUN_004a3770(local_200,uVar3);
          if ((int)puVar10 < 0) {
            local_248 = (short *)local_200;
            local_228 = 1;
            break;
          }
        }
        local_248 = (short *)local_200;
        break;
      case 'E':
      case 'G':
        local_218 = 1;
        cVar8 = cVar8 + ' ';
      case 'e':
      case 'f':
      case 'g':
        local_248 = (short *)local_200;
        if (local_244 < 0) {
          local_244 = 6;
        }
        else if ((local_244 == 0) && (cVar8 == 'g')) {
          local_244 = 1;
        }
        local_210 = *param_3;
        local_20c = param_3[1];
        param_3 = param_3 + 2;
        (*(code *)PTR_FUN_004ee008)(&local_210,local_200,(int)cVar8,local_244,local_218);
        if (((local_24c & 0x80) != 0) && (local_244 == 0)) {
          (*(code *)PTR_FUN_004ee014)(local_200);
        }
        if ((cVar8 == 'g') && ((local_24c & 0x80) == 0)) {
          (*(code *)PTR_FUN_004ee00c)(local_200);
        }
        uVar2 = local_24c | 0x40;
        if (local_200[0] == '-') {
          local_248 = (short *)(local_200 + 1);
          uVar2 = local_24c | 0x140;
        }
        local_24c = uVar2;
        uVar2 = 0xffffffff;
        psVar5 = local_248;
        do {
          if (uVar2 == 0) break;
          uVar2 = uVar2 - 1;
          sVar1 = *psVar5;
          psVar5 = (short *)((int)psVar5 + 1);
        } while ((char)sVar1 != '\0');
        puVar10 = (undefined1 *)(~uVar2 - 1);
        break;
      case 'S':
        if ((local_24c & 0x830) == 0) {
          local_24c = local_24c | 0x800;
        }
      case 's':
        iVar12 = 0x7fffffff;
        if (local_244 != -1) {
          iVar12 = local_244;
        }
        local_248 = (short *)FUN_004a1ac0(&param_3);
        if ((local_24c & 0x810) == 0) {
          psVar5 = local_248;
          if (local_248 == (short *)0x0) {
            psVar5 = (short *)PTR_DAT_004f0470;
            local_248 = (short *)PTR_DAT_004f0470;
          }
          for (; (iVar12 != 0 && (iVar12 = iVar12 + -1, (char)*psVar5 != '\0'));
              psVar5 = (short *)((int)psVar5 + 1)) {
          }
          puVar10 = (undefined1 *)((int)psVar5 - (int)local_248);
        }
        else {
          if (local_248 == (short *)0x0) {
            local_248 = (short *)PTR_DAT_004f0474;
          }
          local_230 = 1;
          for (psVar5 = local_248; (iVar12 != 0 && (iVar12 = iVar12 + -1, *psVar5 != 0));
              psVar5 = psVar5 + 1) {
          }
          puVar10 = (undefined1 *)((int)psVar5 - (int)local_248 >> 1);
        }
        break;
      case 'X':
        goto switchD_004a12f1_caseD_58;
      case 'Z':
        psVar5 = (short *)FUN_004a1ac0(&param_3);
        if ((psVar5 == (short *)0x0) ||
           (local_248 = *(short **)(psVar5 + 2), local_248 == (short *)0x0)) {
          uVar2 = 0xffffffff;
          local_248 = (short *)PTR_DAT_004f0470;
          pcVar11 = PTR_DAT_004f0470;
          do {
            if (uVar2 == 0) break;
            uVar2 = uVar2 - 1;
            cVar8 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar8 != '\0');
          puVar10 = (undefined1 *)(~uVar2 - 1);
        }
        else if ((local_24c & 0x800) == 0) {
          puVar10 = (undefined1 *)(int)*psVar5;
          local_230 = 0;
        }
        else {
          local_230 = 1;
          puVar10 = (undefined1 *)((uint)(int)*psVar5 >> 1);
        }
        break;
      case 'd':
      case 'i':
        local_22c = 10;
        local_24c = local_24c | 0x40;
        goto LAB_004a1627;
      case 'n':
        piVar4 = (int *)FUN_004a1ac0(&param_3);
        if ((local_24c & 0x20) == 0) {
          local_228 = 1;
          *piVar4 = local_240;
        }
        else {
          local_228 = 1;
          *(undefined2 *)piVar4 = (undefined2)local_240;
        }
        break;
      case 'o':
        local_22c = 8;
        if ((local_24c & 0x80) != 0) {
          local_24c = local_24c | 0x200;
        }
        goto LAB_004a1627;
      case 'p':
        local_244 = 8;
switchD_004a12f1_caseD_58:
        local_224 = 7;
LAB_004a15e2:
        local_22c = 0x10;
        if ((local_24c & 0x80) != 0) {
          local_23a = 0x30;
          local_239 = (char)local_224 + 'Q';
          local_238 = 2;
        }
        goto LAB_004a1627;
      case 'u':
        local_22c = 10;
LAB_004a1627:
        if ((local_24c & 0x8000) == 0) {
          if ((local_24c & 0x20) == 0) {
            if ((local_24c & 0x40) == 0) {
              uVar2 = FUN_004a1ac0(&param_3);
              uVar13 = (ulonglong)uVar2;
            }
            else {
              iVar12 = FUN_004a1ac0(&param_3);
              uVar13 = (ulonglong)iVar12;
            }
          }
          else if ((local_24c & 0x40) == 0) {
            uVar2 = FUN_004a1ac0(&param_3);
            uVar13 = (ulonglong)(uVar2 & 0xffff);
          }
          else {
            sVar1 = FUN_004a1ac0(&param_3);
            uVar13 = (ulonglong)(int)sVar1;
          }
        }
        else {
          uVar13 = FUN_004a1ae0(&param_3);
        }
        if ((((local_24c & 0x40) != 0) && ((longlong)uVar13 < 0x100000000)) &&
           ((longlong)uVar13 < 0)) {
          uVar13 = CONCAT44(-((int)(uVar13 >> 0x20) + (uint)((int)uVar13 != 0)),-(int)uVar13);
          local_24c = local_24c | 0x100;
        }
        iVar7 = (int)(uVar13 >> 0x20);
        iVar12 = (int)uVar13;
        if ((local_24c & 0x8000) == 0) {
          iVar7 = 0;
        }
        if (local_244 < 0) {
          local_244 = 1;
        }
        else {
          local_24c = local_24c & 0xfffffff7;
        }
        local_248 = (short *)register0x00000010;
        lVar14 = CONCAT44(iVar7,iVar12);
        if (iVar12 == 0 && iVar7 == 0) {
          local_238 = 0;
          lVar14 = CONCAT44(iVar7,iVar12);
        }
        while( true ) {
          iVar12 = local_22c;
          psVar5 = (short *)((int)local_248 + -1);
          iVar7 = local_244 + -1;
          if ((local_244 < 1) && (lVar14 == 0)) break;
          local_204 = local_22c >> 0x1f;
          iVar6 = __aullrem(lVar14,local_22c,local_204);
          iVar6 = iVar6 + 0x30;
          lVar14 = __aulldiv(lVar14,iVar12,local_204);
          if (0x39 < iVar6) {
            iVar6 = iVar6 + local_224;
          }
          *(char *)psVar5 = (char)iVar6;
          local_244 = iVar7;
          local_248 = psVar5;
        }
        puVar10 = &uStack_1 + -(int)psVar5;
        local_244 = iVar7;
        if (((local_24c & 0x200) != 0) &&
           (((char)*local_248 != '0' || (puVar10 == (undefined1 *)0x0)))) {
          puVar10 = &stack0x00000000 + -(int)psVar5;
          *(char *)psVar5 = '0';
          local_248 = psVar5;
        }
        break;
      case 'x':
        local_224 = 0x27;
        goto LAB_004a15e2;
      }
      if (local_228 == 0) {
        if ((local_24c & 0x40) != 0) {
          if ((local_24c & 0x100) == 0) {
            if ((local_24c & 1) == 0) {
              if ((local_24c & 2) == 0) goto LAB_004a17bf;
              local_23a = 0x20;
            }
            else {
              local_23a = 0x2b;
            }
          }
          else {
            local_23a = 0x2d;
          }
          local_238 = 1;
        }
LAB_004a17bf:
        iVar12 = (local_234 - (int)puVar10) - local_238;
        if ((local_24c & 0xc) == 0) {
          FUN_004a1a40(0x20,iVar12,param_1,&local_240);
        }
        FUN_004a1a80(&local_23a,local_238,param_1,&local_240);
        if (((local_24c & 8) != 0) && ((local_24c & 4) == 0)) {
          FUN_004a1a40(0x30,iVar12,param_1,&local_240);
        }
        if ((local_230 == 0) || (psVar5 = local_248, puVar9 = puVar10, (int)puVar10 < 1)) {
          FUN_004a1a80(local_248,puVar10,param_1,&local_240);
        }
        else {
          do {
            puVar9 = puVar9 + -1;
            iVar7 = FUN_004a3770(local_214,*psVar5);
            if (iVar7 < 1) break;
            FUN_004a1a80(local_214,iVar7,param_1,&local_240);
            psVar5 = psVar5 + 1;
          } while (puVar9 != (undefined1 *)0x0);
        }
        if ((local_24c & 4) != 0) {
          FUN_004a1a40(0x20,iVar12,param_1,&local_240);
        }
      }
    }
    cVar8 = *param_2;
    local_21c = CONCAT31(local_21c._1_3_,cVar8);
    pcVar11 = param_2;
  } while( true );
}

