These are utility program files I created to build the System Verification tape
**************
4041 Clone SysVer4 Tape.tx is a BASIC program that can be downloaded over COMM0 to any 4041 with 512KB of memory.
Run this program with a formatted DC100 tape in your 4041.  This program will automatically create every file on the System Verification tape version 2.8 (I believe this is the latest version - it is the version listed in the latest service manuals posted on the TekWiki).
**************
CopyTapeToFloppy.BAS is a BASIC program if you have the DDU option with SCSI floppy drive.  This program will copy one file at a time from tape to floppy.
**************
Copy Floppy Sysver Files to Tape is another BASIC program if you have the DDU option and have run the program above on a floppy disk from a System Verification tape to create a floppy disk with all those files.  You then can use this floppy to create System Verification tapes.
**************
FLEX_DISK_DIR.TXT is the directory listing of my DDU floppy after using the CopyTapeToFloppy on each file on the System Verification disk.
