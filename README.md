
# Automatic Hand Sanitizer with Temperature Sensing and Alert System

## Overview

This project is an automated hand sanitizer dispenser that uses an Arduino to detect hand presence, measure temperature, and dispense sanitizer. If the temperature exceeds a set threshold, the system sends an SMS alert to an admin.

## Features

- **Automatic Hand Detection**: Uses a PIR sensor to detect when a hand is present.
- **Temperature Monitoring**: Measures hand temperature using an MLX90614 IR sensor.
- **Alert System**: Sends SMS alerts via a GSM module if the temperature is above 37.5°C.
- **Sanitizer Dispensing**: Activates a servo motor to dispense sanitizer automatically.

## Components

- **Arduino**: Microcontroller for controlling the system.
- **PIR Sensor**: Detects hand presence.
- **MLX90614 IR Temperature Sensor**: Measures temperature.
- **Servo Motor**: Dispenses sanitizer.
- **GSM Module**: Sends SMS alerts.

## Circuit Connections

- **PIR Sensor**: Pin 2 (Signal), 5V (VCC), GND
- **MLX90614**: A4 (SDA), A5 (SCL), 3.3V (VCC), GND
- **Servo Motor**: Pin 9 (Signal), 5V (VCC), GND
- **GSM Module**: Pin 7 (RX), Pin 8 (TX), 5V (VCC), GND

## How It Works

1. The PIR sensor detects a hand.
2. The temperature sensor measures the hand's temperature.
3. If the temperature is high, an SMS alert is sent to an admin.
4. The servo motor dispenses sanitizer.

## Applications

- Public spaces
- Healthcare facilities
- Home use

This system enhances hygiene and safety by combining automatic hand sanitization with health monitoring. 
