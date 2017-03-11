void menucillo()
{
  apaga_leds();
  leds_botones.setPixelColor(0, leds_botones.Color(intensidad, intensidad, 0));
  leds_botones.setPixelColor(2, leds_botones.Color(intensidad, intensidad,0));
  leds_botones.setPixelColor(5, leds_botones.Color(intensidad, intensidad,0));
  leds_botones.show();
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print(F("elige un juego"));

  display.setCursor(10, 35);
  display.print(F("SUMA"));
  display.setCursor(70, 35);
  display.print(F("PRODUCTO"));
  display.setCursor(40, 55);
  display.print(F("DEMO"));
  bateria();
  display.display();
}

