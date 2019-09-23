// Vamos iluminando los leds consecutivamente

int leds[]={3,5,6,9,10};

void setup() {
   for(int i=0;i<=4;i=i+1)
   {
      pinMode(leds[i],OUTPUT);
   }

   Serial.begin(9600);
}

void miEspera()
{
  int pot=analogRead(A0); // desde 0 a 1023
  Serial.println(pot);
  int espera=map(pot,0,1023,100,500);
  delay(espera);
}

void loop() {

   int ldr=analogRead(A1);
   int brillo=map(ldr,0,1023,0,255);
   for(int i=0;i<=4;i=i+1)
   {
      analogWrite(leds[i],brillo);
      miEspera();
      analogWrite(leds[i],0);
   }
   for(int i=3;i>0;i=i-1)
   {
      analogWrite(leds[i],brillo);
      miEspera();
      analogWrite(leds[i],0);
   }
}
