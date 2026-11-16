# Arduino-environment-monitor

Arduino Uno temperature and humidity monitor using DHT22 sensor and I²C LCD 

This is my first Arduino project, built to practise connecting electronic components, reading sensor data and displaying measurements. 

My plan is to make five mini projects to learn more about Arduino and electronics, then do a final project that combines all five mini projects in one larger integrated project. And this is the first project out of five. 

## Features 

- Display temperature in degrees Celsius and relative humidity.
- Update readings approximately every two seconds.
- Sends readings to the serial Monitor at 9600 baud.
- Displays an error if the sensor cannot be read.
- Automatically detects the LCD's I²C address.

## Components

- Arduino Uno R3
- DHT22 sensor module with three pins
- 16x2 LCD with I²C adapter
- Breadboard
- Jumper wires
- USB cable

## Wiring

"Make sure to disconnect the USB cable before wiring"
| Components | Pin |    Arduino Uno connection     | 
|____________|_____|_______________________________|
|    DHT22   |  +  | 5V through breadboard + rail  | 
|    DHT22   | OUT |         Digital pin 2         | 
|    DHT22   |  -  | GND through breadboard - rail | 
|     LCD    | VCC | 5V through breadboard + rail  | 
|     LCD    | GND | GND through breadboard - rail | 
|     LCD    | SDA |               A4              |
|     LCD    | SCL |               A5              | 

The Arduino's 5V and GND pins connect to the breadboard power rails so both devices can share power. All power connections use the same connected section of each rail. 

## Software and Libraries 

The project uses Arduino IDE and the following libraries, available through Library Manager: 

- DHT sensor library by Adafruit
- Adafruit Unified Sensor
- hd44780 by Bill Perry

The Wire library is included with the Arduino board software. 

## Running the Project 

1. Install the libraries listed above.
2. Download "Environment_Temp.ino" and place it in a folder named "Environment_Temp".
3. Open the sketch in Arduino IDE.
4. Connect the components using the wiring table.
5. Connect the Arduino to the computer using USB.
6. Select Arduino Uno and the correct USB port.
7. Upload the sketch.
8. The LCD will display temperature and humidity.
9. To view readings on the computer, open Serial Monitor and select 9600 baud.

If the backlight is on but the text is difficult to see try to gently adjust the blue contrast screw on the LCD's I²C adapter. 

## How It Works

The Arduino requests temperature and humidity measurements from the DHT22 through digital pin 2.

It checks whether the readings are valid, then displays them on the LCD using I²C communication. The same measurements are also sent to the computer over serial communication.

This process repeats approximately every two seconds.

## Testing

I tested the sensor by placing my hand near it and observing changes in the readings.

## What I Learned

- Connecting sensors and displays to an Arduino.
- Sharing power using breadboard rails.
- Installing and using Arduino libraries.
- Using "setup()" and "loop()".
- Reading sensor values and checking for errors.
- Displaying information on an LCD and Serial Monitor.

## Planned Improvements

- Add an LED or buzzer for temperature warnings.
- Record minimum and maximum readings.
- Build an enclosure for the circuit.
