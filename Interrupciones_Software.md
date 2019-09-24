## Interrupciones
Las interrupciones son un recurso de los modernos procesadores que permiten detener la ejecución del programa principal para atender un evento (suceso) determinado, realizar algunas acciones y luego retomar la ejecución del programa principal por el punto en el que se detuvo.

De esta manera podemos hacer nuestro programa más simple, programando de forma independiente las reacciones a determinados eventos.

Para ellos crearemos una función que se encargará de realizar el procesamiento de este evento y que tendrá el siguiente formato:

  void funcionInterrupcion(){
  // Código de procesamiento de la interrupcion
  }


El código de estas funciones debe ser lo más breve posible ya que mientras el se procesa una interrupción no se atienden otras tareas que el micro debe hacer (como controlar las señales pwm, de servos, medir el tiempo, etc) Por tanto dentro del código de estas funciones está desaconsejado usar métodos como delay y los relacionados con el envío de datos vía Serial

Estos eventos pueden estar originados por el hardware (cambios en el estado de algún pin) o por un temporizador (parecido a una alarma) que llamaremos de tipo Software

Más adelante hablaremos de las interrupciones hardware, aquellas que se producen cuando el estado de alguna de las patillas cambia.

## Interrupciones software

Las interupciones software se producen por tiempo, es parecido a cuando programamos una alarma en un despertador:
* Configuramos un temporizador (timer en lenguaje técnico) con un tiempo determinado
* Activamos el timer
* Asignamos una función que será llamada cuando llegue ese momento

¿Qué es un timer? : es un hardware independiente al microprocesador que va contando el tiempo de forma  paralela al microprocesador

Todos los timers dependen del system clock de Arduino. Normalmente es 16MHz, salvo Arduino Pro 3,3V con 8Mhz. El ritmo al que cambian estos contadores viene dado por un registro del micro que se llama [prescaler](https://playground.arduino.cc/Code/Prescaler). Por ejemplo, un prescaler de 1000, hará que cada 1000 ciclos del microprocesador, se incremente e1 valor del temporizador.

Los Timers son usados internamente por el core de Arduino para sus funciones internas, como pueden ser millis, delay, analogWrite,..

El microcontrolador de las placas Arduino UNO dispone de 3 módulos Contador/Timers, dos de 8 bits y uno de 16 bits. El tamaño en bits nos da idea de hasta que valores pueden contar.


Las placas de Arduino  Mega tienen además otros timer: timer3, timer4 y timer5 todos de 16bit


* Timer0: Timer0 es un timer de 8bit. Arduino UNO lo usa para delay(), millis() y micros().
* Timer1: Timer1 es un timer de 16bit. Arduino UNO lo usa para controlar los Servos (timer5 en Arduino Mega).
* Timer2: Timer2 is a 8bit timer like timer0. Se usa para tone()

Las interrupciones se pueden activar o desactivar, usando las llamadas [**interrupts**](https://www.arduino.cc/reference/en/language/functions/interrupts/interrupts/) y [**noInterrupts**](http://arduino.cc/en/Reference/NoInterrupts).

Para configurar un temporizador con tiempo determinado son muchos los registros que hay que configurar y el cálculo de sus valores no es algo sencillo. Podemos leerlo en detalle en el [siguiente enlace](http://arduino.cc/es/Tutorial/SecretsOfArduinoPWM)

Afortunadamente existen librerías que nos facilitan enormemente la tarea.

## Librería TimerOne

Es una librería que nos permite trabajar con interrupciones software de maner muy sencilla usando el Timer1

La instalamos desde el gestor de librería y podemos usar directamente sus ejemplos

La libería nos permite hacer varias cosas (a coste de perder el PWM de los pines 9 y 10)

    void initialize(long microseconds=1000000); // Inicializamos el periodo de disparo en microsegundos
    void start();               // Arrancamos el temporizador
    void stop();                // Para el temporizador
    void restart();             // Lo rearranca por donde iba
    unsigned long read();       // tiempo hasta disparo
    void setPeriod(long microseconds);  // cambia el periodo
    void pwm(char pin, int duty);  // para usar pwm en pines 9 y 10
    void setPwmDuty(char pin, int duty);
    void disablePwm(char pin);     // desactiva pwm en 9 y 10
    void attachInterrupt(funcionDisparo);   // establece la función de disparo
    void detachInterrupt();                 // elilmina la función de disparo


Veamos un [ejemplo](https://github.com/javacasm/ArduinoCompletoDE2018/blob/master/material/codigo/ejemploInterrupcionesSoftware.ino) de uso en el que haremos que un led cambie de estado cada segundos



      #include <TimerOne.h>

      #define PIN_LED 13

      void setup() {

        pinMode(PIN_LED , OUTPUT);

        Timer1.initialize(1000000);   // 500000 microseconds o 0.5 segundo  
        Timer1.attachInterrupt( funcionDisparo ); // establecemos la funcion de disparo
        Timer1.start();  // Arancamos la interrupción

      void loop()   {
         // Mientras podemos hacer en el loop otras cosas...
      }

      void funcionDisparo()  {

        if(digitalRead(PIN_LED) == HIGH ){  // Invertimos el estado del led
            digitalWrite( PIN_LED, LOW);
        } else {
          digitalWrite( PIN_LED, HIGH );
        }
      }


Ahora puedes revisar el ejemplo "Interrupt" de la librería


[Vídeo sobre interrupciones software](https://www.youtube.com/embed/oG73lT56m7A)

Éste [otro código](https://github.com/javacasm/ArduinoCompletoDE2018/blob/master/material/codigo/ejemploSemaforoInterrupciones.ino) implementa un semáforo por medio de interrupciones por software


        #include <TimerOne.h>

        #define ROJO        7
        #define AMARILLO    8
        #define VERDE       9

        #define BASE_TIEMPO 100000
        #define DURACION_ROJO     50*BASE_TIEMPO
        #define DURACION_VERDE    10*BASE_TIEMPO
        #define DURACION_AMARILLO 5*BASE_TIEMPO

        // Esto es un semáforo hecho con 3 Leds conectados a las patillas 7, 8 y 9
        //
        // Para hacer el cambio entre estados se usan interrupciones por tiempo

        void setup() {
          pinMode(ROJO,OUTPUT);
          pinMode(VERDE,OUTPUT);
          pinMode(AMARILLO,OUTPUT);
          

          Timer1.initialize(DURACION_ROJO);
          Timer1.attachInterrupt(semaforo);
          
          digitalWrite(ROJO,HIGH);      // encendemos el rojo
          digitalWrite(VERDE,LOW);      // apagamos el verde
          digitalWrite(AMARILLO,LOW);   // apagamos el amarillo
        }

        int estado = 0; // Se usa 0 para rojo, 1 para verde y 2 para ámbar
        void semaforo() {
          switch (estado) {
            case 0: // Estaba en rojo, cambia a verde, que dura menos tiempo
              digitalWrite(ROJO,LOW);      // apagamos el rojo
              digitalWrite(VERDE,HIGH);      // encendemos el verde
              digitalWrite(AMARILLO,LOW);   // apagamos el amarillo
              Timer1.setPeriod(DURACION_VERDE);
              break;
            case 1: // Estaba en verde, cambia a ámbar, que dura todavía menos
              digitalWrite(ROJO,LOW);      // apagamos el rojo
              digitalWrite(VERDE,LOW);      // apagamos el verde
              digitalWrite(AMARILLO,HIGH);   // encendemos el amarillo
              Timer1.setPeriod(DURACION_AMARILLO);
              break;
            case 2: // Estaba en ámbar, cambia a rojo y restablece el periodo original
              digitalWrite(ROJO,HIGH);      // encendemos el rojo
              digitalWrite(VERDE,LOW);      // apagamos el verde
              digitalWrite(AMARILLO,LOW);   // apagamos el amarillo
              Timer1.setPeriod(DURACION_ROJO);
              break;
          }
          estado = (estado + 1) % 3;   // Pasamos de un estado a otro pasando del 2 al 0
        }

        void loop() {

        }
