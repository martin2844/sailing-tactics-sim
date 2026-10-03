
void FUN_00462b10(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_004aff84;
  do {
    FUN_00462af0(puVar1);
    puVar1 = puVar1 + 1;
  } while (puVar1 < &DAT_004aff90);
  FUN_00462af0(&DAT_004aff90);
  return;
}

