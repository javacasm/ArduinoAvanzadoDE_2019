# Arduino: Nivel avanzado


## José Antonio Vacas @javacasm
## Organiza: Darwin Eventur
## Facultad de Ciencias
## 14 al 17 de Febrero de 2017
##								#Arduino2017

![CC](./images/Licencia_CC_peque.png)

* * *

# Proyecto: termostato configurable y que activa un relé

[Proyecto 1](https://arduinolab.wordpress.com/)
![proyecto](https://raw.githubusercontent.com/javacasm/CursosPresenciales/master/Basico/imagenes/arduino-humidity-and-temperature-monitor_bb.jpg)

[Proyecto 2](http://www.electroschematics.com/8998/arduino-temperature-controlled-relay/)
![proyecto2](https://raw.githubusercontent.com/javacasm/CursosPresenciales/master/Basico/imagenes/arduino-lcd-lm35-550x309.jpg)

## Veamos los componentes:

* Sensor lm35 conectado a A0
* Potenciómetro conectado a A1
* Relé conectado a D7
* LCD conectado a A4 y A5

## Programa

Comparamos el valor leido del potenciómetro con el leído del potenciómetro.
Si este es máyor activamos el relé
Mostramos en el lcd la temperatura actual
