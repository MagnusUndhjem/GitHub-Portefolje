#include <Wire.h>
 
// Define Slave I2C Address
#define SLAVE_ADDR 9
#define SLAVE_ADDR2 8
 
// Define Slave answer size
#define ANSWERSIZE 5

int poss;
int rad;
int randomInt;
int led;
int send;
int rad2[] = {2, 3};
int rad3[] = {4, 5, 6};
int rad4[] = {7, 8, 9, 10};
int rad5[] = {2, 3, 4, 5, 6};
int rad6[] = {7, 8, 9, 10, 11, 12};
bool first = true;
bool run = false;
 
void setup() {
 
  // Initialize I2C communications as Master
  Wire.begin();
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, INPUT_PULLUP);
  pinMode(15, OUTPUT);
  // Setup serial monitor
  Serial.begin(9600);
  Serial.println("I2C Master Demonstration");
  randomSeed(analogRead(0));
}
 
void loop() {
  poss = 1;
  rad = 1;
  led = 0;
  if(digitalRead(12) == LOW) {
    run = true;
  }
  while(run) {
    if(first) {
      Wire.beginTransmission(SLAVE_ADDR2);
      Wire.endTransmission();
      delay(5000);
      digitalWrite(11, HIGH);
      delay(1000);
      digitalWrite(11, LOW);
      first = false;
    }
    randomInt = random(2);
    if(randomInt == 0) {
      poss += 0;
      rad++;
    } else if(randomInt == 1) {
      poss += 1;
      rad++;
    }
    if(rad == 5) {
      send = rad5[poss-1];
      Serial.println(send);
      Wire.beginTransmission(SLAVE_ADDR);
      Wire.write(send);
      Wire.endTransmission();
      led = 0;
      first = true;
      run = false;
    }
    if(rad == 4) {
      led = rad4[poss-1];
      Serial.println(led);
    }
    if(rad == 3) {
      led = rad3[poss-1];
      Serial.println(led);
    }
    if(rad == 2) {
      led = rad2[poss-1];
      Serial.println(led);
    }
    digitalWrite(led, HIGH);
    delay(1000+(rad*200));
    digitalWrite(led, LOW);
    if(rad == 5) {
      rad = 0;
      break;
    }
  }
}

/*
void loop() {
  poss = 1;
  rad = 1;
  while(true) {
    randomInt = random(2);
    if(randomInt == 0) {
      poss += 0;
      rad++;
    } else if(randomInt == 1) {
      poss += 1;
      rad++;
    }
    if(rad == 2) {
      Serial.println(poss);
      break;
    }
  }
  delay(100);
  receiveData();
}
*/
