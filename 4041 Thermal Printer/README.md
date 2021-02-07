4041 Thermal Printer
--------------------
4041 printer top view showing the strobe disk and printer motor.
![4041 Printer top view](./Printer%20Strobe%20Disk%20top%20view-small.jpg)

4041 printer bottom view showing the thermal printhead and drive gears.
![4041 Printer bottom view](./Printer%20bottom%20view-small.jpg)

The 4041 internal printer is a model PU-1800 thermal printer, also used on the Rockwell AIM65 microcomputer in the 1970's.

This folder contains excerpts of the AIM65 User's Guide on how the thermal printer works and interesting maintenance and troubleshooting information that I haven't found anywhere else, including adjustments to align the printer output by turning the strobe disk.  I have also included the thermal printer schematic from the AIM65 mainboard schematic for reference.

There are a couple of differences in the implementation of the Tektronix 4041 printer compared to the AIM65 printer:
- The printer is mounted upside down in the 4041 (which makes strobe disk adjustment very easy by pulling the 4041 top cover open to access the printer)
- The 4041 adjustment for dot intensity is on the Front Panel card mounted on top of the main CPU board and adjusts the length of the FIRE-1 signal which enables the dot drivers.
- The 4041 printhead voltage is unregulated 24V, while the AIM65 adjusts the voltage to the thermal printhead.
- The 4041 adjustment for motor speed is on the Printer Interface card

In both implementations, the horizontal dot timing is adjusted by loosening the Strobe Disk screw and twisting the strobe disk slightly while printing, then securing the strobe disk position by tightening the screw when the character dots are aligned for the entire character.

Neither the AIM65 nor Tektronix 4041 service manual indicate what is the proper voltage setting for the motor speed.

My photo of the bottom view shows that the printers removed from two of my 4041 have stickers indicating the nominal drive voltage - and it is almost one volt different between the two printers.  In addition, the newer 4041 printer was manufactured in **1985** while the older 4041 printer was manufactured in **1964**!  There are other minor mechanical differences in the two printers, that may be due to manufacturing improvements over **21 years**!

My research was triggered by repairing the thermal printer in my newer 4041, and trying component swaps from the older 4041.

Since you cannot see the printer label indicating the proper motor voltage without removing the thermal printer, you should not simply swap the Printer Interface card which contains the adjustment for the motor voltage, without first adjusting the replacement printer interface card to the motor voltage on the 4041 printer label without the printer cable being installed.

I have included in this folder the relevant schematic pages from the 4041 Service Manual highlighted to show the printer interface logic, and the Circuit Board Straps page showing the J150 'Diagnose B' jumper can be installed during printer testing to enable front panel keypad keys to be echoed to the display and printer without needing to load a program.  The System Verification Tape does contain a printer test program "PRINTE", but would require you have a tape loaded with all the System Verification files.  If you have configured the 4041 to operate from a PC with serial terminal emulation, delete the first line of the text version of the PRINTE subprogram (which converts it into a full program), and send the edited version to the 4041 from the PC terminal emulator and then RUN the program to test the entire character set.  To calibrate the dot timing, delete the first line of the PTRCAL subprogram and send it to the 4041.

I found you can remove and replace the 4041 printer without removing the front panel:
-Remove the 4041 top cover and left side cover
-Remove the printer flex cable from the printer interface card
-Remove the four printer screws
-Push the printer up out of the printer bracket and move it toward the CPU board, then pull it out of the 4041.
