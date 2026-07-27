# Portable-Environmental-Monitor-PEM

## Overview
A real-time temperature monitoring system built with Arduino Uno and a thermistor-based sensing circuit. Raw analog sensor data is converted to calibrated temperature readings using the Steinhart-Hart equation and displayed on a 16x2 LCD screen.

## Hardware Components
- Arduino Uno (Elegoo)
- 10k NTC Thermistor
- 10k resistor (voltage divider)
- 16x2 LCD1602 display
- Potentiometer (contrast control)
- Breadboard and jumper wires

## Circuit Design
- Thermistor and 10k resistor form a voltage divider connected to analog pin A0
- Arduino reads voltage, converts to resistance, applies Steinhart-Hart equation for temperature
- LCD connected via 4-bit parallel interface on digital pins 2, 3, 4, 5, 11, 12

## Software
- Written in C++ using Arduino IDE
- Libraries: LiquidCrystal (built-in)
- Reads analog voltage every 1 second
- Converts raw ADC value (0-1023) to Fahrenheit
- Outputs live readings to LCD and Serial Monitor

## Results
- Successfully reads and displays real-time temperature
- Serial monitor logs data for post-processing
- Voltage divider circuit validated against theoretical calculations

## Skills Demonstrated
- Analog circuit design (voltage divider)
- Embedded C++ programming
- Sensor calibration and signal processing
- Hardware debugging and troubleshooting
- Technical documentation
