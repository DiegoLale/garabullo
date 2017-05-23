void menu_records()
{
  apaga_leds();
  leds_botones.setPixelColor(8, leds_botones.Color(intensidad, 0, 0));
  leds_botones.show();
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print(F("RECORDS"));
  display.setTextSize(1);
  display.setCursor(0, 30);
  display.print(F("SUMAS = "));
  display.print(EEPROM.read(0));
  display.setCursor(0, 40);
  display.print(F("PRODUCTO = "));
  display.print(EEPROM.read(1));
  display.setCursor(0, 50);
  display.print(F("SIMON = "));
  display.print(EEPROM.read(2));
  display.display();
  debounce();
  byte boton = test_boton_pulsado();
  while (boton != 4)
  {
    boton = test_boton_pulsado();
    delay(10);
  }
  pita();
  debounce();
  
}
