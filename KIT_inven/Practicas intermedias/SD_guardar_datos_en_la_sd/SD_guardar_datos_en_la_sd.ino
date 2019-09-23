#include <SD.h>
File myFile;
int cspin=4;

void setup()
{
  Serial.begin(9600);
  Serial.print("Iniciando SD ...");
  if (!SD.begin(cspin)) {
    Serial.println("No se pudo inicializar");
    return;
  }
  Serial.println("inicializacion exitosa");
}

void loop()
{
  myFile = SD.open("datalog.txt", FILE_WRITE);//abrimos  el archivo
  
  if (myFile) { 
        Serial.print("Escribiendo SD: ");
        int sensor1 = analogRead(0);
        int sensor2 = analogRead(1);
        int sensor3 = analogRead(2);
        myFile.print("Tiempo(ms)=");
        myFile.print(millis());
        	
        myFile.print(sensor1);
        myFile.print(", sensor2=");
        myFile.print(sensor2);
        myFile.print(", sensor3=");
        myFile.println(sensor3);
        
        myFile.close(); //cerramos el archivo
        
        Serial.print("Tiempo(ms)=");
        Serial.print(millis());
        Serial.print(", sensor1=");
        Serial.print(sensor1);
        Serial.print(", sensor2=");
        Serial.print(sensor2);
        Serial.print(", sensor3=");
        Serial.println(sensor3);       
                  
  } else {
    Serial.println("Error al abrir el archivo");
  }
  delay(100);
}

