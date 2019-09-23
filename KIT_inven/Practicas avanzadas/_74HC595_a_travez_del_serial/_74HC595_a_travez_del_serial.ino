// DECLARACIÓN DE VARIABLES 
// Pin conectado a ST_CP del 74HC595
int latchPin = 12;
// Pin conectado a to SH_CP del 74HC595
int clockPin = 11;
// Pin conectado a to DS del 74HC595
int dataPin = 14;

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup() {
  // Establecer los pines para que pueda controlar el registro de desplazamiento
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("reset");
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop() {
  if (Serial.available() > 0) {
    // En ASCII los valores de '0' hasta '9' caracteres son
    // representados por los valores 48 hasta el 57
    // por lo que para obtener el valor numérico de 0 a 9 se le debe restar 48
    int bitToSet = Serial.read() - 48;

  // Escribimos los datos en el registro de desplazamiento
    registerWrite(bitToSet, HIGH);
  }
}


void registerWrite(int whichPin, int whichState) {
  byte bitsToSend = 0;

// Poner el latchPin en LOW para apagar todos los leds
  digitalWrite(latchPin, LOW);

// Convertimos el número en bits 
  bitWrite(bitsToSend, whichPin, whichState);

// Los leds no cambian mientras se están enviado los datos:
  shiftOut(dataPin, clockPin, MSBFIRST, bitsToSend);

//Poner el LatchPin en valor HIGH y los pin se encienden:
  digitalWrite(latchPin, HIGH);

}

