#include <SD.h>

File myFile;
int cspin=4;
int UltimaPocicion=0;
int pausa=1000;
int PinLeds[8]={2,3,5,6,7,8,9,10};//Pines de los Leds
void setup()
{
  Serial.begin(9600);
  Serial.print("Iniciando SD ...");
  if (!SD.begin(cspin)) {
    Serial.println("No se pudo inicializar");
    return;
  }
  Serial.println("inicializacion exitosa");
  for(int i=0;i<8;i++)
  {
    pinMode(PinLeds[i],OUTPUT);
  }
 
}
void loop()
{
  myFile = SD.open("Leds.txt");//abrimos  el archivo
  int totalBytes=myFile.size();
  String cadena="";
  
  if (myFile) {   
      if(UltimaPocicion>=totalBytes)   UltimaPocicion=0;
      myFile.seek(UltimaPocicion); 
      
      //--Leemos una línea de la hoja de texto--------------
      while (myFile.available()) {
          
      	char caracter=myFile.read();
          cadena=cadena+caracter;
          UltimaPocicion=myFile.position();
          if(caracter==10)//ASCII de nueva de línea
          {            
            break;
          }
      }
      //---------------------------------------------------
      myFile.close(); //cerramos el archivo
      Serial.print("Cadena Leida:");
      Serial.print(cadena);
      //-----------procesamos la cadena------------
      int index=0;
      char c=cadena[index++];
      pausa=0;
      while (c >= '0' && c <= '9')
      {
        pausa = 10*pausa + (c - '0');
        c = cadena[index++];
      }
      Serial.print("pausa=");
      Serial.print(pausa);
      Serial.print("   LEDS |");
      for(int i=0;i<8;i++)
      {     
        if(cadena[index+i*2]=='1')
        {
          digitalWrite(PinLeds[i], HIGH);
          Serial.print(" 1 |");
         
        }
        else
        {
          digitalWrite(PinLeds[i], LOW);
          Serial.print(" 0 |");
        } 
      }
      Serial.println();
      Serial.println();    
  
  } else {	
    Serial.println("Error al abrir el archivo");
  }
  delay(pausa);
}

