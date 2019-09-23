// INCLUIMOS LAS LIBRERÍAS QUE VAMOS A UTILIZAR

// DECLARACIÓN DE VARIABLES
const int EchoPin = 5;
const int TriggerPin = 6;
const int LedPin = 13;

// DECLARACIÓN DE FUNCIONES
int ping(int TriggerPin, int EchoPin) {
  long duration, distanceCm;
  
  digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
  distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
     return distanceCm;
}
 
// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup()
{
  Serial.begin(9600);                // inicializamos la comunicación Serie
  pinMode(LedPin, OUTPUT);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop()
{
  int cm = ping(TriggerPin, EchoPin);
  Serial.print("Distancia: ");
  Serial.println(cm);
  delay(1000);
}

