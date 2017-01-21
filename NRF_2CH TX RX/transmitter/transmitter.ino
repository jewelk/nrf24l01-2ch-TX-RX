#include <SPI.h>
#include "RF24.h" 
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL; 
int msg[1]; 
int Joy_X = A0; 
int val_1; 
int Joy_Y = A1; 
int val_2; 
void setup(void){
radio.begin();
radio.openWritingPipe(pipe); 
}
void loop() {
val_1 = analogRead(Joy_X),val_1 = map(val_1, 0, 1023, 55, 100),msg[0] = val_1,radio.write(msg, 1);
val_2 = analogRead(Joy_Y),val_2 = map(val_2, 0, 1023, 128, 255),msg[0] = val_2,radio.write(msg, 1);
}
