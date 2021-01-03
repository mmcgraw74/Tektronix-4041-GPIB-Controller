Tektronix 4041 MP2501 tape was a bad copy of the original tape.
-------
The directory list indicated the files would have required about 110KB or 2/3 of the DC100A tape, but the tape was only formatted for half that size (older 4041 firmware?).
-------
![MP2501 tape](./MP2501%20tape.jpg)
-------
In addition, previous owner must have mistakenly recorded their COMM0 configuration script over the MP2501 AUTOLD file, so that file was corrupted.

You can look at the remainder of the original AUTOLD file in the HEX dump.  This file starts at record 0x05 and ends at record 0x36 in the HEX dump.
```
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
-------
I also noticed the UTL2 file and wondered what it was.  Looking at the tape dump text it looked like it was a loadable ROM file!

```Assembly
Record 37
0        22 00 0C 34 30 34 31 20 52 6F 6D 70 61 63 6B 4C   "..**4041 Rompack**L
1        40 BF 34 00 00 00 00 00 4C 40 7F 00 00 00 00 00   @.4.....L@.....
2        00 4C 40 00 00 00 00 00 00 00 22 00 F0 4D 36 38   .L@......."..**M68**
3        4B 08 01 55 54 4C 32 00 00 00 00 00 00 00 00 00   K..**UTL2**.........
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
