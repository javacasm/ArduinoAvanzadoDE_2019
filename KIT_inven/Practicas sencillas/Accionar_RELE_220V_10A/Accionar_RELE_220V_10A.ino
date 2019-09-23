// DECLARACIÓN DE VARIABLES
const int pin = 9;

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ) 
void setup() {
  Serial.begin(9600);    //iniciar puerto serie
  pinMode(pin, OUTPUT);  //definir pin como salida
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL)  
void loop(){
  digitalWrite(pin, HIGH);   // poner el Pin en HIGH
  delay(10000);               // esperar un segundo
  digitalWrite(pin, LOW);    // poner el Pin en LOW
  delay(10000);               // esperar un segundo
}

