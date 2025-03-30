#include <Servo.h>
Servo myServo;
int const trigPin = 12;
int const echoPin = 13;
double duration = 0;
double distance = 0;

void setup() {
  myServo.attach(9);
  myServo.write(0);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.000001 * 34000 / 2;
 
  Serial.print("distance: ");
  Serial.println(distance);


  if (distance > 30) {
    distance = 30;
  }

  myServo.write(distance * 6);
  delay(100);
}