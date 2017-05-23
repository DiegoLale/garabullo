void menu_principal()
{
  marca_inactivo = millis();

  apaga_leds();
  leds_botones.setPixelColor(0, leds_botones.Color(intensidad, intensidad, 0));
  leds_botones.setPixelColor(2, leds_botones.Color(intensidad, intensidad, 0));
  leds_botones.setPixelColor(3, leds_botones.Color(intensidad, intensidad, 0));
  leds_botones.setPixelColor(7, leds_botones.Color(intensidad, intensidad, 0));
  leds_botones.show();

  display.clearDisplay();
  fondo_vacio();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print(F("OPCIONES"));
  display.setTextSize(1);
  display.setCursor(11, 31);
  display.print(F("ROBOT"));
  display.setCursor(80, 31);
  display.print(F("CONSOLA"));
  display.setCursor(5, 51);
  display.print(F("RECORDS"));
  display.setCursor(80, 51);
  display.print(F("AJUSTES"));
  bateria();
  display.display();

  int boton = test_boton_pulsado();
  while (boton != 2 && boton != 3 && boton != 6 && boton != 7)
  {
    boton = test_boton_pulsado();
    delay(10);
    bateria();
    display.display();
    test_alive();
  }
  pita();
  if ( boton == 2)
  {
    cuadros();
  }
  else if ( boton == 3)
  {
    menu_records();
  }
  else if (boton == 6)
  {
    menu_consola();
  }
  else if (boton == 7)
  {
    menu_ajustes();
  }
}


void menu_consola()
{
  apaga_leds();
  leds_botones.setPixelColor(0, leds_botones.Color(intensidad, intensidad, 0));
  leds_botones.setPixelColor(2, leds_botones.Color(intensidad, intensidad, 0));
  leds_botones.setPixelColor(7, leds_botones.Color(intensidad, intensidad, 0));
  leds_botones.setPixelColor(3, leds_botones.Color(intensidad, 0, 0));

  leds_botones.show();

  display.clearDisplay();
  bateria();
  fondo_vacio();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print(F("JUEGOS"));
  display.setTextSize(1);
  display.setCursor(5, 31);
  display.print(F("SUMAS"));
  display.setCursor(77, 31);
  display.print(F("PRODUCTO"));
  display.setCursor(5, 51);
  display.print(F("SIMON"));
  display.setCursor(77, 51);
  display.print(F("VOLVER"));
  display.display();
  debounce();
  byte boton = test_boton_pulsado();
  while (boton != 2 && boton != 6 && boton != 7  && boton != 3)
  {
    boton = test_boton_pulsado();
    delay(10);
    bateria();
    display.display();
  }
  pita();
  debounce();
  if ( boton == 2)
  {
    juego_sumas_verdadero_falso();
  }
  else if (boton == 6)
  {
    juego_producto();
  }
  else if (boton == 3)
  {
    juego_simon();
  }

}
void menu_ajustes()
{

  apaga_leds();
  leds_botones.setPixelColor(0, leds_botones.Color(intensidad, intensidad, 0));
  leds_botones.setPixelColor(2, leds_botones.Color(intensidad, intensidad, 0));
  leds_botones.setPixelColor(3, leds_botones.Color(intensidad, 0, 0));
  leds_botones.setPixelColor(7, leds_botones.Color(intensidad, intensidad, 0));
  leds_botones.show();

  display.clearDisplay();
  fondo_vacio();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print(F("AJUSTES"));
  display.setTextSize(1);
  display.setCursor(11, 31);
  display.print(F("PASOS"));
  display.setCursor(85, 31);
  display.print(F("LEDS"));
  display.setCursor(5, 51);
  display.print(F("RECORDS"));
  display.setCursor(80, 51);
  display.print(F("VOLVER"));
  bateria();
  display.display();
  debounce();
  int boton = test_boton_pulsado();
  while (boton != 2 && boton != 3 && boton != 6 && boton != 7)
  {
    boton = test_boton_pulsado();
    delay(10);
    bateria();
    display.display();
  }
  pita();
  debounce();
  if ( boton == 2)
  {
    menu_pasos();
  }
  else if ( boton == 3)
  {
    menu_borra_records();
  }
  else if (boton == 6)
  {
    menu_leds();
  }

}


void menu_borra_records()
{
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print(F("BORRAR RECORDS"));
  display.setTextSize(3);
  display.setCursor(5, 31);
  display.print(F("SI"));
  display.setCursor(90, 31);
  display.print(F("NO"));
  bateria();
  display.display();
  debounce();
  int boton = test_boton_pulsado();
  while (boton != 3 && boton != 7)
  {
    boton = test_boton_pulsado();
    delay(10);
    bateria();
    display.display();
  }
  pita();
  debounce();
  if ( boton == 3)
  {
    EEPROM.write(0, 0);
    EEPROM.write(1, 0);
    EEPROM.write(2, 0);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.print(F("RECORDS"));
    display.setCursor(0, 30);
    display.print(F("BORRADOS!"));
    display.display();
    delay(2000);

  }

}
void menu_leds() {
  debounce();
  boolean salimos = 0;
  while (salimos == 0)
  {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.print(F("INTENSIDAD"));
    display.setCursor(40, 30);
    display.print(map(intensidad, 1, 254, 1, 100));
    display.print("%");
    display.setTextSize(3);
    display.setCursor(10, 25);
    display.print(F("-"));
    display.setCursor(90, 25);
    display.print(F("+"));

    display.setTextSize(1);
    display.setCursor(0, 50);
    display.print(F("GUARDAR"));
    display.setCursor(85, 50);
    display.print(F("ATRAS"));
    bateria();
    display.display();

    leds_botones.setPixelColor(0, leds_botones.Color(intensidad, 0, 0));
    leds_botones.setPixelColor(1, leds_botones.Color(0, intensidad, 0));
    leds_botones.setPixelColor(2, leds_botones.Color(0, 0, intensidad));
    leds_botones.setPixelColor(3, leds_botones.Color(intensidad, intensidad, 0));
    leds_botones.setPixelColor(6, leds_botones.Color(0, intensidad, 0));
    leds_botones.setPixelColor(4, leds_botones.Color(intensidad, 0, 0));
    leds_botones.setPixelColor(7, leds_botones.Color(intensidad, intensidad, 0));
    leds_botones.show();
    {
      int boton = test_boton_pulsado();
      {
        while (boton != 3 && boton != 5 && boton != 7 && boton != 8)
        {
          boton = test_boton_pulsado();
          delay(10);
          bateria();
          display.display();
        }


        if ( boton == 3 && intensidad > 1)
        {
          intensidad -= 1;
          delay(15);
        }
        else if (boton == 7 && intensidad < 255)
        {
          intensidad += 1;
          delay(15);
        }
        else if (boton == 5)
        {
          pita();
          debounce();
          EEPROM.write(4, intensidad);
          salimos = 1;
        }
        else if (boton == 8) //si salimos.
        {
          pita();
          debounce();
          intensidad = EEPROM.read(4); // volvemos a hacer que intensidad valga lo que estaba almacenado
          salimos = 1;
        }
      }
    }
  }
}

void menu_pasos() {
  debounce();
  boolean salimos = 0;
  byte retardo_pulsacion = 30;
  byte incremento = 1;
  while (salimos == 0)
  {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);

    display.setCursor(50, 13);
    display.print(pasos_recto);
    display.setCursor(50, 30);
    display.print(pasos_giro);
    display.setTextSize(3);
    display.setCursor(10, 8);
    display.print(F("-"));
    display.setTextSize(2);
    display.print(char(18));
    display.setTextSize(3);
    display.setCursor(100, 8);
    display.print(F("+"));
    display.setCursor(10, 25);
    display.print(F("-"));
    display.setTextSize(2);
    display.print(char(29));
    display.setTextSize(3);
    display.setCursor(100, 25);
    display.print(F("+"));



    display.setTextSize(1);
    display.setCursor(0, 50);
    display.print(F("GUARDAR"));
    display.setCursor(85, 50);
    display.print(F("ATRAS"));
    bateria();
    display.display();

    leds_botones.setPixelColor(0, leds_botones.Color(intensidad, intensidad, 0));
    leds_botones.setPixelColor(2, leds_botones.Color(intensidad, intensidad, 0));
    leds_botones.setPixelColor(3, leds_botones.Color(intensidad, intensidad, 0));
    leds_botones.setPixelColor(7, leds_botones.Color(intensidad, intensidad, 0));
    leds_botones.setPixelColor(6, leds_botones.Color(0, intensidad, 0));
    leds_botones.setPixelColor(4, leds_botones.Color(intensidad, 0, 0));
    leds_botones.show();

    int boton = test_boton_pulsado();

    while (boton != 2 && boton != 6 && boton != 3 && boton != 7  && boton != 5 && boton != 8)
    {
      boton = test_boton_pulsado();
      delay(5);
      bateria();
      display.display();
      retardo_pulsacion = 30;
      incremento = 1;
    }


    if ( boton == 2)
    {
      pasos_recto -= incremento;
      delay(retardo_pulsacion);
      if (retardo_pulsacion > 1)
      {
        retardo_pulsacion -= 1;
      }
      else
      {
        incremento = 5;
      }
    }
    else if (boton == 6)
    {
      pasos_recto += incremento;
      delay(retardo_pulsacion);
      if (retardo_pulsacion > 1)
      {
        retardo_pulsacion -= 1;
      }
      else
      {
        incremento = 5;
      }
    }

    if ( boton == 3)
    {
      pasos_giro -= incremento;
      delay(retardo_pulsacion);
      if (retardo_pulsacion > 1)
      {
        retardo_pulsacion -= 1;
      }
      else
      {
        incremento = 5;
      }
    }
    else if (boton == 7)
    {
      pasos_giro += incremento;
      delay(retardo_pulsacion);
      if (retardo_pulsacion > 1)
      {
        retardo_pulsacion -= 1;
      }
      else
      {
        incremento = 5;
      }

    }

    else if (boton == 5)
    {
      pita();
      debounce();
      guarda_pasos();
      salimos = 1;
    }
    else if (boton == 8)
    {
      pita();
      salimos = 1;
    }
  }


}

