**Tektronix 4041** was also offered as the GPIB controller as part of an **MP 2501 Measurement Package** as shown in the Tek 1985 catalog page below.
![MP2501 tape](./MP%202501%20measurement%20package%20in%201985%20catalog.jpg)


Tektronix 4041 MP2501 tape was a partial copy of the original MP2501 tape.
-------
The directory list indicated the last files would have been written to record 429 on the DC100A tape, but the tape record 329 in the HEX dump was the last record before the end of the tape. 
:disappointed_relieved:
-------
![MP2501 tape](./MP2501%20tape.jpg)
-------
In addition, previous owner must have mistakenly recorded their COMM0 configuration script over the MP2501 AUTOLD file, so the original AUTOLD file was corrupted.

You can look at the remainder of the original AUTOLD file in the HEX dump.  This file starts at record 0x05 and ends at record 0x36 in the HEX dump.
```Assembly
S45F010_I  02-JAN-21 B050239   SOFT ERRORS = 0        
FILE  FILE  LENGTH  START  NUMBER         LAST       
NAME  TYPE IN BYTES RECORD OF REC. MODIFICATION  DATE
------ ---- -------- ------ ------- ------------------
AUTOLD  IT     8160     5     32    01-JAN-81 02:01:00
UTL2    IT     4845    37     19    19-NOV-84 11:09:00
BAKAL1  AS     4845    56     19    14-DEC-84 12:46:00
MP2501  IT   109395    75    429    01-JAN-81 01:31:00
              50745                                   
```
The AUTOLD file is in 4041 ITEM format which is binary.  When this file is loaded into the 4041, the BASIC ROM looks at the last byte of a record at 0xFF, if this byte is an 0xFF, then the 0xFF is removed from the data and the next block is concatenated.

Note that the byte at 0xFF in Record 0x05 is 0x4E, which causes the BASIC ROM to stop loading the program at 0x4D (which is the 0x4E'th byte of the record since 0x00 is the first byte).
-------
I found the BAKAL1 ASCII file to be a full tape backup program!  I have more info in a separate folder for BAKAL1 in this repo.
-------\
I also noticed the **UTL2** file and wondered what it was.  Looking at the tape dump text it looked like it was a **loadable M68K ROM file!**

```Assembly
Record 37
0        22 00 0C 34 30 34 31 20 52 6F 6D 70 61 63 6B 4C   "..4041 RompackL
1        40 BF 34 00 00 00 00 00 4C 40 7F 00 00 00 00 00   @.4.....L@.....
2        00 4C 40 00 00 00 00 00 00 00 22 00 F0 4D 36 38   .L@......."..M68
3        4B 08 01 55 54 4C 32 00 00 00 00 00 00 00 00 00   K..UTL2.........
4        6A 00 01 00 00 00 00 00 08 00 00 00 00 00 00 0A   j...............
5        CE 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00   ................
6        00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20   ............... 
7        43 4F 50 59 52 49 47 48 54 20 28 43 29 20 31 39   COPYRIGHT (C) 19
8        38 34 20 42 59 20 54 45 4B 54 52 4F 4E 49 58 20   84 BY TEKTRONIX 
9        49 4E 43 2E 20 41 4C 4C 20 52 49 47 48 54 53 20   INC. ALL RIGHTS 
A        52 45 53 45 52 56 45 44 2E 47 45 54 41 52 52 20   RESERVED.GETARR 
B        20 00 2E 47 45 54 53 43 4C 20 20 02 66 41 52 52    ..GETSCL  .fARR
C        53 45 47 20 20 05 76 41 52 52 53 43 4C 20 20 07   SEG  .vARRSCL  .
D        0C 48 49 53 54 4F 47 20 20 08 32 00 00 00 00 4E   .HISTOG  .2....N
E        4C 58 4F 20 20 00 07 0C 07 00 AF 66 00 01 5C 4E   LXO  ......f..\N
F        4C 58 4F 20 20 00 1F 0C 05 00 02 67 0E 0C 05 FF   LXO  ......g....
```
I then looked in the HEX dump for the **LOADROMS** call and found it in the fragment of **MP2501** program:

```Assembly
Record 32
0        BF 66 40 C5 3E 93 DC 01 3D 2C DE FF 00 00 04 CE   .f@.>...=,......
1        0A D6 04 C4 00 00 0F 04 DC 02 3D DE 0A DA 04 C9   ..........=.....
2        00 00 0F 04 DC 00 3E DE 1C 2B 04 CE 80 00 0F 16   ......>..+......
3        CE 00 08 BF 0C CC 04 55 54 4C 32 AF C3 AF BF 66   .......UTL2....f
4        40 DC 00 3E 93 DE 1A 43 04 D3 00 00 1D 14 FB 08   @..>...C........
5        4C 4F 41 44 52 4F 4D 53 CC 04 55 54 4C 32 FD FC   LOADROMS..UTL2..
6        DE FF 18 27 04 D8 00 40 1A 12 DB 00 CC 05 20 20   ...'...@......  
7        20 20 20 CE 00 01 BF 0C AA 6A DE FF 1E 28 04 DD      ......j...(..
8        00 00 13 18 DD 04 CC 11 20 20 20 20 20 62 79 74   ........     byt
9        65 73 20 6F 66 20 52 41 4D BB DE FF 28 5E 04 E2   es of RAM...(^..
A        00 00 13 22 DD 05 CC 1C 20 20 20 20 20 41 76 61   ..."....     Ava
B        69 6C 61 62 6C 65 20 55 73 65 72 20 4D 65 6D 6F   ilable User Memo
C        72 79 3A 20 BB DE 16 81 04 E7 02 00 FF 10 CD 0B   ry: ............
D        20 32 38 61 2C 36 44 2C 31 38 61 42 DE FF 1C F3    28a,6D,18aB....
E        04 EC 00 08 1A 12 C5 9E DD 05 CE 00 0F 04 AF BF   ................
F        0B AF DD 04 AF B4 6A DE 00 00 04 E7 0A 2A 04 FF   ......j......*..
```
------
LOADROMS experiment
------
I then tried the LOADROMS call listed in the 4041 UTILITY ROM option to try to load the ROM in the UTL2 tape file:

```Assembly
*LOADROMS "UTL2"
```
and got the following response (see the loadroms test file in this folder):
```Assembly
 *** ERROR # 6007
                                                             
Attempting to load a rompack that is already present in the system
```
**Great!**  My 4041 for this test had the new board including the UTL2 option ROM.

I then powered up my older 4041 that didn't have the UTL2 option ROM and tried the same test:
```Assembly
*LOADROMS "UTL2"
                                                               
*ARRSCL
                                                                               
 *** ERROR # 52
                                                               
Undefined variable
```
I got no error message this time, so I typed in ARRSCL which is a UTL2 ROM call listed in the latest 4041 Service Manual in an appendix, and got the undefined variable error message - as I had not put in the required parameters.
-----
Bottom line, I had hoped to find how to put missing option ROMs in tape files - however you will notice this UTL2 file is not the same as the UTL2.ROM which is my extracted UTL2 file from my 4041 option ROMs on the main 68000 CPU board.

Not only is there an extra set of header bytes in front of the ROM, the UTL2 contents are also slightly different in the file compared to the actual UTL2.ROM.
----------
The MP2501 program has the following requirements:
* Program Development ROMs
* Graphics ROMs
* Plotting ROMs
* Signal Processing ROMs
* Utility 1 ROMs
* Utility 2 ROMs (UTL2)
* Tektronix 4100 or compatible graphics terminal
           
I believe MP2501 requirement for the averaging and other ROM calls in UTL2 was also the reason Tektronix put the UTL2 loadable ROM file on the MP2501 tape, as the original 4041s had a full Option ROM tray with six slots with Program Development (two slots), graphics, plotting, signal processing and utility1 option ROMs.
