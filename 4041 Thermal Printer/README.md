4041 Thermal Printer
--------------------
![4041 Printer top view](./Printer%20Strobe%20Disk%20top%20view-small.jpg) ![4041 Printer bottom view](./Printer%20bottom%20view-small.jpg)

The 4041 internal printer is a model PU-1800 thermal printer, also used on the Rockwell AIM65 microcomputer in the 1970's.

This folder contains excerpts of the AIM65 User's Guide on how the thermal printer works and interesting maintenance and troubleshooting information that I haven't found anywhere else, including adjustments to align the printer output by turning the strobe disk.  I have also included the thermal printer schematic from the AIM65 mainboard schematic for reference.

There are a couple of differences in the implementation of the Tektronix 4041 printer compared to the AIM65 printer:
- The printer is mounted upside down in the 4041 (which makes strobe disk adjustment very easy by pulling the 4041 top cover open to access the printer)
- The 4041 adjustment for dot intensity is on the Front Panel card mounted on top of the main CPU board
- The 4041 logic for timing the dots is a one-shot multivibrator with adjustment on the Front Panel card
- The 4041 adjustment for motor speed is on the Printer Interface card

In both implementations, the horizontal dot timing is adjusted by loosening the Strobe Disk screw and twisting the strobe disk slightly while printing, then securing the strobe disk position by tightening the screw when the characters are even.

Neither the AIM65 nor Tektronix 4041 service manual indicate what is the proper voltage setting for the motor speed.

My photos
