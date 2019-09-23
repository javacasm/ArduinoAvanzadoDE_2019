// INCLUIMOS LAS LIBRERÍAS QUE VAMOS A UTILIZAR

// DECLARACIÓN DE VARIABLES
const int SensorPin = 12;
const int LEDPin = 13;
 
// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup() {
    pinMode(SensorPin , INPUT_PULLUP); //activamos la resistencia interna PULL UP
    pinMode(LEDPin, OUTPUT);
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop() {
    if (digitalRead(SensorPin)) { //encendemos/apagamos el LED cuando movemos el sensor TILT
        digitalWrite(LEDPin, HIGH); 
    }  else {
        digitalWrite(LEDPin, LOW);
    }
}

