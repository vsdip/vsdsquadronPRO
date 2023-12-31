# VSDSquadronPRO

## L1 Behavior

After every

- Boot up
- Reset push on VSDSquadronPro
- Caravel Flash

```L1``` stays on for __20 seconds__ and then flashes with a Frequency of __1Hz__.

<!-- 
(Plan to change this to a short flash every 5 seconds)
-->

> Note that after the 20 seconds few specific registers are set and the blinking begins to indicate completion of bootup sequence.

<!---
(Have to check if the 20 second time can be cut half)

## Correctly flashing caravel

 IO1---1 2---IO4 </br>
 RST---3 4---IO3 </br>
 GND---5 6---CLK </br>
 IO2---7 8---3v3

```bash
sudo make hex
(hold reset button)
sudo make flash
```

> currently im using vsdsquadronPRO/caravel_firmware/caravel_flash/user_keypad/hello_world.c

Wait for flashing to complete.
wait for `L1` to start flashing.
Disconnect power.
--->
## Power Report

### Power Pins
[1]. 5V: The input voltage to the Riscduino board when it’s using an external power source 

[2]. USB: 5V input from the USB can also be used to power the Riscduino

[3]. GND: Ground pins

### Digital Pins
[1]. Digital high outputs +3.3V

[2]. Digital low outputs 0V

### Note 
[1]. It is highly recommended that an external supply is used to power sensors and actuators 

[2]. 3.3V or 5V inputs to sensors can be derived from the 5V supply that’s used to power the board

[3]. Analog data can be written to the pins by using PWM




## Arduino IDE Setup

The packages for VSDSquadronPRO need to be added and installed in Arduino IDE to upload code. 

Refer to this link for the procedure : [Arduino IDE setup](https://github.com/dineshannayya/riscduino_firmware)

Note:
1) It is recommended to use ```version 2.2.1``` of [Arduino IDE](https://www.arduino.cc/en/software). 
2) It is supported on Windows and Linux/Ubuntu.
3) Check if the necessary drivers are installed/updated.
4) Installation on Windows will have Firewall and Software update prompts which may need to be accepted to install correctly.

## Arduino IDE interface and observations

The code is flashed over the serial interface. When starting the ```upload code``` sequence the UART interface should not be used by the program.

By default once the Riscduino Core "Boots Up" it sets the UART interface busy. Hence we cannot flash code.
To get around this every time we have to flash a code from arduino IDE, press the reset button on VSDSquadronPro and make sure you ```upload code``` before ```L1``` Turns of.
