/** A Arduino board shows up as a file on Linux. You programs in C/C++/Python and even Java or whatever, 
need to write and read to this file to communicate with the Arduino. In this example, the Arduino responds 
back with the same text it received.

	Author  : Manohar Kuse <mpkuse@connect.ust.hk>
	Created : 20th Jan, 2019
**/
int led = 17;

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 9600 );
  Serial.println( "Hello\n" ); 
    pinMode(led, OUTPUT);     

}

int c=0;
char incoming_string[100];  
void loop() {

  // If you see anything is available, read it all, 
  // 1 character at a time
  while( Serial.available()  ) {
    incoming_string[c] = Serial.read();
    c++; 
  }

  if( c > 0 ) {
    incoming_string[c] = '\0'; //< Don't forget this

    // Send back whatever was received
    Serial.write( "I received: " );
    Serial.write( incoming_string );
    c = 0;

    // Blink the LED to indicate this action
    digitalWrite(led, HIGH);
    delay(100);             
    digitalWrite(led, LOW); 
    delay(100);  
  }
  delay(5); 
}
