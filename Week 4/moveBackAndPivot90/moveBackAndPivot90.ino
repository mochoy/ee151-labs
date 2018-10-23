// EE 151 - 02 Lab 4, move back and pivot sketch
// Jackson Meyers and Monty Choy

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

// Setup pins
void setup() {
  for (int i = 4; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() 
{
  // Go backwards for one second
  rightMotor(-255);
  leftMotor(-255);
  delay(1000);
  // Stop and wait one second
  stopAllMotors();
  delay(1000);
  // Pivot
  rightMotor(255);
  leftMotor(-255);
  delay(250);
  // Stop
  stopAllMotors();
}


//neg speed = backwards
void rightMotor(int speed) {
  if (speed > 0) {
    digitalWrite(IN1, LOW);
    analogWrite(IN2, abs(speed));

    return;
  }

  digitalWrite(IN2, LOW);
  analogWrite(IN1, abs(speed));

}

//neg speed = backwards
void leftMotor(int speed) {
  if (speed > 0) {
    digitalWrite(IN3, LOW);
    analogWrite(IN4, abs(speed));

    return;
  }

  digitalWrite(IN4, LOW);
  analogWrite(IN3, abs(speed));

}

void stopAllMotors() {
  for (int i = 4; i < 8; i++) {
    digitalWrite(i, LOW);
  }
}
