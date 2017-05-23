/*
 * 
 void test_recto()
{
  delay(1000);
  for (int i = 0; i < 5; i++)
  {
    avanza();
    flecha_arriba();
    delay(100);
  }
  apaga_motores();
}

void test_giro()
{
  delay(1000);
  for (int i = 0; i < 20; i++)
  {
    derecha();
    delay(100);
  }
  apaga_motores();
}

void test_patron()
{
  apaga_leds();
  delay(2000);
  thisNote = 0;
  movimientos = 4;
  while( movimientos > 0)
  {
    avanza();
    delay(100);
    if(movimientos > 0)   //este if es por si se pulsa la interrupción durante el "avanza"
    derecha();
    delay(100);
    movimientos -= 1;
  }

  apaga_motores();
  muestraStop();
  delay(1000);
}
*/
