// INCLUIMOS LAS LIBRERÍAS QUE VAMOS A UTILIZAR

// DECLARACIÓN DE VARIABLES
const int PinLedVerde = 9;
const int PinLedAzul = 10;
const int PinLedRojo = 11;

const int PinEntradaLDR_Rojo = A0;
const int PinEntradaLDR_Verde = A1;
const int PinEntradaLDR_Azul = A2;

int ValorRojo = 0;
int ValorVerde = 0;
int ValorAzul = 0;
 
// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup() {
    Serial.begin(9600);                // inicializamos la comunicación serie
    pinMode(PinLedVerde, OUTPUT);
    pinMode(PinLedAzul, OUTPUT);
    pinMode(PinLedRojo, OUTPUT);
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL) 
void loop() {
    ValorRojo = analogRead(PinEntradaLDR_Rojo)/4;
    delay(5);
    ValorVerde = analogRead(PinEntradaLDR_Verde)/4;
    delay(5);
    ValorAzul = analogRead(PinEntradaLDR_Azul)/4;

    Serial.print("Mapa de color");
    Serial.print(ValorRojo);
    Serial.print(ValorVerde);
    Serial.println(ValorAzul);
    
    analogWrite(PinLedRojo, ValorRojo);
    analogWrite(PinLedVerde, ValorVerde);
    analogWrite(PinLedAzul, ValorAzul);
}

