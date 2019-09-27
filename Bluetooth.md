# Arduino: Nivel avanzado 3ed


## José Antonio Vacas @javacasm
## Organiza: [Darwin Eventur](https://www.darwineventur.com/2019/07/arduino-avanzado-3a-edicion.html)
## BiblioMaker - Facultad de Ciencias
## 23 al 27 de Septiembre de 2019

## http://bit.ly/ArduinoAvanzado19
![CC](./images/Licencia_CC_peque.png)



## Comunicaciones bluetooth


Una vez podemos comunicarnos vía puerto serie el pasar a comunicaciones inalámbricas es  sencillo con bluetooth.

Existen unos dispositivos capaces de enviar al dispositivo con el que están emparejados los datos que ellos reciben por sus pines.

En esta imagen podemos ver uno de ellos. Bajo este aspecto existen diferentes tipos de dispositivos. 
Para hacer lo que pretendemos basta la versión más básica, que será un bluetooth de tipo esclavo (los master pueden costar hasta 4 veces más)

La conexión con Arduino es muy sencilla (sólo hay que tener en cuenta que hay que conectar con los cables cruzados: TX-RX y RX-TX)


![Conexion](http://www.naylampmechatronics.com/img/cms/Blog/Tutorial%20Bluetooth/Tutorial%20HC-06%201.jpg)


El código para controlar un rele via bluetooth es muy sencillo

    const int rele=9;

    void setup() {
      Serial.begin(9600);
      pinMode(rele,OUTPUT);
    }

    void loop() {
      while(Serial.available()>0)
      {
        int iChar=Serial.read();
        Serial.println((char)iChar);
        if(iChar=='1')   // Un caracer '1' lo enciende y cualquier otro lo apaga
          digitalWrite(rele,HIGH);
        else
         digitalWrite(rele,LOW);
      }
    }

Para controlar desde el móvil, debemos emparejar el Bluetooth con nuestro móvil y utilizando alguna aplicación que nos permita enviar datos como por ejemplo Blueterm. Existen mucha aplicaciones que nos permiten controlar muchas funciones, basta con buscar "arduino bluetooth" en google play

En [este vídeo](https://youtu.be/N04DzxnTXqA) vemos cómo utilizarlos y configurarlos


En el [siguiente vídeo](https://youtu.be/j5j-pfIGdoM) vamos a usar un dispositivo bluetooth para activar un rele remotamente desde un móvil
