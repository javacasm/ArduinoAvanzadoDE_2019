// INCLUIMOS LAS LIBRERÍAS QUE VAMOS A UTILIZAR
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// DECLARACIÓN DE VARIABLES
LiquidCrystal_I2C lcd(0x3F, 16, 2);  // Inicia el LCD en la dirección 0x3F, con 16 caracteres y 2 líneas

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup()
{
lcd.begin();				// inicializamos el objeto lcd   
lcd.setCursor(0, 0);	      // Colocamos el cursor para empezar a escribir en 0,0
lcd.print("Linea 1");
lcd.setCursor(0, 1);
lcd.print("Linea 2");
delay(2500);
lcd.clear();			     // Limpiamos el LCD
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL)
void loop()
{
}

