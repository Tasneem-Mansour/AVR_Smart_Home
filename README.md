# AVR_Smart_Home
![flowchart](https://github.com/Tasneem-Mansour/AVR_Smart_Home/assets/114835445/a36ac2a2-8e4d-48ae-9e87-209f3d4416c6)

This project is a microcontroller-based smart home automation system featuring an integrated security system, temperature control, and lighting automation. The system is designed to provide enhanced security with a password-protected door mechanism, automatic fan control based on temperature, and automatic adjustment of lighting intensity based on ambient light conditions.

## Features

### Security System:
- Password-protected door locking and unlocking mechanism.
- Password is stored in EEPROM and communicated using I2C protocol.
- Visitors can enter a password via a keypad or UART interface.
- A counter tracks incorrect password attempts, and after 3 wrong attempts, an alarm (buzzer) is triggered.

### Environmental Control:

#### Fan Automation:
- A DC motor is used as a fan, which turns on automatically if the temperature exceeds 20°C.
- Temperature is monitored using an ADC (Analog-to-Digital Converter).
- The fan can also be controlled manually via a button.

#### Lighting Automation:
- LED lights' intensity is adjusted automatically based on ambient light levels (measured in lux).
- If the light level exceeds 140 lux, the LED intensity decreases; otherwise, full intensity is maintained.

## Other Components:
- LCD screen for password entry and messages.
- Servo motor-controlled door mechanism.
- Buzzer for alert signals after incorrect password entries.
- Potentiometer for manual adjustments of fan speed.

## Components Used:
- Microcontroller Unit (MCU)
- EEPROM (for password storage)
- Keypad (for user input)
- Servo motor (for door mechanism)
- DC motor (for fan control)
- LEDs (for lighting control)
- 7-segment display (for incorrect password attempts)
- Buzzer (for security alert)
- Temperature sensor
- Ambient light sensor (lux measurement)
- Potentiometer (for manual adjustments)
- LCD Display

## Control Logic:
- The system uses interrupts for doorbell handling and password entry.
- Incorrect password attempts are counted and displayed on a 7-segment display.
- When the correct password is entered, the door unlocks using a servo motor.
- The fan turns on if the temperature exceeds 20°C and can be manually turned off with a button.
- Light intensity is adjusted using PWM (Pulse Width Modulation) based on the ambient light levels.

## Getting Started:
1. Clone this repository.
2. Connect the components as per the flowchart.
3. Upload the firmware to the microcontroller.

## How to Use:
- Set the password on the first start, which will be stored in EEPROM.
- Use the keypad to enter the password and unlock the door.
- The fan will automatically turn on or off based on the temperature.
- The LED lights will adjust their intensity based on the room's ambient lighting.
