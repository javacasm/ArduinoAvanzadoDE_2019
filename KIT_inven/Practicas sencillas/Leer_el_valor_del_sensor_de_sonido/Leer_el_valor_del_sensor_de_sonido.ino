// INCLUIMOS LAS LIBRERÍAS QUE VAMOS A UTILIZAR

// DECLARACIÓN DE VARIABLES
const int sensorPin= A0;
const int sensorPin_dig=7;

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup()
{
Serial.begin(9600);                // inicializamos el objeto lcd
pinMode(sensorPin_dig, INPUT);   
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL)
void loop()
{
  int value = analogRead(sensorPin);
  int value_dig = digitalRead(sensorPin_dig);
  Serial.print("SensorValor es:");
  Serial.print(value);
  Serial.print(value_dig);
  if (value_dig == 1){
    delay(1000);
  }
  delay(1);  // siempre es recomendable dejar un pequeño tiempo entre lecturas del conversor analógico-digital
}

