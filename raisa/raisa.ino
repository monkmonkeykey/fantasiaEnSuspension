#include <Adafruit_NeoPixel.h>

const int PIN = 6;        // Cambia el número de pin según cómo hayas conectado la tira de Neopixel
const int NUMPIXELS = 8;  // Cambia este valor según el número de Neopixels en tu tira

int trigger = 2;
int echo = 3;
int distanciaMaxima = 80;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();                // Inicializar todos los píxeles con apagado
  pinMode(trigger, OUTPUT);    //pin como salida
  pinMode(echo, INPUT);        //pin como entrada
  digitalWrite(trigger, LOW);  //Inicializamos el pin con 0
}
void loop() {
  long t;  //timepo que demora en llegar el eco
  long d;  //distancia en centimetros

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);  //Enviamos un pulso de 10us
  digitalWrite(trigger, LOW);

  t = pulseIn(echo, HIGH);  //obtenemos el ancho del pulso
  d = t / 59;               //escalamos el tiempo a una distancia en cm

  Serial.print("Distancia: ");
  Serial.print(d);  //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(50);  //Hacemos una pausa de 100ms
  // Mapea la distancia a un rango de 0 a NUMPIXELS
  // distance = constrain(distance, 0, 30);
  int numeroDePixelesAEncender = map(d, 0, distanciaMaxima, 0, NUMPIXELS);
  numeroDePixelesAEncender = constrain(numeroDePixelesAEncender, 0, NUMPIXELS);
  int brilloNeoPixels = map(d, 0, distanciaMaxima, 20, 40);
  // Enciende los píxeles según la distancia
  if (d <= 40) {  //menor a 40 azul
    strip.setBrightness(brilloNeoPixels);
    colorWipe(strip.Color(10, 100, 255, 25), numeroDePixelesAEncender);
  } else if (d >= 41) {
    strip.setBrightness(brilloNeoPixels);
    colorWipe(strip.Color(188, 40, 127, 25), numeroDePixelesAEncender);
  }

  delay(50);
}

// Función para iluminar los píxeles uno por uno
void colorWipe(uint32_t color, int numPixels) {
  strip.clear();  // Apaga todos los píxeles
  for (int i = 0; i < numPixels; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}
