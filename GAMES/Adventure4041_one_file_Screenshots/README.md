Adventure is a classic text game and it requires the 4041 have the Program Development ROMs installed in order to load the game to the 4041 over COMM0:.

This version of my port of Adventure does not require any other files - all the files are embedding in one file, which dramatically speeds up game play and allows you to play the game without needing a tape or DDU floppy or hard disk like my earlier version of Adventure for the 4041.

This version **may run on a 4041 with only 128KB of RAM - I just don't have one to test.**  I am confident it will run on 4041's with 256KB or 512KB of RAM.

The screenshots are taken from my PC running Tera Term open-source terminal emulator:
https://ttssh2.osdn.jp/index.html.en

After you install Tera Term, configure the Serial for the RS-232 baud rate/ parity/ stop bits you have configured for 4041 RS-232 console.
In addition, configure Tera Term and the 4041 RS-232 COMM0: port for XON/XOFF handshake.

Here are the two commands I send to my 4041 from the front panel serial port (or tape with AUTOLD file) to configure COMM0: as the console with XON/XOFF:

The "!" in 4041 BASIC starts a comment - which in this case echoes the following characters to the front panel LEDs before changing the console to COMM0:
```
Set driver "COMM0(BAUD=9600,STOP=1,FLA=BID,EDIT=RAS):"
Set console "COMM0:" ! Adventure 9600 8N1"
```

Then you can use Tera Term "Send File" to send the **Adventure4041_one_file** text file to the 4041.  

If you hear 4041 speaker beeps during the transfer - this means you have not configured XON/XOFF on Tera Term or the 4041.  You have to cancel the Tera Term program transfer, then press the ABORT front panel key on the 4041 until the beeps (BELL) stops.  Then check the Tera Term and 4041 settings and fix the issue and try the download again.

If the download was successful without errors, type RUN at the 4041 BASIC prompt, and Tera Term should automatically open the "Tek" window which is used for this game text and graphics. 

Here is a screenshot of the one-file Adventure game instructions from a Tera Term "VT or Tek" window when you run the program

![Adventure Instructions](./Adventure%20instructions%20page%201.png)

Here is a screenshot of starting an Adventure game.

![Adventure game](./New%20Game.png)

Adventure is a complex maze loaded with treasures and hazards like trolls and a Pirate that will steal all your treasure.

This version has the ability to SAVE and LOAD games to your PC using Tera Term "Send file" and "Log" commands respectively.

This screenshot shows a previously saved game loaded into memory:

![Adventure Load game](./Adventure%20LOAD%20saved%20game.png)

LOADing a previously saved game is easy - just type LOAD and then use Tera Term "Send file" to pick the saved game to send to the 4041.

SAVEing a game is a little more complicated:

-Type SAVE
-select "Log" in Tera Term and type the filename (make sure to uncheck Append and check Plain Text)
-press RETURN to begin sending the file to Tera Term
-when the text file stops scrolling on Tera Term select "Stop Logging" which closes the Log file
-now press RETURN to continue your Adventure!

ENJOY!!

