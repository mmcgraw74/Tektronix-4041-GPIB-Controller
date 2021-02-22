One serious issue with using the 4041 - 40 years after it was manufactured - is getting the DC100A tapes (30 years since production stopped).  I have purchased NOS 3M DC100A tapes with date codes on the boxes of 1991, and all the tape drive belts in the tapes have broken.  Even worse, the tape belts have stuck to the oxide side of both takeup reels and when the broken belts are removed - the oxide is pulled off the tape completely - which causes the end-of-tape sensor to indicate the tape is unusable.

A DC100A tape can be used to change the 4041 default front panel console to the COMM0: RS-232 port, if you can get one to work, which involves using the front panel keyboard connector and a PC with serial interface to emulate the keyboard to change the console.

A second serious issue with using the 4041 is the lack of the custom 4041 Program Development keyboard, which could be used to type the two 4041 BASIC commands needed to change the default 4041 front panel as the console to the RS-232 COMM0: port standard on every 4041.

After spending several months trying to keep my repaired DC100A tapes working to configure my 4041 console to COMM0: I have come up with a new solution:
**********************
# My 4041 Console Commander!
**********************

The two photos below show my 4041 Console Commander (tiny Gray box on top of my 4041) in operation
![Console Commander in operation](./Console%20Commander%20in%20operation-sm.jpg)

![Console Commander Top View](./4041%20Console%20Commander%20top%20view.jpg)

My 4041 Console Commander is a tiny Arduino computer directly connected to the 4041 keyboard connector with three breadboard jumper cables (no need for the expensive LEMO connector).

The second photo shows the top of the 4041 Console Commander

My 4041 Console Commander features:
- Gets 5V power for the Console Commander from the keyboard connector
- The Commander includes a high current (30mA) open collector driver on the TX signal, required by the 4041 design
- RGB LED in center of the button indicates state of operation
    - Commander LED lights GREEN briefly at 4041 power on (validates the Commander powered up successfully)
    - Commander LED lights BLUE when Commander button is pressed briefly to send console change commands to 4041
    - Commander LED lights LAVENDER when Commander button is pressed for longer than 1/2 second indicating Adventure or other program is being sent to 4041 followed by console change commands.

After the Commander changes the 4041 console to COMM0: no further commands can be sent by the keyboard, or the 4041 speaker will beep, so my Commander program ignores further button presses until the 4041 power is cycled OR the small reset switch on the right side of the Commander is pressed (see second photo above).

This Commander reset was very useful to debug the required delays after each program line was transmitted.  If the 4041 errored out before the transmission was complete, the console is still set to the keyboard.  To see where the transmission stopped simply press the Commander reset button and then briefly press the top button to change the console to COMM0:  Then use the PC terminal emulator to list the program in 4041 memory to see where the transmission stopped with an error.  The reason the keyboard port cannot receive data continously at 4800 baud is the 4041 echoes all the received 'keystrokes' to the front panel LEDs (slow) and the 4041 only buffers one line of keyboard data at a time and needs time to process the ASCII text into BASIC tokens.

In order to send BASIC commands to the 4041 through the keyboard port, these commands must have delays between each line - or the 4041 will emit error beeps.

I uploaded three Commander programs into the Programs folder:
1. ATOM_4041_Serial.ino
2. ATOM_4041_Serial_Artillery.ino
3. ATOM_4041_Serial_Adventure.ino

Program 1 is the template for programs 2 and 3.  Instead of uploading a program on a long press of the button, you could change this program to use different console settings such as EDIT=STORAGE instead of EDIT=RASTER if you are using a Tektronix 4012 or 4014 storage terminal or Tektronix 4050 computer emulating a 4012 or 4014 terminal.

Program 2 sends my port of the Super Artillery game program to the 4041 (a couple of minutes) and then changes the console to COMM0: on a long Commander button press (LAVENDER LED).

Program 3 sends my port of Adventure (single-file) to the 4041 (37 minutes) and then changes the console to COMM0:  This program would be most useful if you only connect the 4041 to a terminal, not a PC, or if you don't have a working 4041 tape and don't have the 4041 DDU floppy or hard disk.

All three programs will only change the console on a short (less than 1/2 second) Commander button press.
