
void presentacion()
{
  display.clearDisplay();
  display.display();
  for (int i = 1; i < 13; i++)
  {
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(30, 30);
    display.clearDisplay();
    display.print(F("Lale"));
    display.setTextColor(BLACK, WHITE);
    display.print(F("bots"));
    display.fillRect(77, 30, 1, 16, WHITE);
    display.fillRect(77, 29, 49, 1, WHITE);
    display.fillCircle(15, display.height() / 2, i, WHITE);
    display.display();
    delay(100);
  }
  delay(1000);

}


void flecha(int mostrar)
{

  display.clearDisplay();
  display.setCursor(40, 0);
  display.setTextColor(WHITE);
  display.setTextSize(8);
  display.print(char(mostrar));
  display.display();
  display.display();
}

void presentaGarabullo()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.print(F("GARABULLO"));
  display.setTextSize(1);
  display.setCursor(13, 25);
  display.print (F("de "));
  display.setTextSize(2);
  display.print (nombre);
  display.setCursor(50, 50);
  display.setTextSize(1);
  display.print (F("by DiegoLale"));
  display.display();
}

void muestraStop()
{
  display.invertDisplay(false);
  display.clearDisplay();
  display.setCursor(6, 20);
  display.setTextColor(WHITE);
  display.setTextSize(5);
  display.print("STOP");
  display.display();
}

void fondo_vacio()
{
  for (int y = 0; y < 2; y++)
  {
    for (int x = 0; x < 2; x++)
    {
      display.drawRoundRect((75 * x), 6 + (20 * (y + 1)), 50, 18, 5, WHITE);
      display.setTextSize(2);
      display.setTextColor(WHITE);
    }
  }
}

