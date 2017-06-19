// This is a simple script to test if data from the bluetooth connection reaches the teensy. 
// You can also send data to the teensy which is then transfered via wifi.
// Note that you may have to change the baudrate of the serial2 connection
// Furthermore, remember to set the right baudrate on your serial monitor

void setup()  
{ 
  Serial.begin(115200);   // For the Arduino IDE Serial Monitor
  Serial2.begin(115200); // bluetooth connection
  delay(5000); // delays because the teensy needs a few seconds to have a connection to the serial monitor
  Serial.println("starting");
  delay(15000);
  Serial.println("Testing for bluetooth connection tool");
  Serial.println("You should now be able to send commands via serial to bluetooth and vice versa");
  
}

 
void loop()   
{
  // READ from HC-05 and WRITE to Arduino Serial Monitor
  if (Serial2.available())
    Serial.write(Serial2.read());

  // READ Arduino Serial Monitor and WRITE to HC-05
  if (Serial.available()){
    char c = Serial.read();
    Serial2.write(c);
    //Serial.write(c);
  }
}
