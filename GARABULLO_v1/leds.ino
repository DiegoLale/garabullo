void apaga_leds()
{
  for (byte i = 0; i < 9; i++) {
    leds_botones.setPixelColor(i, leds_botones.Color(0, 0, 0));
    leds_botones.show();
  }
}

void enciende_leds_verde()
{
  for (byte i = 0; i < 9; i++) {
    leds_botones.setPixelColor(i, leds_botones.Color(0, intensidad, 0));
    leds_botones.show();
  }
}

void enciende_leds_rojo()
{
  for (byte i = 0; i < 9; i++) {
    leds_botones.setPixelColor(i, leds_botones.Color(intensidad, 0, 0));
    leds_botones.show();
  }
}

void enciende_leds_azul()
{
  for (byte i = 0; i < 9; i++) {
    leds_botones.setPixelColor(i, leds_botones.Color(0, 0, intensidad));
    leds_botones.show();
  }
}
void enciende_leds_verdadero_falso()
{
  for (byte i = 0; i < 9; i++)
  {
    leds_botones.setPixelColor(i, leds_botones.Color(0, 0, intensidad / 2));
  }
  leds_botones.setPixelColor(7, leds_botones.Color( intensidad, 0, 0));
  leds_botones.setPixelColor(3, leds_botones.Color(0, intensidad, 0));
  leds_botones.show();
}

void leds_simon()
{
  leds_botones.setPixelColor(1, leds_botones.Color(0, min(intensidad, 40), 0));
  leds_botones.setPixelColor(3, leds_botones.Color(min(intensidad, 40), min(intensidad, 40), 0));
  leds_botones.setPixelColor(5, leds_botones.Color(min(intensidad, 40),0, 0));
  leds_botones.setPixelColor(7, leds_botones.Color(0, 0, min(intensidad, 40)));
}




