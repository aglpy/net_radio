# Net Radio Documentation

## Introduction
This document provides a comprehensive guide to assembling, programming, and using the ESP32-based net radio streamer.

## Components
- ESP32
- MAX98357A Audio Amplifier
- Speaker
- EC2 Rotary Encoder
- Switch
- Wires
- USB Wire for programming
- Battery and TP4056 for battery charge control (optional)

## Circuit Assembly
### Schematics
Refer to the [schematic.pdf](../hardware/schematics/Net_Radio_schematic.pdf) file for details on how to connect each component.

### Assembly
1. Connect the Speaker to the Amplifier output (+  -).
2. Connect the Amplifier to the ESP32 (GND to GND, Vin to +3.3V, Din to D22, GAIN to D25, BCLK to D26 and LRC to D27).
3. Connect middle pin from EC2 to GND and the side pins to D4 and D15 of ESP32.
4. Connect the ESP32 to power supply or TP4056 with battery with switch in the middle.

## Programming
### Initial Setup
1. Install the necessary libraries as indicated in the `/software/requirements.txt` directory.
2. Modify the `config.h` file to change pins if necessary.

### Code Upload
Upload the `net_radio.ino` to the ESP32.

## Using the Net Radio
Power on the device and the speaker streams the radio link given in the code.

## Technical Support
For further assistance, you can open an issue on GitHub.
