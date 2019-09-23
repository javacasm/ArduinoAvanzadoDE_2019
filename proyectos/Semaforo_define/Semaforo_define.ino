#define LED_ROJO 10
#define LED_AMARILLO 9
#define LED_VERDE 8
#define ON(x) digitalWrite(x,HIGH)
#define OFF(x) digitalWrite(x,LOW)

void setup() {
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
}


void loop() {
  int espera=1000;
  
  ON(LED_ROJO);
  delay(espera);   
  
  OFF(LED_ROJO);

  for(int i=0;i<10;i=i+1)
  {
    ON(LED_AMARILLO);
    delay(espera/10);   

    OFF(LED_AMARILLO);
    delay(espera/10);   
  }

  
  ON(LED_VERDE);
  delay(espera);
  OFF(LED_VERDE);



  
}
