// DECLARACIÓN DE LIBRERIAS 
#include <EEPROM.h>

// DECLARACIÓN DE VARIABLES
//Se crea una variable con el valor de la posición de memoria
//en la que se va a almacenar el byte.
int Direccion = 0;
//Se crean una variables para leer los valores de la memoria EEPROM
byte Val1;
byte Val2;

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup()
{
Serial.begin(9600);
//Se almacena la información a guardar en un byte.
byte Informacion = B11001;// La "B" indica que el formato es binario
//También es posible almacenar la información leída a través de un
//sensor. Hay que tener en cuenta que el valor máximo de una variable
//tipo int es de 1023, mientras que el mayor valor que se puede almacenar
//en un solo byte es 255. Por tanto, se divide el valor resultante entre 4
//y a la hora de utilizar el valor se vuelve a multiplicar por 4. En el
//proceso se pierde precisión.
// need to divide by 4 because analog inputs range from
int Valor = analogRead(0) / 4;
//Se almacenan consecutivamente los valores anteriores.
EEPROM.write(Direccion, Informacion);
EEPROM.write(Direccion+1, Valor);
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop()
{
Val1 = EEPROM.read(Direccion);
Val2 = EEPROM.read(Direccion+1);
Serial.print("En la dirección ");
Serial.print(Direccion);
Serial.print(" se encuentra la información: ");
Serial.print(Val1, DEC);// DEC para datos en decimal.
delay(100);
Serial.print("En la dirección ");
Serial.print(Direccion+1);
Serial.print(" se encuentra la información: ");
Serial.print(Val2, DEC);// DEC para datos en decimal.
delay(100);
}

