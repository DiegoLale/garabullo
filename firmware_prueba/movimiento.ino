/*Los movimientos de garabullo están basados en el ejemplo escrito por Mohannad Rawashdeh
  en el siguiente enlace
  https://www.instructables.com/member/Mohannad+Rawashdeh/
  del 28/9/2013
*/
void writeStep_der(int outArray[4] ) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(IN1_der + i, outArray[i]);
  }
}
void writeStep_izq(int outArray[4] ) {
  for (int i = 0; i < 4; i++) {
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
void avanza()
{
  Clockwise_izq = true;
  Clockwise_der = false;
  unsigned long currentMicros;
  int steps_recto = pasos_recto;
  time = 0;
  while (steps_recto > 0) {
    currentMicros = micros();
    if (currentMicros - lastTime >= STEPTIME) {
      stepper_izq();
      stepper_der();
      time += micros() - lastTime;
      lastTime = micros();
      steps_recto--;
    }
  }
  pita();
}
void atras()
{
  Clockwise_izq = false;
  Clockwise_der = true;
  unsigned long currentMicros;
  int steps_recto = pasos_recto;
  time = 0;
  while (steps_recto > 0) {
    currentMicros = micros();
    if (currentMicros - lastTime >= STEPTIME) {
      stepper_izq();
      stepper_der();
      time += micros() - lastTime;
      lastTime = micros();
      steps_recto--;
    }
  }
  pita();
}
void derecha()
{
  Clockwise_izq = true;
  Clockwise_der = true;
  unsigned long currentMicros;
  int steps_giro = pasos_giro;
  time = 0;
  while (steps_giro > 0) {
    currentMicros = micros();
    if (currentMicros - lastTime >= STEPTIME) {
      stepper_izq();
      stepper_der();
      time += micros() - lastTime;
      lastTime = micros();
      steps_giro--;
    }
  }
  pita();
}
void izquierda()
{
  Clockwise_izq = false;
  Clockwise_der = false;
  unsigned long currentMicros;
  int steps_giro = pasos_giro;
  time = 0;
  while (steps_giro > 0) {
    currentMicros = micros();
    if (currentMicros - lastTime >= STEPTIME) {
      stepper_izq();
      stepper_der();
      time += micros() - lastTime;
      lastTime = micros();
      steps_giro--;
    }
  }
  pita();
}
void apaga_motores()
{
  for (int i = 0; i < 4; i++) {
    digitalWrite(IN1_izq + i, LOW);
    digitalWrite(IN1_der + i, LOW);
  }
}
void prueba_movimientos()
{
  delay(1000);
  flecha_arriba();
  avanza();
  flecha_izquierda();
  izquierda();
  flecha_abajo();
  atras();
  flecha_derecha();
  derecha();
  flecha_abajo();
  atras();
  flecha_izquierda();
  izquierda();
  flecha_arriba();
  avanza();
  flecha_derecha();
  derecha();
  muestraStop();
  apaga_motores();
  delay(1000);
}
