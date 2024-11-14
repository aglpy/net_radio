# Wiring Guide for the Net Radio

This document provides detailed wiring instructions for assembling the net radio using the ESP32. Below is the connection schematic for each component involved in the project.

## Components
- ESP32
- MAX98357A Audio Amplifier
- Speaker
- EC2 Rotary Encoder
- Switch
- Wires
- USB Wire for programming
- Battery and TP4056 for battery charge control (optional)

## Speaker Connections

Connect the Speaker to the MAX98357A Audio Amplifier as follows:

- **+ Input (red)**
  - Connect to **+** output of MAX98357A Audio Amplifier.
- **- Input (black)**
  - Connect to **-** output of MAX98357A Audio Amplifier.

## MAX98357A Audio Amplifier

Connect the MAX98357A Audio Amplifier to ESP32 and Speaker as follows:

- **+ Output (red)**
  - Connect to **+** input of Speaker.
- **- Output (black)**
  - Connect to **-** input of Speaker.
- **Vin**
  - Connect to **+3.3V** pin on the ESP32.
- **GND**
  - Connect to **GND** pin on the ESP32.
- **LRC**
  - Connect to **D27** pin on the ESP32.
- **BCLK**
  - Connect to **D26** pin on the ESP32.
- **DIN**
  - Connect to **D22** pin on the ESP32.
- **GAIN**
  - Connect to **D25** pin on the ESP32.

## EC2 Rotary Encoder

Connect the EC2 Rotary Encoder to ESP32 and Speaker as follows:

- **Middle pin**
  - Connect to **GND** pin on the ESP32.
- **Side pin 1**
  - Connect to **D4** pin on the ESP32.
- **Side pin 2**
  - Connect to **D16** pin on the ESP32.

## Switch Connections

Connect the switch between the power supply (or TP4056) **+** and the ESP32 Vin.

## Summary

Ensure all connections are secure and double-check each connection before powering the ESP32. This setup provides a comprehensive guide to assembling the net radio. For further assistance, refer to the component datasheets and ESP32 documentation.
