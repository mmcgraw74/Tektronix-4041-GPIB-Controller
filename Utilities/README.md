These are utility program files I created to build the System Verification tape
---------------
I wrote the TAPEDUMP program to capture every byte on the System Verification (or any other 4041 tape).

I was able to determine how the "68000 **Big-Endian** address mode" 4041 file system works examining the Sysver complete tape dump:

Record 1 contains:

| Tape Name | 4041 FW Version | # of 256 byte Records | Tape Formatted Date/Time | # Soft Errors |
|:-----------------:|----------|----------|----------|----------|
| <p>0x0-9 10 ASCII | <p>0x0B-16 ASCII | <p>0x1C-1D HEX | <p>0x1E-25 ASCII | <p>0x33 |

Records 2 through 4 contain the file names (16 bytes for each file):

| File Name | Starting Record# | # of 256 byte Records | File Type: ASCII or ITEM | File Creation Date/Time |
|:-----------------:|----------|----------|----------|----------|
| <p>0x0-5 ASCII | <p>0x06-7 HEX | <p>0x8-9 HEX | <p>0xA-B ASCII "AS" or "IT" | <p>0xC-F HEX |

* I believe Record CRCs must be outside each record in the area used to seek to a particular record.
* ASC and ITEM files longer than one record have 0xFF at last byte of each record until the last record
* Last byte of last record has a smaller value - which indicates how many bytes of this record are used

To recover the ITEM files or ASCII files from a tape, I load the file into 4041 memory, then list the file and capture the ASCII output to my PC using Realterm.
Then I edit the ASCII file to restore the control characters - the 4041 list prints the control characters as ^X where X is the ASCII character typed with the Control key.

Tektronix 4041 BASIC uses LF characters in PRINT statements for a new line and CR characters as the program line terminators, so I also remove LFs that follow CR characters in the dump.

1. To recover an ASCII file from a HEX dump (where the tape directory is damaged, or the file is an ASCII data file which cannot be loaded into the 4041), I delete the FF from last byte of the intermediate records and use the last byte of the last record to crop the end of the file
2. Then I use Notepad++ editing commands to remove all the "Record x" statements, line counts and ASCII text at the end of every line.
3. I then copy and paste the remaining HEX into an online HEX to BINARY file converter I found at: https://tomeko.net/online_tools/hex_to_file.php?lang=en
4. The resulting converted file is the ASCII program or ASCII data file with all the proper control character formatting.

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
