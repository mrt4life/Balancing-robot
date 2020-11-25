/*
        Arduino Brushless Motor Control
     by Dejan, https://howtomechatronics.com
*/

#include <Servo.h>

Servo ESC;     // create servo object to control the ESC

int speedpercentage;

void setup() {
  // Attach the ESC on pin 9
  ESC.attach(9,1000,2000); // (pin, min pulse width, max pulse width in microseconds)
  ESC.write(0);    // Send the signal to the ESC
  delay(1000);
}

void loop() {
  speedpercentage = 15;
  speedpercentage = map(speedpercentage, 0, 100, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
  ESC.write(speedpercentage);    // Send the signal to the ESC
}
