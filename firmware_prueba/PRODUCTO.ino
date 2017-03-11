void juego_producto()
{
  puntos = 0;
  //********************pantalla presentacion
  apaga_leds();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print(F("MULTIPLICACIONES"));
  display.setCursor(0, 30);
  display.print(F("BUSCA LA CORRECTA"));
  display.setCursor(0, 50);
  display.print(F("Actual record = "));
  display.print(EEPROM.read(1));
  bateria();
  display.display();
  delay(3000);
  espera_inicio();
  tiempo_inicio = millis();
  while (millis() - tiempo_inicio < 60000)
  {
    
    //espera_inicio();
    //primero elegimos dos números al azar entre 1 y 9
    //randomSeed(analogRead(A3));
    int primer_numero = random(1, 11);
    int segundo_numero = random(1, 11);
    resultado = primer_numero * segundo_numero;

    for (int i = 0; i < 9; i++)
    {
      muestras[i] = primer_numero * ((segundo_numero + i) % 11);
    }


    //presentación inicial de los dos números
    apaga_leds();
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(WHITE);
    if (primer_numero > 9)
    {
      display.setCursor(10, 20);
    }
    else
    {
      display.setCursor(28, 20);
    }
    display.print(primer_numero);
    display.print("x");

    if (segundo_numero > 9)
    {
      display.setCursor(60, 20);
    }
    else
    {
      display.setCursor(78, 20);
    }
    display.print(segundo_numero);
    display.print("=");
    //crono_minuto();
    bateria();
    display.display();
    delay(1000);

    // pantalla con resultados
    display.clearDisplay();
    fondo();
    bateria();
    crono_minuto();
    display.display();

    int respuesta = test_boton_pulsado();
    while (respuesta == 0 && (millis() - tiempo_inicio)< 60000)
    {
      respuesta = test_boton_pulsado();
      crono_minuto();
      display.display();
      delay(10);
    }
    digitalWrite(buzzer, HIGH);
    delay(15);
    digitalWrite(buzzer, LOW);
    if (        respuesta == 1 && posicion_acierto == 1
            ||  respuesta == 2 && posicion_acierto == 0
            ||  respuesta == 3 && posicion_acierto == 7
            ||  respuesta == 4 && posicion_acierto == 8
            ||  respuesta == 5 && posicion_acierto == 6
            ||  respuesta == 6 && posicion_acierto == 2
            ||  respuesta == 7 && posicion_acierto == 3
            ||  respuesta == 8 && posicion_acierto == 4
            ||  respuesta == 9 && posicion_acierto == 5
       )
    {
      acertado();
      puntos +=1;      
    }
    else if (respuesta != 0)
    {
      fallo();
      display.clearDisplay();
      display.setTextSize(3);
    display.setTextColor(WHITE);
    
      display.setCursor(0, 20);
    

    display.print(primer_numero);
    display.print("x");

    
    display.print(segundo_numero);
    display.print("=");
 
    display.print(resultado);
    bateria();
    display.display();
    delay(2000);
    
    }


  }
  fin_del_juego(1);
}

void crono_minuto()
{
  linea_tiempo = millis() - tiempo_inicio;
  linea_tiempo = map(linea_tiempo, 0 ,60000 ,0 ,90);
  display.fillRoundRect(0,0, 90, 4, 1, BLACK);
  display.drawRoundRect(0,0, 90, 4, 1, WHITE);
  display.fillRoundRect(0,0, 90 - linea_tiempo, 4, 1, WHITE);
  delay(1);
}


void fondo()
{

  puntero = random(9);

  display.clearDisplay();
  led_bueno();
  for (int y = 0; y < 3; y++)
  {
    for (int x = 0; x < 3; x++)
    {
      display.drawRoundRect(4 + (40 * x), 6 + (20 * y), 38, 18, 5, WHITE);
      display.setTextSize(2);
      display.setTextColor(WHITE);
      int correccion;
      if (muestras[puntero % 9] < 10) correccion = 12;
      else if (muestras[puntero % 9] > 99) correccion = -12;
      else correccion = 0;
      display.setCursor(17 + correccion + (40 * x), 8 + (20 * y));
      crono_minuto();
      display.print(muestras[puntero % 9]);
      puntero += 1;
    }
    //display.fillTriangle(0, 4, 64, 0, 128, 4,  WHITE);
  }
}
