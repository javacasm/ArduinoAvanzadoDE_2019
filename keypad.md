# Arduino: Nivel avanzado 3ed


## José Antonio Vacas @javacasm
## Organiza: Darwin Eventur
## BiblioMaker - Facultad de Ciencias
## 23 al 27 de Septiembre de 2019

## http://bit.ly/ArduinoAvanzado19

![CC](./images/Licencia_CC_peque.png)



* * *


# Uso de teclados (Keypad)  

![Teclado](https://www.prometec.net/wp-content/uploads/2014/10/Img_19_2-300x273.jpg)

![Teclado2](https://imgaz.staticbg.com/thumb/large/2014/xiemeijuan/01/5xSKU142881/1.jpg)

Internamente son así

![Teclado interno](https://www.prometec.net/wp-content/uploads/2014/10/matrix-keypad-300x244.jpg)

Conectaremos los pines, por ejemplo de esta forma

![pinout](http://www.circuitbasics.com/wp-content/uploads/2017/07/Arduino-Keypad-Tutorial-4X4-and-3X4-Keypad-Connection-Diagram.png)

Y usaremos la librería [Keypad](https://playground.arduino.cc/Code/Keypad/)


        #include<Keypad.h>
        const byte filas = 4;
        const byte columnas = 4;
        byte pinesF[filas] = {9,8,7,6}; // Donde hemos conectado las filas
        byte pinesC[columnas] = {5,4,3,2}; // Donde hemos conectado las columnas
         
        char teclas[filas][columnas] = { // Definición de las teclas
                {'1','2','3','A'},
                {'4','5','6','B'},
                {'7','8','9','C'},
                {'*','0','#','D'}
            };
         
        Keypad teclado = Keypad(makeKeymap(teclas), pinesF, pinesC, filas, columnas);
         
        char tecla;

        void setup() {
            Serial.begin(9600);
        }
        
        void loop() {
            tecla = teclado.getKey();
            if (tecla != 0)
            Serial.print(tecla);
        }

## Más detalles

[Teclados matriciales por Prometec](https://www.prometec.net/teclados-matriciales/)
[Teclados matriciales por Luis Llamos](https://www.luisllamas.es/arduino-teclado-matricial/)
