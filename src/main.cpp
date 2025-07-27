#include<Arduino.h>
#define LED_PIN 2
bool ledState = true;  // Start with LED ON
void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  digitalWrite(LED_PIN, ledState);  // Initially ON
  Serial.println("UART Communication Started.\n Type input:");
}
void loop() {
  static char input[100];  // Buffer to hold user input
  static int index = 0;
  if (Serial.available()) {
    char ch = Serial.read();
    if (ch == '\n') {
      input[index] = '\0';  // End of string
      Serial.print("Received: ");
      Serial.println(input);
      
      // Toggle LED state
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);

      index = 0;  // Reset for next message
      Serial.println("you want turn on the led send data again:");
    } else {
      if (index < sizeof(input) - 1) {
        input[index++] = ch;
      }
    }
  }
}
