# Arduino: Nivel avanzado


## José Antonio Vacas @javacasm
## Organiza: Darwin Eventur
## Facultad de Ciencias
## 14 al 17 de Febrero de 2017
##								#Arduino2017

![CC](./images/Licencia_CC_peque.png)

* * *
***

<!-- background: #184bc6-->
<!-- color: #fff -->
<!-- font: centurygothic -->

# Indicador de temperatura (sensor de temperatura)
(podemos usar cualquier sensor de temperatura)

![RTC](http://i56.tinypic.com/scx561.jpg)


* * *

# KIT (registro de desplazamiento)
#### Vamos a encender varios leds de forma consecutiva imitando el efecto que hacía Kit, el coche fantástico

![kit](http://www.gifmania.com/Gif-Animados-Series-Television/Imagenes-Series-Accion/Coche-Fantastico/Kitt-67595.gif)

Usaremos una variable que nos irá diciendo el led que se ha de encender en cada paso.

### montaje

![montaje](../Repaso/imagenes/KIT_CEPL.png)

* * *
# Variables globales

Vamos a usar variables globales para hacer un bucle .

* ContadorVueltas nos dirá el número de iteraciones que ha hecho nuestro programa


![global](../Repaso/imagenes/Globales.png)

* * *
## Números aleatorios

Podemos generar valores aleaotrios con el bloque "Aleatorio" al que le diremos entre qué valores ha de generar los valores. El valor máximo no se alcanza, por lo que si queremos que se incluya tendremos que incrementar el máximo.

Este programa llamado "Discotequero" hace parpadear los leds aleatoriamente durante un tiempo también aleatorio

![alea](../Repaso/imagenes/aleatorio.png)
* * *
![pot](../Repaso/imagenes/Pot.png)

Cambiaremos nuestro programa "Aleatorio" para que el tiempo de espera con el led encendido sea proporcional al valor de espera del led encendido

![aleacont](../Repaso/imagenes/aleatorioControlado.png)

* * *

# Pulsaciones: botones

## Montaje


![circuitoPulsador](http://www.softweb.es/acuario/Esquemas/conexcion%20boya.jpg)

![ejemplo](http://www.ikkaro.com/files/roobre/Arduino/Button.jpg)

## Programa

### Usamos una sentencia condicional: si se cumple esto...se hace aquello
![boton](../Repaso/imagenes/Boton_Led.png)

### Su código

	void setup()
	{
	  pinMode(2,INPUT_PULLUP);  // Usamos 2 como entrada
	  pinMode(13,OUTPUT);		// Usamos 13 como salida
	}


	void loop()
	{
	  if (digitalRead(2) == HIGH)  	// Si el pulsador está pulsado
	  {
	    digitalWrite(13,HIGH);		//Encendemos el led 13
	  }
	  else 							// Si NO se cumple
	  {		
	    digitalWrite(13,LOW);		// Lo apagamos
	  }
	}

* * *
## 2 Pulsadores

Vamos usar 2 pulsadores para mover el led que encenderemos: un pulsador hará que se encienda el led anterior, el otro hará que se encienda el siguiente.

Para ello haremos el siguiente montaje con 6 leds (con resistencias de 330 Ohmios)y 2 pulsadores (con resistencias de 10k)

![6leds+2Pulsdores](../Repaso/imagenes/6leds+2Pulsadores.png)

### Paso 1: 2 pulsadores encienden 2 leds

Empezaremos haciendo un programa que controle 2 leds con 2 pulsadores: cada uno enciende un led

![2leds](../Repaso/imagenes/2Pulsador.png)


### Paso 2: 2 pulsadores que irán encendiendo el led siguiente o el anterior

Utilizamos una variable que vamos incrementando con un pulsador y con otro decrementamos

![kitManual](../Repaso/imagenes/KitManual.png)

(Hay que controlar que cuando lleguemos a un extremo no nos pasemos)

Se añade un retardo para evitar que se detecten varias pulsaciones.

Vemos que hay muchos bloque que se repiten, por lo que para facilitarlo definiremos funciones.

* * *

## Vamos a rehacer el programa usando acceso directo a los puertos


[pinout detallado de las placas](http://www.pighixxx.com/test/pinoutspg/boards/)

![Uno](../images/ARDUINO_UNO_pinout.png)
![Mega](../images/mega_pinout.png)
