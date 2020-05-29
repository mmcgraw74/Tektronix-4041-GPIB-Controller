TEKTRONIX 4041 OPTION ROMS – Oct 2, 2000 mcm
-----
I got two Tek 4041 GPIB controllers.  Both had the programming ROM set.  One had four other option ROM sets:  4041R01 Graphics, 4041R02 Plotting, 4041R03 Signal Processing, and 4041R04 Utility – all labeled Version 2.1

The Option ROMs were in 24pin Molex Low-insertion force carriers P/N 8878 24-D, the ROM tray used Molex  8878 24S sockets.  Neither of these parts could be found on an internet search.  I went to the Molex website and found they still make 24 pin LIF carriers 50-39-5248 and matching sockets but I couldn’t find any in stock in internet electronics distributors.  The 28 pin versions were in stock and around $2.50 a mated set at Carlton-Bates, so I ordered 6 sockets 15-29-9282 and 16 carriers 50-39-5288.

I used a Dremel to modify one 28 pin socket (pulled out two contacts at pins 13 and 16 and then Dremeled a groove on each side to accept the Tek 24 pin carriers.  The carriers have one notch on the pin 1 end and two notches on the pin 12 end.

The Graphics ROMs were Motorola 68766C35 24pin 8Kx8 EPROMs.

Using my Data I/O Model 29B /w Unipak2 – Family 25/Pinout 29, I read each EPROM and transferred the data to the PC.  

.HEX file is just the hex digits for a single ROM
.BIN file is the binary image for either a single ROM or the byte shuffled 16bit ROM image for disassembly

| ROM Pack Label | Left ROM P/N  | Checksum | Right ROM P/N | Checksum |
|:-----------------:|----------|----------|----------|----------|
| Graphics ROMs v2.1 B020801 | <p>160-1755-01 | <p>96F5 | <p>160-1756-01 | <p>2071</p> |
| Plotting ROMs v2.1 B010807 | <p>160-1889-00 | <p>4D5F | <p>160-1890-00 | <p>1938</p> |
| Signal Processing v2.1 B010818 | <p>160-1984-00 | <p>4057 | <p>160-1985-00 | <p>945E</p> |
| Utility #1 v2.1 ROM B020781 | <p>160-2221-01 | <p>1034 | <p>160-2222-01 | <p>721B</p> |
| Pgm Dev ROM1 v2.1 4041F30 | <p>160-1246-03 | <p>C533 | <p>160-1247-03 | <p>C915</p> |
| Pgm Dev ROM2 v2.1 4041F30 | <p>160-1335-03 | <p>7760 | <p>160-1336-03 | <p>EB34</p> |

