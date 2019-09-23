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
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop() {
  // Contar desde 0 a 255 y se muestra el número en los LEDs
  for (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++) {
    // Poner el latchPin en LOW para apagar todos los leds
    digitalWrite(latchPin, LOW);
    // Los leds no cambian mientras se están enviado los datos:
    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);  

    //Poner el LatchPin en valor HIGH y los pin se encienden:
    digitalWrite(latchPin, HIGH);
    // pausa antes del siguiente valor
    delay(500);
  }
}

