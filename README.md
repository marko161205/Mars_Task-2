# Mars_Task-2
Objective:
  1. To connect two IR Sensors and a Stepper Motor through a TB660 Stepper Motor driver to an Arduino by making the appropriate  connections
  2. To program it in such a way that the Stepper Motoe will change it's direction everytime it detects a different ir Sensor
  3. Connect the battery and check it's working

Materials:
  1. Arduino UNO
  2. TB660 Stepper motor Driver
  3. Stepper Motor (12V)
  4. LiPo battery (12 V)
  5. 2x PIR sensors
  6. Buck Converter

Procedure:
  1. First connect the EN-, Dir-, and Pul- to ground on the Arduino.(P.S. we can ignore the EN pins if we want as in this project we won't need it )
  2. Then we connect the EN+, Dir+, Pul+ to three digital Pins in the Arduino.
  3. We connect the A+, A- and B-, B+ to two different coils of the Stepper Motor.
  4. Then we Code the Arduino to sense the two PIR Sensors using digitalRead() command.
  5. Ww initialize the pin connected to EN+ as LOW using digitalWrite() command.
  6. Next we Check the step mode of the motor driver by seeing the SW1, SW2, SW3 switches on the motor Drivers. We set this to 1/8th step by keeping the SW1, SW2, SW3 pins OFF, ON, OFF respectively.
  7. We set the steps per revolution to 1600 as for 1/8th revolution it takes 200 pulses, so for 1 full revolution it will take 1600 steps.
  8. We set the Dir pin to HIGH for one direction and LOW for other direction so we use if conditions to check when one PIR is ON and set Dir to HIGH for that and When the other PIR is ON we set Dir to LOW.
  9. Then for rotoating the Stepper we use forr loops which iterate from 0 to Steps per revolution and send 500 Microsecond Pulses using delayMicroseconds() to the Pul Pin for rotating it.
  10. We can change the pulse Length for Higher and Lower speeds by varying the Pulse Width.
  11. We then connect the motor driver to a Lipo Battery through a Buck Converter and Turn it on to pass current to the Stepper and the setup will work as designed.
  12. Be sure tpo check the SW4, SW5, and SW6 switches are ON for our required current.

Code: 

  const int dirPin = 2;
  const int enPin = 8;
  const int pulPin = 5;
  const int stepsPerRevolution = 1600;
  int ir1Pin = 4;
  int ir2Pin = 6;
  int ir2 = 3;
  int ir1Val;
  int ir2Val;
  void setup()
  {
    pinMode(ir2, OUTPUT);
    pinMode(ir1Pin,INPUT);
    pinMode(ir1Pin,INPUT);
    pinMode(dirPin,OUTPUT);
    pinMode(pulPin,OUTPUT);
    pinMode(enPin, OUTPUT);
    digitalWrite(enPin, LOW);
  
  }
  void loop()
  {
    digitalWrite(ir2,HIGH);
    ir1Val = digitalRead(ir1Pin);
    ir2Val = digitalRead(ir2Pin);
    if(ir1Val && !ir2Val)
    {
      digitalWrite(dirPin,HIGH);
      for (int i=0; i < stepsPerRevolution; i++) {
        digitalWrite(pulPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(pulPin, LOW);
        delayMicroseconds(500);
      }
    }
    if(ir2Val && !ir1Val)
    {
      digitalWrite(dirPin,LOW);
      for (int i=0; i < stepsPerRevolution; i++) {
        digitalWrite(pulPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(pulPin, LOW);
        delayMicroseconds(500);
      }
    }
  
  
  }

Thought Process:
  1. This project helped me to learn about the TB660 driver and its connections to the Arduino.
  2. We can modify this code to point to the PIR sensors which are placed on opposite sides of the Stepper.

References:
  1. https://www.youtube.com/watch?v=idVcItHfGS4
  2. https://www.makerguides.com/tb6600-stepper-motor-driver-arduino-tutorial/
