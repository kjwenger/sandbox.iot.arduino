#include <SoftwareSerial.h>

SoftwareSerial softwareSerial(3,2);

void setup() {
  softwareSerial.begin(9600);
  Serial.begin(9600);
}
 
void loop() {
  softwareSerial.println ("hello Linksprite!");
  Serial.println ("hello Linksprite!");
  delay(1000);
}
