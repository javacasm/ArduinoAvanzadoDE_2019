// INCLUIMOS LAS LIBRERÍAS QUE VAMOS A UTILIZAR


// DECLARACIÓN DE VARIABLES
const int pin_buzzer_activo = 9;

// INICIALIZACIÓN DEL PROGRAMA (SE EJECUTA SOLO UNA VEZ)
void setup()
{
  pinMode(pin_buzzer_activo, OUTPUT);  //definir pin como salida
}

// LOOP CENTRAL DEL PROGRAMA (SE EJECUTA CONSTANTEMENTE DE FORMA SECUENCIAL)
void loop()
{
  digitalWrite(pin_buzzer_activo, HIGH);   // poner el Pin en HIGH
  delay(5000);               // esperar 5 segundos
  digitalWrite(pin_buzzer_activo, LOW);    // poner el Pin en LOW
  delay(20000);               // esperar 20 segundos

}

