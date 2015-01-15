/*
  IR Remote Print
  
  Reads values from the IR receiver and print them over Serial.
 */

#include <IRremote.h>

int remoteInputPin = 2;
IRrecv receiver(remoteInputPin);

decode_results results;

void setup()
{
  Serial.begin(9600);
  receiver.enableIRIn();
}

void loop() {
  if (receiver.decode(&results)) {
    Serial.println(results.value, HEX);    
    receiver.resume();
  }
}

