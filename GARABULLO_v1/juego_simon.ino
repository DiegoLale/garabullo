void juego_simon()
{
  retardo_simon = 800;
  apaga_leds();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print(F("JUEGO DE SIMON"));
  display.setCursor(0, 50);
  display.print(F("Actual record = "));
  display.print(EEPROM.read(2));
  bateria();
  display.display();
  delay(3000);
  espera_inicio();

  display.clearDisplay();
  display.display();
  apaga_leds();
  leds_simon();
  leds_botones.show();
  delay(1000);
  vidas = 1;
  vaciar_almacen();
  int pulsaciones_simon = 0;
  while (vidas > 0)
  {
    nuevo_movimiento();
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(50, 30);
    display.print(puntero);
    display.display();
    muestra_movimientos();
    replica_jugador();
  }

}

void replica_jugador()
{
  int posicion_color = 0;
  int fallo_simon = 0;
  while (almacen[posicion_color] > 0 && fallo_simon == 0)
  {
    byte acierto = almacen[posicion_color];
    byte respuesta = test_boton_pulsado();
    while (respuesta == 0 && vidas > 0)
    {
      respuesta = test_boton_pulsado();
      delay(20);

    }
    pita();
    leds_simon();
    switch (respuesta)
    {
      case 1:
        leds_simon();
        leds_botones.setPixelColor(1, leds_botones.Color(0, 255, 0));
        break;
      case 7:
        leds_simon();
        leds_botones.setPixelColor(3, leds_botones.Color(255, 255, 0));
        break;
      case 9:
        leds_simon();
        leds_botones.setPixelColor(5, leds_botones.Color(255, 0, 0));
        break;
      case 3:
        leds_simon();
        leds_botones.setPixelColor(7, leds_botones.Color(0, 0, 255));
        break;
    }
    leds_botones.show();
    debounce();
    leds_simon();
    leds_botones.show();
    if ((respuesta == 1 && acierto == 1) || (respuesta == 3 && acierto == 4) || (respuesta == 7 && acierto == 2) || (respuesta == 9 && acierto == 3))
    {
      posicion_color += 1;

    }
    else
    {
      fallo();
      fallo_simon = 1;
      vidas -= 1;
      puntos = puntero -1;
      fin_del_juego(2);
    }
  }
  delay(2000);
}






void nuevo_movimiento()
{
  randomSeed(millis());
  int aleatorio = random(1, 5); // 1,2,3,4
  almacen[puntero] = aleatorio;
  puntero += 1;
  retardo_simon = retardo_simon - retardo_simon / 15;
}

void muestra_movimientos()
{
  int posicion_color = 0;
  while (almacen[posicion_color] > 0)
  {
    int actual = almacen[posicion_color];
    {
      apaga_leds();

      switch (actual)
      {
        case 1:
          leds_simon();
          leds_botones.setPixelColor(1, leds_botones.Color(0, 255, 0));
          break;
        case 2:
          leds_simon();
          leds_botones.setPixelColor(3, leds_botones.Color(255, 255, 0));
          break;
        case 3:
          leds_simon();
          leds_botones.setPixelColor(5, leds_botones.Color(255, 0, 0));
          break;
        case 4:
          leds_simon();
          leds_botones.setPixelColor(7, leds_botones.Color(0, 0, 255));
          break;
      }
      posicion_color += 1;
      leds_botones.show();
      pita();
      delay(retardo_simon);
      apaga_leds();
      leds_simon();
      leds_botones.show();
      delay(retardo_simon / 4);

    }
  }

}



