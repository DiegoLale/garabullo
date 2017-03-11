
void setup() {
  leds_botones.begin(); // This initializes the NeoPixel library.
  pinMode(IN1_izq, OUTPUT);
  pinMode(IN2_izq, OUTPUT);
  pinMode(IN3_izq, OUTPUT);
  pinMode(IN4_izq, OUTPUT);
  pinMode(IN1_der, OUTPUT);
  pinMode(IN2_der, OUTPUT);
  pinMode(IN3_der, OUTPUT);
  pinMode(IN4_der, OUTPUT);
  pinMode(buzzer, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  presentacion();
  presentaGarabullo();
  delay(5000);
}

void loop() {
  menucillo();
  int boton = test_boton_pulsado();
  while (boton != 2 && boton !=6 && boton !=9)
  {
    boton = test_boton_pulsado();
    delay(10);
    bateria();
    display.display();
  }
  pita();
  if( boton == 2)
  {
    juego_sumas_verdadero_falso();
  }
  
  else if( boton == 6)
  {
    juego_producto();
  }
  else if (boton == 9)
  {
    prueba_movimientos();
  }
  //  enciende_leds();
  delay(10);
  
}



