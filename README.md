# VSDSquadronPRO

## L1 Behavior

After every

- Boot up
- Reset push on VSDSquadronPro
- Caravel Flash

```L1``` stays on for 20 seconds and then flashes with a Frequency of 1Hz
(Plan to change this to short flash every 5 seconds)

> Note that after the 20 seconds few specific registers are set and the blinking begins to indicate completion of bootup sequence.

(Have to check if the 20 second time v=can be cut half)

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

Wait for flashing to complete.
wait for `L1` to start flashing.
Disconnect power.

## Arduino IDE interface and observations

The code is flashed over the serial interface. When starting the ```upload code``` sequence the UART interface should not be used by the program.

By default once the Riscduino Core "Boots Up" it sets the UART interface busy. Hence we cannot flash code.
To get around this every time we have to flash a code from arduino IDE, press the reset button on VSDSquadronPro and make sure you ```upload code``` before ```L1``` Turns of.
