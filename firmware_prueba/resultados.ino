void acertado()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20, 20);
  display.print("ACIERTO");
  bateria();
  display.display();
  enciende_leds_verde();
  delay(500);
}

void fallo()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(35, 20);
  display.print(F("FALLO"));
  bateria();
  display.display();
  enciende_leds_rojo();
  delay(2000);
}
void fin_del_juego(int juego)
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20, 0);
  display.print(F("FIN DEL"));
  display.setCursor(30, 20);
  display.print(F("JUEGO"));
  display.setCursor(20, 40);
  display.setTextSize(1);
  display.print(F("ACIERTOS = "));
  display.print(puntos);
  bateria();
  display.display();
  delay(2000);
  if(puntos > EEPROM.read(juego))
  {
    nuevoRecord(juego, puntos);
  }
  else if(puntos == EEPROM.read(juego))
  {
    record_igualado();
  }
  espera_boton(4);
}

void nuevoRecord(int juego , int puntos)
{
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print(F("RECORD"));
  display.setCursor(0, 30);
  display.print(F("NUEVO = "));
  display.print(puntos);
  bateria();
   display.setTextSize(1);
   display.setCursor(0, 50);
  display.print(F("Antiguo record = "));
  display.print(EEPROM.read(juego));
  display.display();
  EEPROM.write(juego, puntos);
  delay(2000);
}
void record_igualado()
{
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20, 10);
  display.print(F("RECORD"));
  display.setCursor(20, 30);
  display.print(F("IGUALADO"));
  display.setCursor(30, 50);
  display.print(F("* "));
  display.print(puntos);
  display.print(" *");
  bateria();
  display.display();
  delay(2000);
}
