// This code is based on the "YourDuino.com Example: BlueTooth HC-05 Setup"
// Make sure that you started the HC-05 in AT mode by holding the button during start up
 
void setup()
{
  Serial.begin(9600);   // For the Arduino IDE Serial Monitor
  delay(5000);
  Serial.println("Enter AT commands in top window.");
  Serial3.begin(38400); // HC-05 default speed in AT command mode

}


void loop()
{
  // READ from HC-05 and WRITE to Arduino Serial Monitor
  if (Serial3.available())
    Serial.write(Serial3.read());

  // READ Arduino Serial Monitor and WRITE to HC-05
  if (Serial.available()){
    //char c = Serial.read();
    Serial3.write(Serial.read());
    //Serial.write(c);
  }  
}
