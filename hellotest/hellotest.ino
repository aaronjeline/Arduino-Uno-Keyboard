/* Arduino as USB Keyboard test
 * A simple helloworld
 * Aaron Eline
 * Based on: http://mitchtech.net/arduino-usb-hid-keyboard/
 */
 
uint8_t buf[8] = { 
  0 }; 	/* Keyboard report buffer */
boolean done;
void setup() 
{
  Serial.begin(9600);
  done = false;
  delay(200);
}
 
void loop() 
{
  
  if(!done){
  sendKey(11); //h
  sendKey(8); //e
  sendKey(15); //l
  sendKey(15); //l
  sendKey(18); //o
  done = true;
  }
}
 
void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);	// Release key  
}

void sendKey(int keyNum){
  buf[2] = keyNum;
  Serial.write(buf, 8);
  releaseKey();
}

//
