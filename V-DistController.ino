#include "MIDIUSB.h"
#include "PitchToNote.h"

#include "Configuration.h"

#define PIN_POT A5

int avgCount;
float accu;
float val;
uint8_t control;

void setupValues();
void controlChange(byte channel, byte control, byte value);

void setupValues() {
    avgCount = 0;
    accu = 0.0;
    val = 0.0;
    control = 0;
}

void controlChange(byte channel, byte control, byte value) {

    /* First parameter is the event type (0x0B = control change).
       Second parameter is the event type, combined with the channel.
       Third parameter is the control number number (0-119).
       Fourth parameter is the control value (0-127). */
    midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
    MidiUSB.sendMIDI(event);
    MidiUSB.flush();
}

void setup() {
}

void loop() {
    if (avgCount >= AVERAGE_COUNT) {
        float newVal = (accu / avgCount);
        if (abs(newVal-val) >= MIN_CHANGE) {
            val = newVal;
            uint8_t newControl = floor(newVal / (1024/128));
            if (newControl != control) {
                control = newControl;
                controlChange(MIDI_CHANNEL, MIDI_CC, newControl);
            }
        }
        accu = 0.0;
        avgCount = 0;
    }
    accu += analogRead(PIN_POT);
    avgCount++;
}