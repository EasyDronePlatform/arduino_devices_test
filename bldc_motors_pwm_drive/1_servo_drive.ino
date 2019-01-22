/** Simple servo motor drive with PWM signals 

	Author  : Manohar Kuse <mpkuse@connect.ust.hk>
	Created : 20th Jan, 2019
**/


#include <Servo.h>

Servo myservo; 
int led = 17;

int mc = 1500; 
void setup() {
myservo.attach(16);  //< Initialize 16th pin as servo signal
myservo.writeMicroseconds( 1500 ); //< init servo with 1500.
  pinMode(led, OUTPUT);     //< LED just for visual

}

void loop() {
  myservo.writeMicroseconds( mc ); //< command the servo. 
  mc+=50;

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(500);  

}

