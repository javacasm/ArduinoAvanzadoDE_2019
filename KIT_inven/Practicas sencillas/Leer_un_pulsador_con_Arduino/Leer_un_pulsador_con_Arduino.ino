// DECLARACIÓN DE VARIABLES
const int inputPin = 2;
int value = 0;

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL)
void loop(){
  value = digitalRead(inputPin);  //lectura digital de pin
  //mandar mensaje a puerto serie en función del valor leido
  if (value == HIGH) {
      Serial.println("Encendido");
  }
  else {
      Serial.println("Apagado");
  }
  delay(1000);
}

