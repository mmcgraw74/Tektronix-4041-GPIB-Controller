TEKTRONIX 4041 OPTION ROMS – Oct 2, 2000 mcm
-----
I got two Tek 4041 GPIB controllers.  Both had the programming ROM set.  One had four other option ROM sets:  4041R01 Graphics, 4041R02 Plotting, 4041R03 Signal Processing, and 4041R04 Utility – all labeled Version 2.1

The Option ROMs were in 24pin Molex Low-insertion force carriers P/N 8878 24-D, the ROM tray used Molex  8878 24S sockets.  Neither of these parts could be found on an internet search.  I went to the Molex website and found they still make 24 pin LIF carriers 50-39-5248 and matching sockets but I couldn’t find any in stock in internet electronics distributors.  The 28 pin versions were in stock and around $2.50 a mated set at Carlton-Bates, so I ordered 6 sockets 15-29-9282 and 16 carriers 50-39-5288.

I used a Dremel to modify one 28 pin socket (pulled out two contacts at pins 13 and 16 and then Dremeled a groove on each side to accept the Tek 24 pin carriers.  The carriers have one notch on the pin 1 end and two notches on the pin 12 end.

The Graphics ROMs were Motorola 68766C35 24pin 8Kx8 EPROMs.

Using my Data I/O Model 29B /w Unipak2 – Family 25/Pinout 29, I read each EPROM and transferred the data to the PC.  Set Translation Format to 83 so they can be loaded into PC with DEBUG.COM  HEX files can be loaded with DEBUG.  TXT files are in the default Data I/O format 81.


| column 1 | column 2 | column 3 |
|:----------:|----------|----------|
| value | <p>value 1 | <p>value 2 | <p>value 3</p>  |
| value | <p>value 1<br>value 2<br>value 2</p> |

			‘Left ROM’ Checksum	‘Right ROM’ Checksum
			Part Number		Part Number	
Graphics ROMs B020801	160-1755-01	96F5	160-1756-01	2071
Plotting ROMs  B010807 	160-1889-00	4D5F	160-1890-00	1938
Signal Procesn  B010818	160-1984-00	4057	160-1985-00	945E
Utility #1 ROM B020781	160-2221-01	1034	160-2222-01	721B

The pgm dev ROMs were also 67866C35 EPROMs:

Pgm Dev ROM1 4041F30	160-1246-03	C533	160-1247-03	C915
Pgm Dev ROM2 4041F30	160-1335-03	7760	160-1336-03	EB34

The other 4041 had Pgm Dev ROMs version 2.0

Pgm Dev ROM1 4041F30	160-1246-02	C34E	160-1247-02	C250
Pgm Dev ROM2 4041F30	160-1335-02	5D6B	160-1336-02	C8DE
