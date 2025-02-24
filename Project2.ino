int  switchstate = 0;

void setup() {
  // declare the LED pins as outputs
  pinMode(3,  OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  // declare the switch
  pinMode(2, INPUT);
}

void loop() {
  // read the value of the switch
  switchstate = digitalRead(2);

  if (switchstate == LOW) {
    // if the button is not pressed
    digitalWrite(3,  HIGH); // green LED
    digitalWrite(4, LOW);  // red LED
    digitalWrite(5, LOW);  // red LED
  }
  else  {
    // if the button is pressed
    digitalWrite(3, LOW);
    digitalWrite(4,  LOW);
    digitalWrite(5, HIGH);
    delay(250); // wait for a quarter second
    // toggle the LEDs
    digitalWrite(4,  HIGH);
    digitalWrite(5, LOW);
    delay(250); // wait for a quarter second
  }
}