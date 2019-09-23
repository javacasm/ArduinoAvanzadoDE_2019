// Vamos iluminando los leds consecutivamente

int leds[]={3,5,6,9,25};

void setup() {
   for(int i=0;i<=4;i=i+1)
   {
      pinMode(leds[i],OUTPUT);
   }
}

void loop() {
   for(int i=0;i<=4;i=i+1)
   {
      digitalWrite(leds[i],HIGH);
      delay(200);
      digitalWrite(leds[i],LOW);
   }
   for(int i=3;i>0;i=i-1)
   {
      digitalWrite(leds[i],HIGH);
      delay(200);
      digitalWrite(leds[i],LOW);
   }
}
