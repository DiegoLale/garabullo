void test_alive()
{
  long tiempo_actual = millis();
  if (tiempo_actual > marca_inactivo + tiempo_aviso)
  {
    alarma_tiempo();
  }
}

void alarma_tiempo()
{
  
}

