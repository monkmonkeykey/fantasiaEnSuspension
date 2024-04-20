#define sensor A4  // Sharp IR GP2Y0A41SK0F (4-30cm, analog)
#include <Adafruit_NeoPixel.h>

const int PIN = 6;        // Cambia el número de pin según cómo hayas conectado la tira de Neopixel
const int NUMPIXELS = 8;  // Cambia este valor según el número de Neopixels en tu tira

int trigger = 2;
int echo = 3;
int distanciaMaxima = 90;  //distancia en centimetros máxima
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void loop() {
  float volts = analogRead(sensor) * 0.0048828125;  // value from sensor * (5/1024)
  float distance = 13 * pow(volts, -1) * (2);

  //distance = distance + 5;
  distance = int(distance);
  delay(100);  // slow down serial port

  int numeroDePixelesAEncender = map(distance, 0, distanciaMaxima, 0, NUMPIXELS);
  numeroDePixelesAEncender = constrain(numeroDePixelesAEncender, 0, NUMPIXELS);
  colorWipe(strip.Color(10, 100, 255, 25), numeroDePixelesAEncender);
  //strip.Color();
  // Enciende los píxeles según la distancia
  /*
if (distance > 40) {
}
else if (distance < 40) {
  colorWipe(strip.Color(124, 124, 124, 25), numeroDePixelesAEncender);
}
*/
  delay(50);

  //if (distance > 50) distance = 50;  // Para limitar la escala del serial plotter
  Serial.println(distance);
}


// Función para iluminar los píxeles uno por uno
void colorWipe(uint32_t color, int numPixels) {
  strip.clear();  // Apaga todos los píxeles
  for (int i = 0; i < numPixels; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}