// Define the pins for the IR sensors
int leftSensorPin = 18;
int rightSensorPin = 14;
int centerSensorPin = 16;

int speed1 = 255;
//int speed2 = 170 ;
// Define the pins for the motors
int leftMotorPin1 = 2;
int leftMotorPin2 = 4;
int rightMotorPin1 = 6;
int rightMotorPin2 = 8;

void setup() {
  // Set the pin modes
  Serial.begin(9600);
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  pinMode(centerSensorPin, INPUT);
  
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
}

void loop() {
  // Read the values from the IR sensors
  int leftSensorValue = digitalRead(leftSensorPin);
  int rightSensorValue = digitalRead(rightSensorPin);
  int centerSensorValue = digitalRead(centerSensorPin);

  Serial.print("left");
  Serial.println(leftSensorValue);
  Serial.print("center");
  Serial.println(centerSensorValue);
  Serial.print("right");
  Serial.println(rightSensorValue);
  delay(500);
  

  // If the center sensor is on the black line, move forward
  if (centerSensorValue == 1 && leftSensorValue==0 && rightSensorValue==0 ) {
    analogWrite(leftMotorPin1, speed1);
    digitalWrite(leftMotorPin2, LOW);
    analogWrite(rightMotorPin1, speed1);
    digitalWrite(rightMotorPin2, LOW);
    delay(10);
  }
  // If the left sensor is on the black line, turn left
  else if (leftSensorValue == 1 && centerSensorValue==0 && rightSensorValue==0 ) {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    analogWrite(rightMotorPin1, speed1);
    digitalWrite(rightMotorPin2, LOW);
  }

  // If the right sensor is on the black line, turn right
  else if (rightSensorValue == 1 && leftSensorValue==0 && centerSensorValue==0) {
    analogWrite(leftMotorPin1, speed1);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(rightMotorPin1, LOW);
    analogWrite(rightMotorPin2, LOW);
  }
  
   // If left and center sensors are on the black line, move left
  else if(centerSensorValue == 1 && leftSensorValue==1 && rightSensorValue==0){
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    analogWrite(rightMotorPin1, speed1);
    digitalWrite(rightMotorPin2, LOW);
  }

     // If right and center sensors are on the black line, move right
  else if(centerSensorValue == 1 && rightSensorValue==1 && leftSensorValue==0){
    analogWrite(leftMotorPin1, speed1);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }
   // If All 3 sensors are on the black line, move forward
  else if(centerSensorValue == 1 && leftSensorValue==1 && rightSensorValue==1){
    analogWrite(leftMotorPin1, speed1);
    digitalWrite(leftMotorPin2, LOW);
    analogWrite(rightMotorPin1, speed1);
    digitalWrite(rightMotorPin2, LOW);
  }


  // If both sensors are on the white line, move forward
  else {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }
}
