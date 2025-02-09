# Smart Robotic Control System (Bluetooth) with STM32F401

## Overview
This project allows you to control a robot wirelessly using Bluetooth commands. The robot can move forward, backward, turn left or right, control an LED, and manage a sprinkle system. The commands are sent via Bluetooth using the HC-05 module and the STM32F401 microcontroller.

### Features:
- Bluetooth-controlled movement of the robot (forward, backward, left, right).
- LED on/off control through Bluetooth.
- Sprinkler system on/off control.
- All motor control is handled through basic logic for forward/reverse directions.
- Utilizes STM32F401 microcontroller for smooth performance.

## Hardware Required:
- STM32F401 Microcontroller (configured with Arduino IDE)
- HC-05 Bluetooth module
- 2x DC motors with motor driver (e.g., L298N)
- LED
- Sprinkle system (valve/pump)
- Wires and breadboard for connections
- Power supply (e.g., 5V battery pack)

## Circuit Connections:
1. **HC-05 Bluetooth Module**:
   - TX -> PA10
   - RX -> PA9
   - VCC -> 5V
   - GND -> GND

2. **LED Control**:
   - Connected to pin PB10

3. **Motor Drivers**:
   - Motor A: PA0 (forward), PA1 (reverse)
   - Motor B: PA2 (forward), PA3 (reverse)

4. **Sprinkle System**:
   - PB5: Controls the sprinkle
   - PB6: Output for the sprinkle action

## Code Explanation:
### Pin Configurations:
- `pinout` (PB10) is used to control an LED.
- `motorA1`, `motorA2`, `motorB1`, `motorB2` are used to control the left and right motors.
- `sprinkle` (PB5) and `sprinkle_out` (PB6) are used to control the sprinkle system.

### Bluetooth Communication:
The Bluetooth module is initialized with `bt.begin(9600)`, and incoming Bluetooth data is processed in the `loop()` function. Based on the data received, the robot performs actions such as moving forward, backward, turning left, or stopping.

### Commands:
- `W` - Turn the LED on.
- `w` - Turn the LED off.
- `X` - Activate the sprinkle system.
- `x` - Deactivate the sprinkle system.
- `F` - Move the robot forward.
- `B` - Move the robot backward.
- `L` - Turn the robot left.
- `R` - Turn the robot right.
- `S` - Stop the robot.

## Usage:
1. Set up your STM32F401 board in the Arduino IDE and upload the provided code.
2. Connect your Bluetooth device to the Arduino via the HC-05 module.
3. Open a Bluetooth terminal on your mobile device or PC.
4. Send the commands (`W`, `w`, `X`, `x`, `F`, `B`, `L`, `R`, `S`) to control the robot.

## Notes:
- `STM32F401 Setup` : If you haven't already, make sure you've added STM32 board support in the Arduino IDE. You can follow the instructions from STM32duino to get started with STM32 boards.
- `Motor Driver` : If you're using a motor driver like the L298N, ensure you properly connect the input pins of the driver to the STM32 GPIO pins.
- `Power` : Make sure your power supply is appropriate for both the STM32F401 board and the motors.
This should give you a functional setup with STM32F401 in the Arduino IDE, and it can easily be customized further based on your needs!
