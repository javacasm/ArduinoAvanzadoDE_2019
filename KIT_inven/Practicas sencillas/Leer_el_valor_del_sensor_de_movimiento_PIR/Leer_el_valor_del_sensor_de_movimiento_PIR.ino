// INCLUIMOS LAS LIBRERÍAS QUE VAMOS A UTILIZAR

// DECLARACIÓN DE VARIABLES
const int LEDPin = 13;        // pin para el LED
const int PIRPin = 2;         // pin de entrada (for PIR sensor)
 
int pirState = LOW;           // de inicio no hay movimiento
int val = 0;                  // estado del pin
 
// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup()
{
  Serial.begin(9600);                // inicializamos la comunicación Serie
  pinMode(LEDPin, OUTPUT); 
  pinMode(PIRPin, INPUT);
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop()
{
  val = digitalRead(PIRPin);
  if (val == HIGH)   //si está activado
  { 
    digitalWrite(LEDPin, HIGH);  //LED ON
    if (pirState == LOW)  //si previamente estaba apagado
    {
      Serial.println("Sensor activado");
      pirState = HIGH;
    }
  } 
  else   //si esta desactivado
  {
    digitalWrite(LEDPin, LOW); // LED OFF
    if (pirState == HIGH)  //si previamente estaba encendido
    {
      pirState = LOW;
    }
  }
}

