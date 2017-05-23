
void setup() {
  leds_botones.begin(); // This initializes the NeoPixel library.
  if ( EEPROM.read(4) != 255 && EEPROM.read(4) != 0)
  {
    intensidad = EEPROM.read(4);
  }
  if (EEPROM.read(14) == 100)
  {
    lee_pasos();
  }



  
  pinMode(IN1_izq, OUTPUT);
  pinMode(IN2_izq, OUTPUT);
  pinMode(IN3_izq, OUTPUT);
  pinMode(IN4_izq, OUTPUT);
  pinMode(IN1_der, OUTPUT);
  pinMode(IN2_der, OUTPUT);
  pinMode(IN3_der, OUTPUT);
  pinMode(IN4_der, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  apaga_leds();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  presentacion();
  presentaGarabullo();
  delay(2000);
  attachInterrupt(digitalPinToInterrupt(2), paralo_pol, FALLING);
}

void loop() {
  menu_principal();

  delay(10);

}



