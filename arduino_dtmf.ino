#include "message.h"

short sensorPin = A0;
short outputPin1 = 10;
short outputPin2 = 11;
short pttPin = 12;
float sampling_rate = 8926.0; short adc_centre = 506; float magnitude = 1800.0;

void setup() {
  Serial.begin(9600);
  //String dtmf = Serial.readString();
  send_message(text_to_dtmf("Hello world!"), pttPin, outputPin1, outputPin2, 100);
}

void loop() {
 // int val = analogRead(sensorPin);
  //Serial.println(val); 
  String message = get_message(sensorPin, sampling_rate, adc_centre, magnitude);
  if (message != "") Serial.println(message);
}
