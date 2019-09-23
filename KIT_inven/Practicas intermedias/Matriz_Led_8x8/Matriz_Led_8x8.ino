// DECLARACIÓN DE VARIABLES 
// En el siguiente array pin[0..16] (la posición 0 es ficticia y sirve para iniciar el indice de la matriz en 1) 
// Se trata de esquematizar la conexión de pines en la matriz LED
// Tenga presente que los pines 14 ... 17 corresponden respectivamente a:
//    A0 => 14-esimo pin de arduino
//    A1 => 15-esimo pin de arduino
//    A2 => 16-esimo pin de arduino
//    A3 => 17-esimo pin de arduino
int pins[17]= {-1, 5, 4, 3, 2, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6};

int cols[8] = {pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]};
int rows[8] = {pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};

// DECLARACIÓN DE FUNCIONES
void AllLedOFF()  // Creamos una función que apaga todos los LEDS
{
  for (int i = 1; i <= 8; i++)
  {
        digitalWrite(cols[i - 1], LOW);
        digitalWrite(rows[i - 1], HIGH);
  }
}

void LedON(int r, int c)      //Encendemos el LED en la posición fila R y columna R
{
  AllLedOFF();
  digitalWrite(cols[c - 1], HIGH);
  digitalWrite(rows[r - 1], LOW);
  delay(100);
}

void AllLedON()     // Creamos una función que enciende todos los LEDS
{
  for (int i = 1; i <= 8; i++)
  {
        digitalWrite(cols[i - 1], HIGH);
        digitalWrite(rows[i - 1], LOW);
  }
  delay(1000);
  AllLedOFF();
}

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup() 
{
  // Definimos todos los pin de Arduino como pines de salida
  for (int i = 1; i <= 16; i++)
      pinMode(pins[i], OUTPUT);
  // Ponemos todos los LED la matriz apagados
  AllLedOFF();
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop()
{
  int i, c, r;

  // Vamos encendiendo los LED por columnas de izquierda a derecha
  for (c=1; c<=8; c++)
  {
    for (r=1; r<=8; r++)
       digitalWrite(rows[r - 1], LOW);
    digitalWrite(cols[c - 1], HIGH);
    delay(300);
    digitalWrite(cols[c - 1], LOW);
    for (r=1; r<=8; r++)
       digitalWrite(rows[r - 1], HIGH);
  }
  
  // Vamos enciando los LED por filas de abajo a arriba
  for (r=1; r<=8; r++)
  {
    for (c=1; c<=8; c++)
       digitalWrite(cols[c - 1], HIGH);
    digitalWrite(rows[r - 1], LOW);
    delay(300);
    digitalWrite(rows[r - 1], HIGH);
    for (i=1; i<=8; i++)
      digitalWrite(cols[i - 1], LOW);
  }
  
  // Encendemenos cada led independiente desde la primera posición hasta la 64 
  for (r=1; r<=8; r++)
    for (c=1; c<=8; c++)
      LedON(r,c);
  AllLedOFF();
  // AllLedON();   
}

