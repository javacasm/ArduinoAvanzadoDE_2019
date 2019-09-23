// INCLUIMOS LAS LIBRERÍAS QUE VAMOS A UTILIZAR

// DECLARACIÓN DE VARIABLES
const int pinJoyX = A0;
const int pinJoyY = A1;
const int pinJoyButton = 9;
 
// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup()
{
  Serial.begin(9600);                // inicializamos la comunicación Serie
  pinMode(pinJoyButton, INPUT_PULLUP); // activamos la resistencia pull-up interna
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop()
{
  int Xvalue = 0;
  int Yvalue = 0;
  bool buttonValue = false;
 
  //leer valores
  Xvalue = analogRead(pinJoyX);
  delay(100);           //es necesaria una pequeña pausa entre lecturas analógicas
  Yvalue = analogRead(pinJoyY);
  buttonValue = digitalRead(pinJoyButton);
 
  //mostrar valores por serial
  Serial.print("X:" );
  Serial.print(Xvalue);
  Serial.print("| Y: ");
  Serial.print(Yvalue);
  Serial.print("Pulsador: ");
  Serial.println(buttonValue);
  delay(250);
}

