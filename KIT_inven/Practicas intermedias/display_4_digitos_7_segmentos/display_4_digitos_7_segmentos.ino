// DECLARACIÓN DE VARIABLES 
byte  Digit[10][8] =                // Arduino UNO va muy justo de memoria. Por eso lo
{                                   // definimos como byte y no como int
   { 1,1,1,1,1,1,0,0 },    // 0   
   { 0,1,1,0,0,0,0,0 },    // 1
   { 1,1,0,1,1,0,1,0 },    // 2
   { 1,1,1,1,0,0,1,0 },    // 3
   { 0,0,1,0,0,1,1,0 },    // 4
   { 1,0,1,1,0,1,1,0 },    // 5
   { 1,0,1,1,1,1,1,0 },    // 6
   { 1,1,1,0,0,0,0,0 },    // 7
   { 1,1,1,1,1,1,1,0 },    // 8
   { 1,1,1,0,0,1,1,0 }     // 9
};

// DECLARACIÓN DE FUNCIONES
void Display(int pos, int N)
   {  
       digitalWrite(9 ,LOW);        // Apaga todos los digitos
       digitalWrite(10,LOW);
       digitalWrite(11,LOW);
       digitalWrite(12,LOW);
 
      for (int i= 0 ; i<8 ; i++)    // Esto no cambia de la session anterior
            digitalWrite(i+2 , Digit[N][i]) ;

      digitalWrite(pos + 9, HIGH);      // Enciende el digito pos
  }
void CalculaDigitos( int Num)
   {
    //2386 % 10 = 6          Porque el %  nos devuelve el resto de dividir por 10, o sea 6.
    //2386 % 100 = 86        Ahora hacemos la división entera por 10 o sea 8,los decimales se tiran
    //2386 % 1000 = 386      386 / 100 = 3
    //2386  / 1000 = 2       Directamente, para eso se inventó la división entera.
      int Digit0 = Num %10 ;
      int Digit1 = (Num % 100) / 10 ;
      int Digit2 = (Num % 1000) / 100 ;
      int Digit3 = Num  / 1000)  ;

      Display(3 , Digit3);
      Display(2 , Digit2);
      Display(1 , Digit1);
      Display(0 , Digit0);
   }

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup()
    {
      for (int i= 2; i<13; i++){
        pinMode(i, OUTPUT);
      }
    }


// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop()
   {
       int n = millis() / 1000 ;       // Lo pasamos a segundos
       int segundos = n % 60  ;
       int minutos =  n / 60  ;

       int k = minutos * 100 + segundos ;
       CalculaDigitos(k) ;
   }

