/* Arduino USB Keyboard
 * 
 */
 
 uint8_t buf[8] = {0}; //Keyboard buffer
 boolean done;
 void setup()
 {
   Serial.begin(9600);
   done = false;
 }
 
 void loop()
 {
   if(!done)
   {
     sendMessage("a");
     done = true;
   }
 }
 
 void releaeKey()
 {
   buf[0] = 0;
   buf[2] = 0;
   Serial.write(buf, 8); //Release Key
 }
 
 void sendMessage(String message)
 {
    char msgArray[1024];
    int msgLength;
    int index = 0;
    strcpy(msgArray, message.c_str());
    msgLength = message.length();
    
 }
