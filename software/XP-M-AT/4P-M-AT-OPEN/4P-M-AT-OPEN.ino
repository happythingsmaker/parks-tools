// Author: Eunchan Park

#include <USB-MIDI.h>

#define CHANNEL 1
#define NUM_DIALS 4

#define CC_FOR_DIAL_0 0
#define CC_FOR_DIAL_1 1
#define CC_FOR_DIAL_2 2
#define CC_FOR_DIAL_3 3

int prev_value[NUM_DIALS];
midiEventPacket_t event;
int ADC_pins[NUM_DIALS] = {A0, A1, A2, A3};

void setup() {
    for (int i = 0; i < NUM_DIALS; i ++) {
        pinMode(ADC_pins[i], INPUT);
    }
}


void loop() {
    for (int i = 0; i < NUM_DIALS; i ++) {
        read_adc_send_midi(ADC_pins[i], i, CHANNEL, CC_FOR_DIAL_0);
    }
    delay(50);
}


void read_adc_send_midi(int pin, int index, int channel, int cc) {
    int value_10bit = analogRead(pin);
    int value_7bit = map(value_10bit, 0, 1023, 0, 127);

    if (abs(prev_value[index] - value_7bit) > 0) {
        midiEventPacket_t event = {0x0B, 0xB0 | channel - 1, cc, value_7bit};
        MidiUSB.sendMIDI(event);
        MidiUSB.flush();
    }
    prev_value[index] = value_7bit;
}
