These are utility program files I created to build the System Verification tape
---------------
I wrote the TAPEDUMP program to capture every byte on the System Verification (or any other 4041 tape).

I was able to determine how the "68000 Big-Endian address mode" 4041 file system works:

Record 1 contains:

| Tape Name | 4041 FW Version | # of 256 byte Records | Tape Formatted Date/Time | # Soft Errors |
|:-----------------:|----------|----------|----------|----------|
| <p>0x0-9 10 ASCII | <p>0x0B-16 ASCII | <p>0x1C-1D HEX | <p>0x1E-25 ASCII | <p>0x33 |

Records 2 through 4 contain the file names (16 bytes for each file):

| File Name | Starting Record# | # of 256 byte Records | File Type: ASCII or ITEM | File Creation Date/Time |
|:-----------------:|----------|----------|----------|----------|
| <p>0x0-5 ASCII | <p>0x06-7 HEX | <p>0x8-9 HEX | <p>0xA ASCII "A" or "I" | <p>0xB-F HEX |

Record CRCs must be outside each record in the area used to seek to a particular record.


**************
4041 Clone SysVer4 Tape.tx is a BASIC program that can be downloaded over COMM0 to any 4041 with 512KB of memory.
Run this program with a formatted DC100 tape in your 4041.  This program will automatically create every file on the System Verification tape version 2.8 (I believe this is the latest version - it is the version listed in the latest service manuals posted on the TekWiki).
**************
CopyTapeToFloppy.BAS is a BASIC program if you have the DDU option with SCSI floppy drive.  This program will copy one file at a time from tape to floppy.
**************
Copy Floppy Sysver Files to Tape is another BASIC program if you have the DDU option and have run the program above on a floppy disk from a System Verification tape to create a floppy disk with all those files.  You then can use this floppy to create System Verification tapes.
**************
FLEX_DISK_DIR.TXT is the directory listing of my DDU floppy after using the CopyTapeToFloppy on each file on the System Verification disk.
**************
GAUTO is a file I added to the SYSVER tape and you can LOAD it into the 4041, edit the BAUD rate, and SAVE it as AUTOLD on a tape to simply change the system console from the PD keyboard to COMM0:
**************
MTPACK is a program that I found on a Tektronix service note for the 4041 to run the tape to the end and rewind it back to the beginning.
**************
SYSVER Complete Tape Dump used the TAPEDUMP4 utility to dump every 256 byte record with HEX and ASCII output.
I used this file to create the DATA statements for the 4041 Clone SysVer4 program with NOTEPAD++ and an online HEX to DECIMAL converter program.
**************
TAPEDUMP5 is the same logic as TAPEDUMP4 - but I added messages to the 4041 front panel LEDs to indicate which record was written - as it takes a LONG time to write the entire System Verification files to tape.
