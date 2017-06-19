// This sketch is for the teensy which connects to the Robotiq FT sensor
// Make sure that you connected the pins as they are definded in this code


#define RS_PIN 11 //pin for setting read write status on RS485 converter

bool debug;
int last_write_time;

void setup(){
  debug = false; // activate output to the serial monitor
  writing = false;
  
  pinMode(RS_PIN, OUTPUT);  
  digitalWrite(RS_PIN, writing);
  
  Serial.begin(19200);   // For the Arduino IDE Serial Monitor  
  Serial3.begin(19200); // for the rs-485 bus
  Serial2.begin(19200); //bluetooth
  delay(5000);
  Serial.println("Beginning bluetooth to RS-485. Please set debug to true if you want more output on the serial monitor.");

}


void loop(){
  digitalWrite(RS_PIN, writing); // set the rs-485 on read or write, depending on the current state

  if (Serial3.available()){ //data from bluetooth
    digitalWrite(RS_PIN, true);
    char c = Serial3.read();
    Serial2.write(c);
    if (debug){
      Serial.println("");
      Serial.println("");
      Serial.print("blu ");      
      Serial.print(c, HEX);
    }
    last_write_time = micros();       
    writing = true; 
  }else if(writing && micros() - last_write_time > 2000){
    writing = false;
  }
  
  if (Serial2.available()){ //data from hand
    char c = Serial2.read();        
    Serial3.write(c);
    if(debug){
      Serial.println("");
      Serial.print("hand ");  
      Serial.print(c,HEX);
    }    
  }
}
