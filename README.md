![alt text](https://dl.thorinair.net/MLP/vdistcontroller_b.png "V-Dist Controller")

V-Dist Controller is a simple MIDI hardware counterpart to Violin Melody's [V-Dist Classic](https://violinmelody.net/plugins/vdist/) single-knob VST distortion effect.

Much like the VST itself, the controller features a single knob, and sends back MIDI data of the knob's position to the DAW or VST host of choice. This can be used either for V-Dist itself, or any other VST.

## Requirements
- [MIDIUSB library](https://github.com/arduino-libraries/MIDIUSB)
- [Arduino Micro](https://store.arduino.cc/arduino-micro)

## Additional Notes
In order to have the Arduino Micro appear as "V-Dist Controller" in DAWs and VST hosts, the following change has to be done:
- Navigate to: `c:\Users\<Your User>\AppData\Local\Arduino15\packages\arduino\hardware\avr\<Version Number>\`
- Open `boards.txt` for editing.
- Find the line: `micro.name=Arduino/Genuino Micro`
- Below it, find the line: `micro.build.usb_product="Arduino Micro"`
- Rename "Arduino Micro" to "V-Dist Controller".
- Save the file and restart Arduino IDE.
- NOTE: You may want to restore the original name after you are done flashing the controller, otherwise all future projects will also be called "V-Dist Controller".