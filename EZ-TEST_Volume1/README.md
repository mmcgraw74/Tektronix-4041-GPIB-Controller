Tektronix EZ-TEST was 4041 software designed to make development of automated GPIB test procedures easy to develop.  Here is the Tek 1987 catalog page describing this program:
----------------
EZ-TEST Generator User Guide for Tektronix 4041 with 4105 Terminal now posted on TekWiki
https://w140.com/tekwiki/images/d/d1/062-7503-00.pdf
----------------
![EZ-TEST Vol1 tape](./TEK%20EZ-TEST%20in%201987%20catalog.jpg)

Tektronix 4041 EZ-TEST version 5.0 Volume.1-Generator is a complete set of files that I was able to recover from the original EZ-TEST Vol1 tape and a copy of this tape.
-------
![EZ-TEST Vol1 tape](./EZ-TEST%20Vol1%20and%20Vol2%20Tapes.jpg)
-------
HSELIN help file lists the Tektronix GPIB instruments supported by EZ-TEST Generator and Translator:

  * *DC 5009/DC 5010 Counter/Timer* 
  * *2445/2465 Portable Oscilloscope* 
  * *DM 5010 Multi-meter* 
  * *FG 5010 Function Generator* 
  * *PS 5010 Power Supply* 
  * *MI 5010 Multi-function Interface with cards* 
    * *50M10 ADC*
    * *50M20 DAC*
    * *50M30 DIO*
    * *50M40 RSC*
    * *50M41 LLRSC*
    * *50M50 MEMORY*
    * *50M70 DEV*   
  * *SI 5010 RF Signal Scanner* 
-----------
The EZ-TEST Vol1 and Vol2 tapes were in set of twelve 4041 DC100A tapes that were included in a box of 4052 DC300 tapes that I purchased from Stan Griffiths in 2000.

Not shown in the photo is the twelfth tape which was the System Verification Tape, posted in a separate folder on this repository.

EZ-TEST Vol1 had directory read errors, but there was a copy of Vol1 that I was able to use with my tape dump program and BAKAL1 program from the MP2501 tape to finally get all the files.

![EZ-TEST Vol1 tapes](./EZ-TEST%20Vol1%20Tapes.jpg)
EZ-TEST Vol2 files were also recovered and posted in a separate folder on this repository

The tape directory listing below indicated both EZ-TEST tapes and MP2501 tape had the same part number and serial number:

**S45F010_I  02-JAN-86 B050239** 

```Assembly
S45F010_I  02-JAN-86 B050239   SOFT ERRORS = 0        
 FILE  FILE  LENGTH  START  NUMBER         LAST       
 NAME  TYPE IN BYTES RECORD OF REC. MODIFICATION  DATE
------ ---- -------- ------ ------- ------------------
AUTOLD  IT   136425     5    535    01-JAN-81 00:14:00
HMAIN   AS     3315   540     13    27-MAR-85 13:52:00
HEDIT   AS     4335   553     17    27-MAR-85 13:53:00
HEXECU  AS     5610   570     22    27-MAR-85 13:55:00
HSELIN  AS     7650   592     30    27-MAR-85 13:58:00
               9435                               
```
My 'newest' 4041 included the DDU disk drive unit and had a Tektronix MP2501 sticker below the tape slot on the 4041, but the hard disk did not work and no tapes or floppy disks were supplied with the unit I purchased this year (2020).  I did get my DDU working by replacing both the SCSI hard disk and SCSI floppy drive.

![my 4041 and DDU](./My%20new%204041%20%26%20DDU%20are%20working%20small.jpg)

AUTOLD is the main Generator program, and had been damaged like the MP2501 tape by the previous owner (potentially Tektronix 4041 software developers - since Stan Griffiths had worked at Tektronix for many years) recording a simple AUTOLD file on top of the Vol1 AUTOLD program on the copy tape. :(  

I was able to recover the original AUTOLD file using my modified BAKAL3 program on the original unreadable Vol1 tape (days of work).

The H* files are help text for the main program, and cannot be directly loaded into the 4041 from RS-232 serial as they are not valid BASIC program files.

I put readable versions of the help files in the formatted file folder.

I hope to create a tape restore program from the BAKAL1 program, that could be used to create a complete tape from the HEX dump file I made.
