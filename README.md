Arduino-Uno-Keyboard
====================

Allow an arduino unu SMD R3 to spoof a USB keyboard, and send keys in rapidly

Setup
=====
All instructions are written for Linux, using the ubuntu repositories.
Flashing The Uno SMD R3 Firmware
--------------------------------

We will be using two firmware files provided to us by Mitchtech (http://mitchtech.net/arduino-usb-hid-keyboard/) In fact, much of this setup comes from them. The Firmware files are under the Apache 2 lisence. Enjoy

1. Install dfu-programmer
```
sudo apt-get install dfu-programmer dfu-util
```

2. Plug your arduino into the computer. Load up the arduino IDE, and find the port your board is using under Tools -> Serial Port

3. Put your device into DFU mode, by connecting these two pins: [Image] (http://arduino.cc/en/uploads/Hacking/Uno-front-DFU-reset.png)
The device will blink, and then stop blinking, go back to the IDE and make sure the serial port is no longer visible

4. Upload a test firmware
```
sudo dfu-programmer atmega16u2 erase
sudo dfu-programmer atmega16u2 flash Arduino-usbserial-uno.hex
sudo dfu-programmer atmega16u2 reset
```

5. Power cycle the device, and make sure the IDE can see the board and that you can upload a sketch

How to use the project
==========================

Included in this project are two firmwares, Arduino-usbserial-uno.hex and Arduino-leopard-0.3.hex

The development steps go like this:

1. Start with the Arduino-usbserial-uno.hex, flash that to the board.

2. Write your code, upload it to the board

3. DFU the board, erase, flash Arduino-keyboard-0.3.hex, reset, power cycle

4. Upon giving power to the board, the code will run

5. To edit/reupload code, DFU, erase, flash Arduino-usbserial-uno.hex, reset, power cycle

6. Rinse repeat


Sample Project
==============
Included is a sample project, it can be found in /hellotest

It simply types the word hello when givin power.










