void espera_inicio()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 30);
  display.print(F("PULSA PARA EMPEZAR"));
  bateria();
  display.display();
  espera_boton(4);
  randomSeed(millis());
}

void led_bueno()
{
  /*
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print(puntero);
  */
  apaga_leds();
  switch (puntero)
  {
  case 0:
  posicion_acierto = 0;
  break;
  case 1:
  posicion_acierto = 4;
  break;
  case 2:
  posicion_acierto = 5;
  break;
   case 3:
  posicion_acierto = 6;
  break;
  case 4:
  posicion_acierto = 3;
  break;
  case 5:
  posicion_acierto = 8;
  break;
   case 6:
  posicion_acierto = 7;
  break;
  case 7:
  posicion_acierto = 2;
  break;
  case 8:
  posicion_acierto = 1;
  break;
  }
  enciende_leds_azul();
  //leds_botones.setPixelColor(posicion_acierto, leds_botones.Color(0, 0, intensidad));
  leds_botones.show();
}

