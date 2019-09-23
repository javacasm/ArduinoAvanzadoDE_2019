/*

Más información relativa a la librería
http://jeelabs.org/pub/docs/ethercard/index.html

*/
#include <EtherCard.h>

static byte mymac[] = {0xDD,0xDD,0xDD,0x00,0x01,0x05};
static byte myip[] = {192,168,1,177};
byte Ethernet::buffer[700];

const int ledPin = 2;

char* EstadoLed="OFF";

void setup () {
 
  Serial.begin(9600);
  Serial.println("Test del Modulo  ENC28J60");
 
  if (!ether.begin(sizeof Ethernet::buffer, mymac, 10))
    Serial.println( "No se ha podido acceder a la controlador Ethernet");
 else
   Serial.println("Controlador Ethernet inicializado");
 
  if (!ether.staticSetup(myip))
    Serial.println("No se pudo establecer la dirección IP");

  Serial.println();
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

static word homePage() {
  
 BufferFiller bfill = ether.tcpOffset();
 bfill.emit_p(PSTR("<!DOCTYPE HTML PUBLIC \r\n \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd \r\n\">"
     "Pragma: no-cache\r\n"
      "\r\n"
      "<meta http-equiv='refresh' content='1'/>"
      "<html><head><meta charset=\"UTF-8\"><title>Inven Technology Experts</title></head>"
      "<body>"
      "<div style='text-align:center;'>"
      "<h1>Test del Módulo  ENC28J60</h1>"      
      "Tiempo transcurrido : $L segundos"
      "<br /><br />Estado del LED: $S<br />"      
      "<a href=\"/?status=ON\"><input type=\"button\" value=\"ON\"></a>"
      "<a href=\"/?status=OFF\"><input type=\"button\" value=\"OFF\"></a>"
      "<br /><br />Potenciómetro: $D (resolución de 1024)"
      "<br /><br />"
      "<a href='http://www.inven.es/'>www.inven.es</a>"
      "</body></html>"      
      ),millis()/1000,EstadoLed,analogRead(0));
     
  return bfill.position();
}
  
void loop() {
 
  word len = ether.packetReceive();
  word pos = ether.packetLoop(len);
  
  if(pos) {
    // Comprobamos si se recibe status ON por método GET
    if(strstr((char *)Ethernet::buffer + pos, "GET /?status=ON") != 0) {
      Serial.println("Comando ON recibido");
      digitalWrite(ledPin, HIGH);
      EstadoLed = "ON";
    }

    if(strstr((char *)Ethernet::buffer + pos, "GET /?status=OFF") != 0) {
      Serial.println("Comando OFF recibido");
      digitalWrite(ledPin, LOW);
       EstadoLed= "OFF";
    }        
    ether.httpServerReply(homePage()); // se envia página Web
  }
}

