void juego_sumas_verdadero_falso()
{
  //********************pantalla presentacion
  apaga_leds();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print(F("JUEGO DE SUMAS"));
  display.setCursor(0, 30);
  display.print(F("verdadero o falso?"));
  display.setCursor(0, 50);
  display.print(F("Actual record = "));
  display.print(EEPROM.read(0));
  bateria();
  display.display();
  delay(3000);
  espera_inicio();
  //*********************variables
  puntos = 0;
  temporizador = 100;
  vidas = 3;
  long tiempo_juego = millis();
  long tiempo_actual_juego = tiempo_juego;
  int velocidad_juego = 100;
  int avance_tiempo = 0;
  //*********************comienzo
  while (vidas > 0)
  {
    randomSeed(millis());
    int numero_1 = random(99);
    int numero_2 = random(99);
    resultado = numero_1 + numero_2;
    int muestra = resultado;
    int acierto = random(2);  // esto decide si va a ser correcto o no
    if (acierto == 1) // si acierto vale uno es incorrecto
    {
      int difeund = random(1, 5);
      int momen = random(2);
      if (momen == 1 && resultado - difeund > 0)
      {
        muestra = resultado - difeund;
      }
      else
      {
        muestra = resultado + difeund;
      }


    }
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    if (numero_1 > 9)
    {
      display.setCursor(52, 0);
    }
    else
    {
      display.setCursor(64, 0);
    }
    display.print(numero_1);

    if (numero_2 > 9)
    {
      display.setCursor(52, 15);
    }
    else
    {
      display.setCursor(64, 15);
    }
    display.print(numero_2);
    display.setCursor(40, 15);
    display.print("+");
    display.drawLine(40, 31, 74, 31, WHITE);
    display.setCursor(28, 33);
    display.print("=");
    if (muestra < 10)
    {
      display.setCursor(64, 33);
    }
    else if (muestra > 99)
    {
      display.setCursor(40, 33);
    }
    else display.setCursor(52, 33);
    display.print(muestra);
    display.setCursor(0, 0);
    display.setTextSize(2);
    for (int i = 0; i < vidas; i++)
    {
      display.print(char(3));
    }

    enciende_leds_verdadero_falso();

    int respuesta = test_boton_pulsado();
    while (respuesta != 3 && respuesta != 7 && temporizador > 2)
    {
      tiempo_actual_juego = millis();
      //if (tiempo_actual_juego < tiempo_juego + velocidad_juego)
      {
        temporizador -= 1;
        delay(20);
      }
      display.drawRoundRect(10, 50, temporizador, 10, 2, WHITE);
      bateria();
      display.display();
      respuesta = test_boton_pulsado();
      if (respuesta == 3 || respuesta == 7)
      {
        pita();
      }
      delay(10);
    }
    temporizador = 100 - avance_tiempo * 5;
    if ((muestra == resultado && respuesta == 7) ||  (muestra != resultado && respuesta == 3))
    {
      acertado();
      puntos += 1;
      avance_tiempo += 1;
    }
    else
    {
      fallo();
      vidas -= 1;
      avance_tiempo = 0;
      temporizador = 100;
    }
  }
  fin_del_juego(0);
}
