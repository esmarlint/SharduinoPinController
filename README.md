# SharduinoPinController

## Overview
SharduinoPinController establishes a seamless link between C# applications and Arduino hardware, enabling control over Arduino pins through a serial port. This tool is ideal for manipulating LED states and other digital signals directly from a C# interface.

## Features
- **Pin Control**: Easily toggle Arduino pins between HIGH and LOW states.
- **Serial Communication**: Facilitates communication between C# and Arduino via serial port.
- **Arduino Auto-Detection**: Automatically detects the connected Arduino port.
- **User-Friendly Interface**: Simple and intuitive for all levels of users.
- **Open Source and Customizable**: Perfect for educational, hobbyist, or professional projects.

## Getting Started
### Prerequisites
- Arduino board
- C# development environment
- Serial cable for Arduino

### Installation
1. Clone the repository to your local machine.
2. Open the project in your C# development environment.
3. Upload the Arduino code to your Arduino board.

## Usage
Run the C# application and select the appropriate COM port for your Arduino. Use the interface to control the pins on your Arduino board.


# Arduino Command Interface Documentation

## Overview and Examples
This Arduino program is designed to receive serial commands and control pins based on these commands. The available commands are `identify`, `blink`, `on`, and `off`. Each command, except for `identify`, requires specifying a pin number, and optionally a time duration in milliseconds.

## Command Format
Commands are sent in the format `command:pin,time`. The `time` parameter is optional for `blink`, `on`, and `off` commands. If not provided, a default value is used for `blink`, and `on`/`off` commands will switch the state indefinitely.

### Command Examples
1. **Identify**
   - Format: `identify`
   - Description: Returns the unique ID of the Arduino.
   - Example: 
     ```
     identify
     ```

2. **Blink**
   - Format: `blink:pin,time`
   - Description: Toggles the specified pin on and off. If `time` is provided, it's used as the delay in milliseconds for blinking. Otherwise, a default delay is used.
   - Example: 
     ```
     blink:13,500
     ```
     This makes pin 13 blink with a 500ms delay between states.

3. **On**
   - Format: `on:pin,time`
   - Description: Sets the specified pin to HIGH. If `time` is specified, the pin remains HIGH for that duration and then switches to LOW.
   - Example:
     ```
     on:12,2000
     ```
     This sets pin 12 to HIGH for 2000ms.

4. **Off**
   - Format: `off:pin,time`
   - Description: Sets the specified pin to LOW. If `time` is specified, the pin remains LOW for that duration and then switches to HIGH.
   - Example:
     ```
     off:10,1000
     ```
     This sets pin 10 to LOW for 1000ms.

## Sending Commands from a C# Application
To send commands from a C# application to the Arduino, establish a serial connection using the `System.IO.Ports.SerialPort` class. Write the command string to the serial port, formatted as described above.

### C# Example
```csharp
using System.IO.Ports;

SerialPort mySerialPort = new SerialPort("COM3");

mySerialPort.BaudRate = 9600;
mySerialPort.Open();

// Send a command to blink pin 13
mySerialPort.WriteLine("blink:13,500");

mySerialPort.Close();
```
Replace `"COM3"` with the actual COM port your Arduino is connected to.


## Contributing
You can contact me or let a comment for contributions or questions

## License
Take a look at license section on the proyect
