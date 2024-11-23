# Software for the Net Radio

This directory contains the source code for the Net Radio project, which utilizes a speaker, a MAX98357A, a EC2 Rotary Encoder and ESP32.

## Structure

- `net_radio/net_radio.ino`: The main Arduino sketch file.
- `config.h`: Configuration file containing pin assignments and other global settings.
- `requirements.txt`: Necessary third-party libraries.

## Setup Instructions

1. **Install Arduino IDE or any other IDE extension**: Ensure you have the latest version of the Arduino IDE installed on your computer. Download it from [Arduino Website](https://www.arduino.cc/en/Main/Software).

2. **Clone the Repository**: Clone this repository to your local machine or download the zip file and extract it.

    ```bash
    git clone https://github.com/aglpy/net_radio.git
    cd net_radio/software
    ```

3. **Library Dependencies**: The following libraries are needed for this project. Ensure they are installed:
    - `Wifi` to connect a wifi network.

    You need to add these libraries to your Arduino IDE. Follow these steps:
    
    - Open Arduino IDE, go to Sketch > Include Library > Add .ZIP Library...
    - Navigate to each and select the library folder.

4. **Load the Sketch**: Open the `net_radio.ino` file in Arduino IDE.

5. **Upload to ESP32**: Connect your ESP32 to your computer via USB. Select the correct board and port in Arduino IDE, then upload the sketch.
