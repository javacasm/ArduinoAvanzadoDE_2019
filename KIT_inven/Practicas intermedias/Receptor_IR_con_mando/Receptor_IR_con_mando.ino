//INCLUIMOS LIBRERÍAS
#include <IRremote.h>

//INICIALIZAMOS LAS VARIABLES Y LOS OBJETOS
int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Empezamos a recibir los datos
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop() 
{
  if (irrecv.decode(&results)) 
    {
      Serial.println(results.value, DEC); // Print por Serial 'results.value'
      irrecv.resume();   // Dejamos el sistema a la espera del próximo dato 
    }
}

