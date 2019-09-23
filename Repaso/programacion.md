# Arduino: Nivel avanzado


## José Antonio Vacas @javacasm
## Organiza: Darwin Eventur
## BiblioMaker - Facultad de Ciencias
## 23 al 27 de Septiembre de 2019

## http://bit.ly/ArduinoAvanzado19

![CC](../images/Licencia_CC_peque.png)
 
***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->

# Programas en Arduino

* Dentro de arduino sólo puede haber **1** programa

* Cada vez que programamos borramos el anterior

* El programa se ejecuta en bucle infinitamente

* No se puede recuperar el código de un programa en ejecución (fácilmente)

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->


# ¿Dónde encontrar más información?

* [Arduino programing Notebook](http://www.ardumania.es/wp-content/uploads/2011/10/Arduino_programing_notebook_ES.pdf)

* [Arduino CheatSheet](https://github.com/liffiton/Arduino-Cheat-Sheet/blob/master/Arduino%20Cheat%20Sheet.pdf?raw=true)

* [Arduino PlayGround](http://playground.arduino.cc/)

* [Referencia de Arduino](http://arduino.cc/en/Reference/HomePage)

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->

## Introducción [Bitbloq](http://bitbloq.bq.com)

Usamos bloques para definir los programas:

* bloques electrónicos (led, pulsadores)
* bloques matemáticos (opearaciones)
* bloques de control (bucles, pausas, condicionales)
* bloques de variables

[Tutoriales bitbloq](http://diwo.bq.com/tag/bitbloq/)

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->

## Parpadeo [Bitbloq](http://bitbloq.bq.com)

* LED encendido
* Esperamos
* LED apagado
* Esperamos

Utilizamos el pin 13 porque ya tiene un led conectado en la placa

[Parpadeo bitbloq](https://github.com/javacasm/Robotica-Educativa-Arduino-y-3D/blob/master/ejemplos/1.%20Parpadeo%20CEP.xml) (Compartido como 1. Parpadeo CEP)

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->

# C++ Parpadeo

![blink](http://arduino.cc/en/uploads/Tutorial/ExampleCircuit_bb.png)

int led = 13;

void setup() {                
  pinMode(led, OUTPUT);     
}

void loop() {
  digitalWrite(led, HIGH);   // Encendemos
  delay(1000);               // Esperamos
  digitalWrite(led, LOW);    // Apagamos
  delay(1000);               // Esperamos
}

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->

# [Bitbloq](http://bitbloq.bq.com)

Montaje en la placa de prototipos

![blink](http://4.bp.blogspot.com/-bSwcT88QabE/UVuMY29lHfI/AAAAAAAAAAw/wyLijXEmafk/s1600/01+Blinky_bb.png)

Ejercicio: Cambiamos al pin 8

¡¡Añadimos la resistencia!!

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->

# [Bitbloq](http://bitbloq.bq.com)
## Semáforo

2 leds (rojo y verde) se alternan


* LED Rojo encendido y Verde apagado
* Esperamos
* LED Rojo apagado y Verde encendido
* Esperamos

[Semáforo bitbloq](https://github.com/javacasm/Robotica-Educativa-Arduino-y-3D/blob/master/ejemplos/Semaforo%20CEP.xml)

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->

# C++ Semáforo

	int ledrojo=8;
	int ledverde=9;
	void setup()
	{ pinMode(ledverde,OUTPUT);
	  pinMode(ledrojo,OUTPUT);
	}
	void loop()
	{ int esperaVerde=1000;
	  int esperaRojo=500;
	  digitalWrite(ledverde,LOW);
	  digitalWrite(ledrojo,HIGH);
	  delay(esperaVerde);
	  digitalWrite(ledrojo,LOW);
	  digitalWrite(ledverde,HIGH);
	  delay(esperaRojo);
	}

[código](https://github.com/javacasm/Robotica-Educativa-Arduino-y-3D/tree/master/codigo/Semaforo)

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->

# C++ Semáforo con salida serie

## Enviaremos al PC el estado del semáforo

	int ledrojo=8;
	int ledverde=9;
	void setup()
	{ pinMode(ledverde,OUTPUT); // Vamos a usarlo como salida
	  pinMode(ledrojo,OUTPUT); // Vamos a usarlo como salida
	  Serial.begin(9600); // Inicializamos la comunicación con el PC
	}
	void loop()
	{ int esperaVerde=1000;
	  int esperaRojo=500;

	  digitalWrite(ledverde,LOW);
	  digitalWrite(ledrojo,HIGH);
	  // Estamos en ROJO
	  Serial.println("ROJO");
	  delay(esperaVerde);
	  digitalWrite(ledrojo,LOW);
	  digitalWrite(ledverde,HIGH);
	  // Estamos en VERDE
	  Serial.println("VERDE");
	  delay(esperaRojo);
	}

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->

# Números decimales

Usaremos el tipo de variable float
### Ejemplo: Voltímetro
* Leemos el valor de un potenciómetro conectado a una entrada analógica (A0)
* Convertimos el valor (0-1023) a 0 - 5.0v
* Sacamos el valor por la consola serie

* Calibramos viendo los extremos y el valor intermedio 3.3V

[código](https://github.com/javacasm/Robotica-Educativa-Arduino-y-3D/tree/master/codigo/voltimetro)

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->
## Sentencias de control [Bitbloq](http://bitbloq.bq.com)

* Bucles
	Ejercicio: Hacer 10 parpadeos, esperar 2 segundos, 10 parpadeos, 2 segundos...

* Condicionales
	Ejercicio: En función del valor de un potenciómetros encender 2 leds: Por debajo de 300 rojo, mayor de 600 verde y en medio ninguno.

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->
##  Salidas analógicas

* Distintos rangos:  
entradas 0-1023
salidas 0-255
* Mapeo de valores
* Concepto de PWM

* Ejemplo 1: Led
* Ejemplo 2: Led RGB (inversión de niveles)
* Ejemplo 3: circuito electrónico equivalente

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->
# Detectar una pulsación

Debemos conectar el pin a GND para grantizar el estado LOW si está desconectado: PullDown

![botón](http://playground.arduino.cc/uploads/Main/FGFS_basics_pushbutton.jpg)

if(digitalRead(pinBoton)==HIGH)
{  .....}

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->
# Medidas con sensores

Podemos pensar en los sensores como un circuito externo que tenemos que alimentar conectando a 5v y GND (divisor de tensión)

![divisor de tensión](http://panamahitek.com/wp-content/uploads/2014/01/fotoresistor.png)

Estudiar el comportamiento con la luz

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->
# LDR (célula fotoeléctrica)

Ejemplo: activaremos un led al pasar de determinado nivel de luz
![montaje LDR](http://s3rgiosan.com/workshop-arduino/sketches/sketch5b.png)

Ejemplo LDR Umbral 3 Leds

![ldr](imagenes/LDR_umbral.png)

Ejemplo 2: Regular el nivel con un potenciometro.  Documentarlo.

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->
# Termistor (sensor de temperatura)
[Documentación del kit](http://www.seeedstudio.com/wiki/Sidekick_Basic_Kit_for_Arduino_V2#Thermistors)  

[foros](http://www.seeedstudio.com/forum/viewtopic.php?f=16&t=2117&p=14846&hilit=thermistor#p14846)  

[fabricante](http://www.seeedstudio.com/forum/download/file.php?id=1345)

![RTC](http://i56.tinypic.com/scx561.jpg)

***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->
## Librerías

* Concepto de librería (POO)
* Cómo incluirlas
* Instalación de librerías

* Ejemplo: control de servo con potenciómetro

* Ejemplo: librería [Time](http://playground.arduino.cc/Code/Time)
