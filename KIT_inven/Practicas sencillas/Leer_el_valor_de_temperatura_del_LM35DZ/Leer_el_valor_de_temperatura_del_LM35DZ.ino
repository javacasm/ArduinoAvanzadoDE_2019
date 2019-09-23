// INCLUIMOS LAS LIBRERÍAS QUE VAMOS A UTILIZAR

// DECLARACIÓN DE VARIABLES
const int sensorPin= A0;

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup()
{
Serial.begin(9600);                // inicializamos el objeto lcd   
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL)
void loop()
{
  int value = analogRead(sensorPin);
  float volts = (value / 1024.0) * 5;
  float celsius = (volts - 0.5 ) * 100; 
  Serial.print("La temperatura es:");
  Serial.println(celsius);
  delay(1000);
}


