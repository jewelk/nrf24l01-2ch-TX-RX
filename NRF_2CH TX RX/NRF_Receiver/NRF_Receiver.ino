#include <Servo.h>
#include <SPI.h>
#include "RF24.h"
Servo servo1;
Servo servo2;
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL; 
int msg[1]; 
int data; 
int pos;
void setup()
{
servo1.attach(2); 
servo2.attach(6);
radio.begin();
radio.openReadingPipe(1,pipe); 
radio.startListening();
}
void loop()
{
if (radio.available())radio.read(msg, 1);
if (msg[0] <128 && msg[0] >-1)data = msg[0], pos = map(data, 0, 127, 7, 177),servo1.write(pos);
if (msg[0] >127 && msg[0] <255)data = msg[0], pos = map(data, 128, 254, 9, 177),servo2.write(pos);
}
