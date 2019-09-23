// INCLUIMOS LAS LIBRERÍAS
#include <SPI.h>
#include <RFID.h>

// DECLARACIÓN DE VARIABLES Y OBJETOS
#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN,RST_PIN);

int led = 7;            // PIN indicación de acceso permitido
int serNum[5];
int clave_ok = 0;
bool access = false;
int cards[][5] = {
  {180,17,121,26,200},
  {200,27,221,46,592},
  {180,17,121,26,198},
  {37,30,255,176,116}
};                      // Lista de Array de Tarjetas permitidas
// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup(){

    Serial.begin(9600);     // Iniciamos puerto serie
    SPI.begin();            // Iniciamos protocolo SPI
    rfid.init();            // Iniciamos Objeto RFID

    pinMode(led, OUTPUT);   // iniciamos El PIN del led como salida
    digitalWrite(led, LOW);
    pinMode(power, OUTPUT);   // iniciamos El PIN del rele como salida
    digitalWrite(power, LOW);   
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop(){
    if(rfid.isCard()){   // Detectamos la presencía de una tarjeta en el lector
        if(rfid.readCardSerial()){
            Serial.print(rfid.serNum[0]);
            Serial.print(" ");
            Serial.print(rfid.serNum[1]);
            Serial.print(" ");
            Serial.print(rfid.serNum[2]);
            Serial.print(" ");
            Serial.print(rfid.serNum[3]);
            Serial.print(" ");
            Serial.print(rfid.serNum[4]);
            Serial.println("");
            // Comprobamos cada uno de los valores del array de cards permitidas
            for(int x = 0; x <=(sizeof(cards)/2); x++){
              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
                  if(rfid.serNum[i] == cards[x][i]) {
                      clave_ok++;
                      if(clave_ok==5) { 
                        access = true;
                        break;
                      }
                      else access = false; 
                   } 
              }
          }

      }
    } // Cerramos la lectura de la tarjeta RFID
        
clave_ok=0; 
       if(access){
          Serial.println("BIENVENIDO!");
           digitalWrite(led, HIGH);
           delay(2000);
           digitalWrite(led, LOW);
           access = false;
           
      } else {
           Serial.println("NO PERMITIDO!"); 
           digitalWrite(led, HIGH);
           delay(500);
           digitalWrite(led, LOW); 
           delay(500);
           digitalWrite(led, HIGH);
           delay(500);
           digitalWrite(led, LOW);         
       }           
    
    rfid.halt(); //Ponemos el Módulo RFID en hibernación

}

