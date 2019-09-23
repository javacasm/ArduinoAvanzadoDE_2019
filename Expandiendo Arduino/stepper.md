# Arduino: Nivel avanzado


## José Antonio Vacas @javacasm
## Darwin Eventur
![logo](images/darwincolorv2.png)
## Facultad de ciencias
## 13 al 17 de Julio de 2015 
##								#ARDUINO2015

![CC](https://licensebuttons.net/l/by-sa/3.0/88x31.png)

* * * 

![stepper](http://42bots.com/wp-content/uploads/2014/02/stepper01.jpg)

28BYJ-48:
* pequeño
* barato (5$)
* 5v (hasta 12v)
* con reducción *approximadamente* 64:1
  

|Motor Type|	Unipolar stepper motor|
| --|--|
|Connection Type|	5 Wire Connection (to the motor controller)|
|Voltage|	5-12 Volts DC|
|Frequency|	100 Hz|
|Step mode|	Half-step mode recommended (8 step control signal sequence)
|Step angle|	Half-step mode: 8 step control signal sequence (recommended) 5.625 degrees per step / 64 steps per one revolution of the internal motor shaftFull Step mode: 4 step control signal sequence 11.25 degrees per step / 32 steps per one revolution of the internal motor shaft|
|Gear ratio|	Manufacturer specifies 64:1. Some patient and diligent people on the Arduino forums have disassembled the gear train of these little motors and determined that the exact gear ratio is in fact 63.68395:1. My observations confirm their findings. These means that in the recommended half-step mode we will have:64 steps per motor rotation x 63.684 gear ratio = 4076 steps per full revolution (approximately).|
|Wiring to the ULN2003 controller|	A (Blue), B (Pink), C (Yellow), D (Orange), E (Red, Mid-Point)|
|Weight|	30g|

![interno](http://42bots.com/wp-content/uploads/2014/02/28BYJ-48-Stepper-Motor.jpg)

![driver](http://42bots.com/wp-content/uploads/2014/02/UNL2003-board.jpg)

## código


Usaremos la librería [AccelStepper](http://www.airspayce.com/mikem/arduino/AccelStepper/)

	#include <AccelStepper.h>
	#define HALFSTEP 8

	// Motor pin definitions
	#define motorPin1  3     // IN1 on the ULN2003 driver 1
	#define motorPin2  4     // IN2 on the ULN2003 driver 1
	#define motorPin3  5     // IN3 on the ULN2003 driver 1
	#define motorPin4  6     // IN4 on the ULN2003 driver 1

	// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
	AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

	void setup() {
	  stepper1.setMaxSpeed(1000.0);
	  stepper1.setAcceleration(100.0);
	  stepper1.setSpeed(200);
	  stepper1.moveTo(20000);

	}//--(end setup )---

	void loop() {

	  //Change direction when the stepper reaches the target position
	  if (stepper1.distanceToGo() == 0) {
	    stepper1.moveTo(-stepper1.currentPosition());
	  }
	  stepper1.run();
	}

Resumido de [aquí](http://42bots.com/tutorials/28byj-48-stepper-motor-with-uln2003-driver-and-arduino-uno/)