/*
10 pasos_recto MSB
11 pasos_rectO LSB
12 pasos_giro MSB
13 pasos_giro LSB
14 bandera para saber que hay pasos almacenados
*/


void guarda_pasos()
{
  if (EEPROM.read(14) != 100)
  {
    EEPROM.write(14 , 100);
  }
  byte pasos_recto_msb = highByte(pasos_recto);
  EEPROM.write(10, pasos_recto_msb);
  byte pasos_recto_lsb = lowByte(pasos_recto);
  EEPROM.write(11, pasos_recto_lsb);

  byte pasos_giro_msb = highByte(pasos_giro);
  EEPROM.write(12, pasos_giro_msb);
  byte pasos_giro_lsb = lowByte(pasos_giro);
  EEPROM.write(13, pasos_giro_lsb);
}
void lee_pasos()
{
  byte aux_pasos = 0;
  aux_pasos = EEPROM.read(10);
  pasos_recto = aux_pasos << 8;
  pasos_recto += EEPROM.read(11);

  aux_pasos = 0;
  aux_pasos = EEPROM.read(12);
  pasos_giro = aux_pasos << 8;
  pasos_giro += EEPROM.read(13);
  
}

