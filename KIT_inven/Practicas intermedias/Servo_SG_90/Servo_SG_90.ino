// INCLUIMOS LAS LIBRERÍAS QUE VAMOS A UTILIZAR
#include <Servo.h>

// DECLARACIÓN DE VARIABLES
Servo MiServo;
const int PinPot = A0;
const int PinServo = 9;
int ValorPot;
int ValorMinPot = 1023;
int ValorMaxPot = 0;
int angulo;

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup()
{
  Serial.begin(9600);                // inicializamos la comunicación serie
  MiServo.attach(PinServo);  	    // inicializamos el objeto Servomotor

  while(millis()<10000){            // Inicializamos los márgenes max y min del potenciómetro. Muy útil para sensores LDR, NTC, sensores de llama…
    ValorPot = analogRead(PinPot);
    if (ValorPot > ValorMaxPot){
      ValorMaxPot = ValorPot;  
    }
    if (ValorPot < ValorMinPot){
      ValorMinPot = ValorPot;  
    }
      Serial.print("max: ");
      Serial.print(ValorMaxPot);
      Serial.print(" |  min: ");
      Serial.println(ValorMinPot);
    }
    Serial.println("calibrado!");
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop()
{     
  ValorPot = analogRead(PinPot);
  angulo = map(ValorPot, ValorMinPot, ValorMaxPot, 0, 180);
  Serial.print("Potenc: ");
  Serial.println(ValorPot);
  Serial.print("Angulo: ");
  Serial.println(angulo);
  Serial.println(“--------------------------”);
  MiServo.write(angulo);    // movemos el servomotor al angulo mapeado
  delay(500);
} 

