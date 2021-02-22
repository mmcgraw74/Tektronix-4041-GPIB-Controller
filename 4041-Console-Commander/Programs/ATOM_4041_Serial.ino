/*  Short Press the key control switch to change console to COMM0: 
 *
 *  LONG press the key control switch (more than 1 second) to load AdvTek4041S and change console to COMM0:
*/
#include <M5Atom.h>
#include "utility/M5Timer.h"

int oneshot = 0;

M5Timer M5timer;
void Timeout(){

   M5.update();
   if (M5.Btn.read()) {
    // for Btn held over 500msec - send Adventure program and then change console to comm0:
    M5.dis.drawpix(0, 0x00ffff);
    M5.update();
    Serial2.println("Set driver \"COMM0(BAUD=9600,STOP=1,FLA=BID,EDIT=RAS):\"");
    Serial2.println("set console\"COMM0:\" ! Adventure 9600 8N1");
    delay(2000);
    M5.dis.drawpix(0, 0x000000);
    M5.update();
    } else {
    // for Btn held less than 500msec - just change console to comm0:
    M5.dis.drawpix(0, 0x0000ff);
    M5.update();
    Serial2.println("Set driver \"COMM0(BAUD=9600,STOP=1,FLA=BID,EDIT=RAS):\"");
    Serial2.println("set console\"COMM0:\" !CON= COMM0 9600 8n1");
    delay(1000);
    M5.dis.drawpix(0, 0x000000);
    M5.update();
}
oneshot = 1;
}

void setup() {
   M5.begin(true, false, true);
   Serial2.begin(4800, SERIAL_8N1, 33, 23);
   M5.dis.drawpix(0, 0xff0000);
   M5.update();
   delay(1000);
   M5.dis.drawpix(0, 0x000000);
   M5.update();
 }

void loop() {
    if (oneshot==0) {  // stop looking for Btn press after first time
    M5.update();
    M5timer.run();
  // update button state
   if (M5.Btn.wasPressed()) { // this function is only true first time it is called after Btn was pressed
   M5timer.setTimeout(500,Timeout);
   }
 }
}
