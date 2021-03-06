/**
  Remote Control Motor Driver
  
  Set two motor pins based on input from an infrared remote control.
 **/

#include <IRremote.h>

int remoteInputPin = 2;
IRrecv receiver(remoteInputPin);
decode_results results;

int motorRightForward   = 9;
int motorRightReverse   = 10;
int motorLeftForward    = 11;
int motorLeftReverse    = 12;

void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();
  
  pinMode(motorRightForward, OUTPUT);
  pinMode(motorRightReverse, OUTPUT);
  pinMode(motorLeftForward, OUTPUT);
  pinMode(motorLeftReverse, OUTPUT);
}

void forward() {
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightReverse, LOW);
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftReverse, LOW);
}

void halt() {
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightReverse, LOW);
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftReverse, LOW);  
}

// add more control functions here!

// end of control functions

void loop() {
  if (receiver.decode(&results)) {
    Serial.println(results.value, HEX);

    if (results.value == 0xABCD) {
      Serial.println("FORWARD");
      forward();
    } else if (results.value == 0x0000) {
      Serial.println("HALT");
      halt();
    } // add more "else if" conditions here for other buttons!

    receiver.resume();
  }
}