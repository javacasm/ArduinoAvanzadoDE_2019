// INCLUIMOS LAS LIBRERÍAS QUE VAMOS A UTILIZAR
#include <DHT.h>

// Descomentar el Sensor que vayamos a utilizar
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
 
// DECLARACIÓN DE VARIABLES
const int DHTPin = 5;
DHT dht(DHTPin, DHTTYPE);
float h = 0;
float t = 0;
 
// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup()
{
  Serial.begin(9600);            // inicializamos la comunicación Serie
  dht.begin();                	// inicializamos el objeto dht

}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop()
{
  
  // Leer la temperatura y la humedad toma al rededor de 250milisegundos
  h = dht.readHumidity();
  t = dht.readTemperature();
  delay(250);
 
  if (isnan(h) || isnan(t)) {

    Serial.println("Error de lectura");
  }
  else{ 
  //mostrar valores en el LCD 1602
  Serial.print("Humedad: ");
  Serial.println(h);
  Serial.print("Temp: ");
  Serial.println(t);
  }
}


