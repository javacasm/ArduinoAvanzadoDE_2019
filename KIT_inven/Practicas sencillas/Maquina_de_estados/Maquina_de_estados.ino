// DECLARACIÓN DE VARIABLES
const int buttonPin = 2;     // Pin del pulsador
const int ledPin =  13;      // Pin del led

int buttonState = 0;         // Estado del pulsador

/* Nuestra maquina de estados funciona de la siguiente manera:
 *  0 : Apagado
 *  1 : Encendido
 *  2 : Parpadeo
 */
int estado = 0;           

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
if (buttonState == HIGH) {
  estado ++;
  delay(500);
  if (estado==3){
  estado=0;
  }
}
switch (estado){
    case 0:    // Estado 0 apagado
        digitalWrite(ledPin, LOW);
      break;
    case 1:    // Estado 1 encendido
      digitalWrite(ledPin, HIGH);
      break;
    case 2:    // Estado 2 parpadeando
      digitalWrite(ledPin, LOW);
      delay(500);
      digitalWrite(ledPin, HIGH);
      delay(500);
      break; 
  }
}

