void cuadros()
{
  int flecha = 32;
  apaga_leds();
  /*
    display.clearDisplay();
    bateria();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.print(F("CUADROS"));
    display.setCursor(0, 30);
    display.setTextSize(1);
    display.print(F("Basado en escornabot"));
    display.display();
    delay(1000);
  */
  //reseteo de array
  vaciar_almacen();

  leds_botones.setPixelColor(1, leds_botones.Color(0, 0, intensidad));
  leds_botones.setPixelColor(3, leds_botones.Color(0, 0, intensidad));
  leds_botones.setPixelColor(5, leds_botones.Color(0, 0, intensidad));
  leds_botones.setPixelColor(7, leds_botones.Color(0, 0, intensidad));
  leds_botones.setPixelColor(4, leds_botones.Color(intensidad, 0, 0));
  leds_botones.setPixelColor(8, leds_botones.Color(0, intensidad, 0));
  leds_botones.setPixelColor(6, leds_botones.Color(intensidad, intensidad, 0));
  leds_botones.show();
  mostrar_mov(flecha);


  volver = 0;
  puntero = 0;
  debounce();
  while (volver == 0)
  {
    int boton = test_boton_pulsado();
    while (boton != 1 && boton != 3 && boton != 4 && boton != 9 && boton != 7 && boton != 8 && boton != 5 && boton != 10)
    {
      boton = test_boton_pulsado();
      delay(10);

    }
    if (volver == 0)
    {
      switch (boton)
      {
        case 1:
          almacen[puntero] = 1;

          puntero += 1;
          flecha = 24;
          break;

        case 3:
          almacen[puntero] = 3;
          puntero += 1;
          flecha = 174;
          break;

        case 4:
          //salida de bucle, boton de inicio
          titirititiiiii();

          vaciar_almacen();
          flecha = 32;
          break;

        case 9:
          almacen[puntero] = 9;
          puntero += 1;
          flecha = 25;
          break;

        case 7:
          almacen[puntero] = 7;
          puntero += 1;
          flecha = 175;
          break;

        case 8:
          vaciar_almacen();
          flecha = 32;
          break;

        case 5:
          almacen[puntero] = 5;
          puntero += 1;
          flecha = 4;
          break;

        case 10:
          volver = 1;
          break;
      }
    }
    pita();
    debounce();

    mostrar_mov(flecha);



  }
}

void titirititiiiii()
{
  delay(1000);
  puntero = 0;
  while (almacen[puntero] > 0)
  {
    switch (almacen[puntero])
    {
      case 1:
        avanza();
        break;
      case 3:
        izquierda();
        break;
      case 7:
        derecha();
        break;
      case 9:
        atras();
        break;
      case 5:
        flecha(4);
        delay(1650);
        break;
    }
    puntero += 1;
    if (almacen[puntero] != almacen[puntero-1])
    {
      delay(100);
    }
    
  }
  apaga_motores();
  muestraStop();
  delay(1000);
}


void vaciar_almacen()
{
  puntero = 0;
  while (almacen[puntero] != 0)
  {
    almacen[puntero] = 0;
    puntero += 1;
  }
  puntero = 0;
}
void mostrar_mov(int flecha)
{
  display.clearDisplay();
    bateria();
    display.setTextSize(4);
    display.setCursor(0, 20);
    display.print(puntero);
    display.print(" ");
    display.print(char(flecha));
    display.display();
}

