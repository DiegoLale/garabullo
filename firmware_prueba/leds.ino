void apaga_leds()
{
  for (int i = 0; i < 9; i++) {
    leds_botones.setPixelColor(i, leds_botones.Color(0, 0, 0));
    leds_botones.show();
  }
}

void enciende_leds_verde()
{
  for (int i = 0; i < 9; i++) {
    leds_botones.setPixelColor(i, leds_botones.Color(0, intensidad, 0));
    leds_botones.show();
  }
}

void enciende_leds_rojo()
{
  for (int i = 0; i < 9; i++) {
    leds_botones.setPixelColor(i, leds_botones.Color(intensidad, 0, 0));
    leds_botones.show();
  }
}

void enciende_leds_azul()
{
  for (int i = 0; i < 9; i++) {
    leds_botones.setPixelColor(i, leds_botones.Color(0, 0, intensidad));
    leds_botones.show();
  }
}
void enciende_leds_verdadero_falso()
{
  for (int i = 0; i < 9; i++)
  {
    leds_botones.setPixelColor(i, leds_botones.Color(0, 0, intensidad / 2));
  }
  leds_botones.setPixelColor(7, leds_botones.Color( intensidad, 0, 0));
  leds_botones.setPixelColor(3, leds_botones.Color(0, intensidad, 0));
  leds_botones.show();
}

void pita()
{
  digitalWrite(buzzer, HIGH);
  delay(tiempo_pitido);
  digitalWrite(buzzer, LOW);
}

