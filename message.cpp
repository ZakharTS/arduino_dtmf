#include "message.h"

const unsigned dtmf_tones[8] = { 697, 770, 852, 941, 1209, 1336, 1477, 1633 };

const unsigned char dtmf_map[16] = { 0x11, 0x21, 0x41, 0x12, 0x22, 0x42, 0x14, 0x24, 0x44, 0x28, 0x81, 0x82, 0x84, 0x88, 0x18, 0x48 };

const char dtmf_char[16] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'A', 'B', 'C', 'D', '*', '#' };

String get_message(short sensorPin, float sampling_rate, short adc_centre, float magnitude) {
    //float sampling_rate = 8926.0; int adc_centre = 506; float magnitude = 1800.;
    DTMF dtmf = DTMF(128.0, sampling_rate);
    float d_mags[8];
    unsigned time = millis();
    String message;
    while (millis() - time <= 3000) {
        dtmf.sample(sensorPin);
        dtmf.detect(d_mags, adc_centre);
        char thisChar = dtmf.button(d_mags, magnitude);
        if (thisChar) {
            message += thisChar;
            time = millis();
        }
    }
    return message;
}

void send_message(String dtmfMessage, short pttPin, short outputPin1, short outputPin2, short duration) {
    pinMode(pttPin, OUTPUT);
    digitalWrite(pttPin, HIGH);
    delay(500);
    Tone tone1, tone2;
    tone1.begin(outputPin1);
    tone2.begin(outputPin2);
    Serial.println("Sending...");
    Serial.println(dtmfMessage);
    for (int i = 0; i < dtmfMessage.length(); i++) {
        unsigned freq1, freq2;
        find_freqs(dtmfMessage[i], freq1, freq2);
        tone1.play(freq1, duration);
        tone2.play(freq2, duration);
        delay(duration * 2);
    }

    digitalWrite(pttPin, LOW);
    tone1.stop();
    tone2.stop();
    delay(2000);
}

void find_freqs(char dtmf, unsigned& freq1, unsigned& freq2) {
    int j;
    freq1 = 0;
    freq2 = 0;
    for (j = 0; j < 16; j++) {
        if (dtmf_char[j] == dtmf) break;
    }
    if (j >= 16) return;
    unsigned mask = (int) dtmf_map[j];
    for (int i = 0; i < 8; i++) {
        if (mask & (1 << i)) {
            if (freq1) {
                freq2 = dtmf_tones[i];
            } else {
                freq1 = dtmf_tones[i];
            }
        }
    }
}

String text_to_dtmf(String text) {
    String dtmf;
    for (int i = 0; i < text.length(); i++) {
        int current = (int) text[i];
        dtmf += dtmf_char[current / 16];
        dtmf += dtmf_char[current % 16];
    }
    return dtmf;
}

String dtmf_to_text(String dtmf) {
    String text;
    for (int i = 0; i < dtmf.length(); i += 2) {
        int j;
        char current = 0;
        for (j = 0; j < 16; j++) {
            if (dtmf_char[j] == dtmf[i]) break;
        }
        current += j * 16;
        for (j = 0; j < 16; j++) {
            if (dtmf_char[j] == dtmf[i + 1]) break;
        }
        current += j;
        text += current;
    }
    return text;
}
