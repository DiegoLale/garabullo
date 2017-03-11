
/*En esta pestaña van las variables globales y toda la configuración
 * 
 * 
 * 
 */
/****************************LIBRERÍAS INCLUIDAS*****************************
 * 
 * 
 */
#include <EEPROM.h>
#include <Adafruit_GFX.h>       // librería gráfica de la pantalla
#include <Adafruit_SSD1306.h>   //  Librería para la pantalla
#include <Adafruit_NeoPixel.h>  //  Librería que gestiona los leds direccionables
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");// Si al compilar da este error se debe modificar la librería Adafruit_SSD1306.h
#endif


#define numero_leds_botonera 9
#define pin_leds_botonera 4
#include <Adafruit_NeoPixel.h>  //  Librería que gestiona los leds direccionables
Adafruit_NeoPixel leds_botones = Adafruit_NeoPixel(numero_leds_botonera, pin_leds_botonera, NEO_GRB + NEO_KHZ800);


/***************************VARIABLES GLOBALES********************************
 * 
 */
//*********************variables para movimientos
#define IN1_izq 5
#define IN2_izq 6
#define IN3_izq 7
#define IN4_izq 8

#define IN1_der 9
#define IN2_der 10
#define IN3_der 11
#define IN4_der 12
const int pasos_recto = 2650;
const int pasos_giro = 1230;
const int STEPTIME = 900;
int Step_izq = 0;
int Step_der = 0;
boolean Clockwise_izq = true;
boolean Clockwise_der = true;
int arrayDefault[4] = {LOW, LOW, LOW, LOW};

int stepsMatrix[8][4] = {
  {LOW, LOW, LOW, HIGH},
  {LOW, LOW, HIGH, HIGH},
  {LOW, LOW, HIGH, LOW},
  {LOW, HIGH, HIGH, LOW},
  {LOW, HIGH, LOW, LOW},
  {HIGH, HIGH, LOW, LOW},
  {HIGH, LOW, LOW, LOW},
  {HIGH, LOW, LOW, HIGH},
};

unsigned long lastTime;
unsigned long time;

//**************************************************
 
int puntos = 0;
int intensidad = 10;
int buzzer = 3;
int nivelBateria;
int resultado;
int muestras[9] = {0,1,2,3,4,5,6,7,8};
int puntero;
int posicion_acierto;
long tiempo_inicio;
long linea_tiempo;
int tiempo_pitido = 15;
