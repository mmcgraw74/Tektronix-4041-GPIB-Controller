BAKAL1 was found on both EZ-TEST Volume2 and MP2501 tapes.

This is a very short and clever Tektronix program that takes advantage of the newer or upgraded 4041's with 512KB of memory which allows the complete tape (about 160K bytes) to be loaded into memory, so the original tape can be removed and replaced with a second tape to copy the contents in very short time.

BAKAL1 is very fast:
   * Only a couple of minutes to read an entire tape, and it only reads to the last record used, no matter how many records are formatted.
   * Second pass on the original verifies each record against the memory copy with a single string array compare command!
   * Full error handling in the program - stops the copy and prints the error message
   * The second tape is formatted first
   * Then the original tape header is written to overwrite the first formatted record and the original timestamp or serial number is also written to the first record
   * Then the three original directory records are written, followed by the other records saved in memory
   * Finally, the second tape is reread to verify all records against the memory image.
   
I was stumped on my initial attempts to recover EZ-TEST Volume1 with my 4041 tape dump program, as my program would not read the original Vol1 tape, and the Vol1 copy tape had been overwritten on record 5 by the previous owner - which prevented me from loading the main AUTOLD (binary) program into the 4041 and saving the ASCII file to my PC.

BAKAL1 was able to access the original Vol1 tape to get the original record 5 and other bad sectors I captured from the copy tape, but I had to modify BAKAL1 to send this info to my PC over RS-232 serial, so I could 'patch' the bad records on the copy tape.  

I named my modified program BAKAL3, as BAKAL1 indicated it was version 2.

I created a short program to write single records onto the copy tape, then used BAKAL3 to capture the HEX upload of the corrected Vol1 files.
   1 Run BAKAL3 to capture a tape into memory
   2 When prompted to insert the second tape, eject the first tape, then hit RETURN, which stops the BAKAL3 program
   3 Type RUN 735 to start my PC upload part of BAKAL3 and type y to the prompted question
   4 Configure your terminal emulator (I use Realterm) to capture the data to a file
   5 Press RETURN for BAKAL3 to begin transmitting the memory image of the tape to the PC
   6 As each record in memory is transferred, the RECORD number is printed to the 4041 front panel.
   7 When the memory image of every record has been transmitted (in HEX) to the PC, the upload is complete and this is printed to the 4041 front panel
   8 Stop the capture on the terminal emulator
   

