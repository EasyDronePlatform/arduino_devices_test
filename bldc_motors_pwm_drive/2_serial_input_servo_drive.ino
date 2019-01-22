/**
Arduino + USB input (from PC) + Servo motors: Here I read input from PC 
(through serial communication). From my Linux terminal, I am going to echo 
out numbers to Arduino which will be pulse widths. The Arduino will read these 
pulse widths and act accordingly on the servo.

Author : Manohar Kuse <mpkuse@connect.ust.hk>
Create : 20th Jan, 2019

**/
#include <Servo.h>

int led = 17;
Servo myservo; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin( 9600 );
  Serial.println( "Hello\n" ); 
  pinMode(led, OUTPUT);
  myservo.attach( 16 );
  myservo.writeMicroseconds( 1000 );      

}

int c=0;
int num = 0;
void loop() {

  // If you see anything is available, read it all, 
  // 1 character at a time
  while( Serial.available()  ) {
    char this_char = Serial.read();
    if( this_char == '\n' )
      break;
    int this_digit = (int)(this_char - '0');
    if( this_digit >= 0  && this_digit <= 9 ) {
      num = 10*num + this_digit; 
      Serial.write( "OK " ); 
    }
    else {
      Serial.write( "NOTOK " );
      c=0 ;
      num=0;
      break; //if you see any non digit charater just ignore everthing
    }
    c++; 
  }

  if( c > 0 ) {
    // Send back whatever was received
    Serial.write( "# of digits rcvd=" );
    Serial.write( char(c+'0') );
    Serial.write( '\n' ); 
    
    // Blink the LED to indicate this action
    digitalWrite(led, HIGH);
    delay(100);             
    digitalWrite(led, LOW); 
    delay(100);

    Serial.write( "Setting pulse at " );
    Serial.write( String( num ).c_str() );
    myservo.writeMicroseconds( num ); 
    c = 0;
    num=0;  
  }
  delay(5); 
}
