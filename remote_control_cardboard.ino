/*
  Motor Tester
  Scaffolding to figure out motor directions.
 */

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

void reverse() {
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightReverse, HIGH);
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftReverse, HIGH);
}

void left() {
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightReverse, LOW);
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftReverse, HIGH);
}

void right() {
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightReverse, HIGH);
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftReverse, LOW);
}

void halt() {
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightReverse, LOW);
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftReverse, LOW);  
}

void loop() {
  if (receiver.decode(&results)) {
    Serial.println(results.value, HEX);
    if (results.value == 0xABCD) {
      forward();
    } else if (results.value == 0xDCBA) {
      reverse();
    } else if (results.value == 0x1234) {
      left();
    } else if (results.value == 0x4321) {
      right();
    } else if (results.value == 0x0000) {
      halt();
    }
    receiver.resume();
  }
}

