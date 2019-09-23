// INCLUIMOS LAS LIBRERÍAS QUE VAMOS A UTILIZAR
#include <Keypad.h>

// DECLARACIÓN DE VARIABLES
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13, 12, 11, 10}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad myKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup(){
  Serial.begin(9600);
}
// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop(){
  char Key = myKeypad.getKey();
  
  if (Key){
    Serial.println(Key);
  }
}
Una vez recogido el dato, podemos almacenarle en un array para ser comparado o compararte directamente con el dato obtenido, por ejemplo:
Int posición = 0;
Char CodigoSecreto = “25668”
If (key == CodigoSecreto[posicion])
{
Posicion ++;
}
If (posicion == 5)
{
// El código marcado el correcto
}

