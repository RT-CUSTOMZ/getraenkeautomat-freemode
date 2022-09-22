#define LED_PIN  0
#define REMOTE_PIN  1

void setup() {
  pinMode(LED_PIN, INPUT);          //Connect to NFC Card valid status LED 
  pinMode(REMOTE_PIN, OUTPUT);      //Connect to internal remote control to enable "Free" mode
}

void loop() {
 if(!digitalRead(LED_PIN))          //Pi logic is high active to drive PNP transistor, so we check for signal going low
  {
    delay(20);                      //Debounce signal to avoid EMC issues
    if(!digitalRead(LED_PIN))       //Check if signal is still low and hence valid, then
    {
      digitalWrite(REMOTE_PIN, 1);  //Trigger internal remote button to enable free mode
      delay(100);                   //Signal must be long enough the overcomce debounce meachnism of remote control logic
      digitalWrite(REMOTE_PIN, 0);  
      while(!digitalRead(LED_PIN))  //Make sure that the NFC card was removed and wait until valid status LED is timed out
      {

      }
    }
  }
}
