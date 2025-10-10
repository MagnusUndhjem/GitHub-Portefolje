// Include Arduino Wire library for I2C
#include <Wire.h>
 
// Define Slave I2C Address
#define SLAVE_ADDR 9
 
// Define Slave answer size
#define ANSWERSIZE 5
 
// Define string with response to Master
String answer = "Hello";
int saved = 0;
int forige, state, x;
 
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  for(int i = 2; i < 7; i++) {
    pinMode(i, OUTPUT);
  }
  // Initialize I2C communications as Slave
  Wire.begin(SLAVE_ADDR);

  // Function to run when data received from master
  Wire.onReceive(receiveEvent);
  
  // Setup Serial Monitor 
  Serial.begin(9600);
  Serial.println("I2C Slave Demonstration");
}
 
void receiveEvent() {
 
  // Read while data received
  x = Wire.read();

  // Print to Serial Monitor
  if(x != 0) {
    state = 1;
  }
}
 
void loop() {
  if(state == 1) {
    digitalWrite(x, HIGH);
    delay(2000);
    digitalWrite(x, LOW);
    state = 0;
  }
  // Time delay in loop
  delay(50);
}
