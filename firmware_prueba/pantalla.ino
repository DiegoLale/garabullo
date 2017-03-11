
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
    display.fillRect(77,30,1,16,WHITE);
    display.fillRect(77,29,49,1,WHITE);
    display.fillCircle(15, display.height() / 2, i, WHITE);
    display.display();
    delay(100);
  }
    delay(1000);
  
}


void flecha_arriba()
{
  display.clearDisplay();
  display.fillTriangle(64,5, 44, 30, 84, 30, WHITE );
  display.fillRect(59,30,10,30,WHITE);
  display.display();
}
  void flecha_abajo()
{
  display.clearDisplay();
  display.fillTriangle(64,59, 44, 34, 84, 34, WHITE );
  display.fillRect(59,4,10,30,WHITE);
  display.display();

}
void flecha_derecha()
{
  display.clearDisplay();
  display.fillCircle(display.width()/2, display.height()/2,display.height()/2, WHITE);
  display.fillCircle(display.width()/2, display.height()/2,display.height()/4, BLACK); 
  display.fillRect(display.width()/2, display.height()/2,display.width()/2, display.height()/2, BLACK); 
  display.fillTriangle(73,32, 103, 32, 88, 47, WHITE );
  display.display();
}
void flecha_izquierda()
{
  display.clearDisplay();
  display.fillCircle(display.width()/2, display.height()/2,display.height()/2, WHITE);
  display.fillCircle(display.width()/2, display.height()/2,display.height()/4, BLACK); 
  display.fillRect(0, display.height()/2,display.width()/2, display.height()/2, BLACK); 
  display.fillTriangle(25,32, 55, 32, 40, 47, WHITE );
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
  display.setCursor(13, 20);
  display.print (F("version de prueba"));
  display.setCursor(50,50);
  display.print (F("by DiegoLale"));
  display.display();
}

void muestraStop()
{
  display.invertDisplay(false);
  display.clearDisplay();
  display.setCursor(6,20);
  display.setTextColor(WHITE);
  display.setTextSize(5);
  display.print("STOP");
  display.display();
}
void meco(int posicion)
{
  //paraguas
  //display.fillCircle(display.width() / 2 + posicion, display.height() / 2, 15, WHITE);
  //display.fillRect(49 + posicion, 32, 31, 30, BLACK);
  for (int i = -10; i < 11; i = i + 10)
  {
    display.fillCircle(display.width() / 2 + i + posicion, display.height() / 2 - i / 10 , 5, BLACK);
  }
  //display.drawLine(display.width() / 2 + posicion-1, display.height() / 2-5,display.width() / 2 + 3 + posicion, 48, WHITE );
  //display.drawLine(display.width() / 2 + posicion, display.height() / 2-5,display.width() / 2 + 4 + posicion, 48, WHITE );
  //meco
  display.drawCircle(display.width() / 2 - 5 + posicion, 35, 8, WHITE); //cabeza
  display.drawTriangle(60 + posicion - 5, 38, 68 + posicion - 5, 39, 63 + posicion - 5, 40, WHITE); //boca
  //cuerpo
  display.drawLine(display.width() / 2 - 10 + posicion, 44 , display.width() / 2 - 10 + posicion - 4 + random(3), 44 + 14, WHITE);
  display.drawLine(display.width() / 2 + 2 + posicion, 42 , display.width() / 2 + 2 + posicion + 3 + random(3), 42 + 14, WHITE);
  //pies
  display.fillCircle(display.width() / 2 - 8 + posicion, 62, 3, WHITE);
  display.fillCircle(display.width() / 2  + posicion, 62, 4, WHITE);
  //manos
  display.fillCircle(display.width() / 2 - 12 + posicion, 52, 3, WHITE);
  display.fillCircle(display.width() / 2 + 3 + posicion, 48, 3, WHITE);
  //botones
  display.drawCircle(display.width() / 2-4  + posicion, 46, 2, WHITE);
  display.drawCircle(display.width() / 2-4  + posicion, 49, 2, WHITE);
  display.drawCircle(display.width() / 2-3  + posicion, 53, 2, WHITE);
  
  display.fillCircle(display.width() / 2 - 8 + posicion, 33, 3, WHITE); //ojo
  display.fillCircle(display.width() / 2 - 2 + posicion, 33, 3, WHITE); //ojo
  if (random(20) < 18)
  {
    display.fillCircle(display.width() / 2 - 7 + posicion, 33, 1, BLACK); //pupila
    display.fillCircle(display.width() / 2 - 3 + posicion, 33, 1, BLACK); //pupila
  }
  else
  {
    display.fillCircle(display.width() / 2 - 7 + posicion, 33, 1, WHITE); //pupila
    display.fillCircle(display.width() / 2 - 3 + posicion, 33, 1, WHITE); //pupila
  }
}
