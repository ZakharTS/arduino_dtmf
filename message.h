#ifndef message_h
#define message_h
#include "Arduino.h"
#include "DTMF.h"
#include "Tone.h"

String get_message(short sensorPin, float sampling_rate, short adc_centre, float magnitude);

void send_message(String dtmfMessage, short pttPin, short outputPin1, short outputPin2, short duration);

void find_freqs(char dtmf, unsigned& freq1, unsigned& freq2);

String text_to_dtmf(String text);

String dtmf_to_text(String dtmf);

#endif
