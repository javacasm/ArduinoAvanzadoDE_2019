// Vamos iluminando los leds consetivamente entre el 8 y 12

int leds[]={3,5,6,9,10};

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
   for(int i=4;i>=0;i=i-1)
   {
      digitalWrite(leds[i],HIGH);
      delay(200);
      digitalWrite(leds[i],LOW);
   }
}
