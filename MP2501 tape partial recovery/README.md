Tektronix 4041 MP2501 tape was a bad copy of the original tape.
-------
The directory list indicated the files would have required about 110KB or 2/3 of the DC100A tape, but the tape was only formatted for half that size (older 4041 firmware?).
-------
![MP2501 tape](./MP2501%20tape.jpg)
-------
In addition, previous owner must have mistakenly recorded their COMM0 configuration script over the MP2501 AUTOLD file, so that file was corrupted.

You can look at the remainder of the original AUTOLD file in the HEX dump.

`S45F010_I  02-JAN-21 B050239   SOFT ERRORS = 0        
 FILE  FILE  LENGTH  START  NUMBER         LAST       
 NAME  TYPE IN BYTES RECORD OF REC. MODIFICATION  DATE
------ ---- -------- ------ ------- ------------------
AUTOLD  IT     8160     5     32    01-JAN-81 02:01:00
UTL2    IT     4845    37     19    19-NOV-84 11:09:00
BAKAL1  AS     4845    56     19    14-DEC-84 12:46:00
MP2501  IT   109395    75    429    01-JAN-81 01:31:00
              50745                                  ` 
