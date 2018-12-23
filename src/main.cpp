#include <Arduino.h>

const int LED = 13;   // LED pin
const int BUTTON = 7; // BUTTON pin

int val = 0;     // input state
int old_val = 0; // store old input state

int state = 0; // 0 = LED off while 1 = LED on

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // setup serial monitor at 9600
  Serial.print("Serial Monitor Setup \n");

  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  val = digitalRead(BUTTON);

  if ((val == HIGH) &&
      (old_val == LOW)) { // nothing will happen if you have it pressed down
                          // loop will continue once released

    state = 1 - state; // a way to always get one or zero
    delay(10);         // debounce
  }

  old_val = val; // val is now old, store it

  if (state == 1) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  Serial.print(val);
}
