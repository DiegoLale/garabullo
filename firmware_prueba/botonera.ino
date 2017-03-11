int pinBotoneraA = A0;
int pinBotoneraB = A1;

int lectura_boton_1 = 788;
int lectura_boton_2 = 601;
int lectura_boton_3 = 445;
int lectura_boton_4 = 300;
int lectura_boton_5 = 156;
int lectura_boton_6 = 788;
int lectura_boton_7 = 602;
int lectura_boton_8 = 445;
int lectura_boton_9 = 300;
int lectura_boton_10 = 156;
int abanico = 30;

/*  posicion de los botones
 *    2 1 6
 *    3 4 7
 *    5 9 8
 * 
 * 
 */

void muestra_lectura()
{
  int lectura = test_boton_pulsado();
  if (lectura > 0)
  {

    digitalWrite(buzzer, HIGH);
    delay(15);
    digitalWrite(buzzer, LOW);
    display.clearDisplay();
    display.drawRoundRect(50, 15, 30, 38, 7, WHITE);
    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.setCursor(55, 20);
    display.print(lectura);
    if (lectura == 10)
    {
      display.clearDisplay();
      display.drawRoundRect(45, 15, 48, 38, 7, WHITE);
      display.setCursor(45, 20);
      display.print(lectura);
    }
    display.display();
    debounce();
  }
  else
  {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(10, 20);
    display.print("ESPERANDO");
    display.display();
  }
}
/* la función test_boton_pulsado devuelve un valor desde 1 a 10 en función del botón pulsado o 0 si no hay ningún botón pulsado
 *  se complementa con las fuciones test_botoneraA y test botoneraB
 *  También tienen que estar definidos pinBotoneraA y pin BotoneraB
 */

int test_boton_pulsado()
{
  int boton = test_botoneraA();

  if ((boton < (lectura_boton_1 + abanico)) & (boton > (lectura_boton_1 - abanico)))
  {
    return 1;
  }

  else if ((boton < (lectura_boton_2 + abanico)) & (boton > (lectura_boton_2 - abanico)))
  {
    return 2;
  }
  else if ((boton < (lectura_boton_3 + abanico)) & (boton > (lectura_boton_3 - abanico)))
  {
    return 3;
  }
  else if ((boton < (lectura_boton_4 + abanico)) & (boton > (lectura_boton_4 - abanico)))
  {
    return 4;
  }
  else if ((boton < (lectura_boton_5 + abanico)) & (boton > (lectura_boton_5 - abanico)))
  {
    return 5;
  }
  else
  {
    boton = test_botoneraB();
    if ((boton < (lectura_boton_6 + abanico)) & (boton > (lectura_boton_6 - abanico)))
    {
      return 6;
    }

    else if ((boton < (lectura_boton_7 + abanico)) & (boton > (lectura_boton_7 - abanico)))
    {
      return 7;
    }
    else if ((boton < (lectura_boton_8 + abanico)) & (boton > (lectura_boton_8 - abanico)))
    {
      return 8;
    }
    else if ((boton < (lectura_boton_9 + abanico)) & (boton > (lectura_boton_9 - abanico)))
    {
      return 9;
    }
    else if ((boton < (lectura_boton_10 + abanico)) & (boton > (lectura_boton_10 - abanico)))
    {
      return 10;
    }
    else return 0;
  }
}

int test_botoneraA()
{
  int lecturaA = analogRead(pinBotoneraA);
  return lecturaA;
}

int test_botoneraB()
{
  int lecturaB = analogRead(pinBotoneraB);
  return lecturaB;
}

/*


*/
void debounce()
{
  int estabilidad = 0;
  while (estabilidad < 10)
  {
    delay(1);
    if (test_boton_pulsado() == 0)
    {
      estabilidad += 1;
    }
    else estabilidad = 0;
  }
}


void espera_boton(int boton)
{
  apaga_leds();
  leds_botones.setPixelColor(8, leds_botones.Color(0, intensidad, 0));
  leds_botones.show();
  int espera = 0;
  espera = test_boton_pulsado();
  while (espera != boton)
  {
    espera = test_boton_pulsado();
    bateria();
    display.display();
  }
        digitalWrite(buzzer, HIGH);
        delay(15);
        digitalWrite(buzzer, LOW);
        apaga_leds();
}

