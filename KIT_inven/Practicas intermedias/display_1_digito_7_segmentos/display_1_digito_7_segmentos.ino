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
void Display(int N)
   {
       for (int i= 0 ; i<8 ; i++)
            {   int valor = Digit[N][i] ;
                int pin = i+2;
                digitalWrite(pin , valor) ;
            }
   }

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup()
   {   for (int i= 2; i<11; i++)
            pinMode(i, OUTPUT);
   }


// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop()
   {
       for ( int k=0 ; k<10 ; k++)    // Llama a Display para k de 0 a 9, los digitos
         {  Display(k);
            delay(1000);
         }
   }

