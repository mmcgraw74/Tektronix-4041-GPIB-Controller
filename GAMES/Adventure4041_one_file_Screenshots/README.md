Adventure is a classic text game and it requires the 4041 have the Program Development ROMs installed in order to load the game to the 4041 over COMM0:.

The screenshots are taken from my PC running Tera Term open-source terminal emulator:
https://ttssh2.osdn.jp/index.html.en

After you install Tera Term, configure the Serial for the RS-232 baud rate/ parity/ stop bits you have configured for 4041 RS-232 console.
In addition, configure Tera Term and the 4041 RS-232 COMM0: port for XON/XOFF handshake.

Here are the two commands I send to my 4041 from the front panel serial port (or tape with AUTOLD file) to configure COMM0: as the console with XON/XOFF:

The "!" in 4041 BASIC starts a comment - which in this case echoes the following characters to the front panel LEDs before changing the console to COMM0:
```
Set driver "COMM0(BAUD=9600,STOP=1,FLA=BID,EDIT=STO):"
Set console "COMM0:" !S_Artillery 9600 8N1"
```

Then you can use Tera Term "Send File" to send the Super Artillery text file to the 4041.  

If you hear 4041 speaker beeps during the transfer - this means you have not configured XON/XOFF on Tera Term or the 4041.  You have to cancel the Tera Term program transfer, then press the ABORT front panel key on the 4041 until the beeps (BELL) stops.  Then check the Tera Term and 4041 settings and fix the issue and try the download again.

If the download was successful without errors, type RUN at the 4041 BASIC prompt, and Tera Term should automatically open the "Tek" window which is used for this game text and graphics. 

Here is a screenshot of the one-file Adventure game instructions from a Tera Term "Tek" window automatically launched when you run the program

![Adventure Instructions](./Super%20Adventure%20instructions.png)

and here is a screenshot of a game, with variable wind and tracer lines for the shots from each side.

![Adventure game](./Adventure%20game.png)

