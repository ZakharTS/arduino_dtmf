#ifndef message_h
#define message_h
#include "Arduino.h"
#include "DTMF.h"
#include "Tone.h"

String get_message(int sensorPin, float sampling_rate, int adc_centre, float magnitude);

void send_message(String dtmfMessage, int pttPin, int outputPin1, int outputPin2);

void find_freqs(char dtmf, unsigned& freq1, unsigned& freq2);

String text_to_dtmf(String text);

String dtmf_to_text(String dtmf);

#endif
