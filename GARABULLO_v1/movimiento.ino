/*Los movimientos de garabullo están basados en el ejemplo escrito por Mohannad Rawashdeh
  en el siguiente enlace
  https://www.instructables.com/member/Mohannad+Rawashdeh/
  del 28/9/2013
*/
void writeStep_der(boolean outArray[4] ) {
  for (byte i = 0; i < 4; i++) {
    digitalWrite(IN1_der + i, outArray[i]);
  }
}
void writeStep_izq(boolean outArray[4] ) {
  for (byte i = 0; i < 4; i++) {
    digitalWrite(IN1_izq + i, outArray[i]);
  }
}
void stepper_izq() {
  if ((Step_izq >= 0) && (Step_izq < 8)) {
    writeStep_izq(stepsMatrix[Step_izq]);
  } else {
    writeStep_izq(arrayDefault);
  }
  setDirection_izq();
}
void stepper_der() {
  if ((Step_der >= 0) && (Step_der < 8)) {
    writeStep_der(stepsMatrix[Step_der]);
  } else {
    writeStep_der(arrayDefault);
  }
  setDirection_der();
}

void setDirection_izq() {
  (Clockwise_izq) ? (Step_izq++) : (Step_izq--);

  if (Step_izq > 7) {
    Step_izq = 0;
  } else if (Step_izq < 0) {
    Step_izq = 7;
  }
}

void setDirection_der() {
  (Clockwise_der) ? (Step_der++) : (Step_der--);

  if (Step_der > 7) {
    Step_der = 0;
  } else if (Step_der < 0) {
    Step_der = 7;
  }
}

void arranca_chofer(String padonde)
{

  time = 0;
  unsigned long currentMicros;
  
  
  if (padonde == "recto")
  {
    steps = pasos_recto;
  }
  else if (padonde == "giro")
  {
    steps = pasos_giro;
  }

  while (steps > 0) {
 
    currentMicros = micros();
    if (currentMicros - lastTime >= STEPTIME) {
      stepper_izq();
      stepper_der();
      time += micros() - lastTime;
      lastTime = micros();
      steps--;


    }
  }
}

void avanza()
{
  flecha(24);
  Clockwise_izq = true;
  Clockwise_der = false;
  arranca_chofer("recto");
  pita();
}

void atras()
{
  flecha(25);
  Clockwise_izq = false;
  Clockwise_der = true;
  arranca_chofer("recto");
  pita();
}
void derecha()
{
  flecha(62);
  Clockwise_izq = true;
  Clockwise_der = true;
  arranca_chofer("giro");
  pita();
}
void izquierda()
{
  flecha(60);
  Clockwise_izq = false;
  Clockwise_der = false;
  arranca_chofer("giro");
  pita();
}
void apaga_motores()
{
  for (int i = 0; i < 4; i++) {
    digitalWrite(IN1_izq + i, LOW);
    digitalWrite(IN1_der + i, LOW);
  }
}


