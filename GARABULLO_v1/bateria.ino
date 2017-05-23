void bateria()
{
  display.fillRoundRect(100, 0, 20, 6, 2, BLACK);
  nivelBateria = constrain(map(analogRead(A2), 614, 800, 0, 10), 2, 10);
  if (analogRead(A2) < 450)
  {
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(105, -1);
    display.print(F("xx"));
  }
  else
  {
    display.fillRoundRect(100, 0, 2 * nivelBateria -1, 6, 2, WHITE);
  }
  /*
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(30, 10);
    display.print(analogRead(A2));
    display.setCursor(30, 30);
    display.print(nivelBateria);
  */
  display.drawRoundRect(100, 0, 20, 6, 2, WHITE);
  display.fillRect(120, 2, 1, 2, WHITE);
  
}
