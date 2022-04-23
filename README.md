# DC motor direction control using Arduino

## Introduction
The direction of a DC motor can be controlled with the help of a microcontroller such as Arduino. The manual input in order to control the direction is given to the microcontroller board with the help of a potentiometer.The microcontroller gives appropriate signals to the input pins of a motor driver which in turn drives a dc motor in the required direction

## Overview of few terms
### 1. Potentiometer
<p>Potentiometer is a simple mechanical device which provides varying amount of resistance when its shaft is turned.When a voltage is applied across Vcc and GND pin of the potentiometer, it acts as a voltage divider.The voltage taken out from output pin can be varied by varying the potentiometer resistance.This output can be given to any of the analog pins of a microcontroller such as arduino and can act as a manually controlled signal.</p>
<p align="left">
  <img src="images/potentiometer.jpg" alt="Potentiometer" style="height:250px"/>
</p>

### 2. PWM
<p>Which stands for pulse width modulation is a process of varying the time for which a pulse remains ON. This way the average power delivered by a signal can be controlled. The longer the pulse remains ON compared to its OFF time, the higher the total power supplied to the load.</p>
<p>Duty cyle represents the proportion of ON time of a pulse to its total time period. It is represented in percentage.</p>
</br>
<p align="left">
  <img src="images/Duty_Cycle_Examples.png" alt="PWM examples" style="height:250px"/>
</p>
</br>
An Arduino uno has 6 PWM output pins (3,5,6,9,10,11) labeled with ~ sign. PWM signals can be given using the in-built function "analogWrite()" in Arduino IDE.
</br>

### 3. L298N
<p>L298N is a dual channel motor driver. The H bridge is used to control the direction of the motors by provding HIGH(1) and LOW(0) signals to the direction control pins (IN1,IN2,IN3,IN4).The speed can be controlled by proving PWM signals to these pins.</p>
<p align="left">
  <img src="images/l298n.avif" alt="L298N" style="height:250px"/>
</p>

## Components and supplies
<ul>
<li>Arduino Uno X 1</li>
<li>DC motor(generic) X 1</li>
<li>Jumper wires(generic) X 1</li>
<li>Potentiometer - 10k ohms X 1</li>
<li>L298N motor driver X 1</li>
<li>USB A to B cable X 1</li>
</ul>

## Circuit diagram
## Circuit diagram
<p align="left">
  <img src="images/7-n-1024x651.avif" alt="Circuit diagram" style="height:250px"/>
</p>


## Working 
<p>The voltage at the ouput pin of the potentiometer is varied by turning the potentiometer's shaft The output voltage is fed into arduino as analog input at pin A0 of arduino.The "analogRead()" function is used to read the votage at the pin.</p>
<p>The arduino has a Analog to Digital converter or ADC which convert this analog input to a value in the range <strong>0 to 1023</strong>. This input value is divided into two parts: 
</br>
1. The values in the range <strong>0 to 511</strong> indicate to run the motor in clockwise direction. Thus the PWM output is given at pin 3 of Arduino to input pin IN1 of the L298N motor driver. 
</br>
2. The values in the range<strong>512 to 1023</strong>indicate to run the motor in anticlockwise direction.Thus the PWM output is given at pin 5 of Arduino to input pin IN2 of the L298N motor driver. 
</br>
Both the ranges are mapped to a value in the range <strong>0 to 255</strong> using "map()" function. The mapped value is fed as PWM output to the L298N motor driver which in turn drives the dc motor connected to the output pins of the driver at the desired speed and direction</p>

## Code
Code used to program the arduino
<details>
<summary>Click to expand code...</summary>
<p>

```c++
void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT); // direction control pin given to IN1 of L298N driver
  pinMode(5,OUTPUT); // direction control pin given to IN2 of L298N driver
  pinMode(A0,INPUT);  // analog pin to read 10k potentiometer ouput
}

void loop() {
  int s=analogRead(A0); // read 10k potentiometer output
  int z = 0;
  if (s < 512) {
    int z=map(512-s,0,512,0,255);
    analogWrite(5,0); // disable anticlockwise rotation of dc motor shaft
    if (z>50){
    analogWrite(3,z); // drive the motor in clockwise direction
    }
    Serial.println(z);
  }
  else {
    int z=map(s-512,0,512,0,255);
    analogWrite(3,0); // disable clockwise rotation of dc motor shaft
    if (z>50){
    analogWrite(5,z); // drive the motor in anticlockwise direction
    }
    Serial.println(z);
  }
}
```

</p>
</details>

## Resources
<ul>
<li>Potentiometer:https://docs.arduino.cc/built-in-examples/basics/AnalogReadSerial</li>
<li>PWM:https://create.arduino.cc/projecthub/muhammad-aqib/arduino-pwm-tutorial-ae9d71</li>
<li>L298N:https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/</li>
</ul>
