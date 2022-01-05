#define r 8
#define st 4
String command;
void setup() {
  Serial.begin(9600);
  pinMode(r, OUTPUT);
  pinMode(st, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil("/n");
    command.trim();
    if (command.equals("on")) {
      command = "";
      pulse();
      digitalWrite(st, HIGH);
    }
    if (command.equals("off")) {
      pulse();
      digitalWrite(st, LOW);
    }

    if (command.equals("status")) {
      Serial.print(checkStatus());
    }
  }
}

void pulse() {
  digitalWrite(r, HIGH);
  delay(100);
  digitalWrite(r, LOW);
}

String checkStatus() {
  if (digitalRead(st) == 1) {
    return "on";
  }
  if (digitalRead(st) == 0) {
    return "off";
  }
}
